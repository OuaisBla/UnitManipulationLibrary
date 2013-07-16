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


struct _Temperature : public Object<>, public Facade<_Temperature>
{

  enum { NumeratorBaseTypeValue = 11 };
  enum { DenumeratorBaseTypeValue = 1 };

  inline static Types::String Suffix() { return Types::String( L"K" ); }

  static ScalarType Offset() { return 0.0; }

};


typedef _Temperature::SimplifiedType Temperature;


namespace SI
{


typedef Quantity<Temperature,Yocto>    Yoctokelvin;
typedef Quantity<Temperature,Zepto>    Zeptokelvin;
typedef Quantity<Temperature,Atto>     Attokelvin;
typedef Quantity<Temperature,Femto>    Femtokelvin;
typedef Quantity<Temperature,Pico>     Picokelvin;
typedef Quantity<Temperature,Nano>     Nanokelvin;
typedef Quantity<Temperature,Micro>    Microkelvin;
typedef Quantity<Temperature,Milli>    Millikelvin;
typedef Quantity<Temperature,Centi>    Centikelvin;
typedef Quantity<Temperature,Deci>     Decikelvin;
typedef Quantity<Temperature>          Kelvin;
typedef Quantity<Temperature,Deka>     Dekakelvin;
typedef Quantity<Temperature,Hecto>    Hectokelvin;
typedef Quantity<Temperature,Kilo>     Kilokelvin;
typedef Quantity<Temperature,Mega>     Megakelvin;
typedef Quantity<Temperature,Giga>     Gigakelvin; 
typedef Quantity<Temperature,Tera>     Terakelvin;
typedef Quantity<Temperature,Peta>     Petakelvin;
typedef Quantity<Temperature,Exa>      Exakelvin;
typedef Quantity<Temperature,Zetta>    Zeptakelvin;
typedef Quantity<Temperature,Yotta>    Yottakelvin;


} //namespace SI


namespace NonSI
{

  struct _Celsius : public Temperature
  {

    static Types::String Suffix() { return Types::String( L"°C" ); }

    static ScalarType Offset() { return 273.15; }

  };

  typedef Quantity<_Celsius>          Celsius;

}


template <typename T>
class OffsetHandler<T, NonSI::_Celsius>
{
public:

  typedef NonSI::_Celsius::ScalarType ScalarType;

  inline static ScalarType Convert( ScalarType const value )
  {
    return value + (NonSI::_Celsius::Offset() - T::Offset() );
  }

};

template <typename T>
class OffsetHandler<NonSI::_Celsius, T>
{
public:

  typedef NonSI::_Celsius::ScalarType ScalarType;

  inline static ScalarType Convert( ScalarType const value )
  {
    return value + (T::Offset() - NonSI::_Celsius::Offset() );
  }

};



} //namespace Unit

