#pragma once

#include <glad/glad.h>
#include <GLFW/glfw3.h>
#include <stb/stb_image.h>
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>

#include "OpenGL/Renderer.h"
#include "Camera.h"
#include "OpenGL/Shader.h"
#include "OpenGL/VertexArray.h"
#include "OpenGL/VertexBuffer.h"
#include "OpenGL/ElementBuffer.h"
#include "OpenGL/Texture.h"

#include <iostream>

// Monitor
GLFWmonitor* monitor;

// Window
GLFWwindow* window;
int windowWidth = 1200;
int windowHeight = 900;

bool fullscreen = false;
int tempWidth, tempHeight, tempPosX, tempPosY;

// Delta Time
float delta = 0.0f;
float lastFrame = 0.0f;

// Camera
Camera camera(windowWidth, windowHeight, glm::vec3(0.0f, 0.0f, 5.0f));
bool firstClick = true;

// Functions
void CreateWindow(int width, int height, const char* title);
void InitOpenGL();
void InitSTBImage();
void ProcessInput(GLFWwindow* window);

// GLFW Callbacks
void FramebufferSizeCallback(GLFWwindow* window, int width, int height);
void KeyCallback(GLFWwindow* window, int key, int scancode, int action, int mods);
void ScrollCallback(GLFWwindow* window, double xoffset, double yoffset);

#define DEBUG
#ifdef DEBUG
// OpenGL Debug
void APIENTRY GLDebugMessageCallback(GLenum source,
    GLenum type,
    GLuint id,
    GLenum severity,
    GLsizei length,
    const GLchar* message,
    const void* userParam);
#endif