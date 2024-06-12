//
// Created by zacha on 11/06/2024.
//

#ifndef FINGER_H
#define FINGER_H
#include <shader.h>
#include <shape.h>


class Finger : public Node {
public:
    Finger(Shader *shader_program);
    Node* all;

};



#endif //FINGER_H
