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


struct _Mass : public Object<>, public Facade<_Mass>
{

  typedef SI::Kilo SimplifiedFactor;

  enum { NumeratorBaseTypeValue = 5 };
  enum { DenumeratorBaseTypeValue = 1 };

  inline static String Suffix()
  {
    return String( L"g" );
  }

};


typedef _Mass::SimplifiedType Mass;


namespace SI
{


typedef Simple<Mass,Yocto>    Yoctogram;
typedef Simple<Mass,Zepto>    Zeptogram;
typedef Simple<Mass,Atto>     Attogram;
typedef Simple<Mass,Femto>    Femtogram;
typedef Simple<Mass,Pico>     Picogram;
typedef Simple<Mass,Nano>     Nanogram;
typedef Simple<Mass,Micro>    Microgram;
typedef Simple<Mass,Milli>    Milligram;
typedef Simple<Mass,Centi>    Centigram;
typedef Simple<Mass,Deci>     Decigram;
typedef Simple<Mass>          Gram;
typedef Simple<Mass,Deka>     Dekagram;
typedef Simple<Mass,Hecto>    Hectogram;
typedef Simple<Mass,Kilo>     Kilogram;
typedef Simple<Mass,Mega>     Megagram;
typedef Simple<Mass,Giga>     Gigagram;
typedef Simple<Mass,Tera>     Teragram;
typedef Simple<Mass,Peta>     Petagram;
typedef Simple<Mass,Exa>      Exagram;
typedef Simple<Mass,Zetta>    Zeptagram;
typedef Simple<Mass,Yotta>    Yottagram;


} //namespace SI


} //namespace Unit

