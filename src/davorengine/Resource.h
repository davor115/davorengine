#pragma once

#include <memory>
#include <string>

class Core;
class Resource
{
private:
	friend class Resources; ///< Allows the Resources class to access all of Resource member variables and functions.
	std::weak_ptr<Core> core;
	std::string path;

public:
	virtual void onLoad(const char* _path)
	{
		
	}
	std::shared_ptr<Core> getCore(); //< Returns Core.

};