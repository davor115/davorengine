#pragma once

#include <memory>
#include <string>

class Core;
class Resource
{
private:
	std::weak_ptr<Core> core;

public:
	void onLoad(const std::string &_path);
	std::shared_ptr<Core> getCore();

};