#include "sbar-meminfo.hxx"
#include "sbar-utils.hxx"

#include <iostream>

namespace sbar
{
	MemInfo::MemInfo()
		: file_("/proc/meminfo")
	{}

	MemInfo::~MemInfo()
	{
		file_.close();
	}

	auto operator<<(std::ostream& os, MemInfo& self) -> std::ostream&
 	{
		std::size_t total, available;
		self.file_.ignore(IGNORE, ':');
		self.file_ >> total;
		self.file_.ignore(IGNORE, ':');
		self.file_.ignore(IGNORE, ':');
		self.file_ >> available;
		self.file_.seekg(0);

		pfloat perc = 100 - static_cast<double>(available) / total * 100;
		return os << "memory: " << perc << '%';
	}

}
