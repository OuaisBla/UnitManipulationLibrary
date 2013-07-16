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


  template<typename _ScalarType = Types::Scalar>
  struct _Length : public Object<_ScalarType>, public Facade<_Length<_ScalarType> >
  {

    enum { NumeratorBaseTypeValue = 2 };
    enum { DenumeratorBaseTypeValue = 1 };

    inline static Types::String Suffix()
    { 
      return Types::String( L"m" );
    }

  };


typedef _Length<>::SimplifiedType Length;


namespace SI
{


typedef Quantity<Length,Yocto>    Yoctometer;
typedef Quantity<Length,Zepto>    Zeptometer;
typedef Quantity<Length,Atto>     Attometer;
typedef Quantity<Length,Femto>    Femtometer;
typedef Quantity<Length,Pico>     Picometer;
typedef Quantity<Length,Nano>     Nanometer;
typedef Quantity<Length,Micro>    Micrometer;
typedef Quantity<Length,Milli>    Millimeter;
typedef Quantity<Length,Centi>    Centimeter;
typedef Quantity<Length,Deci>     Decimeter;
typedef Quantity<Length>          Meter;
typedef Quantity<Length,Deka>     Dekameter;
typedef Quantity<Length,Hecto>    Hectometer;
typedef Quantity<Length,Kilo>     Kilometer;
typedef Quantity<Length,Mega>     Megameter;
typedef Quantity<Length,Giga>     Gigameter;
typedef Quantity<Length,Tera>     Terameter;
typedef Quantity<Length,Peta>     Petameter;
typedef Quantity<Length,Exa>      Exameter;
typedef Quantity<Length,Zetta>    Zeptameter;
typedef Quantity<Length,Yotta>    Yottameter;


} // namespace SI


namespace NonSI
{


struct _Mil : public Length
{

  typedef _Mil DerivedType;

  static Types::String Suffix() { return Types::String( L"mil" ); }

};

struct _MilFactor
{

  typedef _MilFactor                SimplifiedFactor;
  typedef InvertFactor<_MilFactor>  InvertedFactor;

  static Types::Scalar ConversionFactor() { return .0000254; }

  static Types::String Suffix() { return Types::String(); }

};


struct _Inch : public Length
{

  typedef _Inch DerivedType;

  static Types::String Suffix() { return Types::String( L"in" ); }

};

struct _InchFactor : public Length
{

  typedef _InchFactor               SimplifiedFactor;
  typedef InvertFactor<_InchFactor> InvertedFactor;

  static Types::Scalar ConversionFactor() { return .0254; }

  static Types::String Suffix() { return Types::String(); }

};

struct _Foot : public Length
{

  typedef _Foot DerivedType;

  static Types::String Suffix() { return Types::String( L"ft" ); }

};

class _FootFactor
{
public:

  typedef _FootFactor               SimplifiedFactor;
  typedef InvertFactor<_FootFactor> InvertedFactor;

  static Types::Scalar ConversionFactor() { return .3048; }

  static Types::String Suffix() { return Types::String(); }

};

typedef Quantity<_Mil,_MilFactor>     Mil;
typedef Quantity<_Inch,_InchFactor>   Inch;
typedef Quantity<_Foot,_FootFactor>   Foot;


} //namespace NonSI


} //Namespace Unit

