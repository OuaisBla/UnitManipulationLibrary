
#include "stdafx.h"
#include "UnitLength.h"
#include <iostream>


using namespace Unit;
using namespace Unit::SI;
using namespace Unit::NonSI;


static void TestClassDefinition();
static void SeeClassDefinition();
static void TestConstructors();
static void TestAssignmentOperators();
static void TestComparaisonOperators();
static void TestMathematicalUnaryOperators();
static void TestMathematicalBinaryOperatorsWithScalar();
static void TestMathematicalAssignmentOperatorsWithScalar();
static void TestMathematicalBinaryOperators();
static void TestMathematicalAssignmentOperators();


void Assert( bool );
bool fequal( double, double );


void TestLength()
{

  TestClassDefinition();
  SeeClassDefinition();
  TestConstructors();
  TestAssignmentOperators();
  TestComparaisonOperators();
  TestMathematicalUnaryOperators();
  TestMathematicalBinaryOperatorsWithScalar();
  TestMathematicalAssignmentOperatorsWithScalar();
  TestMathematicalBinaryOperators();
  TestMathematicalAssignmentOperators();

}


void TestClassDefinition()
{
  Femtometer const femtometer( 1. );
  Assert( fequal( femtometer.GetValue(), 1. ) );
  Assert( fequal( femtometer.GetConvertedValue(), 1.e-15 ) );
  Assert( fequal( femtometer.GetFactor(), 1.e-15 ) );

  Picometer const picometer( 1. );
  Assert( fequal( picometer.GetValue(), 1. ) );
  Assert( fequal( picometer.GetConvertedValue(), 1.e-12 ) );
  Assert( fequal( picometer.GetFactor(), 1.e-12 ) );

  Nanometer const nanometer( 1. );
  Assert( fequal( nanometer.GetValue(), 1. ) );
  Assert( fequal( nanometer.GetConvertedValue(), 1.e-9 ) );
  Assert( fequal( nanometer.GetFactor(), 1.e-9 ) );

  Micrometer const micrometer( 1. );
  Assert( fequal( micrometer.GetValue(), 1. ) );
  Assert( fequal( micrometer.GetConvertedValue(), 1.e-6 ) );
  Assert( fequal( micrometer.GetFactor(), 1.e-6 ) );

  Millimeter const millimeter( 1. );
  Assert( fequal( millimeter.GetValue(), 1. ) );
  Assert( fequal( millimeter.GetConvertedValue(), .001 ) );
  Assert( fequal( millimeter.GetFactor(), .001 ) );

  Centimeter const centimeter( 1. );
  Assert( fequal( centimeter.GetValue(), 1. ) );
  Assert( fequal( centimeter.GetConvertedValue(), .01 ) );
  Assert( fequal( centimeter.GetFactor(), .01 ) );

  Decimeter const decimeter( 1. );
  Assert( fequal( decimeter.GetValue(), 1. ) );
  Assert( fequal( decimeter.GetConvertedValue(), .1 ) );
  Assert( fequal( decimeter.GetFactor(), .1 ) );

  Meter const meter( 1. );
  Assert( fequal( meter.GetValue(), 1. ) );
  Assert( fequal( meter.GetConvertedValue(), 1. ) );
  Assert( fequal( meter.GetFactor(), 1. ) );

  long l = sizeof( Meter );
  long l2 = sizeof( Kilometer );
  long l3 = sizeof( meter );

  Dekameter const dekameter( 1. );
  Assert( fequal( dekameter.GetValue(), 1. ) );
  Assert( fequal( dekameter.GetConvertedValue(), 10. ) );
  Assert( fequal( dekameter.GetFactor(), 10. ) );

  Hectometer const hectometer( 1. );
  Assert( fequal( hectometer.GetValue(), 1. ) );
  Assert( fequal( hectometer.GetConvertedValue(), 100. ) );
  Assert( fequal( hectometer.GetFactor(), 100. ) );

  Kilometer const kilometer( 1. );
  Assert( fequal( kilometer.GetValue(), 1. ) );
  Assert( fequal( kilometer.GetConvertedValue(), 1000. ) );
  Assert( fequal( kilometer.GetFactor(), 1000. ) );

  Megameter const megameter( 1. );
  Assert( fequal( megameter.GetValue(), 1. ) );
  Assert( fequal( megameter.GetConvertedValue(), 1.e6 ) );
  Assert( fequal( megameter.GetFactor(), 1.e6 ) );

  Gigameter const gigameter( 1. );
  Assert( fequal( gigameter.GetValue(), 1. ) );
  Assert( fequal( gigameter.GetConvertedValue(), 1.e9 ) );
  Assert( fequal( gigameter.GetFactor(), 1.e9 ) );

  Terameter const terameter( 1. );
  Assert( fequal( terameter.GetValue(), 1. ) );
  Assert( fequal( terameter.GetConvertedValue(), 1.e12 ) );
  Assert( fequal( terameter.GetFactor(), 1.e12 ) );

  Petameter const petameter( 1. );
  Assert( fequal( petameter.GetValue(), 1. ) );
  Assert( fequal( petameter.GetConvertedValue(), 1.e15 ) );
  Assert( fequal( petameter.GetFactor(), 1.e15 ) );

  Mil const mil( 1. );
  Assert( fequal( mil.GetValue(), 1. ) );
  Assert( fequal( mil.GetConvertedValue(), .0000254 ) );
  Assert( fequal( mil.GetFactor(), .0000254 ) );

  Inch const inch( 1. );
  Assert( fequal( inch.GetValue(), 1. ) );
  Assert( fequal( inch.GetConvertedValue(), .0254 ) );
  Assert( fequal( inch.GetFactor(), .0254 ) );

  Foot const foot( 1. );
  Assert( fequal( foot.GetValue(), 1. ) );
  Assert( fequal( foot.GetConvertedValue(), .3048 ) );
  Assert( fequal( foot.GetFactor(), .3048 ) );
}

