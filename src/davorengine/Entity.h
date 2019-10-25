#pragma once
#ifndef _ENTITY_
#define _ENTITY_
class Component;
class Core;

class Entity
{
private:
	//std::vector<std::shared_ptr<Component>> components;
	std::list<std::shared_ptr<Component>> components;
	std::weak_ptr<Core> core;	


public:
	std::shared_ptr<Core> getCore();	

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