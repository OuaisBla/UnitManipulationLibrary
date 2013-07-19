
#include "stdafx.h"
#include "UnitVolume.h"


using namespace Unit;
using namespace Unit::SI;
using namespace Unit::NonSI;

//
//  Compile time definition.
//
typedef Product<Product<Nanometer,Millimeter>, Micrometer> Attocubicmeter2;
typedef Product<Meter,Product<Nanometer,Meter> > Nanocubicmeter2;
typedef Product<Product<Meter,Micrometer>,Meter> Microcubicmeter2;
typedef Product<Dekameter, Product<Decimeter,Millimeter> > Millicubicmeter2;
typedef Product<Meter,Product<Centimeter,Meter> > Centicubicmeter2;
typedef Product<Product<Decimeter,Meter>, Meter> Decicubicmeter2;
typedef Product<Product<Dekameter>,Decimeter> Dekacubicmeter2;
typedef Product<Meter,Product<Dekameter> > Hectocubicmeter2;
typedef Product<Hectometer,Product<Kilometer,Centimeter> > Kilocubicmeter2;
typedef Product<Meter,Product<Kilometer> > Megacubicmeter2;


static void TestClassDefinition();
static void SeeClassDefinition();
static void TestCompileTimeDefinition();
static void TestConversionConstructor();


void TestCubicMeter()
{

  TestClassDefinition();
  SeeClassDefinition();
  TestCompileTimeDefinition();
  TestConversionConstructor();

}


void TestClassDefinition()
{
  Femtocubicmeter const femtocubicmeter( 1. );
  Assert( fequal( femtocubicmeter.GetValue(), 1. ) );
  Assert( fequal( femtocubicmeter.GetFactor(), 1.e-45, 1.e-45 ) );

  Picocubicmeter const picocubicmeter( 1. );
  Assert( fequal( picocubicmeter.GetValue(), 1. ) );
  Assert( fequal( picocubicmeter.GetFactor(), 1.e-36, 1.e-36 ) );

  Nanocubicmeter const nanocubicmeter( 1. );
  Assert( fequal( nanocubicmeter.GetValue(), 1. ) );
  Assert( fequal( nanocubicmeter.GetFactor(), 1.e-27, 1.e-27 ) );

  Microcubicmeter const microcubicmeter( 1. );
  Assert( fequal( microcubicmeter.GetValue(), 1. ) );
  Assert( fequal( microcubicmeter.GetFactor(), 1.e-18, 1.e-18 ) );

  Millicubicmeter const millicubicmeter( 1. );
  Assert( fequal( millicubicmeter.GetValue(), 1. ) );
  Assert( fequal( millicubicmeter.GetFactor(), 1.e-9, 1.e-9 ) );

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
  Assert( fequal( kilocubicmeter.GetFactor(), 1.e9, 1.e9 ) );

  Megacubicmeter const megacubicmeter( 1. );
  Assert( fequal( megacubicmeter.GetValue(), 1. ) );
  Assert( fequal( megacubicmeter.GetFactor(), 1.e18, 1.e18 ) );

  Gigacubicmeter const gigacubicmeter( 1. );
  Assert( fequal( gigacubicmeter.GetValue(), 1. ) );
  Assert( fequal( gigacubicmeter.GetFactor(), 1.e27, 1.e27 ) );

  Teracubicmeter const teracubicmeter( 1. );
  Assert( fequal( teracubicmeter.GetValue(), 1. ) );
  Assert( fequal( teracubicmeter.GetFactor(), 1.e36, 1.e36 ) );

  Petacubicmeter const petacubicmeter( 1. );
  Assert( fequal( petacubicmeter.GetValue(), 1. ) );
  Assert( fequal( petacubicmeter.GetFactor(), 1.e45, 1.e45 ) );
}

