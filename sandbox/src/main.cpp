#include "Pch.hpp"
#include "Natrium2/Main.hpp"

#include "Natrium2/Core/Logger.hpp"

Na2::Logger<> logger{ "Sandbox" };

int main(int argc, char* argv[])
{
	logger.printf(Na2::Notice, "Hello, {}!", "world");

	return 0;
}
