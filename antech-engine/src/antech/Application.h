#pragma once

#include "Core.h";

#include "Window.h"
#include "antech/LayerStack.h"
#include "antech/Events/Event.h"
#include "antech/Events/ApplicationEvent.h"


namespace Antech {

	class ANTECH_API Application
	{
	public:
		Application();
		virtual ~Application();

		void Run();

		void OnEvent(Event& e);

		void PushLayer(Layer* layer);
		void PushOverlay(Layer* overlay);
		
	private:
		bool OnWindowClose(WindowCloseEvent& e);

		std::unique_ptr<Window> m_Window;
		bool m_Running = true;
		LayerStack m_LayerStack;
	};

	// To be defined in CLIENT
	Application* CreateApplication();


}


