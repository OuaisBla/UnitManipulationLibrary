
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


void TestTemperature()
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

  Celsius const celsius( 1. );
  Assert( fequal( celsius.GetValue(), 1. ) );
  Assert( fequal( celsius.GetConvertedValue(), 274.15 ) );
  Assert( fequal( celsius.GetFactor(), 1. ) );

  Celsius const celciusToCelcius( Celsius( 0. ) );
  Assert( fequal( celciusToCelcius.GetValue(), 0. ) );

  Celsius const KelvinToCelcius( Kelvin( 0.) );
  Assert( fequal( KelvinToCelcius.GetValue(), -273.15 ) );

  Kelvin const CelciusToKelvin( Celsius( 0.) );
  Assert( fequal( CelciusToKelvin.GetValue(), 273.15 ) );

  Kelvin const KelvinToKelvin( Kelvin( 0. ) );
  Assert( fequal( KelvinToKelvin.GetValue(), 0. ) );


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

  Celsius const celsius;
  std::wcout << celsius.GetSuffix() << std::endl;
  std::wcout << Celsius::Suffix() << std::endl;

}

