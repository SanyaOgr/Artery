#include "artpch.h"
#include "Application.h"

namespace art {

    Application::Application()
    {
        Log::Init();

        m_rendererAPI = RendererAPI::CreatePlatformImpl();
        m_rendererAPI->Init();

        m_window = std::make_unique<Window>(WindowSettings{ "Cringe", 600, 400 });
        m_window2 = std::make_unique<Window>(WindowSettings{ "Cringe 2", 200, 200 });

		m_window->SetEventCallback(ART_FORWARD_EVENT_FN(Application::OnEvent));
        m_window2->SetEventCallback(ART_FORWARD_EVENT_FN(Application::OnEvent2));

        m_context = std::make_unique<GraphicsContext>(*m_window);
        m_context->SetCurrentDeviceContext(m_window->GetSystemDeviceContextHandle());

        m_context->SetActive();
	}

	Application::~Application()
	{
	}

	void Application::Run()
	{
        m_running = true;
        ART_INFO("Application Run");

        // OPENGL TEST CODE -----------------------------------------------------------------------------------------------

        const char* vertexShaderSource = "#version 330 core\n"
            "layout (location = 0) in vec3 aPos;\n"
            "void main()\n"
            "{\n"
            "   gl_Position = vec4(aPos.x, aPos.y, aPos.z, 1.0);\n"
            "}\0";
        const char* fragmentShaderSource = "#version 330 core\n"
            "out vec4 FragColor;\n"
            "void main()\n"
            "{\n"
            "   FragColor = vec4(1.0f, 0.5f, 0.2f, 1.0f);\n"
            "}\n\0";

        // build and compile our shader program
        // ------------------------------------
        // vertex shader
        unsigned int vertexShader = glCreateShader(GL_VERTEX_SHADER);
        glShaderSource(vertexShader, 1, &vertexShaderSource, NULL);
        glCompileShader(vertexShader);
        // check for shader compile errors
        int success;
        char infoLog[512];
        glGetShaderiv(vertexShader, GL_COMPILE_STATUS, &success);
        if (!success)
        {
            glGetShaderInfoLog(vertexShader, 512, NULL, infoLog);
            std::cout << "ERROR::SHADER::VERTEX::COMPILATION_FAILED\n" << infoLog << std::endl;
        }
        // fragment shader
        unsigned int fragmentShader = glCreateShader(GL_FRAGMENT_SHADER);
        glShaderSource(fragmentShader, 1, &fragmentShaderSource, NULL);
        glCompileShader(fragmentShader);
        // check for shader compile errors
        glGetShaderiv(fragmentShader, GL_COMPILE_STATUS, &success);
        if (!success)
        {
            glGetShaderInfoLog(fragmentShader, 512, NULL, infoLog);
            std::cout << "ERROR::SHADER::FRAGMENT::COMPILATION_FAILED\n" << infoLog << std::endl;
        }
        // link shaders
        unsigned int shaderProgram = glCreateProgram();
        glAttachShader(shaderProgram, vertexShader);
        glAttachShader(shaderProgram, fragmentShader);
        glLinkProgram(shaderProgram);
        // check for linking errors
        glGetProgramiv(shaderProgram, GL_LINK_STATUS, &success);
        if (!success) {
            glGetProgramInfoLog(shaderProgram, 512, NULL, infoLog);
            std::cout << "ERROR::SHADER::PROGRAM::LINKING_FAILED\n" << infoLog << std::endl;
        }
        glDeleteShader(vertexShader);
        glDeleteShader(fragmentShader);

        // set up vertex data (and buffer(s)) and configure vertex attributes
        // ------------------------------------------------------------------
        float vertices[] = {
             0.5f,  0.5f, 0.0f,  // top right
             0.5f, -0.5f, 0.0f,  // bottom right
            -0.5f, -0.5f, 0.0f,  // bottom left
            -0.5f,  0.5f, 0.0f   // top left 
        };
        unsigned int indices[] = {  // note that we start from 0!
            0, 1, 3,  // first Triangle
            1, 2, 3   // second Triangle
        };
        unsigned int VBO, VAO, EBO;
        glGenVertexArrays(1, &VAO);
        glGenBuffers(1, &VBO);
        glGenBuffers(1, &EBO);
        // bind the Vertex Array Object first, then bind and set vertex buffer(s), and then configure vertex attributes(s).
        glBindVertexArray(VAO);

        glBindBuffer(GL_ARRAY_BUFFER, VBO);
        glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW);

        glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, EBO);
        glBufferData(GL_ELEMENT_ARRAY_BUFFER, sizeof(indices), indices, GL_STATIC_DRAW);

        glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 3 * sizeof(float), (void*)0);
        glEnableVertexAttribArray(0);

        // note that this is allowed, the call to glVertexAttribPointer registered VBO as the vertex attribute's bound vertex buffer object so afterwards we can safely unbind
        glBindBuffer(GL_ARRAY_BUFFER, 0);

        // remember: do NOT unbind the EBO while a VAO is active as the bound element buffer object IS stored in the VAO; keep the EBO bound.
        //glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, 0);

        // You can unbind the VAO afterwards so other VAO calls won't accidentally modify this VAO, but this rarely happens. Modifying other
        // VAOs requires a call to glBindVertexArray anyways so we generally don't unbind VAOs (nor VBOs) when it's not directly necessary.
        glBindVertexArray(0);

        // -----------------------------------------------------------------------------------------------------------------------------------------------------------------------------

		while (m_running)
		{
            m_context->SetCurrentDeviceContext(m_window->GetSystemDeviceContextHandle());
            m_context->SetActive();
            m_window->OnUpdate();

            m_rendererAPI->SetClearColor(0.2f, 0.3f, 0.3f, 1.f);
            m_rendererAPI->Clear();

            // draw our first triangle
            glUseProgram(shaderProgram);
            glBindVertexArray(VAO); // seeing as we only have a single VAO there's no need to bind it every time, but we'll do so to keep things a bit more organized
            //glDrawArrays(GL_TRIANGLES, 0, 6);
            glDrawElements(GL_TRIANGLES, 6, GL_UNSIGNED_INT, 0);
            
            m_context->SwapBuffers();

            m_context->SetCurrentDeviceContext(m_window2->GetSystemDeviceContextHandle());
            m_context->SetActive();
            m_window2->OnUpdate();

            m_rendererAPI->Clear();
            glDrawElements(GL_TRIANGLES, 6, GL_UNSIGNED_INT, 0);

            m_context->SwapBuffers();
        }
		
        ART_INFO("Application Stopped");
	}

	void Application::OnEvent(Event& e)
	{
		EventDispatcher dispatcher(e);

		dispatcher.Dispatch<WindowClosedEvent>(ART_FORWARD_EVENT_FN(Application::onWindowClosed));
		dispatcher.Dispatch<WindowResizedEvent>(ART_FORWARD_EVENT_FN(Application::onWindowResized));
	}

    void Application::OnEvent2(Event& e)
    {
        EventDispatcher dispatcher(e);

        dispatcher.Dispatch<WindowResizedEvent>(ART_FORWARD_EVENT_FN(Application::onWindowResized2));
    }

	void Application::Close()
    {
		m_running = false;
	}

	bool Application::onWindowClosed(WindowClosedEvent& e)
	{
        ART_TRACE("{0}: ClosedEvent", m_window->GetTitle());
		Close();
		return true;
	}

	bool Application::onWindowResized(WindowResizedEvent& e)
	{
        ART_TRACE("{0}: ResizedEvent {1}x{2}", m_window->GetTitle(), e.GetWidth(), e.GetHeight());
        m_rendererAPI->SetViewport(0, 0, e.GetWidth(), e.GetHeight());
		return true;
	}

    bool Application::onWindowResized2(WindowResizedEvent& e)
    {
        ART_TRACE("{0}: ResizedEvent {1}x{2}", m_window2->GetTitle(), e.GetWidth(), e.GetHeight());
        m_rendererAPI->SetViewport(0, 0, e.GetWidth(), e.GetHeight());
        return true;
    }

}