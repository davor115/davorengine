
#include "Resource.h"

class Material : public Resource
{
private:
	std::shared_ptr<rend::Shader> shader;
	std::shared_ptr<rend::Texture> texture;

public:
	void onLoad(const std::string &path);


};