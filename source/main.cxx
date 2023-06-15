#include "sbar.hxx"

#include <immintrin.h>
#include <iostream>

int main(int argc, char const* argv[])
{
	(void)argv, (void)argc;
	sbar::SBar bar;
	for (;;) {
		std::cout << bar;
	}
	return 0;
}
