#pragma once

#ifdef AT_PLATFORM_WINDOWS

extern Antech::Application* Antech::CreateApplication();

int main(int argc, char** argv) {
	Antech::Log::Init();
	AT_CORE_ERROR("Init Log");
	int b = 3;
	AT_INFO("Hello Var={0}", b);


	auto app = Antech::CreateApplication();
	app->Run();
	delete app;
}

#endif
