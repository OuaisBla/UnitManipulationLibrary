
#include "stdafx.h"
#include "UnitArea.h"


using namespace Unit;
using namespace Unit::SI;


//
//  Compile time definition.
//
typedef Product<Nanometer,Micrometer> Femtosquaremeter2;
typedef Product<Nanometer,Meter> Nanosquaremeter2;
typedef Product<Meter,Micrometer> Microsquaremeter2;
typedef Product<Decimeter,Centimeter> Millisquaremeter2;
typedef Product<Centimeter,Meter> Centisquaremeter2;
typedef Product<Decimeter,Meter> Decisquaremeter2;
typedef Product<Dekameter,Meter> Dekasquaremeter2;
typedef Product<Dekameter> Hectosquaremeter2;
typedef Product<Kilometer,Meter> Kilosquaremeter2;
typedef Product<Kilometer> Megasquaremeter2;



static void TestClassDefinition();
static void SeeClassDefinition();
static void TestCompileTimeDefinition();
static void TestConversionConstructor();
static void TestConversionAssignmentOperator();
static void TestCompileTimeConversionConstructor();
static void TestCompileTimeConversionAssignmentOperator();

void TestSquareMeter()
{

  TestClassDefinition();
  SeeClassDefinition();
  TestCompileTimeDefinition();
  TestConversionConstructor();
  TestConversionAssignmentOperator();
  TestCompileTimeConversionConstructor();
  TestCompileTimeConversionAssignmentOperator();

}


void TestClassDefinition()
{
  Femtosquaremeter const femtosquaremeter( 1. );
  Assert( fequal( femtosquaremeter.GetValue(), 1. ) );
  Assert( fequal( femtosquaremeter.GetFactor(), 1.e-30 ) );

  Picosquaremeter const picosquaremeter( 1. );
  Assert( fequal( picosquaremeter.GetValue(), 1. ) );
  Assert( fequal( picosquaremeter.GetFactor(), 1.e-24 ) );

  Nanosquaremeter const nanosquaremeter( 1. );
  Assert( fequal( nanosquaremeter.GetValue(), 1. ) );
  Assert( fequal( nanosquaremeter.GetFactor(), 1.e-18 ) );

  Microsquaremeter const microsquaremeter( 1. );
  Assert( fequal( microsquaremeter.GetValue(), 1. ) );
  Assert( fequal( microsquaremeter.GetFactor(), 1.e-12 ) );

  Millisquaremeter const millisquaremeter( 1. );
  Assert( fequal( millisquaremeter.GetValue(), 1. ) );
  Assert( fequal( millisquaremeter.GetFactor(), 1.e-6 ) );

  Centisquaremeter const centisquaremeter( 1. );
  Assert( fequal( centisquaremeter.GetValue(), 1. ) );
  Assert( fequal( centisquaremeter.GetFactor(), 1.e-4 ) );

  Decisquaremeter const decisquaremeter( 1. );
  Assert( fequal( decisquaremeter.GetValue(), 1. ) );
  Assert( fequal( decisquaremeter.GetFactor(), 1.e-2 ) );

  Squaremeter const squaremeter( 1. );
  Assert( fequal( squaremeter.GetValue(), 1. ) );
  Assert( fequal( squaremeter.GetFactor(), 1. ) );

  Dekasquaremeter const dekasquaremeter( 1. );
  Assert( fequal( dekasquaremeter.GetValue(), 1. ) );
  Assert( fequal( dekasquaremeter.GetFactor(), 1.e2 ) );

  Hectosquaremeter const hectosquaremeter( 1. );
  Assert( fequal( hectosquaremeter.GetValue(), 1. ) );
  Assert( fequal( hectosquaremeter.GetFactor(), 1.e4 ) );

  Kilosquaremeter const kilosquaremeter( 1. );
  Assert( fequal( kilosquaremeter.GetValue(), 1. ) );
  Assert( fequal( kilosquaremeter.GetFactor(), 1.e6 ) );

  Megasquaremeter const megasquaremeter( 1. );
  Assert( fequal( megasquaremeter.GetValue(), 1. ) );
  Assert( fequal( megasquaremeter.GetFactor(), 1.e12 ) );

  Gigasquaremeter const gigasquaremeter( 1. );
  Assert( fequal( gigasquaremeter.GetValue(), 1. ) );
  Assert( fequal( gigasquaremeter.GetFactor(), 1.e18 ) );

  Terasquaremeter const terasquaremeter( 1. );
  Assert( fequal( terasquaremeter.GetValue(), 1. ) );
  Assert( fequal( terasquaremeter.GetFactor(), 1.e24 ) );

  Petasquaremeter const petasquaremeter( 1. );
  Assert( fequal( petasquaremeter.GetValue(), 1. ) );
  Assert( fequal( petasquaremeter.GetFactor(), 1.e30 ) );
}

