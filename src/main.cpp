#include "../include/config.hpp"
#include "../include/shader.hpp"
#include "../include/program.hpp"
#include "../include/io.hpp"
#include "../include/buffer.hpp"

const char *vertexShaderSource = "#version 330 core\n"
        "layout (location = 0) in vec3 aPos;\n"
        "void main()\n"
        "{\n"
        "   gl_Position = vec4(aPos.x, aPos.y, aPos.z, 1.0);\n"
        "}\0";
const char *fragmentShaderSource = "#version 330 core\n"
        "out vec4 FragColor;\n"
        "void main()\n"
        "{\n"
        "   FragColor = vec4(1.0f, 0.5f, 0.2f, 1.0f);\n"
        "}\n\0";

int main(){
    const unsigned int width = 800;
    const unsigned int height = 600;

    GLFWwindow* window = initWindow(width, height);
    if(window == nullptr){
        return -1;
    }

    {
        Shader vertexShader(vertexShaderSource, GL_VERTEX_SHADER);
        Shader fragmentShader(fragmentShaderSource, GL_FRAGMENT_SHADER);

        Program shaderProgram({&vertexShader, &fragmentShader});

        unsigned int VAO;
        glGenVertexArrays(1, &VAO);

        Buffer VBO(GL_ARRAY_BUFFER);
        Buffer EBO(GL_ELEMENT_ARRAY_BUFFER);

        glBindVertexArray(VAO);

        float vertices[] = {
            0.5f,  0.5f, 0.0f,
            0.5f, -0.5f, 0.0f,
            -0.5f, -0.5f, 0.0f,
            -0.5f,  0.5f, 0.0f
        };

        unsigned int indices[] = { 
            0, 1, 3,
            1, 2, 3
        };  

        VBO.bindBuffer();
        VBO.addData(vertices, sizeof(vertices), GL_STATIC_DRAW);

        glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 3 * sizeof(float), (void*)0);
        glEnableVertexAttribArray(0);

        VBO.unbindBuffer();

        EBO.bindBuffer();
        EBO.addData(indices, sizeof(indices), GL_STATIC_DRAW);

        while(!glfwWindowShouldClose(window)){
            processInput(window);

            glClearColor(0.2f, 0.3f, 0.3f, 1.0f);
            glClear(GL_COLOR_BUFFER_BIT);

            glUseProgram(shaderProgram.getProgram());
            glBindVertexArray(VAO);
            glDrawElements(GL_TRIANGLES, 6, GL_UNSIGNED_INT, 0);

            glfwSwapBuffers(window);
            glfwPollEvents();    
        }

        glDeleteVertexArrays(1, &VAO);
    }

    glfwTerminate();

    return 0;
}

