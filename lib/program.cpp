#include "../include/program.hpp"

Program::Program(std::initializer_list<Shader*> shaders){
    shaderProgram = glCreateProgram();

    for(auto& shader : shaders){
        glAttachShader(shaderProgram, shader->getShader());
    }

    int  success;
    char infoLog[512];

    glLinkProgram(shaderProgram);
    glGetProgramiv(shaderProgram, GL_LINK_STATUS, &success);

    if(!success){
        glGetProgramInfoLog(shaderProgram, 512, NULL, infoLog);
        std::cout << "ERROR::PROGRAM::LINKING_FAILED\n" << infoLog << std::endl;
    }
}

Program::~Program(){
    std::cout << "Cleaning up Program..." << std::endl;
    glDeleteProgram(shaderProgram);
}