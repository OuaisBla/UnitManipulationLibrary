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

  enum { NumeratorBaseTypeValue = 7 };
  enum { DenumeratorBaseTypeValue = 1 };

  inline static String Suffix() { return String( L"K" ); }

  static ScalarType Offset() { return 0.0; }

};


typedef _Temperature::SimplifiedType Temperature;


namespace SI
{


typedef Simple<Temperature,Yocto>    Yoctokelvin;
typedef Simple<Temperature,Zepto>    Zeptokelvin;
typedef Simple<Temperature,Atto>     Attokelvin;
typedef Simple<Temperature,Femto>    Femtokelvin;
typedef Simple<Temperature,Pico>     Picokelvin;
typedef Simple<Temperature,Nano>     Nanokelvin;
typedef Simple<Temperature,Micro>    Microkelvin;
typedef Simple<Temperature,Milli>    Millikelvin;
typedef Simple<Temperature,Centi>    Centikelvin;
typedef Simple<Temperature,Deci>     Decikelvin;
typedef Simple<Temperature>          Kelvin;
typedef Simple<Temperature,Deka>     Dekakelvin;
typedef Simple<Temperature,Hecto>    Hectokelvin;
typedef Simple<Temperature,Kilo>     Kilokelvin;
typedef Simple<Temperature,Mega>     Megakelvin;
typedef Simple<Temperature,Giga>     Gigakelvin; 
typedef Simple<Temperature,Tera>     Terakelvin;
typedef Simple<Temperature,Peta>     Petakelvin;
typedef Simple<Temperature,Exa>      Exakelvin;
typedef Simple<Temperature,Zetta>    Zeptakelvin;
typedef Simple<Temperature,Yotta>    Yottakelvin;


} //namespace SI


namespace NonSI
{

  struct _Celsius : public Temperature
  {

    static String Suffix() { return String( L"°C" ); }

    static ScalarType Offset() { return 273.15; }

  };

  typedef Simple<_Celsius>          Celsius;

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

