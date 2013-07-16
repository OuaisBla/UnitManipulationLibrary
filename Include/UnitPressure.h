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


#include "UnitForce.h"


namespace Unit
{


namespace SI
{


struct Pressure : public Product<Newton, Product<Meter>::Invert>::UnitType
{

  typedef Pressure DerivedType;

  inline static Types::String Suffix()
  {
    return Types::String( L"Pa" );
  }

};


typedef Quantity<Pressure,Yocto>  Yoctopascal;
typedef Quantity<Pressure,Zepto>  Zeptopascal;
typedef Quantity<Pressure,Atto>   Attopascal;
typedef Quantity<Pressure,Femto>  Femtopascal;
typedef Quantity<Pressure,Pico>   Picopascal;
typedef Quantity<Pressure,Nano>   Nanopascal;
typedef Quantity<Pressure,Micro>  Micropascal;
typedef Quantity<Pressure,Milli>  Millipascal;
typedef Quantity<Pressure,Centi>  Centipascal;
typedef Quantity<Pressure,Deci>   Decipascal;
typedef Quantity<Pressure>        Pascal;
typedef Quantity<Pressure,Deka>   Dekapascal;
typedef Quantity<Pressure,Hecto>  Hectopascal;
typedef Quantity<Pressure,Kilo>   Kilopascal;
typedef Quantity<Pressure,Mega>   Megapascal;
typedef Quantity<Pressure,Giga>   Gigapascal;
typedef Quantity<Pressure,Tera>   Terapascal;
typedef Quantity<Pressure,Peta>   Petapascal;
typedef Quantity<Pressure,Exa>    Exapascal;
typedef Quantity<Pressure,Zetta>  Zeptapascal;
typedef Quantity<Pressure,Yotta>  Yottapascal;


} //namespace SI


} //namespace Unit

