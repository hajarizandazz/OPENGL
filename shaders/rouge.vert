#version 330 core

// input attribute variable, given per vertex
in vec3 position;

// global matrix variables
uniform mat4 view;
uniform mat4 projection;

// color given to the fragment shader
out vec3 fragColor;

void main() {

    fragColor = vec3(1.f,0.f,0.f);
    // tell OpenGL how to transform the vertex to clip coordinates
    gl_Position = projection * view * vec4(position, 1);
}
