//
// Created by zacha on 13/06/2024.
//

#pragma once

#ifndef EGG_H
#define EGG_H
#include <node.h>


class Egg : public Node {
public:
    Egg(float size, Shader *shader_program, glm::vec3 lightPos, glm::vec3 eggColor, glm::vec3 lightColor = glm::vec3(1.0f, 1.0f, 1.0f));
    Node* node;
};



#endif //EGG_H
