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


/**
  Class that helps to simplify a unit type. (Specialization)
*/

template <typename T>
class BaseUnit<T,0>
{
public:

  typedef Identity BaseType;
  typedef Identity SimplifiedType;
  typedef Identity InvertedType;

};



/**
  Class that represents a product of unit type.
*/

template <typename L, typename R = L>
class PS2 : public Object<>
{

  enum {
    _L_NumeratorBaseTypeValue = L::Exponent >= 0 ? L::NumeratorBaseTypeValue : L::DenumeratorBaseTypeValue,
    _L_DenumeratorBaseTypeValue = L::Exponent >= 0 ? L::DenumeratorBaseTypeValue : L::NumeratorBaseTypeValue,
    _R_NumeratorBaseTypeValue = R::Exponent >= 0 ? R::NumeratorBaseTypeValue : R::DenumeratorBaseTypeValue,
    _R_DenumeratorBaseTypeValue = R::Exponent >= 0 ? R::DenumeratorBaseTypeValue : R::NumeratorBaseTypeValue
  };

  enum {
    _NumeratorBaseTypeValue = _L_NumeratorBaseTypeValue * _R_NumeratorBaseTypeValue,
    _DenumeratorBaseTypeValue = _L_DenumeratorBaseTypeValue * _R_DenumeratorBaseTypeValue,
    _gcd = boost::math::static_gcd<_NumeratorBaseTypeValue, _DenumeratorBaseTypeValue>::value 
  };

public:

  typedef PS2<L,R> BaseType;
  typedef BaseUnit<BaseType> SimplifiedType;
  typedef BaseUnit<BaseType,-1> InvertedType;

  enum { 
    NumeratorBaseTypeValue = (_NumeratorBaseTypeValue / _gcd), 
    DenumeratorBaseTypeValue = (_DenumeratorBaseTypeValue / _gcd)
  };

public:

  inline static String Suffix();

};

template <typename L, typename R>
inline String PS2<L,R>::Suffix()
{
  return L::Suffix() + L'*' + R::Suffix();
}


/**
  PSX  
  Class that helps to simplify combination of products of unit type.
*/

template <typename A, typename B, typename C>
class PS3 : public Object<>
{

  enum { 
    _A_NumeratorBaseTypeValue = A::Exponent >= 0 ? A::NumeratorBaseTypeValue : A::DenumeratorBaseTypeValue,
    _A_DenumeratorBaseTypeValue = A::Exponent >= 0 ? A::DenumeratorBaseTypeValue : A::NumeratorBaseTypeValue,
    _B_NumeratorBaseTypeValue = B::Exponent >= 0 ? B::NumeratorBaseTypeValue : B::DenumeratorBaseTypeValue,
    _B_DenumeratorBaseTypeValue = B::Exponent >= 0 ? B::DenumeratorBaseTypeValue : B::NumeratorBaseTypeValue,
    _C_NumeratorBaseTypeValue = C::Exponent >= 0 ? C::NumeratorBaseTypeValue : C::DenumeratorBaseTypeValue,
    _C_DenumeratorBaseTypeValue = C::Exponent >= 0 ? C::DenumeratorBaseTypeValue : C::NumeratorBaseTypeValue
  };

  enum {
    _NumeratorBaseTypeValue = _A_NumeratorBaseTypeValue * _B_NumeratorBaseTypeValue * _C_NumeratorBaseTypeValue,
    _DenumeratorBaseTypeValue = _A_DenumeratorBaseTypeValue * _B_DenumeratorBaseTypeValue * _C_DenumeratorBaseTypeValue,
    _gcd = boost::math::static_gcd<_NumeratorBaseTypeValue,_DenumeratorBaseTypeValue>::value 
  };


public:

  typedef PS3<A,B,C> BaseType;
  typedef BaseUnit<BaseType> SimplifiedType;
  typedef BaseUnit<BaseType,-1> InvertedType;

