
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
///! The Vertex and Fragment Shader
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
	std::shared_ptr<Context> context = getCore()->getContext();
	shader = context->createShader();
	shader->parse(src);

}

void MeshRenderer::OnDisplay()
{
	
	shader->setUniform("in_Projection", getCore()->getCurrentCamera()->getProjection());
	shader->setUniform("in_View", getCore()->getCurrentCamera()->getView()); 


	shader->setUniform("in_Model", getTransform()->getMat());


	shader->setMesh(shape->mesh);

	shader->render();
}
