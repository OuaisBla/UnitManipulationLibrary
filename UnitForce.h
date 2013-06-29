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


#include "UnitAcceleration.h"
#include "UnitMass.h"


namespace Unit
{


namespace SI
{


class Force : public Product<Kilogram,Acceleration>::UnitType
{
public:

  inline static String Suffix()
  {
    return String( L"N" );
  }

};


typedef Simple<Force,Yocto>  Yoctonewton;
typedef Simple<Force,Zepto>  Zeptonewton;
typedef Simple<Force,Atto>   Attonewton;
typedef Simple<Force,Femto>  Femtonewton;
typedef Simple<Force,Pico>   Piconewton;
typedef Simple<Force,Nano>   Nanonewton;
typedef Simple<Force,Micro>  Micronewton;
typedef Simple<Force,Milli>  Millinewton;
typedef Simple<Force,Centi>  Centinewton;
typedef Simple<Force,Deci>   Decinewton;
typedef Simple<Force>        Newton;
typedef Simple<Force,Deka>   Dekanewton;
typedef Simple<Force,Hecto>  Hectonewton;
typedef Simple<Force,Kilo>   Kilonewton;
typedef Simple<Force,Mega>   Meganewton;
typedef Simple<Force,Giga>   Giganewton;
typedef Simple<Force,Tera>   Teranewton;
typedef Simple<Force,Peta>   Petanewton;
typedef Simple<Force,Exa>    Exanewton;
typedef Simple<Force,Zetta>  Zeptanewton;
typedef Simple<Force,Yotta>  Yottanewton;


} //namespace SI


} //namespace Unit

