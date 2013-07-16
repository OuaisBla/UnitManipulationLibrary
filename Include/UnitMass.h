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

  enum { NumeratorBaseTypeValue = 3 };
  enum { DenumeratorBaseTypeValue = 1 };

  inline static Types::String Suffix()
  {
    return Types::String( L"g" );
  }

};


typedef _Mass::SimplifiedType Mass;


namespace SI
{


typedef Quantity<Mass,Yocto>    Yoctogram;
typedef Quantity<Mass,Zepto>    Zeptogram;
typedef Quantity<Mass,Atto>     Attogram;
typedef Quantity<Mass,Femto>    Femtogram;
typedef Quantity<Mass,Pico>     Picogram;
typedef Quantity<Mass,Nano>     Nanogram;
typedef Quantity<Mass,Micro>    Microgram;
typedef Quantity<Mass,Milli>    Milligram;
typedef Quantity<Mass,Centi>    Centigram;
typedef Quantity<Mass,Deci>     Decigram;
typedef Quantity<Mass>          Gram;
typedef Quantity<Mass,Deka>     Dekagram;
typedef Quantity<Mass,Hecto>    Hectogram;
typedef Quantity<Mass,Kilo>     Kilogram;
typedef Quantity<Mass,Mega>     Megagram;
typedef Quantity<Mass,Giga>     Gigagram;
typedef Quantity<Mass,Tera>     Teragram;
typedef Quantity<Mass,Peta>     Petagram;
typedef Quantity<Mass,Exa>      Exagram;
typedef Quantity<Mass,Zetta>    Zeptagram;
typedef Quantity<Mass,Yotta>    Yottagram;


} //namespace SI


} //namespace Unit

