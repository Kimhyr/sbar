#ifndef SBAR_LIGHT_HXX
#define SBAR_LIGHT_HXX

#include <fstream>

namespace sbar
{
	struct Light
	{
		Light();
		~Light();

		friend auto operator<<(std::ostream&, Light&) -> std::ostream&;
		
	public:
		std::ifstream file_;
	};
	
	auto operator<<(std::ostream&, Light&) -> std::ostream&;
}

#endif
