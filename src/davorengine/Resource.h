#include "Resources.h"

class Core;

class Resource : public Resources
{
private:
	std::weak_ptr<Core> core;

public:
	void onLoad(const std::string &_path);

};