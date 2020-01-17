#include "Exception.h"
#include <iostream>
#include <list>


class Core;
class Component;
class Transform;

	/**
	* \brief Entity Display, Update, Components...
	*/

class Entity
{
private:
	std::list<std::shared_ptr<Component>> components; ///< List of all the components inside an Entity.
	std::weak_ptr<Core> core;	///< A pointer of Core.
	std::weak_ptr<Entity> self; ///< A pointer to itself.

public:
	friend class Core; ///< Core can access all the member functions and variables of Entity.
	std::shared_ptr<Core> getCore(); ///< Returns Core.
	std::shared_ptr<Transform> getTransform();
	/**
	* \brief Updates all the components inside the Entity
	*
	* Core runs every frame the Update() member function of every Entity, and the Update() function runs the OnTick() function of every Component.
	*/
	void Update();
	void Display(); ///< Runs the onDisplay() member function of every Component inside the Entity.
	void Gui(); ///< Runs every frame the member function GUI() from the components.
	/**
	* \brief Returns the specified Component.
	*
	* The function loops through all the components creating a dynamic pointer cast of the desired Component.
	* if the Component is on the list, the created pointer will return a value, else it will return NULL and an exception will be thrown.
	*/
	template<typename T>
	std::shared_ptr<T> getComponent()
	{
		for (auto it = components.begin(); it != components.end(); it++)
		{
			std::shared_ptr<T> rtn = std::dynamic_pointer_cast<T>(*it);
			if (rtn)
			{
				return rtn;
			}
		}		

		throw davorengine::Exception("Couldn't find the component");
	}
	/**
	* \brief Add a component to the Entity.
	*
	* Creates a new shared pointer of the desired component. Sets the a reference to itself for the user to later find the Entity where the Component is attatched.
	* The component is also added to a list of components, the OnInit() function is run and the pointer is returned.
	*/

	template<typename T>
	std::shared_ptr<T> addComponent()
	{
		std::shared_ptr<T> rtn = std::make_shared<T>();		
		std::cout << "Now adding component: " << typeid(T).name() << std::endl;
		rtn->entity = self;
		components.push_back(rtn);
		rtn->OnInit();

		return rtn;
	}
	/**
	* \brief Add a component to the Entity taking one parameter for the OnInit() function.
	*
	* Creates a new shared pointer of the desired component. Sets the a reference to itself for the user to later find the Entity where the Component is attatched.
	* The component is also added to a list of components, the OnInit() function is run and the pointer is returned.
	*/
	template<typename T, typename A>
	std::shared_ptr<T> addComponent(A a)
	{
		std::shared_ptr<T> rtn = std::make_shared<T>();

		rtn->entity = self;
		components.push_back(rtn);
		rtn->OnInit(a);

		return rtn;
	}
	/**
	* \brief Add a component to the Entity taking two parameters for the OnInit() function.
	*
	* Creates a new shared pointer of the desired component. Sets the a reference to itself for the user to later find the Entity where the Component is attatched.
	* The component is also added to a list of components, the OnInit() function is run and the pointer is returned.
	*/
	template<typename T, typename A, typename B>
	std::shared_ptr<T> addComponent(A a, B b)
	{
		std::shared_ptr<T> rtn = std::make_shared<T>();

		rtn->entity = self;
		components.push_back(rtn);
		rtn->OnInit(a, b);

		return rtn;
	}
	/**
	* \brief Add a component to the Entity taking three parameters for the OnInit() function.
	*
	* Creates a new shared pointer of the desired component. Sets the a reference to itself for the user to later find the Entity where the Component is attatched.
	* The component is also added to a list of components, the OnInit() function is run and the pointer is returned.
	*/
	template<typename T, typename A, typename B, typename C>
	std::shared_ptr<T> addComponent(A a, B b, C c)
	{
		std::shared_ptr<T> rtn = std::make_shared<T>();

		rtn->entity = self;
		components.push_back(rtn);
		rtn->OnInit(a, b, c);

		return rtn;
	}
};
