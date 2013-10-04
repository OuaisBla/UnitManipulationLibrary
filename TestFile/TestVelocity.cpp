
#include "stdafx.h"
#include "UnitVelocity.h"


using namespace Unit;
using namespace Unit::SI;
using namespace Unit::NonSI;


//
//  Compile time definition.
//
typedef Product<Meter, Petasecond::Invert>  Femtovelocity2;
typedef Product<Meter, Terasecond::Invert>  Picovelocity2;
typedef Product<Meter, Gigasecond::Invert>  Nanovelocity2;
typedef Product<Meter, Megasecond::Invert>  Microvelocity2;
typedef Product<Meter, Kilosecond::Invert>  Millivelocity2;
typedef Product<Meter, Hectosecond::Invert> Centivelocity2;
typedef Product<Meter, Dekasecond::Invert>  Decivelocity2;
typedef Product<Meter, Decisecond::Invert>  Dekavelocity2;
typedef Product<Meter, Centisecond::Invert> Hectovelocity2;
typedef Product<Meter, Millisecond::Invert> Kilovelocity2;
typedef Product<Meter, Microsecond::Invert> Megavelocity2;
typedef Product<Meter, Nanosecond::Invert>  Gigavelocity2;
typedef Product<Meter, Picosecond::Invert>  Teravelocity2;
typedef Product<Meter, Femtosecond::Invert> Petavelocity2;



typedef Product<Kilometer,Hour::Invert>  CarVelocity;



static void TestClassDefinition();
static void SeeClassDefinition();
static void TestCompileTimeDefinition();
static void SolveVelocityProblems1();
static void SolveVelocityProblems2();
static void SolveVelocityProblems3();
static void TestConstructors();
static void TestAssignmentOperators();
static void TestComparaisonOperators();
static void TestMathematicalUnaryOperators();
static void TestMathematicalBinaryOperatorsWithScalar();
static void TestMathematicalAssignmentOperatorsWithScalar();
static void TestMathematicalBinaryOperators();
static void TestMathematicalAssignmentOperators();


void TestVelocity()
{

  TestClassDefinition();
  SeeClassDefinition();
  TestCompileTimeDefinition();
  TestConstructors();
  TestAssignmentOperators();
  TestComparaisonOperators();
  TestMathematicalUnaryOperators();
  TestMathematicalBinaryOperatorsWithScalar();
  TestMathematicalAssignmentOperatorsWithScalar();
  TestMathematicalBinaryOperators();
  TestMathematicalAssignmentOperators();
  SolveVelocityProblems1();
  SolveVelocityProblems2();
  SolveVelocityProblems3();

}


