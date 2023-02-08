#pragma once

#include <glad/glad.h>
#include <GLFW/glfw3.h>
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>
#include <glm/gtx/rotate_vector.hpp>
#include <glm/gtx/vector_angle.hpp>

#include "OpenGL/Shader.h"

enum CameraDirection
{
	CAMERA_FORWARD,
	CAMERA_BACK,
	CAMERA_LEFT,
	CAMERA_RIGHT,
	CAMERA_UP,
	CAMERA_DOWN
};

class Camera
{
public:
	glm::vec3 Position;
	glm::vec3 Orientation = glm::vec3(0.0f, 0.0f, -1.0f);
	glm::vec3 Up = glm::vec3(0.0f, 1.0f, 0.0f);
	float FOV = 70.0f;

private:
	int width;
	int height;

	float near = 0.1f;
	float far = 100.0f;

	float sensitivity = 150.0f;

public:
	Camera(int width, int height, glm::vec3 position);

	void Matrix(Shader& shader);
	void FreeMove(CameraDirection direction, float speed);
	void Rotate(double mouseX, double mouseY);

	void SetSize(int width, int height);
};