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


#include "UnitArea.h"


namespace Unit
{


namespace SI
{


typedef Product<Squaremeter,Meter>::UnitType Volume;


typedef Quantity<Volume,Yocto>  Yoctocubicmeter;
typedef Quantity<Volume,Zepto>  Zeptocubicmeter;
typedef Quantity<Volume,Atto>   Attocubicmeter;
typedef Quantity<Volume,Femto>  Femtocubicmeter;
typedef Quantity<Volume,Pico>   Picocubicmeter;
typedef Quantity<Volume,Nano>   Nanocubicmeter;
typedef Quantity<Volume,Micro>  Microcubicmeter;
typedef Quantity<Volume,Milli>  Millicubicmeter;
typedef Quantity<Volume,Centi>  Centicubicmeter;
typedef Quantity<Volume,Deci>   Decicubicmeter;
typedef Quantity<Volume>        Cubicmeter;
typedef Quantity<Volume,Deka>   Dekacubicmeter;
typedef Quantity<Volume,Hecto>  Hectocubicmeter;
typedef Quantity<Volume,Kilo>   Kilocubicmeter;
typedef Quantity<Volume,Mega>   Megacubicmeter;
typedef Quantity<Volume,Giga>   Gigacubicmeter;
typedef Quantity<Volume,Tera>   Teracubicmeter;
typedef Quantity<Volume,Peta>   Petacubicmeter;
typedef Quantity<Volume,Exa>    Exacubicmeter;
typedef Quantity<Volume,Zetta>  Zeptacubicmeter;
typedef Quantity<Volume,Yotta>  Yottacubicmeter;


} //namespace SI


namespace NonSI
{


  struct _Liter : public SI::Volume
  {

    typedef _Liter DerivedType;
    typedef SI::Deci SimplifiedFactor;

    static Types::String Suffix() { return Types::String( L"L" ); }

  };


  typedef Quantity<_Liter,SI::Yocto>  Yoctoliter;
  typedef Quantity<_Liter,SI::Zepto>  Zeptoliter;
  typedef Quantity<_Liter,SI::Atto>   Attoliter;
  typedef Quantity<_Liter,SI::Femto>  Femtoliter;
  typedef Quantity<_Liter,SI::Pico>   Picoliter;
  typedef Quantity<_Liter,SI::Nano>   Nanoliter;
  typedef Quantity<_Liter,SI::Micro>  Microliter;
  typedef Quantity<_Liter,SI::Milli>  Milliliter;
  typedef Quantity<_Liter,SI::Centi>  Centiliter;
  typedef Quantity<_Liter,SI::Deci>   Deciliter;
  typedef Quantity<_Liter>            Liter;
  typedef Quantity<_Liter,SI::Deka>   Dekaliter;
  typedef Quantity<_Liter,SI::Hecto>  Hectoliter;
  typedef Quantity<_Liter,SI::Kilo>   Kiloliter;
  typedef Quantity<_Liter,SI::Mega>   Megaliter;
  typedef Quantity<_Liter,SI::Giga>   Gigaliter;
  typedef Quantity<_Liter,SI::Tera>   Teraliter;
  typedef Quantity<_Liter,SI::Peta>   Petaliter;
  typedef Quantity<_Liter,SI::Exa>    Exaliter;
  typedef Quantity<_Liter,SI::Zetta>  Zeptaliter;
  typedef Quantity<_Liter,SI::Yotta>  Yottaliter;


} //namespace SI


} //namespace Unit

