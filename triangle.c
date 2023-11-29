#include <GLFW/glfw3.h>
 
//gcc -Wall -Iinclude -g  triangle.c -o triangle.exe -Llib-mingw-w64 -lglfw3 -lgdi32 -lopengl32
 
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
        /* Render here */
        glClear(GL_COLOR_BUFFER_BIT);
 
       
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
 
        /* Poll for and process events */
        glfwPollEvents();
    }
 
    glfwTerminate();
    return 0;
}