void SeeClassDefinition()
{
  OutputLine( L"-- Squaremeter --" );

  Femtosquaremeter const femtosquaremeter;
  OutputLine( femtosquaremeter.GetSuffix() );

  Picosquaremeter const picosquaremeter;
  OutputLine( picosquaremeter.GetSuffix() );

  Nanosquaremeter const nanosquaremeter;
  OutputLine( nanosquaremeter.GetSuffix() );

  Microsquaremeter const microsquaremeter;
  OutputLine( microsquaremeter.GetSuffix() );

  Millisquaremeter const millisquaremeter;
  OutputLine( millisquaremeter.GetSuffix() );

  Centisquaremeter const centisquaremeter;
  OutputLine( centisquaremeter.GetSuffix() );

  Decisquaremeter const decisquaremeter;
  OutputLine( decisquaremeter.GetSuffix() );

  Squaremeter const squaremeter;
  OutputLine( squaremeter.GetSuffix() );

  Dekasquaremeter const dekasquaremeter;
  OutputLine( dekasquaremeter.GetSuffix() );

  Hectosquaremeter const hectosquaremeter;
  OutputLine( hectosquaremeter.GetSuffix() );

  Kilosquaremeter const kilosquaremeter;
  OutputLine( kilosquaremeter.GetSuffix() );

  Megasquaremeter const megasquaremeter;
  OutputLine( megasquaremeter.GetSuffix() );

  Gigasquaremeter const gigasquaremeter;
  OutputLine( gigasquaremeter.GetSuffix() );

  Terasquaremeter const terasquaremeter;
  OutputLine( terasquaremeter.GetSuffix() );

  Petasquaremeter const petasquaremeter;
  OutputLine( petasquaremeter.GetSuffix() );

}

void TestCompileTimeDefinition()
{
  Femtosquaremeter const femtosquaremeter = Nanometer( 1. ) * Micrometer( 1. );
  Assert( fequal( femtosquaremeter.GetValue(), 1. ) );

  Nanosquaremeter const nanosquaremeter = Nanometer( 1. ) * Meter( 1. );
  Assert( fequal( nanosquaremeter.GetValue(), 1. ) );

  Microsquaremeter const microsquaremeter = Meter( 1. ) * Micrometer( 1. );
  Assert( fequal( microsquaremeter.GetValue(), 1. ) );

  Millisquaremeter const millisquaremeter = Decimeter( 1. ) * Centimeter( 1. );
  Assert( fequal( millisquaremeter.GetValue(), 1. ) );

  Centisquaremeter const centisquaremeter = Centimeter( 1. ) * Meter( 1. );
  Assert( fequal( centisquaremeter.GetValue(), 1. ) );

  Decisquaremeter const decisquaremeter = Decimeter( 1. ) * Meter( 1. );
  Assert( fequal( decisquaremeter.GetValue(), 1. ) );

  Squaremeter const squaremeter = Centimeter( 1. ) * Hectometer( 1. );
  Assert( fequal( squaremeter.GetValue(), 1. ) );

  Dekasquaremeter const dekasquaremeter = Dekameter( 1. ) * Meter( 1. );
  Assert( fequal( dekasquaremeter.GetValue(), 1. ) );

  Hectosquaremeter const hectosquaremeter = Dekameter( 1. ) * Dekameter( 1. );
  Assert( fequal( hectosquaremeter.GetValue(), 1. ) );

  Kilosquaremeter const kilosquaremeter = Kilometer( 1. ) * Meter( 1. );
  Assert( fequal( kilosquaremeter.GetValue(), 1. ) );

  Megasquaremeter const megasquaremeter = Kilometer( 1. ) * Kilometer( 1. );
  Assert( fequal( megasquaremeter.GetValue(), 1. ) );


  Femtosquaremeter2 const femtosquaremeter2 = femtosquaremeter;
  Assert( fequal( femtosquaremeter.GetFactor(), femtosquaremeter2.GetFactor() ) );

  Nanosquaremeter2 const nanosquaremeter2 = nanosquaremeter;
  Assert( fequal( nanosquaremeter.GetFactor(), nanosquaremeter2.GetFactor() ) );

  Microsquaremeter2 const microsquaremeter2 = microsquaremeter;
  Assert( fequal( microsquaremeter.GetFactor(), microsquaremeter2.GetFactor() ) );

  Millisquaremeter2 const millisquaremeter2 = millisquaremeter;
  Assert( fequal( millisquaremeter.GetFactor(), millisquaremeter2.GetFactor() ) );

  Centisquaremeter2 const centisquaremeter2 = centisquaremeter;
  Assert( fequal( centisquaremeter.GetFactor(), centisquaremeter2.GetFactor() ) );

  Decisquaremeter2 const decisquaremeter2 = decisquaremeter;
  Assert( fequal( decisquaremeter.GetFactor(), decisquaremeter2.GetFactor() ) );

  Dekasquaremeter2 const dekasquaremeter2 = dekasquaremeter;
  Assert( fequal( dekasquaremeter.GetFactor(), dekasquaremeter2.GetFactor() ) );

  Hectosquaremeter2 const hectosquaremeter2 = hectosquaremeter;
  Assert( fequal( hectosquaremeter.GetFactor(), hectosquaremeter2.GetFactor() ) );

  Kilosquaremeter2 const kilosquaremeter2 = kilosquaremeter;
  Assert( fequal( kilosquaremeter.GetFactor(), kilosquaremeter2.GetFactor() ) );

  Megasquaremeter2 const megasquaremeter2 = megasquaremeter;
  Assert( fequal( megasquaremeter.GetFactor(), megasquaremeter2.GetFactor() ) );

}

