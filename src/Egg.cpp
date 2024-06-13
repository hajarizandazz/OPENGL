//
// Created by zacha on 13/06/2024.
//

#include "Egg.h"

#include <lighting_sphere.h>
#include <shader.h>

Egg::Egg(float size, Shader *shader_program, glm::vec3 lightPos, glm::vec3 eggColor, glm::vec3 lightColor) {
    node = new Node ();
    // Create Egg
    Node* eggNode = new Node(glm::scale(glm::mat4(1.f), size*glm::vec3(0.5f, 2.5f, 0.5f)));
    eggNode->add(new LightingSphere(shader_program, lightPos, lightColor, eggColor));

    // Create smaller nodes at extremity
    auto small = glm::scale(glm::mat4(1.f), size/10*glm::vec3(1.0f, 1.0f, 1.0f));
    Node* baseNode = new Node(glm::translate(glm::mat4(1.0f), glm::vec3(0.0f, size*1.2, 0.0f))*small);
    Node* endNode = new Node(glm::translate(glm::mat4(1.0f), glm::vec3(0.0f, -size*1.2, 0.0f))*small);

    baseNode->add(new LightingSphere(shader_program, lightPos, lightColor, eggColor));
    endNode->add(new LightingSphere(shader_program, lightPos, lightColor, eggColor));

    node->add(eggNode); node->add(baseNode); node->add(endNode);
}
