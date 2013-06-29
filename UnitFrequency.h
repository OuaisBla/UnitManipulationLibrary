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


#include "UnitTime.h"


namespace Unit
{


namespace SI
{


typedef Second::Invert::UnitType  Frequency;


typedef Simple<Frequency,Yocto>   Yoctohertz;
typedef Simple<Frequency,Zepto>   Zeptohertz;
typedef Simple<Frequency,Atto>    Attohertz;
typedef Simple<Frequency,Femto>   Femtohertz;
typedef Simple<Frequency,Pico>    Picohertz;
typedef Simple<Frequency,Nano>    Nanohertz;
typedef Simple<Frequency,Micro>   Microhertz;
typedef Simple<Frequency,Milli>   Millihertz;
typedef Simple<Frequency,Centi>   Centihertz;
typedef Simple<Frequency,Deci>    Decihertz;
typedef Simple<Frequency>         Hertz;
typedef Simple<Frequency,Deka>    Dekahertz;
typedef Simple<Frequency,Hecto>   Hectohertz;
typedef Simple<Frequency,Kilo>    Kilohertz;
typedef Simple<Frequency,Mega>    Megahertz;
typedef Simple<Frequency,Giga>    Gigahertz;
typedef Simple<Frequency,Tera>    Terahertz;
typedef Simple<Frequency,Peta>    Petahertz;
typedef Simple<Frequency,Exa>     Exahertz;
typedef Simple<Frequency,Zetta>   Zettahertz;
typedef Simple<Frequency,Yotta>   Yottahertz;


} //namespace SI


} //namespace Unit

