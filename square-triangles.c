//Compile command
//gcc -Wall -Iinclude -g  square-triangles.c -o square-triangles.exe -Llib-mingw-w64 -lglfw3 -lgdi32 -lopengl32
 
#include <GLFW/glfw3.h>
#include <stdbool.h>
 
int main(void)
{
    /* Initialize the library */
    if (!glfwInit())
        return -1;
 
    /* Create a windowed mode window and its OpenGL context */
    GLFWwindow* window = glfwCreateWindow(800, 600, "Test Window", NULL, NULL);
 
    if (!window)
    {
        glfwTerminate();
        return -1;
    }
 
    /* Make the window's context current */
    glfwMakeContextCurrent(window);
 
    glClearColor(0.0,0.15,0.35,1.0);
 
    glPolygonMode(GL_FRONT_AND_BACK, GL_LINE);
   
 
    /* Loop until the user closes the window */
    while (!glfwWindowShouldClose(window))
    {
       
        /* Poll for and process events */
        glfwPollEvents();
 
        /* Render here */
        glClear(GL_COLOR_BUFFER_BIT);
 
        if(glfwGetKey(window, GLFW_KEY_ESCAPE) == GLFW_PRESS)
            glfwSetWindowShouldClose(window, true);
 
        glColor3f(0.0,1.0,0.0);
 
        glBegin(GL_TRIANGLES);
            glVertex3f(0.5,0.5,0.0);
            glVertex3f(0.5,-0.5,0.0);
            glVertex3f(-0.5,0.5,0.0);
        glEnd();
 
        glBegin(GL_TRIANGLES);
            glVertex3f(0.5,-0.5,0.0);
            glVertex3f(-0.5,-0.5,0.0);
            glVertex3f(-0.5,0.5,0.0);
        glEnd();
 
        /* Swap front and back buffers */
        glfwSwapBuffers(window);
 
    }
 
    glfwTerminate();
    return 0;
}