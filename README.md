UnitManipulationLibrary
=======================

Template C++ Library for physical unit and value manipulation. 

Main features are : 

Compile time validation of both simple and complex unit (m, s, m\s-1, m\s-2, ...). 
Compile time complex unit reduction in some special case. 
Support for SI Unit
Support for SI Derived Unit
Support for Non SI Unit
Support for Operator (Comparaison, Arithmetic)

TO DO: 
Extend ScalarType to fully support Complex numbers, Integer and floating point number with variable precision policy.
	- Try to preserve compiler interopability between various numerical support whenever possible. (Ie, Float to int conversion, Complex to double conversion, ...)
Implement thorough unit testing for all supported units.
	- More assert
	- More academic problems solving
Add unit support for the scientific domain that are most used.
Add physical constants for supported scientific domain.
	- Implemented with the Boost precision policy