void TestClassDefinition()
{
  Femtovelocity const femtovelocity( 1. );
  Assert( fequal( femtovelocity.GetValue(), 1. ) );
  Assert( fequal( femtovelocity.GetFactor(), 1.e-15 ) );

  Picovelocity const picovelocity( 1. );
  Assert( fequal( picovelocity.GetValue(), 1. ) );
  Assert( fequal( picovelocity.GetFactor(), 1.e-12 ) );

  Nanovelocity const nanovelocity( 1. );
  Assert( fequal( nanovelocity.GetValue(), 1. ) );
  Assert( fequal( nanovelocity.GetFactor(), 1.e-9 ) );

  Microvelocity const microvelocity( 1. );
  Assert( fequal( microvelocity.GetValue(), 1. ) );
  Assert( fequal( microvelocity.GetFactor(), 1.e-6 ) );

  Millivelocity const millivelocity( 1. );
  Assert( fequal( millivelocity.GetValue(), 1. ) );
  Assert( fequal( millivelocity.GetFactor(), 1.e-3 ) );

  Centivelocity const centivelocity( 1. );
  Assert( fequal( centivelocity.GetValue(), 1. ) );
  Assert( fequal( centivelocity.GetFactor(), 1.e-2 ) );

  Decivelocity const decivelocity( 1. );
  Assert( fequal( decivelocity.GetValue(), 1. ) );
  Assert( fequal( decivelocity.GetFactor(), 1.e-1 ) );

  Velocity const velocity( 1. );
  Assert( fequal( velocity.GetValue(), 1. ) );
  Assert( fequal( velocity.GetFactor(), 1. ) );

  long const l = sizeof( Velocity );
  long const l2 = sizeof( Kilovelocity );
  Assert( l == l2 );

  Dekavelocity const dekavelocity( 1. );
  Assert( fequal( dekavelocity.GetValue(), 1. ) );
  Assert( fequal( dekavelocity.GetFactor(), 1.e1 ) );

  Hectovelocity const hectovelocity( 1. );
  Assert( fequal( hectovelocity.GetValue(), 1. ) );
  Assert( fequal( hectovelocity.GetFactor(), 1.e2 ) );

  Kilovelocity const kilovelocity( 1. );
  Assert( fequal( kilovelocity.GetValue(), 1. ) );
  Assert( fequal( kilovelocity.GetFactor(), 1.e3 ) );

  Megavelocity const megavelocity( 1. );
  Assert( fequal( megavelocity.GetValue(), 1. ) );
  Assert( fequal( megavelocity.GetFactor(), 1.e6 ) );

  Gigavelocity const gigavelocity( 1. );
  Assert( fequal( gigavelocity.GetValue(), 1. ) );
  Assert( fequal( gigavelocity.GetFactor(), 1.e9 ) );

  Teravelocity const teravelocity( 1. );
  Assert( fequal( teravelocity.GetValue(), 1. ) );
  Assert( fequal( teravelocity.GetFactor(), 1.e12 ) );

  Petavelocity const petavelocity( 1. );
  Assert( fequal( petavelocity.GetValue(), 1. ) );
  Assert( fequal( petavelocity.GetFactor(), 1.e15 ) );

  CarVelocity const carvelocity( 1. );
  Assert( fequal( carvelocity.GetValue(), 1. ) );
  Assert( fequal( carvelocity.GetFactor(), .27777777777777777777777777777778 ) );

}

void SeeClassDefinition()
{
  OutputLine( L"-- Velocity --" );

  Femtovelocity const femtovelocity;
  OutputLine( femtovelocity.GetSuffix() );

  Picovelocity const picovelocity;
  OutputLine( picovelocity.GetSuffix() );

  Nanovelocity const nanovelocity;
  OutputLine( nanovelocity.GetSuffix() );

  Microvelocity const microvelocity;
  OutputLine( microvelocity.GetSuffix() );

  Millivelocity const millivelocity;
  OutputLine( millivelocity.GetSuffix() );

  Centivelocity const centivelocity;
  OutputLine( centivelocity.GetSuffix() );

  Decivelocity const decivelocity;
  OutputLine( decivelocity.GetSuffix() );

  Velocity const velocity;
  OutputLine( velocity.GetSuffix() );
  Assert( velocity.GetSuffix() == velocity.GetSISuffix() );
  Assert( velocity.GetSISuffix() == Velocity::Suffix() );

  Dekavelocity const dekavelocity;
  OutputLine( dekavelocity.GetSuffix() );

  Hectovelocity const hectovelocity;
  OutputLine( hectovelocity.GetSuffix() );

  Kilovelocity const kilovelocity;
  OutputLine( kilovelocity.GetSuffix() );

  Megavelocity const megavelocity;
  OutputLine( megavelocity.GetSuffix() );

  Gigavelocity const gigavelocity;
  OutputLine( gigavelocity.GetSuffix() );

  Teravelocity const teravelocity;
  OutputLine( teravelocity.GetSuffix() );

  Petavelocity const petavelocity;
  OutputLine( petavelocity.GetSuffix() );

  Femtovelocity2 const femtovelocity2;
  OutputLine( femtovelocity2.GetSuffix() );

  Picovelocity2 const picovelocity2;
  OutputLine( picovelocity2.GetSuffix() );

  Nanovelocity2 const nanovelocity2;
  OutputLine( nanovelocity2.GetSuffix() );

  Microvelocity2 const microvelocity2;
  OutputLine( microvelocity2.GetSuffix() );

  Millivelocity2 const millivelocity2;
  OutputLine( millivelocity2.GetSuffix() );

  Centivelocity2 const centivelocity2;
  OutputLine( centivelocity2.GetSuffix() );

  Decivelocity2 const decivelocity2;
  OutputLine( decivelocity2.GetSuffix() );

  Dekavelocity2 const dekavelocity2;
  OutputLine( dekavelocity2.GetSuffix() );

  Hectovelocity2 const hectovelocity2;
  OutputLine( hectovelocity2.GetSuffix() );

  Kilovelocity2 const kilovelocity2;
  OutputLine( kilovelocity2.GetSuffix() );

  Megavelocity2 const megavelocity2;
  OutputLine( megavelocity2.GetSuffix() );

  Gigavelocity2 const gigavelocity2;
  OutputLine( gigavelocity2.GetSuffix() );

  Teravelocity2 const teravelocity2;
  OutputLine( teravelocity2.GetSuffix() );

  Petavelocity2 const petavelocity2;
  OutputLine( petavelocity2.GetSuffix() );

  CarVelocity const carvelocity;
  OutputLine( carvelocity.GetSuffix() );
}

