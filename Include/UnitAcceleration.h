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


#include "UnitVelocity.h"


namespace Unit
{


namespace SI
{


typedef Product<Velocity,Second::Invert>::UnitType _Acceleration;


typedef Simple<_Acceleration,Yocto>  Yoctoacceleration;
typedef Simple<_Acceleration,Zepto>  Zeptoacceleration;
typedef Simple<_Acceleration,Atto>   Attoacceleration;
typedef Simple<_Acceleration,Femto>  Femtoacceleration;
typedef Simple<_Acceleration,Pico>   Picoacceleration;
typedef Simple<_Acceleration,Nano>   Nanoacceleration;
typedef Simple<_Acceleration,Micro>  Microacceleration;
typedef Simple<_Acceleration,Milli>  Milliacceleration;
typedef Simple<_Acceleration,Centi>  Centiacceleration;
typedef Simple<_Acceleration,Deci>   Deciacceleration;
typedef Simple<_Acceleration>        Acceleration;
typedef Simple<_Acceleration,Deka>   Dekaacceleration;
typedef Simple<_Acceleration,Hecto>  Hectoacceleration;
typedef Simple<_Acceleration,Kilo>   Kiloacceleration;
typedef Simple<_Acceleration,Mega>   Megaacceleration;
typedef Simple<_Acceleration,Giga>   Gigaacceleration;
typedef Simple<_Acceleration,Tera>   Teraacceleration;
typedef Simple<_Acceleration,Peta>   Petaacceleration;
typedef Simple<_Acceleration,Exa>    Exaacceleration;
typedef Simple<_Acceleration,Zetta>  Zeptaacceleration;
typedef Simple<_Acceleration,Yotta>  Yottaacceleration;


} //namespace SI


} //namespace Unit
