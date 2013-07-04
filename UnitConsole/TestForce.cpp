
#include "stdafx.h"
#include "UnitForce.h"
#include "UnitAngular.h"
#include <iostream>

using namespace Unit;
using namespace Unit::SI;
using namespace Unit::NonSI;


//
// Other forms of Force unit definition.
//

typedef Product<Product<Meter,Kilogram> ,Product<Second>::Invert>  Newton2;
typedef Product<Product<Kilogram,Meter> ,Product<Second>::Invert>  Newton3;
typedef Product<Meter,Product<Kilogram,Product<Second>::Invert> > Newton4;
typedef Product<Kilogram,Product<Meter,Product<Second>::Invert> > Newton5;
typedef Product<Product<Kilogram,Meter> ,Product<Second>::Invert>  Newton6;
typedef Product<Product<Kilogram,Product<Second>::Invert> ,Meter> Newton7;
typedef Product<Product<Meter,Product<Second>::Invert> ,Kilogram> Newton8;


//
//  Compile time definition.
//
typedef Product<Gram, Nanoacceleration>       Femtonewton2;
typedef Product<Milligram, Microacceleration> Piconewton2;
typedef Product<Milligram, Milliacceleration> Nanonewton2;
typedef Product<Milligram, Acceleration>      Micronewton2;
typedef Product<Gram, Acceleration>           Millinewton2;
typedef Product<Dekagram, Acceleration>       Centinewton2;
typedef Product<Hectogram, Acceleration>      Decinewton2;
typedef Product<Kilogram, Dekaacceleration>   Dekanewton2;
typedef Product<Kilogram, Hectoacceleration>  Hectonewton2;
typedef Product<Megagram, Acceleration>       Kilonewton2;
typedef Product<Gigagram, Acceleration>       Meganewton2;
typedef Product<Gigagram, Kiloacceleration>   Giganewton2;
typedef Product<Petagram, Milliacceleration>  Teranewton2;
typedef Product<Teragram, Acceleration>       Petanewton2;


void Assert( bool );
bool fequal( double, double );


static void TestClassDefinition();
static void SeeClassDefinition();
static void TestFactorDefinition();
static void TestCompileTimeDefinition();
static void TestSomeForce();
static void SolveForceProblems();


void TestForce()
{

  TestClassDefinition();
  SeeClassDefinition();
  TestCompileTimeDefinition();
  TestFactorDefinition();
  TestSomeForce();
  SolveForceProblems();

}


void TestClassDefinition()
{
  Femtonewton const femtonewton( 1. );
  Assert( fequal( femtonewton.GetValue(), 1. ) );
  Assert( fequal( femtonewton.GetFactor(), 1.e-15 ) );


  Dekanewton const dekanewton( 1. );
  Assert( fequal( dekanewton.GetValue(), 1. ) );
  Assert( fequal( dekanewton.GetFactor(), 1.e1 ) );

}


void SeeClassDefinition()
{
  std::wcout << "-- Force --" << std::endl;

  Newton const newton;
  std::wcout << newton.GetSuffix() << std::endl;

  Newton2 const newton2;
  std::wcout << newton2.GetSuffix() << std::endl;

  Newton3 const newton3;
  std::wcout << newton3.GetSuffix() << std::endl;

  Newton4 const newton4;
  std::wcout << newton4.GetSuffix() << std::endl;

  Newton5 const newton5;
  std::wcout << newton5.GetSuffix() << std::endl;

  Newton6 const newton6;
  std::wcout << newton6.GetSuffix() << std::endl;

  Newton7 const newton7;
  std::wcout << newton7.GetSuffix() << std::endl;

  Newton8 const newton8;
  std::wcout << newton8.GetSuffix() << std::endl;
}

void TestFactorDefinition()
{

  Assert( fequal( Newton::ConversionFactor(), 1.0 ) );
  Assert( fequal( Newton2::ConversionFactor(), 1.0 ) );
  Assert( fequal( Newton3::ConversionFactor(), 1.0 ) );
  Assert( fequal( Newton4::ConversionFactor(), 1.0 ) );
  Assert( fequal( Newton5::ConversionFactor(), 1.0 ) );
  Assert( fequal( Newton6::ConversionFactor(), 1.0 ) );
  Assert( fequal( Newton7::ConversionFactor(), 1.0 ) );
  Assert( fequal( Newton8::ConversionFactor(), 1.0 ) );

}


void TestCompileTimeDefinition()
{

  Newton newton = Kilogram(1.) * Acceleration(1.);

  Newton2 newton2 = Newton2( newton );

  Newton3 newton3 = Newton3( newton2 );

  Newton4 newton4 = Newton4( newton3 );

  Newton5 newton5 = Newton5( newton );

  Newton6 newton6 = newton5;

  Newton7 newton7 = Newton7( newton2 );

  Newton8 newton8 = Newton8( newton7 );


  Meter m = Meter(newton8 * ( Second(1.0) * Second(1.0) ) / Kilogram(1.0));


  Scalar s = Newton(newton2) / Newton(newton);

  Scalar factor = Newton::SimplifiedFactor::ConversionFactor();

  std::wcout << "Newton \\ Newton: " << s << std::endl;

}


void TestSomeForce()
{

  //
  // A 30 kg suitcase moves upward along a 20 degree incline under the influence of an
  // applied horizontal force of 100N. The kinetic coefficient of friction between the 
  // incline and the suicase is 0.20. Find the acceleration of the suitcase.
  //

  Newton const one_hundred( 100. );
  Degree const twenty( 20. );
  Kilogram const thirty( 30. );
  Acceleration const gravity( 9.8 );
  Scalar const kinetic_coeff( .2 );

  Newton const n1 = one_hundred * (twenty.cos() - kinetic_coeff * twenty.sin());

  Newton const n2 = thirty * gravity * (kinetic_coeff * twenty.cos() + twenty.sin());

  Unit::Object<> const &o = Identity() / (thirty / (n2 - n1));

  std::wcout << "Newton: " << n1.GetSuffix() << std::endl;

  std::wcout << o.GetSuffix() << std::endl;
  std::wcout << o.GetValue() << std::endl;
  std::wcout << o.GetFactor() << std::endl;

}

void SolveForceProblems()
{

}

