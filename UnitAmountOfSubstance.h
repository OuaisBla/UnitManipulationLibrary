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


#include "Unit.h"


namespace Unit
{


struct _AmountOfSubstance : public Object<>, public Facade<_AmountOfSubstance>
{

  enum { NumeratorBaseTypeValue = 13 };
  enum { DenumeratorBaseTypeValue = 1 };

  inline static String Suffix()
  { 
    return String( L"mol" );
  }

};


typedef _AmountOfSubstance::SimplifiedType AmountOfSubstance;


namespace SI
{


typedef Simple<AmountOfSubstance,Yocto>    Yoctomole;
typedef Simple<AmountOfSubstance,Zepto>    Zeptomole;
typedef Simple<AmountOfSubstance,Atto>     Attomole;
typedef Simple<AmountOfSubstance,Femto>    Femtomole;
typedef Simple<AmountOfSubstance,Pico>     Picomole;
typedef Simple<AmountOfSubstance,Nano>     Nanomole;
typedef Simple<AmountOfSubstance,Micro>    Micromole;
typedef Simple<AmountOfSubstance,Milli>    Millimole;
typedef Simple<AmountOfSubstance,Centi>    Centimole;
typedef Simple<AmountOfSubstance,Deci>     Decimole;
typedef Simple<AmountOfSubstance>          Mole;
typedef Simple<AmountOfSubstance,Deka>     Dekamole;
typedef Simple<AmountOfSubstance,Hecto>    Hectomole;
typedef Simple<AmountOfSubstance,Kilo>     Kilomole;
typedef Simple<AmountOfSubstance,Mega>     Megamole;
typedef Simple<AmountOfSubstance,Giga>     Gigamole; 
typedef Simple<AmountOfSubstance,Tera>     Teramole;
typedef Simple<AmountOfSubstance,Peta>     Petamole;
typedef Simple<AmountOfSubstance,Exa>      Examole;
typedef Simple<AmountOfSubstance,Zetta>    Zeptamole;
typedef Simple<AmountOfSubstance,Yotta>    Yottamole;


} //namespace SI


} //namespace Unit
