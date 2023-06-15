#ifndef SBAR_BATTERY_H
#define SBAR_BATTERY_H

#include <fstream>

namespace sbar
{
	struct Battery
	{
		Battery();
		~Battery();

		friend auto operator<<(std::ostream& os, Battery& self) -> std::ostream&;
		
	private:
		std::ifstream capacity_;
		std::ifstream power_now_;
		std::ifstream status_;
	};

	auto operator<<(std::ostream& os, Battery& self) -> std::ostream&;
}

#endif
