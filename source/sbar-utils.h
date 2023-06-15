#ifndef SBAR_UTILS_H
#define SBAR_UTILS_H

#include <ios>
#include <limits>

namespace sbar
{
	template<int N>
	constexpr int BASE8 =  ((int)(N / 8.) < (N / 8.) ? (N / 8) + 1 : N / 8) * 8;
	
	constexpr long IGNORE = std::numeric_limits<std::streamsize>::max();

	constexpr unsigned FPRECISION = 1;

	// used for printing a floating-point number
	//
	struct pfloat
	{
		double value;

		pfloat(double x)
			: value(x) {}
	};

	auto operator<<(std::ostream& os, pfloat self) -> std::ostream&;
}


#endif
