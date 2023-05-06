#pragma once
#include "d_var.h"
#include "d_var_math.h"
#include "dimensions.h"
#define _USE_MATH_DEFINES
#include <math.h>

d_var pi_var(M_PI, "\\pi", no_dimensions);

template <typename T>
T euler_column_formula(const T& E, const T& I, const T& L) {
	return (pow(d_var(M_PI, "\\pi", { 0, 0, 0 }), 2.0) * E * I) / pow(L, 2.0);
}
