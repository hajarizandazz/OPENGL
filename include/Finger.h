//
// Created by zacha on 11/06/2024.
//
#pragma once

#ifndef FINGER_H
#define FINGER_H
#include <shader.h>
#include <shape.h>


class Finger : public Node {
public:
    Finger(Shader *shader_program, float size);
    Node* base;
    void rotateElbow(int angle);
    void rotateCurl(int angle);
    void rotateWave(int angle);
};



#endif //FINGER_H
