#include "../include/buffer.hpp"

Buffer::Buffer(unsigned int type) : type(type){
    glGenBuffers(1, &buffer);
}

Buffer::~Buffer(){
    std::cout << "Cleaning up Buffer..." << type << std::endl;
    glDeleteBuffers(1, &buffer);
}