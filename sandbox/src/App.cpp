#include "Pch.hpp"
#include "App.hpp"

#include <Natrium2/Chrono/TimeKeeper.hpp>

namespace Sandbox
{
	App::App(void)
	: m_AssetManager(Na2::AssetManagerCreateInfo{}),
	  m_LayerManager(),
	  m_EventQueue(),
	  m_Window(1280, 720, "Natrium Sandbox"),
	  m_TickAccumulator(1.0)
	{
		m_EventQueue.bind();
	}

	App::~App(void)
	{

	}

	void App::run(void)
	{
		Na2::Chrono::TimeKeeper timekeeper(144);

		m_Running = true;
		while (m_Running)
		{
			for (auto& e : m_EventQueue.poll())
			{
				if (e.type == Na2::EventType::WindowClosed)
					m_Running = false;

				for (auto& layer : m_LayerManager)
					if (!e.handled)
						layer->on_event(e);
			}

			f64 dt = timekeeper.tick();

			u64 tick_count = m_TickAccumulator.update(dt);
			for (auto& layer : m_LayerManager)
			{
				for (u64 i = 0; i < tick_count; i++)
					layer->on_tick();

				layer->on_update(dt);
			}

			if (m_Window.minimized())
			{
				std::this_thread::sleep_for(30ms);
				continue;
			}

			for (auto& layer : m_LayerManager)
				layer->on_draw();

			timekeeper.pace();
		}
	}
} // namespace Sandbox