#include <list>
#include <memory>

#include "Resource.h"


class Resources : public Resource // Doing this so I can access path from Resource to save it.. either this or make weak_ptr of self? But then why do we got Resource.h?
{
private:
	std::list<std::shared_ptr<Resource>> resources;

public:
	template<typename T>
	std::shared_ptr<T> load(std::string _path)
	{
		std::shared_ptr<T> rtn = std::make_shared<T>;
		resources.push_back(rtn);
		path = _path;
	}

	template<typename T>
	std::shared_ptr<T> create()
	{
		std::shared_ptr<T> rtn = std::make_shared<T>;
		return rtn;
	}

};