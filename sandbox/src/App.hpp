#ifndef SBX_APP_HPP
#define SBX_APP_HPP

#include "Core.hpp"
#include <Natrium2/Core/EventQueue.hpp>
#include <Natrium2/Core/Window.hpp>
#include <Natrium2/Layer/LayerManager.hpp>

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

		[[nodiscard]] inline auto& event_queue(void) { return m_EventQueue; }
		[[nodiscard]] inline const auto& event_queue(void) const { return m_EventQueue; }

		[[nodiscard]] inline auto& window(void) { return m_Window; }
		[[nodiscard]] inline const auto& window(void) const { return m_Window; }

		[[nodiscard]] inline auto& layer_manager(void) { return m_LayerManager; }
		[[nodiscard]] inline const auto& layer_manager(void) const { return m_LayerManager; }

	private:
		bool m_Running = false;

		Na2::EventQueue m_EventQueue;
		Na2::Window m_Window;
		Na2::LayerManager m_LayerManager;
	};
} // namespace Sandbox

#endif // SBX_APP_HPP