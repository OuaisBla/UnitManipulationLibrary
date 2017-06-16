
#include "TestHelper.h"
#include "UnitFrequency.h"


using namespace Unit;
using namespace Unit::SI;
using namespace Unit::NonSI;

using Unit::Types::Scalar;

//
//  Compile time definition.
//
typedef Yottasecond::Invert Yoctohertz2;
typedef Zettasecond::Invert Zeptohertz2;
typedef Exasecond::Invert   Attohertz2;
typedef Petasecond::Invert  Femtohertz2;
typedef Terasecond::Invert  Picohertz2;
typedef Gigasecond::Invert  Nanohertz2;
typedef Megasecond::Invert  Microhertz2;
typedef Kilosecond::Invert  Millihertz2;
typedef Hectosecond::Invert Centihertz2;
typedef Dekasecond::Invert  Decihertz2;
typedef Second::Invert      Hertz2;
typedef Decisecond::Invert  Dekahertz2;
typedef Centisecond::Invert Hectohertz2;
typedef Millisecond::Invert Kilohertz2;
typedef Microsecond::Invert Megahertz2;
typedef Nanosecond::Invert  Gigahertz2;
typedef Picosecond::Invert  Terahertz2;
typedef Femtosecond::Invert Petahertz2;
typedef Attosecond::Invert  Exahertz2;
typedef Zeptosecond::Invert Zettahertz2;
typedef Yoctosecond::Invert Yottahertz2;



static void TestClassDefinition();
static void SeeClassDefinition();
static void TestCompileTimeDefinition();
static void TestConversionConstructor();
static void TestConversionAssignmentOperator();
static void TestCastOperator();


void TestFrequency()
{

  TestClassDefinition();
  SeeClassDefinition();
  TestCompileTimeDefinition();
  TestConversionConstructor();
  TestConversionAssignmentOperator();
  TestCastOperator();

}