  enum { 
    NumeratorBaseTypeValue = _NumeratorBaseTypeValue / _gcd, 
    DenumeratorBaseTypeValue =  _DenumeratorBaseTypeValue / _gcd
  };

public:

  inline static String Suffix();

};

template <typename A, typename B, typename C>
inline String PS3<A, B, C>::Suffix()
{
  return A::Suffix() + L'*' + B::Suffix() + L'*' + C::Suffix();
}



template <typename A, typename B, typename C, typename D>
class PS4 : public Object<>
{

  enum { 
    _A_NumeratorBaseTypeValue = A::Exponent >= 0 ? A::NumeratorBaseTypeValue : A::DenumeratorBaseTypeValue,
    _A_DenumeratorBaseTypeValue = A::Exponent >= 0 ? A::DenumeratorBaseTypeValue : A::NumeratorBaseTypeValue,
    _B_NumeratorBaseTypeValue = B::Exponent >= 0 ? B::NumeratorBaseTypeValue : B::DenumeratorBaseTypeValue,
    _B_DenumeratorBaseTypeValue = B::Exponent >= 0 ? B::DenumeratorBaseTypeValue : B::NumeratorBaseTypeValue,
    _C_NumeratorBaseTypeValue = C::Exponent >= 0 ? C::NumeratorBaseTypeValue : C::DenumeratorBaseTypeValue,
    _C_DenumeratorBaseTypeValue = C::Exponent >= 0 ? C::DenumeratorBaseTypeValue : C::NumeratorBaseTypeValue,
    _D_NumeratorBaseTypeValue = D::Exponent >= 0 ? D::NumeratorBaseTypeValue : D::DenumeratorBaseTypeValue,
    _D_DenumeratorBaseTypeValue = D::Exponent >= 0 ? D::DenumeratorBaseTypeValue : D::NumeratorBaseTypeValue
  };

  enum {
    _NumeratorBaseTypeValue = _A_NumeratorBaseTypeValue * _B_NumeratorBaseTypeValue * _C_NumeratorBaseTypeValue * _D_NumeratorBaseTypeValue,
    _DenumeratorBaseTypeValue = _A_DenumeratorBaseTypeValue * _B_DenumeratorBaseTypeValue * _C_DenumeratorBaseTypeValue * _D_DenumeratorBaseTypeValue,
    _gcd = boost::math::static_gcd<_NumeratorBaseTypeValue,_DenumeratorBaseTypeValue>::value 
  };


public:

  typedef PS4<A,B,C,D> BaseType;
  typedef BaseUnit<BaseType> SimplifiedType;
  typedef BaseUnit<BaseType,-1> InvertedType;

  enum { 
    NumeratorBaseTypeValue = _NumeratorBaseTypeValue / _gcd, 
    DenumeratorBaseTypeValue =  _DenumeratorBaseTypeValue / _gcd
  };

public:

  inline static String Suffix();

};

template <typename A, typename B, typename C, typename D>
inline String PS4<A, B, C, D>::Suffix()
{
  return A::Suffix() + L'*' + B::Suffix() + L'*' + C::Suffix() + L'*' + D::Suffix();
}


/**
  Class that helps to simplify products of unit type. (Specialization)
*/

template <>
class PS2<Identity>
{
public:

  typedef Identity BaseType;
  typedef Identity SimplifiedType;

};


template <typename L>
class PS2<L,Identity>
{
public:

  typedef typename L::BaseType BaseType;
  typedef typename L::SimplifiedType SimplifiedType;

};

template <typename R>
class PS2<Identity,R>
{
public:

  typedef typename R::BaseType BaseType;
  typedef typename R::SimplifiedType SimplifiedType;

};


template <typename A, Integer a, Integer b>
class PS2<BaseUnit<A,a>,BaseUnit<A,b> >
{
public:

  typedef typename BaseUnit<A,a + b>::SimplifiedType SimplifiedType;
  typedef typename SimplifiedType::BaseType BaseType;

};


