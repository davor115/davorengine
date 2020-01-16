
#include "Component.h"
#include <glm/glm.hpp>
class Transform : public Component
{
private:
	glm::vec3 position; ///< The position values of the Entity
	glm::vec3 rotation; ///< The rotation values of the Entity
	glm::vec3 scale; ///< The scale values of the Entity

public:
	void OnInit(); ///< Sets the default values of Scale.

	 /**
	* \brief Returns the Model Matrix of the Entity.
	*
	* The member function getMat() creates an identity, then in order (using the position, rotation and scale variable)
	* applies translation, rotation, and scale. Afterwards the model matrix is returned.
	*/
	glm::mat4 getMat();


	void setPosition(glm::vec3 _pos); ///< Sets the position variable.
	void setRotation(glm::vec3 _rot); ///< Sets the rotation variable.
	void setScale(glm::vec3 _s); ///< Sets the scale variable.
	
	void Translate(glm::vec3 _val); ///< Adds a vector3 onto the position variable.
	void Rotate(glm::vec3 _rotVal); ///< Adds a vector3 onto the rotation variable.

	 /**
	* \brief Translates an Entity taking into consideration its rotation.
	*
	* The function Forward() creates a 4x4 matrix, in order it applies rotation onto it, then translation and lastly scale.
	* it then multiplies this matrix by a vector4 to specify the translation axis and default amount. 
	* This translation allows the Entity to always move in the Forward direction according to its rotation.
	*/
	glm::vec3 Forward();
	/**
   * \brief Translates an Entity taking into consideration its rotation.
   *
   * The function Left() creates a 4x4 matrix, in order it applies rotation onto it, then translation and lastly scale.
   * it then multiplies this matrix by a vector4 to specify the translation axis and default amount.
   * This translation allows the Entity to always move in the Left direction according to its rotation.
   */
	glm::vec3 Left();
	/**
   * \brief Translates an Entity taking into consideration its rotation.
   *
   * The function Right() creates a 4x4 matrix, in order it applies rotation onto it, then translation and lastly scale.
   * it then multiplies this matrix by a vector4 to specify the translation axis and default amount.
   * This translation allows the Entity to always move in the Right direction according to its rotation.
   */
	glm::vec3 Right();
	/**
   * \brief Translates an Entity taking into consideration its rotation.
   *
   * The function Up() creates a 4x4 matrix, in order it applies rotation onto it, then translation and lastly scale.
   * it then multiplies this matrix by a vector4 to specify the translation axis and default amount.
   * This translation allows the Entity to always move in the Up direction according to its rotation.
   */
	glm::vec3 Up();
	/**
   * \brief Translates an Entity taking into consideration its rotation.
   *
   * The function Down() creates a 4x4 matrix, in order it applies rotation onto it, then translation and lastly scale.
   * it then multiplies this matrix by a vector4 to specify the translation axis and default amount.
   * This translation allows the Entity to always move in the Down direction according to its rotation.
   */
	glm::vec3 Down();

	glm::vec3 getPosition(); ///< Gets the position variable. Returns a vector3.
	glm::vec3 getRotation(); ///< Gets the rotation variable. Returns a vector3.
	glm::vec3 getSize(); ///< Gets the scale variable. Returns a vector3.
};
