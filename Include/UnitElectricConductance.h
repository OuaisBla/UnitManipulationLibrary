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

    struct Conductance : public Product<Ampere,Volt>::UnitType
    {

      typedef Conductance DerivedType;

      inline static Types::String Suffix()
      {
        return Types::String( L"S" );
      }

    };


    typedef Quantity<Conductance,Yocto>    Yoctosiemens;
    typedef Quantity<Conductance,Zepto>    Zeptosiemens;
    typedef Quantity<Conductance,Atto>     Attosiemens;
    typedef Quantity<Conductance,Femto>    Femtosiemens;
    typedef Quantity<Conductance,Pico>     Picosiemens;
    typedef Quantity<Conductance,Nano>     Nanosiemens;
    typedef Quantity<Conductance,Micro>    Microsiemens;
    typedef Quantity<Conductance,Milli>    Millisiemens;
    typedef Quantity<Conductance,Centi>    Centisiemens;
    typedef Quantity<Conductance,Deci>     Decisiemens;
    typedef Quantity<Conductance>          Siemens;
    typedef Quantity<Conductance,Deka>     Dekasiemens;
    typedef Quantity<Conductance,Hecto>    Hectosiemens;
    typedef Quantity<Conductance,Kilo>     Kilosiemens;
    typedef Quantity<Conductance,Mega>     Megasiemens;
    typedef Quantity<Conductance,Giga>     Gigasiemens;
    typedef Quantity<Conductance,Tera>     Terasiemens;
    typedef Quantity<Conductance,Peta>     Petasiemens;
    typedef Quantity<Conductance,Exa>      Exasiemens;
    typedef Quantity<Conductance,Zetta>    Zeptasiemens;
    typedef Quantity<Conductance,Yotta>    Yottasiemens;


  } // namespace SI


} //Namespace Unit
