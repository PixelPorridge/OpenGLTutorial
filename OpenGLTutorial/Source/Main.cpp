#include "Main.h"

int main()
{
    // Initialise
    CreateWindow(windowWidth, windowHeight, "Halcyon");
    InitOpenGL();
    InitSTBImage();

    // Cube vertex data
    float vertices[] = {
        // positions          // normals           // texture coords
        // Front
        -0.5f, -0.5f,  0.5f,  0.0f,  0.0f, 1.0f,   0.0f, 0.0f,
         0.5f, -0.5f,  0.5f,  0.0f,  0.0f, 1.0f,   1.0f, 0.0f,
         0.5f,  0.5f,  0.5f,  0.0f,  0.0f, 1.0f,   1.0f, 1.0f,
         0.5f,  0.5f,  0.5f,  0.0f,  0.0f, 1.0f,   1.0f, 1.0f,
        -0.5f,  0.5f,  0.5f,  0.0f,  0.0f, 1.0f,   0.0f, 1.0f,
        -0.5f, -0.5f,  0.5f,  0.0f,  0.0f, 1.0f,   0.0f, 0.0f,
        
        // Back
        -0.5f, -0.5f, -0.5f,  0.0f,  0.0f, -1.0f,  1.0f, 0.0f,
         0.5f, -0.5f, -0.5f,  0.0f,  0.0f, -1.0f,  0.0f, 0.0f,
         0.5f,  0.5f, -0.5f,  0.0f,  0.0f, -1.0f,  0.0f, 1.0f,
         0.5f,  0.5f, -0.5f,  0.0f,  0.0f, -1.0f,  0.0f, 1.0f,
        -0.5f,  0.5f, -0.5f,  0.0f,  0.0f, -1.0f,  1.0f, 1.0f,
        -0.5f, -0.5f, -0.5f,  0.0f,  0.0f, -1.0f,  1.0f, 0.0f,

        // Left
        -0.5f,  0.5f,  0.5f, -1.0f,  0.0f,  0.0f,  1.0f, 1.0f,
        -0.5f,  0.5f, -0.5f, -1.0f,  0.0f,  0.0f,  0.0f, 1.0f,
        -0.5f, -0.5f, -0.5f, -1.0f,  0.0f,  0.0f,  0.0f, 0.0f,
        -0.5f, -0.5f, -0.5f, -1.0f,  0.0f,  0.0f,  0.0f, 0.0f,
        -0.5f, -0.5f,  0.5f, -1.0f,  0.0f,  0.0f,  1.0f, 0.0f,
        -0.5f,  0.5f,  0.5f, -1.0f,  0.0f,  0.0f,  1.0f, 1.0f,

        // Right
         0.5f,  0.5f,  0.5f,  1.0f,  0.0f,  0.0f,  0.0f, 1.0f,
         0.5f,  0.5f, -0.5f,  1.0f,  0.0f,  0.0f,  1.0f, 1.0f,
         0.5f, -0.5f, -0.5f,  1.0f,  0.0f,  0.0f,  1.0f, 0.0f,
         0.5f, -0.5f, -0.5f,  1.0f,  0.0f,  0.0f,  1.0f, 0.0f,
         0.5f, -0.5f,  0.5f,  1.0f,  0.0f,  0.0f,  0.0f, 0.0f,
         0.5f,  0.5f,  0.5f,  1.0f,  0.0f,  0.0f,  0.0f, 1.0f,

        // Top
        -0.5f,  0.5f, -0.5f,  0.0f,  1.0f,  0.0f,  0.0f, 1.0f,
         0.5f,  0.5f, -0.5f,  0.0f,  1.0f,  0.0f,  1.0f, 1.0f,
         0.5f,  0.5f,  0.5f,  0.0f,  1.0f,  0.0f,  1.0f, 0.0f,
         0.5f,  0.5f,  0.5f,  0.0f,  1.0f,  0.0f,  1.0f, 0.0f,
        -0.5f,  0.5f,  0.5f,  0.0f,  1.0f,  0.0f,  0.0f, 0.0f,
        -0.5f,  0.5f, -0.5f,  0.0f,  1.0f,  0.0f,  0.0f, 1.0f,
        
         // Bottom
        -0.5f, -0.5f, -0.5f,  0.0f, -1.0f,  0.0f,  0.0f, 0.0f,
         0.5f, -0.5f, -0.5f,  0.0f, -1.0f,  0.0f,  1.0f, 0.0f,
         0.5f, -0.5f,  0.5f,  0.0f, -1.0f,  0.0f,  1.0f, 1.0f,
         0.5f, -0.5f,  0.5f,  0.0f, -1.0f,  0.0f,  1.0f, 1.0f,
        -0.5f, -0.5f,  0.5f,  0.0f, -1.0f,  0.0f,  0.0f, 1.0f,
        -0.5f, -0.5f, -0.5f,  0.0f, -1.0f,  0.0f,  0.0f, 0.0f
    };

    // Cube positions
    glm::vec3 cubePositions[] = {
        glm::vec3(0.0f,  0.0f,  0.0f),
        glm::vec3(2.0f,  5.0f, -15.0f),
        glm::vec3(-1.5f, -2.2f, -2.5f),
        glm::vec3(-3.8f, -2.0f, -12.3f),
        glm::vec3(2.4f, -0.4f, -3.5f),
        glm::vec3(-1.7f,  3.0f, -7.5f),
        glm::vec3(1.3f, -2.0f, -2.5f),
        glm::vec3(1.5f,  2.0f, -2.5f),
        glm::vec3(1.5f,  0.2f, -1.5f),
        glm::vec3(-1.3f,  1.0f, -1.5f)
    };

    // Point light positions
    glm::vec3 pointLightPositions[] = {
        glm::vec3(0.7f,  0.2f,  2.0f),
        glm::vec3(2.3f, -3.3f, -4.0f),
        glm::vec3(-4.0f,  2.0f, -12.0f),
        glm::vec3(0.0f,  0.0f, -3.0f)
    };

    // Data
    VertexBuffer VBO(vertices, sizeof(vertices));

    VertexBufferLayout layout;
    layout.Push<GLfloat>(3); // position
    layout.Push<GLfloat>(3); // normal
    layout.Push<GLfloat>(2); // texture coords

    // Light cube
    VertexArray lightCubeVAO;
    lightCubeVAO.AddBuffer(VBO, layout);

    Shader lightCubeShader("Assets/Shaders/LightCube.shader");

    // Cube
    VertexArray cubeVAO;
    cubeVAO.AddBuffer(VBO, layout);

    Shader cubeShader("Assets/Shaders/Cube.shader");

    Texture container("Assets/Images/Bricks.png", 0);
    Texture specularMap("Assets/Images/BricksSpecular.png", 1);
    
    // Renderer
    Renderer renderer;

    // Variables to calculate FPS
    double prevTime = 0.0;
    double crntTime = 0.0;
    double timeDiff;
    unsigned int counter = 0;

    // Disable vsync
    glfwSwapInterval(0);
    
    // Update window while it hasn't been instructed to close
    while (!glfwWindowShouldClose(window))
    {
        // Calculate FPS / Update title
        crntTime = glfwGetTime();
        timeDiff = crntTime - prevTime;
        counter++;
        if (timeDiff >= 1.0 / 30.0)
        {
            std::string fps = std::to_string((int)((1.0 / timeDiff) * counter));
            std::string newTitle = "Halcyon    " + fps + " FPS    FOV: " + std::to_string((int)camera.FOV);
            glfwSetWindowTitle(window, newTitle.c_str());
            prevTime = crntTime;
            counter = 0;
        }

        // Process input
        ProcessInput(window);

        // Clear screen
        renderer.Clear();

        // Cube shader setup
        cubeShader.Use();

        cubeShader.SetVec3("viewPos", camera.Position);

        cubeShader.SetInt("material.diffuse", 0);
        cubeShader.SetInt("material.specular", 1);
        cubeShader.SetFloat("material.shininess", 32.0f);

        // Directional light
        cubeShader.SetVec3("dirLight.direction", glm::vec3(-0.2f, -1.0f, -0.3f));
        cubeShader.SetVec3("dirLight.ambient", glm::vec3(0.05f));
        cubeShader.SetVec3("dirLight.diffuse", glm::vec3(0.4f));
        cubeShader.SetVec3("dirLight.specular", glm::vec3(0.5f));

        // Point light 1
        cubeShader.SetVec3("pointLights[0].position", pointLightPositions[0]);
        cubeShader.SetVec3("pointLights[0].ambient", glm::vec3(0.05f));
        cubeShader.SetVec3("pointLights[0].diffuse", glm::vec3(0.8f));
        cubeShader.SetVec3("pointLights[0].specular", glm::vec3(1.0f));
        cubeShader.SetFloat("pointLights[0].constant", 1.0f);
        cubeShader.SetFloat("pointLights[0].linear", 0.09f);
        cubeShader.SetFloat("pointLights[0].quadratic", 0.032f);

        // Point light 2
        cubeShader.SetVec3("pointLights[1].position", pointLightPositions[1]);
        cubeShader.SetVec3("pointLights[1].ambient", glm::vec3(0.05f));
        cubeShader.SetVec3("pointLights[1].diffuse", glm::vec3(0.8f));
        cubeShader.SetVec3("pointLights[1].specular", glm::vec3(1.0f));
        cubeShader.SetFloat("pointLights[1].constant", 1.0f);
        cubeShader.SetFloat("pointLights[1].linear", 0.09f);
        cubeShader.SetFloat("pointLights[1].quadratic", 0.032f);

        // Point light 3
        cubeShader.SetVec3("pointLights[2].position", pointLightPositions[2]);
        cubeShader.SetVec3("pointLights[2].ambient", glm::vec3(0.05f));
        cubeShader.SetVec3("pointLights[2].diffuse", glm::vec3(0.8f));
        cubeShader.SetVec3("pointLights[2].specular", glm::vec3(1.0f));
        cubeShader.SetFloat("pointLights[2].constant", 1.0f);
        cubeShader.SetFloat("pointLights[2].linear", 0.09f);
        cubeShader.SetFloat("pointLights[2].quadratic", 0.032f);

        // Point light 4
        cubeShader.SetVec3("pointLights[3].position", pointLightPositions[3]);
        cubeShader.SetVec3("pointLights[3].ambient", glm::vec3(0.05f));
        cubeShader.SetVec3("pointLights[3].diffuse", glm::vec3(0.8f));
        cubeShader.SetVec3("pointLights[3].specular", glm::vec3(1.0f));
        cubeShader.SetFloat("pointLights[3].constant", 1.0f);
        cubeShader.SetFloat("pointLights[3].linear", 0.09f);
        cubeShader.SetFloat("pointLights[3].quadratic", 0.032f);

        // Spot light
        cubeShader.SetVec3("spotLight.position", camera.Position);
        cubeShader.SetVec3("spotLight.direction", camera.Orientation);
        cubeShader.SetVec3("spotLight.ambient", glm::vec3(0.0f));
        cubeShader.SetVec3("spotLight.diffuse", glm::vec3(1.0f));
        cubeShader.SetVec3("spotLight.specular", glm::vec3(1.0f));
        cubeShader.SetFloat("spotLight.constant", 1.0f);
        cubeShader.SetFloat("spotLight.linear", 0.09f);
        cubeShader.SetFloat("spotLight.quadratic", 0.032f);
        cubeShader.SetFloat("spotLight.cutOff", glm::cos(glm::radians(12.5f)));
        cubeShader.SetFloat("spotLight.outerCutOff", glm::cos(glm::radians(15.0f)));

        camera.Matrix(cubeShader);

        // Draw cubes
        for (unsigned int i = 0; i < 10; i++)
        {
            glm::mat4 model = glm::mat4(1.0f);
            model = glm::translate(model, cubePositions[i]);
            float angle = 20.0f * i;
            model = glm::rotate(model, glm::radians(angle), glm::vec3(1.0f, 0.3f, 0.5f));
            cubeShader.SetMat4("model", model);

            renderer.DrawCube(cubeVAO, cubeShader);
        }

        // Light cube shader setup
        lightCubeShader.Use();

        camera.Matrix(lightCubeShader);

        // Draw light cubes
        for (unsigned int i = 0; i < 4; i++)
        {
            glm::mat4 model = glm::mat4(1.0f);
            model = glm::translate(model, pointLightPositions[i]);
            model = glm::scale(model, glm::vec3(0.2f));
            lightCubeShader.SetMat4("model", model);
            
            renderer.DrawCube(lightCubeVAO, lightCubeShader);
        }

        // Swap buffers
        glfwSwapBuffers(window);

        // Poll for events
        glfwPollEvents();
    }
    
    // Terminate GLFW
    glfwTerminate();
    return 0;
}

