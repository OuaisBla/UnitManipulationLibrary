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


namespace Unit
{


struct _Angle : public Object<>
{

  typedef _Angle BaseType;
  typedef BaseUnit<BaseType> SimplifiedType;

  enum { NumeratorBaseTypeValue = 7 };
  enum { DenumeratorBaseTypeValue = 1 };

  inline static Scalar Normalize( Scalar value );

  inline void Normalize();

  inline Simple<SimplifiedType> Normalized() const;

  inline Scalar cos() const;
  inline Scalar sin() const;
  inline Scalar tan() const;

public:

  inline static String Suffix();

};

inline Simple<_Angle::SimplifiedType> _Angle::Normalized() const
{
  return Simple<_Angle::SimplifiedType>( Normalize( GetConvertedValue() ) );
}

inline void _Angle::Normalize()
{
  Scalar const dNormalizedAngle = Normalize( GetConvertedValue() );

  SetValue( dNormalizedAngle / GetFactor() );
}

Scalar _Angle::Normalize( Scalar const value )
{
  Scalar const TowPi = 6.283185307179586476925286766559;
  Scalar dNormalizedAngle = value - static_cast<Scalar>(static_cast<long>(value / TowPi) * TowPi);

  dNormalizedAngle = dNormalizedAngle >= 0. ? dNormalizedAngle : dNormalizedAngle + TowPi;

  return dNormalizedAngle;
}

inline Scalar _Angle::cos() const
{
  return ::cos( GetConvertedValue() );
}

inline Scalar _Angle::sin() const
{
  return ::sin( GetConvertedValue() );
}

inline Scalar _Angle::tan() const
{
  return ::tan( GetConvertedValue() );
}

inline String _Angle::Suffix()
{ 
  return String( L"rad" );
}


typedef _Angle::SimplifiedType Angle;


namespace SI
{


  typedef Simple<Angle> Radian;


} //namespace SI


namespace NonSI
{


  struct _Degree : public Angle
  {

    static String Suffix() { return String( L"\x00B0" ); }

  };

  struct _DegreeFactor
  {

    typedef _DegreeFactor               SimplifiedFactor;
    typedef InvertFactor<_DegreeFactor> InvertedFactor;

    static Scalar ConversionFactor() { return .017453292519943295769236907684886; }

    static String Suffix() { return String(); }

  };

  struct _Grade : public Angle
  {

    static String Suffix() { return String( L"gon" ); }

  };

  struct _GradeFactor
  {

    typedef _GradeFactor               SimplifiedFactor;
    typedef InvertFactor<_GradeFactor> InvertedFactor;

    static Scalar ConversionFactor() { return .015707963267948966192313216916398; }

    static String Suffix() { return String(); }

  };

  struct _AngularMinute : public Angle
  {

    static String Suffix() { return String( L"\'" ); }

  };

  struct _AngularMinuteFactor
  {

    typedef _AngularMinuteFactor               SimplifiedFactor;
    typedef InvertFactor<_AngularMinuteFactor> InvertedFactor;

    static Scalar ConversionFactor() { return 2.9088820866572159615394846141467e-4; }

    static String Suffix() { return String(); }

  };

  struct _AngularSecond : public Angle
  {

    static String Suffix() { return String( L"\"" ); }

  };

  struct _AngularSecondFactor
  {

    typedef _AngularSecondFactor               SimplifiedFactor;
    typedef InvertFactor<_AngularSecondFactor> InvertedFactor;

    static Scalar ConversionFactor() { return 4.8481368110953599358991410235778e-6; }

    static String Suffix() { return String(); }

  };


  typedef Simple<_Degree,_DegreeFactor>                 Degree;
  typedef Simple<_Grade,_GradeFactor>                   Grade;
  typedef Simple<_AngularMinute,_AngularMinuteFactor>   AngularMinute;
  typedef Simple<_AngularSecond,_AngularSecondFactor>   AngularSecond;


} //namespace NonSI


} //Namespace Unit

