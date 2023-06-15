#ifndef SBAR_SYSINFO_H
#define SBAR_SYSINFO_H

#include <fstream>

namespace sbar
{
	struct MemInfo
	{
		MemInfo();
		~MemInfo();

		friend auto operator<<(std::ostream&, MemInfo&) -> std::ostream&;
	
	private:
		std::ifstream file_;
	};

	auto operator<<(std::ostream& os, MemInfo& self) -> std::ostream&;
};

#endif
