#pragma once

#include <glad/glad.h>
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>

#include <string>
#include <fstream>
#include <sstream>
#include <iostream>

class Shader
{
private:
	GLuint ID;
	
public:
	Shader(const char* filePath);
	~Shader();

	void Use() const;

	void SetBool(const char* name, GLboolean value) const;
	void SetInt(const char* name, GLint value) const;
	void SetFloat(const char* name, GLfloat value) const;
	void SetVec2(const char* name, glm::vec2 vector) const;
	void SetVec3(const char* name, glm::vec3 vector) const;
	void SetVec4(const char* name, glm::vec4 vector) const;
	void SetMat2(const char* name, glm::mat2 matrix) const;
	void SetMat3(const char* name, glm::mat3 matrix) const;
	void SetMat4(const char* name, glm::mat4 matrix) const;

private:
	void CheckCompileErrors(GLuint shader, std::string type);
};