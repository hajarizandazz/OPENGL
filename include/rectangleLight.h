//
// Created by chloe on 16/06/24.
//
#ifndef OPENGLPROGRAM_RECTANGLELIGHT_H
#define OPENGLPROGRAM_RECTANGLELIGHT_H
#include <rectangle.h>
#include <shape.h>
#include <../external/glew-cmake/include/GL/glew.h>

class rectangleLight : public Rectangle{
public:
    rectangleLight(Shader *shader_program, glm::vec3 light_position, glm::vec3 light_color, glm::vec3 object_color);

    virtual void draw(glm::mat4& model, glm::mat4& view, glm::mat4& projection);

private:
    glm::vec3 light_position;
    glm::vec3 light_color;
    glm::vec3 object_color;


    // uniform locations
    GLint light_pos_loc;
    GLint light_color_loc;
    GLint object_color_loc;
};

#endif //OPENGLPROGRAM_RECTANGLELIGHT_H