void TestCompileTimeDefinition()
{

  Femtovelocity const femtovelocity = Nanometer( 1. ) / Megasecond( 1. );
  Assert( fequal( femtovelocity.GetValue(), 1. ) );

  Nanovelocity const nanovelocity = Nanometer( 1. ) / Second( 1. );
  Assert( fequal( nanovelocity.GetValue(), 1. ) );

  Microvelocity const microvelocity = Meter( 1. ) / Megasecond( 1. );
  Assert( fequal( microvelocity.GetValue(), 1. ) );

  Millivelocity const millivelocity = Decimeter( 1. ) / Hectosecond( 1. );
  Assert( fequal( millivelocity.GetValue(), 1. ) );

  Centivelocity const centivelocity = Centimeter( 1. ) / Second( 1. );
  Assert( fequal( centivelocity.GetValue(), 1. ) );

  Decivelocity const decivelocity = Decimeter( 1. ) / Second( 1. );
  Assert( fequal( decivelocity.GetValue(), 1. ) );

  Velocity const velocity = Centimeter( 1. ) / Centisecond( 1. );
  Assert( fequal( velocity.GetValue(), 1. ) );

  Dekavelocity const dekavelocity = Dekameter( 1. ) / Second( 1. );
  Assert( fequal( dekavelocity.GetValue(), 1. ) );

  Hectovelocity const hectovelocity = Dekameter( 1. ) / Decisecond( 1. );
  Assert( fequal( hectovelocity.GetValue(), 1. ) );

  Kilovelocity const kilovelocity = Kilometer( 1. ) / Second( 1. );
  Assert( fequal( kilovelocity.GetValue(), 1. ) );

  Megavelocity const megavelocity = Kilometer( 1. ) / Millisecond( 1. );
  Assert( fequal( megavelocity.GetValue(), 1. ) );


  Femtovelocity2 const femtovelocity2 = femtovelocity;
  Assert( fequal( femtovelocity.GetFactor(), femtovelocity2.GetFactor() ) );

  Nanovelocity2 const nanovelocity2 = nanovelocity;
  Assert( fequal( nanovelocity.GetFactor(), nanovelocity2.GetFactor() ) );

  Microvelocity2 const microvelocity2 = microvelocity;
  Assert( fequal( microvelocity.GetFactor(), microvelocity2.GetFactor() ) );

  Millivelocity2 const millivelocity2 = millivelocity;
  Assert( fequal( millivelocity.GetFactor(), millivelocity2.GetFactor() ) );

  Centivelocity2 const centivelocity2 = centivelocity;
  Assert( fequal( centivelocity.GetFactor(), centivelocity2.GetFactor() ) );

  Decivelocity2 const decivelocity2 = decivelocity;
  Assert( fequal( decivelocity.GetFactor(), decivelocity2.GetFactor() ) );

  Dekavelocity2 const dekavelocity2 = dekavelocity;
  Assert( fequal( dekavelocity.GetFactor(), dekavelocity2.GetFactor() ) );

  Hectovelocity2 const hectovelocity2 = hectovelocity;
  Assert( fequal( hectovelocity.GetFactor(), hectovelocity2.GetFactor() ) );

  Kilovelocity2 const kilovelocity2 = kilovelocity;
  Assert( fequal( kilovelocity.GetFactor(), kilovelocity2.GetFactor() ) );

  Megavelocity2 const megavelocity2 = megavelocity;
  Assert( fequal( megavelocity.GetFactor(), megavelocity2.GetFactor() ) );

}


