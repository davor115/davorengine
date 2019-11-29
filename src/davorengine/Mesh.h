
#include "Resource.h"

class ShapeMesh : public Resource
{
private:
	std::shared_ptr<rend::Mesh> mesh;
//	std::shared_ptr<rend::Shader> shader;
	
public:
	void onLoad(const std::string &path);
};