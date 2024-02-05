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
        void setUniformBool(const std::string &name, bool value) const {         
            glUniform1i(glGetUniformLocation(shaderProgram, name.c_str()), (int)value); 
        }
        void setUniformInt(const std::string &name, int value) const { 
            glUniform1i(glGetUniformLocation(shaderProgram, name.c_str()), value); 
        }
        void setUniformFloat(const std::string &name, float value) const { 
            glUniform1f(glGetUniformLocation(shaderProgram, name.c_str()), value); 
        } 

    private:
        unsigned int shaderProgram;
};