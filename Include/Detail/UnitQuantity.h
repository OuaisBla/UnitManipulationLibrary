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
class Quantity : public _UnitType
{
public:

  typedef _UnitType                                         UnitType;
  typedef _Factor                                           _Factor;

  typedef typename UnitType::ScalarType                     ScalarType;
  typedef typename UnitType::Policy                         Policy;
  typedef typename UnitType::Limits                         Limits;


  typedef typename UnitType::SimplifiedType                 SimplifiedType;
  typedef typename SimplifiedType::BaseType                 BaseType;
  typedef typename UnitType::DerivedType                    DerivedType;
  typedef typename UnitType::InvertedType                   InvertedType;
  typedef typename ProductFactor<
    typename _Factor::SimplifiedFactor, 
    typename UnitType::SimplifiedFactor>::SimplifiedFactor  SimplifiedFactor;
  typedef typename SimplifiedFactor::InvertedFactor  
                                                            InvertedFactor;
  
  typedef Quantity<SimplifiedType,SimplifiedFactor>         QuantityType;
  typedef Quantity<InvertedType,InvertedFactor>             Invert;

  enum { Exponent = SimplifiedType::Exponent };
  enum { NumeratorBaseTypeValue = SimplifiedType::NumeratorBaseTypeValue };
  enum { DenumeratorBaseTypeValue = SimplifiedType::DenumeratorBaseTypeValue };

public:

  inline Quantity();
  inline explicit Quantity( ScalarType );
  inline Quantity( Quantity<UnitType,_Factor> const & );

  template< typename OtherUnitType, typename OtherFactor>
  inline Quantity( Quantity<OtherUnitType, OtherFactor> const &_s ) :
    m_Value( OffsetHandler<UnitType, OtherUnitType>::Convert( _s.Quantity<OtherUnitType, OtherFactor>::GetValue() * (Quantity<OtherUnitType, OtherFactor>::ConversionFactor() / m_Factor) ) )
  {
    typedef Quantity<OtherUnitType, OtherFactor> _OtherUnit;

    std::is_convertible<ScalarType, typename _OtherUnit::ScalarType>();

    Detail::CompatibleUnit<NumeratorBaseTypeValue == _OtherUnit::NumeratorBaseTypeValue && 
      DenumeratorBaseTypeValue == _OtherUnit::DenumeratorBaseTypeValue>();
  }

  virtual ~Quantity() { }

public:

  inline Quantity<UnitType,_Factor> const & operator= ( Types::Scalar );
  inline Quantity<UnitType,_Factor> const & operator= ( Quantity<UnitType,_Factor> const & );

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
    return _Factor::Suffix() + DerivedType::Suffix() + Detail::SuffixExponent( static_cast<Types::Integer>( Exponent ) );
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

  inline explicit Quantity( void *, void * ); 

#ifndef NO_STATIC_UNIT_SUFFIXES_EVALUATION
  static Quantity const RuntimeSuffixesCtor;
#else
  friend class Detail::SuffixesInitializer;
#endif

};


template <typename _Factor>
class Quantity<Identity,_Factor>
{

  Quantity();
  void operator= ( Quantity<Identity,_Factor> const & );

public:

  typedef Identity UnitType;
  typedef Identity BaseType;
  typedef Identity SimplifiedType;
  typedef Types::Scalar   ScalarType;
  typedef Identity InvertedType;
  typedef typename _Factor::SimplifiedFactor SimplifiedFactor;
  typedef typename _Factor::InvertedFactor InvertedFactor;
  
  typedef Quantity<UnitType,_Factor> QuantityType;
  typedef Quantity<InvertedType,InvertedFactor> Invert;

public:

  inline Quantity( Types::Scalar );
  inline Quantity( Quantity<Identity,_Factor> const & );

  ~Quantity() { }

public:

  inline operator Types::Scalar() const;

  inline static Types::Scalar ConversionFactor()
  {
    return 1.0;
  }

protected:

  /**
    A scalar to contain the raw value.
    This value is expressed in the current unit type.
  */
  Types::Scalar const m_Value;

};


template <typename T, typename F>
Types::Scalar const Quantity<T,F>::m_Factor = ::pow( Quantity<T,F>::SimplifiedFactor::ConversionFactor(), ::abs( Quantity<T,F>::Exponent ) );


template <typename T, typename F>
typename Quantity<T,F>::ScalarType const Quantity<T,F>::m_Epsilon = boost::math::tools::root_epsilon<typename Quantity<T,F>::ScalarType>();


#ifndef NO_STATIC_UNIT_SUFFIXES_EVALUATION
template <typename T, typename F>
Quantity<T,F> const Quantity<T,F>::RuntimeSuffixesCtor( NULL, NULL );
#endif


//
//  Definition of constructors
//

