//
// Created by chloe on 13/06/2024.
//


//
// Created by chloe on 13/06/2024.
//
#include <rectangle.h>
#include <shape.h>
#include <GL/glew.h>

Rectangle::Rectangle(Shader *shader_program) : Shape(shader_program){

    GLfloat vertex_buffer_data[] = {
        0.0f, 0.5f, 0.0f,
        0.0f, -0.5f, 0.0f,
        -0.5f, 0.0f, 0.0f,
        0.0f, 0.5f, 0.0f,
        0.0f, -0.5f, 0.0f,
        0.5f, 0.0f, 0.0f,
    };

    glGenVertexArrays(1, &VAO);
    glBindVertexArray(VAO);

    glGenBuffers(1, &VBO);

    glEnableVertexAttribArray(0);
    glBindBuffer(GL_ARRAY_BUFFER, VBO);
    glBufferData(GL_ARRAY_BUFFER, sizeof(vertex_buffer_data), vertex_buffer_data, GL_STATIC_DRAW);
    glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 0, nullptr);


}

Rectangle::~Rectangle() {
    glDeleteVertexArrays(1, &VAO);
    glDeleteBuffers(1, &VBO);
}

void Rectangle::draw(glm::mat4& model, glm::mat4& view, glm::mat4& projection){

    glUseProgram(this->shader_program_);

    glBindVertexArray( VAO );

    Shape::draw(model, view, projection);

    /* draw points 0-3 from the currently bound VAO with current in-use shader */
    glDrawArrays( GL_TRIANGLES, 0, 6 );
}

void Rectangle::key_handler(int key) {
    return;
}
