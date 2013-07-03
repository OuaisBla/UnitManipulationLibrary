
#include "stdafx.h"
#include "UnitTemperature.h"
#include <iostream>


using namespace Unit;
using namespace Unit::SI;
using namespace Unit::NonSI;


static void TestClassDefinition();
static void SeeClassDefinition();


void Assert( bool );
bool fequal( double, double );


void TestUnitTemperature()
{

  TestClassDefinition();
  SeeClassDefinition();

}


void TestClassDefinition()
{
  Decikelvin const decikelvin( 1. );
  Assert( fequal( decikelvin.GetValue(), 1. ) );
  Assert( fequal( decikelvin.GetConvertedValue(), 1.e-1 ) );
  Assert( fequal( decikelvin.GetFactor(), 1.e-1 ) );

  Kelvin const kelvin( 1. );
  Assert( fequal( kelvin.GetValue(), 1. ) );
  Assert( fequal( kelvin.GetConvertedValue(), 1. ) );
  Assert( fequal( kelvin.GetFactor(), 1. ) );

  long l = sizeof( Kelvin );
  long l2 = sizeof( Kilokelvin );

  Dekakelvin const dekakelvin( 1. );
  Assert( fequal( dekakelvin.GetValue(), 1. ) );
  Assert( fequal( dekakelvin.GetConvertedValue(), 10. ) );
  Assert( fequal( dekakelvin.GetFactor(), 10. ) );

  Celcius const celcius( 1. );
  Assert( fequal( celcius.GetValue(), 1. ) );
  Assert( fequal( celcius.GetConvertedValue(), 1. ) );
  Assert( fequal( celcius.GetFactor(), 1. ) );

}

void SeeClassDefinition()
{
  std::wcout << "-- Kelvin --" << std::endl;

  Decikelvin const decikelvin;
  std::wcout << decikelvin.GetSuffix() << std::endl;

  Kelvin const kelvin;
  std::wcout << kelvin.GetSuffix() << std::endl;

  Dekakelvin const dekakelvin;
  std::wcout << dekakelvin.GetSuffix() << std::endl;

  Celcius const celcius;
  std::wcout << celcius.GetSuffix() << std::endl;

}

