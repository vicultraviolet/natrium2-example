#include "Pch.hpp"
#include <Natrium2/Main.hpp>

#include <Natrium2/Core/Logger.hpp>
#include <Natrium2/Core/Context.hpp>

#include <Natrium2/Core/Window.hpp>
#include <Natrium2/Core/EventQueue.hpp>
#include <Natrium2/Core/Input.hpp>

Na2::Logger<> logger{ "Sandbox" };

int main(int argc, char* argv[])
{
	Na2::Context context(ContextInitInfo{});
	context.bind();

	Na2::EventQueue event_queue;
	event_queue.bind();

	Na2::Window window(1280, 720, "Natrium Sandbox");

	Na2::Input input;

	while (true)
	{
		for (auto& e : event_queue.poll())
		{
			if (e.type == Na2::EventType::WindowClosed)
				goto End;

			if (e.type == Na2::EventType::KeyPressed)
			{
				if (e.key_pressed.key == Na2::Key::H)
					logger.printf(Na2::Trace, "Key H pressed!");
			}

			input.on_event(e);
		}

		if (input.key(Key::A))
			logger.printf(Na2::Trace, "Key A is pressed!");

		std::this_thread::sleep_for(16ms);
	}

End:
	return 0;
}
