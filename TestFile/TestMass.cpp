
#include "stdafx.h"
#include "UnitMass.h"


using namespace Unit;
using namespace Unit::SI;
using namespace Unit::NonSI;

static void TestClassDefinition();
static void SeeClassDefinition();
static void TestConstructors();

 void TestMass()
{

  TestClassDefinition();
  SeeClassDefinition();
  TestConstructors();

}


void TestClassDefinition()
{
  // Gram is a special case: kg is the base unit 
  // kg is 1000 times more that g but kg is the base unit.
  // t is 1000 times more that kg so 10e6 time more than g.

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

  long const l = sizeof( Gram );
  long const l2 = sizeof( Kilogram );
  Assert( l == l2 );

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

  Millimetric_ton const millimetric_ton( 1. );
  Assert( fequal( millimetric_ton.GetValue(), 1. ) );
  Assert( fequal( millimetric_ton.GetConvertedValue(), 1. ) );
  Assert( fequal( millimetric_ton.GetFactor(), 1. ) );

  Metric_ton const metric_ton( 1. );
  Assert( fequal( metric_ton.GetValue(), 1. ) );
  Assert( fequal( metric_ton.GetConvertedValue(), 1000. ) );
  Assert( fequal( metric_ton.GetFactor(), 1000. ) );

  Megametric_ton const megametric_ton( 1. );
  Assert( fequal( megametric_ton.GetValue(), 1. ) );
  Assert( fequal( megametric_ton.GetConvertedValue(), 1.e9 ) );
  Assert( fequal( megametric_ton.GetFactor(), 1.e9 ) );

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
  OutputLine( gram.GetSISuffix() );
  OutputLine( Gram::Suffix() );
  Assert( gram.GetSuffix() == L"g" );
  Assert( gram.GetSISuffix() == L"g" );
  Assert( Gram::Suffix() == L"g" );

  Dekagram const dekagram;
  OutputLine( dekagram.GetSuffix() );
  OutputLine( Dekagram::Suffix() );

  Hectogram const hectogram;
  OutputLine( hectogram.GetSuffix() );
  OutputLine( Hectogram::Suffix() );

  Kilogram const kilogram;
  OutputLine( kilogram.GetSuffix() );
  OutputLine( kilogram.GetSISuffix() );
  OutputLine( Kilogram::Suffix() );
  Assert( kilogram.GetSuffix() == L"kg" );
  Assert( kilogram.GetSISuffix() == L"kg" );
  Assert( Kilogram::Suffix() == L"kg" );

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


  Millimetric_ton const millimetric_ton( 1. );
  OutputLine( millimetric_ton.GetSuffix() );
  OutputLine( millimetric_ton.GetSISuffix() );
  OutputLine( Millimetric_ton::Suffix() );
  Assert( millimetric_ton.GetSuffix() == L"mt" );
  Assert( millimetric_ton.GetSISuffix() == L"kg" );
  Assert( Millimetric_ton::Suffix() == L"mt" );

  Metric_ton const metric_ton( 1. );
  OutputLine( metric_ton.GetSuffix() );
  OutputLine( metric_ton.GetSISuffix() );
  OutputLine( Metric_ton::Suffix() );
  Assert( metric_ton.GetSuffix() == L"t" );
  Assert( metric_ton.GetSISuffix() == L"Mg" );
  Assert( Metric_ton::Suffix() == L"t" );

  Megametric_ton const megametric_ton( 1. );
  OutputLine( megametric_ton.GetSuffix() );
  OutputLine( megametric_ton.GetSISuffix() );
  OutputLine( Megametric_ton::Suffix() );
  Assert( megametric_ton.GetSuffix() == L"Mt" );
  Assert( megametric_ton.GetSISuffix() == L"Tg" );
  Assert( Megametric_ton::Suffix() == L"Mt" );
}

void TestConstructors()
{
  Gram const default_constructor;
  Assert( fequal( default_constructor.GetValue(), 0. ) );

  Gram const explicit_constructor_with_scalar( 2. );
  Assert( fequal( explicit_constructor_with_scalar.GetValue(), 2. ) );

  Kilogram const one_kilogram( 1. );
  Gram unit_1000_gram = one_kilogram;
  Assert( Kilogram::ConversionFactor() == 1.0 );
  Assert( Gram::ConversionFactor() == 0.001 );
  Assert( fequal( unit_1000_gram.GetValue(), 1000. ) );

  Metric_ton const one_metric_ton( 1. );
  Megagram const one_megagram = one_metric_ton;
  Assert( fequal( one_megagram.GetValue(), 1. ) );
  Assert( fequal( one_megagram.GetConvertedValue(), 1.e3 ) );

  Gram const copy_constructor = explicit_constructor_with_scalar;
  Assert( fequal( copy_constructor.GetValue(), 2. ) );

  Gram const copy_constructor2 = explicit_constructor_with_scalar + one_kilogram;
  Assert( fequal( copy_constructor2.GetValue(), 1000. + 2. ) );

  Gram const copy_constructor3 = explicit_constructor_with_scalar + static_cast<Megagram>( one_metric_ton );
  Assert( fequal( copy_constructor3.GetValue(), 1.e6 + 2. ) );

}
