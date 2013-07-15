
#include "stdafx.h"
#include "UnitElectric.h"


using namespace Unit;
using namespace Unit::SI;
using namespace Unit::NonSI;


static void TestClassDefinition();
static void SeeClassDefinition();
static void TestFactorDefinition();
static void TestCompileTimeDefinition();
static void TestSomeElectric();
static void SolveElectricProblems();


void TestElectric()
{

  TestClassDefinition();
  SeeClassDefinition();
  TestCompileTimeDefinition();
  TestFactorDefinition();
  TestSomeElectric();
  SolveElectricProblems();

}


void TestClassDefinition()
{
  Femtovolt const femtonewton( 1. );
  Assert( femtonewton.GetValue() == 1. );
  Assert( femtonewton.GetFactor() == 1.e-15 );


  Dekavolt const dekanewton( 1. );
  Assert( dekanewton.GetValue()== 1. );
  Assert( dekanewton.GetFactor()== 1.e1 );

}


void SeeClassDefinition()
{
  std::wcout << "-- Electric --" << std::endl;

  Volt const volt;
  std::wcout << volt.GetSuffix() << std::endl;
  std::wcout << Volt::Suffix() << std::endl;

  std::wcout << Product<Watt,Ampere::Invert>::Suffix() << std::endl;

  Ohm const ohm;
  std::wcout << ohm.GetSuffix() << std::endl;
  std::wcout << Ohm::Suffix() << std::endl;

  std::wcout << Product<Volt,Ampere::Invert>::Suffix() << std::endl;

  Coulomb const coulomb;
  std::wcout << coulomb.GetSuffix() << std::endl;
  std::wcout << Coulomb::Suffix() << std::endl;


  std::wcout << Product<Volt,Ohm::Invert>::Suffix() << std::endl;

}

void TestFactorDefinition()
{

  Assert( fequal( Volt::ConversionFactor(), 1.0 ) );
  Assert( fequal( Ohm::ConversionFactor(), 1.0 ) );
  Assert( fequal( Coulomb::ConversionFactor(), 1.0 ) );

}


void TestCompileTimeDefinition()
{

  Ampere a = Volt( 1. ) / Ohm( 1. );

  Ohm ohm = Volt( 1. ) / Ampere( 1. );

  Joule j = Watt( 1. ) * Millisecond( 1. ); 

  Watt w = Joule( 1. ) / Second( 1. );

  Ohm ohm2 = Watt ( 1. ) / Dekaampere( 1. ) / Deciampere( 1. );

  Ohm ohm3 = Watt ( 1. ) / Product<Dekaampere>( 1. );

  Milliampere ma = Kilocoulomb( 1. ) / Microsecond( 1. );

}


void TestSomeElectric()
{



}

void SolveElectricProblems()
{

}

