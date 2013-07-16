/*
Unit Manipulation Library.
Copyright (C) 2002  Jean Gauthier

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


#include "UnitTime.h"


namespace Unit
{


namespace SI
{


  struct Frequency : public Second::Invert::UnitType
  {

    typedef Frequency DerivedType;

    inline static Types::String Suffix()
    {
      return Types::String( L"Hz" );
    }

  };


  typedef Quantity<Frequency,Yocto>   Yoctohertz;
  typedef Quantity<Frequency,Zepto>   Zeptohertz;
  typedef Quantity<Frequency,Atto>    Attohertz;
  typedef Quantity<Frequency,Femto>   Femtohertz;
  typedef Quantity<Frequency,Pico>    Picohertz;
  typedef Quantity<Frequency,Nano>    Nanohertz;
  typedef Quantity<Frequency,Micro>   Microhertz;
  typedef Quantity<Frequency,Milli>   Millihertz;
  typedef Quantity<Frequency,Centi>   Centihertz;
  typedef Quantity<Frequency,Deci>    Decihertz;
  typedef Quantity<Frequency>         Hertz;
  typedef Quantity<Frequency,Deka>    Dekahertz;
  typedef Quantity<Frequency,Hecto>   Hectohertz;
  typedef Quantity<Frequency,Kilo>    Kilohertz;
  typedef Quantity<Frequency,Mega>    Megahertz;
  typedef Quantity<Frequency,Giga>    Gigahertz;
  typedef Quantity<Frequency,Tera>    Terahertz;
  typedef Quantity<Frequency,Peta>    Petahertz;
  typedef Quantity<Frequency,Exa>     Exahertz;
  typedef Quantity<Frequency,Zetta>   Zettahertz;
  typedef Quantity<Frequency,Yotta>   Yottahertz;


} //namespace SI


} //namespace Unit

