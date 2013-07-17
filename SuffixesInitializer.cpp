#include "stdafx.h"
#include "Detail/UnitObject.h"

#ifdef NO_STATIC_UNIT_SUFFIXES_EVALUATION
#include "UnitSI.h"
#endif

using namespace Unit::Detail;


SuffixesMap SuffixesInitializer::RuntimeSuffixes;


#ifdef NO_STATIC_UNIT_SUFFIXES_EVALUATION

#pragma warning( push )
#pragma warning( disable : 4189 )

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

  //Angle Derived Unit
  Radian rad( NULL, NULL );
  Degree deg( NULL, NULL );

  //Mass Derived Unit
  Metric_ton metric_ton( NULL, NULL );

  //Electric Derived Unit
  Volt volt( NULL, NULL ); 
  Joule joule( NULL, NULL );
  Watt watt( NULL, NULL ); 
  Coulomb coulomb( NULL, NULL );
  Ohm ohm( NULL, NULL );

  //Force Derived Unit
  Newton newton( NULL, NULL );
  Pascal ___pascal( NULL, NULL );

  //Frequency Derived Unit
  Hertz hertz( NULL, NULL );

  //Ratio Derived Unit
  Bel bel( NULL, NULL );
  Percent percent( NULL, NULL );

  //Temperature Derived Unit
  Celsius celsius( NULL, NULL );


}

#pragma warning( pop )

#endif
