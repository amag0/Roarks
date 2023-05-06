#pragma once
#include <vector>
#include "../DLL_VARIABLES/Fraction.h"

// Dimension is stored as a set of four fractions.
typedef std::vector<Fraction> Dimension;

// Define dimensions for each variable}
Dimension no_dimensions = { 0, 0, 0, 0 };
Dimension radins_dimensions = { 0, 0, 0, 0 };
Dimension mass_simensions = { 1, 0, 0, 0 };		// M
Dimension length_dimensions = { 0, 1, 0, 0 };   // L
Dimension time_dimensions = { 0, 0, 1, 0 };		// t
Dimension temperature_dimensions = { 0, 0, 0, 1 }; // T

Dimension area_dimensions = { 0, 2, 0, 0 };		// L^2
Dimension inertia_dimensions = { 0, 4, 0, 0 };   // L^4
Dimension modulus_dimensions = { 1, -1, -2, 0 }; // M*L^-1*t^-2
Dimension load_dimensions = { 1, 1, -2, 0 };    // M*L*t^-2=F
Dimension couple_dimensions = { 1, 2, -2, 0 };  // F*L
Dimension load_per_unit_length_dimensions = { 1, 0, -2, 0 };	// M*t-2
Dimension temperature_inverse_dimensions = { 0, 0, 0, -1 };
