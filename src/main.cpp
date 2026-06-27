#include <glad/glad.h>
#include <GLFW/glfw3.h>
#include <iostream>
#include <math.h>
#include <cmath.h>
#define M_PI 3.14159265358979323846

struct Vertex 
{
    float x, y, z;
};

Vertex generateCart(float phi, float theta, float r)
{
    Vertex *cart;
    cart->x = r * sin(phi) * cos(theta);
    cart->y = r * cos(phi);
    cart->z = r * sin(phi) * sin(theta);
    return *cart;

}
Vertex* generateCircleVertex(float r, int stacks, int sectors, int *outCount)
{
    int triCount = stacks * sectors * 2;
    int vertCount = triCount * 3; // 3 vertices per triangle.
    Vertex *verts = new Vertex[vertCount];
    int idx = 0;

    for (int i = 0; i < stacks; i++){
        float ph1 = M_PI * (i / (float)stacks);
        float ph2 = M_PI * ((i+ 1) / (float)stacks);
        for (int j = 0; j < sectors; j++)
        {
            float theta1 = ( 2 * M_PI ) * (j / (float)sectors);
            float theta2 = ( 2 * M_PI ) * ((j+1) / (float)sectors);
            Vertex A = generateCart(r, theta1, ph1);
            Vertex B = generateCart(r, theta1, ph2);
            Vertex C = generateCart(r, theta2, ph1);
            Vertex D = generateCart(r, theta2, ph2);

            verts[idx++] = A;
            verts[idx++] = C;
            verts[idx++] = B;

            verts[idx++] = B;
            verts[idx++] = C;
            verts[idx++] = D;
        }
    }
    *outCount = vertCount; 
    return verts;
}
// Callback to handle window resizing
void framebuffer_size_callback(GLFWwindow* window, int width, int height) {
    glViewport(0, 0, width, height);
}

// Basic input processing (e.g., press ESC to close)
void processInput(GLFWwindow *window) {
    if(glfwGetKey(window, GLFW_KEY_ESCAPE) == GLFW_PRESS)
        glfwSetWindowShouldClose(window, true);
}

// --- YOUR CUDA/HPC FUNCTIONS GO HERE ---
// void init_framework() { ... }
// void run_simulation_frame() { ... }
// ---------------------------------------

int main() {
    // 1. Initialize GLFW and configure version (OpenGL 3.3 Core Profile)
    glfwInit();
    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

    // 2. Create the Window
    GLFWwindow* window = glfwCreateWindow(1024, 768, "CUDA Particle Simulation", NULL, NULL);
    if (window == NULL) {
        std::cerr << "Failed to create GLFW window" << std::endl;
        glfwTerminate();
        return -1;
    }
    glfwMakeContextCurrent(window);
    glfwSetFramebufferSizeCallback(window, framebuffer_size_callback);

    // 3. Load all OpenGL function pointers via GLAD
    if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress)) {
        std::cerr << "Failed to initialize GLAD" << std::endl;
        return -1;
    }

    // --- INITIALIZE YOUR PHYSICS VBO & CUDA INTEROP HERE ---
    // init_framework();
    // -------------------------------------------------------

    // 4. The Main Render/Compute Loop
    while (!glfwWindowShouldClose(window)) {
        // Input
        processInput(window);

        // Clear the screen to a dark background
        glClearColor(0.1f, 0.1f, 0.1f, 1.0f);
        glClear(GL_COLOR_BUFFER_BIT);

        // --- RUN YOUR CUDA KERNEL & DRAW FRAME HERE ---
        // run_simulation_frame();
        // ----------------------------------------------

        // Swap buffers and poll IO events (keys pressed/released, mouse moved etc.)
        glfwSwapBuffers(window);
        glfwPollEvents();
    }

    // 5. Clean up and exit
    glfwTerminate();
    return 0;
}