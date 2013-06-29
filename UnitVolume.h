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


#include "UnitArea.h"


namespace Unit
{


namespace SI
{


typedef Product<Squaremeter,Meter>::UnitType Volume;


typedef Simple<Volume,Yocto>  Yoctocubicmeter;
typedef Simple<Volume,Zepto>  Zeptocubicmeter;
typedef Simple<Volume,Atto>   Attocubicmeter;
typedef Simple<Volume,Femto>  Femtocubicmeter;
typedef Simple<Volume,Pico>   Picocubicmeter;
typedef Simple<Volume,Nano>   Nanocubicmeter;
typedef Simple<Volume,Micro>  Microcubicmeter;
typedef Simple<Volume,Milli>  Millicubicmeter;
typedef Simple<Volume,Centi>  Centicubicmeter;
typedef Simple<Volume,Deci>   Decicubicmeter;
typedef Simple<Volume>        Cubicmeter;
typedef Simple<Volume,Deka>   Dekacubicmeter;
typedef Simple<Volume,Hecto>  Hectocubicmeter;
typedef Simple<Volume,Kilo>   Kilocubicmeter;
typedef Simple<Volume,Mega>   Megacubicmeter;
typedef Simple<Volume,Giga>   Gigacubicmeter;
typedef Simple<Volume,Tera>   Teracubicmeter;
typedef Simple<Volume,Peta>   Petacubicmeter;
typedef Simple<Volume,Exa>    Exacubicmeter;
typedef Simple<Volume,Zetta>  Zeptacubicmeter;
typedef Simple<Volume,Yotta>  Yottacubicmeter;


} //namespace SI


} //namespace Unit

