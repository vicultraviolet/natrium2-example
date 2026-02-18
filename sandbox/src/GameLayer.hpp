#ifndef SBX_GAME_LAYER_HPP
#define SBX_GAME_LAYER_HPP

#include "Core.hpp"
#include <Natrium2/Layer/Layer.hpp>
#include <Natrium2/Core/Input.hpp>
#include <Natrium2/Asset/AssetManager.hpp>
#include <Natrium2/Asset/Text.hpp>

namespace Sandbox
{
	class GameLayer : public Na2::Layer {
	public:
		GameLayer(Na2::AssetManager&, i64 priority = 0);
		~GameLayer(void);

		void on_event(Na2::Event& e) override;
		void on_update(f64 dt) override;
		void on_draw(void) override;
		void on_imgui_draw(void) override;
	private:
		Na2::Input m_Input;
	};
} // namespace Sandbox

#endif // SBX_GAME_LAYER_HPP