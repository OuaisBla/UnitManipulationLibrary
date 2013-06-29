
#include "UnitAcceleration.h"

#include <iostream>


using namespace Unit;
using namespace Unit::SI;
using namespace Unit::NonSI;



//
// Other form for Acceleration.
//
typedef Product<Second> SquareSecond;
typedef Product<Meter,SquareSecond::Invert> Acceleration3;

typedef Product<SquareSecond::Invert, Meter> Acceleration4;


//
//  Compile time definition.
//
typedef Product<Velocity, Petasecond::Invert>  Femtoacceleration2;
typedef Product<Velocity, Terasecond::Invert>  Picoacceleration2;
typedef Product<Velocity, Gigasecond::Invert>  Nanoacceleration2;
typedef Product<Velocity, Megasecond::Invert>  Microacceleration2;
typedef Product<Velocity, Kilosecond::Invert>  Milliacceleration2;
typedef Product<Velocity, Hectosecond::Invert> Centiacceleration2;
typedef Product<Velocity, Dekasecond::Invert>  Deciacceleration2;
typedef Product<Velocity, Decisecond::Invert>  Dekaacceleration2;
typedef Product<Velocity, Centisecond::Invert> Hectoacceleration2;
typedef Product<Velocity, Millisecond::Invert> Kiloacceleration2;
typedef Product<Velocity, Microsecond::Invert> Megaacceleration2;
typedef Product<Velocity, Nanosecond::Invert>  Gigaacceleration2;
typedef Product<Velocity, Picosecond::Invert>  Teraacceleration2;
typedef Product<Velocity, Femtosecond::Invert> Petaacceleration2;



typedef Product<Kilometer,Hour::Invert>  CarSpeed;
typedef Product<Kilometer,Product<Hour::Invert> >  CarAccel;


void Assert( bool );
bool fequal( double, double );


static void TestClassDefinition();
static void SeeClassDefinition();
static void TestCompileTimeDefinition();
static void SolveAccelerationProblems1();
static void SolveAccelerationProblems2();
static void SolveAccelerationProblems3();
static void SolveAccelerationProblems4();


void TestAcceleration()
{

  TestClassDefinition();
  SeeClassDefinition();
  TestCompileTimeDefinition();
  SolveAccelerationProblems1();
  SolveAccelerationProblems2();
  SolveAccelerationProblems3();
  SolveAccelerationProblems4();

}


void TestClassDefinition()
{
  Femtoacceleration const femtoacceleration( 1. );
  Assert( fequal( femtoacceleration.GetValue(), 1. ) );
  Assert( fequal( femtoacceleration.GetFactor(), 1.e-15 ) );

  Picoacceleration const picoacceleration( 1. );
  Assert( fequal( picoacceleration.GetValue(), 1. ) );
  Assert( fequal( picoacceleration.GetFactor(), 1.e-12 ) );

  Nanoacceleration const nanoacceleration( 1. );
  Assert( fequal( nanoacceleration.GetValue(), 1. ) );
  Assert( fequal( nanoacceleration.GetFactor(), 1.e-9 ) );

  Microacceleration const microacceleration( 1. );
  Assert( fequal( microacceleration.GetValue(), 1. ) );
  Assert( fequal( microacceleration.GetFactor(), 1.e-6 ) );

  Milliacceleration const milliacceleration( 1. );
  Assert( fequal( milliacceleration.GetValue(), 1. ) );
  Assert( fequal( milliacceleration.GetFactor(), 1.e-3 ) );

  Centiacceleration const centiacceleration( 1. );
  Assert( fequal( centiacceleration.GetValue(), 1. ) );
  Assert( fequal( centiacceleration.GetFactor(), 1.e-2 ) );

  Deciacceleration const deciacceleration( 1. );
  Assert( fequal( deciacceleration.GetValue(), 1. ) );
  Assert( fequal( deciacceleration.GetFactor(), 1.e-1 ) );

  Acceleration const acceleration( 1. );
  Assert( fequal( acceleration.GetValue(), 1. ) );
  Assert( fequal( acceleration.GetFactor(), 1. ) );

  Dekaacceleration const dekaacceleration( 1. );
  Assert( fequal( dekaacceleration.GetValue(), 1. ) );
  Assert( fequal( dekaacceleration.GetFactor(), 1.e1 ) );

  Hectoacceleration const hectoacceleration( 1. );
  Assert( fequal( hectoacceleration.GetValue(), 1. ) );
  Assert( fequal( hectoacceleration.GetFactor(), 1.e2 ) );

  Kiloacceleration const kiloacceleration( 1. );
  Assert( fequal( kiloacceleration.GetValue(), 1. ) );
  Assert( fequal( kiloacceleration.GetFactor(), 1.e3 ) );

  Megaacceleration const megaacceleration( 1. );
  Assert( fequal( megaacceleration.GetValue(), 1. ) );
  Assert( fequal( megaacceleration.GetFactor(), 1.e6 ) );

  Gigaacceleration const gigaacceleration( 1. );
  Assert( fequal( gigaacceleration.GetValue(), 1. ) );
  Assert( fequal( gigaacceleration.GetFactor(), 1.e9 ) );

  Teraacceleration const teraacceleration( 1. );
  Assert( fequal( teraacceleration.GetValue(), 1. ) );
  Assert( fequal( teraacceleration.GetFactor(), 1.e12 ) );

  Petaacceleration const petaacceleration( 1. );
  Assert( fequal( petaacceleration.GetValue(), 1. ) );
  Assert( fequal( petaacceleration.GetFactor(), 1.e15 ) );

  CarAccel const caracceleration( 1. );
  Assert( fequal( caracceleration.GetValue(), 1. ) );
  //Assert( fequal( caracceleration.GetFactor(), .27777777777777777777777777777778 ) );
}

