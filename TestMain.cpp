
#include "stdafx.h"
#include <cassert>
#include <cmath>
#include <conio.h>
#include <fcntl.h>
#include <io.h>

#include "UnitSI.h"


void TestLength();
void TestForce();
void TestAcceleration();
void TestUnitMass();
void TestVelocity();
void TestAngular();
void TestRunTimePerformance();
void TestPV_equals_NRT();
void TestElectric();
void TestTemperature();

using namespace Unit::SI;

int __cdecl main()
{
  _setmode(_fileno(stdout), _O_U16TEXT);

  TestLength();
  TestVelocity();
  TestUnitMass();   
  TestAcceleration();
  TestForce();
  TestAngular();
  TestPV_equals_NRT();
  TestElectric();
  TestTemperature();

#ifndef _DEBUG
  TestRunTimePerformance();
#endif

  _getch();

  return 0;
}


extern void Assert( bool const b )
{
  assert( b );
}

extern bool fequal( double const x, double const y )
{
  return ::fabs( x - y ) < boost::math::tools::root_epsilon<double>();
}
