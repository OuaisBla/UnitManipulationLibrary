
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
void TestMass();
void TestVelocity();
void TestAngular();
void TestRunTimePerformance();
void TestPV_equals_NRT();
void TestElectric();
void TestTemperature();
void TestFrequency();
void TestSquareMeter();
void TestCubicMeter();

using namespace Unit::SI;

int __cdecl main()
{
  _setmode(_fileno(stdout), _O_U16TEXT);

  TestLength();
  TestVelocity();
  TestMass();   
  TestAcceleration();
  TestForce();
  TestAngular();
  TestPV_equals_NRT();
  TestElectric();
  TestTemperature();
  TestFrequency();
  TestSquareMeter();
  TestCubicMeter();

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

extern void OutputLine( Unit::Types::String const &_s )
{
  std::wcout << _s << std::endl;
}
