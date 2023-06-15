#ifndef SBAR_HXX
#define SBAR_HXX

#include "sbar-clock.hxx"
#include "sbar-meminfo.hxx"
#include "sbar-stat.hxx"
#include "sbar-statvfs.hxx"
#include "sbar-temp.hxx"
#include "sbar-battery.hxx"

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
