#include "n_var_math.h"
#include <sstream>

n_var pow(const n_var& base, double exponent) {
	std::stringstream ss;
	ss << add_brackets_if_needed(base, base.getLevel() > ExponentiationLevel) << "^{" << exponent << "}";
	return n_var(std::pow(double(base), exponent), ss.str(), ExponentiationLevel);
}

n_var abs(const n_var& x) {
	std::stringstream ss;
	ss << "\\lvert " << x.get_latex_symbol() << " \\rvert";
	return n_var(std::abs(double(x)), ss.str());
}

n_var exp(const n_var& x) {
	std::stringstream ss;
	ss << "e^{" << x.get_latex_symbol() << "}";
	return n_var(std::exp(double(x)), ss.str());
}

n_var log(const n_var& x) {
	std::stringstream ss;
	ss << "\\ln(" << x.get_latex_symbol() << ")";
	return n_var(std::log(double(x)), ss.str());
}

n_var sqrt(const n_var& x) {
	std::stringstream ss;
	ss << "\\sqrt[2]{" << x.get_latex_symbol() << "}";
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

n_var cos(const n_var& x) { 
	std::stringstream ss; 
	ss << "\\cos(" << x.get_latex_symbol() << ")"; 
	return n_var(std::cos(x), ss.str()); 
}

n_var tan(const n_var& x) { 
	std::stringstream ss; 
	ss << "\\tan(" << x.get_latex_symbol() << ")";
	return n_var(std::tan(x), ss.str()); 
}

n_var asin(const n_var& x) { 
	std::stringstream ss; 
	ss << "\\arcsin(" << x.get_latex_symbol() << ")";
	return n_var(std::asin(x), ss.str()); 
}

n_var acos(const n_var& x) { 
	std::stringstream ss; 
	ss << "\\arccos(" << x.get_latex_symbol() << ")";
	return n_var(std::acos(x), ss.str());
}

n_var atan(const n_var& x) {
	std::stringstream ss; 
	ss << "\\arctan(" << x.get_latex_symbol() << ")";
	return n_var(std::atan(x), ss.str()); 
}

n_var atan2(const n_var& y, const n_var& x) {
	std::stringstream ss; 
	ss << "\\arctan(\\frac{" << y.get_latex_symbol() << "}{" << x.get_latex_symbol() << "})";
	return n_var(std::atan2(y, x), ss.str()); 
}

n_var sinh(const n_var& x) { 
	std::stringstream ss; 
	ss << "\\sinh(" << x.get_latex_symbol() << ")";
	return n_var(std::sinh(x), ss.str()); 
}

n_var cosh(const n_var& x) { 
	std::stringstream ss; 
	ss << "\\cosh(" << x.get_latex_symbol() << ")";
	return n_var(std::cosh(x), ss.str());
}

n_var tanh(const n_var& x) { 
	std::stringstream ss; 
	ss << "\\tanh(" << x.get_latex_symbol() << ")"; 
	return n_var(std::tanh(x), ss.str()); 
}

n_var asinh(const n_var& x) { 
	std::stringstream ss; 
	ss << "\\arcsinh(" << x.get_latex_symbol() << ")"; 
	return n_var(std::asinh(x), ss.str()); 
}

n_var acosh(const n_var& x) {
	std::stringstream ss; 
	ss << "\\arccosh(" << x.get_latex_symbol() << ")"; 
	return n_var(std::acosh(x), ss.str()); 
}

n_var atanh(const n_var& x) {
	std::stringstream ss; 
	ss << "\\arctanh(" << x.get_latex_symbol() << ")"; 
	return n_var(std::atanh(x), ss.str()); 
}