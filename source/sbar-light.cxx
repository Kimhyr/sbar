#include "sbar-light.hxx"

namespace sbar
{
	Light::Light()
		: file_("/sys/class/backlight/amdgpu_bl0/brightness")
	{}

	Light::~Light()
	{
		file_.close();
	}

	auto operator<<(std::ostream& os, Light& self) -> std::ostream&
	{
		int result;
		self.file_ >> result;
		self.file_.seekg(0);
		return os << "light: " << result;
	}
}
