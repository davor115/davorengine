#include <iostream>
#include <list>
#include <vector>


class Entity;
class Environment;
class Keyboard;
class Transform;

class Core
{
private:
	std::weak_ptr<Core> self;
	std::shared_ptr<Environment> environment;
	//std::vector<std::shared_ptr<Entity>> entities;
	std::list<std::shared_ptr<Entity>> entities;
	std::shared_ptr<Keyboard> keyboard;
	bool running;

public:
	static std::shared_ptr<Core> initialize();
	void Start();
	void Stop();
	std::shared_ptr<Entity> addEntity();

};