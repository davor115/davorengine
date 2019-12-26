#include "Exception.h"
#include <iostream> // How to get rid of these includes 
#include <list>


class Core;
class Component;
class Transform;

class Entity
{
private:
	//std::vector<std::shared_ptr<Component>> components;
	std::list<std::shared_ptr<Component>> components;
	std::weak_ptr<Core> core;	
	std::weak_ptr<Entity> self;

public:
	friend class Core;
	std::shared_ptr<Core> getCore();
	std::shared_ptr<Transform> getTransform();
	void Update();
	void Display();

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

	template<typename T, typename A>
	std::shared_ptr<T> addComponent(A a)
	{
		std::shared_ptr<T> rtn = std::make_shared<T>();

		rtn->entity = self;
		components.push_back(rtn);
		rtn->OnInit(a);

		return rtn;
	}

	template<typename T, typename A, typename B>
	std::shared_ptr<T> addComponent(A a, B b)
	{
		std::shared_ptr<T> rtn = std::make_shared<T>();

		rtn->entity = self;
		components.push_back(rtn);
		rtn->OnInit(a, b);

		return rtn;
	}

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