template <typename A, typename B, typename C, 
          Integer a, Integer b, Integer c, Integer i>
class PS2<BaseUnit<PS2<BaseUnit<A,a>,BaseUnit<B,b> >, i>, BaseUnit<C,c> >
{

  typedef typename BaseUnit<A,a*i>::SimplifiedType _A;
  typedef typename BaseUnit<B,b*i>::SimplifiedType _B;
  typedef typename BaseUnit<C,c>::SimplifiedType   _C;

public:

  typedef typename PS3<_A,_B,_C>::SimplifiedType SimplifiedType;
  typedef typename SimplifiedType::BaseType BaseType;

};

template <typename A, typename B, typename C, 
  Integer a, Integer b, Integer c, Integer i>
class PS2<BaseUnit<A,a>, BaseUnit<PS2<BaseUnit<B,b>, BaseUnit<C,c> >, i> >
{

  typedef typename BaseUnit<A,a>::SimplifiedType   _A;
  typedef typename BaseUnit<B,b*i>::SimplifiedType _B;
  typedef typename BaseUnit<C,c*i>::SimplifiedType _C;

public:

  typedef typename PS3<_A,_B,_C>::SimplifiedType SimplifiedType;
  typedef typename SimplifiedType::BaseType BaseType;

};

template <typename A, typename B, typename C, typename D, 
  Integer a, Integer b, Integer c, Integer d, 
  Integer i, Integer j>
class PS2<BaseUnit<PS2<BaseUnit<A,a>, BaseUnit<B,b> >, i>, BaseUnit<PS2<BaseUnit<C,c>, BaseUnit<D,d> >, j> >
{

  typedef typename BaseUnit<A,a*i>::SimplifiedType _A;
  typedef typename BaseUnit<B,b*i>::SimplifiedType _B;
  typedef typename BaseUnit<C,c*j>::SimplifiedType _C;
  typedef typename BaseUnit<D,c*j>::SimplifiedType _D;

public:

  typedef typename PS4<_A,_B,_C,_D>::SimplifiedType SimplifiedType;
  typedef typename SimplifiedType::BaseType BaseType;

};


/**
  PS2
  Early filter class that helps to simplify combination of products of unit type. (Specialization)
*/

template <typename A, typename B, Integer a, Integer b>
class PS2<BaseUnit<A,a>, BaseUnit<PS2<BaseUnit<B,b>, BaseUnit<A,a> >, -1> >
{
public:

  typedef typename BaseUnit<B,-b>::SimplifiedType SimplifiedType;
  typedef typename SimplifiedType::BaseType BaseType;

};

template <typename A, typename B, Integer a, Integer b>
class PS2<BaseUnit<A,a>, BaseUnit<PS2<BaseUnit<A,a>, BaseUnit<B,b> >, -1> >
{
public:

  typedef typename BaseUnit<B,-b>::SimplifiedType SimplifiedType;
  typedef typename SimplifiedType::BaseType BaseType;

};

template <typename A, typename B, Integer a, Integer b>
class PS2<BaseUnit<PS2<BaseUnit<B,b>, BaseUnit<A,a> >, -1>, BaseUnit<A,a> >
{
public:

  typedef typename BaseUnit<B,-b>::SimplifiedType SimplifiedType;
  typedef typename SimplifiedType::BaseType BaseType;

};

template <typename A, typename B, Integer a, Integer b>
class PS2<BaseUnit<PS2<BaseUnit<A,a>,BaseUnit<B,b> >, -1>, BaseUnit<A,a> >
{
public:

  typedef typename BaseUnit<B,-b>::SimplifiedType SimplifiedType;
  typedef typename SimplifiedType::BaseType BaseType;

};


template <typename A, typename B, typename C, Integer a, Integer b, Integer c>
class PS2<BaseUnit<PS2<BaseUnit<A,a>, BaseUnit<B,b> > >, BaseUnit<PS2<BaseUnit<C,c>, BaseUnit<A,a> >, -1> >
{

