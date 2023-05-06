#pragma once

#include <iostream>
#include <string>
#include <vector>
#include "n_var.h"
#include "dimensions.h"

/// <summary>
/// Dimensioned Variable
/// Stores a named variable with a dimension.
/// </summary>
class d_var : public n_var {
public:
    d_var(double value, const std::string& latex_symbol, const Dimension& dimensions)
        : n_var(value, latex_symbol), dimensions(dimensions) {}
    explicit d_var(double value);
    const Dimension& get_dimensions() const {
        return dimensions;
    }

    d_var& operator=(const d_var& rhs);

    friend d_var operator+(const d_var& lhs, const d_var& rhs);
    friend d_var operator-(const d_var& lhs, const d_var& rhs);
    friend d_var operator*(const d_var& lhs, const d_var& rhs);
    friend d_var operator/(const d_var& lhs, const d_var& rhs);

private:
    Dimension dimensions;
};

d_var operator+(const d_var& lhs, const d_var& rhs);
d_var operator-(const d_var& lhs, const d_var& rhs);
d_var operator*(const d_var& lhs, const d_var& rhs);
d_var operator/(const d_var& lhs, const d_var& rhs);
