#pragma once
#include <glad/glad.h>
#include <GLFW/glfw3.h>

#ifndef GLFW_TRUE
#define GLFW_TRUE 1
#endif

#ifndef GLFW_FALSE
#define GLFW_FALSE 0
#endif


#include <string>
#include "InputManager.h"
namespace GameEngine {

	typedef struct info {
		unsigned int vWidth;
		unsigned int vHeight;
		unsigned int width;
		unsigned int height;
		std::string title;
		info(int w, int h, std::string t, int vW, int vH) : vWidth(vW), vHeight(vH), width(w), height(h), title(t) {};
	} info;

	class Window {
	private:
		static bool terminated;
		static void mouse_button_callback(GLFWwindow* window, int button, int action, int mods);
		static void cursor_position_callback(GLFWwindow* window, double xpos, double ypos);
		static void key_callback(GLFWwindow* window, int key, int scancode, int action, int mods);
		static void scroll_callback(GLFWwindow* window, double xoffset, double yoffset);
		static void cursor_enter_callback(GLFWwindow* window, int entered);
		GLFWwindow* m_window;
		info infos;
		static bool initialized;
		static void framebuffer_size_callback(GLFWwindow* window, int width, int height);
	public:
		static GLFWwindow* currWindow;
		int getFramebufferPixelRatio() const;
		info getWindowPosition();
		void changePosition(int x, int y);
		void makeContextCurrent();
		void swapBuffers();
		void clear();
		static void init();

		bool shouldClose() const { return glfwWindowShouldClose (m_window);}
		info getInfo() const { return infos; }
		GLFWwindow* getWindowID() const { return m_window; }
		void closeWindow();
		Window(int width, int height, std::string title, GLFWwindow* window = nullptr);
		~Window();
	};


}