// Create a window with GLFW
void CreateWindow(int width, int height, const char* title)
{
    // Initialise GLFW and configure
    glfwInit();
#ifdef DEBUG
    glfwWindowHint(GLFW_OPENGL_DEBUG_CONTEXT, true);
#endif
    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 4);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

    // Get primary monitor
    monitor = glfwGetPrimaryMonitor();
    
    // Create a window
    window = glfwCreateWindow(width, height, title, NULL, NULL);
    if (window == NULL)
    {
        std::cout << "Failed to create GLFW window" << std::endl;
        glfwTerminate();
    }
    glfwMakeContextCurrent(window);

    // GLFW callback functions
    glfwSetFramebufferSizeCallback(window, FramebufferSizeCallback);
    glfwSetKeyCallback(window, KeyCallback);
    glfwSetScrollCallback(window, ScrollCallback);
}

// Initialise OpenGL
void InitOpenGL()
{
    // Check if GLAD is successfully initialised
    if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress))
    {
        std::cout << "Failed to initialise GLAD" << std::endl;
    }

#ifdef DEBUG
    // OpenGL debugging
    GLint context_flags = 0;
    glGetIntegerv(GL_CONTEXT_FLAGS, &context_flags);

    if (context_flags && GL_CONTEXT_FLAG_DEBUG_BIT)
    {
        std::cout << "OpenGL Debug Mode Activated\n" << std::endl;
        glEnable(GL_DEBUG_OUTPUT_SYNCHRONOUS);
        glDebugMessageCallback(GLDebugMessageCallback, NULL);
    }
