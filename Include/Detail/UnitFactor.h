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


#include "Detail\UnitObject.h"


namespace Unit
{


namespace SI
{


template<>
class Factor<-24>
{
public:

  typedef Factor<-24> SimplifiedFactor;
  typedef Factor<24> InvertedFactor;

  static Types::Scalar ConversionFactor() { return 1.e-24; }

  static Types::String Suffix() { return Types::String( L"y" ); }

};

template<>
class Factor<-21>
{
public:

  typedef Factor<-21> SimplifiedFactor;
  typedef Factor<21> InvertedFactor;

  static Types::Scalar ConversionFactor() { return 1.e-21; }

  static Types::String Suffix() { return Types::String( L"z" ); }

};

template<>
class Factor<-18>
{
public:

  typedef Factor<-18> SimplifiedFactor;
  typedef Factor<18> InvertedFactor;

  static Types::Scalar ConversionFactor() { return 1.e-18; }

  static Types::String Suffix() { return Types::String( L"a" ); }

};

template<>
class Factor<-15>
{
public:

  typedef Factor<-15> SimplifiedFactor;
  typedef Factor<15> InvertedFactor;

  static Types::Scalar ConversionFactor() { return 1.e-15; }

  static Types::String Suffix() { return Types::String( L"f" ); }

};

template<>
class Factor<-12>
{
public:

  typedef Factor<-12> SimplifiedFactor;
  typedef Factor<12> InvertedFactor;

  static Types::Scalar ConversionFactor() { return 1.e-12; }

  static Types::String Suffix() { return Types::String( L"p" ); }

};

template<>
class Factor<-10>
{
public:

  typedef Factor<-10> SimplifiedFactor;
  typedef Factor<10> InvertedFactor;

  static Types::Scalar ConversionFactor() { return 1.e-10; }

  static Types::String Suffix() { return Types::String( L"\'10e-10\'" ); }

};

template<>
class Factor<-9>
{
public:

  typedef Factor<-9> SimplifiedFactor;
  typedef Factor<9> InvertedFactor;

  static Types::Scalar ConversionFactor() { return 1.e-9; }

  static Types::String Suffix() { return Types::String( L"n" ); }

};

template<>
class Factor<-8>
{
public:

  typedef Factor<-8> SimplifiedFactor;
  typedef Factor<8> InvertedFactor;

  static Types::Scalar ConversionFactor() { return 1.e-8; }

  static Types::String Suffix() { return Types::String( L"\'10e-8\'" ); }

};

template<>
class Factor<-7>
{
public:

  typedef Factor<-7> SimplifiedFactor;
  typedef Factor<7> InvertedFactor;

  static Types::Scalar ConversionFactor() { return 1.e-7; }

  static Types::String Suffix() { return Types::String( L"\'10e-7\'" ); }

};

template<>
class Factor<-6>
{
public:

  typedef Factor<-6> SimplifiedFactor;
  typedef Factor<6> InvertedFactor;

  static Types::Scalar ConversionFactor() { return 1.e-6; }

  static Types::String Suffix() { return Types::String( L"u" ); }

};

template<>
class Factor<-5>
{
public:

  typedef Factor<-5> SimplifiedFactor;
  typedef Factor<5> InvertedFactor;

  static Types::Scalar ConversionFactor() { return 1.e-5; }

  static Types::String Suffix() { return Types::String( L"\'10e-5\'" ); }

};

template<>
class Factor<-4>
{
public:

  typedef Factor<-4> SimplifiedFactor;
  typedef Factor<4> InvertedFactor;

  static Types::Scalar ConversionFactor() { return 1.e-4; }

  static Types::String Suffix() { return Types::String( L"\'10e-4\'" ); }

};

template<>
class Factor<-3>
{
public:

  typedef Factor<-3> SimplifiedFactor;
  typedef Factor<3> InvertedFactor;

  static Types::Scalar ConversionFactor() { return 1.e-3; }

  static Types::String Suffix() { return Types::String( L"m" ); }

};

template<>
class Factor<-2>
{
public:

  typedef Factor<-2> SimplifiedFactor;
  typedef Factor<2> InvertedFactor;

  static Types::Scalar ConversionFactor() { return 1.e-2; }

  static Types::String Suffix() { return Types::String( L"c" ); }

};

template<>
class Factor<-1>
{
public:

  typedef Factor<-1> SimplifiedFactor;
  typedef Factor<1> InvertedFactor;

  static Types::Scalar ConversionFactor() { return 1.e-1; }

  static Types::String Suffix() { return Types::String( L"d" ); }

};

template<>
class Factor<0>
{
public:

  typedef Identity SimplifiedFactor;
  typedef Identity InvertedFactor;

  static Types::Scalar ConversionFactor() { return Identity::ConversionFactor(); }

  static Types::String Suffix() { return Identity::Suffix(); }

};

template<>
class Factor<1>
{
public:

  typedef Factor<1> SimplifiedFactor;
  typedef Factor<-1> InvertedFactor;

  static Types::Scalar ConversionFactor() { return 1.e1; }

  static Types::String Suffix() { return Types::String( L"da" ); }

};

template<>
class Factor<2>
{
public:

  typedef Factor<2> SimplifiedFactor;
  typedef Factor<-2> InvertedFactor;

