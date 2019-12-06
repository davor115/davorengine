#include "Resource.h"

std::shared_ptr<Core> Resource::getCore()
{
	return core.lock();
}
