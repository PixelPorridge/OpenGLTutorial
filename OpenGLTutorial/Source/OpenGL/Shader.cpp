#include "Shader.h"

Shader::Shader(const char* filePath)
{
	// Open file
	std::ifstream stream(filePath);

	// Types of shaders
	enum class ShaderType
	{
		VERTEX, FRAGMENT
	};
	ShaderType type = ShaderType::VERTEX;

	// Read shaders from file
	std::string line;
	std::stringstream ss[2];
	while (getline(stream, line))
	{
		if (line.find("#shader") != std::string::npos)
		{
			if (line.find("vertex") != std::string::npos)
			{
				type = ShaderType::VERTEX;
			}
			else if (line.find("fragment") != std::string::npos)
			{
				type = ShaderType::FRAGMENT;
			}
		}
		else
		{
			ss[(int)type] << line << '\n';
		}
	}

	// Store shader source code
	std::string vertexCode = ss[(int)ShaderType::VERTEX].str();
	std::string fragmentCode = ss[(int)ShaderType::FRAGMENT].str();
	const GLchar* vertexSource = vertexCode.c_str();
	const GLchar* fragmentSource = fragmentCode.c_str();

	// Vertex shader
	GLuint vertex = glCreateShader(GL_VERTEX_SHADER);
	glShaderSource(vertex, 1, &vertexSource, NULL);
	glCompileShader(vertex);
	CheckCompileErrors(vertex, "VERTEX");

	// Fragment shader
	GLuint fragment = glCreateShader(GL_FRAGMENT_SHADER);
	glShaderSource(fragment, 1, &fragmentSource, NULL);
	glCompileShader(fragment);
	CheckCompileErrors(fragment, "FRAGMENT");

	// Shader program
	ID = glCreateProgram();
	glAttachShader(ID, vertex);
	glAttachShader(ID, fragment);
	glLinkProgram(ID);
	CheckCompileErrors(ID, "PROGRAM");

	// Delete shaders
	glDeleteShader(vertex);
	glDeleteShader(fragment);

	// Use shader program
	glUseProgram(ID);
}

Shader::~Shader()
{
	glDeleteProgram(ID);
}

void Shader::Use() const
{
	glUseProgram(ID);
};

void Shader::SetBool(const char* name, GLboolean value) const
{
	glUniform1i(glGetUniformLocation(ID, name), (GLint)value);
}

void Shader::SetInt(const char* name, GLint value) const
{
	glUniform1i(glGetUniformLocation(ID, name), value);
}

void Shader::SetFloat(const char* name, GLfloat value) const
{
	glUniform1f(glGetUniformLocation(ID, name), value);
}

void Shader::SetVec2(const char* name, glm::vec2 vector) const
{
	glUniform2fv(glGetUniformLocation(ID, name), 1, glm::value_ptr(vector));
}

void Shader::SetVec3(const char* name, glm::vec3 vector) const
{
	glUniform3fv(glGetUniformLocation(ID, name), 1, glm::value_ptr(vector));
}

void Shader::SetVec4(const char* name, glm::vec4 vector) const
{
	glUniform4fv(glGetUniformLocation(ID, name), 1, glm::value_ptr(vector));
}

void Shader::SetMat2(const char* name, glm::mat2 matrix) const
{
	glUniformMatrix2fv(glGetUniformLocation(ID, name), 1, GL_FALSE, glm::value_ptr(matrix));
}

void Shader::SetMat3(const char* name, glm::mat3 matrix) const
{
	glUniformMatrix3fv(glGetUniformLocation(ID, name), 1, GL_FALSE, glm::value_ptr(matrix));
}

void Shader::SetMat4(const char* name, glm::mat4 matrix) const
{
	glUniformMatrix4fv(glGetUniformLocation(ID, name), 1, GL_FALSE, glm::value_ptr(matrix));
}

void Shader::CheckCompileErrors(GLuint shader, std::string type)
{
	GLint success;
	GLchar infoLog[1024];

	if (type != "PROGRAM")
	{
		glGetShaderiv(shader, GL_COMPILE_STATUS, &success);
		if (!success)
		{
			glGetShaderInfoLog(shader, 512, NULL, infoLog);
			std::cout << "ERROR::SHADER_COMPILATION_ERROR::" << type << "\n" << infoLog << std::endl;
		}
	}
	else
	{
		glGetProgramiv(shader, GL_LINK_STATUS, &success);
		if (!success)
		{
			glGetProgramInfoLog(shader, 512, NULL, infoLog);
			std::cout << "ERROR::PROGRAM_LINKING_ERROR::" << type << "\n" << infoLog << std::endl;
		}
	}
}