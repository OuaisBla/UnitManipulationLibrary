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


#include <boost/math/common_factor.hpp>


namespace Unit
{


  typedef double        Scalar;
  typedef long          Integer;
  typedef std::wstring  String;


  template <bool>
  struct CompatibleUnit;

  template <>
  struct CompatibleUnit<true> { };


  template <Integer V>
  struct IntegerAbs
  {

    enum{ value = (V > 0 ? V : -V) };

  };

  template <Integer V, Integer E>
  struct IntegerPow
  {

    enum{ value = V * IntegerPow<V, IntegerAbs<E>::value - 1>::value };

  };

  template<Integer V>
  struct IntegerPow<V, 0>
  {

    enum{ value = 1 };

  };

  template<Integer V>
  struct IntegerPow<V, 1>
  {

    enum{ value = V };

  };



}