void SeeClassDefinition()
{
  std::wcout << "-- Meter --" << std::endl;

  Femtometer const femtometer;
  std::wcout << femtometer.GetSuffix() << std::endl;

  Picometer const picometer;
  std::wcout << picometer.GetSuffix() << std::endl;

  Nanometer const nanometer;
  std::wcout << nanometer.GetSuffix() << std::endl;

  Micrometer const micrometer;
  std::wcout << micrometer.GetSuffix() << std::endl;

  Millimeter const millimeter;
  std::wcout << millimeter.GetSuffix() << std::endl;

  Centimeter const centimeter;
  std::wcout << centimeter.GetSuffix() << std::endl;

  Decimeter const decimeter;
  std::wcout << decimeter.GetSuffix() << std::endl;

  Meter const meter;
  std::wcout << meter.GetSuffix() << std::endl;

  Dekameter const dekameter;
  std::wcout << dekameter.GetSuffix() << std::endl;

  Hectometer const hectometer;
  std::wcout << hectometer.GetSuffix() << std::endl;

  Kilometer const kilometer;
  std::wcout << kilometer.GetSuffix() << std::endl;

  Megameter const megameter;
  std::wcout << megameter.GetSuffix() << std::endl;

  Gigameter const gigameter;
  std::wcout << gigameter.GetSuffix() << std::endl;

  Terameter const terameter;
  std::wcout << terameter.GetSuffix() << std::endl;

  Petameter const petameter;
  std::wcout << petameter.GetSuffix() << std::endl;

  Mil const mil;
  std::wcout << Mil::Suffix() << std::endl;
  Assert( mil.GetSuffix() == Mil::Suffix() );

  Inch const inch;
  std::wcout << Inch::Suffix() << std::endl;
  Assert( inch.GetSuffix() == Inch::Suffix() );

  Foot const foot;
  std::wcout << Foot::Suffix() << std::endl;
  Assert( foot.GetSuffix() == Foot::Suffix() );
}

void TestConstructors()
{
  Meter const default_constructor;
  Assert( fequal( default_constructor.GetValue(), 0. ) );

  Meter const explicit_constructor_with_scalar( 2. );
  Assert( fequal( explicit_constructor_with_scalar.GetValue(), 2. ) );

  Kilometer const one_kilometer( 1. );
  Meter unit_1000_meter = one_kilometer;
  Assert( fequal( unit_1000_meter.GetValue(), 1000. ) );

  Foot const one_foot( 1. );
  Meter const _dot_3048_meter = (Inch)one_foot;
  Assert( fequal( _dot_3048_meter.GetValue(), .3048 ) );

  Meter const copy_constructor = explicit_constructor_with_scalar;
  Assert( fequal( copy_constructor.GetValue(), 2. ) );
}


void TestAssignmentOperators()
{
  Meter assign_with_scalar_PParameter;
  Meter multi_template_assignment_operator;
  Meter copy_assignment_operator;

  assign_with_scalar_PParameter = 12.;
  Assert( fequal( assign_with_scalar_PParameter.GetValue(), 12. ) );

  Kilometer one_kilospeed( 1. );
  multi_template_assignment_operator = one_kilospeed;
  Assert( fequal( multi_template_assignment_operator.GetValue(), 1000. ) );

  copy_assignment_operator = assign_with_scalar_PParameter;
  Assert( fequal( copy_assignment_operator.GetValue(), 12. ) );

  Meter self_assignment( 12. );
  self_assignment = self_assignment;
  self_assignment = self_assignment.GetValue();
  Assert( fequal( self_assignment.GetValue(), 12. ) );
}


