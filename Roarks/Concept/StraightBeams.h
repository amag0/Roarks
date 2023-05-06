#pragma once
#include <list>
#include "d_var.h"
#include "dimensions.h"

// TABLE 8.1 Shear, moment, slope, anddeflection formulas for elastic straight beams
// straight beam is the parent for each type of beam
namespace straigth_beam {

	enum class LoadCondition {
		ConcentratedIntermediateLoad,
		PartialDistributedLoad,
		ConcentratedIntermediateMoment,
		IntermediateAngularDisplacement,
		IntermediateLateralDisplacement,
		UniformTemperatureVariation
	};
	enum class EndRestraint {
		LeftFreeRightFixed,
		LeftGuidedRightFixed,
		LeftSimplySupportedRightFixed,
		LeftFixedRightFixed,
		LeftSimplySupportedRightSimplySupported,
		LeftGuidedRightSimplySupported
	};

	class StraightBeamAnalysis {
	public:
		// The public interface of StraigthBeamAnalysis
		virtual void Analyze() = 0;
		virtual std::string Formulation() = 0;
		virtual void CreateWorksheet() = 0;
		virtual std::list<std::pair<double, double>> printGraph() = 0; // no se yo...

		// Inputs List ... ups, dependen del tipo de carga ...


	protected:
		// Constructor with load and support condition
		StraightBeamAnalysis(LoadCondition load_condition, EndRestraint end_restraint) : m_load_condition(load_condition), m_end_restraint(end_restraint) {}

		LoadCondition m_load_condition;
		EndRestraint m_end_restraint;
	};

	class ConcentratedLoadLeftFreeRightFixedStraightBeam : public StraightBeamAnalysis {
	public:
		ConcentratedLoadLeftFreeRightFixedStraightBeam() {};

		void Analyze() override;
	};

	class StraightBeamAnalysisFactory{
	public:
		static StraightBeamAnalysis * create_beam_analysis(LoadCondition load_condition, EndRestraint end_restraint);
	};




	class intermediate_load {

		// VARIABLES DEFINITION
		d_var load = d_var(0.0, "W", load_dimensions);
		d_var unit_load = d_var(0.0, "w", load_per_unit_length_dimensions);
		d_var couple = d_var(0.0, "M_{o}", couple_dimensions);
		d_var concentrated_angular_displacement = d_var(0.0, "\\theta_{o}", radins_dimensions);
		d_var concentrated_lateral_displacement = d_var(0.0, "\\Delta_{o}", length_dimensions);
		d_var top_surface_temperature = d_var(0.0, "T_{1}", temperature_dimensions);
		d_var bottom_surface_temperature = d_var(0.0, "T_{2}", temperature_dimensions);
		d_var left_vertical_reaction = d_var(0.0, "R_{A}", load_dimensions);
		d_var right_vertical_reaction = d_var(0.0, "R_{B}", load_dimensions);
		d_var left_reaction_moment = d_var(0.0, "M_{A}", couple_dimensions);
		d_var right_reaction_moment = d_var(0.0, "M_{B}", couple_dimensions);
		d_var transverse_shear = d_var(0.0, "V", load_dimensions);
		d_var modulus_of_elasticity = d_var(0.0, "E", modulus_dimensions);
		d_var moment_of_inertia = d_var(0.0, "I", inertia_dimensions);
		d_var expansion_coeficient = d_var(0.0, "\\gamma", temperature_inverse_dimensions);
		d_var x = d_var(0.0, "x", length_dimensions);
		d_var a = d_var(0.0, "a", length_dimensions);

		// Extract unit steps to it's own header file?
		// I need a better latex for this? or just a working function
		template <typename T>
		T unit_step_formula(const T& x, const T& a, int n) {
			if ((double)x < (double)a) { return 0; }					// uy uy uy,
			if ((double)x > (double)a) { return 1; }					// uy uy uy, vale con double, pero con d_var???
		}

		// I need a better latex for this
		template <typename T>
		T step_formula(const T& x, const T& a, int n) {
			if ((double)x < (double)a) { return 0; }
			if ((double)x > (double)a) { return pow(x - a, n); }
		}

		// FORMULAS DEFINITION

		// concentrated intermediate load
		template <typename T>
		T vertical_shear_formula(const T& Ra, const T& W, const T& x, const T& a) {
			return Ra - W * unit_step_formula(x, a, 0);
		}

		template <typename T>
		T bending_moment_formula(const T& Ma, const T& Ra, const T& W, const T& x, const T& a) {
			return Ma + Ra * x - W * step_formula(x, a, 1);
		}

		template <typename T>
		T slope_formula(const T& Theta_a, const T& Ma, const T& Ra, const T& W, const T& x, const T& a) {
			return Theta_a + Ma * x / (E * I) + Ra * pow(x, 2) / (2 * E * I) - W / (2 * E * I) * step_formula(x, a, 2);
		}
		// qué pasa con E y con I? de donde los vas a cojer?
		// puedo necesitar E o (double)E...

		template <typename T>
		T deflection_formula(const T& Ya, const T& Theta_a, const T& Ma, const T& Ra, const T& W, const T& x, const T& a) {
			return Ya + Theta_a * x + Ma * pow(x, 2) / (2 * E * I) + Ra * pow(x, 3) / (6 * E * I) - W / (6 * E * I) * step_formula(x, a, 3);
		}

	};
}