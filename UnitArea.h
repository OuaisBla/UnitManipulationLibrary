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


typedef Simple<Area,Yocto>  Yoctosquaremeter;
typedef Simple<Area,Zepto>  Zeptosquaremeter;
typedef Simple<Area,Atto>   Attosquaremeter;
typedef Simple<Area,Femto>  Femtosquaremeter;
typedef Simple<Area,Pico>   Picosquaremeter;
typedef Simple<Area,Nano>   Nanosquaremeter;
typedef Simple<Area,Micro>  Microsquaremeter;
typedef Simple<Area,Milli>  Millisquaremeter;
typedef Simple<Area,Centi>  Centisquaremeter;
typedef Simple<Area,Deci>   Decisquaremeter;
typedef Simple<Area>        Squaremeter;
typedef Simple<Area,Deka>   Dekasquaremeter;
typedef Simple<Area,Hecto>  Hectosquaremeter;
typedef Simple<Area,Kilo>   Kilosquaremeter;
typedef Simple<Area,Mega>   Megasquaremeter;
typedef Simple<Area,Giga>   Gigasquaremeter;
typedef Simple<Area,Tera>   Terasquaremeter;
typedef Simple<Area,Peta>   Petasquaremeter;
typedef Simple<Area,Exa>    Exasquaremeter;
typedef Simple<Area,Zetta>  Zeptasquaremeter;
typedef Simple<Area,Yotta>  Yottasquaremeter;


} //namespace SI


} //namespace Unit

