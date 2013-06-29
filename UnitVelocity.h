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


typedef Simple<_Velocity,Yocto>  Yoctovelocity;
typedef Simple<_Velocity,Zepto>  Zeptovelocity;
typedef Simple<_Velocity,Atto>   Attovelocity;
typedef Simple<_Velocity,Femto>  Femtovelocity;
typedef Simple<_Velocity,Pico>   Picovelocity;
typedef Simple<_Velocity,Nano>   Nanovelocity;
typedef Simple<_Velocity,Micro>  Microvelocity;
typedef Simple<_Velocity,Milli>  Millivelocity;
typedef Simple<_Velocity,Centi>  Centivelocity;
typedef Simple<_Velocity,Deci>   Decivelocity;
typedef Simple<_Velocity>        Velocity;
typedef Simple<_Velocity,Deka>   Dekavelocity;
typedef Simple<_Velocity,Hecto>  Hectovelocity;
typedef Simple<_Velocity,Kilo>   Kilovelocity;
typedef Simple<_Velocity,Mega>   Megavelocity;
typedef Simple<_Velocity,Giga>   Gigavelocity;
typedef Simple<_Velocity,Tera>   Teravelocity;
typedef Simple<_Velocity,Peta>   Petavelocity;
typedef Simple<_Velocity,Exa>    Exavelocity;
typedef Simple<_Velocity,Zetta>  Zeptavelocity;
typedef Simple<_Velocity,Yotta>  Yottavelocity;


} //namespace SI


} //namespace Unit

