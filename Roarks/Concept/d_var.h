#pragma once

#include <iostream>
#include <string>
#include <vector>

class n_var {
public:
    n_var(double value, const std::string& latex_symbol)
        : value(value), latex_symbol(latex_symbol) {}

    operator double() const {
        return value;
    }

    const std::string& get_latex_symbol() const {
        return latex_symbol;
    }

protected:
    double value;
    std::string latex_symbol;
};

class d_var : public n_var {
public:
    d_var(double value, const std::string& latex_symbol, const std::vector<int>& dimensions)
        : n_var(value, latex_symbol), dimensions(dimensions) {}
    explicit d_var(double value);
    const std::vector<int>& get_dimensions() const {
        return dimensions;
    }

    friend d_var operator+(const d_var& lhs, const d_var& rhs);
    friend d_var operator-(const d_var& lhs, const d_var& rhs);
    friend d_var operator*(const d_var& lhs, const d_var& rhs);
    friend d_var operator/(const d_var& lhs, const d_var& rhs);

private:
    std::vector<int> dimensions;
};

d_var operator+(const d_var& lhs, const d_var& rhs);
d_var operator-(const d_var& lhs, const d_var& rhs);
d_var operator*(const d_var& lhs, const d_var& rhs);
d_var operator/(const d_var& lhs, const d_var& rhs);
