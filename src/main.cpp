#include "../include/config.hpp"
#include "../include/shader.hpp"
#include "../include/program.hpp"
#include "../include/io.hpp"
#include "../include/buffer.hpp"
#include "../include/varray.hpp"
#include "../include/texture.hpp"

#include <cmath>

int main(){
    const unsigned int width = 800;
    const unsigned int height = 600;

    GLFWwindow* window = initWindow(width, height);
    if(window == nullptr){
        return -1;
    }

    {
        float t1_vertices[] = {
            // Position         // Color            // Texture
            0.0f, 0.0f, 0.0f,   1.0f, 0.0f, 0.0f,   0.0f, 0.0f,
            -1.0f, 0.0f, 0.0f,  0.0f, 1.0f, 0.0f,   -1.0f, 0.0f,
            -0.5f, 1.0f, 0.0f,  0.0f, 0.0f, 1.0f,   -0.5f, 1.0f
        };

        unsigned int indices[] = { 
            0, 1, 2
        };

        Shader vertexShader("shaders/shader.vs");
        Shader fragmentShader("shaders/shader.fs");

        Program shaderProgram({&vertexShader, &fragmentShader});

        VArray t1_VAO;

        Buffer t1_VBO(GL_ARRAY_BUFFER);
        Buffer EBO(GL_ELEMENT_ARRAY_BUFFER);

        t1_VAO.bindVA();

        t1_VBO.bindBuffer();
        t1_VBO.addData(t1_vertices, sizeof(t1_vertices), GL_STATIC_DRAW);

        t1_VAO.getAttributePointers<float>(0, 3, GL_FLOAT, GL_FALSE, 8, 0);
        t1_VAO.getAttributePointers<float>(1, 3, GL_FLOAT, GL_FALSE, 8, 3);
        t1_VAO.getAttributePointers<float>(2, 2, GL_FLOAT, GL_FALSE, 8, 6);
        t1_VBO.unbindBuffer();

        EBO.bindBuffer();
        EBO.addData(indices, sizeof(indices), GL_STATIC_DRAW);

        t1_VAO.unbindVA();

        Texture tex1("textures/texture.jpg");

        while(!glfwWindowShouldClose(window)){
            processInput(window);

            glClearColor(0.2f, 0.3f, 0.3f, 1.0f);
            glClear(GL_COLOR_BUFFER_BIT);

            glUseProgram(shaderProgram.getProgram());

            glActiveTexture(GL_TEXTURE0);
            glBindTexture(GL_TEXTURE_2D, tex1.getTexture());
            glBindVertexArray(t1_VAO.getVArray());
            glDrawElements(GL_TRIANGLES, 3, GL_UNSIGNED_INT, 0);

            glfwSwapBuffers(window);
            glfwPollEvents();    
        }
    }

    glfwTerminate();

    return 0;
}