void SeeClassDefinition()
{
  std::wcout << "-- Acceleration --" << std::endl;

  Femtoacceleration const femtoacceleration;
  std::wcout << femtoacceleration.GetSuffix() << std::endl;

  Picoacceleration const picoacceleration;
  std::wcout << picoacceleration.GetSuffix() << std::endl;

  Nanoacceleration const nanoacceleration;
  std::wcout << nanoacceleration.GetSuffix() << std::endl;

  Microacceleration const microacceleration;
  std::wcout << microacceleration.GetSuffix() << std::endl;

  Milliacceleration const milliacceleration;
  std::wcout << milliacceleration.GetSuffix() << std::endl;

  Centiacceleration const centiacceleration;
  std::wcout << centiacceleration.GetSuffix() << std::endl;

  Deciacceleration const deciacceleration;
  std::wcout << deciacceleration.GetSuffix() << std::endl;

  Acceleration const acceleration;
  std::wcout << acceleration.GetSuffix() << std::endl;

  Dekaacceleration const dekaacceleration;
  std::wcout << dekaacceleration.GetSuffix() << std::endl;

  Hectoacceleration const hectoacceleration;
  std::wcout << hectoacceleration.GetSuffix() << std::endl;

  Kiloacceleration const kiloacceleration;
  std::wcout << kiloacceleration.GetSuffix() << std::endl;

  Megaacceleration const megaacceleration;
  std::wcout << megaacceleration.GetSuffix() << std::endl;

  Gigaacceleration const gigaacceleration;
  std::wcout << gigaacceleration.GetSuffix() << std::endl;

  Teraacceleration const teraacceleration;
  std::wcout << teraacceleration.GetSuffix() << std::endl;

  Petaacceleration const petaacceleration;
  std::wcout << petaacceleration.GetSuffix() << std::endl;

  Femtoacceleration2 const femtoacceleration2;
  std::wcout << femtoacceleration2.GetSuffix() << std::endl;

  Picoacceleration2 const picoacceleration2;
  std::wcout << picoacceleration2.GetSuffix() << std::endl;

  Nanoacceleration2 const nanoacceleration2;
  std::wcout << nanoacceleration2.GetSuffix() << std::endl;

  Microacceleration2 const microacceleration2;
  std::wcout << microacceleration2.GetSuffix() << std::endl;

  Milliacceleration2 const milliacceleration2;
  std::wcout << milliacceleration2.GetSuffix() << std::endl;

  Centiacceleration2 const centiacceleration2;
  std::wcout << centiacceleration2.GetSuffix() << std::endl;

  Deciacceleration2 const deciacceleration2;
  std::wcout << deciacceleration2.GetSuffix() << std::endl;

  Dekaacceleration2 const dekaacceleration2;
  std::wcout << dekaacceleration2.GetSuffix() << std::endl;

  Hectoacceleration2 const hectoacceleration2;
  std::wcout << hectoacceleration2.GetSuffix() << std::endl;

  Kiloacceleration2 const kiloacceleration2;
  std::wcout << kiloacceleration2.GetSuffix() << std::endl;

  Megaacceleration2 const megaacceleration2;
  std::wcout << megaacceleration2.GetSuffix() << std::endl;

  Gigaacceleration2 const gigaacceleration2;
  std::wcout << gigaacceleration2.GetSuffix() << std::endl;

  Teraacceleration2 const teraacceleration2;
  std::wcout << teraacceleration2.GetSuffix() << std::endl;

  Petaacceleration2 const petaacceleration2;
  std::wcout << petaacceleration2.GetSuffix() << std::endl;

  CarAccel const caraccel;
  std::wcout << caraccel.GetSuffix() << std::endl;

  Acceleration3 const accel3;
  std::wcout << accel3.GetSuffix() << std::endl;

  Acceleration4 const accel4;
  std::wcout << accel4.GetSuffix() << std::endl;
  
}



