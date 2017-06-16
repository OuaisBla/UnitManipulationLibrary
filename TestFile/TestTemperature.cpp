
#include "TestHelper.h"
#include "UnitTemperature.h"


using namespace Unit;
using namespace Unit::SI;
using namespace Unit::NonSI;


using Unit::Types::Scalar;

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

  Fahrenheit const fahrenheit( 1. );
  Assert( fequal( fahrenheit.GetValue(), 1. ) );
  Assert( fequal( fahrenheit.GetConvertedValue(), 255.9277777777778 ) );
  Assert( fequal( fahrenheit.GetFactor(), 0.55555555555555555555555555555556 ) );


  Celsius const CelsiusToCelsius( Celsius( 1. ) );
  Assert( fequal( CelsiusToCelsius.GetValue(), 1. ) );

  Celsius const KelvinToCelsius( Kelvin( 1.) );
  Assert( fequal( KelvinToCelsius.GetValue(), -272.15 ) );

  Celsius const FahrenheitToCelsius( Fahrenheit( 1.) );
  Assert( fequal( FahrenheitToCelsius.GetValue(), -17.22222222222222 ) );

  Kelvin const CelsiusToKelvin( Celsius( 0.) );
  Assert( fequal( CelsiusToKelvin.GetValue(), 273.15 ) );

  Kelvin const KelvinToKelvin( Kelvin( 1. ) );
  Assert( fequal( KelvinToKelvin.GetValue(), 1. ) );

  Kelvin const FahrenheitToKelvin( Fahrenheit( 1. ) );
  Assert( fequal( FahrenheitToKelvin.GetValue(), 255.92777777777778 ) );

  Fahrenheit const FahrenheitToFahrenheit( Fahrenheit( 1.) );
  Assert( fequal( FahrenheitToFahrenheit.GetValue(), 1. ) );

  Fahrenheit const KelvinToFahrenheit( Kelvin( 1. ) );
  Assert( fequal( KelvinToFahrenheit.GetValue(), -457.87 ) );

  Fahrenheit const CelsiusToFahrenheit( Celsius( 1. ) );
  Assert( fequal( CelsiusToFahrenheit.GetValue(), 33.8 ) );


}

void SeeClassDefinition()
{
  OutputLine( L"-- Kelvin --" );

  Decikelvin const decikelvin;
  OutputLine( decikelvin.GetSuffix() );
  OutputLine( decikelvin.GetSISuffix() );
  OutputLine( Decikelvin::Suffix() );

  Kelvin const kelvin;
  OutputLine( kelvin.GetSuffix() );
  OutputLine( kelvin.GetSISuffix() );
  OutputLine( Kelvin::Suffix() );
  Assert( kelvin.GetSuffix() == L"K" );
  Assert( kelvin.GetSISuffix() == L"K" );
  Assert( Kelvin::Suffix() == L"K" );

  Dekakelvin const dekakelvin;
  OutputLine( dekakelvin.GetSuffix() );
  OutputLine( dekakelvin.GetSISuffix() );
  OutputLine( Dekakelvin::Suffix() );

  Celsius const celsius;
  OutputLine( celsius.GetSuffix() );
  OutputLine( celsius.GetSISuffix() );
  OutputLine( Celsius::Suffix() );
  Assert( celsius.GetSuffix() == L"°C" );
  Assert( celsius.GetSISuffix() == L"K" );
  Assert( Celsius::Suffix() == L"°C" );

  Fahrenheit const fahrenheit;
  OutputLine( fahrenheit.GetSuffix() );
  OutputLine( fahrenheit.GetSISuffix() );
  OutputLine( Fahrenheit::Suffix() );
  Assert( fahrenheit.GetSuffix() == L"°F" );
  Assert( fahrenheit.GetSISuffix() == L"K" );
  Assert( Fahrenheit::Suffix() == L"°F" );

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
