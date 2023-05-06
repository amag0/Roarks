#include "d_var.h"

d_var::d_var(double value)
    : n_var(value, std::to_string(value)), dimensions({ 0, 0, 0 }) {}

d_var& d_var::operator=(const d_var& rhs) {
    if (this != &rhs) {
        value = rhs.value;
        dimensions = rhs.dimensions;

        // Update latex_formula
        latex_formula = latex_symbol + " = " + rhs.latex_symbol;

        // Keep the latex_symbol unchanged
    }
    return *this;
}

d_var operator+(const d_var& lhs, const d_var& rhs) {
    if (lhs.dimensions != rhs.dimensions) {
        throw std::runtime_error("Dimension mismatch in addition operation");
    }
    return d_var(lhs.value + rhs.value, lhs.latex_symbol + " + " + rhs.latex_symbol, lhs.dimensions);
}

d_var operator-(const d_var& lhs, const d_var& rhs) {
    if (lhs.dimensions != rhs.dimensions) {
        throw std::runtime_error("Dimension mismatch in subtraction operation");
    }
    return d_var(lhs.value - rhs.value, lhs.latex_symbol + " - " + rhs.latex_symbol, lhs.dimensions);
}

d_var operator*(const d_var& lhs, const d_var& rhs) {
    Dimension result_dimensions(lhs.dimensions.size());
    for (size_t i = 0; i < lhs.dimensions.size(); ++i) {
        result_dimensions[i] = lhs.dimensions[i] + rhs.dimensions[i];
    }
    return d_var(lhs.value * rhs.value, lhs.latex_symbol + "\\cdot " + rhs.latex_symbol, result_dimensions);
}

d_var operator/(const d_var& lhs, const d_var& rhs) {
    Dimension result_dimensions(lhs.dimensions.size());
    for (size_t i = 0; i < lhs.dimensions.size(); ++i) {
        result_dimensions[i] = lhs.dimensions[i] - rhs.dimensions[i];
    }
    return d_var(lhs.value / rhs.value, "\\frac{" + lhs.latex_symbol + "}{" + rhs.latex_symbol + "}", result_dimensions);
}
