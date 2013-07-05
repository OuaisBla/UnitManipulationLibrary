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


namespace Unit
{


struct _LuminousIntensity : public Object<>, public Facade<_LuminousIntensity>
{

  enum { NumeratorBaseTypeValue = 17 };
  enum { DenumeratorBaseTypeValue = 1 };

  inline static Types::String Suffix()
  { 
    return Types::String( L"cd" );
  }

};


typedef _LuminousIntensity::SimplifiedType LuminousIntensity;


namespace SI
{


typedef Simple<LuminousIntensity,Yocto>    Yoctocandela;
typedef Simple<LuminousIntensity,Zepto>    Zeptocandela;
typedef Simple<LuminousIntensity,Atto>     Attocandela;
typedef Simple<LuminousIntensity,Femto>    Femtocandela;
typedef Simple<LuminousIntensity,Pico>     Picocandela;
typedef Simple<LuminousIntensity,Nano>     Nanocandela;
typedef Simple<LuminousIntensity,Micro>    Microcandela;
typedef Simple<LuminousIntensity,Milli>    Millicandela;
typedef Simple<LuminousIntensity,Centi>    Centicandela;
typedef Simple<LuminousIntensity,Deci>     Decicandela;
typedef Simple<LuminousIntensity>          Candela;
typedef Simple<LuminousIntensity,Deka>     Dekacandela;
typedef Simple<LuminousIntensity,Hecto>    Hectocandela;
typedef Simple<LuminousIntensity,Kilo>     Kilocandela;
typedef Simple<LuminousIntensity,Mega>     Megacandela;
typedef Simple<LuminousIntensity,Giga>     Gigacandela; 
typedef Simple<LuminousIntensity,Tera>     Teracandela;
typedef Simple<LuminousIntensity,Peta>     Petacandela;
typedef Simple<LuminousIntensity,Exa>      Exacandela;
typedef Simple<LuminousIntensity,Zetta>    Zeptacandela;
typedef Simple<LuminousIntensity,Yotta>    Yottacandela;


} //namespace SI


} //namespace Unit
