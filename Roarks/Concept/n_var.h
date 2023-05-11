#pragma once

#ifdef DLL_VARIABLES_EXPORTS
#define DLL_VARIABLES_API __declspec(dllexport)
#else
#define DLL_VARIABLES_API __declspec(dllimport)
#endif

#include <string>
#include <sstream>
#include <iomanip>
#include <concepts>

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
	n_var(double value, const std::string& latex_symbol, int level = 0)
		: value(value), latex_symbol(latex_symbol), level(level) {}
	explicit n_var(double value, int level = 0);

	operator double() const {
		return value;
	}

	const std::string& get_latex_symbol() const {
		return latex_symbol;
	}

	const std::string& get_latex_formula() const {
		return latex_formula;
	}

	int getLevel() const { return level; }
	n_var& operator=(const n_var& rhs);

	DLL_VARIABLES_API friend n_var operator+(n_var& lhs, const n_var& rhs);
	DLL_VARIABLES_API friend n_var operator-(n_var& lhs, const n_var& rhs);
	DLL_VARIABLES_API friend n_var operator*(n_var& lhs, const n_var& rhs);
	DLL_VARIABLES_API friend n_var operator/(n_var& lhs, const n_var& rhs);
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
	int level;
};

template <typename T>
concept n_var_constructible = std::is_arithmetic_v<T>;

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

// Declare template operators for mix of arithmetic type and n_var
// need also templates for + * / == != < > <= >= I guess...
template <n_var_constructible T>
n_var operator+(const T& lhs, const n_var& rhs) {
	return n_var(lhs) + rhs;
}

template <n_var_constructible T>
n_var operator+(const n_var& lhs, const T& rhs) {
	return lhs + n_var(rhs);
}

template <n_var_constructible T>
n_var operator-(const T& lhs, const n_var& rhs) {
	return n_var(lhs) - rhs;
}

template <n_var_constructible T>
n_var operator-(const n_var& lhs, const T& rhs) {
	return lhs - n_var(rhs);
}

template <n_var_constructible T>
n_var operator*(const T& lhs, const n_var& rhs) {
	return n_var(lhs) * rhs;
}

template <n_var_constructible T>
n_var operator*(const n_var& lhs, const T& rhs) {
	return lhs * n_var(rhs);
}

template <n_var_constructible T>
n_var operator/(const T& lhs, const n_var& rhs) {
	return n_var(lhs) / rhs;
}

template <n_var_constructible T>
n_var operator/(const n_var& lhs, const T& rhs) {
	return lhs / n_var(rhs);
}

template <n_var_constructible T>
n_var operator==(const T& lhs, const n_var& rhs) {
	return n_var(lhs) == rhs;
}

template <n_var_constructible T>
n_var operator==(const n_var& lhs, const T& rhs) {
	return lhs == n_var(rhs);
}

template <n_var_constructible T>
n_var operator!=(const T& lhs, const n_var& rhs) {
	return n_var(lhs) != rhs;
}

template <n_var_constructible T>
n_var operator!=(const n_var& lhs, const T& rhs) {
	return lhs != n_var(rhs);
}

template <n_var_constructible T>
n_var operator<(const T& lhs, const n_var& rhs) {
	return n_var(lhs) < rhs;
}

template <n_var_constructible T>
n_var operator<(const n_var& lhs, const T& rhs) {
	return lhs < n_var(rhs);
}

template <n_var_constructible T>
n_var operator>(const T& lhs, const n_var& rhs) {
	return n_var(lhs) > rhs;
}

template <n_var_constructible T>
n_var operator>(const n_var& lhs, const T& rhs) {
	return lhs > n_var(rhs);
}

template <n_var_constructible T>
n_var operator<=(const T& lhs, const n_var& rhs) {
	return n_var(lhs) <= rhs;
}

template <n_var_constructible T>
n_var operator<=(const n_var& lhs, const T& rhs) {
	return lhs <= n_var(rhs);
}

template <n_var_constructible T>
n_var operator>=(const T& lhs, const n_var& rhs) {
	return n_var(lhs) >= rhs;
}

template <n_var_constructible T>
n_var operator>=(const n_var& lhs, const T& rhs) {
	return lhs >= n_var(rhs);
}

enum PrecedenceLevel {
	LiteralLevel = 0,
	ExponentiationLevel = 1,
	MultiplyDivideLevel = 2,
	AddSubtractLevel = 3,
	ComparisonLevel = 4,
	// Add more levels if needed
};

inline std::string add_brackets_if_needed(const n_var& var, bool needs_brackets) {
	if (needs_brackets) {
		return "(" + var.get_latex_symbol() + ")";
	}
	return var.get_latex_symbol();
}