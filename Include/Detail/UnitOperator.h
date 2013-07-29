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


#include "Detail\UnitObject.h"


namespace Unit
{


template <typename, typename>
class Quantity;

template <typename, typename>
class Product;


//
//  Definition of comparison operator.
//

template <typename T, typename F>
inline bool operator== ( Quantity<T,F> const &_s1, Quantity<T,F> const &_s2 )
{
  return ::fabs( _s1.Quantity<T,F>::GetValue() - _s2.Quantity<T,F>::GetValue() ) < Quantity<T,F>::Epsilon();
}

template <typename T, typename F>
inline bool operator!= ( Quantity<T,F> const &_s1, Quantity<T,F> const &_s2 )
{
  return !(_s1 == _s2);
}

template <typename T, typename F>
inline bool operator< ( Quantity<T,F> const &_s1, Quantity<T,F> const &_s2 )
{
  return _s1.Quantity<T,F>::GetValue() < _s2.Quantity<T,F>::GetValue() && _s1 != _s2;
}

template <typename T, typename F>
inline bool operator> ( Quantity<T,F> const &_s1, Quantity<T,F> const &_s2 )
{
  return  _s2 < _s1;
}

template <typename T, typename F>
inline bool operator<= ( Quantity<T,F> const &_s1, Quantity<T,F> const &_s2 )
{
  return !(_s2 < _s1);
}

template <typename T, typename F>
inline bool operator>= ( Quantity<T,F> const &_s1, Quantity<T,F> const &_s2 )
{
  return !(_s1 < _s2);
}

//
//  Definition of overloaded comparison operator.
//

template <typename T, typename F1, typename F2>
inline bool operator== ( Quantity<T,F1> const &_s1, Quantity<T,F2> const &_s2 )
{
  typedef typename ProductFactor<F1, typename F2::InvertedFactor>::SimplifiedFactor _ScaledFactor;

  Types::Scalar const _scaleFactor =  ::pow( _ScaledFactor::ConversionFactor(), ::abs( T::Exponent ) );

  T::ScalarType const _s1Value = _s1.Quantity<T,F1>::GetValue() * _scaleFactor;
  T::ScalarType const _s2Value = _s2.Quantity<T,F2>::GetValue();

  return ::fabs( _s1Value - _s2Value ) < Quantity<T,_ScaledFactor>::Epsilon();
}

template <typename T, typename F1, typename F2>
inline bool operator!= ( Quantity<T,F1> const &_s1, Quantity<T,F2> const &_s2 )
{
  return !(_s1 == _s2);
}

template <typename T, typename F1, typename F2>
inline bool operator< ( Quantity<T,F1> const &_s1, Quantity<T,F2> const &_s2 )
{
  typedef typename ProductFactor<F1, typename F2::InvertedFactor>::SimplifiedFactor _ScaledFactor;

  Types::Scalar const _scaleFactor = ::pow( _ScaledFactor::ConversionFactor(), ::abs( T::Exponent ) );

  T::ScalarType const _s1Value = _s1.Quantity<T,F1>::GetValue() * _scaleFactor;
  T::ScalarType const _s2Value = _s2.Quantity<T,F2>::GetValue();

  return _s1Value < _s2Value && 
    ::fabs( _s1Value - _s2Value ) >= Quantity<T,_ScaledFactor>::Epsilon();
}

template <typename T, typename F1, typename F2>
inline bool operator> ( Quantity<T,F1> const &_s1, Quantity<T,F2> const &_s2 )
{
  return  _s2 < _s1;
}

template <typename T, typename F1, typename F2>
inline bool operator<= ( Quantity<T,F1> const &_s1, Quantity<T,F2> const &_s2 )
{
  return !(_s2 < _s1);
}

template <typename T, typename F1, typename F2>
inline bool operator>= ( Quantity<T,F1> const &_s1, Quantity<T,F2> const &_s2 )
{
  return !(_s1 < _s2);
}


//
//  Definition of arithmetical operator (Template)
//

template <typename T1, typename T2, typename F1, typename F2>
inline bool operator== ( Quantity<T1,F1> const &_s1, Quantity<T2,F2> const &_s2 )
{
  std::is_convertible<typename Quantity<T1,F1>::ScalarType, typename Quantity<T2,F2>::ScalarType>();

  Detail::CompatibleUnit<Quantity<T1,F1>::NumeratorBaseTypeValue == Quantity<T2,F2>::NumeratorBaseTypeValue && 
    Quantity<T1,F1>::DenumeratorBaseTypeValue == Quantity<T2,F2>::DenumeratorBaseTypeValue>();

  typedef typename ProductFactor<F1, typename F2::InvertedFactor>::SimplifiedFactor _ScaledFactor;

  Types::Scalar const _scaleFactor =  ::pow( _ScaledFactor::ConversionFactor(), ::abs( T1::Exponent ) );

  typename Quantity<T1,F1>::ScalarType const _s1scaled = _s1.Quantity<T1,F1>::GetValue() * _scaleFactor;
  typename Quantity<T2,F2>::ScalarType const _s2scaled = OffsetHandler<T1, T2>::Convert( _s2.Quantity<T2,F2>::GetValue() );

  return ::fabs( _s1scaled - _s2scaled ) < Quantity<T1,_ScaledFactor>::Epsilon();
}

template <typename T1, typename T2, typename F1, typename F2>
inline bool operator!= ( Quantity<T1,F1> const &_s1, Quantity<T2,F2> const &_s2 )
{
  return !(_s1 == _s2);
}

template <typename T1, typename T2, typename F1, typename F2>
inline bool operator< ( Quantity<T1,F1> const &_s1, Quantity<T2,F2> const &_s2 )
{
  std::is_convertible<typename Quantity<T1,F1>::ScalarType, typename Quantity<T2,F2>::ScalarType>();

  Detail::CompatibleUnit<Quantity<T1,F1>::NumeratorBaseTypeValue == Quantity<T2,F2>::NumeratorBaseTypeValue && 
    Quantity<T1,F1>::DenumeratorBaseTypeValue == Quantity<T2,F2>::DenumeratorBaseTypeValue>();

  typedef typename ProductFactor<F1, typename F2::InvertedFactor>::SimplifiedFactor _ScaledFactor;

  Types::Scalar const _scaleFactor =  ::pow( _ScaledFactor::ConversionFactor(), ::abs( T1::Exponent ) );

  typename Quantity<T1,F1>::ScalarType const _s1scaled = _s1.Quantity<T1,F1>::GetValue() * _scaleFactor;
  typename Quantity<T2,F2>::ScalarType const _s2scaled = OffsetHandler<T1, T2>::Convert( _s2.Quantity<T2,F2>::GetValue() );

  return _s1scaled < _s2scaled && 
    ::fabs( _s1scaled - _s2scaled ) >= Quantity<T1,_ScaledFactor>::Epsilon();
}

template <typename T1, typename T2, typename F1, typename F2>
inline bool operator> ( Quantity<T1,F1> const &_s1, Quantity<T2,F2> const &_s2 )
{
  return  _s2 < _s1;
}

template <typename T1, typename T2, typename F1, typename F2>
inline bool operator<= ( Quantity<T1,F1> const &_s1, Quantity<T2,F2> const &_s2 )
{
  return !(_s2 < _s1);
}

template <typename T1, typename T2, typename F1, typename F2>
inline bool operator>= ( Quantity<T1,F1> const &_s1, Quantity<T2,F2> const &_s2 )
{
  return !(_s1 < _s2);
}

//
//  Definition of arithmetical operator (Quantity and scalar)
//

template <typename T, typename F>
inline Quantity<T,F> operator* ( Quantity<T,F> const &_o, Types::Scalar const _s )
{
  return Quantity<T,F>( _o.Quantity<T,F>::GetValue() * _s );
}

template <typename T, typename F>
inline Quantity<T,F> operator* ( Types::Scalar const _s, Quantity<T,F> const &_o )
{
  return _o * _s;
}

template <typename T, typename F>
inline Quantity<T,F> operator/ ( Quantity<T,F> const &_o, Types::Scalar const _s )
{
  return Quantity<T,F>( _o.Quantity<T,F>::GetValue() / _s );
}

template <typename T, typename F>
inline typename Quantity<T,F>::Invert operator/ ( Types::Scalar const _s, Quantity<T,F> const &_o )
{
  return typename Quantity<T,F>::Invert( _s / _o.Quantity<T,F>::GetValue() );
}


//
//  Definition of specialized arithmetical operator (Binary)
//

template <typename T, typename F>
inline Quantity<T,F> operator+ ( Quantity<T,F> const &_s1, Quantity<T,F> const &_s2 )
{
  return Quantity<T,F> ( _s1.Quantity<T,F>::GetValue() + _s2.Quantity<T,F>::GetValue() );
}

template <typename T, typename F>
inline Quantity<T,F> operator- ( Quantity<T,F> const &_s1, Quantity<T,F> const &_s2 )
{
  return Quantity<T,F> ( _s1.Quantity<T,F>::GetValue() - _s2.Quantity<T,F>::GetValue() );
}

template <typename T, typename F>
inline Types::Scalar operator/ ( Quantity<T,F> const &_s1, Quantity<T,F> const &_s2 )
{
  return _s1.Quantity<T,F>::GetValue() / _s2.Quantity<T,F>::GetValue();
}

template <typename T, typename F,Types::Integer Exp>
inline Types::Scalar operator* ( Quantity<BaseUnit<T,Exp>,F> const &_s1, Quantity<BaseUnit<T,-Exp>,F> const &_s2 )
{
  return _s1.Quantity<BaseUnit<T,Exp>,F>::GetValue() * _s2.Quantity<BaseUnit<T,-Exp>,F>::GetValue();
}


//
//  Definition of overloaded arithmetical operator (Binary)
//

template <typename T, typename F1, typename F2>
inline Quantity<T,typename ProductFactor<F1, F2>::SimplifiedFactor> operator+ ( Quantity<T,F1> const &_s1, Quantity<T,F2> const &_s2 )
{
  typedef Quantity<T,typename ProductFactor<F1, F2>::SimplifiedFactor> _ScaledType;

  _ScaledType const _s1scaled = _ScaledType(_s1);
  _ScaledType const _s2scaled = _ScaledType(_s2);

  return _ScaledType( _s1scaled._ScaledType::GetValue() + _s2scaled._ScaledType::GetValue() );
}

template <typename T, typename F1, typename F2>
inline Quantity<T,typename ProductFactor<F1, F2>::SimplifiedFactor> operator- ( Quantity<T,F1> const &_s1, Quantity<T,F2> const &_s2 )
{
  typedef Quantity<T,typename ProductFactor<F1, F2>::SimplifiedFactor> _ScaledType;

  _ScaledType const _s1scaled = _ScaledType(_s1);
  _ScaledType const _s2scaled = _ScaledType(_s2);

  return _ScaledType( _s1scaled._ScaledType::GetValue() - _s2scaled._ScaledType::GetValue() );
}

template <typename T, typename F1, typename F2>
inline Types::Scalar operator/ ( Quantity<T,F1> const &_s1, Quantity<T,F2> const &_s2 )
{
  typedef Quantity<T,typename ProductFactor<F1, F2>::SimplifiedFactor> _ScaledType;

  _ScaledType const _s1scaled = _ScaledType(_s1);
  _ScaledType const _s2scaled = _ScaledType(_s2);

  return (_s1scaled._ScaledType::GetValue() / _s2scaled._ScaledType::GetValue() );
}


//
//  Definition of specialized arithmetical operator (Unary).
//

template <typename T, typename F>
inline Quantity<T,F> operator- ( Quantity<T,F> const &_s )
{
  return Quantity<T,F>( -_s.Quantity<T,F>::GetValue() );
}


//
//  Definition of assignment arithmetical operator (Binary).
//

template <typename T, typename F1, typename F2>
inline Quantity<T,F1> const & operator+= ( Quantity<T,F1> &_s1, Quantity<T,F2> const &_s2 )
{
  return _s1 = _s1 + _s2;
}

template <typename T, typename F1, typename F2>
inline Quantity<T,F1> const & operator-= ( Quantity<T,F1> &_s1, Quantity<T,F2> const &_s2 )
{
  return _s1 = _s1 - _s2;
}

template <typename T, typename F>
inline Quantity<T,F> const & operator*= ( Quantity<T,F> &_o, Types::Scalar const _s )
{
  return _o = _o * _s;
}

template <typename T, typename F>
inline Quantity<T,F> const & operator/= ( Quantity<T,F> &_o, Types::Scalar const _s )
{
  return _o = _o / _s;
}


//
//  Definition of arithmetical operator related to Identity.
//

template <typename T, typename F>
inline Quantity<T,F> const & operator* ( Quantity<T,F> const &_s, Identity const & )
{
  return _s;
}

template <typename T, typename F>
inline Quantity<T,F> const & operator* ( Identity const &, Quantity<T,F> const &_s )
{
  return _s;
}

template <typename T, typename F>
inline Quantity<T,F> const & operator/ ( Quantity<T,F> const &_s, Identity const & )
{
  return _s;
}

template <typename T, typename F>
inline typename Quantity<T,F>::Invert operator/ ( Identity const &, Quantity<T,F> const &_s )
{
  return typename Quantity<T,F>::Invert( 1. / _s.Quantity<T,F>::GetValue() );
}


//
//  Complex related binary operator.
//

template <typename T1, typename F1, typename T2, typename F2>
inline typename Product<Quantity<T1,F1>,Quantity<T2,F2> >::QuantityType operator* ( Quantity<T1,F1> const &_s1, Quantity<T2,F2> const &_s2 )
{
  std::is_convertible<typename Quantity<T1,F1>::ScalarType, typename Quantity<T2,F2>::ScalarType>();

  typedef typename Product<Quantity<T1,F1>,Quantity<T2,F2> >::QuantityType ProductType;

  Scalar const factor = ProductType::InvertedFactor::ConversionFactor();

  ProductType::ScalarType const _s1value = _s1.Quantity<T1,F1>::GetValue() * Quantity<T1,F1>::SimplifiedFactor::ConversionFactor();
  ProductType::ScalarType const _s2value = _s2.Quantity<T2,F2>::GetValue() * Quantity<T2,F2>::SimplifiedFactor::ConversionFactor();

  return ProductType( (_s1value * _s2value) * factor );
}


template <typename T1, typename F1, typename T2, typename F2>
inline typename Product<Quantity<T1,F1>,typename Quantity<T2,F2>::Invert>::QuantityType operator/ ( Quantity<T1,F1> const &_s1, Quantity<T2,F2> const &_s2 )
{
  std::is_convertible<typename Quantity<T1,F1>::ScalarType, typename Quantity<T2,F2>::ScalarType>();

  typedef typename Product<Quantity<T1,F1>,typename Quantity<T2,F2>::Invert>::QuantityType ProductType;

  Scalar const factor = ProductType::InvertedFactor::ConversionFactor();

  ProductType::ScalarType const _s1value = _s1.Quantity<T1,F1>::GetValue() * Quantity<T1,F1>::SimplifiedFactor::ConversionFactor();
  ProductType::ScalarType const _s2value = _s2.Quantity<T2,F2>::GetValue() * Quantity<T2,F2>::SimplifiedFactor::ConversionFactor();

  return ProductType( (_s1value / _s2value) * factor );
}

template <typename T, Types::Integer E, typename F>
inline Quantity<BaseUnit<T, E / 2>, F> sqrt( Quantity<BaseUnit<T, E>, F> const &_s )
{
  Detail::CompatibleUnit<(E > 1)>();

  typedef Quantity<BaseUnit<T, E>, F> _QuantityTypeArg;
  typedef Quantity<BaseUnit<T, E / 2>, F> _QuantityTypeReturn;

  return _QuantityTypeReturn( ::sqrt( _s._QuantityTypeArg::GetValue() ) );
}

template <typename _L, Types::Integer ExpL, typename _R, Types::Integer ExpR, Types::Integer E, typename F>
inline Quantity<BaseUnit<ComplexUnit<BaseUnit<_L,(ExpL * E) / 2>, BaseUnit<_R,(ExpR * E) / 2> >, 1>, F> 
  sqrt( Quantity<BaseUnit<ComplexUnit<BaseUnit<_L,ExpL>, BaseUnit<_R,ExpR> >, E>, F> const &_s )
{
  CompatibleUnit<(E * ExpL > 1) && (E * ExpR > 1)>();

  typedef Quantity<BaseUnit<ComplexUnit<BaseUnit<_L,ExpL>, BaseUnit<_R,ExpR> >, E>, F> _QuantityTypeArg;
  typedef Quantity<BaseUnit<ComplexUnit<BaseUnit<_L,(ExpL * E) / 2>, BaseUnit<_R,(ExpR * E) / 2> >, 1>, F> _QuantityTypeReturn;

  return _QuantityTypeReturn( ::sqrt( _s._QuantityTypeArg::GetValue() ) );
}


} //Namespace Unit

