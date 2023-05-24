#define GL_SILENCE_DEPRECATION
#include "GLFW/include/GLFW/glfw3.h"
#include <math.h>
#include <iostream>
using namespace std;
void drawOctahedron() {
    float size = 0.5f;
    glBegin(GL_LINE_LOOP);

    // Top pyramid
    glColor3f(1.0f, 0.0f, 0.0f); // red
    glVertex3f(0.0f, size, 0.0f);
    glVertex3f(-size, 0.0f, size);
    glVertex3f(size, 0.0f, size);

    glColor3f(0.0f, 1.0f, 0.0f); // green
    glVertex3f(0.0f, size, 0.0f);
    glVertex3f(size, 0.0f, size);
    glVertex3f(size, 0.0f, -size);

    glColor3f(0.0f, 0.0f, 1.0f); // blue
    glVertex3f(0.0f, size, 0.0f);
    glVertex3f(size, 0.0f, -size);
    glVertex3f(-size, 0.0f, -size);

    glColor3f(1.0f, 1.0f, 0.0f); // yellow
    glVertex3f(0.0f, size, 0.0f);
    glVertex3f(-size, 0.0f, -size);
    glVertex3f(-size, 0.0f, size);

    // Bottom pyramid
    glColor3f(1.0f, 0.0f, 1.0f); // magenta
    glVertex3f(0.0f, -size, 0.0f);
    glVertex3f(-size, 0.0f, size);
    glVertex3f(size, 0.0f, size);

    glColor3f(0.0f, 1.0f, 1.0f); // cyan
    glVertex3f(0.0f, -size, 0.0f);
    glVertex3f(size, 0.0f, size);
    glVertex3f(size, 0.0f, -size);

    glColor3f(1.0f, 1.0f, 1.0f); // white
    glVertex3f(0.0f, -size, 0.0f);
    glVertex3f(size, 0.0f, -size);
    glVertex3f(-size, 0.0f, -size);

    glColor3f(0.5f, 0.5f, 0.5f); // gray
    glVertex3f(0.0f, -size, 0.0f);
    glVertex3f(-size, 0.0f, -size);
    glVertex3f(-size, 0.0f, size);

    glEnd();
}
void drawTetrahedron() {
    const float a = 0.5f;  // side length

    glBegin(GL_LINE_LOOP);
    // Front face
    glVertex3f(-a / 2, -a / (2 * sqrt(2)), a / (2 * sqrt(2)));
    glVertex3f(a / 2, -a / (2 * sqrt(2)), a / (2 * sqrt(2)));
    glVertex3f(0.0f, a / (sqrt(2)), 0.0f);
    // Right face
    glVertex3f(a / 2, -a / (2 * sqrt(2)), a / (2 * sqrt(2)));
    glVertex3f(a / 2, -a / (2 * sqrt(2)), -a / (2 * sqrt(2)));
    glVertex3f(0.0f, a / (sqrt(2)), 0.0f);
    // Back face
    glVertex3f(a / 2, -a / (2 * sqrt(2)), -a / (2 * sqrt(2)));
    glVertex3f(-a / 2, -a / (2 * sqrt(2)), -a / (2 * sqrt(2)));
    glVertex3f(0.0f, a / (sqrt(2)), 0.0f);
    // Left face
    glVertex3f(-a / 2, -a / (2 * sqrt(2)), -a / (2 * sqrt(2)));
    glVertex3f(-a / 2, -a / (2 * sqrt(2)), a / (2 * sqrt(2)));
    glVertex3f(0.0f, a / (sqrt(2)), 0.0f);
    glEnd();
}
void drawCube() {
    glBegin(GL_LINE_LOOP);
    // Front face
    glVertex3f(-0.5f, -0.5f, 0.5f);
    glVertex3f(0.5f, -0.5f, 0.5f);
    glVertex3f(0.5f, 0.5f, 0.5f);
    glVertex3f(-0.5f, 0.5f, 0.5f);
    // Back face
    glVertex3f(-0.5f, -0.5f, -0.5f);
    glVertex3f(-0.5f, 0.5f, -0.5f);
    glVertex3f(0.5f, 0.5f, -0.5f);
    glVertex3f(0.5f, -0.5f, -0.5f);
    // Top face
    glVertex3f(-0.5f, 0.5f, -0.5f);
    glVertex3f(-0.5f, 0.5f, 0.5f);
    glVertex3f(0.5f, 0.5f, 0.5f);
    glVertex3f(0.5f, 0.5f, -0.5f);
    // Bottom face
    glVertex3f(-0.5f, -0.5f, -0.5f);
    glVertex3f(0.5f, -0.5f, -0.5f);
    glVertex3f(0.5f, -0.5f, 0.5f);
    glVertex3f(-0.5f, -0.5f, 0.5f);
    // Right face
    glVertex3f(0.5f, -0.5f, -0.5f);
    glVertex3f(0.5f, 0.5f, -0.5f);
    glVertex3f(0.5f, 0.5f, 0.5f);
    glVertex3f(0.5f, -0.5f, 0.5f);
    // Left face
    glVertex3f(-0.5f, -0.5f, -0.5f);
    glVertex3f(-0.5f, -0.5f, 0.5f);
    glVertex3f(-0.5f, 0.5f, 0.5f);
    glVertex3f(-0.5f, 0.5f, -0.5f);
    glEnd();
}

int main()
{
    GLFWwindow* window;

    if (!glfwInit()) {
        return -1;
    }

    window = glfwCreateWindow(640, 480, "Moving Triangle", NULL, NULL);

    if (!window) {
        glfwTerminate();
        return -1;
    }

    glfwMakeContextCurrent(window);


    while (!glfwWindowShouldClose(window))
    {
        glClear(GL_COLOR_BUFFER_BIT);
        glRotatef(1, 1.0f, 1.0f, 1.0f);
        //drawCube();
        drawOctahedron();
        //drawTetrahedron();
        glfwWaitEventsTimeout(0.01);
        glfwSwapBuffers(window);
        glfwPollEvents();
    }
   
    glfwTerminate();
    return 0;
}