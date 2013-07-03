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


#include "UnitObject.h"
#include "UnitHelper.h"


namespace Unit
{


template <typename _UnitType, typename _Factor = Identity>
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
  typedef typename UnitType::InvertedType       InvertedType;
  typedef typename ProductFactor<
    typename _Factor::SimplifiedFactor, 
    typename UnitType::SimplifiedFactor::InvertedFactor>
    ::SimplifiedFactor                          SimplifiedFactor;
  typedef typename _Factor::InvertedFactor      InvertedFactor;
  
  typedef Simple<UnitType,_Factor>              SimpleType;
  typedef Simple<InvertedType,InvertedFactor>   Invert;

  enum { NumeratorBaseTypeValue = SimplifiedType::NumeratorBaseTypeValue };
  enum { DenumeratorBaseTypeValue = SimplifiedType::DenumeratorBaseTypeValue };

public:

  inline Simple();
  inline explicit Simple( ScalarType );
  inline Simple( Simple<UnitType,_Factor> const & );

  template< typename OtherUnitType, typename OtherFactor>
  inline Simple( Simple<OtherUnitType, OtherFactor> const &_s ) :
    m_Value( _s.Simple<OtherUnitType, OtherFactor>::GetValue() * (OtherFactor::ConversionFactor() / m_Factor) )
  {
    typedef Simple<OtherUnitType, OtherFactor> _OtherUnit;

    CompatibleUnit<NumeratorBaseTypeValue == _OtherUnit::NumeratorBaseTypeValue && 
      DenumeratorBaseTypeValue == _OtherUnit::DenumeratorBaseTypeValue>();
  }

public:

  virtual ~Simple() { }

public:

  inline Simple<UnitType,_Factor> const & operator= ( Scalar );
  inline Simple<UnitType,_Factor> const & operator= ( Simple<UnitType,_Factor> const & );

public:

  inline ScalarType GetValue() const;
  inline Scalar GetFactor() const;
  inline ScalarType GetConvertedValue() const;

public:

  inline String GetSuffix() const;

public:

  inline static Scalar ConversionFactor()
  {
    return m_Factor;
  }

  inline static Scalar Epsilon()
  {
    return m_Epsilon;
  }

  inline static String Suffix()
  {
    return _Factor::Suffix() + UnitType::Suffix() + UnitType::SuffixExponent();
  }


protected:

  inline void SetValue( ScalarType );

protected:

  /**
    A scalar to contain the conversion factor.
  */
  static Scalar const m_Factor;


  /**
    A scalar to contain the current epsilon according to precision policy.
  */
  static ScalarType const m_Epsilon;

  /**
    A scalar to contain the raw value.
    This value is expressed in the current unit type.
  */
  ScalarType m_Value;

};

template <typename T, typename F>
Scalar const Simple<T,F>::m_Factor = ::pow( Simple<T,F>::SimplifiedFactor::ConversionFactor(), ::abs( Simple<T,F>::SimplifiedType::Exponent ) );


template <typename T, typename F>
typename Simple<T,F>::ScalarType const Simple<T,F>::m_Epsilon = boost::math::tools::root_epsilon<typename Simple<T,F>::ScalarType>();



template <typename _Factor>
class Simple<Identity,_Factor>
{

  Simple();
  void operator= ( Simple<Identity,_Factor> const & );

public:

  typedef Identity UnitType;
  typedef Identity BaseType;
  typedef Identity SimplifiedType;
  typedef Scalar   ScalarType;
  typedef Identity InvertedType;
  typedef typename _Factor::SimplifiedFactor SimplifiedFactor;
  typedef typename _Factor::InvertedFactor InvertedFactor;
  
  typedef Simple<UnitType,_Factor> SimpleType;
  typedef Simple<InvertedType,InvertedFactor> Invert;

public:

  inline Simple( Scalar );
  inline Simple( Simple<Identity,_Factor> const & );

  ~Simple() { }

public:

  inline operator Scalar() const;

protected:

  /**
    A scalar to contain the raw value.
    This value is expressed in the current unit type.
  */
  Scalar const m_Value;

};


//
//  Definition of constructors
//

template <typename T, typename F>
inline Simple<T,F>::Simple() :
  m_Value( 0. )
{
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



//
//  Definition of assignment operators.
//

template <typename T, typename F>
inline Simple<T,F> const & Simple<T,F>::operator= ( Scalar const _s )
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
inline Scalar Simple<T,F>::GetFactor() const
{
  return m_Factor;
}

template <typename T, typename F>
inline typename Simple<T,F>::ScalarType Simple<T,F>::GetConvertedValue() const
{ 
  return m_Value * m_Factor;
}

template <typename T, typename F>
inline String Simple<T,F>::GetSuffix() const
{
  boost::unordered_map<Integer, Integer> factors;
   
  decompose( static_cast<Integer>( NumeratorBaseTypeValue ), factors );
  decompose( -static_cast<Integer>( DenumeratorBaseTypeValue ), factors );

  boost::unordered_map<Integer, Integer>::const_iterator it = factors.begin();

  std::pair<String, String> const & suffix_0 = Object<ScalarType>::RuntimeSuffix[it->first];

  String runtimeSuffix = (factors.size() > 1 ? suffix_0.first : String()) + suffix_0.second + SuffixExponent( it->second );

  for( ++it; it != factors.end(); ++it )
  {
    std::pair<String, String> const & suffix_n = Object<ScalarType>::RuntimeSuffix[it->first];

    runtimeSuffix += DOT_OPERATOR + suffix_n.first + suffix_n.second + SuffixExponent( it->second );
  }

  return _Factor::Suffix() + runtimeSuffix;
}

//
template <typename F>
inline Simple<Identity,F>::Simple( Scalar const _s ) :
  m_Value( _s )
{
}

template <typename F>
inline Simple<Identity,F>::Simple( Simple<Identity,F> const &_s ) :
  m_Value( _s.m_Value )
{
}

template <typename F>
inline Simple<Identity,F>::operator Scalar() const
{
  return m_Value;
}


} //Namespace Unit

