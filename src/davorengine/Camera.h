
#include "Component.h"
#include <glm/glm.hpp>
#include <GL/glew.h>
#include <SDL2/SDL.h>
#include <rend/rend.h>

class Camera : public Component
{
private:
	std::weak_ptr<Camera> self;  ///< Saves a pointer to reference itself.

	glm::mat4 _viewMatrix;  ///< The view matrix for the camera.
	int posx, posy;
	glm::vec3 camPos;  ///< The position of the camera in the world.
	glm::vec2 oldMousePosition;
	float _cameraAngleY;
	float _cameraAngleX;
	float mouseSpeed;  ///< Mouse sensitivity.

	glm::vec3 cam_direction;
	glm::vec3 cam_right;

public:
	glm::mat4 getView(); ///< Returns the camera's viewing matrix
	glm::mat4 getProjection(); ///< Creates and returns the camera's projection matrix. This sets the near and far planes, fov, and scale (4:3, 16:9, 16:10) based on the screen's resolution.
	void OnInit(); ///< A function that runs once the component is added. This function is used to initialize the variables.
	void OnTick(); ///< OnTick runs the code every frame.


	glm::vec3 getCamDirection(); ///< Returns the camera's direction, used for the translation in the forward and backwards direction.
	glm::vec3 getCamRight(); ///< Returns the camera's right direction, used for the translation in the right and left direction.
};