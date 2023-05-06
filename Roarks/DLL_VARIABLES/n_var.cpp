#include "../Concept/n_var.h"

n_var::n_var(double value) : value(value)
{
	std::ostringstream oss;
	oss << std::setprecision(8) << std::noshowpoint << value;
	latex_symbol = oss.str();
}

BoolVariable& BoolVariable::operator=(const BoolVariable& rhs)
{
	if (this != &rhs) {
		value = rhs.value;

		// Update latex symbol
		latex_symbol = rhs.latex_symbol;
	}
	return *this;
}

n_var& n_var::operator=(const n_var& rhs)
{
	if (this != &rhs) {
		value = rhs.value;

		// Update latex_formula
		latex_formula = latex_symbol + " = " + rhs.latex_symbol;

		// Keep the latex_symbol unchanged
	}
	return *this;
}

n_var operator+(const n_var& lhs, const n_var& rhs)
{
	return n_var(lhs.value + rhs.value, lhs.latex_symbol + " + " + rhs.latex_symbol);
}

n_var operator-(const n_var& lhs, const n_var& rhs)
{
	return n_var(lhs.value - rhs.value, lhs.latex_symbol + " - " + rhs.latex_symbol);
}

n_var operator*(const n_var& lhs, const n_var& rhs)
{
	return n_var(lhs.value * rhs.value, lhs.latex_symbol + " \\cdot " + rhs.latex_symbol);
}

n_var operator/(const n_var& lhs, const n_var& rhs)
{
	return n_var(lhs.value / rhs.value, "\\frac{" + lhs.latex_symbol + "}{" + rhs.latex_symbol + "}");
}

BoolVariable operator==(const n_var& lhs, const n_var& rhs) {
	return BoolVariable(lhs.value == rhs.value, lhs.latex_symbol + " = " + rhs.latex_symbol);
}

BoolVariable operator!=(const n_var& lhs, const n_var& rhs) {
	return BoolVariable(lhs.value != rhs.value, lhs.latex_symbol + " \\neq " + rhs.latex_symbol);
}

BoolVariable operator<(const n_var& lhs, const n_var& rhs) {
	return BoolVariable(lhs.value < rhs.value, lhs.latex_symbol + " < " + rhs.latex_symbol);
}

BoolVariable operator>(const n_var& lhs, const n_var& rhs) {
	return BoolVariable(lhs.value > rhs.value, lhs.latex_symbol + " > " + rhs.latex_symbol);
}

BoolVariable operator<=(const n_var& lhs, const n_var& rhs) {
	return BoolVariable(lhs.value <= rhs.value, lhs.latex_symbol + " \\leq " + rhs.latex_symbol);
}

BoolVariable operator>=(const n_var& lhs, const n_var& rhs) {
	return BoolVariable(lhs.value >= rhs.value, lhs.latex_symbol + " \\geq " + rhs.latex_symbol);
}

BoolVariable::BoolVariable(bool value) : value(value)
{
	if (value) { latex_symbol = "Y"; }
	else { latex_symbol = "N"; }
}
