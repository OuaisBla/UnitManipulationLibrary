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

  inline static String Suffix()
  {
    return String( L"Pa" );
  }

};


typedef Simple<Pressure,Yocto>  Yoctopascal;
typedef Simple<Pressure,Zepto>  Zeptopascal;
typedef Simple<Pressure,Atto>   Attopascal;
typedef Simple<Pressure,Femto>  Femtopascal;
typedef Simple<Pressure,Pico>   Picopascal;
typedef Simple<Pressure,Nano>   Nanopascal;
typedef Simple<Pressure,Micro>  Micropascal;
typedef Simple<Pressure,Milli>  Millipascal;
typedef Simple<Pressure,Centi>  Centipascal;
typedef Simple<Pressure,Deci>   Decipascal;
typedef Simple<Pressure>        Pascal;
typedef Simple<Pressure,Deka>   Dekapascal;
typedef Simple<Pressure,Hecto>  Hectopascal;
typedef Simple<Pressure,Kilo>   Kilopascal;
typedef Simple<Pressure,Mega>   Megapascal;
typedef Simple<Pressure,Giga>   Gigapascal;
typedef Simple<Pressure,Tera>   Terapascal;
typedef Simple<Pressure,Peta>   Petapascal;
typedef Simple<Pressure,Exa>    Exapascal;
typedef Simple<Pressure,Zetta>  Zeptapascal;
typedef Simple<Pressure,Yotta>  Yottapascal;


} //namespace SI


} //namespace Unit

