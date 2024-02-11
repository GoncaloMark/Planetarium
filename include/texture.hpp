#pragma once

#include "../lib/glad/include/glad/glad.h"
#include <iostream>
#include <GLFW/glfw3.h>

class Texture {
    public:
        Texture(const char* path);
        unsigned int getTexture(){ return texture; }

    private:
        const char* path;
        unsigned int texture;
};