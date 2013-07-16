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


#include "Unit.h"


namespace Unit
{


struct _ElectricCurrent : public Object<>, public Facade<_ElectricCurrent>
{

  enum { NumeratorBaseTypeValue = 7 };
  enum { DenumeratorBaseTypeValue = 1 };

  inline static Types::String Suffix()
  { 
    return Types::String( L"A" );
  }

};


typedef _ElectricCurrent::SimplifiedType ElectricCurrent;


namespace SI
{


typedef Quantity<ElectricCurrent,Yocto>    Yoctoampere;
typedef Quantity<ElectricCurrent,Zepto>    Zeptoampere;
typedef Quantity<ElectricCurrent,Atto>     Attoampere;
typedef Quantity<ElectricCurrent,Femto>    Femtoampere;
typedef Quantity<ElectricCurrent,Pico>     Picoampere;
typedef Quantity<ElectricCurrent,Nano>     Nanoampere;
typedef Quantity<ElectricCurrent,Micro>    Microampere;
typedef Quantity<ElectricCurrent,Milli>    Milliampere;
typedef Quantity<ElectricCurrent,Centi>    Centiampere;
typedef Quantity<ElectricCurrent,Deci>     Deciampere;
typedef Quantity<ElectricCurrent>          Ampere;
typedef Quantity<ElectricCurrent,Deka>     Dekaampere;
typedef Quantity<ElectricCurrent,Hecto>    Hectoampere;
typedef Quantity<ElectricCurrent,Kilo>     Kiloampere;
typedef Quantity<ElectricCurrent,Mega>     Megaampere;
typedef Quantity<ElectricCurrent,Giga>     Gigaampere;
typedef Quantity<ElectricCurrent,Tera>     Teraampere;
typedef Quantity<ElectricCurrent,Peta>     Petaampere;
typedef Quantity<ElectricCurrent,Exa>      Exaampere;
typedef Quantity<ElectricCurrent,Zetta>    Zeptaampere;
typedef Quantity<ElectricCurrent,Yotta>    Yottaampere;


} // namespace SI


} //Namespace Unit
