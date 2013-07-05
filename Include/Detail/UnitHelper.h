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
#include <boost/unordered_map.hpp>
#include <xstring>


namespace Unit
{

  namespace Types
  {

    typedef double        Scalar;
    typedef long          Integer;
    typedef std::wstring  String;

  }


  namespace Literals
  {

    //
    //  Constants literals
    //
    wchar_t const DOT_OPERATOR            = L'\u22C5';
    wchar_t const SUPERSCRIPT_PLUS        = L'\u207A';
    wchar_t const SUPERSCRIPT_MINUS       = L'\u207B';

    wchar_t const SUPERSCRIPT_1           = L'\u00B9';
    wchar_t const SUPERSCRIPT_2           = L'\u00B2';
    wchar_t const SUPERSCRIPT_3           = L'\u00B3';
    wchar_t const SUPERSCRIPT_4           = L'\u2074';
    wchar_t const SUPERSCRIPT_5           = L'\u2075';
    wchar_t const SUPERSCRIPT_6           = L'\u2076';
    wchar_t const SUPERSCRIPT_7           = L'\u2077';
    wchar_t const SUPERSCRIPT_8           = L'\u2078';
    wchar_t const SUPERSCRIPT_9           = L'\u2079';
    wchar_t const SUPERSCRIPT_0           = L'\u2070';

  }

  namespace Detail
  {

    typedef std::pair<Types::String, Types::String>     PairString;
    typedef boost::unordered_map<Types::Integer, PairString>   SuffixesMap;

    //
    //  Compile-time assertion operator
    //
    template <bool>
    struct CompatibleUnit;

    template <>
    struct CompatibleUnit<true> { };


    //
    //  Compile time integer helper
    //
    template <Types::Integer V>
    struct IntegerAbs
    {

      enum{ value = (V > 0 ? V : -V) };

    };

    template <Types::Integer V, Types::Integer E>
    struct IntegerPow
    {

      enum{ value = V * IntegerPow<V, IntegerAbs<E>::value - 1>::value };

    };

    template<Types::Integer V>
    struct IntegerPow<V, 0>
    {

      enum{ value = 1 };

    };

    template<Types::Integer V>
    struct IntegerPow<V, 1>
    {

      enum{ value = V };

    };


    inline Types::String SuffixExponent( Types::Integer E )
    {
      wchar_t buf[4] = { L'\0', L'\0', L'\0', L'\0' };

      switch( E )
      {
      case -4:
        buf[0] = Literals::SUPERSCRIPT_MINUS;
        buf[1] = Literals::SUPERSCRIPT_4;
        break;
      case -3:
        buf[0] = Literals::SUPERSCRIPT_MINUS;
        buf[1] = Literals::SUPERSCRIPT_3;
        break;
      case -2:
        buf[0] = Literals::SUPERSCRIPT_MINUS;
        buf[1] = Literals::SUPERSCRIPT_2;
        break;
      case -1:
        buf[0] = Literals::SUPERSCRIPT_MINUS;
        buf[1] = Literals::SUPERSCRIPT_1;
        break;
      case 1:
        break;
      case 2:
        buf[0] = Literals::SUPERSCRIPT_2;
        break;
      case 3:
        buf[0] = Literals::SUPERSCRIPT_3;
        break;
      case 4:
        buf[0] = Literals::SUPERSCRIPT_4;
        break;
      default:
        ::swprintf_s( buf, L"%d", Types::Integer( E ) );
      }

      return Types::String( buf );
    }


    //
    //  Runtime time integer helper for factorization
    //
    inline void decompose(Types::Integer n, boost::unordered_map<Types::Integer, Types::Integer> &out)
    {
      int _sign = n < 0 ? -1 : 1; 

      n = ::abs( n );

      Types::Integer i(2);

      while (n != 1)
      {
        while (n % i == Types::Integer(0))
        {
          boost::unordered_map<Types::Integer, Types::Integer>::iterator it = out.find( i ); 
          if( it == out.end() )
          {
            it = out.insert( boost::unordered_map<Types::Integer, Types::Integer>::value_type( i, 0 ) ).first;
          }

          it->second += _sign;

          n /= i;
        }
        ++i;
      }
    }

    inline bool IsPrime( Types::Integer n )
    {
      Types::Integer const count = static_cast<Types::Integer>( ::sqrt( n * 1.0 ) ) + 1;

      bool is_prime = n == 2 || n % 2 != 0;

      for(Types::Integer i = 3; i < count && is_prime; i += 2) 
      { 
        is_prime = n % i != 0;
      }

      return is_prime;
    }

  }

}
