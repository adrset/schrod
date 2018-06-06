#ifndef GRAPH_H
#define GRAPH_H
#include <vector>
#include "Renderable.h"

namespace GameEngine{

  class Graph : public Renderable{
  public:
    Graph(int num);
    ~Graph();
    int num=0;
    void draw(Shader* shader);
    void addPoint(float x, float y);
    void update(float*);
    void setBoundariesY(glm::vec2);
  private:
    bool init;
    unsigned int iter = 0;
    float maxX, minX;
    float maxY, minY;
    unsigned int m_vao, m_vbo;
    float* m_points;
    unsigned int m_lastUpdated;

  };

}

#endif
