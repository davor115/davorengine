
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
"attribute vec3 a_Position;" \
"attribute vec2 a_TexCoord;" \
"attribute vec3 a_Normal;" \
"" \
"uniform mat4 in_Projection;" \
"uniform mat4 in_Model;" \
"uniform mat4 in_View;" \
"" \
"varying vec2 v_TexCoord;" \
"varying vec3 v_Normal;" \
"" \
"void main()" \
"{" \
"  gl_Position = in_Projection * in_View * in_Model * vec4(a_Position, 1.0);" \
"  v_TexCoord = a_TexCoord;" \
"  v_Normal = a_Normal;" \
"}" \
"" \
"\n#endif\n" \
"\n#ifdef FRAGMENT\n" \
"uniform sampler2D u_Texture;" \
"varying vec2 v_TexCoord;" \
"varying vec3 v_Normal;" \
"void main()" \
"{" \
"  gl_FragColor = texture2D(u_Texture, v_TexCoord);" \
"  if(gl_FragColor.x == 9) gl_FragColor.x = v_Normal.x;" \
"}" \
"\n#endif\n"
"";

//  gl_FragColor = vec4(v_TexCoord, 0, 1);

//
//const char* obj =
//"v -1 1 0           \n" \
//"v -1 -1 0          \n" \
//"v 1 -1 0           \n" \
//"v 1 1 0            \n" \
//"                   \n" \
//"vt 0 1             \n" \
//"vt 0 0             \n" \
//"vt 1 0             \n" \
//"vt 1 1             \n" \
//"                   \n" \
//"f 1/1 2/2 3/3 4/4  \n" \
//"                   \n";

MeshRenderer::MeshRenderer()
{	
	// Since the .obj gives the info below, we don't need to set it ourselves.

	//buffer = context->createBuffer();
	//buffer->add(vec3(0.0f, 0.5f, 0.0f));
	//buffer->add(vec3(-0.5f, -0.5f, 0.0f));
	//buffer->add(vec3(0.5f, -0.5f, 0.0f));
	//shader->setAttribute("in_Position", buffer);

	//buffer = context->createBuffer();
	//buffer->add(vec4(1.0f, 0.0f, 0.0f, 1.0f));
	//buffer->add(vec4(0.0f, 1.0f, 0.0f, 1.0f));
	//buffer->add(vec4(0.0f, 0.0f, 1.0f, 1.0f));
	//shader->setAttribute("in_Color", buffer);
	
}

//void MeshRenderer::LoadObject(const char* path)
//{ 
//	std::shared_ptr<Context> context = Context::initialize();
//	shader = context->createShader();
//	shader->parse(src);
//
//	shape = context->createMesh();
//	{
//		std::ifstream f;
//		f.open(path);
//		std::string obj;
//		std::string line;
//
//		while (!f.eof())
//		{
//			std::getline(f, line);
//			obj += line + "\n";
//		}
//
//		shape->parse(obj);
//	}
//}

//void MeshRenderer::LoadTexture(const char* path)
//{
//	std::shared_ptr<Context> context = Context::initialize();
//	texture = context->createTexture();
//	{
//		int w = 0;
//		int h = 0;
//		int bpp = 0;
//
//		unsigned char *data = stbi_load(path,
//			&w, &h, &bpp, 3);
//
//		if (!data)
//		{
//			throw rend::Exception("Failed to open image");
//		}
//
//		texture->setSize(w, h);
//
//		for (int y = 0; y < h; y++)
//		{
//			for (int x = 0; x < w; x++)
//			{
//				int r = y * w * 3 + x * 3;
//
//				texture->setPixel(x, y, vec3(
//					data[r] / 255.0f,
//					data[r + 1] / 255.0f,
//					data[r + 2] / 255.0f));
//			}
//		}
//		stbi_image_free(data);
//	}
//
//	shape->setTexture("u_Texture", texture);
//
//}

void MeshRenderer::setMesh(std::shared_ptr<Mesh> shape)
{
	this->shape = shape;
}

void MeshRenderer::setMaterial(std::shared_ptr<Material> material)
{
	this->texture = material;
	this->shape->mesh->setTexture("u_Texture", texture->texture);
}

void MeshRenderer::OnInit()
{
	// Create one in core.
	std::shared_ptr<Context> context = getCore()->getContext();
	shader = context->createShader();
	shader->parse(src);

}

void MeshRenderer::OnDisplay()
{
	
	// TODO: Move SDL_Window to Core::initialize -> Problem, since Core is static and Start is not, how do I use window variable in both? -> Fixed.
	// TODO: Add Sound init to Core::initialize
	// TODO: Move clear to core -> Done 
	// TODO: Move SDL_GL_SwapWindow to core -> Done
	// TODO: Remove old raw gl stuff out of here -> Done
	// TODO: View matrix -> Done
	// TODO: Move this class (TriangleRender), -> MeshRenderer -> engine -> Done
	//getEntity()->addComponent<SoundSource>(Resources::load<AudioClip>("sounds/bang"));

	
	// VAO -> Comes from Mesh
	// Projection -> Camera
	// View -> Camera transform inverse
	// Model -> this. transform

	shader->setUniform("in_Projection", getCore()->getCurrentCamera()->getProjection());
	shader->setUniform("in_View", getCore()->getCurrentCamera()->getView()); 


	shader->setUniform("in_Model", getTransform()->getMat());


	shader->setMesh(shape->mesh);

	shader->render();

//	SDL_GL_SwapWindow(window);
}
