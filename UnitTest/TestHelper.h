#pragma once

#include <string>
#include <boost/math/tools/precision.hpp>

void Assert(bool);
void OutputLine(std::wstring const &);
std::wstring ToString(double _s);


inline bool fequal(double const x, double const y, double const _scale = 1.0)
{
  return ::fabs(x / _scale - y / _scale) < boost::math::tools::root_epsilon<double>();
}
