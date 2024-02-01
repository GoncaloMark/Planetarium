#include "../include/shader.hpp"

Shader::Shader(const char* sourceFile) {
    std::string shaderCode;
    std::ifstream shaderSource;
    std::string ext;

    shaderSource.exceptions(std::ifstream::failbit | std::ifstream::badbit); //TODO

    ext = std::filesystem::path(sourceFile).extension().string();
    setType(ext);
    
    try
    {
        std::stringstream shaderStream;

        shaderSource.open(sourceFile);
        shaderStream << shaderSource.rdbuf();
        shaderSource.close();

        shaderCode = shaderStream.str();
    }
    catch(const std::ifstream::failure& e)
    {
        std::cerr << "ERROR::SHADER::FILE_NOT_SUCCESFULLY_READ" << '\n';
    }
    
    const char* glShaderCode = shaderCode.c_str();

    shader = glCreateShader(type);
    glShaderSource(shader, 1, &glShaderCode, NULL);
    glCompileShader(shader);

    int  success;
    char infoLog[512];
    glGetShaderiv(shader, GL_COMPILE_STATUS, &success);

    if(!success){
        glGetShaderInfoLog(shader, 512, NULL, infoLog);
        std::cout << "ERROR::SHADER::VERTEX::COMPILATION_FAILED\n" << infoLog << std::endl;
    }
}

Shader::~Shader(){
    std::cout << "Cleaning up Shader..." << type << std::endl;
    glDeleteShader(shader);
}

void Shader::setType(std::string& extension){
    static const std::unordered_map<std::string, Type> type_map{
        {".fs", Type::FragmentShader},
        {".vs", Type::VertexShader}
    };

    switch(type_map.count(extension) ? type_map.at(extension) : Type::Undefined) {
        case Type::FragmentShader:
            type = GL_FRAGMENT_SHADER;
            break;
        case Type::VertexShader:
            type = GL_VERTEX_SHADER;
            break;
        default:
            break;
    }
}