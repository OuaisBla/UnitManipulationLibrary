/*
Unit Manipulation Library.
Copyright (C) 2002-2013 Jean Gauthier

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
#include <boost/utility/enable_if.hpp>


namespace Unit
{


/**
  Class that helps to simplify a unit type. (Specialization)
*/

template <typename T>
class BaseUnit<T,0>
{
public:

  typedef Identity BaseType;
  typedef Identity DerivedType;
  typedef Identity SimplifiedType;
  typedef Identity InvertedType;
  typedef Identity SimplifiedFactor;

  static bool const is_simple = true;

  typedef Identity L;
  typedef Identity R;


  typedef Identity::ScalarType   ScalarType;
  typedef Identity::Policy       Policy;
  typedef Identity::Limits       Limits;

};


/**
  Class that represents a product of unit type.
*/

template <typename _L, typename _R = _L, typename Enable = void>
class ComplexUnit : public Object<typename _L::ScalarType, typename _L::Policy>
{

  template <typename A, typename B, typename E> friend class ComplexUnit;

  enum 
  {
    _NumeratorBaseTypeValue = _L::NumeratorBaseTypeValue * _R::NumeratorBaseTypeValue,
    _DenumeratorBaseTypeValue = _L::DenumeratorBaseTypeValue * _R::DenumeratorBaseTypeValue,
    _gcd = boost::math::static_gcd<_NumeratorBaseTypeValue, _DenumeratorBaseTypeValue>::value 
  };

public:

  enum 
  { 
    NumeratorBaseTypeValue = _NumeratorBaseTypeValue / _gcd, 
    DenumeratorBaseTypeValue = _DenumeratorBaseTypeValue / _gcd,
    BaseTypeValue = NumeratorBaseTypeValue * DenumeratorBaseTypeValue
  };

  typedef ComplexUnit<_L,_R>              BaseType;
  typedef BaseType                        DerivedType;
  typedef BaseUnit<BaseType>              SimplifiedType;
  typedef BaseUnit<BaseType,-1>           InvertedType;
  typedef Identity                        SimplifiedFactor;

  static bool const is_simple = false;

  typedef _L L;
  typedef _R R;

public:

  inline static Types::String Suffix()
  {
    return _L::Suffix() + Literals::DOT_OPERATOR + _R::Suffix();
  }

};



/**
  Helper class that helps to simplify products of unit type.
*/


template <>
struct ComplexUnit<Identity,Identity>
{

  enum 
  { 
    NumeratorBaseTypeValue = Identity::NumeratorBaseTypeValue,
    DenumeratorBaseTypeValue = Identity::DenumeratorBaseTypeValue,
    BaseTypeValue = NumeratorBaseTypeValue * DenumeratorBaseTypeValue 
  };

  typedef Identity  BaseType;
  typedef Identity  DerivedType;
  typedef Identity  SimplifiedType;
  typedef Identity  InvertedType;
  typedef Identity  SimplifiedFactor;

  typedef Identity::ScalarType            ScalarType;
  typedef Identity::Policy                Policy;
  typedef Identity::Limits                Limits;

  static bool const is_simple = false;

  typedef Identity L;
  typedef Identity R;

};

template <typename _L>
struct ComplexUnit<_L,Identity> : 
  public Object<typename _L::ScalarType, typename _L::Policy>
{

  enum 
  { 
    NumeratorBaseTypeValue = _L::NumeratorBaseTypeValue,
    DenumeratorBaseTypeValue = _L::DenumeratorBaseTypeValue,
    BaseTypeValue = NumeratorBaseTypeValue * DenumeratorBaseTypeValue 
  };

  typedef typename _L::BaseType BaseType;
  typedef typename _L::DerivedType DerivedType;
  typedef typename _L::SimplifiedType SimplifiedType;
  typedef typename _L::InvertedType InvertedType;
  typedef typename _L::SimplifiedFactor SimplifiedFactor;

  static bool const is_simple = false;

  typedef _L L;
  typedef _L R;

};

