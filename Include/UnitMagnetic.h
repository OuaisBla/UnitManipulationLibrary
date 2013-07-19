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
#include "UnitArea.h"


namespace Unit
{

  namespace SI
  {

    struct MagneticFlux : public Product<Volt,Ampere::Invert>::UnitType
    {
    
      typedef MagneticFlux DerivedType;

      inline static Types::String Suffix()
      {
        return Types::String( L"Wb" );
      }

    };


    typedef Quantity<MagneticFlux,Yocto>    Yoctoweber;
    typedef Quantity<MagneticFlux,Zepto>    Zeptoweber;
    typedef Quantity<MagneticFlux,Atto>     Attoweber;
    typedef Quantity<MagneticFlux,Femto>    Femtoweber;
    typedef Quantity<MagneticFlux,Pico>     Picoweber;
    typedef Quantity<MagneticFlux,Nano>     Nanoweber;
    typedef Quantity<MagneticFlux,Micro>    Microweber;
    typedef Quantity<MagneticFlux,Milli>    Milliweber;
    typedef Quantity<MagneticFlux,Centi>    Centiweber;
    typedef Quantity<MagneticFlux,Deci>     Deciweber;
    typedef Quantity<MagneticFlux>          Weber;
    typedef Quantity<MagneticFlux,Deka>     Dekaweber;
    typedef Quantity<MagneticFlux,Hecto>    Hectoweber;
    typedef Quantity<MagneticFlux,Kilo>     Kiloweber;
    typedef Quantity<MagneticFlux,Mega>     Megaweber;
    typedef Quantity<MagneticFlux,Giga>     Gigaweber;
    typedef Quantity<MagneticFlux,Tera>     Teraweber;
    typedef Quantity<MagneticFlux,Peta>     Petaweber;
    typedef Quantity<MagneticFlux,Exa>      Exaweber;
    typedef Quantity<MagneticFlux,Zetta>    Zeptaweber;
    typedef Quantity<MagneticFlux,Yotta>    Yottaweber;


    struct MagneticFluxDensity : public Product<Weber,Squaremeter::Invert>::UnitType
    {

      typedef MagneticFluxDensity DerivedType;

      inline static Types::String Suffix()
      {
        return Types::String( L"T" );
      }

    };


    typedef Quantity<MagneticFluxDensity,Yocto>    Yoctotesla;
    typedef Quantity<MagneticFluxDensity,Zepto>    Zeptotesla;
    typedef Quantity<MagneticFluxDensity,Atto>     Attotesla;
    typedef Quantity<MagneticFluxDensity,Femto>    Femtotesla;
    typedef Quantity<MagneticFluxDensity,Pico>     Picotesla;
    typedef Quantity<MagneticFluxDensity,Nano>     Nanotesla;
    typedef Quantity<MagneticFluxDensity,Micro>    Microtesla;
    typedef Quantity<MagneticFluxDensity,Milli>    Millitesla;
    typedef Quantity<MagneticFluxDensity,Centi>    Centitesla;
    typedef Quantity<MagneticFluxDensity,Deci>     Decitesla;
    typedef Quantity<MagneticFluxDensity>          Tesla;
    typedef Quantity<MagneticFluxDensity,Deka>     Dekatesla;
    typedef Quantity<MagneticFluxDensity,Hecto>    Hectotesla;
    typedef Quantity<MagneticFluxDensity,Kilo>     Kilotesla;
    typedef Quantity<MagneticFluxDensity,Mega>     Megatesla;
    typedef Quantity<MagneticFluxDensity,Giga>     Gigatesla;
    typedef Quantity<MagneticFluxDensity,Tera>     Teratesla;
    typedef Quantity<MagneticFluxDensity,Peta>     Petatesla;
    typedef Quantity<MagneticFluxDensity,Exa>      Exatesla;
    typedef Quantity<MagneticFluxDensity,Zetta>    Zeptatesla;
    typedef Quantity<MagneticFluxDensity,Yotta>    Yottatesla;


    struct Inductance : public Product<Weber,Ampere::Invert>::UnitType
    {

      typedef Inductance DerivedType;

      inline static Types::String Suffix()
      {
        return Types::String( L"H" );
      }

    };
    

    typedef Quantity<Inductance,Yocto>    Yoctohenry;
    typedef Quantity<Inductance,Zepto>    Zeptohenry;
    typedef Quantity<Inductance,Atto>     Attohenry;
    typedef Quantity<Inductance,Femto>    Femtohenry;
    typedef Quantity<Inductance,Pico>     Picohenry;
    typedef Quantity<Inductance,Nano>     Nanohenry;
    typedef Quantity<Inductance,Micro>    Microhenry;
    typedef Quantity<Inductance,Milli>    Millihenry;
    typedef Quantity<Inductance,Centi>    Centihenry;
    typedef Quantity<Inductance,Deci>     Decihenry;
    typedef Quantity<Inductance>          Henry;
    typedef Quantity<Inductance,Deka>     Dekahenry;
    typedef Quantity<Inductance,Hecto>    Hectohenry;
    typedef Quantity<Inductance,Kilo>     Kilohenry;
    typedef Quantity<Inductance,Mega>     Megahenry;
    typedef Quantity<Inductance,Giga>     Gigahenry;
    typedef Quantity<Inductance,Tera>     Terahenry;
    typedef Quantity<Inductance,Peta>     Petahenry;
    typedef Quantity<Inductance,Exa>      Exahenry;
    typedef Quantity<Inductance,Zetta>    Zeptahenry;
    typedef Quantity<Inductance,Yotta>    Yottahenry;


  } // namespace SI


} //Namespace Unit
