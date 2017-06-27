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


namespace Unit
{


/**
  Class that helps to simplify a unit type. (Specialization)
*/

template <typename T>
class BaseUnit<T,0> : public Identity
{

};

template <Types::Integer a>
class BaseUnit<Identity, a> : public Identity
{

};


/**
  Class that represents a product of unit type.
*/

template <typename _L, typename _R = _L>
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

  typedef typename _L::BaseType BaseType;
  typedef typename _L::DerivedType DerivedType;
  typedef typename BaseUnit<BaseType,a+b>::SimplifiedType SimplifiedType;
  typedef typename SimplifiedType::InvertedType InvertedType;
  typedef typename SimplifiedType::SimplifiedFactor SimplifiedFactor;

  enum
  {
    NumeratorBaseTypeValue = BaseType::NumeratorBaseTypeValue,
    DenumeratorBaseTypeValue = BaseType::DenumeratorBaseTypeValue
  };


};

template <typename _L, typename _R, Types::Integer a, Types::Integer b, Types::Integer c, Types::Integer d>
class ComplexUnit<BaseUnit<ComplexUnit<BaseUnit<_L, a>, BaseUnit<_R, b>>, c>, BaseUnit<_L, d>> :
  public Object<typename _L::ScalarType, typename _L::Policy>
{

  typedef typename BaseUnit<_L, (a * c) + d>::SimplifiedType L;
  typedef typename BaseUnit<_R, (a * c)>::SimplifiedType R;

public:

  typedef typename ComplexUnit<L,R>::BaseType BaseType;
  typedef ComplexUnit<typename L::DerivedType, typename R::DerivedType>  DerivedType;
  typedef typename BaseUnit<BaseType>::SimplifiedType SimplifiedType;
  typedef typename SimplifiedType::InvertedType InvertedType;
  typedef typename SimplifiedType::SimplifiedFactor SimplifiedFactor;

  enum
  {
    NumeratorBaseTypeValue = BaseType::NumeratorBaseTypeValue,
    DenumeratorBaseTypeValue = BaseType::DenumeratorBaseTypeValue
  };


};

template <typename _L, typename _R, Types::Integer a, Types::Integer b, Types::Integer c, Types::Integer d>
class ComplexUnit<BaseUnit<ComplexUnit<BaseUnit<_L, a>, BaseUnit<_R, b>>, c>, BaseUnit<_R, d>> :
  public Object<typename _L::ScalarType, typename _L::Policy>
{

  typedef typename BaseUnit<_L, (a * c)>::SimplifiedType L;
  typedef typename BaseUnit<_R, (b * c) + d>::SimplifiedType R;

public:

  typedef typename ComplexUnit<L, R>::BaseType BaseType;
  typedef ComplexUnit<typename L::DerivedType, typename R::DerivedType>  DerivedType;
  typedef typename BaseUnit<BaseType>::SimplifiedType SimplifiedType;
  typedef typename SimplifiedType::InvertedType InvertedType;
  typedef typename SimplifiedType::SimplifiedFactor SimplifiedFactor;

  enum
  {
    NumeratorBaseTypeValue = BaseType::NumeratorBaseTypeValue,
    DenumeratorBaseTypeValue = BaseType::DenumeratorBaseTypeValue
  };

};

template <typename _L, typename _R, Types::Integer a, Types::Integer b, Types::Integer c, Types::Integer d>
class ComplexUnit<BaseUnit<_R, d>, BaseUnit<ComplexUnit<BaseUnit<_L, a>, BaseUnit<_R, b>>, c>> :
  public Object<typename _L::ScalarType, typename _L::Policy>
{

  typedef typename BaseUnit<_L, (a * c)>::SimplifiedType L;
  typedef typename BaseUnit<_R, (b * c) + d>::SimplifiedType R;

public:

  typedef typename ComplexUnit<L, R>::BaseType BaseType;
  typedef ComplexUnit<typename L::DerivedType, typename R::DerivedType>  DerivedType;
  typedef typename BaseUnit<BaseType>::SimplifiedType SimplifiedType;
  typedef typename SimplifiedType::InvertedType InvertedType;
  typedef typename SimplifiedType::SimplifiedFactor SimplifiedFactor;

  enum
  {
    NumeratorBaseTypeValue = BaseType::NumeratorBaseTypeValue,
    DenumeratorBaseTypeValue = BaseType::DenumeratorBaseTypeValue
  };

};


