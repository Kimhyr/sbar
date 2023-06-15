#include "sbar-temp.hxx"
#include "sbar-utils.hxx"

namespace sbar
{
	Temp::Temp()
		: file_("/sys/class/thermal/thermal_zone0/temp")
	{}

	Temp::~Temp()
	{
		file_.close();
	}

	auto operator<<(std::ostream& os, Temp& self) -> std::ostream&
	{
		std::size_t temp;
		self.file_ >> temp;
		self.file_.seekg(0);
		temp /= 1000;
		return os << "temp: " << temp << 'C';
	}
}
