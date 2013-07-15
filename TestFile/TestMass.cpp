
#include "stdafx.h"
#include "UnitMass.h"


using namespace Unit;
using namespace Unit::SI;


static void TestClassDefinition();
static void SeeClassDefinition();


void TestMass()
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
  OutputLine( L"-- Gram --" );

  Femtogram const femtogram;
  OutputLine( femtogram.GetSuffix() );
  OutputLine( Femtogram::Suffix() );

  Picogram const picogram;
  OutputLine( picogram.GetSuffix() );
  OutputLine( Picogram::Suffix() );

  Nanogram const nanogram;
  OutputLine( nanogram.GetSuffix() );
  OutputLine( Nanogram::Suffix() );

  Microgram const microgram;
  OutputLine( microgram.GetSuffix() );
  OutputLine( Microgram::Suffix() );

  Milligram const milligram;
  OutputLine( milligram.GetSuffix() );
  OutputLine( Milligram::Suffix() );

  Centigram const centigram;
  OutputLine( centigram.GetSuffix() );
  OutputLine( Centigram::Suffix() );

  Decigram const decigram;
  OutputLine( decigram.GetSuffix() );
  OutputLine( Femtogram::Suffix() );

  Gram const gram;
  OutputLine( gram.GetSuffix() );
  OutputLine( Gram::Suffix() );

  Dekagram const dekagram;
  OutputLine( dekagram.GetSuffix() );
  OutputLine( Dekagram::Suffix() );

  Hectogram const hectogram;
  OutputLine( hectogram.GetSuffix() );
  OutputLine( Hectogram::Suffix() );

  Kilogram const kilogram;
  OutputLine( kilogram.GetSuffix() );
  OutputLine( Kilogram::Suffix() );

  Megagram const megagram;
  OutputLine( megagram.GetSuffix() );
  OutputLine( Megagram::Suffix() );

  Gigagram const gigagram;
  OutputLine( gigagram.GetSuffix() );
  OutputLine( Gigagram::Suffix() );

  Teragram const teragram;
  OutputLine( teragram.GetSuffix() );
  OutputLine( Teragram::Suffix() );

  Petagram const petagram;
  OutputLine( petagram.GetSuffix() );
  OutputLine( Petagram::Suffix() );
}

