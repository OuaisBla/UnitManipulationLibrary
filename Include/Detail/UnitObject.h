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


#include <cmath>
#include <limits>
#include <cstdlib>
#include <boost/math/policies/policy.hpp>
#include <boost/math/tools/precision.hpp>
#include "Detail\UnitHelper.h"


#ifndef __cplusplus
#error This header requires a C++ compiler ...
#endif


#pragma inline_depth( 255 )
#pragma inline_recursion( on )


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

  enum { 
    Exponent = 0,
    NumeratorBaseTypeValue = 1, 
    DenumeratorBaseTypeValue = 1
  };

public:

  Identity() { }
  ~Identity() { }
  
  inline static Types::Scalar ConversionFactor();

  inline static Types::String Suffix();

};

inline Types::Scalar Identity::ConversionFactor()
{
  return 1.;
}

inline Types::String Identity::Suffix()
{
  return Types::String();
}


template <typename, Types::Integer = 1>
class BaseUnit;

template <typename, typename = Identity>
class Quantity;

/**
  Abstract class representing the basic interface of a unit object.
  
  A unit simple object is defined basically by a scalar value and is 
  associated with a conversion factor relative to a base unit.
  A base unit object is an unit object that has a conversion factor 
  equals to 1.
*/

template<typename _ScalarType = Types::Scalar, typename _Policy = boost::math::policies::precision<_ScalarType, boost::math::policies::policy<> > >
class Object
{
public:

  typedef _ScalarType                     ScalarType;
  typedef _Policy                         Policy;
  typedef std::numeric_limits<ScalarType> Limits;

public:

  inline Object();
  virtual ~Object() { }

public:

  virtual ScalarType GetValue() const { return 0; }
  virtual Types::Scalar GetFactor() const { return 1; }
  virtual ScalarType GetConvertedValue() const { return 0; }

public:

  virtual Types::String GetSuffix() const { return Types::String(); } 
  virtual Types::String GetSISuffix() const { return Types::String(); } 

protected:

  virtual void SetValue( ScalarType ) { }

};


template<typename _BaseType>
struct Facade
{

  typedef _BaseType                       BaseType;
  typedef BaseType                        DerivedType;
  typedef BaseUnit<BaseType>              SimplifiedType;
  typedef BaseUnit<BaseType,-1>           InvertedType;
  typedef Identity                        SimplifiedFactor;

};


namespace Detail
{

  class SuffixesInitializer
  {

    SuffixesInitializer();
    SuffixesInitializer( SuffixesInitializer const &);
    void operator= ( SuffixesInitializer const &);

    template<class B, Types::Integer E> friend class BaseUnit;
    template<class T, class F>          friend class Quantity;

  public:

  #ifndef NO_STATIC_UNIT_SUFFIXES_EVALUATION
    inline static void Initialize()
    {
    }
  #else
    static void Initialize();
  #endif

  private:

    static SuffixesMap RuntimeSuffixes;

  };

}


template<typename S, typename P>
inline Object<S,P>::Object()
{
}

/**
  Class that helps to simplify a unit type.
*/

template <typename _BaseType, Types::Integer E>
class BaseUnit : public _BaseType
{

  enum { _NumeratorBaseTypeValue = E >= 0 ? BaseType::NumeratorBaseTypeValue : BaseType::DenumeratorBaseTypeValue };
  enum { _DenumeratorBaseTypeValue = E >= 0 ? BaseType::DenumeratorBaseTypeValue : BaseType::NumeratorBaseTypeValue };

public:

  typedef _BaseType                       BaseType;
  typedef BaseUnit<BaseType,E>            SimplifiedType;
  typedef BaseUnit<BaseType,-E>           InvertedType;
  typedef typename BaseType::ScalarType   ScalarType;
  typedef typename BaseType::Policy       Policy;

public:

  inline BaseUnit();

  enum { Exponent = E };

  enum { NumeratorBaseTypeValue = Detail::IntegerPow<_NumeratorBaseTypeValue, Exponent>::value };
  enum { DenumeratorBaseTypeValue = Detail::IntegerPow<_DenumeratorBaseTypeValue, Exponent>::value };

public:

  inline static Types::String SuffixExponent();
  inline static Types::String Suffix();

private:

  inline explicit BaseUnit( void *, void * ); 

#ifndef NO_STATIC_UNIT_SUFFIXES_EVALUATION
  static BaseUnit const RuntimeSuffixesCtor;
#else
  friend class Detail::SuffixesInitializer;
#endif

};


#ifndef NO_STATIC_UNIT_SUFFIXES_EVALUATION
template <typename T, Types::Integer E>
BaseUnit<T,E> const BaseUnit<T,E>::RuntimeSuffixesCtor( NULL, NULL );
#endif


template <typename T, Types::Integer E>
inline BaseUnit<T,E>::BaseUnit()
{
#ifndef NO_STATIC_UNIT_SUFFIXES_EVALUATION
  static BaseUnit<T,E> __ForceLinker = BaseUnit<T,E>::RuntimeSuffixesCtor;
#endif
}

