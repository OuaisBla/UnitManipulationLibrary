
#include "TestHelper.h"
#include "UnitForce.h"
#include "UnitAngular.h"

using namespace Unit;
using namespace Unit::SI;
using namespace Unit::NonSI;

using Unit::Types::Scalar;

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
typedef Product<Product<Meter, Second::Invert>, Product<Second::Invert, Kilogram>> Newton9;
typedef Product<Product<Second::Invert, Meter>, Product<Kilogram, Second::Invert>> Newton10;
typedef Product<Product<Second::Invert, Kilogram>, Product<Meter, Second::Invert>> Newton11;
typedef Product<Product<Kilogram, Second::Invert>, Product<Second::Invert, Meter>> Newton12;

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
  OutputLine( L"-- Force --" );

  Newton const newton;
  OutputLine( newton.GetSuffix() );

  Newton2 const newton2;
  OutputLine( newton2.GetSuffix() );

  Newton3 const newton3;
  OutputLine( newton3.GetSuffix() );

  Newton4 const newton4;
  OutputLine( newton4.GetSuffix() );

  Newton5 const newton5;
  OutputLine( newton5.GetSuffix() );

  Newton6 const newton6;
  OutputLine( newton6.GetSuffix() );

  Newton7 const newton7;
  OutputLine( newton7.GetSuffix() );

  Newton8 const newton8;
  OutputLine( newton8.GetSuffix() );
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

  Newton9 newton9 = Newton8(newton7);

  Newton10 newton10 = Newton8(newton7);

  Newton11 newton11 = Newton8(newton7);

  Newton12 newton12 = Newton8(newton7);


  Meter const m = Meter(newton8 * ( Second(1.0) * Second(1.0) ) / Kilogram(1.0));
  Assert( m == Meter( 1.0 ) );

  Scalar const s = Newton(newton2) / Newton(newton);
  OutputLine( L"Newton \\ Newton: " + ToString( s ) );

  Scalar const factor = Newton::SimplifiedFactor::ConversionFactor();
  Assert( factor == 1.0 );

  Scalar const s1 = newton / newton2;
  Assert( fequal( s1, 1.0)  );

  Scalar const s2 = newton2 / newton3;
  Assert(fequal(s2, 1.0));

  Scalar const s3 = newton3 / newton4;
  Assert(fequal(s3, 1.0));

  Scalar const s4 = newton5 / newton6;
  Assert(fequal(s4, 1.0));

  Scalar const s5 = newton7 / newton8;
  Assert(fequal(s5, 1.0));

  Scalar const s6 = newton8 / newton7;
  Assert(fequal(s6, 1.0));

  Scalar const s7 = newton5 / newton2;
  Assert(fequal(s7, 1.0));

  Scalar const s8 = newton4 / newton3;
  Assert(fequal(s8, 1.0));

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

  OutputLine( Types::String( L"Newton: " ) + n1.GetSuffix() );

  OutputLine( o.GetSuffix() );
  OutputLine( ToString( o.GetValue() ) );
  OutputLine( ToString( o.GetFactor() ) );

}

void SolveForceProblems()
{

}

