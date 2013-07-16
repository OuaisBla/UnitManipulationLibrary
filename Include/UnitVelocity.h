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
#include "UnitTime.h"


namespace Unit
{


namespace SI
{


typedef Product<Meter,Second::Invert>::UnitType _Velocity;


typedef Quantity<_Velocity,Yocto>  Yoctovelocity;
typedef Quantity<_Velocity,Zepto>  Zeptovelocity;
typedef Quantity<_Velocity,Atto>   Attovelocity;
typedef Quantity<_Velocity,Femto>  Femtovelocity;
typedef Quantity<_Velocity,Pico>   Picovelocity;
typedef Quantity<_Velocity,Nano>   Nanovelocity;
typedef Quantity<_Velocity,Micro>  Microvelocity;
typedef Quantity<_Velocity,Milli>  Millivelocity;
typedef Quantity<_Velocity,Centi>  Centivelocity;
typedef Quantity<_Velocity,Deci>   Decivelocity;
typedef Quantity<_Velocity>        Velocity;
typedef Quantity<_Velocity,Deka>   Dekavelocity;
typedef Quantity<_Velocity,Hecto>  Hectovelocity;
typedef Quantity<_Velocity,Kilo>   Kilovelocity;
typedef Quantity<_Velocity,Mega>   Megavelocity;
typedef Quantity<_Velocity,Giga>   Gigavelocity;
typedef Quantity<_Velocity,Tera>   Teravelocity;
typedef Quantity<_Velocity,Peta>   Petavelocity;
typedef Quantity<_Velocity,Exa>    Exavelocity;
typedef Quantity<_Velocity,Zetta>  Zeptavelocity;
typedef Quantity<_Velocity,Yotta>  Yottavelocity;


} //namespace SI


} //namespace Unit

