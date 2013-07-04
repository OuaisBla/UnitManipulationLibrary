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


#include "UnitComplex.h"


namespace Unit
{


template <typename, typename>
class Simple;


/**
  Class that represents a product of two unit type.
*/

template <typename L, typename R = L>
class Product : public Simple<
  typename PS2<typename L::SimplifiedType, typename R::SimplifiedType>::SimplifiedType, 
  typename ProductFactor<typename L::SimplifiedFactor, typename R::SimplifiedFactor>::SimplifiedFactor>
{
public:

  typedef typename ProductFactor<typename L::SimplifiedFactor, typename R::SimplifiedFactor>::SimplifiedFactor    SimplifiedFactor;
  typedef typename ProductFactor<typename L::SimplifiedFactor, typename R::SimplifiedFactor>::InvertedFactor      InvertedFactor;

  typedef Simple<typename PS2<typename L::SimplifiedType, typename R::SimplifiedType>::SimplifiedType, SimplifiedFactor> ParentType;

  typedef typename ParentType::BaseType           BaseType;
  typedef typename ParentType::SimplifiedType     SimplifiedType;

  typedef typename ParentType::ScalarType         ScalarType;

public:

  Product() { }

  inline explicit Product( ScalarType );
  inline Product( ScalarType, ScalarType );
  inline Product( L const &, R const & );
  inline Product( Product<L,R> const & );
  inline Product( Product<R,L> const & );

  template<
    typename OtherUnitType, 
    typename OtherFactor
    >
  inline Product( Simple<OtherUnitType, OtherFactor> const &_s ) :
    ParentType( _s )
  {
  }

  inline operator ParentType() const
  {
    return ParentType( mValue );
  }

  virtual ~Product() { }

public:

  inline Product<L,R> const & operator= ( ScalarType );
  inline Product<L,R> const & operator= ( Product<L,R> const & );
  inline Product<L,R> const & operator= ( Product<R,L> const & );

};


/**
  Class that represents a product of two unit type. (Specialization)
*/

template <typename T, Integer a, Integer b, typename F1, typename F2>
class Product<Simple<BaseUnit<T,a>,F1>,Simple<BaseUnit<T,b>,F2> > : public Simple<
  typename BaseUnit<typename T::BaseType,a+b>::SimplifiedType, 
  typename ProductFactor<F1,F2>::SimplifiedFactor>
{
  
  typedef Simple<BaseUnit<T,a>,F1> L;
  typedef Simple<BaseUnit<T,b>,F2> R;

public:

  typedef typename ProductFactor<typename L::SimplifiedFactor, typename R::SimplifiedFactor>::SimplifiedFactor  SimplifiedFactor;
  typedef typename ProductFactor<typename L::SimplifiedFactor, typename R::SimplifiedFactor>::InvertedFactor    InvertedFactor;

  typedef Simple<typename BaseUnit<typename T::BaseType,a + b>::SimplifiedType, SimplifiedFactor> ParentType;

  typedef typename ParentType::BaseType           BaseType;
  typedef typename ParentType::SimplifiedType     SimplifiedType;

  typedef typename ParentType::ScalarType         ScalarType;

public:

  Product() { }
  
  inline explicit Product( ScalarType );
  inline Product( ScalarType, ScalarType );
  inline Product( L const &, R const & );
  inline Product( Product<L,R> const & );

  template<
    typename OtherUnitType, 
    typename OtherFactor
  >
  inline Product( Simple<OtherUnitType, OtherFactor> const &_s ) :
    ParentType( _s )
  {
  }


  virtual ~Product() { }

public:

  inline Product<L,R> const & operator= ( ScalarType );
  inline Product<L,R> const & operator= ( Product<L,R> const & );

};


//
//  Constructor
//

template <typename L, typename R>
inline Product<L,R>::Product( ScalarType const _value ) : 
  ParentType( _value )
{
}

template <typename L, typename R>
inline Product<L,R>::Product( ScalarType const _s1, ScalarType const _s2 ) : 
  ParentType( _s1, _s2 )
{
}

template <typename L, typename R>
inline Product<L,R>::Product( L const &_l, R const &_r ) : 
  ParentType( _l.L::GetValue() * _r.R::GetValue() )
{
}

template <typename L, typename R>
inline Product<L,R>::Product( Product<L,R> const &_parent ) : 
  ParentType( _parent ) 
{
}

template <typename L, typename R>
inline Product<L,R>::Product( Product<R,L> const &_parent ) : 
  ParentType( _parent.Product<R,L>::GetValue() )
{
}

template <typename T, Integer a, Integer b, typename F1, typename F2>
inline Product<Simple<BaseUnit<T,a>,F1>,Simple<BaseUnit<T,b>,F2> >::Product( ScalarType const _s ) : 
  ParentType( _s )
{
}

template <typename T, Integer a, Integer b, typename F1, typename F2>
inline Product<Simple<BaseUnit<T,a>,F1>,Simple<BaseUnit<T,b>,F2> >::Product( ScalarType const _s1, ScalarType const _s2 ) : 
  ParentType( _s1, _s2 )
{
}

template <typename T, Integer a, Integer b, typename F1, typename F2>
inline Product<Simple<BaseUnit<T,a>,F1>,Simple<BaseUnit<T,b>,F2> >::Product( L const &_l, R const &_r ) : 
  ParentType( _l.L::GetValue() * _r.R::GetValue() )
{
}

template <typename T, Integer a, Integer b, typename F1, typename F2>
inline Product<Simple<BaseUnit<T,a>,F1>,Simple<BaseUnit<T,b>,F2> >::Product( Product<L,R> const &_parent ) : 
  ParentType( _parent )
{
}


//
//  Assignment operator
//

template <typename L, typename R>
inline Product<L,R> const & Product<L,R>::operator= ( ScalarType const _s )
{
  ParentType::operator= ( _s );
  return *this;
}

template <typename L, typename R>
inline Product<L,R> const & Product<L,R>::operator= ( Product<L,R> const &_parent )
{
  ParentType::operator= ( _parent );
  return *this;
}

template <typename L, typename R>
inline Product<L,R> const & Product<L,R>::operator= ( Product<R,L> const &_parent )
{
  ParentType::operator= ( _parent.Product<R,L>::GetValue() );
  return *this;
}

template <typename T, Integer a, Integer b, typename F1, typename F2>
inline Product<Simple<BaseUnit<T,a>,F1>,Simple<BaseUnit<T,b>,F2> > const & Product<Simple<BaseUnit<T,a>,F1>,Simple<BaseUnit<T,b>,F2> >::operator= ( ScalarType const _s )
{
  ParentType::operator= ( _s );
  return *this;
}


template <typename T, Integer a, Integer b, typename F1, typename F2>
inline Product<Simple<BaseUnit<T,a>,F1>,Simple<BaseUnit<T,b>,F2> > const & Product<Simple<BaseUnit<T,a>,F1>,Simple<BaseUnit<T,b>,F2> >::operator= ( Product<L,R> const &_parent )
{
  ParentType::operator= ( _parent );
  return *this;
}


} //namespace Unit

