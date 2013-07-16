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


#include "UnitLength.h"


namespace Unit
{


namespace SI
{


typedef Product<Meter>::UnitType Area;


typedef Quantity<Area,Yocto>  Yoctosquaremeter;
typedef Quantity<Area,Zepto>  Zeptosquaremeter;
typedef Quantity<Area,Atto>   Attosquaremeter;
typedef Quantity<Area,Femto>  Femtosquaremeter;
typedef Quantity<Area,Pico>   Picosquaremeter;
typedef Quantity<Area,Nano>   Nanosquaremeter;
typedef Quantity<Area,Micro>  Microsquaremeter;
typedef Quantity<Area,Milli>  Millisquaremeter;
typedef Quantity<Area,Centi>  Centisquaremeter;
typedef Quantity<Area,Deci>   Decisquaremeter;
typedef Quantity<Area>        Squaremeter;
typedef Quantity<Area,Deka>   Dekasquaremeter;
typedef Quantity<Area,Hecto>  Hectosquaremeter;
typedef Quantity<Area,Kilo>   Kilosquaremeter;
typedef Quantity<Area,Mega>   Megasquaremeter;
typedef Quantity<Area,Giga>   Gigasquaremeter;
typedef Quantity<Area,Tera>   Terasquaremeter;
typedef Quantity<Area,Peta>   Petasquaremeter;
typedef Quantity<Area,Exa>    Exasquaremeter;
typedef Quantity<Area,Zetta>  Zeptasquaremeter;
typedef Quantity<Area,Yotta>  Yottasquaremeter;


} //namespace SI


} //namespace Unit

