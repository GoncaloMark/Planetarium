#include "../include/buffer.hpp"

Buffer::Buffer(unsigned int type) : type(type){
    glGenBuffers(1, &buffer);
}

Buffer::~Buffer(){
    glDeleteBuffers(1, &buffer);
}