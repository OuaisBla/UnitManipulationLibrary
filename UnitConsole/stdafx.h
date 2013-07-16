


#pragma once


#include <iostream>
#include <sstream>

#include "Unit.h"

using namespace Unit::Types;

void Assert( bool );
void OutputLine( String const & );


inline bool fequal( double const x, double const y, double const _scale = 1.0 )
{
  return ::fabs( x / _scale - y / _scale ) < boost::math::tools::root_epsilon<double>();
} 

inline String ToString( Scalar const _s )
{
  std::wostringstream oss;

  oss << _s;
  
  return oss.str();
}


