#pragma once

#ifdef AT_PLATFORM_WINDOWS

extern Antech::Application* Antech::CreateApplication();

int main(int argc, char** argv) {
	auto app = Antech::CreateApplication();
	app->Run();
	delete app;
}

#endif
