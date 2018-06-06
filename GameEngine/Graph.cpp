#include "Graph.h"
namespace GameEngine {
Graph::Graph(int num) {
    this->num = num;
    init = false;
    m_points = new float[num];
    m_lastUpdated = 0;
    glGenVertexArrays(1, &m_vao);
    glGenBuffers(1, &m_vbo);

    glBindVertexArray(m_vao);

    glBindBuffer(GL_ARRAY_BUFFER, m_vbo);
    glBufferData(GL_ARRAY_BUFFER, num * 2 * sizeof(float), nullptr, GL_DYNAMIC_DRAW);

    glVertexAttribPointer(0, 2, GL_FLOAT, GL_FALSE, 2 * sizeof(float), (void*)0);
    glEnableVertexAttribArray(0);

    glBindBuffer(GL_ARRAY_BUFFER, 0);

    glBindVertexArray(0);

}

Graph::~Graph() {
    //delete m_points;
    glDeleteBuffers(1, &m_vbo);
    glDeleteVertexArrays(1, &m_vao);
}
 void Graph::setBoundariesY(glm::vec2 vec){
	 minY = vec.x;
	 maxY = vec.y;
	 
 }
void Graph::update(float* points) {
    minX = points[0];
    maxX = points[0];
    //minY = points[1];
    //maxY = points[1];
    for(unsigned int i=2; i<num; i=i+2) {
        if(points[i]> maxX)
            maxX = points[i];
        if(points[i]< minX)
            minX = points[i];
        /*if(points[i+1]> maxY)
            maxY = points[i+1];
        if(points[i+1]< minY)
            minY = points[i+1];*/
       
    }
    glBindBuffer(GL_ARRAY_BUFFER, m_vbo);
    glBufferSubData(GL_ARRAY_BUFFER,0, num * 2 * sizeof(float), points);
    glBindBuffer(GL_ARRAY_BUFFER, 0);
}



void Graph::draw(Shader* shader) {
    glBindVertexArray(m_vao);
    shader->use();
    shader->setVec2("min", glm::vec2(minX, minY));
    shader->setVec2("max", glm::vec2(maxX, maxY));
    glDrawArrays(GL_LINE_STRIP, 0, num/2);
    glBindVertexArray(0);

}
}
