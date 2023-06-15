#ifndef SBAR_CLOCK_HXX
#define SBAR_CLOCK_HXX

#include <chrono>
#include <ostream>

namespace sbar
{
	using clock = std::chrono::system_clock;
	
	struct Clock
	{
		Clock() = default;
		~Clock() = default;
		
		friend auto operator<<(std::ostream&, Clock) noexcept -> std::ostream&;
	};

	auto operator<<(std::ostream& os, Clock date) noexcept -> std::ostream&;
}


#endif
