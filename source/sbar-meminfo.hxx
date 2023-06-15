#ifndef SBAR_SYSINFO_HXX
#define SBAR_SYSINFO_HXX

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
