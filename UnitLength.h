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


namespace Unit
{


  template<typename _ScalarType = Scalar>
  struct _Length : public Object<_ScalarType>
  {

    typedef _Length             BaseType;
    typedef BaseUnit<BaseType>  SimplifiedType;

    enum { NumeratorBaseTypeValue = 2 };
    enum { DenumeratorBaseTypeValue = 1 };

    inline static String Suffix()
    { 
      return String( L"m" );
    }

  };


typedef _Length<>::SimplifiedType Length;


namespace SI
{


typedef Simple<Length,Yocto>    Yoctometer;
typedef Simple<Length,Zepto>    Zeptometer;
typedef Simple<Length,Atto>     Attometer;
typedef Simple<Length,Femto>    Femtometer;
typedef Simple<Length,Pico>     Picometer;
typedef Simple<Length,Nano>     Nanometer;
typedef Simple<Length,Micro>    Micrometer;
typedef Simple<Length,Milli>    Millimeter;
typedef Simple<Length,Centi>    Centimeter;
typedef Simple<Length,Deci>     Decimeter;
typedef Simple<Length>          Meter;
typedef Simple<Length,Deka>     Dekameter;
typedef Simple<Length,Hecto>    Hectometer;
typedef Simple<Length,Kilo>     Kilometer;
typedef Simple<Length,Mega>     Megameter;
typedef Simple<Length,Giga>     Gigameter;
typedef Simple<Length,Tera>     Terameter;
typedef Simple<Length,Peta>     Petameter;
typedef Simple<Length,Exa>      Exameter;
typedef Simple<Length,Zetta>    Zeptameter;
typedef Simple<Length,Yotta>    Yottameter;


} // namespace SI


namespace NonSI
{


struct _Mil : public Length
{

  static String Suffix() { return String( L"mil" ); }

};

struct _MilFactor
{

  typedef _MilFactor                SimplifiedFactor;
  typedef InvertFactor<_MilFactor>  InvertedFactor;

  static Scalar ConversionFactor() { return .0000254; }

  static String Suffix() { return String(); }

};


struct _Inch : public Length
{

  static String Suffix() { return String( L"in" ); }

};

struct _InchFactor : public Length
{

  typedef _InchFactor               SimplifiedFactor;
  typedef InvertFactor<_InchFactor> InvertedFactor;

  static Scalar ConversionFactor() { return .0254; }

  static String Suffix() { return String(); }

};

struct _Foot : public Length
{

  static String Suffix() { return String( L"ft" ); }

};

class _FootFactor
{
public:

  typedef _FootFactor               SimplifiedFactor;
  typedef InvertFactor<_FootFactor> InvertedFactor;

  static Scalar ConversionFactor() { return .3048; }

  static String Suffix() { return String(); }

};

typedef Simple<_Mil,_MilFactor>     Mil;
typedef Simple<_Inch,_InchFactor>   Inch;
typedef Simple<_Foot,_FootFactor>   Foot;


} //namespace NonSI


} //Namespace Unit

