
#include "Component.h"
#include <glm/glm.hpp>
#include <rend/rend.h>

class Material;
class Mesh;

	/**
	* \brief GUI, GUI Set Texture..
	*/

class GUI : public Component
{
private:
	std::shared_ptr<rend::Context> context; ///< The Context from Core will be saved here for reference.
	std::shared_ptr<Entity> myGUI; ///< An temporary Entity to access Core from other functions.
	std::shared_ptr<Mesh> shape; ///< The shape of the GUI
	glm::mat4 projection; ///< The ortographic projection matrix
	std::shared_ptr<rend::Shader> shader; ///< GUI Shader
	std::shared_ptr<rend::Buffer> buffer;
	
	std::shared_ptr<Material> material; ///< The texture for the GUI.
public:
	/**
	* \brief GUI construction for Initialization of buffers.
	*
	* In this Constructor the Buffer is initialized and the mesh set for the Texture to fit in the size of the GUI and position in the right place.
	*/
	GUI(std::shared_ptr<Core> _core);
	/**
	* \brief Set the Texture on the GUI, the Model and the Projection matrix.
	*/
	void setGUITexture(glm::vec4 position, std::shared_ptr<Material> texture);
	void setMesh(std::shared_ptr<Mesh> _set); ///< Set the Mesh
	void OnInit();

};