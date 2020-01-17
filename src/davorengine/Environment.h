	/**
	* \brief Calculate deltaTime
	*/
class Environment
{
private:
	
	friend class Core; ///< The Core class can access all the member variables and functions of the Environment class.
	float deltaTime;
	float currentTime;
	float lastTime;

public:
	Environment(); ///< Initliaze the variables to default values.
	float getDeltaTime(); ///< Get the deltaTime value
	void UpdateEnvironment(); ///< Calculate deltaTime.
	
};