void TestConstructors()
{

  //  A distance of 3 kilometer
  Kilometer const three_kilometer( 3. );

  //  That took 5 minutes to a car to do.
  Minute::Invert const five_minute = Identity() / Minute( 5. );

  //  So the velocity was:
  CarVelocity const car_velocity( three_kilometer, five_minute );
  Assert( fequal( car_velocity.GetValue(), 36. ) ); // In kilometer/hour of course.

  //  In the SI system the velocity is:
  Velocity const si_car_velocity = car_velocity;
  Assert( fequal( si_car_velocity.GetValue(), 10. ) ); // Yes, it is really 10 m/s

  //  Let's try it runtime.

  CarVelocity const product_velocity = three_kilometer * five_minute;
  Assert( fequal( product_velocity.GetValue(), 36. ) ); // In kilometer/hour of course.

  CarVelocity const quotient_velocity = Hectometer( 30. ) / Hour( 0.08333333333333333333333333333333 );
  Assert( fequal( quotient_velocity.GetValue(), 36. ) ); // In kilometer/hour.

}


void TestAssignmentOperators()
{
  Velocity assign_with_scalar_PParameter;
  Velocity multi_template_assignment_operator;
  Velocity copy_assignment_operator;

  assign_with_scalar_PParameter = 12.;
  Assert( fequal( assign_with_scalar_PParameter.GetValue(), 12. ) );

  Kilovelocity one_kilospeed( 1. );
  multi_template_assignment_operator = one_kilospeed;
  Assert( fequal( multi_template_assignment_operator.GetValue(), 1000. ) );

  copy_assignment_operator = assign_with_scalar_PParameter;
  Assert( fequal( copy_assignment_operator.GetValue(), 12. ) );

  Velocity self_assignment( 12. );
  self_assignment = self_assignment;
  self_assignment = self_assignment.GetValue();
  Assert( fequal( self_assignment.GetValue(), 12. ) );
}


void TestComparaisonOperators()
{

  Velocity const unit_1000_velocity( 1000. );
  Kilovelocity const unit_1_kilovelocity( 1. );
  Velocity const unit_500_velocity( 500. );
  Velocity const unit_2000_velocity( 2000. );


  Assert( unit_1000_velocity == unit_1_kilovelocity && unit_1_kilovelocity == unit_1000_velocity );
  Assert( unit_1_kilovelocity != unit_2000_velocity );
  Assert( unit_1_kilovelocity < unit_2000_velocity );
  Assert( unit_1_kilovelocity > unit_500_velocity );
  Assert( unit_1_kilovelocity <= unit_2000_velocity );
  Assert( unit_1_kilovelocity <= unit_1000_velocity );
  Assert( unit_1_kilovelocity >= unit_500_velocity );
  Assert( unit_1_kilovelocity >= unit_1000_velocity );

  Assert( unit_1000_velocity == unit_1000_velocity );
  Assert( unit_1000_velocity != unit_2000_velocity );
  Assert( unit_1000_velocity < unit_2000_velocity );
  Assert( unit_1000_velocity > unit_500_velocity );
  Assert( unit_1000_velocity <= unit_2000_velocity );
  Assert( unit_1000_velocity <= unit_1000_velocity );
  Assert( unit_1000_velocity >= unit_500_velocity );
  Assert( unit_1000_velocity >= unit_1000_velocity );

 
}

void TestMathematicalUnaryOperators()
{
  Kilovelocity const unit_10_kilovelocity = (Kilovelocity)10.;
  
  Hectovelocity const unit_100_hectovelocity = -unit_10_kilovelocity;
  Assert( fequal( unit_100_hectovelocity.GetValue(), -100. ) );
}

