
#include "stdafx.h"
#include "TestHelper.h"


using namespace System;


void __cdecl Assert( bool const b )
{
  Microsoft::VisualStudio::TestTools::UnitTesting::Assert::IsTrue( b );
}

void OutputLine(std::wstring const &_s )
{
  Console::WriteLine( gcnew String( _s.c_str() ) );
}

std::wstring ToString(double const _s)
{
  System::String ^s = _s.ToString(System::Globalization::CultureInfo::InvariantCulture);

  return msclr::interop::marshal_as<std::wstring>(s);
}
