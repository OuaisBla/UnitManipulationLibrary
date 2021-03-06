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


  struct _Celsius : public Temperature
  {

    typedef _Celsius DerivedType;

    static Types::String Suffix() { return Types::String( L"�C" ); }

    static ScalarType Offset() { return 273.15; }

  };


  typedef Quantity<_Celsius,Yocto>    Yoctocelsius;
  typedef Quantity<_Celsius,Zepto>    Zeptocelsius;
  typedef Quantity<_Celsius,Atto>     Attocelsius;
  typedef Quantity<_Celsius,Femto>    Femtocelsius;
  typedef Quantity<_Celsius,Pico>     Picocelsius;
  typedef Quantity<_Celsius,Nano>     Nanocelsius;
  typedef Quantity<_Celsius,Micro>    Microcelsius;
  typedef Quantity<_Celsius,Milli>    Millicelsius;
  typedef Quantity<_Celsius,Centi>    Centicelsius;
  typedef Quantity<_Celsius,Deci>     Decicelsius;
  typedef Quantity<_Celsius>          Celsius;
  typedef Quantity<_Celsius,Deka>     Dekacelsius;
  typedef Quantity<_Celsius,Hecto>    Hectocelsius;
  typedef Quantity<_Celsius,Kilo>     Kilocelsius;
  typedef Quantity<_Celsius,Mega>     Megacelsius;
  typedef Quantity<_Celsius,Giga>     Gigacelsius; 
  typedef Quantity<_Celsius,Tera>     Teracelsius;
  typedef Quantity<_Celsius,Peta>     Petacelsius;
  typedef Quantity<_Celsius,Exa>      Exacelsius;
  typedef Quantity<_Celsius,Zetta>    Zeptacelsius;
  typedef Quantity<_Celsius,Yotta>    Yottacelsius;

} //namespace SI


namespace NonSI
{

  struct _Fahrenheit : public Temperature
  {

    typedef _Fahrenheit DerivedType;

    static Types::String Suffix() { return Types::String( L"�F" ); }

    static ScalarType Offset() { return 255.37222222222222222222222222222; }

  };

  struct _FahrenheitFactor
  {

    typedef _FahrenheitFactor               SimplifiedFactor;
    typedef InvertFactor<_FahrenheitFactor> InvertedFactor;

    static Types::Scalar ConversionFactor() { return 5./9.; }

    static Types::String Suffix() { return Types::String(); }

  };


  typedef Quantity<_Fahrenheit, _FahrenheitFactor> Fahrenheit;

}


template <>
struct is_supporting_offset<_Temperature> : public ::boost::integral_constant<bool,true>
{
};


} //namespace Unit
