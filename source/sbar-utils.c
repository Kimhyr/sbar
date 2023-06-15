#include "sbar-utils.h"

#include <iomanip>

namespace sbar
{
	auto operator<<(std::ostream& os, pfloat self) -> std::ostream&
	{
		return os << std::fixed << std::setprecision(FPRECISION) << self.value;
	}
}

