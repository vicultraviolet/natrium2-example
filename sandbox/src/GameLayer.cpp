#include "Pch.hpp"
#include "GameLayer.hpp"

namespace Sandbox
{
	GameLayer::GameLayer(
		Na2::AssetManager& asset_manager,
		i64 priority
	)
	: Na2::Layer(priority)
	{
		auto hello_world_txt = asset_manager.create_asset<Na2::Text>("hello_world");

		asset_manager.save_registry();

		hello_world_txt->str() = "hello, world!";
		hello_world_txt->save("assets/hello_world.txt");

		asset_manager.destroy_asset(hello_world_txt->uuid());
	}

	GameLayer::~GameLayer(void)
	{

	}

	void GameLayer::on_event(Na2::Event& e)
	{
		m_Input.on_event(e);
	}

	void GameLayer::on_tick(void)
	{
		g_Logger.printf(Na2::Debug, "FPS: {}", m_FrameCount);
		m_FrameCount = 0;
	}

	void GameLayer::on_update(f64 dt)
	{
		m_FrameCount++;

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
