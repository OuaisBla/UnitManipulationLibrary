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
class Quantity;


/**
  Class that represents a product of two unit type.
*/

template <typename _L, typename _R = _L>
class Product : public Quantity<
  typename ComplexUnit<typename _L::SimplifiedType, typename _R::SimplifiedType>::SimplifiedType, 
  typename ProductFactor<typename _L::SimplifiedFactor, typename _R::SimplifiedFactor>::SimplifiedFactor>
{
public:

  typedef typename ProductFactor<typename _L::SimplifiedFactor, typename _R::SimplifiedFactor>::SimplifiedFactor    SimplifiedFactor;
  typedef typename SimplifiedFactor::InvertedFactor      InvertedFactor;

  typedef Quantity<typename ComplexUnit<typename _L::SimplifiedType, typename _R::SimplifiedType>::SimplifiedType, SimplifiedFactor> ParentType;

  typedef typename ParentType::BaseType           BaseType;
  typedef typename ParentType::BaseType           DerivedType;
  typedef typename ParentType::SimplifiedType     SimplifiedType;
  typedef typename ParentType::InvertedType       InvertedType;

  typedef typename ParentType::ScalarType         ScalarType;
  typedef typename ParentType::Policy             Policy;
  typedef typename ParentType::Limits             Limits;

public:

  Product() { }

  inline explicit Product( ScalarType );
  inline Product( ScalarType, ScalarType );
  inline Product( _L const &, _R const & );
  inline Product( Product<_L,_R> const & );

  template<
    typename OtherUnitType, 
    typename OtherFactor
    >
  inline Product( Quantity<OtherUnitType, OtherFactor> const &_s ) :
    ParentType( _s )
  {
  }

  inline operator ParentType() const
  {
    return ParentType( mValue );
  }

  virtual ~Product() { }

public:

  inline Product<_L,_R> const & operator= ( ScalarType );
  inline Product<_L,_R> const & operator= ( Product<_L,_R> const & );

};


//
//  Constructor
//

template <typename _L, typename _R>
inline Product<_L,_R>::Product( ScalarType const _value ) : 
  ParentType( _value )
{
}

template <typename _L, typename _R>
inline Product<_L,_R>::Product( ScalarType const _s1, ScalarType const _s2 ) : 
  ParentType( _s1, _s2 )
{
}

template <typename _L, typename _R>
inline Product<_L,_R>::Product( _L const &_l, _R const &_r ) : 
  ParentType( _l._L::GetValue() * _r._R::GetValue() )
{
}

template <typename _L, typename _R>
inline Product<_L,_R>::Product( Product<_L,_R> const &_parent ) : 
  ParentType( _parent ) 
{
}


//
//  Assignment operator
//

template <typename _L, typename _R>
inline Product<_L,_R> const & Product<_L,_R>::operator= ( ScalarType const _s )
{
  ParentType::operator= ( _s );
  return *this;
}

template <typename _L, typename _R>
inline Product<_L,_R> const & Product<_L,_R>::operator= ( Product<_L,_R> const &_parent )
{
  ParentType::operator= ( _parent );
  return *this;
}


} //namespace Unit

