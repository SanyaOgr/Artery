#pragma once
#include <string>
#include <glad/glad.h>
#include <GLFW/glfw3.h>

namespace art {

	class Window
	{
	public:
		Window(int width, int height, const std::string& title);

		void Update();

	private:
		GLFWwindow* m_glfwHandle;
	};

 }