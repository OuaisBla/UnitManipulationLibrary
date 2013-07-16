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

      inline static Types::String Suffix()
      {
        return Types::String( L"C" );
      }

    };


    typedef Quantity<ElectricCharge,Yocto>    Yoctocoulomb;
    typedef Quantity<ElectricCharge,Zepto>    Zeptocoulomb;
    typedef Quantity<ElectricCharge,Atto>     Attocoulomb;
    typedef Quantity<ElectricCharge,Femto>    Femtocoulomb;
    typedef Quantity<ElectricCharge,Pico>     Picocoulomb;
    typedef Quantity<ElectricCharge,Nano>     Nanocoulomb;
    typedef Quantity<ElectricCharge,Micro>    Microcoulomb;
    typedef Quantity<ElectricCharge,Milli>    Millicoulomb;
    typedef Quantity<ElectricCharge,Centi>    Centicoulomb;
    typedef Quantity<ElectricCharge,Deci>     Decicoulomb;
    typedef Quantity<ElectricCharge>          Coulomb;
    typedef Quantity<ElectricCharge,Deka>     Dekacoulomb;
    typedef Quantity<ElectricCharge,Hecto>    Hectocoulomb;
    typedef Quantity<ElectricCharge,Kilo>     Kilocoulomb;
    typedef Quantity<ElectricCharge,Mega>     Megacoulomb;
    typedef Quantity<ElectricCharge,Giga>     Gigacoulomb;
    typedef Quantity<ElectricCharge,Tera>     Teracoulomb;
    typedef Quantity<ElectricCharge,Peta>     Petacoulomb;
    typedef Quantity<ElectricCharge,Exa>      Exacoulomb;
    typedef Quantity<ElectricCharge,Zetta>    Zeptacoulomb;
    typedef Quantity<ElectricCharge,Yotta>    Yottacoulomb;


  } // namespace SI


} //Namespace Unit
