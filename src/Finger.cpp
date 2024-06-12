//
// Created by zacha on 11/06/2024.
//

#include "Finger.h"

#include <glm/glm.hpp>
#include "glm/ext.hpp"
#include <glm/gtc/matrix_transform.hpp>

#include <lighting_sphere.h>
#include <shape.h>

Finger::Finger(Shader *shader_program) : Node() {


    glm::mat4 mat = glm::translate(glm::mat4(1.0f), glm::vec3(1.0f, 0.0f, -4.0f))
        * glm::scale(glm::mat4(1.0f), glm::vec3(1.0f, 1.0f, 1.0f))
        * glm::rotate(glm::mat4(1.0f), glm::radians(0.0f), glm::vec3(1.0f, 0.0f, 0.0f));


    Node* base = new Node(mat);
    Node* mid = new Node(mat);
    Node* head = new Node(mat);

    Shape* HeadSphere = new LightingSphere(shader_program,glm::vec3(0.0f, 1.0f, 0.0f),
        glm::vec3(1.0f, 1.0f, 1.0f), glm::vec3(0.0f, 0.0f, 1.0f));
    head->add(HeadSphere);
    Shape* MidCylind = new LightingSphere(shader_program,glm::vec3(0.0f, 1.0f, 0.0f),
        glm::vec3(1.0f, 1.0f, 1.0f), glm::vec3(0.0f, 0.0f, 1.0f));
    mid->add(MidCylind);
    Shape* BaseCylind = new LightingSphere(shader_program,glm::vec3(0.0f, 1.0f, 0.0f),
        glm::vec3(1.0f, 1.0f, 1.0f), glm::vec3(0.0f, 0.0f, 1.0f));
    base->add(BaseCylind);
}
