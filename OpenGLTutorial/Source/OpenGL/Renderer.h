#pragma once

#include "VertexArray.h"
#include "ElementBuffer.h"
#include "Shader.h"

class Renderer
{
public:
	void Clear() const;
	void DrawTriangle(const VertexArray& vertexArray, const Shader& shader) const;
	void DrawRectangle(const VertexArray& vertexArray, const ElementBuffer& elementBuffer, const Shader& shader) const;
	void DrawCube(const VertexArray& vertexArray, const Shader& shader) const;
};