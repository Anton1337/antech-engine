#include <Antech.h>

class ExampleLayer : public Antech::Layer {

public:
	ExampleLayer()
		: Layer("Example") {}

	void OnUpdate() override {
		AT_INFO("ExampleLayer::Update");
	}

	void OnEvent(Antech::Event& event) override {
		AT_TRACE("{0}", event);
	}
};

class Sandbox : public Antech::Application {
public:
	Sandbox(){
		PushLayer(new ExampleLayer());
	}
	~Sandbox(){}
};

Antech::Application* Antech::CreateApplication() {
	return new Sandbox();
}