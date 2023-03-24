#include "d_var_math.h"
#include <sstream>
#include <cmath>

d_var pow(const d_var& base, double exponent) {
    std::vector<int> result_dimensions(base.get_dimensions().size());
    for (size_t i = 0; i < base.get_dimensions().size(); ++i) {
        result_dimensions[i] = base.get_dimensions()[i] * exponent;
    }
    std::stringstream ss;
    ss << base.get_latex_symbol() << "^{" << exponent << "}";
    return d_var(std::pow(base, exponent), ss.str(), result_dimensions);
}

d_var sin(const d_var& x) {
    if (x.get_dimensions() != std::vector<int>{0, 0, 0}) {
        throw std::runtime_error("Dimension mismatch in sin function");
    }
    std::stringstream ss;
    ss << "\\sin(" << x.get_latex_symbol() << ")";
    return d_var(std::sin(x), ss.str(), x.get_dimensions());
}
