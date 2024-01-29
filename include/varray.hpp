#pragma once
#include <glad/glad.h>
#include <iostream>
#include <GLFW/glfw3.h>

class VArray {
    public:
        VArray();
        ~VArray();
        void bindVA(){
            glBindVertexArray(varray);
        };
        void unbindVA(){
            glBindVertexArray(0);
        };
        template <typename T> void getAttributePointers(unsigned int index, unsigned int size, unsigned int type, unsigned int normalized, size_t stride){
            glVertexAttribPointer(index, size, type, normalized, stride * sizeof(T), (void*)0);
            glEnableVertexAttribArray(0);
        };
        unsigned int getVArray() const { return varray; }

    private:
        unsigned int varray;
};