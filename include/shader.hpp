#pragma once
#include <glad/glad.h>
#include <iostream>
#include <GLFW/glfw3.h>

class Shader {
    public:
        Shader(const char* def, unsigned int type);
        ~Shader();
        const char* getDef() const { return def; }
        unsigned int getType() const {return type; }
        unsigned int getShader() const { return shader; }

    private:
        const char* def;
        unsigned int type;
        unsigned int shader;
};