  typedef typename BaseUnit<B,b>::SimplifiedType _B;
  typedef typename BaseUnit<C,-c>::SimplifiedType _C;

public:

  typedef typename PS2<_B,_C>::SimplifiedType SimplifiedType;
  typedef typename SimplifiedType::BaseType BaseType;

};

template <typename A, typename B, typename C, Integer a, Integer b, Integer c>
class PS2<BaseUnit<PS2<BaseUnit<B,b>, BaseUnit<A,a> > >, BaseUnit<PS2<BaseUnit<C,c>, BaseUnit<A,a> >, -1> >
{

  typedef typename BaseUnit<B,b>::SimplifiedType _B;
  typedef typename BaseUnit<C,-c>::SimplifiedType _C;

public:

  typedef typename PS2<_B,_C>::SimplifiedType SimplifiedType;
  typedef typename SimplifiedType::BaseType BaseType;

};

template <typename A, typename B, typename C, Integer a, Integer b, Integer c>
class PS2<BaseUnit<PS2<BaseUnit<B,b>, BaseUnit<A,a> >, -1>, BaseUnit<PS2<BaseUnit<A,a>,BaseUnit<C,c> > > >
{

  typedef typename BaseUnit<B,-b>::SimplifiedType _B;
  typedef typename BaseUnit<C,c>::SimplifiedType _C;

public:

  typedef typename PS2<_B,_C>::SimplifiedType SimplifiedType;
  typedef typename SimplifiedType::BaseType BaseType;

};

template <typename A, typename B, typename C, Integer a, Integer b, Integer c>
class PS2<BaseUnit<PS2<BaseUnit<A,a>, BaseUnit<B,b> >, -1>, BaseUnit<PS2<BaseUnit<A,a>,BaseUnit<C,c> > > >
{

  typedef typename BaseUnit<B,-b>::SimplifiedType _B;
  typedef typename BaseUnit<C,c>::SimplifiedType _C;

public:

  typedef typename PS2<_B,_C>::SimplifiedType SimplifiedType;
  typedef typename SimplifiedType::BaseType BaseType;

};


/**
  PS3  
  Class that helps to simplify combination of products of unit type. (Specialization)
*/

template <typename A, typename B, Integer a, Integer b, Integer c>
class PS3<BaseUnit<A,a>, BaseUnit<A,c>, BaseUnit<B,b> >
{
public:

  typedef typename PS2<typename BaseUnit<A,a+c>::SimplifiedType, typename BaseUnit<B,b>::SimplifiedType>::SimplifiedType SimplifiedType;

};

template <typename A, typename B, Integer a, Integer b, Integer c>
class PS3<BaseUnit<A,a>, BaseUnit<B,b>, BaseUnit<A,c> >
{
public:

  typedef typename PS2<typename BaseUnit<A,a+c>::SimplifiedType, typename BaseUnit<B,b>::SimplifiedType>::SimplifiedType SimplifiedType;

};

template <typename A, typename B, Integer a, Integer b, Integer c>
class PS3<BaseUnit<B,b>, BaseUnit<A,a>, BaseUnit<A,c> >
{
public:

  typedef typename PS2<typename BaseUnit<A,a + c>::SimplifiedType, typename BaseUnit<B,b>::SimplifiedType>::SimplifiedType SimplifiedType;

};

template <typename A, Integer a, Integer b, Integer c>
class PS3<BaseUnit<A,a>,BaseUnit<A,b>,BaseUnit<A,c> >
{
public:

  typedef typename BaseUnit<A,a+b+c>::SimplifiedType SimplifiedType;

};


/**
  PS4
  Class that helps to simplify combination of products of unit type. (Specialization)
*/

