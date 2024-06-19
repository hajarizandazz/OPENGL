//
// Created by zacha on 11/06/2024.
//
#pragma once

#ifndef FINGER_H
#define FINGER_H
#include <shader.h>
#include <shape.h>

#include "Egg.h"


class Finger {
public:
    Finger(Shader *shader_program, float size);

    Node* base;
    Node* mid;
    Node* head;

    Egg* baseEgg;
    Egg* midEgg;
    Egg* headEgg;

    void alignJoints();

    void transform(glm::mat4 transfo);

    Egg* getHeadEgg();

    void rotateElbow();
    void rotateCurl();
    void rotateWave(int angle);
};



#endif //FINGER_H
