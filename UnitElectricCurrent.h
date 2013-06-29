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


struct _ElectricCurrent : public Object<>
{

  typedef _ElectricCurrent BaseType;
  typedef BaseUnit<BaseType> SimplifiedType;

  enum { NumeratorBaseTypeValue = 11 };
  enum { DenumeratorBaseTypeValue = 1 };

  inline static String Suffix()
  { 
    return String( L"A" );
  }

};


typedef _ElectricCurrent::SimplifiedType ElectricCurrent;


namespace SI
{


typedef Simple<ElectricCurrent,Yocto>    Yoctoampere;
typedef Simple<ElectricCurrent,Zepto>    Zeptoampere;
typedef Simple<ElectricCurrent,Atto>     Attoampere;
typedef Simple<ElectricCurrent,Femto>    Femtoampere;
typedef Simple<ElectricCurrent,Pico>     Picoampere;
typedef Simple<ElectricCurrent,Nano>     Nanoampere;
typedef Simple<ElectricCurrent,Micro>    Microampere;
typedef Simple<ElectricCurrent,Milli>    Milliampere;
typedef Simple<ElectricCurrent,Centi>    Centiampere;
typedef Simple<ElectricCurrent,Deci>     Deciampere;
typedef Simple<ElectricCurrent>          Ampere;
typedef Simple<ElectricCurrent,Deka>     Dekaampere;
typedef Simple<ElectricCurrent,Hecto>    Hectoampere;
typedef Simple<ElectricCurrent,Kilo>     Kiloampere;
typedef Simple<ElectricCurrent,Mega>     Megaampere;
typedef Simple<ElectricCurrent,Giga>     Gigaampere;
typedef Simple<ElectricCurrent,Tera>     Teraampere;
typedef Simple<ElectricCurrent,Peta>     Petaampere;
typedef Simple<ElectricCurrent,Exa>      Exaampere;
typedef Simple<ElectricCurrent,Zetta>    Zeptaampere;
typedef Simple<ElectricCurrent,Yotta>    Yottaampere;


} // namespace SI


} //Namespace Unit
