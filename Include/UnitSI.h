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


#include "UnitBaseSI.h"
#include "UnitAcceleration.h"
#include "UnitAngular.h"
#include "UnitArea.h"
#include "UnitForce.h"
#include "UnitElectric.h"
#include "UnitFrequency.h"
#include "UnitPower.h"
#include "UnitPowerRatio.h"
#include "UnitPressure.h"
#include "UnitRatio.h"
#include "UnitVelocity.h"
#include "UnitVolume.h"
#include "UnitMagnetic.h"
#include "UnitElectronVolt.h"


namespace Unit
{

namespace SI
{

  typedef Product<Pascal, Second>::QuantityType                                   DynamicViscosity;
  typedef Product<Newton, Meter>::QuantityType                                    MomentOfForce;
  typedef Product<Newton, Meter::Invert>::QuantityType                            SurfaceTension; 
  typedef Product<Radian, Second::Invert>::QuantityType                           AngularVelocity;
  typedef Product<Radian, Product<Second>::Invert>::QuantityType                  AngularAcceleration;
  typedef Product<Watt, Squaremeter::Invert>::QuantityType                        HeatFluxDensity;
  typedef Product<Joule, Kelvin::Invert>::QuantityType                            HeatCapacity;
  typedef Product<Joule, Kelvin::Invert>::QuantityType                            Entropy;
  typedef Product<Joule, Product<Kilogram, Kelvin>::Invert>::QuantityType         SpecificHeatCapacity;
  typedef Product<Joule, Product<Kilogram, Kelvin>::Invert>::QuantityType         SpecificEntropy;
  typedef Product<Joule, Kilogram::Invert>::QuantityType                          SpecificEnergy; 
  typedef Product<Watt, Product<Meter, Kelvin>::Invert>::QuantityType             ThermalConductivity;
  typedef Product<Joule, Cubicmeter::Invert>::QuantityType                        EnergyDensity;
  typedef Product<Volt, Meter::Invert>::QuantityType                              ElectricFieldStrength;
  typedef Product<Coulomb, Cubicmeter::Invert>::QuantityType                      ElectricChargeDensity;
  typedef Product<Coulomb, Squaremeter::Invert>::QuantityType                     ElectricFluxDensity;
  typedef Product<Farad, Meter::Invert>::QuantityType                             Permittivity;
  typedef Product<Henry, Meter::Invert>::QuantityType                             Permeability;
  typedef Product<Joule, Mole::Invert>::QuantityType                              MolarEnergy;
  typedef Product<Joule, Product<Mole, Kelvin>::Invert>::QuantityType             MolarEntropy;
  typedef Product<Coulomb, Kilogram::Invert>::QuantityType                        Exposure;
  typedef Product<Watt, Steradian::Invert>::QuantityType                          RadiantIntensity;
  typedef Product<Watt, Product<Squaremeter, Steradian>::Invert>::QuantityType    Radiance;
  typedef Product<Katal, Cubicmeter::Invert>::QuantityType                        CatalyticActivityConcentration;

}

}
