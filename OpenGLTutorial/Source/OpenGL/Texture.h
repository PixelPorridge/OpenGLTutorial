#pragma once

#include <glad/glad.h>
#include <stb/stb_image.h>

#include <iostream>

class Texture
{
private:
	GLuint ID;

public:
	Texture(const char* filePath, const GLuint unit);
	~Texture();

	void Bind(const GLuint unit) const;
	void Unbind() const;
};