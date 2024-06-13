//
// Created by chloe on 13/06/2024.
//
#pragma once

#include "shape.h"
#include "shader.h"
#include <../external/glew-cmake/include/GL/glew.h>
#include <texture.h>



class Rectangle : public Shape {
public:
    Rectangle(Shader *shader_program);
    void draw(glm::mat4& model, glm::mat4& view, glm::mat4& projection) override;
    void key_handler(int key);
    virtual ~Rectangle();

private:
    GLuint VAO{};
    GLuint VBO{};
};