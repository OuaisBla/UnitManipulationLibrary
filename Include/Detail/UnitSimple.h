/*
Unit Manipulation Library.
Copyright (C) 2002  Jean Gauthier

The goal of this library is to make easy, reliable and efficient the
manipulation of units, including arithmetical operations and safe 
conversions from unit type to another. 

This library is free software; you can redistribute it and/or
modify it under the terms of the GNU Library General Public
License as published by the Free Software Foundation; either
version 2 of the License, or (at your option) any later version.

This library is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
Library General Public License for more details.

You should have received a copy of the GNU Library General Public
License along with this library; if not, write to the
Free Software Foundation, Inc., 59 Temple Place - Suite 330,
Boston, MA  02111-1307, USA.

jean.gauthier@programmer.net
*/


#pragma once 


#include "Detail\UnitObject.h"
#include "Detail\UnitHelper.h"
#include <typeinfo>


namespace Unit
{


template <typename _UnitType, typename _Factor>
class Simple : public _UnitType
{
public:

  typedef _UnitType                             UnitType;
  typedef _Factor                               _Factor;

  typedef typename UnitType::ScalarType         ScalarType;
  typedef typename UnitType::Policy             Policy;
  typedef typename UnitType::Limits             Limits;


  typedef typename UnitType::SimplifiedType     SimplifiedType;
  typedef typename SimplifiedType::BaseType     BaseType;
  typedef typename UnitType::DerivedType        DerivedType;
  typedef typename UnitType::InvertedType       InvertedType;
  typedef typename ProductFactor<
    typename _Factor::SimplifiedFactor, 
    typename UnitType::SimplifiedFactor::InvertedFactor>
    ::SimplifiedFactor                          SimplifiedFactor;
  typedef typename _Factor::InvertedFactor      InvertedFactor;
  
  typedef Simple<UnitType,_Factor>              SimpleType;
  typedef Simple<InvertedType,InvertedFactor>   Invert;

  enum { Exponent = SimplifiedType::Exponent };
  enum { NumeratorBaseTypeValue = SimplifiedType::NumeratorBaseTypeValue };
  enum { DenumeratorBaseTypeValue = SimplifiedType::DenumeratorBaseTypeValue };

public:

  inline Simple();
  inline explicit Simple( ScalarType );
  inline Simple( Simple<UnitType,_Factor> const & );

  template< typename OtherUnitType, typename OtherFactor>
  inline Simple( Simple<OtherUnitType, OtherFactor> const &_s ) :
    m_Value( OffsetHandler<UnitType, OtherUnitType>::Convert( _s.Simple<OtherUnitType, OtherFactor>::GetValue() * (OtherFactor::ConversionFactor() / m_Factor) ) )
  {
    typedef Simple<OtherUnitType, OtherFactor> _OtherUnit;

    Detail::CompatibleUnit<NumeratorBaseTypeValue == _OtherUnit::NumeratorBaseTypeValue && 
      DenumeratorBaseTypeValue == _OtherUnit::DenumeratorBaseTypeValue>();
  }

  virtual ~Simple() { }

public:

  inline Simple<UnitType,_Factor> const & operator= ( Types::Scalar );
  inline Simple<UnitType,_Factor> const & operator= ( Simple<UnitType,_Factor> const & );

public:

  inline ScalarType GetValue() const;
  inline Types::Scalar GetFactor() const;
  inline ScalarType GetConvertedValue() const;

public:

  inline Types::String GetSuffix() const;
  inline Types::String GetSISuffix() const;

public:

  inline static Types::Scalar ConversionFactor()
  {
    return m_Factor;
  }

  inline static Types::Scalar Epsilon()
  {
    return m_Epsilon;
  }

  inline static Types::String Suffix()
  {
    return _Factor::Suffix() + DerivedType::Suffix();
  }


protected:

  inline void SetValue( ScalarType );

protected:

  /**
    A scalar to contain the conversion factor.
  */
  static Types::Scalar const m_Factor;


  /**
    A scalar to contain the current epsilon according to precision policy.
  */
  static ScalarType const m_Epsilon;

