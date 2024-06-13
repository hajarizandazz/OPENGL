//
// Created by chloe on 13/06/2024.
//


#include "shape.h"
#include "shader.h"
#include <GL/glew.h>
#include <texture.h>
#include "rectangle.h"


class RectangleText : public Rectangle {
public:
    RectangleText(Shader *shader_program, Texture *texture);

    void draw(glm::mat4& model, glm::mat4& view, glm::mat4& projection) override;

private:
    GLuint loc_diffuse_map;
    Texture *texture;
};





