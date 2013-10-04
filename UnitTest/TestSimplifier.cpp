#include "stdafx.h"
#include "UnitAcceleration.h"
#include "UnitArea.h"
#include "UnitFrequency.h"


using namespace Unit;
using namespace Unit::SI;
using namespace Unit::NonSI;
using namespace Unit::Types;



void TestSimplifier()
{
  Integer const _lengthBaseTypeValue = Length::SimplifiedType::BaseTypeValue;
  Integer const _areaBaseTypeValue = Area::SimplifiedType::BaseTypeValue;
  Integer const _timeBaseTypeValue = Time::SimplifiedType::BaseTypeValue;


  ComplexUnit<Length::SimplifiedType, Length::SimplifiedType>::SimplifiedType _lengthReduced;
  ComplexUnit<Length::SimplifiedType, Time::SimplifiedType>::SimplifiedType _lengthTimeReduced;
  ComplexUnit<Hertz::SimplifiedType, Time::SimplifiedType>::SimplifiedType _FrequencyTimeReduced;
  ComplexUnit<Time::SimplifiedType, Velocity::SimplifiedType>::SimplifiedType _TimeVelocityReduced;


  Integer const _lengthReducedBaseTypeValue = _lengthReduced.BaseTypeValue;

  Assert( _lengthReducedBaseTypeValue != _lengthBaseTypeValue );
  Assert( _lengthReducedBaseTypeValue == _areaBaseTypeValue );


  Integer const _lengthTimeReducedBaseTypeValue = _lengthTimeReduced.BaseTypeValue;

  Assert( _lengthTimeReducedBaseTypeValue != _lengthBaseTypeValue );
  Assert( _lengthTimeReducedBaseTypeValue != _timeBaseTypeValue );
  Assert( _lengthTimeReducedBaseTypeValue == _lengthBaseTypeValue * _timeBaseTypeValue );

  Integer const _FrequencyTimeReducedBaseTypeValue = _FrequencyTimeReduced.BaseTypeValue;

  Assert( _FrequencyTimeReducedBaseTypeValue == 1 );

  Integer const _TimeVelocityReducedBaseTypeValue = _TimeVelocityReduced.BaseTypeValue;

  Assert( _TimeVelocityReducedBaseTypeValue == _lengthBaseTypeValue );

}