void TestCompileTimeDefinition()
{

  Femtoacceleration const femtoacceleration = (Nanometer( 1. ) / Megasecond( 1. )) / Second( 1. );
  Assert( fequal( femtoacceleration.GetValue(), 1. ) );

  Nanoacceleration const nanoacceleration = (Nanometer( 1. ) / Second( 1. )) / Second( 1. );
  Assert( fequal( nanoacceleration.GetValue(), 1. ) );

  Microacceleration const microacceleration = Meter( 1. ) / (Megasecond( 1. ) * Second( 1. ));
  Assert( fequal( microacceleration.GetValue(), 1. ) );

  Milliacceleration const milliacceleration = Decimeter( 1. ) / (Hectosecond( 1. ) * Second( 1. ));
  Assert( fequal( milliacceleration.GetValue(), 1. ) );

  Centiacceleration const centiacceleration = (Centimeter( 1. ) / Second( 1. )) / Second( 1. );
  Assert( fequal( centiacceleration.GetValue(), 1. ) );

  Deciacceleration const deciacceleration = Decimeter( 1. ) / (Second( 1. ) * Second( 1. ));
  Assert( fequal( deciacceleration.GetValue(), 1. ) );

  Dekaacceleration const dekaacceleration = Dekameter( 1. ) / (Second( 1. ) * Second( 1. ));
  Assert( fequal( dekaacceleration.GetValue(), 1. ) );

  Hectoacceleration const hectoacceleration = Dekameter( 1. ) / (Decisecond( 1. ) * Second( 1. ));
  Assert( fequal( hectoacceleration.GetValue(), 1. ) );

  Kiloacceleration const kiloacceleration = (Kilometer( 1. ) / Second( 1. )) / Second( 1. );
  Assert( fequal( kiloacceleration.GetValue(), 1. ) );

  Megaacceleration const megaacceleration = Kilometer( 1. ) / (Millisecond( 1. ) * Second( 1. ));
  Assert( fequal( megaacceleration.GetValue(), 1. ) );


  Femtoacceleration2 const femtoacceleration2 = femtoacceleration;
  Assert( fequal( femtoacceleration.GetFactor(), femtoacceleration2.GetFactor() ) );

  Nanoacceleration2 const nanoacceleration2 = nanoacceleration;
  Assert( fequal( nanoacceleration.GetFactor(), nanoacceleration2.GetFactor() ) );

  Microacceleration2 const microacceleration2 = microacceleration;
  Assert( fequal( microacceleration.GetFactor(), microacceleration2.GetFactor() ) );

  Milliacceleration2 const milliacceleration2 = milliacceleration;
  Assert( fequal( milliacceleration.GetFactor(), milliacceleration2.GetFactor() ) );

  Centiacceleration2 const centiacceleration2 = centiacceleration;
  Assert( fequal( centiacceleration.GetFactor(), centiacceleration2.GetFactor() ) );

  Deciacceleration2 const deciacceleration2 = deciacceleration;
  Assert( fequal( deciacceleration.GetFactor(), deciacceleration2.GetFactor() ) );

  Acceleration3 const acceleration3 = Acceleration();
  Assert( fequal( Acceleration().GetFactor(), acceleration3.GetFactor() ) );

  Acceleration4 const acceleration4( Acceleration(1.0) );
  Assert( fequal( Acceleration().GetFactor(), acceleration3.GetFactor() ) );

  Acceleration3 const acceleration32 = acceleration3;
  Assert( fequal( Acceleration().GetFactor(), acceleration32.GetFactor() ) );

  Dekaacceleration2 const dekaacceleration2 = dekaacceleration;
  Assert( fequal( dekaacceleration.GetFactor(), dekaacceleration2.GetFactor() ) );

  Hectoacceleration2 const hectoacceleration2 = hectoacceleration;
  Assert( fequal( hectoacceleration.GetFactor(), hectoacceleration2.GetFactor() ) );

  Kiloacceleration2 const kiloacceleration2 = kiloacceleration;
  Assert( fequal( kiloacceleration.GetFactor(), kiloacceleration2.GetFactor() ) );

  Megaacceleration2 const megaacceleration2 = megaacceleration;
  Assert( fequal( megaacceleration.GetFactor(), megaacceleration2.GetFactor() ) );

  Scalar s = acceleration3 / acceleration4;

}

