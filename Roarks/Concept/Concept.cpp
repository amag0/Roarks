#include <iostream>
#include "dimensions.h"
#include "d_var.h"
#include "d_var_math.h"




int main() {
	// Create d_var objects for input variables
	d_var E(200000, "E", modulus_dimensions); // Elasticity modulus
	d_var I(2700, "I", inertia_dimensions);   // Inertia
	d_var L(800, "L", length_dimensions);     // Column length

	
	// Calculate the critical load using d_var objects
	d_var critical_load = d_var(0.0, "P_{cr}", load_dimensions);
	critical_load = euler_column_formula(E, I, L);
	std::cout << "Critical load: " << critical_load << ", LaTeX formula: "
		<< critical_load.get_latex_formula() << std::endl;

	// Calculate the critical load using double values
	double critical_load_double = euler_column_formula(double(E), double(I), double(L));
	std::cout << "Critical load (double): " << critical_load.get_latex_symbol() << " = " << critical_load_double << std::endl;
	
	return 0;
}