#include "Renderer.h"

void Renderer::Clear() const
{
	glClearColor(0.1f, 0.1f, 0.1f, 1.0f);
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
}

void Renderer::DrawTriangle(const VertexArray& vertexArray, const Shader& shader) const
{
	shader.Use();
	vertexArray.Bind();

	glDrawArrays(GL_TRIANGLES, 0, 3);
}

void Renderer::DrawRectangle(const VertexArray& vertexArray, const ElementBuffer& elementBuffer, const Shader& shader) const
{
	shader.Use();
	vertexArray.Bind();
	elementBuffer.Bind();

	glDrawElements(GL_TRIANGLES, 6, GL_UNSIGNED_INT, 0);
}

void Renderer::DrawCube(const VertexArray& vertexArray, const Shader& shader) const
{
	shader.Use();
	vertexArray.Bind();

	glDrawArrays(GL_TRIANGLES, 0, 36);
}