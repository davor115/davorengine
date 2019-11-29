#include "Mesh.h"
#include <fstream>

void ShapeMesh::onLoad(const std::string &path)
{
	std::shared_ptr<rend::Context> context = getContext();
//	shader = context->createShader();
//	shader->parse(src);

	mesh = context->createMesh();
	{
		std::ifstream f;
		f.open(path);
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