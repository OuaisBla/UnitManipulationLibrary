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


#include "Unit.h"
#include <math.h>
#include <boost\math\constants\constants.hpp>


namespace Unit
{


  template<typename _ScalarType = Types::Scalar, class _Policy = boost::math::policies::precision<_ScalarType, boost::math::policies::policy<> > >
  class _Angle : public Object<_ScalarType, _Policy>, public Facade<_Angle<_ScalarType,_Policy> >
  {

    typedef Facade<_Angle<_ScalarType,_Policy> > _Facade;

  public:

    typedef _ScalarType                         ScalarType;
    typedef typename _Facade::SimplifiedType   SimplifiedType;

    enum { NumeratorBaseTypeValue = 19 };
    enum { DenumeratorBaseTypeValue = 1 };

    inline static ScalarType Normalize( ScalarType value );

    inline void Normalize();

    inline Quantity<SimplifiedType> Normalized() const;

    inline ScalarType cos() const;
    inline ScalarType sin() const;
    inline ScalarType tan() const;

    using Object<_ScalarType, _Policy>::GetValue;
    using Object<_ScalarType, _Policy>::GetFactor;
    using Object<_ScalarType, _Policy>::GetConvertedValue;
    using Object<_ScalarType, _Policy>::SetValue;

    inline static Types::String Suffix()
    { 
      return Types::String( L"rad" );
    }

  };

  template<typename S, class P>
  S _Normalize( S const value )
  {
    S const TowPi = boost::math::constants::two_pi<S,P>();
    S dNormalizedAngle = value - static_cast<S>(static_cast<long>(value / TowPi) * TowPi);

    dNormalizedAngle = dNormalizedAngle >= 0. ? dNormalizedAngle : dNormalizedAngle + TowPi;

    return dNormalizedAngle;
  }

  template<typename S, typename P>
  inline Quantity<typename _Angle<S,P>::SimplifiedType> _Angle<S,P>::Normalized() const
  {
    return Quantity<typename _Angle<S,P>::SimplifiedType>( _Normalize<S,P>( GetConvertedValue() ) );
  }

  template<typename S, typename P>
  inline void _Angle<S,P>::Normalize()
  {
    typename _Angle<S,P>::ScalarType const dNormalizedAngle = _Normalize<S,P>( GetConvertedValue() );

    SetValue( dNormalizedAngle / GetFactor() );
  }

  template<typename S, typename P>
  inline S _Angle<S,P>::cos() const
  {
    return ::cos( GetConvertedValue() );
  }

  template<typename S, typename P>
  inline S _Angle<S,P>::sin() const
  {
    return ::sin( GetConvertedValue() );
  }

  template<typename S, typename P>
  inline S _Angle<S,P>::tan() const
  {
    return ::tan( GetConvertedValue() );
  }


  typedef _Angle<>::SimplifiedType Angle;


namespace SI
{


  typedef Quantity<Angle> Radian;


} //namespace SI


namespace NonSI
{


  struct _Degree : public Angle
  {

    typedef _Degree DerivedType;

    static Types::String Suffix() { return Types::String( L"\x00B0" ); }

  };

  struct _DegreeFactor
  {

    typedef _DegreeFactor               SimplifiedFactor;
    typedef InvertFactor<_DegreeFactor> InvertedFactor;

    static Types::Scalar ConversionFactor() { return .017453292519943295769236907684886; }

    static Types::String Suffix() { return Types::String(); }

  };

  struct _Grade : public Angle
  {

    typedef _Grade DerivedType;

    static Types::String Suffix() { return Types::String( L"gon" ); }

  };

  struct _GradeFactor
  {

    typedef _GradeFactor               SimplifiedFactor;
    typedef InvertFactor<_GradeFactor> InvertedFactor;

    static Types::Scalar ConversionFactor() { return .015707963267948966192313216916398; }

    static Types::String Suffix() { return Types::String(); }

  };

  struct _AngularMinute : public Angle
  {

    typedef _AngularMinute DerivedType;

    static Types::String Suffix() { return Types::String( L"\'" ); }

  };

  struct _AngularMinuteFactor
  {

    typedef _AngularMinuteFactor               SimplifiedFactor;
    typedef InvertFactor<_AngularMinuteFactor> InvertedFactor;

    static Types::Scalar ConversionFactor() { return 2.9088820866572159615394846141467e-4; }

    static Types::String Suffix() { return Types::String(); }

  };

  struct _AngularSecond : public Angle
  {

    typedef _AngularSecond DerivedType;

    static Types::String Suffix() { return Types::String( L"\"" ); }

  };

  struct _AngularSecondFactor
  {

    typedef _AngularSecondFactor               SimplifiedFactor;
    typedef InvertFactor<_AngularSecondFactor> InvertedFactor;

    static Types::Scalar ConversionFactor() { return 4.8481368110953599358991410235778e-6; }

    static Types::String Suffix() { return Types::String(); }

  };


  typedef Quantity<_Degree,_DegreeFactor>                 Degree;
  typedef Quantity<_Grade,_GradeFactor>                   Grade;
  typedef Quantity<_AngularMinute,_AngularMinuteFactor>   AngularMinute;
  typedef Quantity<_AngularSecond,_AngularSecondFactor>   AngularSecond;


} //namespace NonSI


} //Namespace Unit