void TestClassDefinition()
{

  Yoctohertz const yoctohertz( 1. );
  Assert( fequal( yoctohertz.GetValue(), 1. ) );
  Assert( fequal( yoctohertz.GetFactor(), 1.e-24 ) );

  Zeptohertz const zeptohertz( 1. );
  Assert( fequal( zeptohertz.GetValue(), 1. ) );
  Assert( fequal( zeptohertz.GetFactor(), 1.e-21 ) );

  Attohertz const attohertz( 1. );
  Assert( fequal( attohertz.GetValue(), 1. ) );
  Assert( fequal( attohertz.GetFactor(), 1.e-18 ) );

  Femtohertz const femtohertz( 1. );
  Assert( fequal( femtohertz.GetValue(), 1. ) );
  Assert( fequal( femtohertz.GetFactor(), 1.e-15 ) );

  Picohertz const picohertz( 1. );
  Assert( fequal( picohertz.GetValue(), 1. ) );
  Assert( fequal( picohertz.GetFactor(), 1.e-12 ) );

  Nanohertz const nanohertz( 1. );
  Assert( fequal( nanohertz.GetValue(), 1. ) );
  Assert( fequal( nanohertz.GetFactor(), 1.e-9 ) );

  Microhertz const microhertz( 1. );
  Assert( fequal( microhertz.GetValue(), 1. ) );
  Assert( fequal( microhertz.GetFactor(), 1.e-6 ) );

  Millihertz const millihertz( 1. );
  Assert( fequal( millihertz.GetValue(), 1. ) );
  Assert( fequal( millihertz.GetFactor(), .001 ) );

  Centihertz const centihertz( 1. );
  Assert( fequal( centihertz.GetValue(), 1. ) );
  Assert( fequal( centihertz.GetFactor(), .01 ) );

  Decihertz const decihertz( 1. );
  Assert( fequal( decihertz.GetValue(), 1. ) );
  Assert( fequal( decihertz.GetFactor(), .1 ) );

  Hertz const hertz( 1. );
  Assert( fequal( hertz.GetValue(), 1. ) );
  Assert( fequal( hertz.GetFactor(), 1. ) );

  Dekahertz const dekahertz( 1. );
  Assert( fequal( dekahertz.GetValue(), 1. ) );
  Assert( fequal( dekahertz.GetFactor(), 10. ) );

  Hectohertz const hectohertz( 1. );
  Assert( fequal( hectohertz.GetValue(), 1. ) );
  Assert( fequal( hectohertz.GetFactor(), 100. ) );

  Kilohertz const kilohertz( 1. );
  Assert( fequal( kilohertz.GetValue(), 1. ) );
  Assert( fequal( kilohertz.GetFactor(), 1000. ) );

  Megahertz const megahertz( 1. );
  Assert( fequal( megahertz.GetValue(), 1. ) );
  Assert( fequal( megahertz.GetFactor(), 1.e6 ) );

  Gigahertz const gigahertz( 1. );
  Assert( fequal( gigahertz.GetValue(), 1. ) );
  Assert( fequal( gigahertz.GetFactor(), 1.e9 ) );

  Terahertz const terahertz( 1. );
  Assert( fequal( terahertz.GetValue(), 1. ) );
  Assert( fequal( terahertz.GetFactor(), 1.e12 ) );

  Petahertz const petahertz( 1. );
  Assert( fequal( petahertz.GetValue(), 1. ) );
  Assert( fequal( petahertz.GetFactor(), 1.e15 ) );

  Exahertz const exahertz( 1. );
  Assert( fequal( exahertz.GetValue(), 1. ) );
  Assert( fequal( exahertz.GetFactor(), 1.e18 ) );

  Zettahertz const zettahertz( 1. );
  Assert( fequal( zettahertz.GetValue(), 1. ) );
  Assert( fequal( zettahertz.GetFactor(), 1.e21 ) );

  Yottahertz const yottahertz( 1. );
  Assert( fequal( yottahertz.GetValue(), 1. ) );
  Assert( fequal( yottahertz.GetFactor(), 1.e24 ) );

}

void SeeClassDefinition()
{
  OutputLine( L"-- Hertz --" );

  Femtohertz const femtohertz;
  OutputLine( femtohertz.GetSuffix() );
  OutputLine( Femtohertz::Suffix() );

  Picohertz const picohertz;
  OutputLine( picohertz.GetSuffix() );
  OutputLine( Picohertz::Suffix() );

  Nanohertz const nanohertz;
  OutputLine( nanohertz.GetSuffix() );
  OutputLine( Nanohertz::Suffix() );

  Microhertz const microhertz;
  OutputLine( microhertz.GetSuffix() );
  OutputLine( Microhertz::Suffix() );

  Millihertz const millihertz;
  OutputLine( millihertz.GetSuffix() );
  OutputLine( Millihertz::Suffix() );

  Centihertz const centihertz;
  OutputLine( centihertz.GetSuffix() );
  OutputLine( Centihertz::Suffix() );

  Decihertz const decihertz;
  OutputLine( decihertz.GetSuffix() );
  OutputLine( Decihertz::Suffix() );

  Hertz const hertz;
  OutputLine( hertz.GetSuffix() );
  OutputLine( Hertz::Suffix() );

  Dekahertz const dekahertz;
  OutputLine( dekahertz.GetSuffix() );
  OutputLine( Dekahertz::Suffix() );

  Hectohertz const hectohertz;
  OutputLine( hectohertz.GetSuffix() );
  OutputLine( Hectohertz::Suffix() );

  Kilohertz const kilohertz;
  OutputLine( kilohertz.GetSuffix() );
  OutputLine( Kilohertz::Suffix() );

  Megahertz const megahertz;
  OutputLine( megahertz.GetSuffix() );
  OutputLine( Megahertz::Suffix() );

  Gigahertz const gigahertz;
  OutputLine( gigahertz.GetSuffix() );
  OutputLine( Gigahertz::Suffix() );

  Terahertz const terahertz;
  OutputLine( terahertz.GetSuffix() );
  OutputLine( Terahertz::Suffix() );

  Petahertz const petahertz;
  OutputLine( petahertz.GetSuffix() );
  OutputLine( Petahertz::Suffix() );

}

