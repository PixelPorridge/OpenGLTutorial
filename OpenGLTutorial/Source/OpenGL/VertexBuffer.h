#pragma once

#include <glad/glad.h>

class VertexBuffer
{
private:
	GLuint ID;

public:
	VertexBuffer(const GLfloat* data, const GLsizeiptr size);
	~VertexBuffer();

	void Bind() const;
	void Unbind() const;
};