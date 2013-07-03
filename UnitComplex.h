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


template <typename _BaseType>
class BaseUnit<_BaseType, 1> : public _BaseType
{
public:

  typedef _BaseType                       BaseType;
  typedef BaseUnit<BaseType,1>            SimplifiedType;
  typedef BaseUnit<BaseType,-1>           InvertedType;
  typedef typename BaseType::ScalarType   ScalarType;
  typedef typename BaseType::Policy       Policy;

public:

  inline BaseUnit();

  enum { Exponent = 1 };

  enum { NumeratorBaseTypeValue = BaseType::NumeratorBaseTypeValue };
  enum { DenumeratorBaseTypeValue = BaseType::DenumeratorBaseTypeValue };

public:

  inline static String SuffixExponent();
  inline static String Suffix();

private:
  
  inline explicit BaseUnit( void * ); 

  static BaseUnit const RuntimeSuffixesCtor;

};


template <typename T>
BaseUnit<T,1> const BaseUnit<T,1>::RuntimeSuffixesCtor( NULL );

template <typename T>
inline BaseUnit<T,1>::BaseUnit()
{
  static BaseUnit<T, 1> __ForceLinker = BaseUnit<T, 1>::RuntimeSuffixesCtor;
}

template <typename T>
inline BaseUnit<T,1>::BaseUnit( void * ) 
{
  Integer const _NumeratorBaseTypeValue = static_cast<Integer>( NumeratorBaseTypeValue * DenumeratorBaseTypeValue );

  SuffixesMap::iterator it = Object<ScalarType,Policy>::RuntimeSuffixes.find(_NumeratorBaseTypeValue);

  if( IsPrime( _NumeratorBaseTypeValue ) && it == Object<ScalarType,Policy>::RuntimeSuffixes.end() )
  {
    String const suffix = BaseType::Suffix();
    String const factorsuffix = BaseType::SimplifiedFactor::Suffix();

    Object<ScalarType,Policy>::RuntimeSuffixes.insert( SuffixesMap::value_type( _NumeratorBaseTypeValue, PairString( factorsuffix, suffix ) ) );
  }
}

template <typename T>
inline String BaseUnit<T, 1>::SuffixExponent()
{
  return String();
}

template <typename T>
inline String BaseUnit<T, 1>::Suffix()
{ 
  return BaseType::SimplifiedFactor::Suffix() + BaseType::Suffix();
}



/**
  Class that represents a product of unit type.
*/

template <typename L, typename R = L>
class PS2 : public Object<>, public Facade<PS2<L,R> >
{

  enum {
    _NumeratorBaseTypeValue =  L::NumeratorBaseTypeValue * R::NumeratorBaseTypeValue,
    _DenumeratorBaseTypeValue = L::DenumeratorBaseTypeValue * R::DenumeratorBaseTypeValue,
    _gcd = boost::math::static_gcd<_NumeratorBaseTypeValue, _DenumeratorBaseTypeValue>::value 
  };

public:

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
  return L::Suffix() + DOT_OPERATOR + R::Suffix();
}


/**
  PSX  
  Class that helps to simplify combination of products of unit type.
*/

template <typename A, typename B, typename C>
class PS3 : public Object<>, public Facade<PS3<A,B,C> >
{

  enum {
    _NumeratorBaseTypeValue = A::NumeratorBaseTypeValue * B::NumeratorBaseTypeValue * C::NumeratorBaseTypeValue,
    _DenumeratorBaseTypeValue = A::DenumeratorBaseTypeValue * B::DenumeratorBaseTypeValue * C::DenumeratorBaseTypeValue,
    _gcd = boost::math::static_gcd<_NumeratorBaseTypeValue,_DenumeratorBaseTypeValue>::value 
  };


public:

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
  return A::Suffix() + DOT_OPERATOR + B::Suffix() + DOT_OPERATOR + C::Suffix();
}



template <typename A, typename B, typename C, typename D>
class PS4 : public Object<>, public Facade<PS4<A,B,C,D> >
{

