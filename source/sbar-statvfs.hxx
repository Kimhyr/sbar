#ifndef SBAR_STATVFS_HXX
#define SBAR_STATVFS_HXX

#include <ios>
#include <sys/statvfs.h>

namespace sbar
{
	struct Statvfs
	{
		Statvfs();
		~Statvfs() = default;

		friend auto operator<<(std::ostream&, Statvfs&) -> std::ostream&;
		
	private:
		struct statvfs root_;
		struct statvfs home_;
	};

	auto operator<<(std::ostream&, Statvfs&) -> std::ostream&;
}

#endif
