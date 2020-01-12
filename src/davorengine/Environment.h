
class Environment
{
private:
	
	friend class Core;
	float deltaTime;
	float currentTime;
	float lastTime;

public:
	Environment();
	float getDeltaTime();
	
};
