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


#include "UnitElectricCharge.h"
#include "UnitElectricPotential.h"


namespace Unit
{

  namespace SI
  {

    struct Capacitance : public Product<Coulomb,Volt::Invert>::UnitType
    {

      typedef Capacitance DerivedType;

      inline static Types::String Suffix()
      {
        return Types::String( L"F" );
      }

    };


    typedef Quantity<Capacitance,Yocto>    Yoctofarad;
    typedef Quantity<Capacitance,Zepto>    Zeptofarad;
    typedef Quantity<Capacitance,Atto>     Attofarad;
    typedef Quantity<Capacitance,Femto>    Femtofarad;
    typedef Quantity<Capacitance,Pico>     Picofarad;
    typedef Quantity<Capacitance,Nano>     Nanofarad;
    typedef Quantity<Capacitance,Micro>    Microfarad;
    typedef Quantity<Capacitance,Milli>    Millifarad;
    typedef Quantity<Capacitance,Centi>    Centifarad;
    typedef Quantity<Capacitance,Deci>     Decifarad;
    typedef Quantity<Capacitance>          Farad;
    typedef Quantity<Capacitance,Deka>     Dekafarad;
    typedef Quantity<Capacitance,Hecto>    Hectofarad;
    typedef Quantity<Capacitance,Kilo>     Kilofarad;
    typedef Quantity<Capacitance,Mega>     Megafarad;
    typedef Quantity<Capacitance,Giga>     Gigafarad;
    typedef Quantity<Capacitance,Tera>     Terafarad;
    typedef Quantity<Capacitance,Peta>     Petafarad;
    typedef Quantity<Capacitance,Exa>      Exafarad;
    typedef Quantity<Capacitance,Zetta>    Zeptafarad;
    typedef Quantity<Capacitance,Yotta>    Yottafarad;


  } // namespace SI


} //Namespace Unit
