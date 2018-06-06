#include "Game.h"

#include <vector>
#include <cstdlib>
#include <fstream>

#include <iostream>
#include <unistd.h>

Game::Game(int width, int height, std::string title,int fps):  m_width(width), m_height(height), m_title(title)
{
    GameEngine::Window::init();

    m_graphWindow = new GameEngine::Window(m_width, m_height, "Graph");

    m_graph = new GameEngine::Graph(NN*2);
    m_graph2 = new GameEngine::Graph(NN*2);
    m_graph3 = new GameEngine::Graph(NN*2);

    m_timer = new GameEngine::Timer(fps);

    m_graphShader = new GameEngine::Shader("graph.vs", "graph.fs");
    m_graphShader2 = new GameEngine::Shader("graph2.vs", "graph2.fs");
    m_graphShader3 = new GameEngine::Shader("graph3.vs", "graph3.fs");

    ra= (0.5 * h / mass) * (dt / pow(del_x, 2));
    all = new float[NN*2];
    V = new float[NN];
    pos = new float[NN];
    real = new float[NN];
    imag = new float[NN];
    sum = new float[NN];
    pTotal = 0;
    real[0] = 0;
    imag[0] = 0;
    pos[0] = 0;
    for (int i = 0; i < NN; i++) {
		V[i] = 0;
		
	}
	
	for (int i = 300; i < 320; i++) {
		V[i] = 1.6e-19;
		
	}
    // Gaussian
    sum[0] = pow(real[0],2) + pow(imag[0],2);
    for (int i = 1; i < NN; i++) {
        real[i] = exp(-1.0 * pow(((i - nc) / (sqrt(2)*sigma)), 2)) * cos(K* (i - nc) ) ;
        imag[i] = exp(-1.0 * pow(((i - nc) / (sqrt(2)*sigma)), 2)) * sin(K*(i - nc) );
        sum[i] = pow(real[i],2) + pow(imag[i],2);
        pos[i] = dx * i;
        pTotal = pTotal + sum[i];
    }
     double norm = sqrt(pTotal);
    

   
    // not normalis(z)ing
   // pTotal = 0;



}

void Game::start() {
    loop();
}

void Game::loop() {
    m_graph->setBoundariesY(glm::vec2(-1,1));
    m_graph2->setBoundariesY(glm::vec2(-1,1));
    m_graph3->setBoundariesY(glm::vec2(-1,1));
    while (!m_graphWindow->shouldClose())
    {

        // First window drawing
        m_timer->start();
        m_graphWindow->clear();
        processInput();

        for (int i = 1; i < NN - 1; i++) {
            // LAPLACIAN
            real[i] = real[i] - ra * (imag[i - 1] - 2 * imag[i] + imag[i + 1]) + (dt/h) * V[i] * imag[i];
            imag[i] = imag[i] + ra * (real[i - 1] - 2 * real[i] + real[i + 1]) - (dt/h) * V[i] * real[i];
            sum[i] = pow(real[i],2)  + pow(imag[i],2);
        }
       for (int i = 0; i < NN *2; i+=2) {
            all[i] = pos[i/2];
            all[i+1] = imag[i/2];
        }

        m_graph->update(all);


        m_graph->draw(m_graphShader);
        for (int i = 0; i < NN *2; i+=2) {
            all[i] = pos[i/2];
            all[i+1] = real[i/2];
        }
        m_graph2->update(all);


        m_graph2->draw(m_graphShader2);

        for (int i = 0; i < NN *2; i+=2) {
            all[i] = pos[i/2];
            all[i+1] = sum[i/2];
        }
        m_graph3->update(all);


        m_graph3->draw(m_graphShader3);
        m_graphWindow->swapBuffers();
        glfwPollEvents();

        waitAndShoutFPS();


    }

    cleanUp();

}

void Game::waitAndShoutFPS() {
    m_fps = 1.0/m_timer->end();
	std::cout<<m_fps<<std::endl;
    m_timer->wait();

}

void Game::gameLogic() {

}

void Game::processInput()
{
    if(GameEngine::InputManager::isKeyPressed(GLFW_KEY_ESCAPE))
        glfwSetWindowShouldClose(m_graphWindow->getWindowID(), true);
}


void Game::cleanUp() {
    m_graphWindow->closeWindow();
}


Game::~Game()
{
    delete m_graphShader;
    delete m_graphShader2;
    delete m_graphShader3;
    delete m_graphWindow;
    delete m_timer;
    delete m_graph;
    delete m_graph2;
    delete m_graph3;

    delete[] all;
    delete[] V;
    delete[] pos;
    delete[] real;
    delete[] imag;
    delete[] sum;
    std::cout << "Closing game." << std::endl;
}