  enum {
    _NumeratorBaseTypeValue = A::NumeratorBaseTypeValue * B::NumeratorBaseTypeValue * C::NumeratorBaseTypeValue * D::NumeratorBaseTypeValue,
    _DenumeratorBaseTypeValue = A::DenumeratorBaseTypeValue * B::DenumeratorBaseTypeValue * C::DenumeratorBaseTypeValue * D::DenumeratorBaseTypeValue,
    _gcd = boost::math::static_gcd<_NumeratorBaseTypeValue,_DenumeratorBaseTypeValue>::value 
  };

public:

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
  return A::Suffix() + DOT_OPERATOR + B::Suffix() + DOT_OPERATOR + C::Suffix() + DOT_OPERATOR + D::Suffix();
}

/*
template <typename A, typename B, typename C, typename D, typename E>
class PS5 : public Object<>
{

  enum { 
    _A_NumeratorBaseTypeValue = A::Exponent >= 0 ? A::NumeratorBaseTypeValue : A::DenumeratorBaseTypeValue,
    _A_DenumeratorBaseTypeValue = A::Exponent >= 0 ? A::DenumeratorBaseTypeValue : A::NumeratorBaseTypeValue,
    _B_NumeratorBaseTypeValue = B::Exponent >= 0 ? B::NumeratorBaseTypeValue : B::DenumeratorBaseTypeValue,
    _B_DenumeratorBaseTypeValue = B::Exponent >= 0 ? B::DenumeratorBaseTypeValue : B::NumeratorBaseTypeValue,
    _C_NumeratorBaseTypeValue = C::Exponent >= 0 ? C::NumeratorBaseTypeValue : C::DenumeratorBaseTypeValue,
    _C_DenumeratorBaseTypeValue = C::Exponent >= 0 ? C::DenumeratorBaseTypeValue : C::NumeratorBaseTypeValue,
    _D_NumeratorBaseTypeValue = D::Exponent >= 0 ? D::NumeratorBaseTypeValue : D::DenumeratorBaseTypeValue,
    _D_DenumeratorBaseTypeValue = D::Exponent >= 0 ? D::DenumeratorBaseTypeValue : D::NumeratorBaseTypeValue,
    _E_NumeratorBaseTypeValue = E::Exponent >= 0 ? E::NumeratorBaseTypeValue : E::DenumeratorBaseTypeValue,
    _E_DenumeratorBaseTypeValue = E::Exponent >= 0 ? E::DenumeratorBaseTypeValue : E::NumeratorBaseTypeValue
  };

  enum {
    _NumeratorBaseTypeValue = _A_NumeratorBaseTypeValue * _B_NumeratorBaseTypeValue * _C_NumeratorBaseTypeValue * _D_NumeratorBaseTypeValue * _E_NumeratorBaseTypeValue,
    _DenumeratorBaseTypeValue = _A_DenumeratorBaseTypeValue * _B_DenumeratorBaseTypeValue * _C_DenumeratorBaseTypeValue * _D_DenumeratorBaseTypeValue * _E_DenumeratorBaseTypeValue,
    _gcd = boost::math::static_gcd<_NumeratorBaseTypeValue,_DenumeratorBaseTypeValue>::value 
  };


public:

  typedef PS5<A,B,C,D,E> BaseType;
  typedef BaseUnit<BaseType> SimplifiedType;
  typedef BaseUnit<BaseType,-1> InvertedType;

  enum { 
    NumeratorBaseTypeValue = _NumeratorBaseTypeValue / _gcd, 
    DenumeratorBaseTypeValue =  _DenumeratorBaseTypeValue / _gcd
  };

public:

  inline static String Suffix();

};

template <typename A, typename B, typename C, typename D, typename E>
inline String PS5<A, B, C, D, E>::Suffix()
{
  return A::Suffix() + DOT_OPERATOR + B::Suffix() + DOT_OPERATOR + C::Suffix() + DOT_OPERATOR + D::Suffix() + DOT_OPERATOR + E::Suffix();
}
*/

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

