#include "InputManager.h"

namespace GameEngine {

	MouseCoords InputManager::m_mCoords(glm::vec2(), nullptr);
	glm::vec2 InputManager::m_scroll;
	std::unordered_map<unsigned int, bool> InputManager::m_mouseKeyMap;
	std::unordered_map<unsigned int, bool> InputManager::m_previousMouseKeyMap;
	std::unordered_map<unsigned int, bool> InputManager::m_keyMap;
	std::unordered_map<unsigned int, bool> InputManager::m_previousKeyMap;

	void InputManager::update() {


		for (auto& it : m_keyMap) {
			m_previousKeyMap[it.first] = it.second;
		}
		for (auto& it : m_mouseKeyMap) {
			m_previousMouseKeyMap[it.first] = it.second;
		}
	}

	void InputManager::pressKey(unsigned int keyID) {
		m_keyMap[keyID] = true; // same as _keyMap.insert();
	}
	void InputManager::releaseKey(unsigned int keyID) {
		m_keyMap[keyID] = false;
	}

	void InputManager::setMouseCoords(float x, float y, void* window) {
		m_mCoords.xy.x = x;
		m_mCoords.xy.y = y;
		m_mCoords.window = window;
	}

	bool InputManager::isKeyDown(unsigned int keyID) {
		auto it = m_keyMap.find(keyID);
		if (it != m_keyMap.end()) {
			return it->second;//ret val (it's bool)
		}
		else {
			return false;
		}
	}

	bool InputManager::isKeyPressed(unsigned int keyID)
	{
		if (isKeyDown(keyID) == true && wasKeyDown(keyID) == false) {
			return true;
		}
		return false;
	}


	bool InputManager::wasKeyDown(unsigned int keyID)
	{
		auto it = m_previousKeyMap.find(keyID);
		if (it != m_previousKeyMap.end()) {
			return it->second; //ret val (it's bool)
		}
		else {
			return false;
		}
	}


	void InputManager::pressMouseKey(unsigned int keyID) {
		m_mouseKeyMap[keyID] = true;
	}

	void InputManager::releaseMouseKey(unsigned int keyID) {
		m_mouseKeyMap[keyID] = false;
	}

	bool InputManager::isMouseKeyDown(unsigned int keyID) {
		auto it = m_mouseKeyMap.find(keyID);
		if (it != m_mouseKeyMap.end()) {
			return it->second;//ret val (it's bool)
		}
		else {
			return false;
		}
	}

	void InputManager::addScroll(glm::vec2 scroll) {
		m_scroll += scroll;
	}

	bool InputManager::isMouseKeyPressed(unsigned int keyID)
	{
		if (isMouseKeyDown(keyID) == true && wasMouseKeyDown(keyID) == false) {
			return true;
		}
		return false;
	}

	bool InputManager::wasMouseKeyDown(unsigned int keyID)
	{
		auto it = m_previousMouseKeyMap.find(keyID);
		if (it != m_previousMouseKeyMap.end()) {
			return it->second; //ret val (it's bool)
		}
		else {
			return false;
		}
	}

}