void TestMathematicalBinaryOperatorsWithScalar()
{
  Kilovelocity const unit_10_kilovelocity( 10. );

  Hectovelocity unit_110_hectovelocity = unit_10_kilovelocity + Kilovelocity( 1. );
  Assert( fequal( unit_110_hectovelocity.GetValue(), 110. ) );

  unit_110_hectovelocity = Kilovelocity( 1. ) + unit_10_kilovelocity;
  Assert( fequal( unit_110_hectovelocity.GetValue(), 110. ) );

  Hectovelocity unit_90_hectovelocity = unit_10_kilovelocity - Kilovelocity( 1. );
  Assert( fequal( unit_90_hectovelocity.GetValue(), 90. ) );

  Hectovelocity minus_90_hectovelocity = Kilovelocity( 1. ) - unit_10_kilovelocity;
  Assert( fequal( minus_90_hectovelocity.GetValue(), -90. ) );

  Hectovelocity unit_200_hectovelocity = unit_10_kilovelocity * 2.;
  Assert( fequal( unit_200_hectovelocity.GetValue(), 200. ) );

  unit_200_hectovelocity = 2. * unit_10_kilovelocity;
  Assert( fequal( unit_200_hectovelocity.GetValue(), 200. ) );

  Hectovelocity unit_50_hectovelocity = unit_10_kilovelocity / 2.;
  Assert( fequal( unit_50_hectovelocity.GetValue(), 50. ) );

  Hectovelocity::Invert unit_2_hectovelocity = 2. / unit_10_kilovelocity;
  Assert( fequal( unit_2_hectovelocity.GetValue(), 0.02 ) );
}


void TestMathematicalAssignmentOperatorsWithScalar()
{
  Kilovelocity to_evaluate( 10. );

  to_evaluate += Kilovelocity( 12. );
  Assert( fequal( to_evaluate.GetValue(), 22. ) );

  to_evaluate -= Kilovelocity( 12. );
  Assert( fequal( to_evaluate.GetValue(), 10. ) );

  to_evaluate *= 4.;
  Assert( fequal( to_evaluate.GetValue(), 40. ) );

  to_evaluate /= 2.;
  Assert( fequal( to_evaluate.GetValue(), 20. ) );
}

void TestMathematicalBinaryOperators()
{
  Kilovelocity const unit_10_kilovelocity( 10. );
  Kilovelocity const unit_9_kilovelocity( 9. );

  Hectovelocity const unit_200_hectovelocity = unit_10_kilovelocity + unit_10_kilovelocity;
  Assert( fequal( unit_200_hectovelocity.GetValue(), 200. ) );

  Hectovelocity const unit_10_hectovelocity = unit_10_kilovelocity - unit_9_kilovelocity;
  Assert( fequal( unit_10_hectovelocity.GetValue(), 10. ) );

  Velocity const unit_31000_velocity = unit_10_kilovelocity + unit_200_hectovelocity + unit_10_hectovelocity;
  Assert( fequal( unit_31000_velocity.GetValue(), 31000. ) );

  Scalar const unit_20_ = unit_200_hectovelocity / unit_10_hectovelocity;
  Assert( fequal( unit_20_, 20. ) );

  Scalar const unit_2_ = unit_200_hectovelocity / unit_10_kilovelocity;
  Assert( fequal( unit_2_, 2. ) );
}

void TestMathematicalAssignmentOperators()
{
  Kilovelocity const unit_10_kilovelocity( 10. );
  Kilovelocity const unit_9_kilovelocity( 9. );

  Hectovelocity unit_200_hectovelocity = unit_10_kilovelocity;
  unit_200_hectovelocity += unit_10_kilovelocity;
  Assert( fequal( unit_200_hectovelocity.GetValue(), 200. ) );

  Hectovelocity unit_10_hectovelocity = unit_10_kilovelocity;
  unit_10_hectovelocity -= unit_9_kilovelocity;
  Assert( fequal( unit_10_hectovelocity.GetValue(), 10. ) );
}


