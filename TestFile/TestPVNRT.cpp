
#include "TestHelper.h"
#include "UnitVolume.h"
#include "UnitPressure.h"
#include "UnitEnergy.h"
#include "UnitPower.h"
#include "UnitElectricPotential.h"
#include "UnitElectricCurrent.h"
#include "UnitAmountOfSubstance.h"
#include "UnitTemperature.h"


using namespace Unit;
using namespace Unit::SI;

using Unit::Types::Scalar;


//                 /
//                 |  
//                 |  P: Pressure (Pascal) 
//                 |  V: Volume (m³)
//    PV = nRT    <   n: Amount of substance (mol)
//                 |  R: 8.31415 J x mol-1 x K-1
//                 |  T: Temperature (Kelvin)
//                 |
//                 \ 


typedef Product<Joule,Product<Mole, Kelvin>::Invert> RType;
typedef Product<Watt,Ampere::Invert> Volt3;



typedef Product<Product<Meter,Kilogram>,Product<Second>::Invert> Newton2;
typedef Product<Newton2,Product<Meter>::Invert> Pascal2;
typedef Product<Newton2,Meter> Joule2;
typedef Product<Joule2,Second::Invert> Watt2;
typedef Product<Watt2,Ampere::Invert> Volt2;


typedef Product<Product<Meter,Kilogram>,Product<Second>::Invert> Newton2;
typedef Product<Product<Meter,Kilogram>,Product<Second,Meter>::Invert> Pascal3;


void TestPV_equals_NRT()
{
  OutputLine( L"-- Test PV equals NRT -- " );

  RType const R( 8.3144621 );


  Pascal pressure( 101300. );

  Mole air( .0624 );

  Kelvin temperature( 292.87476745575 );
  Cubicmeter spaceneeded( .0015 );

  Pascal2 p0;

  OutputLine( Types::String( L"Newton: " ) + Newton().GetSuffix() );
  OutputLine( Types::String( L"Newton: " ) + Newton().GetSISuffix() );
  OutputLine( Types::String( L"Newton2: " ) + Newton2().GetSuffix() );
  OutputLine( Types::String( L"Newton2: " ) + Newton2().GetSISuffix() );
  OutputLine( Types::String( L"Pascal: " ) + Pascal().GetSuffix() );
  OutputLine( Types::String( L"Pascal: " ) + Pascal().GetSISuffix() );
  OutputLine( Types::String( L"Pascal2: " ) + Pascal2().GetSuffix() );
  OutputLine( Types::String( L"Pascal2: " ) + Pascal2().GetSISuffix() );
  OutputLine( Types::String( L"Joule: " ) + Joule().GetSuffix() );
  OutputLine( Types::String( L"Joule: " ) + Joule().GetSISuffix() );
  OutputLine( Types::String( L"Joule2: " ) + Joule2().GetSuffix() );
  OutputLine( Types::String( L"Joule2: " ) + Joule2().GetSISuffix() );
  OutputLine( Types::String( L"Watt: " ) + Watt().GetSuffix() );
  OutputLine( Types::String( L"Watt: " ) + Watt().GetSISuffix() );
  OutputLine( Types::String( L"Watt2: " ) + Watt2().GetSuffix() );
  OutputLine( Types::String( L"Watt2: " ) + Watt2().GetSISuffix() );
  OutputLine( Types::String( L"Volt: " ) + Volt().GetSuffix() );
  OutputLine( Types::String( L"Volt: " ) + Volt().GetSISuffix() );
  OutputLine( Types::String( L"Volt2: " ) + Volt2().GetSuffix() );
  OutputLine( Types::String( L"Volt2: " ) + Volt2().GetSISuffix() );
  OutputLine( Types::String( L"Volt3: " ) + Volt3().GetSuffix() );
  OutputLine( Types::String( L"Volt3: " ) + Volt3().GetSISuffix() );
  OutputLine( (Pascal2() / Joule2( 1. )).GetSuffix() );

  OutputLine( (pressure * spaceneeded).GetSuffix() );
  OutputLine( (air * R * temperature).GetSuffix() );

  Scalar const PV = (pressure * spaceneeded).GetConvertedValue();
  Scalar const nRT = (air * R * temperature).GetConvertedValue();

  Assert( (pressure * spaceneeded) == (air * R * temperature) );
  Assert( fequal( PV, nRT ) );

}
