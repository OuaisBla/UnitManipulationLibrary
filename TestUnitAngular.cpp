

#include "UnitAngular.h"
#include <iostream>

using namespace Unit;
using namespace Unit::SI;
using namespace Unit::NonSI;


void Assert( bool );
bool fequal( double, double );


void TestAngular()
{

  Radian const rad( 1. );
  Assert( fequal( rad.GetValue(), 1. ) );
  Assert( fequal( rad.GetConvertedValue(), 1. ) );
  Assert( fequal( rad.GetFactor(), 1. ) );

  AngularSecond const second( 1. );
  Assert( fequal( second.GetValue(), 1. ) );
  Assert( fequal( second.GetConvertedValue(), second.GetFactor() ) );

  Degree const degree( 1. );
  Assert( fequal( degree.GetValue(), 1. ) );
  Assert( fequal( degree.GetConvertedValue(), degree.GetFactor() ) );


  Radian const pi( 3.1415926535897932384626433832795 );
  Degree const unit_180_degree = pi;
  AngularMinute const unit_10800_minute = pi;

  Assert( fequal( pi.sin(), 0. ) );
  Assert( fequal( pi.cos(), -1. ) );
  Assert( fequal( pi.tan(), 0. ) );

  Assert( fequal( unit_180_degree.GetValue(), 180. ) );
  Assert( fequal( unit_180_degree.sin(), 0. ) );
  Assert( fequal( unit_180_degree.cos(), -1. ) );
  Assert( fequal( unit_180_degree.tan(), 0. ) );

  Assert( fequal( unit_10800_minute.GetValue(), 10800. ) );
  Assert( fequal( unit_10800_minute.sin(), 0. ) );
  Assert( fequal( unit_10800_minute.cos(), -1. ) );
  Assert( fequal( unit_10800_minute.tan(), 0. ) );

  Assert( Degree( 360. ) == Grade( 400. ) );
  Assert( Degree( 1.) == AngularMinute( 60. ) );
  Assert( Degree( 1.) == AngularSecond( 3600. ) );
  
  Degree toNormalize( 0. );
  toNormalize.Normalize();
  Assert( fequal( toNormalize.GetValue(), 0. ) );

  toNormalize = 360.;
  toNormalize.Normalize();
  Assert( fequal( toNormalize.GetValue(), 0. ) );

  toNormalize = -540.;
  toNormalize.Normalize();
  Assert( fequal( toNormalize.GetValue(), 180. ) );
  Assert( fequal( toNormalize.sin(), 0. ) );
  Assert( fequal( toNormalize.cos(), -1. ) );
  Assert( fequal( toNormalize.tan(), 0. ) );


  std::wcout << Radian::Suffix() << std::endl;
  std::wcout << Degree::Suffix() << std::endl;
  std::wcout << Grade::Suffix() << std::endl;
  std::wcout << AngularMinute::Suffix() << std::endl;
  std::wcout << AngularSecond::Suffix() << std::endl;

}
