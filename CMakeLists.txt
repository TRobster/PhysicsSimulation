cmake_minimum_required(VERSION 3.20)
project(ParticleSim)

set(CMAKE_CXX_STANDARD 17)

# 1. Fetch GLFW directly from GitHub
include(FetchContent)
FetchContent_Declare(
    glfw
    GIT_REPOSITORY https://github.com/glfw/glfw.git
    GIT_TAG        3.3.8
)
set(GLFW_BUILD_DOCS OFF CACHE BOOL "" FORCE)
set(GLFW_BUILD_TESTS OFF CACHE BOOL "" FORCE)
set(GLFW_BUILD_EXAMPLES OFF CACHE BOOL "" FORCE)
FetchContent_MakeAvailable(glfw)

# 2. Fetch GLM (Math Library)
FetchContent_Declare(
    glm
    GIT_REPOSITORY https://github.com/g-truc/glm.git
    GIT_TAG        0.9.9.8
)
FetchContent_MakeAvailable(glm)

# 3. Add your executable and GLAD source
add_executable(ParticleSim 
    src/main.cpp 
    src/glad.c
)

# 4. Include directories and link libraries
target_include_directories(ParticleSim PRIVATE include)
target_link_libraries(ParticleSim PRIVATE glfw glm)