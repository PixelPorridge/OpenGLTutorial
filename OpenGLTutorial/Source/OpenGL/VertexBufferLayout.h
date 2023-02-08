#pragma once

#include <glad/glad.h>

#include <vector>
#include <iostream>

struct VertexBufferAttribute
{
	GLuint size;
	GLenum type;
	GLboolean normalised;
	intptr_t offset;
};

class VertexBufferLayout
{
private:
	std::vector<VertexBufferAttribute> attributes;
	GLsizei stride = 0;

public:
	// Push an attribute, given a data type
	template<typename T>
	void Push(GLuint size);

	template<>
	void Push<GLfloat>(GLuint size)
	{
		attributes.push_back({ size, GL_FLOAT, GL_FALSE, stride });
		stride += size * sizeof(GLfloat);
	}

	template<>
	void Push<GLuint>(GLuint size)
	{
		attributes.push_back({ size, GL_UNSIGNED_INT, GL_FALSE, stride });
		stride += size * sizeof(GLuint);
	}

	template<>
	void Push<GLubyte>(GLuint size)
	{
		attributes.push_back({ size, GL_UNSIGNED_BYTE, GL_TRUE, stride });
		stride += size * sizeof(GLubyte);
	}

	// Get attributes from layout
	inline const std::vector<VertexBufferAttribute>& GetAttributes() const { return attributes; }

	// Get layout stride
	inline GLsizei GetStride() const { return stride; }
};