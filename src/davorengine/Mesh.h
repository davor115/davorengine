
#include "Resource.h"

#include <rend/rend.h>

class Mesh : public Resource
{
private:
	friend class MeshRenderer;
	friend class GUI;
	std::shared_ptr<rend::Mesh> mesh;
//	std::shared_ptr<rend::Shader> shader;
	
public:
	void onLoad(const char* path);
};