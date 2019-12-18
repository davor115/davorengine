#include "Mesh.h"
#include "Core.h"
#include <rend/rend.h>
#include <fstream>

void Mesh::onLoad(const char* path)
{
	std::shared_ptr<rend::Context> context = getCore()->getContext();
//	shader = context->createShader();
//	shader->parse(src);

	mesh = context->createMesh();
	{
		std::ifstream f;
		f.open(path);

		if(!f.is_open())
		{
			//TODO: Own Exception (not rend)
			throw rend::Exception("Failed to open file");
		}

		std::string obj;
		std::string line;

		while (!f.eof())
		{
			std::getline(f, line);
			obj += line + "\n";
		}

		mesh->parse(obj);
	}


}
