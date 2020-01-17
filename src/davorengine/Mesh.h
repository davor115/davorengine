
#include "Resource.h"

#include <rend/rend.h>

	/**
	* \brief Loading Mesh
	*/

class Mesh : public Resource
{
private:
	friend class MeshRenderer; ///< Allows the MeshRenderer class access all member functions and variables of Mesh
	friend class GUI; ///< Allows the GUI class access all member functions and variables of Mesh
	std::shared_ptr<rend::Mesh> mesh;
	
public:
	/**
	* \brief Loads the .obj file specified by its path
	*
	* A Mesh is initialized using the Context from Core. The .obj file is read using stbi_load and the string values acquired from the file are passed onto the Mesh.
	*/
	void onLoad(const char* path);
};