
#include "Component.h"
#include <glm/glm.hpp>
#include <GL/glew.h>
#include <SDL2/SDL.h>
#include <rend/rend.h>

class Camera : public Component
{
private:
	std::weak_ptr<Camera> self;

public:
	glm::mat4 getView();
	glm::mat4 getProjection();
	void OnInit();

};