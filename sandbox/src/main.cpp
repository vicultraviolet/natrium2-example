#include "Pch.hpp"
#include <Natrium2/Main.hpp>

#include <Natrium2/Core/Context.hpp>
#include "App.hpp"

#include "GameLayer.hpp"

int main(int argc, char* argv[])
{
	Na2::Context context(ContextInitInfo{});
	context.bind();

	auto app = Na2::MakeUnique<Sandbox::App>();

	app->attach_layer(Na2::MakeRef<Sandbox::GameLayer>());

	app->run();
	
	return 0;
}
