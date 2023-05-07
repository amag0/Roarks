#include "pch.h"
#include "CppUnitTest.h"
#include "../Concept/n_var.h"
#include "../DLL_VARIABLES/n_var_math.h"
#define _USE_MATH_DEFINES
#include <math.h>

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

// test dimensions
// test d_var addition, subtraction, multiplication, division...
// test d_var creation

namespace ConceptTests
{
	TEST_CLASS(TestNamedVariableOperators)
	{
	public:
		TEST_METHOD(AddNamedVariables)
		{
			n_var FirstSide(7.0, "L_{1}");
			n_var SecondSide(8.5, "L_{2}");
			n_var ThirdSide(6.2, "L_{3}");
			n_var Perimeter(0.0, "P");

			Perimeter = FirstSide + SecondSide + ThirdSide;
			const double ExpectedValue = 7.0 + 8.5 + 6.2;
			const char* ExpectedSymbol = "P";
			const char* ExpectedFormula = "P = L_{1} + L_{2} + L_{3}";

			Assert::AreEqual(double(Perimeter), ExpectedValue);
			Assert::AreEqual(Perimeter.get_latex_symbol().c_str(), ExpectedSymbol);
			Assert::AreEqual(Perimeter.get_latex_formula().c_str(), ExpectedFormula);
		}
		TEST_METHOD(SubtractNamedVariables)
		{
			n_var FirstValue(3.284, "a");
			n_var SecondValue(2.11, "b");
			n_var Subtraction(0.0, "r");

			Subtraction = FirstValue - SecondValue;
			const double ExpectedValue = 3.284 - 2.11, ExpecedFirstValue = 3.284, ExpectedSecondValue = 2.11;
			const char* ExpectedSymbol = "r", *ExpectedFirstSymbol = "a", *ExpectedSecondSymbol = "b";
			const char* ExpectedFormula = "r = a - b";

			Assert::AreEqual(double(Subtraction), ExpectedValue);
			Assert::AreEqual(Subtraction.get_latex_symbol().c_str(), ExpectedSymbol);
			Assert::AreEqual(Subtraction.get_latex_formula().c_str(), ExpectedFormula);
		}
		// MultiplyNamedVariables
		// DivideNamedVariables
		// pi constant
		TEST_METHOD(MoreComplexFormula)
		{
			double E = 200000, A = 74.5, I = 700, L = 180;
			const char* SymbolE = "E_{c}", * SymbolA = "A", * SymbolI = "I_{x}", * SymbolL = "L";
			n_var vE(E, SymbolE), vA(A, SymbolA), vI(I, SymbolI), vL(L, SymbolL);
			n_var vPcr(0, "P_{cr}");
			
			vPcr = pow(pi_var, 2) * vE * vI / pow(vL, 2);
			const double ExpectedValue = pow(M_PI, 2) * E * I / pow(L, 2);
			const char* ExpectedSymbol = "P_{cr}";
			const char* ExpectedFormula = "P_{cr} = \\frac{\\pi^{2} \\cdot E_{c} \\cdot I_{x}}{L^{2}}";

			// check formula results
			Assert::AreEqual(double(vPcr), ExpectedValue);
			Assert::AreEqual(vPcr.get_latex_symbol().c_str(), ExpectedSymbol);
			Assert::AreEqual(vPcr.get_latex_formula().c_str(), ExpectedFormula);
			// check variables
			Assert::AreEqual(vI.get_latex_symbol().c_str(), SymbolI);
			Assert::AreEqual(double(vI), I);
		}

		TEST_METHOD(ComparisonOperator)
		{
			n_var FirstValue(2.16, "a");
			n_var SecondValue(0.87, "x");

			BoolVariable Coincident = FirstValue == SecondValue;
			BoolVariable NotEqual = FirstValue != SecondValue;
			BoolVariable LessThan = FirstValue < SecondValue;
			BoolVariable GreaterThan = FirstValue > SecondValue;
			BoolVariable LessThanOrEqual = FirstValue <= SecondValue;
			BoolVariable GreaterThanOrEqual = FirstValue >= SecondValue;

			bool CoincidentValue = (double)FirstValue == (double)SecondValue;
			bool NotEqualValue = (double)FirstValue != (double)SecondValue;
			bool LessThanValue = (double)FirstValue < (double)SecondValue;
			bool GreaterThanValue = (double)FirstValue > (double)SecondValue;
			bool LessThanOrEqualValue = (double)FirstValue <= (double)SecondValue;
			bool GreaterThanOrEqualValue = (double)FirstValue >= (double)SecondValue;

			const char* CoincidentSymbol = "a = x";
			const char* NotEqualSymbol = "a \\neq x";
			const char* LessThanSymbol = "a < x";
			const char* GreaterThanSymbol = "a > x";
			const char* LessThanOrEqualSymbol = "a \\leq x";
			const char* GreaterThanOrEqualSymbol = "a \\geq x";

			Assert::AreEqual(bool(Coincident), CoincidentValue);
			Assert::AreEqual(bool(NotEqual), NotEqualValue);
			Assert::AreEqual(bool(LessThan), LessThanValue);
			Assert::AreEqual(bool(GreaterThan), GreaterThanValue);
			Assert::AreEqual(bool(LessThanOrEqual), LessThanOrEqualValue);
			Assert::AreEqual(bool(GreaterThanOrEqual), GreaterThanOrEqualValue);

			Assert::AreEqual(Coincident.get_latex_symbol().c_str(), CoincidentSymbol);
			Assert::AreEqual(NotEqual.get_latex_symbol().c_str(), NotEqualSymbol);
			Assert::AreEqual(LessThan.get_latex_symbol().c_str(), LessThanSymbol);
			Assert::AreEqual(GreaterThan.get_latex_symbol().c_str(), GreaterThanSymbol);
			Assert::AreEqual(LessThanOrEqual.get_latex_symbol().c_str(), LessThanOrEqualSymbol);
			Assert::AreEqual(GreaterThanOrEqual.get_latex_symbol().c_str(), GreaterThanOrEqualSymbol);
		}

		TEST_METHOD(MoreComplexComparison)
		{
			n_var First(10, "a");
			n_var Second(3, "b");
			n_var Third(6, "x");

			BoolVariable Comparison = sqrt(First) <= Second + n_var(1.0) / Third;
			
			bool ExpectedValue = sqrt(double(First)) <= double(Second) + 1.0 / double(Third);
			const char* ExpectedSymbol = "\\sqrt[2]{a} \\leq b + \\frac{1}{x}";

			Assert::AreEqual(bool(Comparison), ExpectedValue);
			Assert::AreEqual(Comparison.get_latex_symbol().c_str(), ExpectedSymbol);
		}

		TEST_METHOD(OtherFunctions)
		{
			double dValue = -1.16;
			double xValue = 2.18;
			n_var d(dValue, "d");
			n_var x(xValue, "x");

			const char* ExpFunction = "e^{d}";
			const char* LogFunction = "\\ln(x)";
			const char* SqrtFunction = "\\sqrt[2]{x}";

			Assert::AreEqual(exp(dValue), double(exp(d)));
			Assert::AreEqual(log(xValue), double(log(x)));
			Assert::AreEqual(sqrt(xValue), double(sqrt(x)));
		
			Assert::AreEqual(ExpFunction, exp(d).get_latex_symbol().c_str());
			Assert::AreEqual(LogFunction, log(x).get_latex_symbol().c_str());
			Assert::AreEqual(SqrtFunction, sqrt(x).get_latex_symbol().c_str());
		}

		TEST_METHOD(VerticalSymbols)
		{
			double dValue = -1.11;
			n_var d(dValue, "d");

			const char* AbsFunction = "\\lvert d \\rvert";
			const char* CeilFunction = "\\lceil d \\rceil";
			const char* FloorFunction = "\\lfloor d \\rfloor";
		
			Assert::AreEqual(abs(dValue), double(abs(d)));
			Assert::AreEqual(ceil(dValue), double(ceil(d)));
			Assert::AreEqual(floor(dValue), double(floor(d)));

			Assert::AreEqual(AbsFunction, abs(d).get_latex_symbol().c_str());
			Assert::AreEqual(CeilFunction, ceil(d).get_latex_symbol().c_str());
			Assert::AreEqual(FloorFunction, floor(d).get_latex_symbol().c_str());
		}
		
		TEST_METHOD(TrigonometricExpresions)
		{
			double alpha = 0.77;
			n_var Angle(alpha, "\\alpha");
			double x = 2.18;
			double y = -0.6;
			n_var xVar(x, "x");
			n_var yVar(y, "y");

			const char* SinSymbol = "\\sin(\\alpha)";
			const char* CosSymbol = "\\cos(\\alpha)";
			const char* TanSymbol = "\\tan(\\alpha)";
			const char* ArcSinSymbol = "\\arcsin(\\frac{y}{x})";
			const char* ArcCosSymbol = "\\arccos(\\frac{y}{x})";
			const char* ArcTanSymbol = "\\arctan(\\frac{y}{x})";
			const char* ArcTan2Symbol = "\\arctan(\\frac{y}{x})";

			Assert::AreEqual(sin(alpha), double(sin(Angle)));
			Assert::AreEqual(cos(alpha), double(cos(Angle)));
			Assert::AreEqual(tan(alpha), double(tan(Angle)));
			Assert::AreEqual(asin(y/x), double(asin(yVar/xVar)));
			Assert::AreEqual(acos(y/x), double(acos(yVar/xVar)));
			Assert::AreEqual(atan(y/x), double(atan(yVar/xVar)));
			Assert::AreEqual(atan2(y,x), double(atan2(yVar, xVar)));

			Assert::AreEqual(SinSymbol, sin(Angle).get_latex_symbol().c_str());
			Assert::AreEqual(CosSymbol, cos(Angle).get_latex_symbol().c_str());
			Assert::AreEqual(TanSymbol, tan(Angle).get_latex_symbol().c_str());
			Assert::AreEqual(ArcSinSymbol, asin(yVar / xVar).get_latex_symbol().c_str());
			Assert::AreEqual(ArcCosSymbol, acos(yVar / xVar).get_latex_symbol().c_str());
			Assert::AreEqual(ArcTanSymbol, atan(yVar / xVar).get_latex_symbol().c_str());
			Assert::AreEqual(ArcTan2Symbol, atan2(yVar, xVar).get_latex_symbol().c_str());
		}

		TEST_METHOD(HyperbolicTrigonometric)
		{
			double beta = 0.77;
			double bValue = 3.11;
			double cValue = 1.27;

			n_var Angle(beta, "\\beta");
			n_var b(bValue, "b");
			n_var c(cValue, "c");

			const char* SinH = "\\sinh(\\beta)";
			const char* CosH = "\\cosh(\\beta)";
			const char* TanH = "\\tanh(\\beta)";
			const char* ArcSinH = "\\arcsinh(\\frac{b}{c})";
			const char* ArcCosH = "\\arccosh(\\frac{b}{c})";
			const char* ArcTanH = "\\arctanh(\\frac{c}{b})";

			Assert::AreEqual(sinh(beta), double(sinh(Angle)));
			Assert::AreEqual(cosh(beta), double(cosh(Angle)));
			Assert::AreEqual(tanh(beta), double(tanh(Angle)));
			Assert::AreEqual(asinh(bValue / cValue), double(asinh(b / c)));
			Assert::AreEqual(acosh(bValue / cValue), double(acosh(b / c)));
			Assert::AreEqual(atanh(cValue / bValue), double(atanh(c / b)));

			Assert::AreEqual(SinH, sinh(Angle).get_latex_symbol().c_str());
			Assert::AreEqual(CosH, cosh(Angle).get_latex_symbol().c_str());
			Assert::AreEqual(TanH, tanh(Angle).get_latex_symbol().c_str());
			Assert::AreEqual(ArcSinH, asinh(b / c).get_latex_symbol().c_str());
			Assert::AreEqual(ArcCosH, acosh(b / c).get_latex_symbol().c_str());
			Assert::AreEqual(ArcTanH, atanh(c / b).get_latex_symbol().c_str());
		}
		// TODO: test the AssignmentIf function
	};
}
