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

      inline static String Suffix()
      {
        return String( L"V" );
      }

    };

    typedef Simple<ElectricPotentialDifference,Yocto>    Yoctovolt;
    typedef Simple<ElectricPotentialDifference,Zepto>    Zeptovolt;
    typedef Simple<ElectricPotentialDifference,Atto>     Attovolt;
    typedef Simple<ElectricPotentialDifference,Femto>    Femtovolt;
    typedef Simple<ElectricPotentialDifference,Pico>     Picovolt;
    typedef Simple<ElectricPotentialDifference,Nano>     Nanovolt;
    typedef Simple<ElectricPotentialDifference,Micro>    Microvolt;
    typedef Simple<ElectricPotentialDifference,Milli>    Millivolt;
    typedef Simple<ElectricPotentialDifference,Centi>    Centivolt;
    typedef Simple<ElectricPotentialDifference,Deci>     Decivolt;
    typedef Simple<ElectricPotentialDifference>          Volt;
    typedef Simple<ElectricPotentialDifference,Deka>     Dekavolt;
    typedef Simple<ElectricPotentialDifference,Hecto>    Hectovolt;
    typedef Simple<ElectricPotentialDifference,Kilo>     Kilovolt;
    typedef Simple<ElectricPotentialDifference,Mega>     Megavolt;
    typedef Simple<ElectricPotentialDifference,Giga>     Gigavolt;
    typedef Simple<ElectricPotentialDifference,Tera>     Teravolt;
    typedef Simple<ElectricPotentialDifference,Peta>     Petavolt;
    typedef Simple<ElectricPotentialDifference,Exa>      Exavolt;
    typedef Simple<ElectricPotentialDifference,Zetta>    Zeptavolt;
    typedef Simple<ElectricPotentialDifference,Yotta>    Yottavolt;


  } // namespace SI


} //Namespace Unit
