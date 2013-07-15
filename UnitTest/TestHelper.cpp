
#include "stdafx.h"
#include <math.h>
#include <boost\math\tools\precision.hpp>

using namespace System;
using namespace System::Text;
using namespace System::Collections::Generic;


void __cdecl Assert( bool const b )
{
  Microsoft::VisualStudio::TestTools::UnitTesting::Assert::IsTrue( b );
}


bool __cdecl fequal( double const x, double const y )
{
  return ::fabs( x - y ) < boost::math::tools::root_epsilon<double>();
}
