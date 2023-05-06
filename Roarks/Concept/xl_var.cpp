#include "xl_var.h"

xl_var::xl_var(double value)
	: n_var(value, std::to_string(value)) {}

xl_var& xl_var::operator=(const xl_var& rhs) {
	if (this != &rhs) {
		value = rhs.value;

		// Update excel_formula
		excel_formula = " = " + rhs.excel_formula;
	}
	return *this;
}

xl_var operator+(const xl_var& lhs, const xl_var& rhs) {
	return xl_var(lhs.value + rhs.value, lhs.excel_cell + "+" + rhs.excel_cell);
}

xl_var operator-(const xl_var& lhs, const xl_var& rhs) {
	return xl_var(lhs.value - rhs.value, lhs.excel_cell + "-" + rhs.excel_cell);
}

xl_var operator* (const xl_var& lhs, const xl_var& rhs) {
	return xl_var(lhs.value * rhs.value, lhs.excel_cell + "*" + rhs.excel_cell);
}

xl_var operator/(const xl_var& lhs, const xl_var& rhs) {
	return xl_var(lhs.value / rhs.value, lhs.excel_cell + "/" + rhs.excel_cell);
}