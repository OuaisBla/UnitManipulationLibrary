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


#include "UnitEnergy.h"


namespace Unit
{


namespace SI
{

struct Power : public Product<Joule,Second::Invert>::UnitType
{

  typedef Power DerivedType;

  inline static Types::String Suffix()
  {
    return Types::String( L"W" );
  }

};


typedef Quantity<Power,Yocto>  Yoctowatt;
typedef Quantity<Power,Zepto>  Zeptowatt;
typedef Quantity<Power,Atto>   Attowatt;
typedef Quantity<Power,Femto>  Femtowatt;
typedef Quantity<Power,Pico>   Picowatt;
typedef Quantity<Power,Nano>   Nanowatt;
typedef Quantity<Power,Micro>  Microwatt;
typedef Quantity<Power,Milli>  Milliwatt;
typedef Quantity<Power,Centi>  Centiwatt;
typedef Quantity<Power,Deci>   Deciwatt;
typedef Quantity<Power>        Watt;
typedef Quantity<Power,Deka>   Dekawatt;
typedef Quantity<Power,Hecto>  Hectowatt;
typedef Quantity<Power,Kilo>   Kilowatt;
typedef Quantity<Power,Mega>   Megawatt;
typedef Quantity<Power,Giga>   Gigawatt;
typedef Quantity<Power,Tera>   Terawatt;
typedef Quantity<Power,Peta>   Petawatt;
typedef Quantity<Power,Exa>    Exawatt;
typedef Quantity<Power,Zetta>  Zeptawatt;
typedef Quantity<Power,Yotta>  Yottawatt;


} //namespace SI


} //namespace Unit