void SeeClassDefinition()
{
  OutputLine( L"-- Cubicmeter --" );

  Femtocubicmeter const femtocubicmeter;
  OutputLine( femtocubicmeter.GetSuffix() );
  OutputLine( femtocubicmeter.GetSISuffix() );
  OutputLine( Femtocubicmeter::Suffix() );

  Picocubicmeter const picocubicmeter;
  OutputLine( picocubicmeter.GetSuffix() );
  OutputLine( picocubicmeter.GetSISuffix() );
  OutputLine( Picocubicmeter::Suffix() );

  Nanocubicmeter const nanocubicmeter;
  OutputLine( nanocubicmeter.GetSuffix() );
  OutputLine( nanocubicmeter.GetSISuffix() );
  OutputLine( Nanocubicmeter::Suffix() );

  Microcubicmeter const microcubicmeter;
  OutputLine( microcubicmeter.GetSuffix() );
  OutputLine( microcubicmeter.GetSISuffix() );
  OutputLine( Microcubicmeter::Suffix() );

  Millicubicmeter const millicubicmeter;
  OutputLine( millicubicmeter.GetSuffix() );
  OutputLine( millicubicmeter.GetSISuffix() );
  OutputLine( Millicubicmeter::Suffix() );

  Centicubicmeter const centicubicmeter;
  OutputLine( centicubicmeter.GetSuffix() );
  OutputLine( centicubicmeter.GetSISuffix() );
  OutputLine( Centicubicmeter::Suffix() );

  Decicubicmeter const decicubicmeter;
  OutputLine( decicubicmeter.GetSuffix() );
  OutputLine( decicubicmeter.GetSISuffix() );
  OutputLine( Decicubicmeter::Suffix() );

  Cubicmeter const cubicmeter;
  OutputLine( cubicmeter.GetSuffix() );
  OutputLine( cubicmeter.GetSISuffix() );
  OutputLine( Cubicmeter::Suffix() );
  Assert( cubicmeter.GetSuffix() == L"m³" );
  Assert( cubicmeter.GetSISuffix() == L"m³" );
  Assert( Cubicmeter::Suffix() == L"m³" );

  Dekacubicmeter const dekacubicmeter;
  OutputLine( dekacubicmeter.GetSuffix() );
  OutputLine( dekacubicmeter.GetSISuffix() );
  OutputLine( Dekacubicmeter::Suffix() );

  Hectocubicmeter const hectocubicmeter;
  OutputLine( hectocubicmeter.GetSuffix() );
  OutputLine( hectocubicmeter.GetSISuffix() );
  OutputLine( Hectocubicmeter::Suffix() );

  Kilocubicmeter const kilocubicmeter;
  OutputLine( kilocubicmeter.GetSuffix() );
  OutputLine( kilocubicmeter.GetSISuffix() );
  OutputLine( Kilocubicmeter::Suffix() );
  Assert( kilocubicmeter.GetSuffix() == L"km³" );
  Assert( kilocubicmeter.GetSISuffix() == L"km³" );
  Assert( Kilocubicmeter::Suffix() == L"km³" );

  Megacubicmeter const megacubicmeter;
  OutputLine( megacubicmeter.GetSuffix() );
  OutputLine( megacubicmeter.GetSISuffix() );
  OutputLine( Megacubicmeter::Suffix() );

  Gigacubicmeter const gigacubicmeter;
  OutputLine( gigacubicmeter.GetSuffix() );
  OutputLine( gigacubicmeter.GetSISuffix() );
  OutputLine( Gigacubicmeter::Suffix() );

  Teracubicmeter const teracubicmeter;
  OutputLine( teracubicmeter.GetSuffix() );
  OutputLine( teracubicmeter.GetSISuffix() );
  OutputLine( Teracubicmeter::Suffix() );

  Petacubicmeter const petacubicmeter;
  OutputLine( petacubicmeter.GetSuffix() );
  OutputLine( petacubicmeter.GetSISuffix() );
  OutputLine( Petacubicmeter::Suffix() );

}

void TestCompileTimeDefinition()
{
  Attocubicmeter const attocubicmeter = Micrometer( 1. ) * Micrometer( 1. ) * Micrometer( 1. );
  Assert( fequal( attocubicmeter.GetValue(), 1. ) );

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


  Attocubicmeter2 const attocubicmeter2 = attocubicmeter;
  Assert( fequal( attocubicmeter.GetFactor(), attocubicmeter2.GetFactor(), 1.e-45 ) );

  Nanocubicmeter2 const nanocubicmeter2 = nanocubicmeter;
  Assert( fequal( nanocubicmeter.GetFactor(), nanocubicmeter2.GetFactor(), 1.e-27 ) );

  Microcubicmeter2 const microcubicmeter2 = microcubicmeter;
  Assert( fequal( microcubicmeter.GetFactor(), microcubicmeter2.GetFactor(), 1.e-18 ) );

  Millicubicmeter2 const millicubicmeter2 = millicubicmeter;
  Assert( fequal( millicubicmeter.GetFactor(), millicubicmeter2.GetFactor(), 1.e-9 ) );

  Centicubicmeter2 const centicubicmeter2 = centicubicmeter;
  Assert( fequal( centicubicmeter.GetFactor(), centicubicmeter2.GetFactor() ) );

  Decicubicmeter2 const decicubicmeter2 = decicubicmeter;
  Assert( fequal( decicubicmeter.GetFactor(), decicubicmeter2.GetFactor() ) );

  Dekacubicmeter2 const dekacubicmeter2 = dekacubicmeter;
  Assert( fequal( dekacubicmeter.GetFactor(), dekacubicmeter2.GetFactor() ) );

  Hectocubicmeter2 const hectocubicmeter2 = hectocubicmeter;
  Assert( fequal( hectocubicmeter.GetFactor(), hectocubicmeter2.GetFactor() ) );

  Kilocubicmeter2 const kilocubicmeter2 = kilocubicmeter;
  Assert( fequal( kilocubicmeter.GetFactor(), kilocubicmeter2.GetFactor(), 1.e9 ) );

  Megacubicmeter2 const megacubicmeter2 = megacubicmeter;
  Assert( fequal( megacubicmeter.GetFactor(), megacubicmeter2.GetFactor(), 1.e18 ) );

}

void TestConversionConstructor()
{

  //1 m3 = 1,000,000 cm3
  Centicubicmeter const _rep1 = Cubicmeter( 1. );
  Scalar const rep1 = _rep1.GetValue();
  Assert( fequal( rep1, 1.e6, 1.e6 ) );

  Assert( Centicubicmeter( rep1 ) == Cubicmeter( 1. ) );

  //1,000,000 - 1 cm3 < 1 m3 
  Assert( ( Centicubicmeter( rep1 ) - Centicubicmeter( 1 ) ) < Cubicmeter( 1. ) );

  Decicubicmeter decicubicmeter = Liter( 1.0 );
  Assert( fequal( decicubicmeter.GetValue(), 1.0 ) );

  Cubicmeter cubicmeter = Liter( 1.0 );
  Assert( fequal( cubicmeter.GetValue(), 0.001 ) );

}

