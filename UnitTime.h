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


struct _Time : public Object<>
{

  typedef _Time BaseType;
  typedef BaseUnit<BaseType> SimplifiedType;

  enum { NumeratorBaseTypeValue = 3 };
  enum { DenumeratorBaseTypeValue = 1 };

  inline static String Suffix()
  {
    return String( L"s" );
  }

};


typedef _Time::SimplifiedType Time;


namespace SI
{


typedef Simple<Time,Yocto>    Yoctosecond;
typedef Simple<Time,Zepto>    Zeptosecond;
typedef Simple<Time,Atto>     Attosecond;
typedef Simple<Time,Femto>    Femtosecond;
typedef Simple<Time,Pico>     Picosecond;
typedef Simple<Time,Nano>     Nanosecond;
typedef Simple<Time,Micro>    Microsecond;
typedef Simple<Time,Milli>    Millisecond;
typedef Simple<Time,Centi>    Centisecond;
typedef Simple<Time,Deci>     Decisecond;
typedef Simple<Time>          Second;
typedef Simple<Time,Deka>     Dekasecond;
typedef Simple<Time,Hecto>    Hectosecond;
typedef Simple<Time,Kilo>     Kilosecond;
typedef Simple<Time,Mega>     Megasecond;
typedef Simple<Time,Giga>     Gigasecond; 
typedef Simple<Time,Tera>     Terasecond;
typedef Simple<Time,Peta>     Petasecond;
typedef Simple<Time,Exa>      Exasecond;
typedef Simple<Time,Zetta>    Zettasecond;
typedef Simple<Time,Yotta>    Yottasecond;


} //namespace SI


namespace NonSI
{


struct _Minute : public Time
{

  static String Suffix() { return String( L"min" ); }

};

struct _MinuteFactor
{

  typedef _MinuteFactor               SimplifiedFactor;
  typedef InvertFactor<_MinuteFactor> InvertedFactor;

  static Scalar ConversionFactor() { return 60.; }

  static String Suffix() { return String(); }

};


struct _Hour : public Time
{

  static String Suffix() { return String( L"h" ); }

};

struct _HourFactor
{

  typedef _HourFactor               SimplifiedFactor;
  typedef InvertFactor<_HourFactor> InvertedFactor;

  static Scalar ConversionFactor() { return 3600.; }

  static String Suffix() { return String(); }

};

typedef Simple<_Minute,_MinuteFactor>   Minute;
typedef Simple<_Hour,_HourFactor>       Hour;


} //namespace NonSI


} //namespace Unit

