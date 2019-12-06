#pragma once

#include <memory>
#include <string>

class Core;
class Resource
{
private:
	friend class Resources;
	std::weak_ptr<Core> core;

public:
	virtual void onLoad(const std::string &_path)
	{

	}
	std::shared_ptr<Core> getCore();

};