void SolveAccelerationProblems1()
{
  //1. A flower pot falls from a windowsill 25.0 m above the sidewalk.   
  //   How much time does a person below have to move out of the way?  
  //   How fast is the flower pot moving when it strikes the ground? 
  Meter const potfalls( 25. );
  SquareSecond const falloffsquaretime = (potfalls * 2.) / Acceleration3( 9.8 );
  Second const rep1 = sqrt( falloffsquaretime );
  Velocity const rep1_2 = potfalls / rep1;
  Scalar const _rep1 = rep1.GetValue();
  Scalar const _rep1_2 = rep1_2.GetValue();

  //2. A plane, starting from rest at one end of a runway, undergoes a 
  //   constant acceleration of 1.6 m/s2 for a distance of 1600 m before 
  //   takeoff.  What is its speed upon takeoff?  What is the time required 
  //   for takeoff?
  Meter const planedistance( 1600. );
  SquareSecond const squaretime2 = (planedistance * 2.) / Acceleration3( 1.6 );
  Second const rep2 = sqrt( squaretime2 );
  Velocity const rep2_2 = planedistance / rep2;
  Scalar const _rep2 = rep2.GetValue();
  Scalar const _rep2_2 = rep2_2.GetValue(); 

}

void SolveAccelerationProblems2()
{
  //1. In 0.5 seconds, a projectile goes from 0 to 300 m/s. What is the acceleration of the 
  //   projectile? 
  Acceleration const rep1 = Velocity( 300. ) / Second( .5 );
  Scalar const _rep1 = rep1.GetValue();

  //2. A meteoroid changed velocity from 1.0 km/s to 1.8 km/s in 0.03 seconds. What is
  //   the acceleration of the meteoroid? 
  Acceleration const rep2 = (Kilovelocity( 1.8 ) - Kilovelocity( 1. )) / Second( .03 );
  Scalar const _rep2 = rep2.GetValue();

  //3. The space shuttle releases a space telescope into orbit around the earth. The 
  //   telescope goes from being stationary to traveling at a speed of 1700 m/s in 25 
  //   seconds. What is the acceleration of the satellite? 
  Acceleration const rep3 = Velocity( 1700. ) / Second( 25. );
  Scalar const _rep3 = rep3.GetValue();

  //4. A dragster in a race accelerated from stop to 60 m/s by the time it reached the 
  //   finish line. The  dragster moved in a straight line and traveled from the starting line to
  //   the finish line in 8.0 sec.   What was the acceleration of the dragster? 
  Acceleration const rep4 = Velocity( 60. ) / Second( 8. );
  Scalar const _rep4 = rep4.GetValue();

}

