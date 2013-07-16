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


#include "UnitForce.h"


namespace Unit
{


namespace SI
{


struct Energy : public Product<Newton, Meter>::UnitType
{

  typedef Energy DerivedType;

  inline static Types::String Suffix()
  {
    return Types::String( L"J" );
  }

};


typedef Quantity<Energy,Yocto>  Yoctojoule;
typedef Quantity<Energy,Zepto>  Zeptojoule;
typedef Quantity<Energy,Atto>   Attojoule;
typedef Quantity<Energy,Femto>  Femtojoule;
typedef Quantity<Energy,Pico>   Picojoule;
typedef Quantity<Energy,Nano>   Nanojoule;
typedef Quantity<Energy,Micro>  Microjoule;
typedef Quantity<Energy,Milli>  Millijoule;
typedef Quantity<Energy,Centi>  Centijoule;
typedef Quantity<Energy,Deci>   Decijoule;
typedef Quantity<Energy>        Joule;
typedef Quantity<Energy,Deka>   Dekajoule;
typedef Quantity<Energy,Hecto>  Hectojoule;
typedef Quantity<Energy,Kilo>   Kilojoule;
typedef Quantity<Energy,Mega>   Megajoule;
typedef Quantity<Energy,Giga>   Gigajoule;
typedef Quantity<Energy,Tera>   Terajoule;
typedef Quantity<Energy,Peta>   Petajoule;
typedef Quantity<Energy,Exa>    Exajoule;
typedef Quantity<Energy,Zetta>  Zeptajoule;
typedef Quantity<Energy,Yotta>  Yottajoule;


} //namespace SI


} //namespace Unit
