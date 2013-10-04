/*
Unit Manipulation Library.
Copyright (C) 2013  Jean Gauthier

The goal of this library is to make easy, reliable and efficient the
manipulation of units, including arithmetical operations and safe 
conversions from unit type to another. 

This library is free software; you can redistribute it and/or
modify it under the terms of the GNU Library General Public
License as published by the Free Software Foundation; either
version 2 of the License, or (at your option) any later version.

This library is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
Library General Public License for more details.

You should have received a copy of the GNU Library General Public
License along with this library; if not, write to the
Free Software Foundation, Inc., 59 Temple Place - Suite 330,
Boston, MA  02111-1307, USA.

jean.gauthier@programmer.net
*/


#pragma once


#include "UnitSI.h"



namespace Unit
{

  namespace SI
  {

    namespace Constants
    {
      

      Kilogram                                                                   const mu( 1.660538921e-27 );   // 2010 CODATA atomic mass constant	
      Mole::Invert                                                               const Na( 6.02214129e23 );     // Avogadro constant	
      Product<Joule, Tesla::Invert>::QuantityType                                const mB( 9.27400949e-24 );    // Bohr magneton	
      Meter                                                                      const a0( 5.2917721092e-11 );  // 2010 CODATA Bohr radius
      Product<Joule, Kelvin::Invert>::QuantityType                               const kb( 1.3806504e-23 );     // 2006 CODATA Boltzmann constant
      Siemens                                                                    const G0(	7.7480917346e-5 );  // conductance quantum	
      //Product<Farad, Meter::Invert>::QuantityType   const e0	1/(m0·c2) = 8.85418781...x10-12 F/m         // electric permittivity constant
      Meter                                                                      const lc(	2.4263102175e-12 ); // 2010 CODATA electron Compton wavelength	
      //electron magnetic moment	me	9.284764x10-24
      Meter	                                                                     const re( 2.8179403267e-15 );  // electron radius (classical)
      Kilogram	                                                                 const me(	9.109382e-31 );     // electron rest mass
      Joule                                                                      const eV(	1.60217653e-19 );   // electron volt
      Coulomb	                                                                   const e ( 1.602176565e-19 );   // elementary charge
      Product<Farad, Mole::Invert>::QuantityType                                 const F ( 9.648524e104 );      // Faraday constant	
      Product<Newton, Product<Product<Meter, Kilogram>>::Invert>::QuantityType   const G ( 6.67384e-11 );       // gravitational constant
      Product<Hertz, Volt::Invert>::QuantityType                                 const KJ( 4.83597870e14 );     // Josephson constant	
      Weber                                                                      const F0( 2.067833758e-15 );   // magnetic flux quantum


      /*
      magnetic permeability constant	m0	4p x10-7 = 1.2566370614...x10-6 H/m
      neutron magnetic moment	mn	9.662364x10-27 J/T
      neutron rest mass	mn	1.674927x10-27 kg
      nuclear magneton	mN	5.050783x10-27 J/T
      Planck constant	h	6.626069x10-34 J-s
      proton Compton wavelength	lc,p	1.321410x10-15 m
      proton magnetic moment	mp	1.410607x10-26 J/T
      proton rest mass	mp	1.672622x10-27 kg
      Rydberg constant		1.097373x107 /m
      second radiation constant	c2	1.438775x10-2 m-K
      speed of light in vacuum	c	2.99792458x108 m/s
      standard volume of ideal gas	V0	2.24136x10-2 m3/mol
      Stefan-Boltzmann constant	s	5.670400x10-8 W/m2-K4
      universal gas constant	R	8.314472 J/mol-K
      Wien displacement law constant	b	2.897769x10-3 m-K
      */
    }

  }

}
