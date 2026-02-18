#include "Pch.hpp"
#include "App.hpp"

namespace Sandbox
{
	App::App(void)
	: m_EventQueue(),
	  m_Window(1280, 720, "Natrium Sandbox"),
	  m_LayerManager()
	{
		m_EventQueue.bind();
	}

	App::~App(void)
	{

	}

	void App::run(void)
	{
		m_Running = true;
		while (m_Running)
		{
			for (auto& e : m_EventQueue.poll())
			{
				if (e.type == Na2::EventType::WindowClosed)
				{
					m_Running = false;
					goto End;
				}

				for (auto& layer : m_LayerManager)
					if (!e.handled)
						layer->on_event(e);
			}

			for (auto& layer : m_LayerManager)
				layer->on_update(0.016);

			if (m_Window.minimized())
			{
				std::this_thread::sleep_for(33ms);
				continue;
			}

			for (auto& layer : m_LayerManager)
				layer->on_draw();

			std::this_thread::sleep_for(16ms);

		End:
			;
		}
	}
} // namespace Sandbox