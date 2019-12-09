#include <list>
#include <memory>

class Core;
class Resource;
class Resources
{
private:
	friend class Core;
	std::list<std::shared_ptr<Resource>> resources;
	std::weak_ptr<Core> core;
public:
	template<typename T>
	std::shared_ptr<T> load(const char* _path)
	{
		std::shared_ptr<T> rtn = std::make_shared<T>();
		rtn->core = core;
		rtn->onLoad(_path);
		resources.push_back(rtn);
		return rtn;
	}

	/*template<typename T>
	std::shared_ptr<T> create()
	{
		std::shared_ptr<T> rtn = std::make_shared<T>;
		return rtn;
	}*/

};