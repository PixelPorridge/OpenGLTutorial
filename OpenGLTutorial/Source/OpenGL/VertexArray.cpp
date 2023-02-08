#include "VertexArray.h"

VertexArray::VertexArray()
{
	glGenVertexArrays(1, &ID);
	glBindVertexArray(ID);
}

VertexArray::~VertexArray()
{
	glDeleteVertexArrays(1, &ID);
}

void VertexArray::AddBuffer(const VertexBuffer& vertexBuffer, const VertexBufferLayout& layout)
{
	// Bind Vertex array and vertex buffer
	Bind();
	vertexBuffer.Bind();

	// Get vertex attributes from layout
	const std::vector<VertexBufferAttribute>& attributes = layout.GetAttributes();

	// Add each attribute to vertex array
	for (GLuint i = 0; i < attributes.size(); i++)
	{
		const VertexBufferAttribute& attribute = attributes[i];
		glVertexAttribPointer(i, attribute.size, attribute.type, attribute.normalised, layout.GetStride(), (const void*)attribute.offset);
		glEnableVertexAttribArray(i);
	}
}

void VertexArray::Bind() const
{
	glBindVertexArray(ID);
}

void VertexArray::Unbind() const
{
	glBindVertexArray(0);
}