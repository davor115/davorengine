
#include "Component.h"
#include <glm/glm.hpp>
#include <GL/glew.h>
#include <SDL2/SDL.h>
#include <rend/rend.h>

class Camera : public Component
{
private:
	std::weak_ptr<Camera> self;

	glm::mat4 _viewMatrix;
	int posx, posy;
	glm::vec3 camPos;
	glm::vec2 oldMousePosition;
	float _cameraAngleY;
	float _cameraAngleX;
	float mouseSpeed;

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