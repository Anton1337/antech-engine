#include "hzpch.h"
#include "Application.h"

#include "antech/Events/ApplicationEvent.h"
#include "antech/Log.h"

#include <GLFW/glfw3.h>

namespace Antech {

#define BIND_EVENT_FN(x) std::bind(&Application::x, this, std::placeholders::_1)

	Application::Application(){
		m_Window = std::unique_ptr<Window>(Window::Create());
		m_Window->SetEventCallback(BIND_EVENT_FN(OnEvent));
	}
	Application::~Application(){}

	void Application::OnEvent(Event& e) {
		AT_CORE_INFO("{0}", e);
	}

	void Application::Run() {

		while (m_Running) {
			glClearColor(1, 0, 1, 1);
			glClear(GL_COLOR_BUFFER_BIT);
			m_Window->OnUpdate();
		}
	}
}
