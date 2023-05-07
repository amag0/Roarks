#pragma once

#ifdef DLL_VARIABLES_EXPORTS
#define DLL_VARIABLES_API __declspec(dllexport)
#else
#define DLL_VARIABLES_API __declspec(dllimport)
#endif

#define _USE_MATH_DEFINES
#include <math.h>
#include "../Concept/n_var.h"

__declspec(dllexport) const n_var pi_var(M_PI, "\\pi");

// Custom pow function for namedVariables
DLL_VARIABLES_API n_var pow(const n_var& base, double exponent);
DLL_VARIABLES_API n_var abs(const n_var& x);
DLL_VARIABLES_API n_var exp(const n_var& x);
DLL_VARIABLES_API n_var log(const n_var& x);
DLL_VARIABLES_API n_var sqrt(const n_var& x);
DLL_VARIABLES_API n_var ceil(const n_var& x);
DLL_VARIABLES_API n_var floor(const n_var& x);

// Custom sin function for namedVariables
DLL_VARIABLES_API n_var sin(const n_var& x);
DLL_VARIABLES_API n_var cos(const n_var& x);
DLL_VARIABLES_API n_var tan(const n_var& x);
DLL_VARIABLES_API n_var asin(const n_var& x);
DLL_VARIABLES_API n_var acos(const n_var& x);
DLL_VARIABLES_API n_var atan(const n_var& x);
DLL_VARIABLES_API n_var atan2(const n_var& y, const n_var& x);
DLL_VARIABLES_API n_var sinh(const n_var& x);
DLL_VARIABLES_API n_var cosh(const n_var& x);
DLL_VARIABLES_API n_var tanh(const n_var& x);
DLL_VARIABLES_API n_var asinh(const n_var& x);
DLL_VARIABLES_API n_var acosh(const n_var& x);
DLL_VARIABLES_API n_var atanh(const n_var& x);