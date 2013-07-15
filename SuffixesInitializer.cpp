#include "stdafx.h"
#include "Detail/UnitObject.h"

#ifndef NO_STATIC_UNIT_SUFFIXES_EVALUATION
#include "UnitSI.h"
#endif

using namespace Unit;
using namespace Unit::Detail;


SuffixesMap SuffixesInitializer::RuntimeSuffixes;


#ifdef NO_STATIC_UNIT_SUFFIXES_EVALUATION

void SuffixesInitializer::Initialize()
{
  using namespace Unit::SI;
  using namespace Unit::NonSI;

  //Base Unit
  Meter::SimplifiedType m(NULL, NULL);
  Kilogram::SimplifiedType kg(NULL, NULL);
  Time::SimplifiedType s(NULL, NULL);
  Ampere::SimplifiedType A(NULL, NULL);
  Kelvin::SimplifiedType K(NULL, NULL);
  Mole::SimplifiedType mol(NULL, NULL);
  Candela::SimplifiedType cd(NULL, NULL);

  //Derived Unit
  Radian rad( NULL, NULL ); 
  Degree deg( NULL, NULL );

}

#endif
