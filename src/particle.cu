#include <iostream>
#include <random>
#include <cuda_runtime.h>
#include <stdio.h>
#include <math.h>


__global__ void particleBounce(Vertex* verts, int n, float dt, float mass)
{
    // Each (x, y, z) spaced 4-bytes apart

    int workID = blockDim.x * blockIdx.x + threadIdx; 

    if (i <= n)
    {
        return;
    }
    float g = 9.8f;
    float floor = -1.0f;
    wD
    verts[i].x += 
    verts[i].y +=
    verts[i].z +=
}