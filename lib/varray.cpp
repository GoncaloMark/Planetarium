#include "../include/varray.hpp"

VArray::VArray(){
    glGenVertexArrays(1, &varray);
}

VArray::~VArray(){
    std::cout << "Cleaning up VArray..." << std::endl;
    glDeleteVertexArrays(1, &varray);
}