#ifndef SBX_APP_HPP
#define SBX_APP_HPP

#include "Core.hpp"
#include <Natrium2/Asset/AssetManager.hpp>
#include <Natrium2/Layer/LayerManager.hpp>
#include <Natrium2/Core/EventQueue.hpp>
#include <Natrium2/Core/Window.hpp>
#include <Natrium2/Chrono/Accumulator.hpp>

namespace Sandbox
{
	class App {
	public:
		App(void);
		~App(void);

		void run(void);

		inline void attach_layer(Na2::Ref<Na2::Layer> layer) { m_LayerManager.attach_layer(layer); }
		inline void detach_layer(Na2::Ref<Na2::Layer> layer) { m_LayerManager.detach_layer(layer); }

		[[nodiscard]] inline bool running(void) const { return m_Running; }

		[[nodiscard]] inline auto& asset_manager(void) { return m_AssetManager; }
		[[nodiscard]] inline const auto& asset_manager(void) const { return m_AssetManager; }

		[[nodiscard]] inline auto& layer_manager(void) { return m_LayerManager; }
		[[nodiscard]] inline const auto& layer_manager(void) const { return m_LayerManager; }

		[[nodiscard]] inline auto& event_queue(void) { return m_EventQueue; }
		[[nodiscard]] inline const auto& event_queue(void) const { return m_EventQueue; }

		[[nodiscard]] inline auto& window(void) { return m_Window; }
		[[nodiscard]] inline const auto& window(void) const { return m_Window; }

	private:
		bool m_Running = false;

		Na2::AssetManager m_AssetManager;
		Na2::LayerManager m_LayerManager;

		Na2::EventQueue m_EventQueue;
		Na2::Window m_Window;

		Na2::Chrono::Accumulator m_TickAccumulator;
	};
} // namespace Sandbox

#endif // SBX_APP_HPP