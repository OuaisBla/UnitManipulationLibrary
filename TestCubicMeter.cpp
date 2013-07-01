
#include "stdafx.h"
#include "UnitVolume.h"
#include <iostream>


using namespace Unit;
using namespace Unit::SI;


//
//  Compile time definition.
//
typedef Product<Product<Nanometer,Millimeter>, Millimeter> Femtocubicmeter2;
typedef Product<Meter,Product<Nanometer,Meter> > Nanocubicmeter2;
typedef Product<Product<Meter,Micrometer>,Meter> Microcubicmeter2;
typedef Product<Dekameter, Product<Decimeter,Millimeter> > Millicubicmeter2;
typedef Product<Meter,Product<Centimeter,Meter> > Centicubicmeter2;
typedef Product<Product<Decimeter,Meter>, Meter> Decicubicmeter2;
typedef Product<Product<Dekameter>,Decimeter> Dekacubicmeter2;
typedef Product<Meter,Product<Dekameter> > Hectocubicmeter2;
typedef Product<Hectometer,Product<Kilometer,Centimeter> > Kilocubicmeter2;
typedef Product<Meter,Product<Kilometer> > Megacubicmeter2;



void Assert( bool );
bool fequal( double, double );


static void TestClassDefinition();
static void SeeClassDefinition();
static void TestCompileTimeDefinition();
static void TestConversionConstructor();
static void TestConversionAssignmentOperator();
static void TestCompileTimeConversionConstructor();
static void TestCompileTimeConversionAssignmentOperator();

void TestCubicMeter()
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
  Femtocubicmeter const femtocubicmeter( 1. );
  Assert( fequal( femtocubicmeter.GetValue(), 1. ) );
  Assert( fequal( femtocubicmeter.GetFactor(), 1.e-45 ) );

  Picocubicmeter const picocubicmeter( 1. );
  Assert( fequal( picocubicmeter.GetValue(), 1. ) );
  Assert( fequal( picocubicmeter.GetFactor(), 1.e-36 ) );

  Nanocubicmeter const nanocubicmeter( 1. );
  Assert( fequal( nanocubicmeter.GetValue(), 1. ) );
  Assert( fequal( nanocubicmeter.GetFactor(), 1.e-27 ) );

  Microcubicmeter const microcubicmeter( 1. );
  Assert( fequal( microcubicmeter.GetValue(), 1. ) );
  Assert( fequal( microcubicmeter.GetFactor(), 1.e-18 ) );

  Millicubicmeter const millicubicmeter( 1. );
  Assert( fequal( millicubicmeter.GetValue(), 1. ) );
  Assert( fequal( millicubicmeter.GetFactor(), 1.e-9 ) );

  Centicubicmeter const centicubicmeter( 1. );
  Assert( fequal( centicubicmeter.GetValue(), 1. ) );
  Assert( fequal( centicubicmeter.GetFactor(), 1.e-6 ) );

  Decicubicmeter const decicubicmeter( 1. );
  Assert( fequal( decicubicmeter.GetValue(), 1. ) );
  Assert( fequal( decicubicmeter.GetFactor(), 1.e-3 ) );

  Cubicmeter const cubicmeter( 1. );
  Assert( fequal( cubicmeter.GetValue(), 1. ) );
  Assert( fequal( cubicmeter.GetFactor(), 1. ) );

  Dekacubicmeter const dekacubicmeter( 1. );
  Assert( fequal( dekacubicmeter.GetValue(), 1. ) );
  Assert( fequal( dekacubicmeter.GetFactor(), 1.e3 ) );

  Hectocubicmeter const hectocubicmeter( 1. );
  Assert( fequal( hectocubicmeter.GetValue(), 1. ) );
  Assert( fequal( hectocubicmeter.GetFactor(), 1.e6 ) );

  Kilocubicmeter const kilocubicmeter( 1. );
  Assert( fequal( kilocubicmeter.GetValue(), 1. ) );
  Assert( fequal( kilocubicmeter.GetFactor(), 1.e9 ) );

  Megacubicmeter const megacubicmeter( 1. );
  Assert( fequal( megacubicmeter.GetValue(), 1. ) );
  Assert( fequal( megacubicmeter.GetFactor(), 1.e18 ) );

  Gigacubicmeter const gigacubicmeter( 1. );
  Assert( fequal( gigacubicmeter.GetValue(), 1. ) );
  Assert( fequal( gigacubicmeter.GetFactor(), 1.e27 ) );

  Teracubicmeter const teracubicmeter( 1. );
  Assert( fequal( teracubicmeter.GetValue(), 1. ) );
  Assert( fequal( teracubicmeter.GetFactor(), 1.e36 ) );

  Petacubicmeter const petacubicmeter( 1. );
  Assert( fequal( petacubicmeter.GetValue(), 1. ) );
