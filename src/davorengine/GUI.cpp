#include "GUI.h"
#include "Material.h"
#include "Mesh.h"
#include "Core.h"

#include "Entity.h"

const GLchar *src2 =
"\n#ifdef VERTEX\n" \
"attribute vec3 a_Position;" \
"attribute vec2 a_TexCoord;" \
"attribute vec3 a_Normal;" \
"" \
"uniform mat4 U_Projection;" \
"uniform mat4 U_Model;" \
"" \
"varying vec2 v_TexCoord;" \
"varying vec3 v_Normal;" \
"" \
"void main()" \
"{" \
"  gl_Position = U_Projection * U_Model * vec4(a_Position, 1.0);" \
"  v_TexCoord = a_TexCoord;" \
"  v_Normal = a_Normal;" \
"}" \
"" \
"\n#endif\n" \
"\n#ifdef FRAGMENT\n" \
"uniform sampler2D U_Texture;" \
"varying vec2 v_TexCoord;" \
"varying vec3 v_Normal;" \
"void main()" \
"{" \
"  gl_FragColor = texture2D(U_Texture, v_TexCoord);" \
"  if(gl_FragColor.x == 9) gl_FragColor.x = v_Normal.x;" \
"}" \
"\n#endif\n"
"";

GUI::GUI(std::shared_ptr<Core> _core)
{
	buffer = _core->getContext()->createBuffer();
	buffer->add(glm::vec2(0, 0));
	buffer->add(glm::vec2(0, 1));
	buffer->add(glm::vec2(1, 1));

	buffer->add(glm::vec2(1, 1));
	buffer->add(glm::vec2(1, 0));
	buffer->add(glm::vec2(0, 0));

	//shape->mesh = _core->getContext()->createMesh();
	shape->mesh->setBuffer("a_Position", buffer);
	
}


void GUI::OnInit()
{
		//getCore()->Gui = getEntity()->getComponent<GUI>();
		shape->mesh = getCore()->getContext()->createMesh();
}

void GUI::setGUITexture(glm::vec4 position, std::shared_ptr<Material> texture)
{
	std::shared_ptr<rend::Context> context = getCore()->getContext();
	shader = context->createShader();
	shader->parse(src2);

	float sw = 640.0f;
	float sh = 480.0f;
	shader->setUniform("U_Projection", glm::ortho(0.0f, sw, sh, 0.0f, -1.0f, 1.0f));
	

	glm::mat4 mat(1.0f);

	mat = glm::translate(mat, glm::vec3(position.x, position.y, 0));
	mat = glm::scale(mat, glm::vec3(position.z, position.w, 1.0f));
	shader->setUniform("U_Model", mat);

	this->material = texture;
	shape->mesh->setTexture("U_Texture", this->material->texture);


	shader->setMesh(shape->mesh);
	shader->render();
}

void GUI::setMesh(std::shared_ptr<Mesh> _set)
{
	this->shape = _set;
}