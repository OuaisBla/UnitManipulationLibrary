
#include "stdafx.h"
#include "UnitFrequency.h"


using namespace Unit;
using namespace Unit::SI;



static void TestBinaryOperator();




void TestUnitIdentity()
{

  Identity const identity;

  Scalar const one_factor = identity.ConversionFactor();
  Assert( fequal( one_factor, 1. ) );

  TestBinaryOperator();

}

void TestBinaryOperator()
{

  Second t1 = Second( 1. ) * Identity();
  Assert( fequal( t1.GetValue(), 1. ) );

  Second t2 = Identity() * Second( 1. );
  Assert( fequal( t2.GetValue(), 1. ) );

  Second t3 = Second( 1. ) / Identity();
  Assert( fequal( t3.GetValue(), 1. ) );

  Hertz h1 = Identity() / Second( 1. );
  Assert( fequal( h1.GetValue(), 1. ) );

}