//
//  Source : http://dbhs.wvusd.k12.ca.us/Metric/Metric-Square&Cubic-Units.html
//
void TestConversionConstructor()
{

  //1) Convert 4.26 x 10e4 m2 to km2 
  Kilosquaremeter const _rep1 = Squaremeter( 4.260e4 );
  Scalar rep1 = _rep1.GetValue(); //4.62 x 10e-2

  //2) Convert 3.20 x 10e10 fm2 to cm2. 
  Centisquaremeter const _rep2 = Femtosquaremeter( 3.2e10 );
  Scalar const rep2 = _rep2.GetValue(); //3.20 x 10e-16 

  //3) Convert the answer in number 2 to Mm2 
  Millisquaremeter const _rep3_1 = Femtosquaremeter( 3.2e10 );
  Millisquaremeter const _rep3_2 = _rep2;
  Scalar const rep3_1 = _rep3_1.GetValue(); //3.20 x 10e-14
  Scalar const rep3_2 = _rep3_2.GetValue(); //3.20 x 10e-14

}

void TestConversionAssignmentOperator()
{

  //1) Convert 4.26 x 10e4 m2 to km2 
  Kilosquaremeter _rep1;
  _rep1 = Squaremeter( 4.260e4 );
  Scalar rep1 = _rep1.GetValue();

  //2) Convert 3.20 x 10e10 fm2 to cm2. 
  Centisquaremeter _rep2;
  _rep2 = Femtosquaremeter( 3.2e10 );
  Scalar const rep2 = _rep2.GetValue();

  //3) Convert the answer in number 2 to Mm2 
  Millisquaremeter _rep3_1;
  _rep3_1 = Femtosquaremeter( 3.2e10 );
  Millisquaremeter _rep3_2;
  _rep3_2 = _rep2;
  Scalar const rep3_1 = _rep3_1.GetValue();
  Scalar const rep3_2 = _rep3_2.GetValue();

}

void TestCompileTimeConversionConstructor()
{

  //1) Convert 4.26 x 10e4 m2 to km2 
  Kilosquaremeter2 const _rep1 = Squaremeter( 4.260e4 );
  Scalar rep1 = _rep1.GetValue();

  //2) Convert 3.20 x 10e10 fm2 to cm2. 
  Centisquaremeter2 const _rep2 = Femtosquaremeter2( 3.2e10 );
  Scalar const rep2 = _rep2.GetValue();

  //3) Convert the answer in number 2 to Mm2 
  Millisquaremeter2 const _rep3_1 = Femtosquaremeter2( 3.2e10 );
  Millisquaremeter2 const _rep3_2 = _rep2;
  Scalar const rep3_1 = _rep3_1.GetValue();
  Scalar const rep3_2 = _rep3_2.GetValue();

}

void TestCompileTimeConversionAssignmentOperator()
{

  //1) Convert 4.26 x 10e4 m2 to km2 
  Kilosquaremeter2 _rep1;
  _rep1 = Squaremeter( 4.260e4 );
  Scalar rep1 = _rep1.GetValue();

  //2) Convert 3.20 x 10e10 fm2 to cm2. 
  Centisquaremeter2 _rep2;
  _rep2 = Femtosquaremeter2( 3.2e10 );
  Scalar const rep2 = _rep2.GetValue();

  //3) Convert the answer in number 2 to Mm2 
  Millisquaremeter2 _rep3_1;
  _rep3_1 = Femtosquaremeter2( 3.2e10 );
  Millisquaremeter2 _rep3_2;
  _rep3_2 = _rep2;
  Scalar const rep3_1 = _rep3_1.GetValue();
  Scalar const rep3_2 = _rep3_2.GetValue();

}
