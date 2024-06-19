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
           // positions          // texture coords
           -0.5f,  0.5f, 0.0f,   0.0f, 1.0f,
           -0.5f, -0.5f, 0.0f,   0.0f, 0.0f,
           0.5f, -0.5f, 0.0f,   1.0f, 0.0f,
           0.5f,  0.5f, 0.0f,   1.0f, 1.0f
   };


   GLuint indices[] = {  // Note that we start from 0!
           0, 1, 2,  // First Triangle
           0, 2, 3   // Second Triangle
   };


   glGenVertexArrays(1, &VAO);
   glBindVertexArray(VAO);


   glGenBuffers(1, &VBO);
   glBindBuffer(GL_ARRAY_BUFFER, VBO);
   glBufferData(GL_ARRAY_BUFFER, sizeof(vertex_buffer_data), vertex_buffer_data, GL_STATIC_DRAW);


   glGenBuffers(1, &EBO);
   glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, EBO);
   glBufferData(GL_ELEMENT_ARRAY_BUFFER, sizeof(indices), indices, GL_STATIC_DRAW);


// Position attribute
   glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 5 * sizeof(GLfloat), (void*)0);
   glEnableVertexAttribArray(0);


// Texture coordinate attribute
   glVertexAttribPointer(1, 2, GL_FLOAT, GL_FALSE, 5 * sizeof(GLfloat), (void*)(3 * sizeof(GLfloat)));
   glEnableVertexAttribArray(1);




}


Rectangle::~Rectangle() {
   glDeleteVertexArrays(1, &VAO);
   glDeleteBuffers(1, &VBO);
}


void Rectangle::draw(glm::mat4& model, glm::mat4& view, glm::mat4& projection){


   glUseProgram(this->shader_program_);


   glUniformMatrix4fv(glGetUniformLocation(this->shader_program_, "model"), 1, GL_FALSE, glm::value_ptr(model));
   glUniformMatrix4fv(glGetUniformLocation(this->shader_program_, "view"), 1, GL_FALSE, glm::value_ptr(view));
   glUniformMatrix4fv(glGetUniformLocation(this->shader_program_, "projection"), 1, GL_FALSE, glm::value_ptr(projection));


   glBindVertexArray(VAO);
   glDrawElements(GL_TRIANGLES, 6, GL_UNSIGNED_INT, 0);
   glBindVertexArray(0);
}


void Rectangle::key_handler(int key) {
   return;
}