/*template <typename A, typename B, typename C, typename D, 
  Integer a, Integer b, Integer c, Integer d, 
  Integer i>
class PS2<BaseUnit<PS3<BaseUnit<A,a>, BaseUnit<B,b>, BaseUnit<C,c> >, i>, BaseUnit<D,d> >
{

  typedef typename BaseUnit<A,a*i>::SimplifiedType _A;
  typedef typename BaseUnit<B,b*i>::SimplifiedType _B;
  typedef typename BaseUnit<C,c*i>::SimplifiedType _C;
  typedef typename BaseUnit<D,d>::SimplifiedType   _D;

public:

  typedef typename PS4<_A,_B,_C,_D>::SimplifiedType SimplifiedType;
  typedef typename SimplifiedType::BaseType BaseType;

};

template <typename A, typename B, typename C, typename D, 
  Integer a, Integer b, Integer c, Integer d, 
  Integer i>
class PS2<BaseUnit<D,d>, BaseUnit<PS3<BaseUnit<A,a>, BaseUnit<B,b>, BaseUnit<C,c> >, i> >
{

  typedef typename BaseUnit<A,a*i>::SimplifiedType _A;
  typedef typename BaseUnit<B,b*i>::SimplifiedType _B;
  typedef typename BaseUnit<C,c*i>::SimplifiedType _C;
  typedef typename BaseUnit<D,d>::SimplifiedType   _D;

public:

  typedef typename PS4<_A,_B,_C,_D>::SimplifiedType SimplifiedType;
  typedef typename SimplifiedType::BaseType BaseType;

};

template <typename A, typename B, typename C, typename D, typename E, 
  Integer a, Integer b, Integer c, Integer d, Integer e,
  Integer i, Integer j>
class PS2<BaseUnit<PS2<BaseUnit<D,d>, BaseUnit<E,e> >, j>, BaseUnit<PS3<BaseUnit<A,a>, BaseUnit<B,b>, BaseUnit<C,c> >, i> >
{

  typedef typename BaseUnit<A,a*i>::SimplifiedType _A;
  typedef typename BaseUnit<B,b*i>::SimplifiedType _B;
  typedef typename BaseUnit<C,c*i>::SimplifiedType _C;
  typedef typename BaseUnit<D,d*j>::SimplifiedType   _D;
  typedef typename BaseUnit<E,e*j>::SimplifiedType   _E;

public:

  typedef typename PS5<_A,_B,_C,_D,_E>::SimplifiedType SimplifiedType;
  typedef typename SimplifiedType::BaseType BaseType;

};

template <typename A, typename B, typename C, typename D, typename E,
  Integer a, Integer b, Integer c, Integer d, Integer e,
  Integer i, Integer j>
class PS2<BaseUnit<PS3<BaseUnit<A,a>, BaseUnit<B,b>, BaseUnit<C,c> >, i>, BaseUnit<PS2<BaseUnit<D,d>, BaseUnit<E,e> >, j> >
{

  typedef typename BaseUnit<A,a*i>::SimplifiedType _A;
  typedef typename BaseUnit<B,b*i>::SimplifiedType _B;
  typedef typename BaseUnit<C,c*i>::SimplifiedType _C;
  typedef typename BaseUnit<D,d*j>::SimplifiedType _D;
  typedef typename BaseUnit<E,e*j>::SimplifiedType _E;

public:

  typedef typename PS5<_A,_B,_C,_D,_E>::SimplifiedType SimplifiedType;
  typedef typename SimplifiedType::BaseType BaseType;

};*/


/**
  PS2
  Early filter class that helps to simplify trivial combination of products of unit type. (Specialization)
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


template <typename A, typename B>
class PS3<Identity, A, B>
{
public:

  typedef typename PS2<typename A::SimplifiedType, typename B::SimplifiedType>::SimplifiedType SimplifiedType;

};

template <typename A, typename B>
class PS3<A, Identity, B>
{
public:

  typedef typename PS2<typename A::SimplifiedType, typename B::SimplifiedType>::SimplifiedType SimplifiedType;

};

template <typename A, typename B>
class PS3<A, B, Identity>
{
public:

  typedef typename PS2<typename A::SimplifiedType, typename B::SimplifiedType>::SimplifiedType SimplifiedType;

};

template <typename A>
class PS3<A, Identity, Identity>
{
public:

  typedef typename A::SimplifiedType SimplifiedType;

};

template <typename A>
class PS3<Identity, A, Identity>
{
public:

  typedef typename A::SimplifiedType SimplifiedType;

};

template <typename A>
class PS3<Identity, Identity, A>
{
public:

  typedef typename A::SimplifiedType SimplifiedType;

};

template <>
class PS3<Identity, Identity, Identity>
{
public:

  typedef Identity SimplifiedType;

};

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
