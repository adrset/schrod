#pragma once
#include <GLFW/glfw3.h>
#include <unordered_map>
#include <glm/vec2.hpp>
namespace GameEngine {
	typedef struct MouseCoords{
		glm::vec2 xy;
		void* window;
		MouseCoords(glm::vec2 pos, void* win) : xy(pos), window(win) {};
	}MouseCoords;
	class InputManager
	{
	public:


		static void update();
		static bool wasMouseKeyDown(unsigned int keyID);
		static bool isMouseKeyPressed(unsigned int keyID);
		static void pressMouseKey(unsigned int keyID);
		static void releaseMouseKey(unsigned int keyID);

		static bool isMouseKeyDown(unsigned int keyID);
		static void pressKey(unsigned int keyID);
		static void releaseKey(unsigned int keyID);
		static void setMouseCoords(float x, float y, void* window);

		static bool isKeyDown(unsigned int keyID);
		static bool isKeyPressed(unsigned int keyID);

		static void addScroll(glm::vec2 scroll);
		static MouseCoords getMouseCoords() {return m_mCoords; }
	private:
		static bool wasKeyDown(unsigned int keyID);
		static std::unordered_map<unsigned int, bool> m_mouseKeyMap;
		static std::unordered_map<unsigned int, bool> m_previousMouseKeyMap;
		static std::unordered_map<unsigned int, bool> m_keyMap;
		static std::unordered_map<unsigned int, bool> m_previousKeyMap;

		static MouseCoords m_mCoords;
		static glm::vec2 m_scroll;
	};

}
