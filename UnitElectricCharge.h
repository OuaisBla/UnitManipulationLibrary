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
#include "UnitTime.h"


namespace Unit
{

  namespace SI
  {

    struct ElectricCharge : public Product<Ampere,Second>::UnitType
    {

      typedef ElectricCharge DerivedType;

      inline static String Suffix()
      {
        return String( L"C" );
      }

    };


    typedef Simple<ElectricCharge,Yocto>    Yoctocoulomb;
    typedef Simple<ElectricCharge,Zepto>    Zeptocoulomb;
    typedef Simple<ElectricCharge,Atto>     Attocoulomb;
    typedef Simple<ElectricCharge,Femto>    Femtocoulomb;
    typedef Simple<ElectricCharge,Pico>     Picocoulomb;
    typedef Simple<ElectricCharge,Nano>     Nanocoulomb;
    typedef Simple<ElectricCharge,Micro>    Microcoulomb;
    typedef Simple<ElectricCharge,Milli>    Millicoulomb;
    typedef Simple<ElectricCharge,Centi>    Centicoulomb;
    typedef Simple<ElectricCharge,Deci>     Decicoulomb;
    typedef Simple<ElectricCharge>          Coulomb;
    typedef Simple<ElectricCharge,Deka>     Dekacoulomb;
    typedef Simple<ElectricCharge,Hecto>    Hectocoulomb;
    typedef Simple<ElectricCharge,Kilo>     Kilocoulomb;
    typedef Simple<ElectricCharge,Mega>     Megacoulomb;
    typedef Simple<ElectricCharge,Giga>     Gigacoulomb;
    typedef Simple<ElectricCharge,Tera>     Teracoulomb;
    typedef Simple<ElectricCharge,Peta>     Petacoulomb;
    typedef Simple<ElectricCharge,Exa>      Exacoulomb;
    typedef Simple<ElectricCharge,Zetta>    Zeptacoulomb;
    typedef Simple<ElectricCharge,Yotta>    Yottacoulomb;


  } // namespace SI


} //Namespace Unit
