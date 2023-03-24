#include <iostream>
#include "d_var.h"
#include "d_var_math.h"
#define _USE_MATH_DEFINES
#include <math.h>


template <typename T>
T euler_column_formula(const T& E, const T& I, const T& L) {
    return (pow(d_var(M_PI, "\\pi", { 0, 0, 0 }), 2.0) * E * I) / pow(L, 2.0);
}

int main() {
    // Define dimensions for each variable
    std::vector<int> modulus_dimensions = { 1, -1, -2 }; // M*L^-1*T^-2
    std::vector<int> inertia_dimensions = { 0, 4, 0 };   // L^4
    std::vector<int> length_dimensions = { 0, 1, 0 };    // L
    std::vector<int> load_dimensions = { 1, 1, -2 };    // M*L*T^-2
    std::vector<int> no_dimensions = { 0, 0, 0 };

    // Create d_var objects for input variables
    d_var E(200.0, "E", modulus_dimensions); // Elasticity modulus
    d_var I(0.0001, "I", inertia_dimensions); // Inertia
    d_var L(2.0, "L", length_dimensions);    // Column length

    // Define pi_var as a n_var object
    d_var pi_var(M_PI, "\\pi", no_dimensions);
    d_var var_c = d_var(2.0);

    // Calculate the critical load using d_var objects
    d_var critical_load = euler_column_formula(E, I, L);
    std::cout << "Critical load: " << critical_load << ", LaTeX formula: "
        << critical_load.get_latex_symbol() << std::endl;

    // Calculate the critical load using double values
    double critical_load_double = euler_column_formula(double(E), double(I), double(L));
    std::cout << "Critical load (double): " << critical_load_double << std::endl;

    return 0;
}