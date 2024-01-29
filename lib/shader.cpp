#include "../include/shader.hpp"

Shader::Shader(const char* def, unsigned int type) : def(def), type(type) {
    shader = glCreateShader(type);
    glShaderSource(shader, 1, &def, NULL);
    glCompileShader(shader);

    int  success;
    char infoLog[512];
    glGetShaderiv(shader, GL_COMPILE_STATUS, &success);

    if(!success){
        glGetShaderInfoLog(shader, 512, NULL, infoLog);
        std::cout << "ERROR::SHADER::VERTEX::COMPILATION_FAILED\n" << infoLog << std::endl;
    }
}

Shader::~Shader(){
    std::cout << "Cleaning up Shader..." << type << std::endl;
    glDeleteShader(shader);
}