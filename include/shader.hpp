#pragma once
#include <glad/glad.h>
#include <iostream>
#include <GLFW/glfw3.h>
#include <string>
#include <fstream>
#include <sstream>
#include <filesystem>
#include <unordered_map>

enum class Type {
    FragmentShader, 
    VertexShader,
    Undefined
};

class Shader {
    public:
        Shader(const char* sourceFile);
        ~Shader();
        unsigned int getType() const {return type; }
        unsigned int getShader() const { return shader; }

        void setUniformBool(const std::string &name, bool value) const {         
            glUniform1i(glGetUniformLocation(shader, name.c_str()), (int)value); 
        }
        void setUniformInt(const std::string &name, int value) const { 
            glUniform1i(glGetUniformLocation(shader, name.c_str()), value); 
        }
        void setUniformFloat(const std::string &name, float value) const { 
            glUniform1f(glGetUniformLocation(shader, name.c_str()), value); 
        } 

    private:
        unsigned int type;
        unsigned int shader;
        void setType(std::string& extension);
};