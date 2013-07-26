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


#include "Unit.h"
#include "UnitArea.h"
#include "UnitAngular.h"


namespace Unit
{


struct _LuminousIntensity : public Object<>, public Facade<_LuminousIntensity>
{

  enum { NumeratorBaseTypeValue = 17 };

  inline static Types::String Suffix()
  { 
    return Types::String( L"cd" );
  }

};


typedef _LuminousIntensity::SimplifiedType LuminousIntensity;


namespace SI
{


  typedef Quantity<LuminousIntensity,Yocto>    Yoctocandela;
  typedef Quantity<LuminousIntensity,Zepto>    Zeptocandela;
  typedef Quantity<LuminousIntensity,Atto>     Attocandela;
  typedef Quantity<LuminousIntensity,Femto>    Femtocandela;
  typedef Quantity<LuminousIntensity,Pico>     Picocandela;
  typedef Quantity<LuminousIntensity,Nano>     Nanocandela;
  typedef Quantity<LuminousIntensity,Micro>    Microcandela;
  typedef Quantity<LuminousIntensity,Milli>    Millicandela;
  typedef Quantity<LuminousIntensity,Centi>    Centicandela;
  typedef Quantity<LuminousIntensity,Deci>     Decicandela;
  typedef Quantity<LuminousIntensity>          Candela;
  typedef Quantity<LuminousIntensity,Deka>     Dekacandela;
  typedef Quantity<LuminousIntensity,Hecto>    Hectocandela;
  typedef Quantity<LuminousIntensity,Kilo>     Kilocandela;
  typedef Quantity<LuminousIntensity,Mega>     Megacandela;
  typedef Quantity<LuminousIntensity,Giga>     Gigacandela; 
  typedef Quantity<LuminousIntensity,Tera>     Teracandela;
  typedef Quantity<LuminousIntensity,Peta>     Petacandela;
  typedef Quantity<LuminousIntensity,Exa>      Exacandela;
  typedef Quantity<LuminousIntensity,Zetta>    Zeptacandela;
  typedef Quantity<LuminousIntensity,Yotta>    Yottacandela;


  struct LuminousFlux : public Product<Candela,Steradian>::UnitType
  {

    typedef LuminousFlux DerivedType;

    inline static Types::String Suffix()
    {
      return Types::String( L"lm" );
    }

  };


  typedef Quantity<LuminousFlux>  Lumen;


  struct Illuminance : public Product<Lumen,Squaremeter::Invert>::UnitType
  {

    typedef Illuminance DerivedType;

    inline static Types::String Suffix()
    {
      return Types::String( L"lx" );
    }

  };

  typedef Quantity<Illuminance>  Lux;

} //namespace SI

} //namespace Unit
