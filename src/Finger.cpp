//
// Created by zacha on 11/06/2024.
//

#include "Finger.h"

#include <glm/glm.hpp>
#include "glm/ext.hpp"
#include <glm/gtc/matrix_transform.hpp>

#include <lighting_sphere.h>
#include <shape.h>

#include "Egg.h"

Finger::Finger(Shader *shader_program, float size/*, float angleElbow, float angleCurl, float angleWave*/) : Node() {
    auto position = glm::translate(glm::mat4(1.0f), glm::vec3(0.0f, 0.0f, 0.0f));
    // Proportions par défaut 90% 100% 40%
    auto ovoid = size*glm::vec3(0.5f, 2.5f, 0.5f);
    auto orientation = glm::rotate(glm::mat4(1.0f), glm::radians(0.0f), glm::vec3(1.0f, 0.0f, 0.0f));

    glm::mat4 matbase = position
        * glm::scale(glm::mat4(1.f), 0.9f*ovoid)
        * orientation;

    glm::mat4 matmid = glm::translate(glm::mat4(1.0f), glm::vec3(0.3f, 0.0f, 0.0f))
        * glm::scale(glm::mat4(0.3f), 1.0f*ovoid)
        * glm::rotate(glm::mat4(1.0f), glm::radians(0.0f), glm::vec3(1.0f, 0.0f, 0.0f));

    glm::mat4 mathead = glm::translate(glm::mat4(1.0f), glm::vec3(0.6f, 0.0f, 0.0f))
        * glm::scale(glm::mat4(0.3f), 0.4f*ovoid)
        * glm::rotate(glm::mat4(1.0f), glm::radians(0.0f), glm::vec3(1.0f, 0.0f, 0.0f));

    auto color = glm::vec3(0.0f, 1.0f, 1.0f);
    auto lightpos = glm::vec3(1.0f, 1.0f, 1.0f);

    auto baseEgg = new Egg(size, shader_program, lightpos, color);
    base = baseEgg->node;
    Node* head = new Node(mathead);
    Node* mid = new Node(matmid);

    mid->add(head);
    base->add(mid);

    Shape* HeadEgg = new LightingSphere(shader_program,glm::vec3(0.0f, 1.0f, 0.0f),
        glm::vec3(1.0f, 1.0f, 1.0f), glm::vec3(0.0f, 0.0f, 1.0f));
    head->add(HeadEgg);
    Shape* MidEgg = new LightingSphere(shader_program,glm::vec3(0.0f, 1.0f, 0.0f),
        glm::vec3(1.0f, 1.0f, 1.0f), glm::vec3(0.0f, 0.0f, 1.0f));
    mid->add(MidEgg);
    Shape* BaseEgg = new LightingSphere(shader_program,glm::vec3(0.0f, 1.0f, 0.0f),
        glm::vec3(1.0f, 1.0f, 1.0f), glm::vec3(0.0f, 0.0f, 1.0f));
    base->add(BaseEgg);
}
void Finger::rotateElbow(int angle) {}
void Finger::rotateCurl(int angle) {}
void Finger::rotateWave(int angle) {}