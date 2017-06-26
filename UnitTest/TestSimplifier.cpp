#include "TestHelper.h"
#include "UnitAcceleration.h"
#include "UnitArea.h"
#include "UnitFrequency.h"
#include "UnitConstants.h"

using namespace Unit;
using namespace Unit::SI;
using namespace Unit::NonSI;
using namespace Unit::Types;

using Unit::Types::Scalar;


void TestSimplifier()
{
  Integer const _lengthBaseTypeValue = Length::SimplifiedType::NumeratorBaseTypeValue;
  Integer const _areaBaseTypeValue = Area::SimplifiedType::NumeratorBaseTypeValue;
  Integer const _timeBaseTypeValue = Time::SimplifiedType::NumeratorBaseTypeValue;


  ComplexUnit<Length::SimplifiedType, Length::SimplifiedType>::SimplifiedType _lengthReduced;
  ComplexUnit<Length::SimplifiedType, Time::SimplifiedType>::SimplifiedType _lengthTimeReduced;
  ComplexUnit<Hertz::SimplifiedType, Time::SimplifiedType>::SimplifiedType _FrequencyTimeReduced;
  ComplexUnit<Time::SimplifiedType, Velocity::SimplifiedType>::SimplifiedType _TimeVelocityReduced;


  Integer const _lengthReducedBaseTypeValue = _lengthReduced.NumeratorBaseTypeValue;

  Assert( _lengthReducedBaseTypeValue != _lengthBaseTypeValue );
  Assert( _lengthReducedBaseTypeValue == _areaBaseTypeValue );


  Integer const _lengthTimeReducedBaseTypeValue = _lengthTimeReduced.NumeratorBaseTypeValue;

  Assert( _lengthTimeReducedBaseTypeValue != _lengthBaseTypeValue );
  Assert( _lengthTimeReducedBaseTypeValue != _timeBaseTypeValue );
  Assert( _lengthTimeReducedBaseTypeValue == _lengthBaseTypeValue * _timeBaseTypeValue );

  Integer const _FrequencyTimeReducedBaseTypeValue = _FrequencyTimeReduced.NumeratorBaseTypeValue;

  Assert( _FrequencyTimeReducedBaseTypeValue == 1 );

  Integer const _TimeVelocityReducedBaseTypeValue = _TimeVelocityReduced.NumeratorBaseTypeValue;

  Assert( _TimeVelocityReducedBaseTypeValue == _lengthBaseTypeValue );

}


void TestConstants()
{


  Unit::Object<> const & o = 1.0 / (Unit::SI::Constants::m0 * Unit::SI::Constants::c * Unit::SI::Constants::c);

  Unit::Object<> o2 = 1.0 / (Unit::SI::Constants::m0 * Unit::SI::Constants::c * Unit::SI::Constants::c);

  OutputLine( L"Unit::SI::Constants::m0: " + o.GetSuffix());
  OutputLine( L"Unit::SI::Constants::m0: " + o.GetSISuffix());

  Assert(fequal(Unit::SI::Constants::e0.GetValue(), o.GetValue(), 1.e-12));
  Assert( fequal(Unit::SI::Constants::e0.GetValue(), 8.8541878178734628e-12, 1.e-12) );

}