template <typename T, typename F>
inline Quantity<T,F>::Quantity() :
  m_Value( 0. )
{
#ifndef NO_STATIC_UNIT_SUFFIXES_EVALUATION
  static Quantity<T,F> __ForceLinker = Quantity<T,F>::RuntimeSuffixesCtor;
#endif
}

template <typename T, typename F>
inline Quantity<T,F>::Quantity( ScalarType const _v ) :
  m_Value( _v )
{
}

template <typename T, typename F>
inline Quantity<T,F>::Quantity( Quantity<UnitType,F> const &_s ) :
  m_Value( _s.m_Value )
{
}

template <typename T, typename F>
inline Quantity<T,F>::Quantity( void *, void * ) 
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
inline Quantity<T,F> const & Quantity<T,F>::operator= ( Types::Scalar const _s )
{
  m_Value = _s;
  return *this;
}

template <typename T, typename F>
inline Quantity<T,F> const & Quantity<T,F>::operator= ( Quantity<UnitType,F> const &_s )
{
  m_Value = _s.m_Value;
  return *this;
}


//
//  Definition of public members.
//

template <typename T, typename F>
inline typename Quantity<T,F>::ScalarType Quantity<T,F>::GetValue() const
{ 
  return m_Value;
}

template <typename T, typename F>
inline void Quantity<T,F>::SetValue( ScalarType const _s )
{
  m_Value = _s;
}

template <typename T, typename F>
inline Types::Scalar Quantity<T,F>::GetFactor() const
{
  return m_Factor;
}

template <typename T, typename F>
inline typename Quantity<T,F>::ScalarType Quantity<T,F>::GetConvertedValue() const
{ 
  return OffsetHandler<BaseType, UnitType>::Convert( m_Value * m_Factor );
}

template <typename T, typename F>
inline Types::String Quantity<T,F>::GetSuffix() const
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

    return _Factor::Suffix() + suffix.BaseUnitSI;
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

  Types::String runtimeSuffix = suffix_0.QuantityUnit + Detail::SuffixExponent( it->second );

  for( ++it; it != factors.end(); ++it )
  {
    Detail::SuffixesString const & suffix_n = Detail::SuffixesInitializer::RuntimeSuffixes[it->first];

    runtimeSuffix += Literals::DOT_OPERATOR + suffix_n.QuantityUnit + Detail::SuffixExponent( it->second );
  }

  return SimplifiedFactor::Suffix() + runtimeSuffix;
}

template <typename T, typename F>
inline Types::String Quantity<T,F>::GetSISuffix() const
{
  Detail::SuffixesValueMap factors;

  Detail::decomposePrime( static_cast<Types::Integer>( NumeratorBaseTypeValue ), factors );
  Detail::decomposePrime( -static_cast<Types::Integer>( DenumeratorBaseTypeValue ), factors );

  if( factors.empty() )
  {
    return Suffix();
  }

  Detail::SuffixesValueMap::const_iterator it = factors.begin();

  Detail::SuffixesMap::const_iterator iSuffix = Detail::SuffixesInitializer::RuntimeSuffixes.find(it->first);

  if( iSuffix == Detail::SuffixesInitializer::RuntimeSuffixes.end() )
  {
    throw std::runtime_error( "error: incomplete base unit" );
  }

  Detail::SuffixesString const & suffix_0 = iSuffix->second;

  //Simple quantity are expressed using BaseUnitSI. Ie. scale + g
  if( factors.size() == 1 )
  {
    typedef typename ProductFactor<SimplifiedFactor, typename BaseType::SimplifiedFactor::InvertedFactor> _BaseUnitFactor;

    Types::String const runtimeSuffix = _BaseUnitFactor::Suffix() + suffix_0.BaseUnitSI + Detail::SuffixExponent( it->second );

    return runtimeSuffix;
  }

  //Complex unit type are expressed using QuantityUnit string. Ie. scale + (kg * m).
  Types::String runtimeSuffix = suffix_0.QuantityUnit + Detail::SuffixExponent( it->second );

  for( ++it; it != factors.end(); ++it )
  {
    iSuffix = Detail::SuffixesInitializer::RuntimeSuffixes.find(it->first);

    if( iSuffix == Detail::SuffixesInitializer::RuntimeSuffixes.end() )
    {
      throw std::runtime_error("error: incomplete base unit");
    }

    Detail::SuffixesString const & suffix_n = iSuffix->second;

    runtimeSuffix += Literals::DOT_OPERATOR + suffix_n.QuantityUnit + Detail::SuffixExponent( it->second );
  }

  return _Factor::Suffix() + runtimeSuffix;
}


//
template <typename F>
inline Quantity<Identity,F>::Quantity( Types::Scalar const _s ) :
  m_Value( _s )
{
}

template <typename F>
inline Quantity<Identity,F>::Quantity( Quantity<Identity,F> const &_s ) :
  m_Value( _s.m_Value )
{
}

template <typename F>
inline Quantity<Identity,F>::operator Types::Scalar() const
{
  return m_Value * F::ConversionFactor();
}


} //Namespace Unit

