#pragma once
#ifndef _ENTITY_
#define _ENTITY_

class Entity
{
private:
	std::vector<std::shared_ptr<Component>> components;
	std::weak_ptr<Core> core;


public:
	std::shared_ptr<Core> getCore();

	
	

	template<typename T>
	std::shared_ptr<T> addComponent(T)
	{

	}



};



#endif