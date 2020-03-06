#include <Antech.h>

class Sandbox : public Antech::Application {
public:
	Sandbox(){}
	~Sandbox(){}
};

Antech::Application* Antech::CreateApplication() {
	return new Sandbox();
}