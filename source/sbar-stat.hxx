#ifndef SBAR_STAT_HXX
#define SBAR_STAT_HXX

#include <fstream>

namespace sbar
{
	struct Stat
	{
		Stat();
		~Stat();

		friend auto operator<<(std::ostream&, Stat&) -> std::ostream&;
		
	private:
		std::ifstream file_;
		int idle_;
		int total_ = 0;
	};

	auto operator<<(std::ostream& os, Stat& self) -> std::ostream&;
}

#endif
