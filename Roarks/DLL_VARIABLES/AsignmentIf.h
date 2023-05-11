#pragma once

#include <vector>
#include <functional>
#include <type_traits>

template <typename B, typename T>
using ConditionAssignmentPair = std::pair<std::function<B()>, std::function<T()>>;

template <typename B, typename T>
T AssignmentIf(const std::vector<ConditionAssignmentPair<B,T>>& condition_list) {
	std::string latex_formula = "\\begin{cases}";
	double retval = 0.0;
	for (const auto& [condition, assignment] : condition_list) {
		if constexpr (std::is_same_v<T, double>) {
			if (condition()) {
				return assignment();
			}
		}
		else if constexpr (std::is_same_v<T, n_var>) {
			BoolVariable cond = condition();
			latex_formula += assignment().get_latex_symbol() + "& \\mathrm{if} \\ " + cond.get_latex_symbol() + " \\\\";
			if (condition()) {
				retval = double(assignment());
			}
		}
	}
	latex_formula += "\\end{cases}";
	n_var result(retval, latex_formula);
	return result;
}

