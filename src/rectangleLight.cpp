//
// Created by chloe on 16/06/24.
//


#include "rectangleLight.h"


rectangleLight::rectangleLight(Shader *shader_program, glm::vec3 light_position, glm::vec3 light_color, glm::vec3 object_color) :
       Rectangle(shader_program),
       light_position(light_position),
       light_color(light_color),
       object_color(object_color)
{
    // uniform locations
    light_pos_loc = glGetUniformLocation(this->shader_program_, "lightPos");
    light_color_loc = glGetUniformLocation(this->shader_program_, "lightColor");
    object_color_loc = glGetUniformLocation(this->shader_program_, "objectColor");
}


void rectangleLight::draw(glm::mat4& model, glm::mat4& view, glm::mat4& projection)
{


    Rectangle::draw(model, view, projection);


    // set uniform variables for light and color
    glUniform3fv(light_pos_loc, 1, glm::value_ptr(light_position));
    glUniform3fv(light_color_loc, 1, glm::value_ptr(light_color));
    glUniform3fv(object_color_loc, 1, glm::value_ptr(object_color));
}