template <typename T, Types::Integer E>
inline BaseUnit<T,E>::BaseUnit( void *, void * ) 
{
  Detail::SuffixesValue const suffixKey( static_cast<Types::Integer>( NumeratorBaseTypeValue ), static_cast<Types::Integer>( DenumeratorBaseTypeValue ) );

  Detail::SuffixesMap::iterator it = Detail::SuffixesInitializer::RuntimeSuffixes.find( suffixKey );

  if( it == Detail::SuffixesInitializer::RuntimeSuffixes.end() &&
      Detail::IsPrime( suffixKey.Product() ) )
  {
    Types::String const baseTypeSISuffix = BaseType::Suffix();
    Types::String const baseTypeFactorSuffix = BaseType::SimplifiedFactor::InvertedFactor::Suffix();
    Types::String const quantityUnitSuffix = baseTypeFactorSuffix + baseTypeSISuffix;

    Detail::SuffixesInitializer::RuntimeSuffixes.insert( Detail::SuffixesMap::value_type( suffixKey, Detail::SuffixesString( quantityUnitSuffix, baseTypeSISuffix ) ) );
  }
}


template <typename T, Types::Integer E>
inline Types::String BaseUnit<T, E>::SuffixExponent()
{
  return Detail::SuffixExponent( E );
}

template <typename T, Types::Integer E>
inline Types::String BaseUnit<T, E>::Suffix()
{ 
  return BaseType::SimplifiedFactor::Suffix() + BaseType::Suffix() + SuffixExponent();
}


namespace SI
{


/**
  Class that represents SI factors that are exponent of 10.
*/

template<Types::Integer E>
class Factor
{
public:

  typedef Factor<E> SimplifiedFactor;
  typedef Factor<-E> InvertedFactor;

public:

  inline static Types::Scalar ConversionFactor();

public:

  inline static Types::String Suffix();

};

template<Types::Integer E>
inline Types::Scalar Factor<E>::ConversionFactor()
{ 
  return ::pow( 10., E );
}

template<Types::Integer E>
inline Types::String Factor<E>::Suffix()
{ 
  wchar_t buf[8];
  ::swprintf_s( buf, L"%d", int( E ) );
  return Types::String( L"\'10e" ) + buf + L'\'';
}


} //Namespace SI



/**
  Class that represents the product of two factors.
*/
template <typename L, typename R = L>
class OffsetHandler
{
public:

  typedef typename L::ScalarType ScalarType;

  inline static ScalarType Convert( ScalarType const value )
  {
    return value;
  }

};


/**
  Class that represents the product of two factors.
*/

template <typename L, typename R = L>
class ProductFactor
{
public:

  typedef ProductFactor<typename L::SimplifiedFactor,typename R::SimplifiedFactor> SimplifiedFactor;
  typedef ProductFactor<typename L::InvertedFactor,typename R::InvertedFactor> InvertedFactor;

public:

  inline static Types::Scalar ConversionFactor();

public:

  inline static Types::String Suffix();

};

template <Types::Integer L, Types::Integer R>
class ProductFactor<SI::Factor<L>,SI::Factor<R> >
{
  
  typedef SI::Factor<L + R> _F;

public:

  typedef typename _F::SimplifiedFactor SimplifiedFactor;
  typedef typename _F::InvertedFactor InvertedFactor;

public:

  inline static Types::Scalar ConversionFactor();

public:

  inline static Types::String Suffix();

};

template <typename L>
class ProductFactor<L,Identity>
{
public:

  typedef typename L::SimplifiedFactor SimplifiedFactor;
  typedef typename L::InvertedFactor InvertedFactor;

public:

  inline static Types::Scalar ConversionFactor();

public:

  inline static Types::String Suffix();

};

template <typename R>
class ProductFactor<Identity,R>
{
public:

  typedef typename R::SimplifiedFactor SimplifiedFactor;
  typedef typename R::InvertedFactor InvertedFactor;

public:

  inline static Types::Scalar ConversionFactor();

public:

  inline static Types::String Suffix();

};

template <>
class ProductFactor<Identity>
{
public:

  typedef Identity SimplifiedFactor;
  typedef Identity InvertedFactor;

public:

  inline static Types::Scalar ConversionFactor();

public:

  inline static Types::String Suffix();

};


template <typename L, typename R>
inline Types::Scalar ProductFactor<L,R>::ConversionFactor()
{
  return L::ConversionFactor() * R::ConversionFactor();
}

template <typename L, typename R>
inline Types::String ProductFactor<L,R>::Suffix()
{
  wchar_t buf[32];
  ::swprintf_s( buf, L"%g", ConversionFactor() );
  return Types::String( L"\'" ) + buf + L'\'';
}

template <Types::Integer L, Types::Integer R>
inline Types::Scalar ProductFactor<SI::Factor<L>,SI::Factor<R> >::ConversionFactor()
{
  return _F::ConversionFactor();
}

template <Types::Integer L, Types::Integer R>
inline Types::String ProductFactor<SI::Factor<L>,SI::Factor<R> >::Suffix()
{
  return _F::Suffix();
}

template <typename L>
inline Types::Scalar ProductFactor<L,Identity>::ConversionFactor()
{
  return L::ConversionFactor();
}

template <typename L>
inline Types::String ProductFactor<L,Identity>::Suffix()
{
  return L::Suffix();
}

template <typename R>
inline Types::Scalar ProductFactor<Identity,R>::ConversionFactor()
{
  return R::ConversionFactor();
}

template <typename R>
inline Types::String ProductFactor<Identity,R>::Suffix()
{
  return R::Suffix();
}

inline Types::Scalar ProductFactor<Identity>::ConversionFactor()
{
  return Identity::ConversionFactor();
}

inline Types::String ProductFactor<Identity>::Suffix()
{
  return Identity::Suffix();
}


} //Namespace Unit

