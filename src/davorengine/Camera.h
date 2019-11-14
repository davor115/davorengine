#include <davorengine/Engineincludes.h>

class Camera : public Component
{
private:


public:
	glm::mat4 getView();
	glm::mat4 getProjection();


};