#endif

    // Blend alpha images
    glEnable(GL_BLEND);
    glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);

    // Enable depth testing
    glEnable(GL_DEPTH_TEST);
}

// Initialise STB Image
void InitSTBImage()
{
    // Flip images on load
    stbi_set_flip_vertically_on_load(true);
}

// Resize window
void FramebufferSizeCallback(GLFWwindow* window, int width, int height)
{
    // Update window width and height
    windowWidth = width;
    windowHeight = height;

    // Update camera size
    camera.SetSize(width, height);

    // Resize the OpenGL viewport when the user resizes the window
    glViewport(0, 0, width, height);
}

// Check for keyboard input
void KeyCallback(GLFWwindow* window, int key, int scancode, int action, int mods)
{
    // Escape: Close the window
    if (key == GLFW_KEY_ESCAPE && action == GLFW_PRESS)
        glfwSetWindowShouldClose(window, true);

    // F: Toggle fullscreen
    if (key == GLFW_KEY_F && action == GLFW_PRESS)
    {
        if (!fullscreen)
        {
            glfwGetWindowSize(window, &tempWidth, &tempHeight);
            glfwGetWindowPos(window, &tempPosX, &tempPosY);
            const GLFWvidmode* mode = glfwGetVideoMode(monitor);
            glfwSetWindowMonitor(window, monitor, 0, 0, mode->width, mode->height, mode->refreshRate);
        }
        else
        {
            glfwSetWindowMonitor(window, NULL, tempPosX, tempPosY, tempWidth, tempHeight, 0);
        }
        fullscreen = !fullscreen;
    }

    // Q: Toggle polygon mode
    if (key == GLFW_KEY_Q && action == GLFW_PRESS)
    {
        GLint polyMode;
        glGetIntegerv(GL_POLYGON_MODE, &polyMode);

        switch (polyMode)
        {
        case GL_FILL:
            glPolygonMode(GL_FRONT_AND_BACK, GL_LINE);
            break;
        case GL_LINE:
            glPolygonMode(GL_FRONT_AND_BACK, GL_POINT);
            break;
        case GL_POINT:
            glPolygonMode(GL_FRONT_AND_BACK, GL_FILL);
            break;
        }
    }
}

