#include "sbar-clock.h"
#include "sbar.h"

namespace sbar
{
	auto operator<<(std::ostream& os, Clock) noexcept -> std::ostream&
	{
		auto now = clock::now();  
    	auto epoch = now.time_since_epoch();
		auto seconds = std::chrono::duration_cast<std::chrono::seconds>(epoch);
		os << std::format("date: {0:%F %R:}{1:%S}", now, seconds);
		return os;
	}
}

