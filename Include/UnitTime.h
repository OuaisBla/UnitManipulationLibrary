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


struct _Time : public Object<>, public Facade<_Time>
{

  enum { NumeratorBaseTypeValue = 5 };
  enum { DenumeratorBaseTypeValue = 1 };

  inline static Types::String Suffix()
  {
    return Types::String( L"s" );
  }

};


typedef _Time::SimplifiedType Time;


namespace SI
{


typedef Quantity<Time,Yocto>    Yoctosecond;
typedef Quantity<Time,Zepto>    Zeptosecond;
typedef Quantity<Time,Atto>     Attosecond;
typedef Quantity<Time,Femto>    Femtosecond;
typedef Quantity<Time,Pico>     Picosecond;
typedef Quantity<Time,Nano>     Nanosecond;
typedef Quantity<Time,Micro>    Microsecond;
typedef Quantity<Time,Milli>    Millisecond;
typedef Quantity<Time,Centi>    Centisecond;
typedef Quantity<Time,Deci>     Decisecond;
typedef Quantity<Time>          Second;
typedef Quantity<Time,Deka>     Dekasecond;
typedef Quantity<Time,Hecto>    Hectosecond;
typedef Quantity<Time,Kilo>     Kilosecond;
typedef Quantity<Time,Mega>     Megasecond;
typedef Quantity<Time,Giga>     Gigasecond; 
typedef Quantity<Time,Tera>     Terasecond;
typedef Quantity<Time,Peta>     Petasecond;
typedef Quantity<Time,Exa>      Exasecond;
typedef Quantity<Time,Zetta>    Zettasecond;
typedef Quantity<Time,Yotta>    Yottasecond;


} //namespace SI


namespace NonSI
{


struct _Minute : public Time
{

  typedef _Minute DerivedType;

  static Types::String Suffix() { return Types::String( L"min" ); }

};

struct _MinuteFactor
{

  typedef _MinuteFactor               SimplifiedFactor;
  typedef InvertFactor<_MinuteFactor> InvertedFactor;

  static Types::Scalar ConversionFactor() { return 60.; }

  static Types::String Suffix() { return Types::String(); }

};


struct _Hour : public Time
{

  typedef _Hour DerivedType;

  static Types::String Suffix() { return Types::String( L"h" ); }

};

struct _HourFactor
{

  typedef _HourFactor               SimplifiedFactor;
  typedef InvertFactor<_HourFactor> InvertedFactor;

  static Types::Scalar ConversionFactor() { return 3600.; }

  static Types::String Suffix() { return Types::String(); }

};

typedef Quantity<_Minute,_MinuteFactor>   Minute;
typedef Quantity<_Hour,_HourFactor>       Hour;


} //namespace NonSI


} //namespace Unit

