
#include "Resource.h"

class Material : public Resource
{
private:
	friend class MeshRenderer;
	std::shared_ptr<rend::Shader> shader;
	std::shared_ptr<rend::Texture> texture;

public:
	void onLoad(const char* path);


};