

#include "Core.h"
#include <rend/rend.h>
class Resource;

class Resources : public Core
{
private:
	std::list<std::shared_ptr<Resource>> resources;

public:
	template<typename T>
	std::shared_ptr<T> load(std::string _path)
	{
		std::shared_ptr<T> rtn = std::make_shared<T>;
		resources.push_back(rtn);
	}

	/*template<typename T>
	std::shared_ptr<T> create()
	{
		std::shared_ptr<T> rtn = std::make_shared<T>;
		return rtn;
	}*/

};