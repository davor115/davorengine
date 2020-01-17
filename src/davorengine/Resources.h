#include <list>
#include <memory>

class Core;
class Resource;
	/**
	* \brief Loading Resources
	*/

class Resources
{
private:
	friend class Core;
	std::list<std::shared_ptr<Resource>> resources;
	std::weak_ptr<Core> core;


public:

	/**
	* \brief Sends the information of the destination of the file into the Material/Mesh Classes and returns a pointer to the Class.
	*
	* The load() function searches for the list of Resources in case the Texture or Material the user wants to load was already loaded
	* If the Material or Texture were loaded then it returns it, else it will create a new shared pointer; save the path information onto it;
	* save the address of Core; call the load function passing the path of the file; saving the current pointer onto the list of resources and lastly returning it.
	*/

	template<typename T>
	std::shared_ptr<T> load(const char* _path)
	{
		std::shared_ptr<T> rtnTmp;
		for (auto it = resources.begin(); it != resources.end(); it++)
		{
			std::shared_ptr<T> rtn = std::dynamic_pointer_cast<T>(*it);
			if (rtn && rtn->path == _path)
			{
				rtnTmp = rtn;
				return rtnTmp;
			}			
		}	
		rtnTmp = std::make_shared<T>();
		rtnTmp->path = _path;
		rtnTmp->core = core;
		rtnTmp->onLoad(_path);
		resources.push_back(rtnTmp);
		return rtnTmp;
	}

};