template <typename _L>
struct ComplexUnit<Identity,_L> : 
  public Object<typename _L::ScalarType, typename _L::Policy>
{

  enum 
  { 
    NumeratorBaseTypeValue = _L::NumeratorBaseTypeValue,
    DenumeratorBaseTypeValue = _L::DenumeratorBaseTypeValue,
    BaseTypeValue = NumeratorBaseTypeValue * DenumeratorBaseTypeValue 
  };

  typedef typename _L::BaseType BaseType;
  typedef typename _L::DerivedType DerivedType;
  typedef typename _L::SimplifiedType SimplifiedType;
  typedef typename _L::InvertedType InvertedType;
  typedef typename _L::SimplifiedFactor SimplifiedFactor;

  static bool const is_simple = false;

  typedef _L L;
  typedef _L R;

};

template <typename _L, Types::Integer a, Types::Integer b>
struct ComplexUnit<BaseUnit<_L,a>, BaseUnit<_L,b>> : 
  public Object<typename _L::ScalarType, typename _L::Policy>
{

  enum 
  { 
    NumeratorBaseTypeValue = _L::NumeratorBaseTypeValue,
    DenumeratorBaseTypeValue = _L::DenumeratorBaseTypeValue,
    BaseTypeValue = NumeratorBaseTypeValue * DenumeratorBaseTypeValue
  };

  typedef typename _L::BaseType BaseType;
  typedef typename _L::DerivedType DerivedType;
  typedef typename BaseUnit<BaseType,a+b>::SimplifiedType SimplifiedType;
  typedef typename SimplifiedType::InvertedType InvertedType;
  typedef typename _L::SimplifiedFactor SimplifiedFactor;

  static bool const is_simple = false;

  typedef SimplifiedType L;
  typedef SimplifiedType R;

};

