#include <glad/glad.h>
#include <GLFW/glfw3.h>
#include <iostream>


struct Vertex 
{
    float x, y, z;
}

Vertex* generateCircleVertex(float cx, float cy, float cz, int segments)
{
    
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