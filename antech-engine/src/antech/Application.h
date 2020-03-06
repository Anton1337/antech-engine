#pragma once

#include "Core.h";

namespace Antech {

	class ANTECH_API Application
	{
	public:
		Application();
		virtual ~Application();

		void Run();
	};

	// To be defined in CLIENT
	Application* CreateApplication();


}


