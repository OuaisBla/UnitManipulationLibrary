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
class BaseUnit<T,0> : public Identity
{

};


/**
  Class that represents a product of unit type.
*/

template <typename _L, typename _R = _L, typename Enable = void>
class ComplexUnit : public Object<typename _L::ScalarType, typename _L::Policy>
{

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
  typedef ComplexUnit<_L,_R>              DerivedType;
  typedef BaseUnit<BaseType>              SimplifiedType;
  typedef BaseUnit<BaseType,-1>           InvertedType;
  typedef Identity                        SimplifiedFactor;

public:

  inline static Types::String Suffix()
  {
    return _L::Suffix() + Literals::DOT_OPERATOR + _R::Suffix();
  }

};

template <typename _L, typename _R, Types::Integer a>
class BaseUnit<ComplexUnit<BaseUnit<_L, 0>, BaseUnit<_R, 0>>, a> : public Identity
{

};


/**
  Helper class that helps to simplify products of unit type.
*/


template <>
class ComplexUnit<Identity,Identity> : public Identity
{

};

template <typename _L>
class ComplexUnit<_L,Identity> : public _L
{

};

template <typename _L>
class ComplexUnit<Identity,_L> : public _L
{

};

template <typename _L, Types::Integer a, Types::Integer b>
class ComplexUnit<BaseUnit<_L,a>, BaseUnit<_L,b>> :
  public Object<typename _L::ScalarType, typename _L::Policy>
{
public:

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
  typedef typename SimplifiedType::SimplifiedFactor SimplifiedFactor;

};

template <typename _L, Types::Integer a, Types::Integer b, Types::Integer c, Types::Integer d>
class ComplexUnit<BaseUnit<ComplexUnit<BaseUnit<_L,a>, BaseUnit<_L, b>>,c>, BaseUnit<_L, d>> :
  public Object<typename _L::ScalarType, typename _L::Policy>
{
public:

  enum
  {
    NumeratorBaseTypeValue = _L::NumeratorBaseTypeValue,
    DenumeratorBaseTypeValue = _L::DenumeratorBaseTypeValue,
    BaseTypeValue = NumeratorBaseTypeValue * DenumeratorBaseTypeValue
  };

  typedef typename _L::BaseType BaseType;
  typedef typename _L::DerivedType DerivedType;
  typedef typename BaseUnit<BaseType, ((a + b) * c) + d>::SimplifiedType SimplifiedType;
  typedef typename SimplifiedType::InvertedType InvertedType;
  typedef typename SimplifiedType::SimplifiedFactor SimplifiedFactor;

};

template <typename _L, typename _R, Types::Integer a, Types::Integer b, Types::Integer c, Types::Integer d>
class ComplexUnit<BaseUnit<ComplexUnit<BaseUnit<_L, a>, BaseUnit<_R, b>>, c>, BaseUnit<_L, d>> :
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

  typedef BaseUnit<_L, (a * c) + d> L;
  typedef BaseUnit<_R, (a * c)> R;

  typedef ComplexUnit<L,R>  BaseType;
  typedef ComplexUnit<L,R>  DerivedType;
  typedef typename BaseUnit<BaseType>::SimplifiedType SimplifiedType;
  typedef typename SimplifiedType::InvertedType InvertedType;
  typedef typename SimplifiedType::SimplifiedFactor SimplifiedFactor;

};

template <typename _L, typename _R, Types::Integer a, Types::Integer b, Types::Integer c, Types::Integer d>
class ComplexUnit<BaseUnit<ComplexUnit<BaseUnit<_L, a>, BaseUnit<_R, b>>, c>, BaseUnit<_R, d>> :
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

  typedef BaseUnit<_L, (a * c)> L;
  typedef BaseUnit<_R, (b * c) + d> R;

  typedef ComplexUnit<L, R>  BaseType;
  typedef ComplexUnit<L, R>  DerivedType;
  typedef typename BaseUnit<BaseType>::SimplifiedType SimplifiedType;
  typedef typename SimplifiedType::InvertedType InvertedType;
  typedef typename SimplifiedType::SimplifiedFactor SimplifiedFactor;

};

template <typename _L, Types::Integer a, Types::Integer b, Types::Integer c, Types::Integer d, Types::Integer e, Types::Integer f>
class ComplexUnit<BaseUnit<ComplexUnit<BaseUnit<_L, a>, BaseUnit<_L, b>>, c>, BaseUnit<ComplexUnit<BaseUnit<_L, d>, BaseUnit<_L, e>>, f>> :
  public Object<typename _L::ScalarType, typename _L::Policy>
{
public:

  enum
  {
    NumeratorBaseTypeValue = _L::NumeratorBaseTypeValue,
    DenumeratorBaseTypeValue = _L::DenumeratorBaseTypeValue,
    BaseTypeValue = NumeratorBaseTypeValue * DenumeratorBaseTypeValue
  };

  typedef typename _L::BaseType BaseType;
  typedef typename _L::DerivedType DerivedType;
  typedef typename BaseUnit<BaseType, ((a + b) * c) + ((d + e) * f)>::SimplifiedType SimplifiedType;
  typedef typename SimplifiedType::InvertedType InvertedType;
  typedef typename SimplifiedType::SimplifiedFactor SimplifiedFactor;

};

template <typename _L, typename _R, Types::Integer a, Types::Integer b, Types::Integer c, Types::Integer d, Types::Integer e, Types::Integer f>
class ComplexUnit<BaseUnit<ComplexUnit<BaseUnit<_L, a>, BaseUnit<_R, b>>, c>, BaseUnit<ComplexUnit<BaseUnit<_R, d>, BaseUnit<_L, e>>, f>> :
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

  typedef BaseUnit<_L, (a * c) + (e * f)> L;
  typedef BaseUnit<_R, (b * c) + (d * f)> R;

  typedef ComplexUnit<L, R>  BaseType;
  typedef ComplexUnit<L, R>  DerivedType;
  typedef typename BaseUnit<BaseType>::SimplifiedType SimplifiedType;
  typedef typename SimplifiedType::InvertedType InvertedType;
  typedef typename SimplifiedType::SimplifiedFactor SimplifiedFactor;

};

} //namespace Unit
