
#include "stdafx.h"


using namespace System;


void __cdecl Assert( bool const b )
{
  Microsoft::VisualStudio::TestTools::UnitTesting::Assert::IsTrue( b );
}

void OutputLine( Unit::Types::String const &_s )
{
  Console::WriteLine( gcnew String( _s.c_str() ) );
}


