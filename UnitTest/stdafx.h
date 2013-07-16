// stdafx.h : include file for standard system include files,
// or project specific include files that are used frequently,
// but are changed infrequently

#pragma once


#include "Unit.h"
#include "UnitSI.h"
#include <msclr\marshal.h>
#include <msclr\marshal_cppstd.h>

using Unit::Types::Scalar;


void Assert( bool );
void OutputLine( Unit::Types::String const & );

inline bool fequal( double const x, double const y, double const _scale = 1.0 )
{
  return ::fabs( x / _scale - y / _scale ) < boost::math::tools::root_epsilon<double>();
} 

inline Unit::Types::String ToString( Scalar const _s )
{
  System::String ^s = _s.ToString( System::Globalization::CultureInfo::InvariantCulture );

  return msclr::interop::marshal_as<std::wstring>(s);
}
