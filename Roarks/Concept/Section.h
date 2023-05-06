#pragma once
#include "d_var.h"
#include "dimensions.h"

// Define the Section Properties interface
template <typename T>
class ISectionProperties {
	~ISectionProperties() = default;
	virtual const T Ix() = 0;
	virtual const T Iy() = 0;
	virtual const T A() = 0;
};

template <typename T>
class BeamIWithEqualFlanges : public ISectionProperties<T> {
private:
	// Input variables
	T b;
	T t;
	T tw;
	T d;
	// Output variables
	// hmmmm pero estas no tienen nombre?
	T v_Ix;
	T v_Iy;
	T v_A;
public:
	void Analyze();
	BeamIWithEqualFlanges(T b, T t, T tw, T d) : b(b), t(t), tw(tw), d(d) {}
	const T Ix() { return v_Ix; }
	const T Iy() { return v_Iy; }
	const T A() { return A; }
};

template <typename T>
void BeamIWithEqualFlanges<T>::Analyze()
{
	v_Ix = b * pow((d + 2 * t), 3) / 12 - (b - tw) * pow(d, 3) / 12;
	v_Iy = pow(b, 3) / 6 + pow(tw, 3) * d / 12;
	v_A = 2 * b * t + tw * d;
}

std::string penis()
{
	// construct with d_var variables
	d_var v_b = d_var(30.0, "b", length_dimensions);
	d_var v_t = d_var(2.4, "t", length_dimensions);
	d_var v_tw = d_var(0.8, "tw", length_dimensions);
	d_var v_d = d_var(48, "d", length_dimensions);
	BeamIWithEqualFlanges<d_var> x = BeamIWithEqualFlanges<d_var>(v_b, v_t, v_tw, v_d);
	x.Analyze();
	return x.A().get_latex_formula();
}

double mine()
{
	// construct with double variables
	double d_b = 30.0;
	double d_t = 2.4;
	double d_tw = 0.8;
	double d_d = 48.0;
	BeamIWithEqualFlanges<double> x = BeamIWithEqualFlanges<double>(d_b, d_t, d_tw, d_d);
	x.Analyze();
	return x.A();
}

double yours()
{

}