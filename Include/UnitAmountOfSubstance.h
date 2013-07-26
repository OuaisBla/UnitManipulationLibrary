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
#include "UnitTime.h"


namespace Unit
{


struct _AmountOfSubstance : public Object<>, public Facade<_AmountOfSubstance>
{

  enum { NumeratorBaseTypeValue = 13 };

  inline static Types::String Suffix()
  { 
    return Types::String( L"mol" );
  }

};


typedef _AmountOfSubstance::SimplifiedType AmountOfSubstance;


namespace SI
{


  typedef Quantity<AmountOfSubstance,Yocto>    Yoctomole;
  typedef Quantity<AmountOfSubstance,Zepto>    Zeptomole;
  typedef Quantity<AmountOfSubstance,Atto>     Attomole;
  typedef Quantity<AmountOfSubstance,Femto>    Femtomole;
  typedef Quantity<AmountOfSubstance,Pico>     Picomole;
  typedef Quantity<AmountOfSubstance,Nano>     Nanomole;
  typedef Quantity<AmountOfSubstance,Micro>    Micromole;
  typedef Quantity<AmountOfSubstance,Milli>    Millimole;
  typedef Quantity<AmountOfSubstance,Centi>    Centimole;
  typedef Quantity<AmountOfSubstance,Deci>     Decimole;
  typedef Quantity<AmountOfSubstance>          Mole;
  typedef Quantity<AmountOfSubstance,Deka>     Dekamole;
  typedef Quantity<AmountOfSubstance,Hecto>    Hectomole;
  typedef Quantity<AmountOfSubstance,Kilo>     Kilomole;
  typedef Quantity<AmountOfSubstance,Mega>     Megamole;
  typedef Quantity<AmountOfSubstance,Giga>     Gigamole; 
  typedef Quantity<AmountOfSubstance,Tera>     Teramole;
  typedef Quantity<AmountOfSubstance,Peta>     Petamole;
  typedef Quantity<AmountOfSubstance,Exa>      Examole;
  typedef Quantity<AmountOfSubstance,Zetta>    Zeptamole;
  typedef Quantity<AmountOfSubstance,Yotta>    Yottamole;


  struct CatalyticActivity : public Product<Second::Invert,Mole>
  {

    typedef CatalyticActivity DerivedType;

    inline static Types::String Suffix()
    {
      return Types::String( L"kat" );
    }

  };

  typedef Quantity<CatalyticActivity,Yocto>    Yoctokatal;
  typedef Quantity<CatalyticActivity,Zepto>    Zeptokatal;
  typedef Quantity<CatalyticActivity,Atto>     Attokatal;
  typedef Quantity<CatalyticActivity,Femto>    Femtokatal;
  typedef Quantity<CatalyticActivity,Pico>     Picokatal;
  typedef Quantity<CatalyticActivity,Nano>     Nanokatal;
  typedef Quantity<CatalyticActivity,Micro>    Microkatal;
  typedef Quantity<CatalyticActivity,Milli>    Millikatal;
  typedef Quantity<CatalyticActivity,Centi>    Centikatal;
  typedef Quantity<CatalyticActivity,Deci>     Decikatal;
  typedef Quantity<CatalyticActivity>          Katal;
  typedef Quantity<CatalyticActivity,Deka>     Dekakatal;
  typedef Quantity<CatalyticActivity,Hecto>    Hectokatal;
  typedef Quantity<CatalyticActivity,Kilo>     Kilokatal;
  typedef Quantity<CatalyticActivity,Mega>     Megakatal;
  typedef Quantity<CatalyticActivity,Giga>     Gigakatal;
  typedef Quantity<CatalyticActivity,Tera>     Terakatal;
  typedef Quantity<CatalyticActivity,Peta>     Petakatal;
  typedef Quantity<CatalyticActivity,Exa>      Exakatal;
  typedef Quantity<CatalyticActivity,Zetta>    Zeptakatal;
  typedef Quantity<CatalyticActivity,Yotta>    Yottakatal;


} //namespace SI


} //namespace Unit
