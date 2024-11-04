// OpenGl Programs.cpp : This file contains the 'main' function. Program execution begins and ends there.

#include <iostream>
#include <stdio.h>
#include <GL/glew.h>
#include <GLFW/glfw3.h>


const GLint width = 1000, height = 1000;

int main()
{
    // Initializing GLFW
    if (!glfwInit())
    {
        std::cout << "GLFW initialization Failed !";
        glfwTerminate();
        // Return 1 as error
        return 1;
    }
    // Setting up GLFW window properties

    // Opengl version
    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
    // No Backward Compatiblity : Core profile
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
    // Forward Compatiblity enabled
    glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, GL_TRUE);

    // Create Window Pointer
    GLFWwindow* newWindow = glfwCreateWindow(width,height,"My Window",NULL,NULL);
    if (!newWindow)
    {
        std::cout << "Window Creation Failed";
        glfwTerminate();
        return 1;
    }

    // Get buffersize info
    int bufferht, bufferwd;
    glfwGetFramebufferSize(newWindow, &bufferwd, &bufferht);

    // Make the window's OpenGL context current
    glfwMakeContextCurrent(newWindow);

    // Context for GLEW
    glewExperimental = GL_TRUE;

    // If GLEW not initialized
    if (glewInit() != GLEW_OK)
    {
        printf("GLEW Can't initialise!");
        glfwDestroyWindow(newWindow);
        glfwTerminate();
        return 1;
    }

    // Setting Viewport size
    glViewport(0, 0, bufferwd, bufferht);

    // Loop till window closed
    while (!glfwWindowShouldClose(newWindow))
    {
        // Getting input events
        glfwPollEvents();
        // Clear window
        glClearColor(1.0f, 1.0f, 0.0f, 1.0f);
        glClear(GL_COLOR_BUFFER_BIT);
        //buffer smooth refresh (swap buffer till new window is loaded)
        glfwSwapBuffers(newWindow);
    }
    return 0;
}

