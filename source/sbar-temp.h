#ifndef SBAR_TEMP_H
#define SBAR_TEMP_H

#include <ios>
#include <fstream>

namespace sbar
{
	struct Temp
	{
		Temp();
		~Temp();

		friend auto operator<<(std::ostream&, Temp&) -> std::ostream&;
		
	private:
		std::ifstream file_;
	};

	auto operator<<(std::ostream&, Temp&) -> std::ostream&;
}

#endif
