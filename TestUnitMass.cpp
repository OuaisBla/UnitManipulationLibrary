
#include "stdafx.h"
#include "UnitMass.h"
#include <iostream>


using namespace Unit;
using namespace Unit::SI;


static void TestClassDefinition();
static void SeeClassDefinition();


void Assert( bool );
bool fequal( double, double );


void TestUnitMass()
{

  TestClassDefinition();
  SeeClassDefinition();

}


void TestClassDefinition()
{
  Microgram const microgram( 1. );
  Assert( fequal( microgram.GetValue(), 1. ) );
  Assert( fequal( microgram.GetConvertedValue(), 1.e-9 ) );
  Assert( fequal( microgram.GetFactor(), 1.e-9 ) );

  Milligram const milligram( 1. );
  Assert( fequal( milligram.GetValue(), 1. ) );
  Assert( fequal( milligram.GetConvertedValue(), 1.e-6 ) );
  Assert( fequal( milligram.GetFactor(), 1.e-6 ) );

  Centigram const centigram( 1. );
  Assert( fequal( centigram.GetValue(), 1. ) );
  Assert( fequal( centigram.GetConvertedValue(), 1.e-5 ) );
  Assert( fequal( centigram.GetFactor(), 1.e-5 ) );

  Decigram const decigram( 1. );
  Assert( fequal( decigram.GetValue(), 1. ) );
  Assert( fequal( decigram.GetConvertedValue(), 1.e-4 ) );
  Assert( fequal( decigram.GetFactor(), 1.e-4 ) );

  Gram const gram( 1. );
  Assert( fequal( gram.GetValue(), 1. ) );
  Assert( fequal( gram.GetConvertedValue(), .001 ) );
  Assert( fequal( gram.GetFactor(), .001 ) );

  long l = sizeof( Gram );
  long l2 = sizeof( Kilogram );

  Dekagram const dekagram( 1. );
  Assert( fequal( dekagram.GetValue(), 1. ) );
  Assert( fequal( dekagram.GetConvertedValue(), .01 ) );
  Assert( fequal( dekagram.GetFactor(), .01 ) );

  Hectogram const hectogram( 1. );
  Assert( fequal( hectogram.GetValue(), 1. ) );
  Assert( fequal( hectogram.GetConvertedValue(), .1 ) );
  Assert( fequal( hectogram.GetFactor(), .1 ) );

  Kilogram const kilogram( 1. );
  Assert( fequal( kilogram.GetValue(), 1. ) );
  Assert( fequal( kilogram.GetConvertedValue(), 1. ) );
  Assert( fequal( kilogram.GetFactor(), 1. ) );

  Megagram const megagram( 1. );
  Assert( fequal( megagram.GetValue(), 1. ) );
  Assert( fequal( megagram.GetConvertedValue(), 1.e3 ) );
  Assert( fequal( megagram.GetFactor(), 1.e3 ) );

  Gigagram const gigagram( 1. );
  Assert( fequal( gigagram.GetValue(), 1. ) );
  Assert( fequal( gigagram.GetConvertedValue(), 1.e6 ) );
  Assert( fequal( gigagram.GetFactor(), 1.e6 ) );

}

void SeeClassDefinition()
{
  std::wcout << "-- Gram --" << std::endl;

  Femtogram const femtogram;
  std::wcout << femtogram.GetSuffix() << std::endl;

  Picogram const picogram;
  std::wcout << picogram.GetSuffix() << std::endl;

  Nanogram const nanogram;
  std::wcout << nanogram.GetSuffix() << std::endl;

  Microgram const microgram;
  std::wcout << microgram.GetSuffix() << std::endl;

  Milligram const milligram;
  std::wcout << milligram.GetSuffix() << std::endl;

  Centigram const centigram;
  std::wcout << centigram.GetSuffix() << std::endl;

  Decigram const decigram;
  std::wcout << decigram.GetSuffix() << std::endl;

  Gram const gram;
  std::wcout << gram.GetSuffix() << std::endl;

  Dekagram const dekagram;
  std::wcout << dekagram.GetSuffix() << std::endl;

  Hectogram const hectogram;
  std::wcout << hectogram.GetSuffix() << std::endl;

  Kilogram const kilogram;
  std::wcout << kilogram.GetSuffix() << std::endl;

  Megagram const megagram;
  std::wcout << megagram.GetSuffix() << std::endl;

  Gigagram const gigagram;
  std::wcout << gigagram.GetSuffix() << std::endl;

  Teragram const teragram;
  std::wcout << teragram.GetSuffix() << std::endl;

  Petagram const petagram;
  std::wcout << petagram.GetSuffix() << std::endl;
}

