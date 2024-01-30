#include "../include/config.hpp"
#include "../include/shader.hpp"
#include "../include/program.hpp"
#include "../include/io.hpp"
#include "../include/buffer.hpp"
#include "../include/varray.hpp"

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
        "   FragColor = vec4(1.0f, 1.0f, 0.2f, 1.0f);\n"
        "}\n\0";

int main(){
    const unsigned int width = 800;
    const unsigned int height = 600;

    GLFWwindow* window = initWindow(width, height);
    if(window == nullptr){
        return -1;
    }

    {
        float t1_vertices[] = {
            0.0f, 0.0f, 0.0f,
            -1.0f, 0.0f, 0.0f,
            -0.5f, 1.0f, 0.0f,
        };

        float t2_vertices[] = {
            0.0f, 0.0f, 0.0f, 
            1.0f,  0.0f, 0.0f, 
            0.5f, 1.0f, 0.0f
        };

        unsigned int indices[] = { 
            0, 1, 2
        };

        Shader vertexShader(vertexShaderSource, GL_VERTEX_SHADER);
        Shader fragmentShader(fragmentShaderSource, GL_FRAGMENT_SHADER);

        Program shaderProgram({&vertexShader, &fragmentShader});

        VArray t1_VAO;
        VArray t2_VAO;

        Buffer t1_VBO(GL_ARRAY_BUFFER);
        Buffer t2_VBO(GL_ARRAY_BUFFER);
        Buffer EBO(GL_ELEMENT_ARRAY_BUFFER);

        t1_VAO.bindVA();

        t1_VBO.bindBuffer();
        t1_VBO.addData(t1_vertices, sizeof(t1_vertices), GL_STATIC_DRAW);

        t1_VAO.getAttributePointers<float>(0, 3, GL_FLOAT, GL_FALSE, 3);
        t1_VBO.unbindBuffer();

        t2_VAO.bindVA();

        t2_VBO.bindBuffer();
        t2_VBO.addData(t2_vertices, sizeof(t2_vertices), GL_STATIC_DRAW);

        t2_VAO.getAttributePointers<float>(0, 3, GL_FLOAT, GL_FALSE, 3);
        t2_VBO.unbindBuffer();

        EBO.bindBuffer();
        EBO.addData(indices, sizeof(indices), GL_STATIC_DRAW);

        t1_VAO.unbindVA();
        t2_VAO.unbindVA();

        while(!glfwWindowShouldClose(window)){
            processInput(window);

            glClearColor(0.2f, 0.3f, 0.3f, 1.0f);
            glClear(GL_COLOR_BUFFER_BIT);

            glUseProgram(shaderProgram.getProgram());
            glBindVertexArray(t1_VAO.getVArray());
            glDrawArrays(GL_TRIANGLES, 0, 3);

            glBindVertexArray(t2_VAO.getVArray());
            glDrawArrays(GL_TRIANGLES, 0, 3);

            glfwSwapBuffers(window);
            glfwPollEvents();    
        }
    }

    glfwTerminate();

    return 0;
}

