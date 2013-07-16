
#include "stdafx.h"
#include "UnitTemperature.h"


using namespace Unit;
using namespace Unit::SI;
using namespace Unit::NonSI;


static void TestClassDefinition();
static void SeeClassDefinition();
static void TestComparaisonOperators();



void TestTemperature()
{

  TestClassDefinition();
  SeeClassDefinition();
  TestComparaisonOperators();

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
  OutputLine( L"-- Kelvin --" );

  Decikelvin const decikelvin;
  OutputLine( decikelvin.GetSuffix() );

  Kelvin const kelvin;
  OutputLine( kelvin.GetSuffix() );

  Dekakelvin const dekakelvin;
  OutputLine( dekakelvin.GetSuffix() );

  Celsius const celsius;
  OutputLine( celsius.GetSuffix() );
  OutputLine( Celsius::Suffix() );

}

void TestComparaisonOperators()
{

  Celsius const unit_0_celsius( 0. );
  Celsius const unit_100_celsius( 100. );
  Kelvin const unit_0_celsius_in_kelvin = unit_0_celsius;
  Kelvin const unit_100_celsius_in_kelvin = unit_0_celsius_in_kelvin + Kelvin( 100. );
  Kelvin const unit_0_kelvin;

  Assert( unit_0_celsius_in_kelvin == unit_0_celsius && unit_0_celsius == unit_0_celsius_in_kelvin );
  Assert( unit_0_celsius != unit_100_celsius_in_kelvin );
  Assert( unit_0_celsius < unit_100_celsius_in_kelvin );
  Assert( unit_0_celsius > unit_0_kelvin );
  Assert( unit_0_celsius <= unit_100_celsius_in_kelvin );
  Assert( unit_0_celsius >= unit_0_kelvin );

}
