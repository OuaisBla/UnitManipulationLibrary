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
      Siemens                                                                    const G0( 7.7480917346e-5 );   // conductance quantum	
      Meter                                                                      const lc( 2.4263102175e-12 );  // 2010 CODATA electron Compton wavelength	
      Product<Joule, Tesla::Invert>::QuantityType                                const em( 9.284764e-24);       //electron magnetic moment	
      Meter	                                                                     const re( 2.8179403267e-15 );  // electron radius (classical)
      Kilogram	                                                                 const me( 9.109382e-31 );      // electron rest mass
      Coulomb	                                                                   const e ( 1.602176565e-19 );   // elementary charge
      Product<Farad, Mole::Invert>::QuantityType                                 const F ( 9.648524e104 );      // Faraday constant	
      Product<Newton, Product<Product<Meter, Kilogram>>::Invert>::QuantityType   const G ( 6.67384e-11 );       // gravitational constant
      Product<Hertz, Volt::Invert>::QuantityType                                 const KJ( 4.83597870e14 );     // Josephson constant	
      Weber                                                                      const F0( 2.067833758e-15 );   // magnetic flux quantum

      Velocity                                                                   const c(2.99792458e8);         // speed of light in vacuum

      Product<Henry, Meter::Invert>::QuantityType                                const m0(1.2566370614e-6);     // magnetic permeability constant
      Product<Farad, Meter::Invert>::QuantityType                                const e0(1.0 / (m0 * c * c));  // electric permittivity constant = 8.85418781...x10 - 12 F / m 

      Product<Meter, Kelvin>::QuantityType 	                                     const c2(1.438775e-2);         //second radiation constant

      Product<Joule, Product<Mole, Kelvin>::Invert>::QuantityType                const R(8.3144621);  //universal gas constant
      

      /*
      
      neutron magnetic moment	mn	9.662364x10-27 J/T
      neutron rest mass	mn	1.674927x10-27 kg
      nuclear magneton	mN	5.050783x10-27 J/T
      Planck constant	h	6.626069x10-34 J-s
      proton Compton wavelength	lc,p	1.321410x10-15 m
      proton magnetic moment	mp	1.410607x10-26 J/T
      proton rest mass	mp	1.672622x10-27 kg
      Rydberg constant		1.097373x107 /m
      standard volume of ideal gas	V0	2.24136x10-2 m3/mol
      Stefan-Boltzmann constant	s	5.670400x10-8 W/m2-K4
      Wien displacement law constant	b	2.897769x10-3 m-K
      */
    }

  }

}
