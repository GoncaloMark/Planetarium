#pragma once
#include <glad/glad.h>
#include <iostream>
#include <GLFW/glfw3.h>
#include "../include/shader.hpp"

class Program {
    public:
        Program(std::initializer_list<Shader*> shader);
        ~Program();
        unsigned int getProgram() const { return shaderProgram; }

    private:
        unsigned int shaderProgram;
};