//
// Created by zacha on 11/06/2024.
//

#include "Finger.h"

#include <glm/glm.hpp>
#include "glm/ext.hpp"
#include <glm/gtc/matrix_transform.hpp>

#include <Egg.h>
#include <iostream>

Finger::Finger(Shader *shader_program, float size) {
    auto color = glm::vec3(0.0f, 1.0f, 1.0f);
    auto lightpos = glm::vec3(1.0f, 1.0f, 1.0f);
    auto id = glm::mat4(1.0f);

    // Proportions par défaut 90% 100% 40%
    base = new Node(id);
    auto baseEgg = new Egg(0.9*size, shader_program, lightpos, color);
    base->add(baseEgg->node);

    mid = new Node(id);
    auto midEgg = new Egg(size, shader_program, lightpos, color);
    mid->add(midEgg->node);

    head = new Node(id);
    auto headEgg = new Egg(0.4*size, shader_program, lightpos, color);
    head->add(headEgg->node);

    mid->add(head);
    base->add(mid);

    auto MidToBase = baseEgg->get1Pos() - midEgg->get2Pos(); // error ?
    mid->move(translate(id, MidToBase));
    auto HeadToMid = midEgg->get1Pos() - headEgg->get2Pos();
    head->move(translate(id, HeadToMid));
}

void Finger::alignJoints() {
    auto id = glm::mat4(1.0f);
    auto MidToBase = baseEgg->get1Pos() - midEgg->get2Pos(); // error ?
    mid->move(translate(id, MidToBase));
    auto HeadToMid = midEgg->get1Pos() - headEgg->get2Pos();
    head->move(translate(id, HeadToMid));
}

void Finger::transform(glm::mat4 transfo) {
    base->move(transfo);
    alignJoints();
}

void Finger::rotateElbow(int angle) {}
void Finger::rotateCurl(int angle) {}
void Finger::rotateWave(int angle) {}