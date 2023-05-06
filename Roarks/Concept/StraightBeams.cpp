#include "StraightBeams.h"

using namespace straigth_beam;

StraightBeamAnalysis* StraightBeamAnalysisFactory::create_beam_analysis(LoadCondition load_condition, EndRestraint end_restraint) {
	if (load_condition == LoadCondition::ConcentratedIntermediateLoad && end_restraint == EndRestraint::LeftFreeRightFixed)
	{
		return new ConcentratedLoadLeftFreeRightFixedStraightBeam();
	}
	return nullptr;
}