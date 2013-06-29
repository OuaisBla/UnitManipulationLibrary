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


#include <string>
#include <typeinfo>
#include <cmath>
#include <limits>
#include <cstdlib>
#include "UnitHelper.h"

#ifndef __cplusplus
#error This header requires a C++ compiler ...
#endif


#pragma inline_depth( 255 )
#pragma inline_recursion( on )

#ifndef _MSC_VER
#pragma template_depth( 255 )
#endif


namespace Unit
{


/**
  This class represents the identity in the Unit Library.
*/

class Identity
{
public:

  typedef Identity BaseType;
  typedef Identity SimplifiedType;
  typedef Identity InvertedType;
  typedef Identity SimplifiedFactor;
  typedef Identity InvertedFactor;

public:

  Identity() { }
  ~Identity() { }
  
  inline static Scalar ConversionFactor();

  inline static String Suffix();

};

inline Scalar Identity::ConversionFactor()
{
  return 1.;
}

inline String Identity::Suffix()
{
  return String();
}



/**
  Abstract class representing the basic interface of a unit object.
  
  A unit simple object is defined basically by a scalar value and is 
  associated with a conversion factor relative to a base unit.
  A base unit object is an unit object that has a conversion factor 
  equals to 1.
*/

template<typename _ScalarType = Scalar>
class Object
{
  
  Object( Object const & );
  void operator=( Object const & );

public:

  //Default facade
  typedef _ScalarType   ScalarType;
  typedef Identity      SimplifiedFactor;

public:

  Object() { }
  virtual ~Object() { }

public:

  virtual ScalarType GetValue() const = 0;
  virtual Scalar GetFactor() const = 0;
  virtual ScalarType GetConvertedValue() const = 0;

public:

  virtual String GetSuffix() const = 0;

protected:

  virtual void SetValue( ScalarType ) = 0;

};


/**
  Class that helps to simplify a unit type.
*/

template <typename _BaseType, Integer E = 1>
class BaseUnit : public _BaseType
{
public:

  typedef _BaseType                       BaseType;
  typedef BaseUnit<BaseType,E>            SimplifiedType;
  typedef BaseUnit<BaseType,-E>           InvertedType;

public:

  enum { Exponent = E };

  enum { NumeratorBaseTypeValue = IntegerPow<BaseType::NumeratorBaseTypeValue, Exponent>::value };
  enum { DenumeratorBaseTypeValue = IntegerPow<BaseType::DenumeratorBaseTypeValue, Exponent>::value };

public:

  inline static String Suffix();

};

template <typename T, Integer E>
inline String BaseUnit<T, E>::Suffix()
{ 
  wchar_t buf[4] = { L'\0' };

  switch( E )
  {
  case -3:
    wcscpy_s( buf, L"-\x00B3" );
    break;
  case -2:
    wcscpy_s( buf, L"-\x00B2" );
    break;
  case -1:
    wcscpy_s( buf, L"-\x00B9" );
    break;
  case 1:
    break;
  case 2:
    wcscpy_s( buf, L"\x00B2" );
    break;
  case 3:
    wcscpy_s( buf, L"\x00B3" );
    break;
  default:
    ::swprintf_s( buf, L"%d", Integer( E ) );
  }

  return BaseType::SimplifiedFactor::Suffix() + BaseType::Suffix() + buf;
}


namespace SI
{


/**
  Class that represents SI factors that are exponent of 10.
*/

template<Integer E>
class Factor
{
public:

  typedef Factor<E> SimplifiedFactor;
  typedef Factor<-E> InvertedFactor;

public:

  inline static Scalar ConversionFactor();

public:

  inline static String Suffix();

};

template<Integer E>
inline Scalar Factor<E>::ConversionFactor()
{ 
  return ::pow( 10., E );
}

template<Integer E>
inline String Factor<E>::Suffix()
{ 
  wchar_t buf[8];
  ::swprintf_s( buf, L"%d", int( E ) );
  return String( L"\'10e" ) + buf + L'\'';
}


} //Namespace SI


/**
  Class that represents the product of two factors.
*/

template <typename L, typename R = L>
class ProductFactor
{
public:

  typedef ProductFactor<typename L::SimplifiedFactor,typename R::SimplifiedFactor> SimplifiedFactor;
  typedef ProductFactor<typename R::SimplifiedFactor,typename L::SimplifiedFactor> InvertedFactor;

public:

  inline static Scalar ConversionFactor();

public:

  inline static String Suffix();

};

template <Integer L, Integer R>
class ProductFactor<SI::Factor<L>,SI::Factor<R> >
{
  
  typedef SI::Factor<L + R> _F;

public:

  typedef typename _F::SimplifiedFactor SimplifiedFactor;
  typedef typename _F::InvertedFactor InvertedFactor;

public:

  inline static Scalar ConversionFactor();

public:

  inline static String Suffix();

};

template <typename L>
class ProductFactor<L,Identity>
{
public:

  typedef typename L::SimplifiedFactor SimplifiedFactor;
  typedef typename L::InvertedFactor InvertedFactor;

public:

  inline static Scalar ConversionFactor();

public:

  inline static String Suffix();

};

template <typename R>
class ProductFactor<Identity,R>
{
public:

  typedef typename R::SimplifiedFactor SimplifiedFactor;
  typedef typename R::InvertedFactor InvertedFactor;

public:

  inline static Scalar ConversionFactor();

public:

  inline static String Suffix();

};

template <>
class ProductFactor<Identity>
{
public:

  typedef Identity SimplifiedFactor;
  typedef Identity InvertedFactor;

public:

  inline static Scalar ConversionFactor();

public:

  inline static String Suffix();

};


template <typename L, typename R>
inline Scalar ProductFactor<L,R>::ConversionFactor()
{
  return L::ConversionFactor() * R::ConversionFactor();
}

template <typename L, typename R>
inline String ProductFactor<L,R>::Suffix()
{
  wchar_t buf[32];
  ::swprintf_s( buf, L"%g", ConversionFactor() );
  return String( L"\'" ) + buf + L'\'';
}

template <Integer L, Integer R>
inline Scalar ProductFactor<SI::Factor<L>,SI::Factor<R> >::ConversionFactor()
{
  return _F::ConversionFactor();
}

template <Integer L, Integer R>
inline String ProductFactor<SI::Factor<L>,SI::Factor<R> >::Suffix()
{
  return _F::Suffix();
}

template <typename L>
inline Scalar ProductFactor<L,Identity>::ConversionFactor()
{
  return L::ConversionFactor();
}

template <typename L>
inline String ProductFactor<L,Identity>::Suffix()
{
  return L::Suffix();
}

template <typename R>
inline Scalar ProductFactor<Identity,R>::ConversionFactor()
{
  return R::ConversionFactor();
}

template <typename R>
inline String ProductFactor<Identity,R>::Suffix()
{
  return R::Suffix();
}

inline Scalar ProductFactor<Identity>::ConversionFactor()
{
  return Identity::ConversionFactor();
}

inline String ProductFactor<Identity>::Suffix()
{
  return Identity::Suffix();
}


} //Namespace Unit