//  Assert( fequal( petacubicmeter.GetFactor(), 1.e45 ) );
}

void SeeClassDefinition()
{
  std::wcout << "-- Cubicmeter --" << std::endl;

  Femtocubicmeter const femtocubicmeter;
  std::wcout << femtocubicmeter.GetSuffix() << std::endl;

  Picocubicmeter const picocubicmeter;
  std::wcout << picocubicmeter.GetSuffix() << std::endl;

  Nanocubicmeter const nanocubicmeter;
  std::wcout << nanocubicmeter.GetSuffix() << std::endl;

  Microcubicmeter const microcubicmeter;
  std::wcout << microcubicmeter.GetSuffix() << std::endl;

  Millicubicmeter const millicubicmeter;
  std::wcout << millicubicmeter.GetSuffix() << std::endl;

  Centicubicmeter const centicubicmeter;
  std::wcout << centicubicmeter.GetSuffix() << std::endl;

  Decicubicmeter const decicubicmeter;
  std::wcout << decicubicmeter.GetSuffix() << std::endl;

  Cubicmeter const cubicmeter;
  std::wcout << cubicmeter.GetSuffix() << std::endl;

  Dekacubicmeter const dekacubicmeter;
  std::wcout << dekacubicmeter.GetSuffix() << std::endl;

  Hectocubicmeter const hectocubicmeter;
  std::wcout << hectocubicmeter.GetSuffix() << std::endl;

  Kilocubicmeter const kilocubicmeter;
  std::wcout << kilocubicmeter.GetSuffix() << std::endl;

  Megacubicmeter const megacubicmeter;
  std::wcout << megacubicmeter.GetSuffix() << std::endl;

  Gigacubicmeter const gigacubicmeter;
  std::wcout << gigacubicmeter.GetSuffix() << std::endl;

  Teracubicmeter const teracubicmeter;
  std::wcout << teracubicmeter.GetSuffix() << std::endl;

  Petacubicmeter const petacubicmeter;
  std::wcout << petacubicmeter.GetSuffix() << std::endl;

}

