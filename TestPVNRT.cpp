

#include "UnitVolume.h"
#include "UnitPressure.h"
#include "UnitEnergy.h"
#include "UnitPower.h"
#include "UnitElectricCurrent.h"
#include "UnitAmountOfSubstance.h"
#include "UnitTemperature.h"
#include <iostream>


using namespace Unit;
using namespace Unit::SI;


void Assert( bool );
bool fequal( double, double );




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
typedef Product<Watt,Ampere::Invert> Volt;



typedef Product<Product<Meter,Kilogram>,Product<Second>::Invert> Newton2;
typedef Product<Newton2,Product<Meter>::Invert> Pascal2;
typedef Product<Newton2,Meter> Joule2;
typedef Product<Joule2,Second::Invert> Watt2;
typedef Product<Watt2,Ampere::Invert> Volt2;


typedef Product<Product<Meter,Kilogram>,Product<Second>::Invert> Newton2;
typedef Product<Product<Meter,Kilogram>,Product<Second,Meter>::Invert> Pascal3;


void TestPV_equals_NRT()
{
  std::wcout << "-- Test PV equals NRT -- " << std::endl;

  RType const R( 8.3144621 );


  Pascal pressure( 101300. );

  Mole air( .0624 );

  Kelvin temperature( 292.87476745575 );
  Cubicmeter spaceneeded( .0015 );

  Pascal2 p0;

  std::wcout << "Newton: " << Newton().GetSuffix() << std::endl;
  std::wcout << "Newton2: " << Newton2().GetSuffix() << std::endl;
  std::wcout << "Pascal: " << Pascal().GetSuffix() << std::endl;
  std::wcout << "Pascal2: " << Pascal2().GetSuffix() << std::endl;
  std::wcout << "Joule: " << Joule().GetSuffix() << std::endl;
  std::wcout << "Joule2: " << Joule2().GetSuffix() << std::endl;
  std::wcout << "Watt: " << Watt().GetSuffix() << std::endl;
  std::wcout << "Watt2: " << Watt2().GetSuffix() << std::endl;
  std::wcout << "Volt: " << Volt().GetSuffix() << std::endl;
  std::wcout << "Volt2: " << Volt2().GetSuffix() << std::endl;

  std::wcout << (Pascal2() / Joule2( 1. )).GetSuffix() << std::endl;

  std::wcout << (pressure * spaceneeded).GetSuffix() << std::endl;
  std::wcout << (air * R * temperature).GetSuffix() << std::endl;

  int num = (pressure * spaceneeded).NumeratorBaseTypeValue;
  int denum = (pressure * spaceneeded).DenumeratorBaseTypeValue;

  int num2 = (air * R * temperature).NumeratorBaseTypeValue;
  int denum2 = (air * R * temperature).DenumeratorBaseTypeValue;


  Scalar const PV = (pressure * spaceneeded).GetConvertedValue();
  Scalar const nRT = (air * R * temperature).GetConvertedValue();

  Assert( (pressure * spaceneeded) == (air * R * temperature) );

}
