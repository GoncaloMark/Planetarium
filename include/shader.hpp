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

    private:
        unsigned int type;
        unsigned int shader;
        void setType(std::string& extension);
};