// Check for scroll input
void ScrollCallback(GLFWwindow* window, double xoffset, double yoffset)
{
    // Change camera fov
    camera.FOV -= (float)yoffset;
}

// Process input
void ProcessInput(GLFWwindow* window)
{
    // Delta time
    float currentFrame = glfwGetTime();
    delta = currentFrame - lastFrame;
    lastFrame = currentFrame;

    // Adjust camera speed
    float speed = (glfwGetKey(window, GLFW_KEY_LEFT_SHIFT) == GLFW_PRESS) ? 5.0f : 2.5f;
    float cameraSpeed = speed * delta;

    // W: Move forward
    if (glfwGetKey(window, GLFW_KEY_W) == GLFW_PRESS)
        camera.FreeMove(CAMERA_FORWARD, cameraSpeed);

    // S: Move back
    if (glfwGetKey(window, GLFW_KEY_S) == GLFW_PRESS)
        camera.FreeMove(CAMERA_BACK, cameraSpeed);

    // A: Move left
    if (glfwGetKey(window, GLFW_KEY_A) == GLFW_PRESS)
        camera.FreeMove(CAMERA_LEFT, cameraSpeed);

    // D: Move right
    if (glfwGetKey(window, GLFW_KEY_D) == GLFW_PRESS)
        camera.FreeMove(CAMERA_RIGHT, cameraSpeed);

    // Space: Move up
    if (glfwGetKey(window, GLFW_KEY_SPACE) == GLFW_PRESS)
        camera.FreeMove(CAMERA_UP, cameraSpeed);

    // Left Control: Move down
    if (glfwGetKey(window, GLFW_KEY_LEFT_CONTROL) == GLFW_PRESS)
        camera.FreeMove(CAMERA_DOWN, cameraSpeed);

    // Left Mouse Button: Look around
    if (glfwGetMouseButton(window, GLFW_MOUSE_BUTTON_RIGHT) == GLFW_PRESS)
    {
        glfwSetInputMode(window, GLFW_CURSOR, GLFW_CURSOR_HIDDEN);

        if (firstClick)
        {
            glfwSetCursorPos(window, windowWidth / 2.0, windowHeight / 2.0);
            firstClick = false;
        }

        double mouseX;
        double mouseY;
        glfwGetCursorPos(window, &mouseX, &mouseY);

        camera.Rotate(mouseX, mouseY);

        glfwSetCursorPos(window, windowWidth / 2.0, windowHeight / 2.0);
    }
    else if (glfwGetMouseButton(window, GLFW_MOUSE_BUTTON_RIGHT) == GLFW_RELEASE)
    {
        glfwSetInputMode(window, GLFW_CURSOR, GLFW_CURSOR_NORMAL);
        firstClick = true;
    }
}

