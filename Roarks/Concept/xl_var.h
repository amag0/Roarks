#pragma once

#include <iostream>
#include <string>
#include <vector>
#include "n_var.h"

class xl_var : public n_var {
public:
    xl_var(double value, const std::string& cell_reference, const std::string& cell_formula)
        : n_var(value, "latex_symbol"), excel_cell(cell_reference), excel_formula(cell_formula) {}
    explicit xl_var(double value);
    
    xl_var(double value, const std::string& cell_reference)
        : n_var(value, ""), excel_cell(cell_reference), excel_formula("") {}

    const std::string& get_xls_cell() const {
        return excel_cell;
    }

    const std::string& get_xls_formula() const {
        return excel_formula;
    }

    xl_var& operator=(const xl_var& rhs);

    friend xl_var operator+(const xl_var& lhs, const xl_var& rhs);
    friend xl_var operator-(const xl_var& lhs, const xl_var& rhs);
    friend xl_var operator*(const xl_var& lhs, const xl_var& rhs);
    friend xl_var operator/(const xl_var& lhs, const xl_var& rhs);

private:
    std::string excel_cell;
    std::string excel_formula;
};

xl_var operator+(const xl_var& lhs, const xl_var& rhs);
xl_var operator-(const xl_var& lhs, const xl_var& rhs);
xl_var operator*(const xl_var& lhs, const xl_var& rhs);
xl_var operator/(const xl_var& lhs, const xl_var& rhs);
