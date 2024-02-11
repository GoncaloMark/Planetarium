#pragma once
#include "../lib/glad/include/glad/glad.h"
#include <iostream>
#include <GLFW/glfw3.h>

class Buffer {
    public:
        Buffer(unsigned int type);
        ~Buffer();
        unsigned int getBuffer() const { return buffer; }
        unsigned int getType() const { return type; }
        template <typename T> void addData(T* data, size_t size, unsigned int draw_mode){
            glBufferData(type, sizeof(T)*size, data, draw_mode);
        }
        void bindBuffer(){
            glBindBuffer(type, buffer);
        };

        void unbindBuffer(){
            glBindBuffer(type, 0);
        };

    private:
        unsigned int buffer;
        unsigned int type;
};