template <typename A, typename B, typename C, Integer a, Integer b, Integer c, Integer d>
class PS4<BaseUnit<A,a>, BaseUnit<A,d>, BaseUnit<B,b>, BaseUnit<C,c> >
{
public:

  typedef typename PS3<typename BaseUnit<A,a+d>::SimplifiedType, typename BaseUnit<B,b>::SimplifiedType, typename BaseUnit<C,c>::SimplifiedType>::SimplifiedType SimplifiedType;

};

template <typename A, typename B, typename C, Integer a, Integer b, Integer c, Integer d>
class PS4<BaseUnit<B,b>, BaseUnit<A,a>, BaseUnit<A,d>, BaseUnit<C,c> >
{
public:

  typedef typename PS3<typename BaseUnit<A,a+d>::SimplifiedType, typename BaseUnit<B,b>::SimplifiedType, typename BaseUnit<C,c>::SimplifiedType>::SimplifiedType SimplifiedType;

};

template <typename A, typename B, typename C, Integer a, Integer b, Integer c, Integer d>
class PS4<BaseUnit<B,b>, BaseUnit<C,c>, BaseUnit<A,a>, BaseUnit<A,d> >
{
public:

  typedef typename PS3<typename BaseUnit<A,a+d>::SimplifiedType, typename BaseUnit<B,b>::SimplifiedType, typename BaseUnit<C,c>::SimplifiedType>::SimplifiedType SimplifiedType;

};

template <typename A, typename B, typename C, Integer a, Integer b, Integer c, Integer d>
class PS4<BaseUnit<B,b>, BaseUnit<A,a>, BaseUnit<C,c>, BaseUnit<A,d> >
{
public:

  typedef typename PS3<typename BaseUnit<A,a+d>::SimplifiedType, typename BaseUnit<B,b>::SimplifiedType, typename BaseUnit<C,c>::SimplifiedType>::SimplifiedType SimplifiedType;

};

template <typename A, typename B, typename C, Integer a, Integer b, Integer c, Integer d>
class PS4<BaseUnit<A,a>, BaseUnit<B,b>, BaseUnit<C,c>, BaseUnit<A,d> >
{
public:

  typedef typename PS3<typename BaseUnit<A,a+d>::SimplifiedType, typename BaseUnit<B,b>::SimplifiedType, typename BaseUnit<C,c>::SimplifiedType>::SimplifiedType SimplifiedType;

};

template <typename A, typename B, Integer a, Integer b, Integer c, Integer d>
class PS4<BaseUnit<A,a>, BaseUnit<A,c>, BaseUnit<B,b>, BaseUnit<A,d> >
{
public:

  typedef typename PS2<typename BaseUnit<A,a+c+d>::SimplifiedType, typename BaseUnit<B,b>::SimplifiedType>::SimplifiedType SimplifiedType;

};

template <typename A, typename B, Integer a, Integer b, Integer c, Integer d>
class PS4<BaseUnit<A,a>, BaseUnit<B,b>, BaseUnit<A,c>, BaseUnit<A,d> >
{
public:

  typedef typename PS2<typename BaseUnit<A,a+c+d>::SimplifiedType, typename BaseUnit<B,b>::SimplifiedType>::SimplifiedType SimplifiedType;

};

template <typename A, typename B, Integer a, Integer b, Integer c, Integer d>
class PS4<BaseUnit<A,a>, BaseUnit<B,b>, BaseUnit<B,c>, BaseUnit<A,d> >
{
public:

  typedef typename PS2<typename BaseUnit<A,a+d>::SimplifiedType, typename BaseUnit<B,b+c>::SimplifiedType>::SimplifiedType SimplifiedType;

};

template <typename A, Integer a, Integer b, Integer c, Integer d>
class PS4<BaseUnit<A,a>, BaseUnit<A,b>, BaseUnit<A,c>, BaseUnit<A,d> >
{
public:

  typedef typename BaseUnit<A,a+b+c+d>::SimplifiedType SimplifiedType;

};

} //namespace Unit
