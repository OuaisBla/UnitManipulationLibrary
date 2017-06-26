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


#include "UnitEnergy.h"



namespace Unit
{

namespace SI
{

  namespace Constants
  {

    Joule const eV(1.60217653e-19);    // electron volt

  }


  struct _ElectronVoltFactor
  {

    typedef _ElectronVoltFactor               SimplifiedFactor;
    typedef InvertFactor<_ElectronVoltFactor> InvertedFactor;

    static Types::Scalar ConversionFactor() { return Constants::eV.GetValue(); }

    static Types::String Suffix() { return Types::String(); }

  };


  struct _ElectronVolt : public Energy
  {

    typedef _ElectronVolt DerivedType;
    typedef _ElectronVoltFactor SimplifiedFactor;

    inline static Types::String Suffix()
    {
      return Types::String( L"eV" );
    }

  };


  typedef Quantity<_ElectronVolt,Yocto>  Yoctoelectronvolt;
  typedef Quantity<_ElectronVolt,Zepto>  Zeptoelectronvolt;
  typedef Quantity<_ElectronVolt,Atto>   Attoelectronvolt;
  typedef Quantity<_ElectronVolt,Femto>  Femtoelectronvolt;
  typedef Quantity<_ElectronVolt,Pico>   Picoelectronvolt;
  typedef Quantity<_ElectronVolt,Nano>   Nanoelectronvolt;
  typedef Quantity<_ElectronVolt,Micro>  Microelectronvolt;
  typedef Quantity<_ElectronVolt,Milli>  Millielectronvolt;
  typedef Quantity<_ElectronVolt,Centi>  Centielectronvolt;
  typedef Quantity<_ElectronVolt,Deci>   Decielectronvolt;
  typedef Quantity<_ElectronVolt>        ElectronVolt;
  typedef Quantity<_ElectronVolt,Deka>   Dekaelectronvolt;
  typedef Quantity<_ElectronVolt,Hecto>  Hectoelectronvolt;
  typedef Quantity<_ElectronVolt,Kilo>   Kiloelectronvolt;
  typedef Quantity<_ElectronVolt,Mega>   Megaelectronvolt;
  typedef Quantity<_ElectronVolt,Giga>   Gigaelectronvolt;
  typedef Quantity<_ElectronVolt,Tera>   Teraelectronvolt;
  typedef Quantity<_ElectronVolt,Peta>   Petaelectronvolt;
  typedef Quantity<_ElectronVolt,Exa>    Exaelectronvolt;
  typedef Quantity<_ElectronVolt,Zetta>  Zeptaelectronvolt;
  typedef Quantity<_ElectronVolt,Yotta>  Yottaelectronvolt;


} //namespace SI


} //namespace Unit
