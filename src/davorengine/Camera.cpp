#include "Camera.h"
#include "Transform.h"
#include "Core.h"
#include "Entity.h"
void Camera::OnInit()
{
	std::cout << "Camera on" << std::endl;
	getCore()->currentCamera = getEntity()->getComponent<Camera>();
	mouseSpeed = 0.005f;
	_cameraAngleX = 3.14f;
	_cameraAngleY = 0.0f;
	oldMousePosition = glm::vec2(0);

}

glm::mat4 Camera::getView()
{
	//glm::mat4 rtn = getTransform()->getMat();
	return _viewMatrix;
}
glm::mat4 Camera::getProjection()
{
	glm::mat4 rtn = glm::perspective(glm::radians(45.0f), 1.0f, 0.1f, 100.0f);
	return rtn;
}

void Camera::OnTick()
{
	camPos = getEntity()->getComponent<Transform>()->getPosition();
	int Mid_X = 320;
	int Mid_Y = 240;
	// move the mouse back to the middle of the screen each frame
	SDL_WarpMouseInWindow(NULL, 320, 240);
	SDL_ShowCursor(false);
	// get the current position of the cursor
	SDL_GetMouseState(&posx, &posy);

	float diff_x = Mid_X - oldMousePosition.x;
	float diff_y = Mid_Y - oldMousePosition.y;

	_cameraAngleX += mouseSpeed * (posx - oldMousePosition.x + diff_x);
	_cameraAngleY += mouseSpeed * (posy - oldMousePosition.y + diff_y);
	oldMousePosition = glm::vec2(posx, posy);

	glm::vec3 direction(cos(_cameraAngleY) * sin(_cameraAngleX), sin(_cameraAngleY), cos(_cameraAngleY) * cos(_cameraAngleX));
	glm::vec3 right = glm::vec3(sin(_cameraAngleX - 3.14f / 2.0f), 0, cos(_cameraAngleX - 3.14f / 2.0f));
	glm::vec3 up = glm::cross(right, direction);

	cam_direction = direction;
	cam_right = right;
	
	_viewMatrix = glm::lookAt(camPos, camPos + direction, up);

	
}