void SolveVelocityProblems1()
{
  //1. In the 1988 Olympic games the average time for the men in the 100 m 
  //   dash was 9.86 sec.  What was the average velocity? 
  Velocity const rep1 = Dekameter( 10. ) / Second( 9.86 );
  Scalar const _rep1 = rep1.GetValue();
  Assert( fequal( _rep1, 10.141987829615 ) );

  //2. A person is driving down a street at 55 km/h.  Suddenly a child runs 
  //   into the street.  If it takes 0.75 s to react and apply the brakes, 
  //   how many meters will she have moved before she begins to slow down? 
  Meter const rep2 = Second( .75 ) * CarVelocity( 55. );
  Scalar const _rep2 = rep2.GetValue();
  Assert( fequal( _rep2, 11.458333333333 ) );
  
  //3. A person walks 13 km in 2.0 h.  What is the person's average velocity 
  //   in km/h and m/s? 
  CarVelocity const rep3( Kilometer( 13. ), Hour::Invert( 1. / 2. ) );   
  Velocity const rep3_2( rep3 );
  Velocity const rep3_3( Kilometer( 13. ) / Hour( 2. ) );
  Scalar const _rep3 = rep3.GetValue();
  Scalar const _rep3_2 = rep3_2.GetValue();
  Assert( rep3 == rep3_3 );
  Assert( fequal( _rep3, 6.5000000000000 ) );
  Assert( fequal( _rep3_2, 1.8055555555556 ) );

  //4. Light from the sun reaches Earth in 8.3 min.  The velocity of light is 
  //   3.00 x 10 8 m/s.  How far is Earth from the sun? 
  Meter const rep4 = Velocity( 3.e8 ) * Minute( 8.3 );
  Scalar const _rep4 = rep4.GetValue();
  Assert( fequal( _rep4, 149400000000.00, 1.e8 ) );

  //5. You and a friend each drive 50 km.  You travel at 90 km/h, your friend 
  //   at 95 km/h.  How long will your friend wait for you at the end of the 
  //   trip? 
  Kilometer const fifty( 50. );
  Hour const rep5 = fifty / CarVelocity( 90. ) - fifty / CarVelocity( 95. );
  Scalar const _rep5 = rep5.GetValue();
  Assert( fequal( _rep5, 0.029239766081871 ) );

}

void SolveVelocityProblems2()
{
  //1. What is the velocity of a rocket that travels 9000 meters in 12.12 seconds? 
  Velocity const rep1 = Kilometer( 9. ) / Second( 12.12 );
  Scalar const _rep1 = rep1.GetValue(); 
  Assert( fequal( _rep1, 742.57425742574 ) );

  //2. What is the velocity of a jet plane that travels 528 meters in 4 seconds? 
  Velocity const rep2 = Hectometer( 5.28 ) / Decisecond( 40. );
  Scalar const _rep2 = rep2.GetValue();
  Assert( fequal( _rep2, 132.00000000000 ) );
 
  //3. After an impact involving a non-functioning satellite, a paint chip leaves the surface 
  //   of the satellite at a velocity of 96 m/s. After 17 seconds, how far has the chip landed? 
  Meter const rep3 = Velocity( 96. ) * Dekasecond( 1.7 );
  Scalar const _rep3 = rep3.GetValue(); 
  Assert( fequal( _rep3, 1632.0000000000 ) );

  //4. The space shuttle Endeavor is launched to altitude of 500 km above the surface of 
  //   the earth. The shuttle travels at an average rate of 700 m/s. How long will it take for 
  //   Endeavor to reach its orbit? 
  Second const rep4 = Megameter( .5 ) / Hectovelocity2( 7. );
  Scalar const _rep4 = rep4.GetValue();
  Assert( fequal( _rep4, 714.28571428571 ) );

  //5. How long will your trip take (in hours) if you travel 350 km at an average velocity of 
  //   80 km/hr? 
  Hour const rep5 = (Kilometer( 350. ) / CarVelocity( 80. ) );
  Scalar const _rep5 = rep5.GetValue();
  Assert( fequal( _rep5, 4.3750000000000 ) );

  //6. How many seconds will it take for a satellite to travel 450 km at a rate of 120 m/s? 
  Second const rep6 = Kilometer( 450. ) / Velocity( 120. );
  Scalar const _rep6 = rep6.GetValue();
  Assert( fequal( _rep6, 3750.0000000000 ) );

  //7. What is the velocity of a walking person in m/s if the person travels 1000 m in 20 
  //   minutes? 
  Velocity const rep7 = Meter( 1000. ) / Minute( 20. );
  Scalar const _rep7 = rep7.GetValue();
  Assert( fequal( _rep7, 0.83333333333333 ) );

  //8. How far (in meters) will you travel in 3 minutes running at a rate of 6 m/s? 
  Meter const rep8 = Minute( 3. ) * Velocity( 6. );
  Scalar const _rep8 = rep8.GetValue();
  Assert( fequal( _rep8, 1080.0000000000 ) );

  //9. A trip to cape Canaveral, Florida takes 10 hours. The distance is 816 km. 
  //   Calculate the average velocity. 
  CarVelocity rep9 = Kilometer( 816. ) / Hour( 10. );
  Scalar const _rep9 = rep9.GetValue();
  Assert( fequal( _rep9, 81.600000000000 ) );

}

