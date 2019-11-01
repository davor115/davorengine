#pragma once
#ifndef _ENTITY_
#define _ENTITY_

#include <iostream> // How to get rid of these includes 
#include <list>

#include "Exception.h"
class Core;
class Component;

class Entity
{
private:
	//std::vector<std::shared_ptr<Component>> components;
	std::list<std::shared_ptr<Component>> components;
	std::weak_ptr<Core> core;	


public:
	std::shared_ptr<Core> getCore();
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

		throw rend::Exception("Couldn't find the component");
	}


	template<typename T>
	std::shared_ptr<T> addComponent()
	{
		std::shared_ptr<T> rtn = std::make_shared<T>();		
		components.push_back(rtn);
		return rtn;
	}

	template<typename T, typename A>
	std::shared_ptr<T> addComponent(A a)
	{
		std::shared_ptr<T> rtn = std::make_shared<T>(a);
		components.push_back(rtn);
		return rtn;
	}

	template<typename T, typename A, typename B>
	std::shared_ptr<T> addComponent(A a, B b)
	{
		std::shared_ptr<T> rtn = std::make_shared<T>(a, b);
		components.push_back(rtn);
		return rtn;
	}

	template<typename T, typename A, typename B, typename C>
	std::shared_ptr<T> addComponent(A a, B b, C c)
	{
		std::shared_ptr<T> rtn = std::make_shared<T>(a, b, c);
		components.push_back(rtn);
		return rtn;
	}


};



#endif
