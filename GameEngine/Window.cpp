#include <iostream>
#include "Window.h"
#include "errors.h"

#define GLFW_FALSE 0

namespace GameEngine {

	bool Window::initialized = false;
	GLFWwindow* Window::currWindow = nullptr;
	void Window::init(){
		if(!initialized){
			if (!glfwInit())
			{
				glfwTerminate();
				fatalError("Could not init GLFW");
			}

			glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
			glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);

	#ifdef __APPLE__
			glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, GL_TRUE);
			glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
	#endif

			glfwWindowHint(GLFW_RESIZABLE, GLFW_FALSE);
			glfwSetErrorCallback(glfwError);

			initialized = true;

		}
	}
	void Window::clear(){
		glClearColor(0.2f, 0.2f, 0.2f, 1.0f);
		glClear(GL_COLOR_BUFFER_BIT | GL_STENCIL_BUFFER_BIT);

	}

	void Window::mouse_button_callback(GLFWwindow* window, int button, int action, int mods)
	{
		(action != GLFW_RELEASE) ? InputManager::pressMouseKey(button) : InputManager::releaseMouseKey(button);
	}

	void Window::swapBuffers(){
		glfwSwapBuffers(m_window);
	}

	void Window::framebuffer_size_callback(GLFWwindow* window, int width, int height)
	{
    // make sure the viewport matches the new window dimensions; note that width and
    // height will be significantly larger than specified on retina displays.
    glViewport(0, 0, width, height);
	}

	void Window::cursor_enter_callback(GLFWwindow* window, int entered){
	    if (entered)
	    {
	    	currWindow = window;
	    }else{
	    	currWindow = nullptr;
	    }
	}

	void Window::scroll_callback(GLFWwindow* window, double xoffset, double yoffset)
	{
		InputManager::addScroll(glm::vec2(xoffset, yoffset));
	}

	void Window::key_callback(GLFWwindow* window, int key, int scancode, int action, int mods)
	{
		(action != GLFW_RELEASE) ? InputManager::pressKey(key) : InputManager::releaseKey(key);
	}



	void Window::cursor_position_callback(GLFWwindow* window, double xpos, double ypos)
	{
		InputManager::setMouseCoords((float)xpos, (float)ypos, (void*) window);
	}

	bool Window::terminated = false;
	Window::~Window() {
		std::cout << "Deleting window" << std::endl;
	}

	void Window::makeContextCurrent(){
		glfwMakeContextCurrent(this->m_window);
	}
	int Window::getFramebufferPixelRatio() const{
		int fbWidth, fbHeight;
		glfwGetFramebufferSize(getWindowID(), &fbWidth, &fbHeight);
		return (float)fbWidth / (float)fbHeight;
	}

	Window::Window(int width, int height, std::string title, GLFWwindow* window):infos(width, height, title, 0, 0){
		if(!initialized)
			fatalError("Window:: Window was not initialized!");
		if(window != nullptr){
			std::cout<< "Sharing context with: ["<< window << "]"<<std::endl;
		}

		m_window = glfwCreateWindow(width, height, title.c_str(), nullptr	, window);

		if (!m_window)
		{
			closeWindow();
			fatalError("Window:: Could not create window!");
		}

		makeContextCurrent();

		if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress))
		{
    	fatalError("Window:: Failed to initialize GLAD");
		}



		const GLFWvidmode* vidmode = glfwGetVideoMode(glfwGetPrimaryMonitor());
		glfwSetWindowPos(m_window, (int)(0.5 * (vidmode->width - width)), int((0.5*(vidmode->height - height))));

    	infos.vWidth = vidmode->width;
		infos.vHeight = vidmode->height;
		glfwSetFramebufferSizeCallback(m_window, framebuffer_size_callback);
		glfwSetInputMode(m_window, GLFW_CURSOR, GLFW_CURSOR_NORMAL);
		glfwSetKeyCallback(m_window, key_callback);
		glfwSetCursorPosCallback(m_window, cursor_position_callback);
		glfwSetScrollCallback(m_window, scroll_callback);
		glfwSetMouseButtonCallback(m_window, mouse_button_callback);
		glfwSetCursorEnterCallback(m_window, cursor_enter_callback);
		glfwSwapInterval( 0);
		if(window != nullptr){
				glfwMakeContextCurrent(window);
		}
	}

	void Window::changePosition(int x, int y){
			glfwSetWindowPos(m_window, x, y);
	}

	info Window::getWindowPosition(){
			return this->infos;
	}


	void Window::closeWindow() {
		glfwDestroyWindow(m_window);
		if(!terminated){
			terminated = true;
			glfwTerminate();

		}

	}
}
