#pragma once
#include <iostream>
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>
#include <GameEngine/Window.h>
#include <GameEngine/Shader.h>
#include <GameEngine/Timer.h>
#include <GameEngine/Graph.h>

class Game
{
public:
	Game(int width, int height, std::string title, int fps);
	~Game();
	void cleanUp();
	void start();
	void gameLogic();
	void waitAndShoutFPS();
private:
	float* real;
	float* all;
	float* pos;
	float* V;
	float* imag;
	float* sum;
	GameEngine::Shader* m_graphShader;
	GameEngine::Shader* m_graphShader2;
	GameEngine::Shader* m_graphShader3;
	GameEngine::Graph* m_graph;
	GameEngine::Graph* m_graph2;
	GameEngine::Graph* m_graph3;
	int m_fps = 60;
	void processInput();
	int m_width;
	int m_height;
	std::string m_title;
	GameEngine::Window* m_graphWindow;
	GameEngine::Timer* m_timer;
	void loop();
	
	int NN = 400;
	double h = 1.054e-34;
	double mass = 9.1e-31;
	double del_x = .1e-9;
	double dt = 1e-18;
	double ra;
	double dx = del_x * 1e9;
	double sigma = 10;
	double nc =140; // Starting position
	double pTotal = 0;
	double pi = 3.14159265359;
	double K = 1;

};