  static Types::Scalar ConversionFactor() { return 1.e2; }

  static Types::String Suffix() { return Types::String( L"h" ); }

};

template<>
class Factor<3>
{
public:

  typedef Factor<3> SimplifiedFactor;
  typedef Factor<-3> InvertedFactor;

  static Types::Scalar ConversionFactor() { return 1.e3; }

  static Types::String Suffix() { return Types::String( L"k" ); }

};

template<>
class Factor<4>
{
public:

  typedef Factor<4> SimplifiedFactor;
  typedef Factor<-4> InvertedFactor;

  static Types::Scalar ConversionFactor() { return 1.e4; }

  static Types::String Suffix() { return Types::String( L"\'10e4\'" ); }

};

template<>
class Factor<5>
{
public:

  typedef Factor<5> SimplifiedFactor;
  typedef Factor<-5> InvertedFactor;

  static Types::Scalar ConversionFactor() { return 1.e5; }

  static Types::String Suffix() { return Types::String( L"\'10e5\'" ); }

};

template<>
class Factor<6>
{
public:

  typedef Factor<6> SimplifiedFactor;
  typedef Factor<-6> InvertedFactor;

  static Types::Scalar ConversionFactor() { return 1.e6; }

  static Types::String Suffix() { return Types::String( L"M" ); }

};

template<>
class Factor<7>
{
public:

  typedef Factor<7> SimplifiedFactor;
  typedef Factor<-7> InvertedFactor;

  static Types::Scalar ConversionFactor() { return 1.e7; }

  static Types::String Suffix() { return Types::String( L"\'10e7\'" ); }

};

template<>
class Factor<8>
{
public:

  typedef Factor<8> SimplifiedFactor;
  typedef Factor<-8> InvertedFactor;

  static Types::Scalar ConversionFactor() { return 1.e8; }

  static Types::String Suffix() { return Types::String( L"\'10e8\'" ); }

};

template<>
class Factor<9>
{
public:

  typedef Factor<9> SimplifiedFactor;
  typedef Factor<-9> InvertedFactor;

  static Types::Scalar ConversionFactor() { return 1.e9; }

  static Types::String Suffix() { return Types::String( L"G" ); }

};

template<>
class Factor<10>
{
public:

  typedef Factor<10> SimplifiedFactor;
  typedef Factor<-10> InvertedFactor;

  static Types::Scalar ConversionFactor() { return 1.e10; }

  static Types::String Suffix() { return Types::String( L"\'10e10\'" ); }

};

template<>
class Factor<12>
{
public:

  typedef Factor<12> SimplifiedFactor;
  typedef Factor<-12> InvertedFactor;

  static Types::Scalar ConversionFactor() { return 1.e12; }

  static Types::String Suffix() { return Types::String( L"T" ); }

};

template<>
class Factor<15>
{
public:

  typedef Factor<15> SimplifiedFactor;
  typedef Factor<-15> InvertedFactor;

  static Types::Scalar ConversionFactor() { return 1.e15; }

  static Types::String Suffix() { return Types::String( L"P" ); }

};

template<>
class Factor<18>
{
public:

  typedef Factor<18> SimplifiedFactor;
  typedef Factor<-18> InvertedFactor;

  static Types::Scalar ConversionFactor() { return 1.e18; }

  static Types::String Suffix() { return Types::String( L"E" ); }

};

template<>
class Factor<21>
{
public:

  typedef Factor<21> SimplifiedFactor;
  typedef Factor<-21> InvertedFactor;

  static Types::Scalar ConversionFactor() { return 1.e21; }

  static Types::String Suffix() { return Types::String( L"Z" ); }

};

template<>
class Factor<24>
{
public:

  typedef Factor<24> SimplifiedFactor;
  typedef Factor<-24> InvertedFactor;

  static Types::Scalar ConversionFactor() { return 1.e24; }

  static Types::String Suffix() { return Types::String( L"Y" ); }

};


typedef Factor<-24> Yocto;
typedef Factor<-21> Zepto;
typedef Factor<-18> Atto;
typedef Factor<-15> Femto;
typedef Factor<-12> Pico;
typedef Factor<-9>  Nano;
typedef Factor<-6>  Micro;
typedef Factor<-3>  Milli;
typedef Factor<-2>  Centi;
typedef Factor<-1>  Deci;
typedef Factor<1>   Deka;
typedef Factor<2>   Hecto;
typedef Factor<3>   Kilo;
typedef Factor<6>   Mega;
typedef Factor<9>   Giga;
typedef Factor<12>  Tera;
typedef Factor<15>  Peta;
typedef Factor<18>  Exa;
typedef Factor<21>  Zetta;
typedef Factor<24>  Yotta;


} //Namespace SI



  template<typename T>
  class InvertFactor
  {
  public:

    typedef InvertFactor<T> SimplifiedFactor;
    typedef T               InvertedFactor;

    static Types::Scalar ConversionFactor() { return 1.0 / T::ConversionFactor(); }

    static Types::String Suffix() 
    { 
      Types::String const _factorString = T::Suffix();

      return _factorString.empty() ? Types::String() : Types::String( L"//" ) + _factorString; 
    }

  };

} //Namespace Unit