#ifdef DEBUG
void APIENTRY GLDebugMessageCallback(GLenum source,
    GLenum type,
    GLuint id,
    GLenum severity,
    GLsizei length,
    const GLchar* message,
    const void* userParam)
{
    // Error blacklist
    switch (id)
    {
    case 131185: return; break;
    }

    std::cout << "[OpenGL] ";

    switch (severity)
    {
    case GL_DEBUG_SEVERITY_LOW:
        std::cout << "LOW ";
        break;
    case GL_DEBUG_SEVERITY_MEDIUM:
        std::cout << "MEDIUM ";
        break;
    case GL_DEBUG_SEVERITY_HIGH:
        std::cout << "HIGH ";
        break;
    }

    switch (type)
    {
    case GL_DEBUG_TYPE_ERROR:
        std::cout << "ERROR";
        break;
    case GL_DEBUG_TYPE_DEPRECATED_BEHAVIOR:
        std::cout << "DEPRECATED_BEHAVIOR";
        break;
    case GL_DEBUG_TYPE_UNDEFINED_BEHAVIOR:
        std::cout << "UNDEFINED_BEHAVIOR";
        break;
    case GL_DEBUG_TYPE_PORTABILITY:
        std::cout << "PORTABILITY";
        break;
    case GL_DEBUG_TYPE_PERFORMANCE:
        std::cout << "PERFORMANCE";
        break;
    case GL_DEBUG_TYPE_OTHER:
        std::cout << "OTHER";
        break;
    }

    std::cout << " ";

    std::cout << id << ": " << message << std::endl;
}
#endif