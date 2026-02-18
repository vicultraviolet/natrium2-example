#ifndef SBX_CORE_HPP
#define SBX_CORE_HPP

#include <Natrium2/Core.hpp>
#include <Natrium2/Core/Logger.hpp>

namespace Sandbox
{
	using namespace Na2::Primitives;

	inline Na2::Logger<> g_Logger{ "Sandbox" };
} // namespace Sandbox

#endif // SBX_CORE_HPP