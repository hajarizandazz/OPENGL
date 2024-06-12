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



    glm::mat4 mat = glm::translate(glm::mat4(1.0f), glm::vec3(0.0f, 0.0f, 0.0f))
        * glm::scale(glm::mat4(1.f), glm::vec3(0.5f, 2.5f, 0.5f))
        * glm::rotate(glm::mat4(1.0f), glm::radians(0.0f), glm::vec3(1.0f, 0.0f, 0.0f));

    all=new Node(mat);

    glm::mat4 matbase = glm::translate(glm::mat4(1.0f), glm::vec3(0.0f, 0.0f, 0.0f))
        * glm::scale(glm::mat4(0.3f), glm::vec3(0.5f, 0.05f, 0.09f))
        * glm::rotate(glm::mat4(1.0f), glm::radians(0.0f), glm::vec3(1.0f, 0.0f, 0.0f));

    glm::mat4 matmid = glm::translate(glm::mat4(1.0f), glm::vec3(0.3f, 0.0f, 0.0f))
        * glm::scale(glm::mat4(0.3f), glm::vec3(0.5f, 0.05f, 0.09f))
        * glm::rotate(glm::mat4(1.0f), glm::radians(0.0f), glm::vec3(1.0f, 0.0f, 0.0f));

    glm::mat4 mathead = glm::translate(glm::mat4(1.0f), glm::vec3(0.6f, 0.0f, 0.0f))
        * glm::scale(glm::mat4(0.3f), glm::vec3(0.5f, 0.05f, 0.09f))
        * glm::rotate(glm::mat4(1.0f), glm::radians(0.0f), glm::vec3(1.0f, 0.0f, 0.0f));


    Node* base = new Node(matbase);
    Node* mid = new Node(matmid);
    Node* head = new Node(mathead);

    Shape* HeadSphere = new LightingSphere(shader_program,glm::vec3(0.0f, 1.0f, 0.0f),
        glm::vec3(1.0f, 1.0f, 1.0f), glm::vec3(0.0f, 0.0f, 1.0f));
    head->add(HeadSphere);
    Shape* MidCylind = new LightingSphere(shader_program,glm::vec3(0.0f, 1.0f, 0.0f),
        glm::vec3(1.0f, 1.0f, 1.0f), glm::vec3(0.0f, 0.0f, 1.0f));
    mid->add(MidCylind);
    Shape* BaseCylind = new LightingSphere(shader_program,glm::vec3(0.0f, 1.0f, 0.0f),
        glm::vec3(1.0f, 1.0f, 1.0f), glm::vec3(0.0f, 0.0f, 1.0f));
    base->add(BaseCylind);

    all->add(base);
    all->add(mid);
    all->add(head);


}
