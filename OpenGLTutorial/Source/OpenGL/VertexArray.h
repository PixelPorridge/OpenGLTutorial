#pragma once

#include <glad/glad.h>

#include "VertexBuffer.h"
#include "VertexBufferLayout.h"

class VertexArray
{
private:
	GLuint ID;

public:
	VertexArray();
	~VertexArray();

	void AddBuffer(const VertexBuffer& vertexBuffer, const VertexBufferLayout& layout);

	void Bind() const;
	void Unbind() const;
};