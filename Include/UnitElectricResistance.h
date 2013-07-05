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


    typedef Simple<ElectricResistance,Yocto>    Yoctoohm;
    typedef Simple<ElectricResistance,Zepto>    Zeptoohm;
    typedef Simple<ElectricResistance,Atto>     Attoohm;
    typedef Simple<ElectricResistance,Femto>    Femtoohm;
    typedef Simple<ElectricResistance,Pico>     Picoohm;
    typedef Simple<ElectricResistance,Nano>     Nanoohm;
    typedef Simple<ElectricResistance,Micro>    Microohm;
    typedef Simple<ElectricResistance,Milli>    Milliohm;
    typedef Simple<ElectricResistance,Centi>    Centiohm;
    typedef Simple<ElectricResistance,Deci>     Deciohm;
    typedef Simple<ElectricResistance>          Ohm;
    typedef Simple<ElectricResistance,Deka>     Dekaohm;
    typedef Simple<ElectricResistance,Hecto>    Hectoohm;
    typedef Simple<ElectricResistance,Kilo>     Kiloohm;
    typedef Simple<ElectricResistance,Mega>     Megaohm;
    typedef Simple<ElectricResistance,Giga>     Gigaohm;
    typedef Simple<ElectricResistance,Tera>     Teraohm;
    typedef Simple<ElectricResistance,Peta>     Petaohm;
    typedef Simple<ElectricResistance,Exa>      Exaohm;
    typedef Simple<ElectricResistance,Zetta>    Zeptaohm;
    typedef Simple<ElectricResistance,Yotta>    Yottaohm;


  } // namespace SI


} //Namespace Unit
