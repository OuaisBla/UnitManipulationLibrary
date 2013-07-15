


#pragma once


#include <iostream>
#include <sstream>

#include "Unit.h"

using namespace Unit::Types;

void Assert( bool );
void OutputLine( String const & );


inline bool fequal( double const x, double const y )
{
  return ::fabs( x - y ) < boost::math::tools::root_epsilon<double>();
}

inline String ToString( Scalar const _s )
{
  std::wostringstream oss;

  oss << _s;
  
  return oss.str();
}