template <typename _L, Types::Integer a, Types::Integer b, Types::Integer c, Types::Integer d, Types::Integer e, Types::Integer f>
class ComplexUnit<BaseUnit<ComplexUnit<BaseUnit<_L, a>, BaseUnit<_L, b>>, c>, BaseUnit<ComplexUnit<BaseUnit<_L, d>, BaseUnit<_L, e>>, f>> :
  public Object<typename _L::ScalarType, typename _L::Policy>
{
public:

  typedef typename _L::BaseType BaseType;
  typedef typename _L::DerivedType DerivedType;
  typedef typename BaseUnit<BaseType, ((a + b) * c) + ((d + e) * f)>::SimplifiedType SimplifiedType;
  typedef typename SimplifiedType::InvertedType InvertedType;
  typedef typename SimplifiedType::SimplifiedFactor SimplifiedFactor;

  enum
  {
    NumeratorBaseTypeValue = BaseType::NumeratorBaseTypeValue,
    DenumeratorBaseTypeValue = BaseType::DenumeratorBaseTypeValue
  };

};

template <typename _L, typename _R, Types::Integer a, Types::Integer b, Types::Integer c, Types::Integer d, Types::Integer e, Types::Integer f>
class ComplexUnit<BaseUnit<ComplexUnit<BaseUnit<_L, a>, BaseUnit<_R, b>>, c>, BaseUnit<ComplexUnit<BaseUnit<_R, d>, BaseUnit<_L, e>>, f>> :
  public Object<typename _L::ScalarType, typename _L::Policy>
{

  typedef typename BaseUnit<_L, (a * c) + (e * f)>::SimplifiedType L;
  typedef typename BaseUnit<_R, (b * c) + (d * f)>::SimplifiedType R;

public:

  typedef typename ComplexUnit<L, R>::BaseType BaseType;
  typedef ComplexUnit<typename L::DerivedType, typename R::DerivedType>  DerivedType;
  typedef typename BaseUnit<BaseType>::SimplifiedType SimplifiedType;
  typedef typename SimplifiedType::InvertedType InvertedType;
  typedef typename SimplifiedType::SimplifiedFactor SimplifiedFactor;

  enum
  {
    NumeratorBaseTypeValue = BaseType::NumeratorBaseTypeValue,
    DenumeratorBaseTypeValue = BaseType::DenumeratorBaseTypeValue
  };

};


