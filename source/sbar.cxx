#include "sbar.hxx"

#include <iostream>
#include <thread>

namespace sbar
{
	auto operator<<(std::ostream& os, SBar& self) -> std::ostream&
	{
		std::cout
			<< self.light_ << SEP
			<< self.temp_ << SEP
			<< self.stat_ << SEP
			<< self.mem_info_ << SEP
			<< self.statvfs_ << SEP
			<< self.battery_ << SEP
			<< self.clock_ << std::endl;
		auto seconds = std::chrono::seconds(TICK);
		std::this_thread::sleep_for(seconds);
		return os;
	}
}
