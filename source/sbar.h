#ifndef SBAR_H
#define SBAR_H

#include "sbar-clock.h"
#include "sbar-meminfo.h"
#include "sbar-stat.h"
#include "sbar-statvfs.h"
#include "sbar-temp.h"
#include "sbar-battery.h"

namespace sbar
{
	constexpr unsigned TICK = 1;
	constexpr char const* SEP = " | ";

	struct SBar
	{
		SBar() = default;
		~SBar() = default;

		friend auto operator<<(std::ostream&, SBar&) -> std::ostream&;

	private:
		Clock clock_;
		MemInfo mem_info_;
		Stat stat_;
		Statvfs statvfs_;
		Temp temp_;
		Battery battery_;
	};
	
	auto operator<<(std::ostream& os, SBar& self) -> std::ostream&;
}

#endif
