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


struct Force : public Product<Kilogram,Acceleration>::UnitType
{

  typedef Force DerivedType;

  inline static Types::String Suffix()
  {
    return Types::String( L"N" );
  }

};


typedef Quantity<Force,Yocto>  Yoctonewton;
typedef Quantity<Force,Zepto>  Zeptonewton;
typedef Quantity<Force,Atto>   Attonewton;
typedef Quantity<Force,Femto>  Femtonewton;
typedef Quantity<Force,Pico>   Piconewton;
typedef Quantity<Force,Nano>   Nanonewton;
typedef Quantity<Force,Micro>  Micronewton;
typedef Quantity<Force,Milli>  Millinewton;
typedef Quantity<Force,Centi>  Centinewton;
typedef Quantity<Force,Deci>   Decinewton;
typedef Quantity<Force>        Newton;
typedef Quantity<Force,Deka>   Dekanewton;
typedef Quantity<Force,Hecto>  Hectonewton;
typedef Quantity<Force,Kilo>   Kilonewton;
typedef Quantity<Force,Mega>   Meganewton;
typedef Quantity<Force,Giga>   Giganewton;
typedef Quantity<Force,Tera>   Teranewton;
typedef Quantity<Force,Peta>   Petanewton;
typedef Quantity<Force,Exa>    Exanewton;
typedef Quantity<Force,Zetta>  Zeptanewton;
typedef Quantity<Force,Yotta>  Yottanewton;


} //namespace SI


} //namespace Unit

