
#include "UnitElectric.h"
#include <iostream>

using namespace Unit;
using namespace Unit::SI;
using namespace Unit::NonSI;


void Assert( bool );
bool fequal( double, double );


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

  std::wcout << Product<Watt,Ampere::Invert>::Suffix() << std::endl;

  Ohm const ohm;
  std::wcout << ohm.GetSuffix() << std::endl;

  std::wcout << Product<Volt,Ampere::Invert>::Suffix() << std::endl;

  Coulomb const coulomb;
  std::wcout << coulomb.GetSuffix() << std::endl;


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



  int iVolt = Volt::NumeratorBaseTypeValue;
  int jVolt = Volt::DenumeratorBaseTypeValue;

  int iOhm = Ohm::NumeratorBaseTypeValue;
  int jOhm = Ohm::DenumeratorBaseTypeValue;

  int i = (Volt( 1. ) / Ohm( 1. )).NumeratorBaseTypeValue;
  int j = (Volt( 1. ) / Ohm( 1. )).DenumeratorBaseTypeValue;

  Ampere a = Volt( 1. ) / Ohm( 1. );

}


void TestSomeElectric()
{



}

void SolveElectricProblems()
{

}

