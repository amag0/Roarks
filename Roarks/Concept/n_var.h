#pragma once

#ifdef DLL_VARIABLES_EXPORTS
#define DLL_VARIABLES_API __declspec(dllexport)
#else
#define DLL_VARIABLES_API __declspec(dllimport)
#endif

#include <string>
#include <sstream>
#include <iomanip>

class n_var;

class BoolVariable {
public:
	BoolVariable(bool value, const std::string symbol) : value(value), latex_symbol(symbol) {}
	explicit BoolVariable(bool value);
	operator bool const() { return value; }

	const std::string& get_latex_symbol() { return latex_symbol; }

	BoolVariable& operator=(const BoolVariable& rhs);
protected:
	bool value;
	std::string latex_symbol;
};

/// <summary>
/// named variable class.
/// variable with a floating point value, a latex symbol, and a latex formula.
/// </summary>
class DLL_VARIABLES_API n_var {
public:
	n_var(double value, const std::string& latex_symbol)
		: value(value), latex_symbol(latex_symbol) {}
	n_var(double value);

	operator double() const {
		return value;
	}

	const std::string& get_latex_symbol() const {
		return latex_symbol;
	}

	const std::string& get_latex_formula() const {
		return latex_formula;
	}

	n_var& operator=(const n_var& rhs);

	DLL_VARIABLES_API friend n_var operator+(const n_var& lhs, const n_var& rhs);
	DLL_VARIABLES_API friend n_var operator-(const n_var& lhs, const n_var& rhs);
	DLL_VARIABLES_API friend n_var operator*(const n_var& lhs, const n_var& rhs);
	DLL_VARIABLES_API friend n_var operator/(const n_var& lhs, const n_var& rhs);
	DLL_VARIABLES_API friend BoolVariable operator==(const n_var& lhs, const n_var& rhs);
	DLL_VARIABLES_API friend BoolVariable operator!=(const n_var& lhs, const n_var& rhs);
	DLL_VARIABLES_API friend BoolVariable operator<(const n_var& lhs, const n_var& rhs);
	DLL_VARIABLES_API friend BoolVariable operator>(const n_var& lhs, const n_var& rhs);
	DLL_VARIABLES_API friend BoolVariable operator<=(const n_var& lhs, const n_var& rhs);
	DLL_VARIABLES_API friend BoolVariable operator>=(const n_var& lhs, const n_var& rhs);

protected:
	double value;
	std::string latex_symbol;
	std::string latex_formula;
};

n_var operator+(const n_var& lhs, const n_var& rhs);
n_var operator-(const n_var& lhs, const n_var& rhs);
n_var operator*(const n_var& lhs, const n_var& rhs);
n_var operator/(const n_var& lhs, const n_var& rhs);

// Declare the comparison operators
BoolVariable operator==(const n_var& lhs, const n_var& rhs);
BoolVariable operator!=(const n_var& lhs, const n_var& rhs);
BoolVariable operator<(const n_var& lhs, const n_var& rhs);
BoolVariable operator>(const n_var& lhs, const n_var& rhs);
BoolVariable operator<=(const n_var& lhs, const n_var& rhs);
BoolVariable operator>=(const n_var& lhs, const n_var& rhs);