#include "Camera.h"
#include "Transform.h"


void Camera::OnInit()
{
	std::cout << "Camera on" << std::endl;
	
}

glm::mat4 Camera::getView()
{
	glm::mat4 rtn = getTransform()->getMat();
	return glm::inverse(rtn);
}
glm::mat4 Camera::getProjection()
{
	glm::mat4 rtn = glm::perspective(glm::radians(45.0f), 1.0f, 0.1f, 100.0f);
	return rtn;
}

