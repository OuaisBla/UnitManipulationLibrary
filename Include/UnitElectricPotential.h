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


#include "UnitElectricCurrent.h"
#include "UnitPower.h"


namespace Unit
{

  namespace SI
  {


    struct ElectricPotentialDifference : public Product<Watt,Ampere::Invert>::UnitType
    {
    
      typedef ElectricPotentialDifference DerivedType;

      inline static Types::String Suffix()
      {
        return Types::String( L"V" );
      }

    };

    typedef Quantity<ElectricPotentialDifference,Yocto>    Yoctovolt;
    typedef Quantity<ElectricPotentialDifference,Zepto>    Zeptovolt;
    typedef Quantity<ElectricPotentialDifference,Atto>     Attovolt;
    typedef Quantity<ElectricPotentialDifference,Femto>    Femtovolt;
    typedef Quantity<ElectricPotentialDifference,Pico>     Picovolt;
    typedef Quantity<ElectricPotentialDifference,Nano>     Nanovolt;
    typedef Quantity<ElectricPotentialDifference,Micro>    Microvolt;
    typedef Quantity<ElectricPotentialDifference,Milli>    Millivolt;
    typedef Quantity<ElectricPotentialDifference,Centi>    Centivolt;
    typedef Quantity<ElectricPotentialDifference,Deci>     Decivolt;
    typedef Quantity<ElectricPotentialDifference>          Volt;
    typedef Quantity<ElectricPotentialDifference,Deka>     Dekavolt;
    typedef Quantity<ElectricPotentialDifference,Hecto>    Hectovolt;
    typedef Quantity<ElectricPotentialDifference,Kilo>     Kilovolt;
    typedef Quantity<ElectricPotentialDifference,Mega>     Megavolt;
    typedef Quantity<ElectricPotentialDifference,Giga>     Gigavolt;
    typedef Quantity<ElectricPotentialDifference,Tera>     Teravolt;
    typedef Quantity<ElectricPotentialDifference,Peta>     Petavolt;
    typedef Quantity<ElectricPotentialDifference,Exa>      Exavolt;
    typedef Quantity<ElectricPotentialDifference,Zetta>    Zeptavolt;
    typedef Quantity<ElectricPotentialDifference,Yotta>    Yottavolt;


  } // namespace SI


} //Namespace Unit