template <typename _A, typename _B, typename _C, Types::Integer a, Types::Integer b, Types::Integer c, Types::Integer d, Types::Integer e, Types::Integer f, Types::Integer g, Types::Integer h, Types::Integer i, Types::Integer j>
class ComplexUnit<
    BaseUnit<
      ComplexUnit<
        BaseUnit<_A, a>,
        BaseUnit<ComplexUnit<
                    BaseUnit<_B, b>, 
                    BaseUnit<_C, c>>,d>>, e>,
     BaseUnit<
        ComplexUnit<
          BaseUnit<ComplexUnit<
                    BaseUnit<_B, f>,
                    BaseUnit<_A, g>>,h>,
          BaseUnit<_C, i>>,j>> : 
  public Object<typename _A::ScalarType, typename _A::Policy>
{

  typedef typename BaseUnit<_A, (a * e) + (g * h * j)>::SimplifiedType A;
  typedef typename BaseUnit<_B, (b * d * e) + (f * h * j)>::SimplifiedType B;

  typedef typename ComplexUnit<A,B>::SimplifiedType L;
  typedef typename BaseUnit<_C, (c * d * e) + (i * j)>::SimplifiedType R;
  
public:

  typedef typename ComplexUnit<L,R>::BaseType BaseType;
  typedef ComplexUnit<typename L::DerivedType, typename R::DerivedType>  DerivedType;
  typedef typename BaseUnit<BaseType>::SimplifiedType SimplifiedType;
  typedef typename SimplifiedType::InvertedType InvertedType;
  typedef typename SimplifiedType::SimplifiedFactor SimplifiedFactor;

  enum
  {
    NumeratorBaseTypeValue = BaseType::NumeratorBaseTypeValue,
    DenumeratorBaseTypeValue = BaseType::DenumeratorBaseTypeValue
  };

};

  template <typename _A, typename _B, typename _C, Types::Integer a, Types::Integer b, Types::Integer c, Types::Integer d, Types::Integer e, Types::Integer f, Types::Integer g, Types::Integer h, Types::Integer i, Types::Integer j>
  class ComplexUnit<
    BaseUnit<
      ComplexUnit<
        BaseUnit<
          ComplexUnit<
            BaseUnit<_B, a>,
            BaseUnit<_A, b>>, c>,
        BaseUnit<_C, d>>, e>,
    BaseUnit<
      ComplexUnit<
        BaseUnit<
          ComplexUnit<
            BaseUnit<_A, f>,
            BaseUnit<_B, g>>, i>,
        BaseUnit<_C, h>>, j>> :
  public Object<typename _A::ScalarType, typename _A::Policy>
  {

    typedef typename BaseUnit<_A, (b * c * e) + (f * i * j)>::SimplifiedType A;
    typedef typename BaseUnit<_B, (a * c * e) + (g * i * j)>::SimplifiedType B;

    typedef typename ComplexUnit<A,B>::SimplifiedType L;
    typedef typename BaseUnit<_C, (d * e) + (h * j)>::SimplifiedType R;

  public:

    typedef typename ComplexUnit<L,R>::BaseType BaseType;
    typedef ComplexUnit<typename L::DerivedType, typename R::DerivedType>  DerivedType;
    typedef typename BaseUnit<BaseType>::SimplifiedType SimplifiedType;
    typedef typename SimplifiedType::InvertedType InvertedType;
    typedef typename SimplifiedType::SimplifiedFactor SimplifiedFactor;

    enum
    {
      NumeratorBaseTypeValue = BaseType::NumeratorBaseTypeValue,
      DenumeratorBaseTypeValue = BaseType::DenumeratorBaseTypeValue
    };

  };

  template <typename _A, typename _B, typename _C, Types::Integer a, Types::Integer b, Types::Integer c, Types::Integer d, Types::Integer e, Types::Integer f, Types::Integer g, Types::Integer h, Types::Integer i, Types::Integer j>
  class ComplexUnit<
    BaseUnit<
      ComplexUnit<
        BaseUnit<
          ComplexUnit<
            BaseUnit<_A, a>,
            BaseUnit<_B, b>>, c>,
        BaseUnit<_C, d>>, e>,
     BaseUnit<
        ComplexUnit<
          BaseUnit<_B, f>,
          BaseUnit<
            ComplexUnit<
              BaseUnit<_A, g>,
              BaseUnit<_C, h>>, i>>, j>> :
  public Object<typename _A::ScalarType, typename _A::Policy>
  {

    typedef typename BaseUnit<_A, (a * c * e) + (g * i * j)>::SimplifiedType A;
    typedef typename BaseUnit<_B, (b * c * e) + (f * j)>::SimplifiedType B;

    typedef typename ComplexUnit<A,B>::SimplifiedType L;
    typedef typename BaseUnit<_C, (d * e) + (h * i * j)>::SimplifiedType R;

  public:

    typedef typename ComplexUnit<L,R>::BaseType BaseType;
    typedef ComplexUnit<typename L::DerivedType, typename R::DerivedType>  DerivedType;
    typedef typename BaseUnit<BaseType>::SimplifiedType SimplifiedType;
    typedef typename SimplifiedType::InvertedType InvertedType;
    typedef typename SimplifiedType::SimplifiedFactor SimplifiedFactor;

    enum
    {
      NumeratorBaseTypeValue = BaseType::NumeratorBaseTypeValue,
      DenumeratorBaseTypeValue = BaseType::DenumeratorBaseTypeValue
    };

  };


  template <typename _A, typename _B, typename _C, Types::Integer a, Types::Integer b, Types::Integer c, Types::Integer d, Types::Integer e, Types::Integer f, Types::Integer g, Types::Integer h, Types::Integer i, Types::Integer j>
  class ComplexUnit<
    BaseUnit<
      ComplexUnit<
        BaseUnit<_A, a>,
        BaseUnit<
          ComplexUnit<
            BaseUnit<_B, b>,
            BaseUnit<_C, c>>, d>>, e>,
      BaseUnit<
        ComplexUnit<
          BaseUnit<
            ComplexUnit<
              BaseUnit<_A, f>,
              BaseUnit<_B, g>>, h>,
          BaseUnit<_C, i>>, j>> :
  public Object<typename _A::ScalarType, typename _A::Policy>
  {

    typedef typename BaseUnit<_A, (a * e) + (f * h * j)>::SimplifiedType A;
    typedef typename BaseUnit<_B, (b * d * e) + (g * h * j)>::SimplifiedType B;

    typedef typename ComplexUnit<A,B>::SimplifiedType L;
    typedef typename BaseUnit<_C, (c * d * e) + (i * j)>::SimplifiedType R;

  public:

    typedef typename ComplexUnit<L,R>::BaseType BaseType;
    typedef ComplexUnit<typename L::DerivedType, typename R::DerivedType>  DerivedType;
    typedef typename BaseUnit<BaseType>::SimplifiedType SimplifiedType;
    typedef typename SimplifiedType::InvertedType InvertedType;
    typedef typename SimplifiedType::SimplifiedFactor SimplifiedFactor;

    enum
    {
      NumeratorBaseTypeValue = BaseType::NumeratorBaseTypeValue,
      DenumeratorBaseTypeValue = BaseType::DenumeratorBaseTypeValue
    };

  };

  template <typename _A, typename _B, typename _C, Types::Integer a, Types::Integer b, Types::Integer c, Types::Integer d, Types::Integer e, Types::Integer f, Types::Integer g, Types::Integer h, Types::Integer i, Types::Integer j>
  class ComplexUnit<
    BaseUnit<
      ComplexUnit<
        BaseUnit<
          ComplexUnit<
            BaseUnit<_A, a>,
            BaseUnit<_C, b>>, c>,
        BaseUnit<_B, d>>, e>,
    BaseUnit<
      ComplexUnit<
        BaseUnit<
          ComplexUnit<
            BaseUnit<_B, f>,
            BaseUnit<_C, g>>, h>,
        BaseUnit<_A, i>>, j>> :
  public Object<typename _A::ScalarType, typename _A::Policy>
  {

    typedef typename BaseUnit<_A, (a * c * e) + (i * j)>::SimplifiedType A;
    typedef typename BaseUnit<_B, (d * e) + (f * h * j)>::SimplifiedType B;

    typedef typename ComplexUnit<A,B>::SimplifiedType L;
    typedef typename BaseUnit<_C, (b * c * e) + (g * h * j)>::SimplifiedType R;

  public:

    typedef typename ComplexUnit<L,R>::BaseType BaseType;
    typedef ComplexUnit<typename L::DerivedType, typename R::DerivedType>  DerivedType;
    typedef typename BaseUnit<BaseType>::SimplifiedType SimplifiedType;
    typedef typename SimplifiedType::InvertedType InvertedType;
    typedef typename SimplifiedType::SimplifiedFactor SimplifiedFactor;

    enum
    {
      NumeratorBaseTypeValue = BaseType::NumeratorBaseTypeValue,
      DenumeratorBaseTypeValue = BaseType::DenumeratorBaseTypeValue
    };

  };

} //namespace Unit
