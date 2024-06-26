//
// Created by chloe on 11/06/2024.
//


#include <camera.h>
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <GLFW/glfw3.h>
#include <glm/vec3.hpp>




// An abstract camera class that processes input and calculates the corresponding Euler Angles, Vectors and Matrices for use in OpenGL
   Camera::Camera(glm::vec3 position , glm::vec3 up , float yaw, float pitch ) :
   Front(glm::vec3(0.0f, 0.0f, -1.0f)), MovementSpeed(1.0f), MouseSensitivity(0.1f), Zoom(45.0f)
   {
       this->Position = position;
       this->WorldUp = up;
       this->Yaw = yaw;
       this->Pitch = pitch;
       updateCameraVectors();
   }


   // returns the view matrix calculated using Euler Angles and the LookAt Matrix
   glm::mat4 Camera::GetViewMatrix()
   {
       return glm::lookAt(Position, Position + Front, Up);
   }


   glm::vec3 Camera::getPosition(){return Position;}
   float Camera::getYaw(){return Yaw;}


   // processes input received from any keyboard-like input system. Accepts input parameter in the form of camera defined ENUM (to abstract it from windowing systems)
   void Camera::ProcessKeyboard(Camera_Movement direction, float deltaTime)
   {
       float velocity = MovementSpeed * deltaTime;
       if (direction == FORWARD)
           Position += Front * velocity;
       if (direction == BACKWARD)
           Position -= Front * velocity;
       if (direction == LEFT)
           Position -= Right * velocity;
       if (direction == RIGHT)
           Position += Right * velocity;
       Position.y=0.0f; //keep the user on the ground level (no more flying)


       if(Position.x < -4.9f){
           Position.x = -4.9f;
       }
       if(Position.x > 4.9f){
           Position.x = 4.9f;
       }
       if(Position.z < -4.9f){
           Position.z = -4.9f;
       }
       if(Position.z > 4.9f){
           Position.z = 4.9f;
       }


   }


   // processes input received from a mouse input system. Expects the offset value in both the x and y direction.
   void Camera::ProcessMouseMovement(float xoffset, float yoffset, bool constrainPitch)
   {
       xoffset *= MouseSensitivity;
       yoffset *= MouseSensitivity;


       Yaw   += xoffset;
       Pitch += yoffset;


       // make sure that when pitch is out of bounds, screen doesn't get flipped
       if (constrainPitch)
       {
           if (Pitch > 89.0f)
               Pitch = 89.0f;
           if (Pitch < -89.0f)
               Pitch = -89.0f;
       }


       // update Front, Right and Up Vectors using the updated Euler angles
       updateCameraVectors();
   }




   // calculates the front vector from the Camera's (updated) Euler Angles
   void Camera::updateCameraVectors()
   {
       // calculate the new Front vector
       glm::vec3 front;
       front.x = cos(glm::radians(Yaw)) * cos(glm::radians(Pitch));
       front.y = sin(glm::radians(Pitch));
       front.z = sin(glm::radians(Yaw)) * cos(glm::radians(Pitch));
       Front = glm::normalize(front);
       // also re-calculate the Right and Up vector
       Right = glm::normalize(glm::cross(Front, WorldUp));  // normalize the vectors, because their length gets closer to 0 the more you look up or down which results in slower movement.
       Up    = glm::normalize(glm::cross(Right, Front));
   }

