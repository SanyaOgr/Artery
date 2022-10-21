#include "Window.h"
#include <iostream>

namespace art {

	Window::Window(int width, int height, const std::string& title)
        : m_glfwHandle(nullptr)
	{
		if (!glfwInit())
		{
			std::cout << "failed to init GLFW\n";
		}
		
		m_glfwHandle = glfwCreateWindow(width, height, title.c_str(), nullptr, nullptr);

		if (!m_glfwHandle)
		{
			std::cout << "failed to create GLFW window\n";
		}
		
		glfwMakeContextCurrent(m_glfwHandle);

		if (!gladLoadGLLoader(reinterpret_cast<GLADloadproc>(glfwGetProcAddress)))
		{
			std::cout << "failed to init OpenGL context\n";
		}

		glfwSetCursorPosCallback(m_glfwHandle, [](GLFWwindow*, double xpos, double ypos) {
			std::cout << "X: " << xpos << "\tY: " << ypos << "\n";
			});
	}

	void Window::Update()
	{
		glfwPollEvents();
		glfwSwapBuffers(m_glfwHandle);
	}

}
