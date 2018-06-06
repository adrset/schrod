#ifndef SHADER_H
#define SHADER_H

#include <string>
#include <fstream>
#include <sstream>
#include <iostream>
#include <map>
#include <glad/glad.h>
#include <glm/matrix.hpp>
#include <glm/gtc/type_ptr.hpp>
#include "errors.h"

namespace GameEngine {
	class Shader
	{
	public:
		// the program ID
		unsigned int ID;

		// constructor reads and builds the shader
		Shader(const char* vertexPath, const char* fragmentPath);
		Shader(){ fprintf(stderr, "%s\n", "Creating empt shader!");}
		// use/activate the shader
		void use();
		// utility uniform functions
		void setBool(const std::string &name, bool value) const;
		void setInt(const std::string &name, int value) const;
		void setFloat(const std::string &name, float value) const;
		void setMat4(const std::string &name, const glm::mat4 &mat) const;
		void setVec4(const std::string &name, const glm::vec4 &value) const;
		void setVec3(const std::string &name, const glm::vec3 &value) const;
		void setVec3(const std::string &name, float x, float y, float z) const;
		void setVec2(const std::string &name, const glm::vec2 &value) const;
	private:
		int getUniformLocation(const std::string uniform) const;
		void checkCompileErrors(unsigned int shader, std::string type);
	};
}
#endif
