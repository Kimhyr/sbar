#include "sbar-stat.hxx"
#include "sbar-utils.hxx"

#include <numeric>
#include <iostream>

namespace sbar
{
	Stat::Stat()
		: file_("/proc/stat"), total_(0)
	{
		file_.ignore(IGNORE, ' ');
		int times[BASE8<7>];
		for (unsigned i = 0; i < sizeof(times) / sizeof(int); ++i) {
			file_ >> times[i];
			total_ += times[i];
		}
		file_.seekg(0);
		idle_ = times[3];
	}

	Stat::~Stat()
	{
		file_.close();
	}

	auto operator<<(std::ostream& os, Stat& self) -> std::ostream&
	{
		self.file_.ignore(IGNORE, ' ');
		int times[BASE8<7>];
		int total = 0;
		for (unsigned i = 0; i < sizeof(times) / sizeof(int); ++i) {
			self.file_ >> times[i];
			total += times[i];
		}
		self.file_.seekg(0);
		
		int idle = times[3];
		int idle_delta = idle - self.idle_;
		int total_delta = total - self.total_;
		pfloat util = 100. * (total_delta - static_cast<double>(idle_delta)) / total_delta;
		
		self.idle_ = idle;
		self.total_ = total;
		return os << "cpu: " << util << '%';
	}
}
