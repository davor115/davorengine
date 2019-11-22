#include "Engineincludes.h"
#include <fstream>
using namespace davorengine;
/// Use this.
/*
#include <davorengine/davorengine.h>

class TriangleRenderer : public Component
{
  TriangleRenderer(); // Init SDL, VBOs, Shader
  void onDisplay(); // bind vao, shader, glDrawArrays
};

////



void Player::onUpdate()
{
  //if(getEntity()->getCore()->getKeyboard()->isKeyDown('w'))
  if(getKeyboard()->isKeyDown('w'))
  {
    // move forwards
  }
}
*/

// Put these ones in actual variables.

const GLfloat positions[] = {
0.0f, 0.5f, 0.0f,
-0.5f, -0.5f, 0.0f,
0.5f, -0.5f, 0.0f
};

const GLfloat colors[] = {
  1.0f, 0.0f, 0.0f, 1.0f,
  0.0f, 1.0f, 0.0f, 1.0f,
  0.0f, 0.0f, 1.0f, 1.0f
};

const GLchar *src =
"\n#ifdef VERTEX\n" \
"attribute vec3 in_Position;" \
"attribute vec4 in_Color;" \
"" \
"uniform mat4 in_Projection;" \
"uniform mat4 in_Model;" \
"uniform mat4 in_View;" \
"" \
"varying vec4 ex_Color;" \
"" \
"void main()" \
"{" \
"  gl_Position = in_Projection * in_View * in_Model * vec4(in_Position, 1.0);" \
"  ex_Color = in_Color;" \
"}" \
"" \
"\n#endif\n" \
"\n#ifdef FRAGMENT\n" \
"varying vec4 ex_Color;" \
"void main()" \
"{" \
"  gl_FragColor = ex_Color;" \
"}" \
"\n#endif\n"
"";

MeshRenderer::MeshRenderer()
{

	// Make the following:
	// in_Model = 
	std::shared_ptr<Context> context = Context::initialize();
	shader = context->createShader();
	shader->parse(src);

	shape = context->createMesh();

	{
		std::ifstream f("share/rend/samples/curuthers/curuthers.obj");
		std::string obj;
		std::string line;

		while (!f.eof())
		{
			std::getline(f, line);
			obj += line + "\n";
		}
		shape->parse(obj);

	}


	buffer = context->createBuffer();
	buffer->add(vec3(0.0f, 0.5f, 0.0f));
	buffer->add(vec3(-0.5f, -0.5f, 0.0f));
	buffer->add(vec3(0.5f, -0.5f, 0.0f));
	shader->setAttribute("in_Position", buffer);

	buffer = context->createBuffer();
	buffer->add(vec4(1.0f, 0.0f, 0.0f, 1.0f));
	buffer->add(vec4(0.0f, 1.0f, 0.0f, 1.0f));
	buffer->add(vec4(0.0f, 0.0f, 1.0f, 1.0f));
	shader->setAttribute("in_Color", buffer);


	
}

void MeshRenderer::OnDisplay()
{

	SDL_Event event = { 0 };

	while (SDL_PollEvent(&event))
	{
		if (event.type == SDL_QUIT)
		{
			throw std::exception();
		}
	}

	// TODO: Move SDL_Window to Core::initialize -> Problem, since Core is static and Start is not, how do I use window variable in both? -> Fixed.
	// TODO: Add Sound init to Core::initialize
	// TODO: Move clear to core -> Done 
	// TODO: Move SDL_GL_SwapWindow to core -> Done
	// TODO: Remove old raw gl stuff out of here -> Done
	// TODO: View matrix
	// TODO: Move this class (TriangleRender), -> MeshRenderer -> engine
	//getEntity()->addComponent<SoundSource>(Resources::load<AudioClip>("sounds/bang"));

	
	// VAO -> Comes from Mesh
	// Projection -> Camera
	// View -> Camera transform inverse
	// Model -> this. transform

	shader->setUniform("in_Projection", getCore()->getCurrentCamera()->getProjection()); // This is not working..
	shader->setUniform("in_View", getCore()->getCurrentCamera()->getView()); // Figure out how to get the camera then uncomment this line.
	shader->setUniform("in_Model", getTransform()->getMat());
	

	shader->setMesh(shape);

	shader->render();

//	SDL_GL_SwapWindow(window);
}

