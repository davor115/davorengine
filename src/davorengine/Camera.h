
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
	glm::mat4 getView();
	glm::mat4 getProjection();
	void OnInit();
	void OnTick();


	glm::vec3 getCamDirection() { return cam_direction; }
	glm::vec3 getCamRight() { return cam_right; }
};