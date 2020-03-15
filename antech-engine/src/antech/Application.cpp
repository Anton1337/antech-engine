#include "Application.h"

#include "antech/Events/ApplicationEvent.h"
#include "antech/Log.h"

namespace Antech {

	Application::Application(){}
	Application::~Application(){}

	void Application::Run() {
		WindowResizeEvent e(1280, 720);
		if (e.IsInCategory(EventCategoryApplication)) {
			AT_TRACE(e);
		}
		if (e.IsInCategory(EventCategoryInput)) {
			AT_TRACE(e);
		}

		while (true);
	}
}