  /**
    A scalar to contain the raw value.
    This value is expressed in the current unit type.
  */
  ScalarType m_Value;

private:

  inline explicit Simple( void *, void * ); 

#ifndef NO_STATIC_UNIT_SUFFIXES_EVALUATION
  static Simple const RuntimeSuffixesCtor;
#else
  friend class Detail::SuffixesInitializer;
#endif

};


template <typename _Factor>
class Simple<Identity,_Factor>
{

  Simple();
  void operator= ( Simple<Identity,_Factor> const & );

public:

  typedef Identity UnitType;
  typedef Identity BaseType;
  typedef Identity SimplifiedType;
  typedef Types::Scalar   ScalarType;
  typedef Identity InvertedType;
  typedef typename _Factor::SimplifiedFactor SimplifiedFactor;
  typedef typename _Factor::InvertedFactor InvertedFactor;
  
  typedef Simple<UnitType,_Factor> SimpleType;
  typedef Simple<InvertedType,InvertedFactor> Invert;

public:

  inline Simple( Types::Scalar );
  inline Simple( Simple<Identity,_Factor> const & );

  ~Simple() { }

public:

  inline operator Types::Scalar() const;

protected:

  /**
    A scalar to contain the raw value.
    This value is expressed in the current unit type.
  */
  Types::Scalar const m_Value;

};


template <typename T, typename F>
Types::Scalar const Simple<T,F>::m_Factor = ::pow( Simple<T,F>::SimplifiedFactor::ConversionFactor(), ::abs( Simple<T,F>::Exponent ) );


template <typename T, typename F>
typename Simple<T,F>::ScalarType const Simple<T,F>::m_Epsilon = boost::math::tools::root_epsilon<typename Simple<T,F>::ScalarType>();


#ifndef NO_STATIC_UNIT_SUFFIXES_EVALUATION
template <typename T, typename F>
Simple<T,F> const Simple<T,F>::RuntimeSuffixesCtor( NULL, NULL );
#endif


//
//  Definition of constructors
//

template <typename T, typename F>
inline Simple<T,F>::Simple() :
  m_Value( 0. )
{
#ifndef NO_STATIC_UNIT_SUFFIXES_EVALUATION
  static Simple<T,F> __ForceLinker = Simple<T,F>::RuntimeSuffixesCtor;
#endif
}

template <typename T, typename F>
inline Simple<T,F>::Simple( ScalarType const _v ) :
  m_Value( _v )
{
}

template <typename T, typename F>
inline Simple<T,F>::Simple( Simple<UnitType,F> const &_s ) :
  m_Value( _s.m_Value )
{
}

template <typename T, typename F>
inline Simple<T,F>::Simple( void *, void * ) 
{
  using namespace Detail;
  using namespace Types;

  SuffixesValue const suffixKey( static_cast<Integer>( NumeratorBaseTypeValue ), static_cast<Integer>( DenumeratorBaseTypeValue ) );

  SuffixesMap::iterator it = SuffixesInitializer::RuntimeSuffixes.find(suffixKey);

  if( it == SuffixesInitializer::RuntimeSuffixes.end() &&
      typeid( BaseType ) != typeid( DerivedType ) )
  {
    String const derivedTypeSuffix = DerivedType::Suffix();

    SuffixesInitializer::RuntimeSuffixes.insert( SuffixesMap::value_type( suffixKey, SuffixesString( String(), derivedTypeSuffix ) ) );
  }
}


//
//  Definition of assignment operators.
//

template <typename T, typename F>
inline Simple<T,F> const & Simple<T,F>::operator= ( Types::Scalar const _s )
{
  m_Value = _s;
  return *this;
}

template <typename T, typename F>
inline Simple<T,F> const & Simple<T,F>::operator= ( Simple<UnitType,F> const &_s )
{
  m_Value = _s.m_Value;
  return *this;
}


//
//  Definition of public members.
//

template <typename T, typename F>
inline typename Simple<T,F>::ScalarType Simple<T,F>::GetValue() const
{ 
  return m_Value;
}

template <typename T, typename F>
inline void Simple<T,F>::SetValue( ScalarType const _s )
{
  m_Value = _s;
}

template <typename T, typename F>
inline Types::Scalar Simple<T,F>::GetFactor() const
{
  return m_Factor;
}

template <typename T, typename F>
inline typename Simple<T,F>::ScalarType Simple<T,F>::GetConvertedValue() const
{ 
  return OffsetHandler<BaseType, UnitType>::Convert( m_Value * m_Factor );
}

template <typename T, typename F>
inline Types::String Simple<T,F>::GetSuffix() const
{
  if( typeid( BaseType ) != typeid( DerivedType ) )
  {
    return Suffix();
  }

  Detail::SuffixesValue const suffixKey( static_cast<Types::Integer>( NumeratorBaseTypeValue ), static_cast<Types::Integer>( DenumeratorBaseTypeValue ) );

  Detail::SuffixesMap::const_iterator itDerived = Detail::SuffixesInitializer::RuntimeSuffixes.find(suffixKey);

  if( itDerived != Detail::SuffixesInitializer::RuntimeSuffixes.end() )
  {
    Detail::SuffixesString const & suffix = itDerived->second;

    return _Factor::Suffix() + suffix.TypeString;
  }

  Detail::SuffixesKey const keys = Keys( Detail::SuffixesInitializer::RuntimeSuffixes );

  Detail::SuffixesValueMap factors;
  Detail::decomposeFactor( static_cast<Types::Integer>( NumeratorBaseTypeValue ), keys, factors );
  Detail::decomposeFactor( -static_cast<Types::Integer>( DenumeratorBaseTypeValue ), keys, factors );

  if( factors.empty() )
  {
    return Suffix();
  }

  Detail::SuffixesValueMap::const_iterator it = factors.begin();

  Detail::SuffixesString const & suffix_0 = Detail::SuffixesInitializer::RuntimeSuffixes[it->first];

  Types::String runtimeSuffix = suffix_0.FactorString + suffix_0.TypeString + Detail::SuffixExponent( it->second );

  for( ++it; it != factors.end(); ++it )
  {
    Detail::SuffixesString const & suffix_n = Detail::SuffixesInitializer::RuntimeSuffixes[it->first];

    runtimeSuffix += Literals::DOT_OPERATOR + suffix_n.FactorString + suffix_n.TypeString + Detail::SuffixExponent( it->second );
  }

  return SimplifiedFactor::Suffix() + runtimeSuffix;
}

template <typename T, typename F>
inline Types::String Simple<T,F>::GetSISuffix() const
{
  Detail::SuffixesValueMap factors;

  Detail::decomposePrime( static_cast<Types::Integer>( NumeratorBaseTypeValue ), factors );
  Detail::decomposePrime( -static_cast<Types::Integer>( DenumeratorBaseTypeValue ), factors );

  if( factors.empty() )
  {
    return Suffix();
  }

  Detail::SuffixesValueMap::const_iterator it = factors.begin();

  Detail::SuffixesString const & suffix_0 = Detail::SuffixesInitializer::RuntimeSuffixes[it->first];

  Types::String runtimeSuffix = suffix_0.FactorString + suffix_0.TypeString + Detail::SuffixExponent( it->second );

  for( ++it; it != factors.end(); ++it )
  {
    Detail::SuffixesString const & suffix_n = Detail::SuffixesInitializer::RuntimeSuffixes[it->first];

    runtimeSuffix += Literals::DOT_OPERATOR + suffix_n.FactorString + suffix_n.TypeString + Detail::SuffixExponent( it->second );
  }

  return _Factor::Suffix() + runtimeSuffix;
}


//
template <typename F>
inline Simple<Identity,F>::Simple( Types::Scalar const _s ) :
  m_Value( _s )
{
}

template <typename F>
inline Simple<Identity,F>::Simple( Simple<Identity,F> const &_s ) :
  m_Value( _s.m_Value )
{
}

template <typename F>
inline Simple<Identity,F>::operator Types::Scalar() const
{
  return m_Value * F::ConversionFactor();
}


} //Namespace Unit

