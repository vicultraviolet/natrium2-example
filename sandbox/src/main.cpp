#include "Pch.hpp"
#include "Natrium2/Main.hpp"

#include <Natrium2/Core/Logger.hpp>
#include <Natrium2/Core/Context.hpp>

Na2::Logger<> logger{ "Sandbox" };

int main(int argc, char* argv[])
{
	Na2::Context context(ContextInitInfo{});
	context.bind();

	logger.printf(Na2::Notice, "Hello, {}!", "world");

	return 0;
}
