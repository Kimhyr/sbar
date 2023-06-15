#include "sbar-battery.h"
#include "sbar-utils.h"

#define PATH "/sys/class/power_supply/BAT0/"

namespace sbar
{
	Battery::Battery()
		: capacity_(PATH "capacity"), power_now_(PATH "power_now"),
		  status_(PATH "status") {}

	Battery::~Battery()
	{
		capacity_.close();
		power_now_.close();
		status_.close();
	}

	auto operator<<(std::ostream& os, Battery& self) -> std::ostream&
	{
		short capacity;
		self.capacity_ >> capacity;
		self.capacity_.seekg(0);
		
		unsigned power_now;
		self.power_now_ >> power_now;
		self.power_now_.seekg(0);
		pfloat wpower_now = static_cast<double>(power_now) / 1'000'000;

		char status;
		self.status_ >> status;
		self.status_.seekg(0);
	
		return os << "battery: " << status << ' ' << wpower_now << "W " << capacity << '%';
	}
}