void TestCompileTimeDefinition()
{
  Femtocubicmeter const femtocubicmeter = Millimeter( 1. ) * Nanometer( 1. ) * Millimeter( 1. );
  Assert( fequal( femtocubicmeter.GetValue(), 1. ) );

  Nanocubicmeter const nanocubicmeter = Nanometer( 1. ) * Meter( 1. ) * Meter( 1. );
  Assert( fequal( nanocubicmeter.GetValue(), 1. ) );

  Microcubicmeter const microcubicmeter = Meter( 1. ) * Micrometer( 1. ) * Meter( 1. );
  Assert( fequal( microcubicmeter.GetValue(), 1. ) );

  Millicubicmeter const millicubicmeter = Decimeter( 1. ) * Centimeter( 1. ) * Meter( 1. );
  Assert( fequal( millicubicmeter.GetValue(), 1. ) );

  Centicubicmeter const centicubicmeter = Centimeter( 1. ) * Meter( 1. ) * Meter( 1. );
  Assert( fequal( centicubicmeter.GetValue(), 1. ) );

  Decicubicmeter const decicubicmeter = Decimeter( 1. ) * Meter( 1. ) * Meter( 1. );
  Assert( fequal( decicubicmeter.GetValue(), 1. ) );

  Cubicmeter const cubicmeter = Centimeter( 1. ) * Hectometer( 1. ) * Meter( 1. );
  Assert( fequal( cubicmeter.GetValue(), 1. ) );

  Dekacubicmeter const dekacubicmeter = Dekameter( 1. ) * Meter( 1. ) * Meter( 1. );
  Assert( fequal( dekacubicmeter.GetValue(), 1. ) );

  Hectocubicmeter const hectocubicmeter = Dekameter( 1. ) * Dekameter( 1. ) * Meter( 1. );
  Assert( fequal( hectocubicmeter.GetValue(), 1. ) );

  Kilocubicmeter const kilocubicmeter = Kilometer( 1. ) * Meter( 1. ) * Meter( 1. );
  Assert( fequal( kilocubicmeter.GetValue(), 1. ) );

  Megacubicmeter const megacubicmeter = Kilometer( 1. ) * Kilometer( 1. ) * Meter( 1. );
  Assert( fequal( megacubicmeter.GetValue(), 1. ) );


  Femtocubicmeter2 const femtocubicmeter2 = femtocubicmeter;
  Femtocubicmeter2 const femtocubicmeter22 = femtocubicmeter2;
  Assert( fequal( femtocubicmeter.GetFactor(), femtocubicmeter2.GetFactor() ) );

  Nanocubicmeter2 const nanocubicmeter2 = nanocubicmeter;
  Assert( fequal( nanocubicmeter.GetFactor(), nanocubicmeter2.GetFactor() ) );

  Microcubicmeter2 const microcubicmeter2 = microcubicmeter;
  Assert( fequal( microcubicmeter.GetFactor(), microcubicmeter2.GetFactor() ) );

  Millicubicmeter2 const millicubicmeter2 = millicubicmeter;
  Assert( fequal( millicubicmeter.GetFactor(), millicubicmeter2.GetFactor() ) );

  Centicubicmeter2 const centicubicmeter2 = centicubicmeter;
  Assert( fequal( centicubicmeter.GetFactor(), centicubicmeter2.GetFactor() ) );

  Decicubicmeter2 const decicubicmeter2 = decicubicmeter;
  Assert( fequal( decicubicmeter.GetFactor(), decicubicmeter2.GetFactor() ) );

  Dekacubicmeter2 const dekacubicmeter2 = dekacubicmeter;
  Assert( fequal( dekacubicmeter.GetFactor(), dekacubicmeter2.GetFactor() ) );

  Hectocubicmeter2 const hectocubicmeter2 = hectocubicmeter;
  Assert( fequal( hectocubicmeter.GetFactor(), hectocubicmeter2.GetFactor() ) );

  Kilocubicmeter2 const kilocubicmeter2 = kilocubicmeter;
  Assert( fequal( kilocubicmeter.GetFactor(), kilocubicmeter2.GetFactor() ) );

  Megacubicmeter2 const megacubicmeter2 = megacubicmeter;
  Assert( fequal( megacubicmeter.GetFactor(), megacubicmeter2.GetFactor() ) );

}

//
//  Source : http://dbhs.wvusd.k12.ca.us/Metric/Metric-Cubic&Cubic-Units.html
//
void TestConversionConstructor()
{

  //1) Convert 4.26 x 10e4 m2 to km2 
  Cubicmeter const _rep1 = Centicubicmeter( 4310. );
  Scalar const rep1 = _rep1.GetValue(); //4.31e-3

  //2) Convert 3.20 x 10e10 fm2 to cm2. 
  Millicubicmeter const _rep2 = Centicubicmeter( 86.3 );
  Scalar const rep2 = _rep2.GetValue(); //8.63e4

  //3) Convert the answer in number 2 to Mm2 
  Decicubicmeter const _rep3_1 = Millicubicmeter( 5.94e10 );
  Scalar const rep3_1 = _rep3_1.GetValue();

}

void TestConversionAssignmentOperator()
{


}

void TestCompileTimeConversionConstructor()
{


}

void TestCompileTimeConversionAssignmentOperator()
{

 
}

