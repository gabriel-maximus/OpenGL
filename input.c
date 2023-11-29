//Compile command
//gcc -Wall -Iinclude -g  input.c -o input.exe -Llib-mingw-w64 -lglfw3 -lgdi32 -lopengl32
 
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
   
 
    /* Loop until the user closes the window */
    while (!glfwWindowShouldClose(window))
    {
       
        /* Poll for and process events */
        glfwPollEvents();
 
        /* Render here */
        glClear(GL_COLOR_BUFFER_BIT);
 
        if(glfwGetKey(window, GLFW_KEY_ESCAPE) == GLFW_PRESS)
            glfwSetWindowShouldClose(window, true);
 
        glBegin(GL_TRIANGLES);
            glColor3f(1.0,0.0,0.0);
            glVertex3f(0.0,0.5,0.0);
            glColor3f(0.0,1.0,0.0);
            glVertex3f(-0.5,-0.5,0.0);
            glColor3f(0.0,0.0,1.0);
            glVertex3f(0.5,-0.5,0.0);
        glEnd();
 
        /* Swap front and back buffers */
        glfwSwapBuffers(window);
 
    }
 
    glfwTerminate();
    return 0;
}