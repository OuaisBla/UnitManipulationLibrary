/*
Unit Manipulation Library.
Copyright (C) 2013  Jean Gauthier

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


#include "UnitElectricPotential.h"


namespace Unit
{

  namespace SI
  {

    struct ElectricResistance : public Product<Volt,Ampere::Invert>::UnitType
    {
    
      typedef ElectricResistance DerivedType;

      inline static Types::String Suffix()
      {
        return Types::String( L"\x2126" );
      }

    };


    typedef Quantity<ElectricResistance,Yocto>    Yoctoohm;
    typedef Quantity<ElectricResistance,Zepto>    Zeptoohm;
    typedef Quantity<ElectricResistance,Atto>     Attoohm;
    typedef Quantity<ElectricResistance,Femto>    Femtoohm;
    typedef Quantity<ElectricResistance,Pico>     Picoohm;
    typedef Quantity<ElectricResistance,Nano>     Nanoohm;
    typedef Quantity<ElectricResistance,Micro>    Microohm;
    typedef Quantity<ElectricResistance,Milli>    Milliohm;
    typedef Quantity<ElectricResistance,Centi>    Centiohm;
    typedef Quantity<ElectricResistance,Deci>     Deciohm;
    typedef Quantity<ElectricResistance>          Ohm;
    typedef Quantity<ElectricResistance,Deka>     Dekaohm;
    typedef Quantity<ElectricResistance,Hecto>    Hectoohm;
    typedef Quantity<ElectricResistance,Kilo>     Kiloohm;
    typedef Quantity<ElectricResistance,Mega>     Megaohm;
    typedef Quantity<ElectricResistance,Giga>     Gigaohm;
    typedef Quantity<ElectricResistance,Tera>     Teraohm;
    typedef Quantity<ElectricResistance,Peta>     Petaohm;
    typedef Quantity<ElectricResistance,Exa>      Exaohm;
    typedef Quantity<ElectricResistance,Zetta>    Zeptaohm;
    typedef Quantity<ElectricResistance,Yotta>    Yottaohm;


  } // namespace SI


} //Namespace Unit
