#include "sbar-statvfs.h"
#include "sbar-utils.h"

#include <ostream>

namespace sbar
{
	Statvfs::Statvfs()
	{
		statvfs("/", &root_);
		statvfs("/home", &home_);
	}

	auto operator<<(std::ostream& os, Statvfs& self) -> std::ostream&
	{
		std::size_t rtotal = self.root_.f_blocks;
		std::size_t rfree = self.root_.f_bavail;
		std::size_t rused = rtotal - rfree;
		pfloat rperc = static_cast<float>(rused) / rtotal * 100;
		statvfs("/", &self.root_);

		std::size_t htotal = self.home_.f_blocks;
		std::size_t hfree = self.home_.f_bavail;
		std::size_t hused = htotal - hfree;
		pfloat hperc = static_cast<float>(hused) / htotal * 100;
		statvfs("/home", &self.home_);

		return os << "disk: " << "/ " << rperc << "% /home " << hperc << '%';
	}
}