void SolveAccelerationProblems3()
{
  //  1. An ice cream truck is moving along at 20 m/s (its initial velocity.) It then speeds up 
  //     (accelerates) for 5 seconds at 8 m/s2. What distance would the truck travel in this time 
  //     interval? 
  Meter const rep1 = (Velocity(20.) * Second(5.)) + (0.5 * SquareSecond(5.) * Acceleration4( 8. ) );
  Assert( rep1 == Meter( 120. ) );

  //  2. What velocity would be attained by rolling ball which is accelerated at 0.30 m/s2 over a 
  //     distance of 50. m. The starting velocity was 0.50 m/s and the force that caused the acceleration 
  //     was applied for 5.0 seconds. 
  //Velocity const rep2 = Velocity( .5 ) + 

  //  3. If a calculator falls off the side of student desk and hits the floor 0.39 seconds later, 
  //     how tall is the desk and how fast would the calculator be traveling when it hits the floor? 

 
  //  4. If a rocket in space is moving at a constant velocity of 9.8 m/s and then uses its propulsion 
  //     system to accelerate to 10. m/s during a 3.0 minute burn, what would be the acceleration 
  //     of the rocket? 

 
  //  5. A car, initially traveling with a uniform velocity, accelerates at a rate of 1.0 m/s2 for a 
  //     period of 12 seconds. If the car traveled 190 m during this 12 second period, what was the 
  //     velocity of the car when it started to accelerate? 


  //  6. A ball rolls down an inclined plane with a constant acceleration of 2.5 m/s2: 
  //            a) how fast is the ball traveling after 3 seconds? 
  //            b) how far has the ball traveled in those 3 seconds? 
  //            c) how far has the ball traveled by the time its velocity is 15 m/s? 

 

  //  7. If you travel one mile at a speed of 1000 mi/h and another mile at 1 mi/h, what is your 
  //     average speed? 

  //  8. A pedestrian is running at his maximum speed of 6.0 m/s to catch a bus stopped by a traffic 
  //  light. When he is 25 meters away from the bus the light changes and the bus accelerates uniformly 
  //  at 1.0 m/s2. Find either; how far he has to run to catch the bus, or his frustration distance 
  //  (closest approach). You may use graphs, charts, appropriate equations, tables, and/or computers. 

  
}


void SolveAccelerationProblems4()
{
 
  //  1. A body with an initial velocity of 8 m/s moves with a constant acceleration and travels 640 m in 40 
  //     seconds. Find its acceleration. 
  //     (a = 0.4 m/s2) 

  //  2. A box slides down an inclined plane with a uniform acceleration and attains a velocity of 27 m/s in 3 
  //     seconds from rest. Find the final velocity and distance moved in 6 seconds (initially at rest). 
  //     (Vf = 54 m/s, d = 162 m) 

  //  3. A car has a uniformly accelerated motion of 5 m/s2. Find the speed acquired and distance traveled 
  //     in 4 seconds from rest. 
  //     (Vf = 20 m/s, d = 40m) 

  //  4. Before leaving the ground an airplane traveling with constant acceleration makes a run on the runway 
  //     of 1800 m in 12 seconds. Find 
  //       a) acceleration 
  //       b) speed at which it leaves the ground 
  //       c) distance traveled during the first and twelfth seconds.     
  //     (a) 25 m/s2 b) 300 m/s c) 12.5 m, 288 m

  //  5. A marble is dropped from a bridge and strikes the water in 5 seconds. Calculate the speed with which 
  //     it strikes and the height of the bridge. 
  //     (Vf = 49 m/s, d = 122 m) 

  //  6. A car starts from rest and accelerates uniformly to a velocity of 80 ft/s after traveling 250 ft. 
  //     Find its acceleration.        
  //     (a=12.8ft/s2) 

  //  7. What velocity is attained by an object which is accelerated at 0.30 m/s2 for a distance of 50. m 
  //     with a starting velocity of 0.0 m/s? 
  //     (Vf = 6 m/s) 

}
