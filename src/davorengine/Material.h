
#include "Resource.h"

class Material : public Resource
{
private:
	friend class MeshRenderer; ///< Allows the MeshRenderer class access all member functions and variables of Material
	friend class GUI; ///< Allows the GUI class access all member functions and variables of Material
	std::shared_ptr<rend::Shader> shader;
	std::shared_ptr<rend::Texture> texture;
	
public:
	/**
	* \brief Loads an Image into the Texture.
	*
	* The function takes a string parameter as the destination of the image file. Then it gets Context from Core and uses it to run a function that creates a Texture.
	* The shared pointer of texture is filled with the pixel values from the Image.
	*/
	void onLoad(const char* path);


};