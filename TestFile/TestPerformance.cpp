
#include "stdafx.h"
#include "UnitTime.h"
#include "UnitLength.h"
#include <time.h>


using namespace Unit;
using namespace Unit::SI;
using namespace Unit::NonSI;


static void PrintPerformance( clock_t , clock_t );
static void TestSimple_T_F();
static void TestSimple_Exp1_F();
static void TestSimple_ExpMinus1_F();

#ifdef _DEBUG
static int const nbloop = 1000000;
#else
static int const nbloop = 10000000;
#endif

/*
  clock_t const startraw = clock();
  for( int x = 0; x < nbloop; ++x )
  {
  }
  clock_t const endraw = clock();

  clock_t const startunit = clock();
  for( int y = 0; y < nbloop; ++y )
  {
  }
  clock_t const endunit = clock();
*/

void TestRunTimePerformance()
{

  TestSimple_T_F();
  TestSimple_Exp1_F();
  TestSimple_ExpMinus1_F();

}

void TestSimple_T_F()
{


}

void TestSimple_Exp1_F()
{

  OutputLine( L" -- Test Simple<S<T,1>,F> form. --" );

  volatile Scalar s = 0;

  clock_t const startraw = clock();
  for( int x = 0; x < nbloop; ++x )
  {
    
    volatile Scalar s0;
    volatile Scalar const s1 = 2.;
    volatile Scalar const s2 = s1;
    volatile Scalar const s3 = s1 + s2;
    volatile Scalar const s4 = s1 * 2.;
    volatile Scalar const s5 = 1. * 1000.;
    s0 = 2. * nbloop;
    s0 += s1;
    s0 -= s5;
    s += s0 + s1 + s2 + s3 + s4 + s5;

  }
  clock_t const endraw = clock();

  Meter m;

  clock_t const startunit = clock();
  for( int y = 0; y < nbloop; ++y )
  {

    Meter m0;
    Meter const m1( 2. );
    Meter const m2 = m1;
    Meter const m3 = m1 + m2;
    Meter const m4 = m1 * 2.;
    Meter const m5 = Kilometer( 1. );
    m0 = 2. * nbloop;
    m0 += m1;
    m0 -= m5;
    m += m0 + m1 + m2 + m3 + m4 + m5;

  }
  clock_t const endunit = clock();

  if( m.GetValue() != s )
  {
    OutputLine( L"Implementation error while processing test." );
  }

  PrintPerformance( endraw - startraw, endunit - startunit );

}

void TestSimple_ExpMinus1_F()
{

}

void PrintPerformance( clock_t const rawdiff, clock_t const unitdiff )
{
  Second const rawtime( Scalar( rawdiff ) / CLOCKS_PER_SEC );
  Second const unittime( Scalar( unitdiff ) / CLOCKS_PER_SEC ); 
  Second const difftime = unittime - rawtime;

  OutputLine( L"Raw time: " + ToString( rawtime.GetValue() ) + rawtime.GetSuffix() );
  OutputLine( L"Unit time: " + ToString( unittime.GetValue() )  + unittime.GetSuffix() );
  OutputLine( L"Time difference: " + ToString( difftime.GetValue() ) + difftime.GetSuffix() );

  OutputLine( L"Performance factor: " + ToString( unittime / rawtime) );
}
