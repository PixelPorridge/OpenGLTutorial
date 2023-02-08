#include "Camera.h"

Camera::Camera(int width, int height, glm::vec3 position)
{
	this->width = width;
	this->height = height;
	this->Position = position;
}

void Camera::Matrix(Shader& shader)
{
	glm::mat4 view = glm::lookAt(Position, Position + Orientation, Up);
	glm::mat4 projection = glm::perspective(glm::radians(FOV), (float)width / (float)height, near, far);

	shader.SetMat4("view", view);
	shader.SetMat4("projection", projection);
}

void Camera::FreeMove(CameraDirection direction, float speed)
{
	switch (direction)
	{
	case CAMERA_FORWARD: Position += speed * Orientation; break;
	case CAMERA_BACK: Position -= speed * Orientation; break;
	case CAMERA_LEFT: Position -= glm::normalize(glm::cross(Orientation, Up)) * speed; break;
	case CAMERA_RIGHT: Position += glm::normalize(glm::cross(Orientation, Up)) * speed; break;
	case CAMERA_UP: Position += speed * Up; break;
	case CAMERA_DOWN: Position -= speed * Up; break;
	}
}

void Camera::Rotate(double mouseX, double mouseY)
{
	float rotX = sensitivity * (float)(mouseY - (height / 2)) / height;
	float rotY = sensitivity * (float)(mouseX - (width / 2)) / width;

	glm::vec3 newOrientation = glm::rotate(Orientation, glm::radians(-rotX), glm::normalize(glm::cross(Orientation, Up)));

	if (abs(glm::angle(newOrientation, Up) - glm::radians(90.0f)) <= glm::radians(85.0f))
	{
		Orientation = newOrientation;
	}

	Orientation = glm::rotate(Orientation, glm::radians(-rotY), Up);
}

void Camera::SetSize(int width, int height)
{
	this->width = width;
	this->height = height;
}