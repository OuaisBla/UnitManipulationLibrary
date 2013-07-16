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


typedef Quantity<_Acceleration,Yocto>  Yoctoacceleration;
typedef Quantity<_Acceleration,Zepto>  Zeptoacceleration;
typedef Quantity<_Acceleration,Atto>   Attoacceleration;
typedef Quantity<_Acceleration,Femto>  Femtoacceleration;
typedef Quantity<_Acceleration,Pico>   Picoacceleration;
typedef Quantity<_Acceleration,Nano>   Nanoacceleration;
typedef Quantity<_Acceleration,Micro>  Microacceleration;
typedef Quantity<_Acceleration,Milli>  Milliacceleration;
typedef Quantity<_Acceleration,Centi>  Centiacceleration;
typedef Quantity<_Acceleration,Deci>   Deciacceleration;
typedef Quantity<_Acceleration>        Acceleration;
typedef Quantity<_Acceleration,Deka>   Dekaacceleration;
typedef Quantity<_Acceleration,Hecto>  Hectoacceleration;
typedef Quantity<_Acceleration,Kilo>   Kiloacceleration;
typedef Quantity<_Acceleration,Mega>   Megaacceleration;
typedef Quantity<_Acceleration,Giga>   Gigaacceleration;
typedef Quantity<_Acceleration,Tera>   Teraacceleration;
typedef Quantity<_Acceleration,Peta>   Petaacceleration;
typedef Quantity<_Acceleration,Exa>    Exaacceleration;
typedef Quantity<_Acceleration,Zetta>  Zeptaacceleration;
typedef Quantity<_Acceleration,Yotta>  Yottaacceleration;


} //namespace SI


} //namespace Unit
