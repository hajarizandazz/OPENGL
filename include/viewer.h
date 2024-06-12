#ifndef VIEWER_H
#define VIEWER_H

#include <vector>
#include <string>

#include <GL/glew.h>
#include <GLFW/glfw3.h>
#include "camera.h"
#include "shader.h"
#include "node.h"

class Viewer {
public:
    Viewer(int width=1500, int height=1000);

    void run();
    void on_key(int key,float currentFrame);
    void on_mouse(double xpos, double ypos);
    Node *scene_root;

private:
    GLFWwindow* win;
    Camera* cam=new Camera(glm::vec3(0.0f, 0.0f, 0.0f), glm::vec3(0.0f, 1.0f, 0.0f), -90.0f,0.0f);
    bool firstMouse;
    float lastX = 750, lastY = 500; //depends on the size of the window
    float deltaTime = 0.0f;	// Time between current frame and last frame
    float lastFrame = 0.0f;
    static void key_callback(GLFWwindow* window, int key, int scancode, int action, int mods);
    static void mouse_callback(GLFWwindow* window, double xpos, double ypos);
};

#endif // VIEWER_H