void TestCompileTimeDefinition()
{

  Yoctohertz const yoctohertz = Identity() / Yottasecond( 1. );
  Assert( fequal( yoctohertz.GetValue(), 1. ) );

  Zeptohertz const zeptohertz = Identity() / Zettasecond( 1. );
  Assert( fequal( zeptohertz.GetValue(), 1. ) );

  Attohertz const attohertz = Identity() / Exasecond( 1. );
  Assert( fequal( attohertz.GetValue(), 1. ) );

  Femtohertz const femtohertz = Identity() / Petasecond( 1. );
  Assert( fequal( femtohertz.GetValue(), 1. ) );

  Picohertz const picohertz = Identity() / Terasecond( 1. );
  Assert( fequal( picohertz.GetValue(), 1. ) );

  Nanohertz const nanohertz = Identity() / Gigasecond( 1. );
  Assert( fequal( nanohertz.GetValue(), 1. ) );

  Microhertz const microhertz = Identity() / Megasecond( 1. );
  Assert( fequal( microhertz.GetValue(), 1. ) );

  Millihertz const millihertz = Identity() / Kilosecond( 1. );
  Assert( fequal( millihertz.GetValue(), 1. ) );

  Centihertz const centihertz = Identity() / Hectosecond( 1. );
  Assert( fequal( centihertz.GetValue(), 1. ) );

  Decihertz const decihertz = Identity() / Dekasecond( 1. );
  Assert( fequal( decihertz.GetValue(), 1. ) );

  Hertz const hertz = Identity() / Second( 1. );
  Assert( fequal( hertz.GetValue(), 1. ) );

  Dekahertz const dekahertz = Identity() / Decisecond( 1. );
  Assert( fequal( dekahertz.GetValue(), 1. ) );

  Hectohertz const hectohertz = Identity() / Centisecond( 1. );
  Assert( fequal( hectohertz.GetValue(), 1. ) );

  Kilohertz const kilohertz = Identity() / Millisecond( 1. );
  Assert( fequal( kilohertz.GetValue(), 1. ) );

  Megahertz const megahertz = Identity() / Microsecond( 1. );
  Assert( fequal( megahertz.GetValue(), 1. ) );

  Gigahertz const gigahertz = Identity() / Nanosecond( 1. );
  Assert( fequal( gigahertz.GetValue(), 1. ) );
  
  Terahertz const terahertz = Identity() / Picosecond( 1. );
  Assert( fequal( terahertz.GetValue(), 1. ) );

  Petahertz const petahertz = Identity() / Femtosecond( 1. );
  Assert( fequal( petahertz.GetValue(), 1. ) );

  Exahertz const exahertz = Identity() / Attosecond( 1. );
  Assert( fequal( exahertz.GetValue(), 1. ) );

  Zettahertz const zettahertz = Identity() / Zeptosecond( 1. );
  Assert( fequal( zettahertz.GetValue(), 1. ) );

  Yottahertz const yottahertz = Identity() / Yoctosecond( 1. );
  Assert( fequal( yottahertz.GetValue(), 1. ) );


  Yoctohertz2 const yoctohertz2 = yoctohertz;
  Assert( fequal( yoctohertz.GetFactor(), yoctohertz2.GetFactor() ) );

  Zeptohertz2 const zeptohertz2 = zeptohertz;
  Assert( fequal( yoctohertz.GetFactor(), yoctohertz2.GetFactor() ) );

  Attohertz2 const attohertz2 = attohertz;
  Assert( fequal( attohertz.GetFactor(), attohertz2.GetFactor() ) );

  Femtohertz2 const femtohertz2 = femtohertz;
  Assert( fequal( femtohertz.GetFactor(), femtohertz.GetFactor() ) );

  Picohertz2 const picohertz2 = picohertz;
  Assert( fequal( picohertz.GetFactor(), picohertz2.GetFactor() ) );

  Nanohertz2 const nanohertz2 = yoctohertz;
  Assert( fequal( nanohertz.GetFactor(), nanohertz2.GetFactor() ) );

  Microhertz2 const microhertz2 = microhertz;
  Assert( fequal( microhertz.GetFactor(), microhertz2.GetFactor() ) );

  Millihertz2 const millihertz2 = millihertz;
  Assert( fequal( millihertz.GetFactor(), millihertz2.GetFactor() ) );

  Centihertz2 const centihertz2 = centihertz;
  Assert( fequal( centihertz.GetFactor(), centihertz2.GetFactor() ) );

  Decihertz2 const decihertz2 = decihertz;
  Assert( fequal( decihertz.GetFactor(), decihertz2.GetFactor() ) );

  Dekahertz2 const dekahertz2 = dekahertz;
  Assert( fequal( dekahertz.GetFactor(), dekahertz2.GetFactor() ) );

  Hectohertz2 const hectohertz2 = hectohertz;
  Assert( fequal( hectohertz.GetFactor(), hectohertz2.GetFactor() ) );

  Kilohertz2 const kilohertz2 = kilohertz;
  Assert( fequal( kilohertz.GetFactor(), kilohertz2.GetFactor() ) );

  Megahertz2 const megahertz2 = megahertz;
  Assert( fequal( megahertz.GetFactor(), megahertz2.GetFactor() ) );

  Gigahertz2 const gigahertz2 = gigahertz;
  Assert( fequal( gigahertz.GetFactor(), gigahertz2.GetFactor() ) );
  
  Terahertz2 const terahertz2 = terahertz;
  Assert( fequal( terahertz.GetFactor(), terahertz2.GetFactor() ) );

  Petahertz2 const petahertz2 = petahertz;
  Assert( fequal( petahertz.GetFactor(), petahertz2.GetFactor() ) );

  Exahertz2 const exahertz2 = exahertz;
  Assert( fequal( exahertz.GetFactor(), exahertz2.GetFactor() ) );

  Zettahertz2 const zettahertz2 = zettahertz;
  Assert( fequal( zettahertz.GetFactor(), zettahertz2.GetFactor() ) );

  Yottahertz2 const yottahertz2 = yottahertz;
  Assert( fequal( yottahertz.GetFactor(), yottahertz2.GetFactor() ) );

}

void TestConversionConstructor()
{

}

void TestConversionAssignmentOperator()
{

}

void TestCastOperator()
{
  Hertz2 const unit_2_hertz( 2. );
  Kilohertz2 const unit_5_kilohertz( 5. );
  Millihertz2 const unit_1_millihertz( 1. );

  Scalar const s1 = unit_2_hertz / unit_2_hertz;
  Assert( fequal( s1, 1. ) );

  Scalar const s2 = unit_5_kilohertz / unit_1_millihertz;
  Assert( fequal( s2, 5000000. ) );

  Scalar const s3 = unit_2_hertz / unit_5_kilohertz;
  Assert( fequal( s3, 0.0004 ) );

  Scalar const s4 = unit_5_kilohertz * Millisecond( 1. );
  Assert( fequal( s4, 5. ) );

  Scalar const s5 = unit_5_kilohertz * Second( 1. );
  Assert( fequal( s5, 5000. ) );

  Scalar const s6 = Hertz( 1. ) * Second( 1. );
  Assert( fequal( s6, 1. ) );

  Scalar const s7 = Kilohertz( 1. ) * Second( 1. );
  Assert( fequal( s7, 1000. ) );
}
