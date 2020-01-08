#include "GUI.h"
#include "Material.h"
#include "Mesh.h"
#include "Core.h"


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
void GUI::setGUITexture(glm::vec4 position, std::shared_ptr<Material> texture)
{
	std::shared_ptr<rend::Context> context = getCore()->getContext();
	shader = context->createShader();
	shader->parse(src2);

	int sw = 640;
	int sh = 480;
	shader->setUniform("U_Projection", glm::ortho(0, sw, sh, 0));
	

	glm::mat4 mat(1.0f);

	mat = glm::translate(mat, glm::vec3(position.x, position.y, 0));
	mat = glm::scale(mat, glm::vec3(position.z, position.w, 1.0f));
	shader->setUniform("U_Model", mat);

	this->material = texture;
	mesh->mesh->setTexture("U_Texture", this->material->texture);


	shader->setMesh(mesh->mesh);
	shader->render();
}

void GUI::setMesh(std::shared_ptr<Mesh> _set)
{
	this->mesh = _set;
}