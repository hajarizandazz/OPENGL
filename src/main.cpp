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

#ifndef SHADER_DIR
#error "SHADER_DIR not defined"
#endif

#ifndef TEXTURE_DIR
#error "TEXTURE_DIR not defined"
#endif

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

    /*Shape* palmR = new LightingSphere(phong_shader, glm::vec3(0.0f, 1.0f, 0.0f), glm::vec3(1.0f, 1.0f, 1.0f), glm::vec3(0.0f, 0.0f, 1.0f));
    glm::mat4 palmR_mat = glm::translate(glm::mat4(1.0f), glm::vec3(1.0f, 0.0f, -4.0f))
        * glm::scale(glm::mat4(1.0f), glm::vec3(1.0f, 1.0f, 1.0f))
        * glm::rotate(glm::mat4(1.0f), glm::radians(0.0f), glm::vec3(1.0f, 0.0f, 0.0f));
    
    Node* palmR_node = new Node(palmR_mat);
    palmR_node->add(palmR);

    viewer.scene_root->add(palmR_node);*/

    Texture *texture = new Texture(texture_dir + "texturesablelisse.png");

    Shape* text = new RectangleText(texture_shader,texture);

    glm::mat4 text_mat = glm::translate(glm::mat4(1.0f), glm::vec3(2.0f, -4.0f, 2.0f))
        * glm::scale(glm::mat4(1.0f), glm::vec3(1.0f, 1.0f, 1.0f))
        * glm::rotate(glm::mat4(1.0f), glm::radians(90.0f), glm::vec3(1.0f, 0.0f, 0.0f));

    Node* text_node = new Node(text_mat);

    text_node->add(text);

    viewer.scene_root->add(text);

    Finger* Rarm = new Finger(phong_shader, .01f);
    Node* Rshoulder = new Node(glm::translate(glm::mat4(1.0f), glm::vec3(1.0f, 0.0f, 1.0f)));
    Rshoulder->add(Rarm->base);
    viewer.scene_root->add(Rshoulder);

    Finger* Larm = new Finger(phong_shader, .01f);
    Node* Lshoulder = new Node(glm::translate(glm::mat4(1.0f), glm::vec3(1.0f, 0.0f, 1.0f)));
    Lshoulder->add(Larm->base);
    viewer.scene_root->add(Lshoulder);

    Finger* Rfing1 = new Finger(phong_shader, .01f);
    Finger* Rfing2 = new Finger(phong_shader, .01f);
    Finger* Rfing3 = new Finger(phong_shader, .01f);

    Node* Rhand = new Node(glm::translate(glm::mat4(1.0f), glm::vec3(1.0f, 0.0f, 1.0f)));
    Rhand->add(Rfing1->base);
    Rhand->add(Rfing2->base);
    Rhand->add(Rfing3->base);
    viewer.scene_root->add(Rhand);
    /*
    auto color = glm::vec3(0.0f, 1.0f, 1.0f);
    auto lightpos = glm::vec3(1.0f, 1.0f, 1.0f);
    Egg* test = new Egg(0.05f, phong_shader, lightpos, color);
    Node* flatEgg = new Node(glm::rotate(glm::mat4(1.0f), glm::radians(90.0f), glm::vec3(1.0f, 0.0f, 0.0f)));
    flatEgg->add(test->node);
    viewer.scene_root->add(flatEgg);*/

    viewer.run();
}