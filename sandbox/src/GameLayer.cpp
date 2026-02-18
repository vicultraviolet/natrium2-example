#include "Pch.hpp"
#include "GameLayer.hpp"

namespace Sandbox
{
	GameLayer::GameLayer(i64 priority)
	: Na2::Layer(priority)
	{

	}

	GameLayer::~GameLayer(void)
	{

	}

	void GameLayer::on_event(Na2::Event& e)
	{
		m_Input.on_event(e);
	}

	void GameLayer::on_update(f64 dt)
	{
		if (m_Input.key(Na2::Key::A))
		{
			g_Logger.printf(Na2::Notice, "A key is being held down!");
		}
	}

	void GameLayer::on_draw(void)
	{

	}

	void GameLayer::on_imgui_draw(void)
	{

	}
} // namespace Sandbox