void SolveVelocityProblems3()
{

  //1. The electron beam in a typical TV set sweeps out a complete picture in 0.030 seconds, 
  //   and each picture is composed of 525 lines. If the width of the screen is 50. cm, what 
  //   is the speed of the beam horizontally across the screen? 
  Velocity const rep1 = Centimeter( 50. ) * 525. / Second( .03 );
  Scalar const _rep1 = rep1.GetValue();
  Assert( fequal( _rep1, 8750.0 ) );


  //2. What is your average speed in each of these cases? 
  //     a) you run 100. m at a speed of 5.0 m/s and then walk 100. m at 1.0 m/s. 
  //     b) you run for 100. s at a speed of 5.0 m/s and then walk for 100. s at a speed of 1.0 m/s? 
  Velocity const rep2  = (Meter( 100. ) * 2.) / (Meter( 100. ) / Velocity( 5. ) + Meter( 100. ) / Velocity( 1. ));
  Velocity const rep2_2 = ( Velocity( 5. ) * Second( 100. ) + Velocity( 1. ) * Second( 100. ) ) / (Second( 100. ) * 2.);
  Scalar const _rep2 = rep2.GetValue();
  Scalar const _rep2_2 = rep2_2.GetValue();
  Assert( fequal( _rep2, 1.6666666666666667 ) );
  Assert( fequal( _rep2_2, 3.0 ) );

  //3. A rabbit and a turtle are practicing for their big race. The rabbit covers a 30. m practice course 
  //   in 5.0 seconds, the turtle covers the same distance in 120 seconds. If the actual race is run on a 96 m 
  //   course, by how many seconds will the rabbit beat the turtle? 
  Second const rep3 = Meter( 96. ) / (Meter( 30. ) / Second( 5. )) - Meter( 96. ) / (Meter( 120. ) / Second( 5. ));
  Scalar const _rep3 = rep3.GetValue();
  Assert( fequal( _rep3, 12.0 ) );

  //4. A tsunami caused by an earthquake occurring in Alaska in 1946 consisted of several huge waves 
  //   which were found to travel at the average speed of 790 km/hr. The first of the waves reached 
  //   Hawaii 4 hours 34 minutes after the earthquake occurred. From this data, calculate how far the origin 
  //   of the tsunami was from Hawaii. 
  Kilometer const rep4 = CarVelocity( 790. ) * (Hour( 4. ) + (Hour)Minute( 34 ) );
  Scalar const _rep4 = rep4.GetValue();
  Assert( fequal( _rep4, 3607.666666666667 ) );

  //5. Two cyclist race with nearly uniform speed on a 500. m course. The blue bicycle crosses the 
  //   finish line 2.0 s ahead of the red bicycle. If the red bicycle maintained an average speed of 10. m/s, 
  //   what was the average speed of the blue bicycle? 
  Velocity const rep5 = Meter( 500. ) / (Second(Meter( 500. ) / Velocity( 10. )) + Second( 2. ));
  Scalar const _rep5 = rep5.GetValue();
  Assert( fequal( _rep5, 9.6153846153846150 ) );

}
