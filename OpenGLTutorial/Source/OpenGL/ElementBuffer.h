#pragma once

#include <glad/glad.h>

class ElementBuffer
{
private:
	GLuint ID;

public:
	ElementBuffer(const GLuint* data, const GLsizeiptr size);
	~ElementBuffer();

	void Bind() const;
	void Unbind() const;
};