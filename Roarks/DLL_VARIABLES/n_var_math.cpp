#include "n_var_math.h"
#include <sstream>

n_var pow(const n_var& base, double exponent) {
	std::stringstream ss;
	ss << base.get_latex_symbol() << "^{" << exponent << "}";
	return n_var(std::pow(double(base), exponent), ss.str());
}

n_var abs(const n_var& x) {
	std::stringstream ss;
	ss << "\\lvert " << x.get_latex_symbol() << "\\rvert";
	return n_var(std::abs(double(x)), ss.str());
}

n_var exp(const n_var& x) {
	std::stringstream ss;
	ss << "\\exp(" << x.get_latex_symbol() << ")";
	return n_var(std::exp(double(x)), ss.str());
}

n_var log(const n_var& x) {
	std::stringstream ss;
	ss << "\\log(" << x.get_latex_symbol() << ")";
	return n_var(std::log(double(x)), ss.str());
}

n_var sqrt(const n_var& x) {
	std::stringstream ss;
	ss << "\\sqrt{" << x.get_latex_symbol() << "}";
	return n_var(std::sqrt(double(x)), ss.str());
}

n_var ceil(const n_var& x) {
	std::stringstream ss;
	ss << "\\lceil " << x.get_latex_symbol() << " \\rceil";
	return n_var(std::ceil(double(x)), ss.str());
}

n_var floor(const n_var& x) {
	std::stringstream ss;
	ss << "\\lfloor " << x.get_latex_symbol() << " \\rfloor";
	return n_var(std::floor(double(x)), ss.str());
}

n_var sin(const n_var& x) {
	std::stringstream ss;
	ss << "\\sin(" << x.get_latex_symbol() << ")";
	return n_var(std::sin(x), ss.str());
}