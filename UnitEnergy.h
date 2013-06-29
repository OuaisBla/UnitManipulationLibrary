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


#include "UnitForce.h"


namespace Unit
{


namespace SI
{


class Energy : public Product<Product<Product<Meter>,Kilogram>,Product<Second>::Invert>::UnitType
{
public:

  inline static String Suffix()
  {
    return String( L"J" );
  }

};


typedef Simple<Energy,Yocto>  Yoctojoule;
typedef Simple<Energy,Zepto>  Zeptojoule;
typedef Simple<Energy,Atto>   Attojoule;
typedef Simple<Energy,Femto>  Femtojoule;
typedef Simple<Energy,Pico>   Picojoule;
typedef Simple<Energy,Nano>   Nanojoule;
typedef Simple<Energy,Micro>  Microjoule;
typedef Simple<Energy,Milli>  Millijoule;
typedef Simple<Energy,Centi>  Centijoule;
typedef Simple<Energy,Deci>   Decijoule;
typedef Simple<Energy>        Joule;
typedef Simple<Energy,Deka>   Dekajoule;
typedef Simple<Energy,Hecto>  Hectojoule;
typedef Simple<Energy,Kilo>   Kilojoule;
typedef Simple<Energy,Mega>   Megajoule;
typedef Simple<Energy,Giga>   Gigajoule;
typedef Simple<Energy,Tera>   Terajoule;
typedef Simple<Energy,Peta>   Petajoule;
typedef Simple<Energy,Exa>    Exajoule;
typedef Simple<Energy,Zetta>  Zeptajoule;
typedef Simple<Energy,Yotta>  Yottajoule;


} //namespace SI


} //namespace Unit
