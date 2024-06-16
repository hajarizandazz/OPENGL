#include "viewer.h"
#include "textured_sphere.h"
#include "lighting_sphere.h"
#include "texture.h"
#include "node.h"
#include "shader.h"
#include <string>
#include <triangle.h>

#include "../include/Egg.h"
#include "Finger.h"
#include "rectangle.h"
#include "RectangleText.h"
#include "rectangleLight.h"

#ifndef SHADER_DIR
#error "SHADER_DIR not defined"
#endif

#ifndef TEXTURE_DIR
#error "TEXTURE_DIR not defined"
#endif


static void alignJointsR(Finger* f,Finger* hand) {
    auto id = glm::mat4(1.0f);
    glm::vec3 FingerToHand = hand->headEgg->get2Pos() - f->baseEgg->get1Pos();
    //f->base->move(translate(id, MidToBase));
}

int main()
{

    // create window, add shaders & scene objects, then run rendering loop
    Viewer viewer;

    // get shader directory
    std::string shader_dir = SHADER_DIR;

    Shader *texture_shader = new Shader(shader_dir + "texture.vert", shader_dir + "texture.frag");

    // get textures directory
    std::string texture_dir = TEXTURE_DIR;

    Texture *texterre = new Texture(texture_dir + "BeachBall.jpg");
    Shape* sphere1 = new TexturedSphere(texture_shader, texterre);
    glm::mat4 sphere1_mat = glm::translate(glm::mat4(1.0f), glm::vec3(-1.0f, 0.0f, -4.0f))
        * glm::scale(glm::mat4(1.0f), glm::vec3(1.0f, 1.0f, 1.0f))
        * glm::rotate(glm::mat4(1.0f), glm::radians(0.0f), glm::vec3(1.0f, 0.0f, 0.0f));

    Node* sphere1_node = new Node(sphere1_mat);

    sphere1_node->add(sphere1);

    viewer.scene_root->add(sphere1_node);

    Shader *phong_shader = new Shader(shader_dir + "phong.vert", shader_dir + "phong.frag");

    Shape* palmR = new LightingSphere(phong_shader, glm::vec3(-5.0f, -5.0f, 5.0f), glm::vec3(1.0f, 1.0f, 1.0f), glm::vec3(0.0f, 0.0f, 1.0f));
    glm::mat4 palmR_mat = glm::translate(glm::mat4(1.0f), glm::vec3(1.0f, 0.0f, -4.0f))
        * glm::scale(glm::mat4(1.0f), glm::vec3(1.0f, 1.0f, 1.0f))
        * glm::rotate(glm::mat4(1.0f), glm::radians(0.0f), glm::vec3(1.0f, 0.0f, 0.0f));
    
    Node* palmR_node = new Node(palmR_mat);

    palmR_node->add(palmR);

    viewer.scene_root->add(palmR_node);
/*
    Finger* test= new Finger(phong_shader);

    viewer.scene_root->add(test->all);*/

//le sol
    Texture *texture = new Texture(texture_dir + "sand_texture.jpg");

    Shader *textrect_shader = new Shader(shader_dir + "textrect.vert", shader_dir + "textrect.frag");

    Shape* text = new RectangleText(textrect_shader,texture);

    glm::mat4 text_mat = glm::translate(glm::mat4(1.0f), glm::vec3(0.0f, -1.0f, 0.0f))
        * glm::scale(glm::mat4(1.0f), 10.0f * glm::vec3(1.0f, 1.0f, 1.0f))
        * glm::rotate(glm::mat4(1.0f), glm::radians(90.0f), glm::vec3(1.0f, 0.0f, 0.0f));

    Node* text_node = new Node(text_mat);

    text_node->add(text);

    viewer.scene_root->add(text_node);

//les murs

    Shape* rect1 = new rectangleLight(phong_shader, glm::vec3(0.0f, 0.0f, 0.0f), glm::vec3(1.0f, 1.0f, 1.0f), glm::vec3(0.0f, 0.0f, 1.0f));

    glm::mat4 rect1_mat = glm::translate(glm::mat4(1.0f), glm::vec3(5.0f, 0.0f, 0.0f))
                         * glm::scale(glm::mat4(1.0f), 10.0f * glm::vec3(1.0f, 1.0f, 1.0f))
                         * glm::rotate(glm::mat4(1.0f), glm::radians(90.0f), glm::vec3(0.0f, 1.0f, 0.0f));

    Node* rect1_node = new Node(rect1_mat);

    rect1_node->add(rect1);

    viewer.scene_root->add(rect1_node);



    Shape* rect2 = new rectangleLight(phong_shader, glm::vec3(0.0f, 0.0f, 0.0f), glm::vec3(1.0f, 1.0f, 1.0f), glm::vec3(0.0f, 0.0f, 1.0f));

    glm::mat4 rect2_mat = glm::translate(glm::mat4(1.0f), glm::vec3(0.0f, 0.0f, 5.0f))
                          * glm::scale(glm::mat4(1.0f), 10.0f * glm::vec3(1.0f, 1.0f, 1.0f))
                          * glm::rotate(glm::mat4(1.0f), glm::radians(90.0f), glm::vec3(0.0f, 0.0f, 1.0f));

    Node* rect2_node = new Node(rect2_mat);

    rect2_node->add(rect2);


    viewer.scene_root->add(rect2_node);



    Shape* rect3 = new rectangleLight(phong_shader, glm::vec3(0.0f, 0.0f, 0.0f), glm::vec3(1.0f, 1.0f, 1.0f), glm::vec3(0.0f, 0.0f, 1.0f));

    glm::mat4 rect3_mat = glm::translate(glm::mat4(1.0f), glm::vec3(-5.0f, 0.0f, 0.0f))
                          * glm::scale(glm::mat4(1.0f), 10.0f * glm::vec3(1.0f, 1.0f, 1.0f))
                          * glm::rotate(glm::mat4(1.0f), glm::radians(90.0f), glm::vec3(0.0f, 1.0f, 0.0f));

    Node* rect3_node = new Node(rect3_mat);

    rect3_node->add(rect3);

    viewer.scene_root->add(rect3_node);



    Shape* rect4 = new rectangleLight(phong_shader, glm::vec3(0.0f, 0.0f, 0.0f), glm::vec3(1.0f, 1.0f, 1.0f), glm::vec3(0.0f, 0.0f, 1.0f));

    glm::mat4 rect4_mat = glm::translate(glm::mat4(1.0f), glm::vec3(0.0f, 0.0f, -5.0f))
                          * glm::scale(glm::mat4(1.0f), 10.0f * glm::vec3(1.0f, 1.0f, 1.0f))
                          * glm::rotate(glm::mat4(1.0f), glm::radians(90.0f), glm::vec3(0.0f, 0.0f, 1.0f));

    Node* rect4_node = new Node(rect4_mat);

    rect4_node->add(rect4);


    viewer.scene_root->add(rect4_node);

//le ciel

    Shape* rect5 = new rectangleLight(phong_shader, glm::vec3(0.0f, 0.0f, 0.0f), glm::vec3(1.0f, 1.0f, 1.0f), glm::vec3(0.0f, 0.0f, 1.0f));

    glm::mat4 rect5_mat = glm::translate(glm::mat4(1.0f), glm::vec3(0.0f, 5.0f, 0.0f))
                          * glm::scale(glm::mat4(1.0f), 10.0f * glm::vec3(1.0f, 1.0f, 1.0f))
                          * glm::rotate(glm::mat4(1.0f), glm::radians(90.0f), glm::vec3(1.0f, 0.0f, 0.0f));

    Node* rect5_node = new Node(rect5_mat);

    rect5_node->add(rect5);


    viewer.scene_root->add(rect5_node);



    Finger* Rarm = new Finger(phong_shader, .1f);
    Node* Rshoulder = new Node(glm::translate(glm::mat4(1.0f), glm::vec3(-1.0f, -0.5f, 1.0f)));
    Rshoulder->add(Rarm->base);


    Finger* Larm = new Finger(phong_shader, .01f);
    Node* Lshoulder = new Node(glm::translate(glm::mat4(1.0f), glm::vec3(-1.0f, 0.0f, -1.0f)));
    Lshoulder->add(Larm->base);
    viewer.scene_root->add(Lshoulder);

    Finger* Rfing1 = new Finger(phong_shader, .01f);
    Node* Rfing1_node = new Node(glm::rotate(glm::mat4(1.0f), glm::radians(25.0f), glm::vec3(1.0f, 0.0f, 0.0f)));
    Rfing1_node->add(Rfing1->base);
    Finger* Rfing2 = new Finger(phong_shader, .01f);
    Node* Rfing2_node = new Node(glm::rotate(glm::mat4(1.0f), glm::radians(25.0f), glm::vec3(0.0f, 1.0f, 0.0f)));
    Rfing2_node->add(Rfing2->base);
    Finger* Rfing3 = new Finger(phong_shader, .01f);
    Node* Rfing3_node = new Node(glm::rotate(glm::mat4(1.0f), glm::radians(25.0f), glm::vec3(0.0f, 0.0f, 1.0f)));
    Rfing3_node->add(Rfing3->base);

    //alignJointsR(Rfing1,Rarm);
    //auto id = glm::mat4(1.0f);
    //glm::vec3 PosHand = Rarm->getHeadEgg()->get2Pos();
    //glm::vec3 PosFing = Rfing1->baseEgg->get1Pos();
    //glm::vec3 FingerToHand = glm::vec3(PosHand[0]-PosFing[0],PosHand[1]-PosFing[1],PosHand[2]-PosFing[2]);
    //glm::vec3 FingerToHand = Rarm->headEgg->get2Pos() - Rfing1->baseEgg->get1Pos();
    //Rfing1->base->move(translate(id, FingerToHand));
    //alignJointsR(*Rfing2,*Rarm);
    //alignJointsR(*Rfing3,*Rarm);

    Node* Rhand = new Node(glm::translate(glm::mat4(1.0f), glm::vec3(0.0f, 0.38f, 0.0f)));
    Rhand->add(Rfing1_node);
    Rhand->add(Rfing2_node);
    Rhand->add(Rfing3_node);

    Rshoulder->add(Rhand);




    viewer.scene_root->add(Rshoulder);

    viewer.run();
}