template <typename _L, typename _R>
class ComplexUnit<_L, _R, 
  typename boost::enable_if_c<_L::BaseTypeValue != _R::BaseTypeValue && !_L::is_simple && _R::is_simple>::type> : 
  public Object<typename _L::ScalarType, typename _L::Policy>
{

  enum {
    _NumeratorBaseTypeValue = _L::NumeratorBaseTypeValue * _R::NumeratorBaseTypeValue,
    _DenumeratorBaseTypeValue = _L::DenumeratorBaseTypeValue * _R::DenumeratorBaseTypeValue,
    _gcd = boost::math::static_gcd<_NumeratorBaseTypeValue, _DenumeratorBaseTypeValue>::value 
  };

public:

  enum 
  { 
    NumeratorBaseTypeValue = _NumeratorBaseTypeValue / _gcd,
    DenumeratorBaseTypeValue = _DenumeratorBaseTypeValue / _gcd,
    BaseTypeValue = NumeratorBaseTypeValue * DenumeratorBaseTypeValue 
  };

  typedef typename _L::L _L_L;
  typedef typename _L::R _L_R;

  typedef typename ComplexUnit<typename _L_L::SimplifiedType, typename _R::SimplifiedType>::SimplifiedType _L_L_R_SimplifiedType;
  typedef ComplexUnit<typename _L_R::SimplifiedType, _L_L_R_SimplifiedType> _SimplifiedType;

  typedef typename _SimplifiedType::L L;
  typedef typename _SimplifiedType::R R;

  typedef typename _SimplifiedType::BaseType   BaseType;
  typedef BaseType                             DerivedType;
  typedef BaseUnit<BaseType>                   SimplifiedType;
  typedef BaseUnit<BaseType,-1>                InvertedType;
  typedef typename BaseType::SimplifiedFactor  SimplifiedFactor;

  static bool const is_simple = BaseType::is_simple;

public:

  inline static Types::String Suffix()
  {
    return _L::Suffix() + Literals::DOT_OPERATOR + _R::Suffix();
  }

};
/*

template <typename _L, typename _R>
class ComplexUnit<_L, _R, 
  typename boost::enable_if_c<_L::BaseTypeValue != _R::BaseTypeValue && _L::is_simple && !_R::is_simple>::type> : 
  public Object<typename _L::ScalarType, typename _L::Policy>
{

  enum {
    _NumeratorBaseTypeValue = _L::NumeratorBaseTypeValue * _R::NumeratorBaseTypeValue,
    _DenumeratorBaseTypeValue = _L::DenumeratorBaseTypeValue * _R::DenumeratorBaseTypeValue,
    _gcd = boost::math::static_gcd<_NumeratorBaseTypeValue, _DenumeratorBaseTypeValue>::value 
  };

public:

  enum
  { 
    NumeratorBaseTypeValue = _NumeratorBaseTypeValue / _gcd,
    DenumeratorBaseTypeValue = _DenumeratorBaseTypeValue / _gcd,
    BaseTypeValue = NumeratorBaseTypeValue * DenumeratorBaseTypeValue 
  };

  typedef typename _R::L _R_L;
  typedef typename _R::R _R_R;

  typedef typename ComplexUnit<typename _R_L::SimplifiedType, typename _L::SimplifiedType>::SimplifiedType _R_L_R_SimplifiedType;
  typedef ComplexUnit<_R_L_R_SimplifiedType, typename _R_R::SimplifiedType> _SimplifiedType;

  typedef typename _SimplifiedType::L L;
  typedef typename _SimplifiedType::R R;

  typedef typename _SimplifiedType::BaseType   BaseType;
  typedef BaseType                             DerivedType;
  typedef BaseUnit<BaseType>                   SimplifiedType;
  typedef BaseUnit<BaseType,-1>                InvertedType;
  typedef typename BaseType::SimplifiedFactor  SimplifiedFactor;

  static bool const is_simple = BaseType::is_simple;

public:

  inline static Types::String Suffix()
  {
    return _L::Suffix() + Literals::DOT_OPERATOR + _R::Suffix();
  }

};



template <typename _L, typename _R>
class ComplexUnit<_L, _R, 
  typename boost::enable_if_c<_L::BaseTypeValue != _R::BaseTypeValue && !is_simple_unit<_L>::value && !is_simple_unit<_R>::value>::type> : 
  public Object<>, public Facade<ComplexUnit<_L,_R> >
{

  enum {
    _NumeratorBaseTypeValue = _L::NumeratorBaseTypeValue * _R::NumeratorBaseTypeValue,
    _DenumeratorBaseTypeValue = _L::DenumeratorBaseTypeValue * _R::DenumeratorBaseTypeValue,
    _gcd = boost::math::static_gcd<_NumeratorBaseTypeValue, _DenumeratorBaseTypeValue>::value 
  };

public:

  enum
  { 
    NumeratorBaseTypeValue = _NumeratorBaseTypeValue / _gcd,
    DenumeratorBaseTypeValue = _DenumeratorBaseTypeValue / _gcd,
    BaseTypeValue = NumeratorBaseTypeValue * DenumeratorBaseTypeValue 
  };

  typedef typename _L::L _L_L;
  typedef typename _L::R _L_R;
  typedef typename _R::L _R_L;
  typedef typename _R::R _R_R;

  typedef typename ComplexUnit<typename _L_L::SimplifiedType, typename _R_L::SimplifiedType>::SimplifiedType _L_L_R_L_SimplifiedType;
  typedef typename ComplexUnit<typename _L_L::SimplifiedType, typename _R_R::SimplifiedType>::SimplifiedType _L_L_R_R_SimplifiedType;
  typedef typename ComplexUnit<typename _L_R::SimplifiedType, typename _R_L::SimplifiedType>::SimplifiedType _L_R_R_L_SimplifiedType;
  typedef typename ComplexUnit<typename _L_R::SimplifiedType, typename _R_R::SimplifiedType>::SimplifiedType _L_R_R_R_SimplifiedType;

  typedef typename ComplexUnit<_L_L_R_L_SimplifiedType, typename BaseUnit<_L_L_R_R_SimplifiedType,-1>::SimplifiedType>::SimplifiedType _L_SimplifiedType;
  typedef typename ComplexUnit<_L_R_R_L_SimplifiedType, typename BaseUnit<_L_R_R_R_SimplifiedType,-1>::SimplifiedType>::SimplifiedType _R_SimplifiedType;

  typedef typename _L_SimplifiedType::L __L;
  typedef typename _R_SimplifiedType::R __R;

  typedef typename __L::SimplifiedType L;
  typedef typename __R::SimplifiedType R;

  typedef typename ComplexUnit<L, R>::BaseType   BaseType;
  typedef BaseType                               DerivedType;
  typedef BaseUnit<BaseType>                     SimplifiedType;
  typedef BaseUnit<BaseType,-1>                  InvertedType;

  static bool const is_simple = BaseType::is_simple;

public:

  inline static Types::String Suffix()
  {
    return _L::Suffix() + Literals::DOT_OPERATOR + _R::Suffix();
  }

};
  */

} //namespace Unit