void TestComparaisonOperators()
{

  Meter const unit_1000_meter( 1000. );
  Kilometer const unit_1_kilometer( 1. );
  Meter const unit_500_meter( 500. );
  Meter const unit_2000_meter( 2000. );
  Dekameter const unit_10_dekameter( 100. );


  Assert( unit_1000_meter == unit_1_kilometer && unit_1_kilometer == unit_1000_meter );
  Assert( unit_1_kilometer != unit_2000_meter );
  Assert( unit_1_kilometer < unit_2000_meter );
  Assert( unit_1_kilometer > unit_500_meter );
  Assert( unit_1_kilometer <= unit_2000_meter );
  Assert( unit_1_kilometer <= unit_1000_meter );
  Assert( unit_1_kilometer >= unit_500_meter );
  Assert( unit_1_kilometer >= unit_1000_meter );

  Assert( unit_1_kilometer == unit_10_dekameter && unit_10_dekameter == unit_1_kilometer );

  Assert( unit_1000_meter == unit_1000_meter );
  Assert( unit_1000_meter != unit_2000_meter );
  Assert( unit_1000_meter < unit_2000_meter );
  Assert( unit_1000_meter > unit_500_meter );
  Assert( unit_1000_meter <= unit_2000_meter );
  Assert( unit_1000_meter <= unit_1000_meter );
  Assert( unit_1000_meter >= unit_500_meter );
  Assert( unit_1000_meter >= unit_1000_meter );
  
}

void TestMathematicalUnaryOperators()
{
  Kilometer const unit_10_kilometer = (Kilometer)10.;
  
  Hectometer const unit_100_hectometer = -unit_10_kilometer;
  Assert( fequal( unit_100_hectometer.GetValue(), -100. ) );
}

void TestMathematicalBinaryOperatorsWithScalar()
{
  Kilometer const unit_10_kilometer( 10. );

  Hectometer unit_110_hectometer = unit_10_kilometer + Kilometer( 1.);
  Assert( fequal( unit_110_hectometer.GetValue(), 110. ) );

  unit_110_hectometer = Kilometer( 1.) + unit_10_kilometer;
  Assert( fequal( unit_110_hectometer.GetValue(), 110. ) );

  Hectometer unit_90_hectometer = unit_10_kilometer - Kilometer( 1.);
  Assert( fequal( unit_90_hectometer.GetValue(), 90. ) );

  Hectometer minus_90_hectometer = Kilometer( 1.) - unit_10_kilometer;
  Assert( fequal( minus_90_hectometer.GetValue(), -90. ) );

  Hectometer unit_200_hectometer = unit_10_kilometer * 2.;
  Assert( fequal( unit_200_hectometer.GetValue(), 200. ) );

  unit_200_hectometer = 2. * unit_10_kilometer;
  Assert( fequal( unit_200_hectometer.GetValue(), 200. ) );

  Hectometer unit_50_hectometer = unit_10_kilometer / 2.;
  Assert( fequal( unit_50_hectometer.GetValue(), 50. ) );

  Hectometer::Invert unit_2_hectometer = 2. / unit_10_kilometer;
  Assert( fequal( unit_2_hectometer.GetValue(), 0.02 ) );
}


void TestMathematicalAssignmentOperatorsWithScalar()
{
  Kilometer to_evaluate( 10. );

  to_evaluate += Kilometer( 12. );
  Assert( fequal( to_evaluate.GetValue(), 22. ) );

  to_evaluate -= Kilometer( 12. );
  Assert( fequal( to_evaluate.GetValue(), 10. ) );

  to_evaluate *= 4.;
  Assert( fequal( to_evaluate.GetValue(), 40. ) );

  to_evaluate /= 2.;
  Assert( fequal( to_evaluate.GetValue(), 20. ) );
}

void TestMathematicalBinaryOperators()
{
  Kilometer const unit_10_kilometer( 10. );
  Kilometer const unit_9_kilometer( 9. );

  Hectometer const unit_200_hectometer = unit_10_kilometer + unit_10_kilometer;
  Assert( fequal( unit_200_hectometer.GetValue(), 200. ) );

  Hectometer const unit_10_hectometer = unit_10_kilometer - unit_9_kilometer;
  Assert( fequal( unit_10_hectometer.GetValue(), 10. ) );

  Meter const unit_31000_meter = unit_10_kilometer + unit_200_hectometer + unit_10_hectometer;
  Assert( fequal( unit_31000_meter.GetValue(), 31000. ) );

  Scalar const unit_20_ = unit_200_hectometer / unit_10_hectometer;
  Assert( fequal( unit_20_, 20. ) );

  Scalar const unit_2_ = unit_200_hectometer / unit_10_kilometer;
  Assert( fequal( unit_2_, 2. ) );
}

void TestMathematicalAssignmentOperators()
{
  Kilometer const unit_10_kilometer( 10. );
  Kilometer const unit_9_kilometer( 9. );

  Hectometer unit_200_hectometer = unit_10_kilometer;
  unit_200_hectometer += unit_10_kilometer;
  Assert( fequal( unit_200_hectometer.GetValue(), 200. ) );

  Hectometer unit_10_hectometer = unit_10_kilometer;
  unit_10_hectometer -= unit_9_kilometer;
  Assert( fequal( unit_10_hectometer.GetValue(), 10. ) );
}
