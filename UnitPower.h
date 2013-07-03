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

  inline static String Suffix()
  {
    return String( L"W" );
  }

};


typedef Simple<Power,Yocto>  Yoctowatt;
typedef Simple<Power,Zepto>  Zeptowatt;
typedef Simple<Power,Atto>   Attowatt;
typedef Simple<Power,Femto>  Femtowatt;
typedef Simple<Power,Pico>   Picowatt;
typedef Simple<Power,Nano>   Nanowatt;
typedef Simple<Power,Micro>  Microwatt;
typedef Simple<Power,Milli>  Milliwatt;
typedef Simple<Power,Centi>  Centiwatt;
typedef Simple<Power,Deci>   Deciwatt;
typedef Simple<Power>        Watt;
typedef Simple<Power,Deka>   Dekawatt;
typedef Simple<Power,Hecto>  Hectowatt;
typedef Simple<Power,Kilo>   Kilowatt;
typedef Simple<Power,Mega>   Megawatt;
typedef Simple<Power,Giga>   Gigawatt;
typedef Simple<Power,Tera>   Terawatt;
typedef Simple<Power,Peta>   Petawatt;
typedef Simple<Power,Exa>    Exawatt;
typedef Simple<Power,Zetta>  Zeptawatt;
typedef Simple<Power,Yotta>  Yottawatt;


} //namespace SI


} //namespace Unit

