#include <davorengine/Engineincludes.h>
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
"" \
"varying vec4 ex_Color;" \
"" \
"void main()" \
"{" \
"  gl_Position = in_Projection * in_Model * vec4(in_Position, 1.0);" \
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

MeshRenderer::~MeshRenderer()
{
	SDL_DestroyWindow(window);
	SDL_Quit();
}


MeshRenderer::MeshRenderer()
{
	
	if (SDL_Init(SDL_INIT_VIDEO) < 0)
	{
		throw std::exception();
	}

	window = SDL_CreateWindow("DavorEngine",
		SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED,
		WINDOW_WIDTH, WINDOW_HEIGHT, SDL_WINDOW_RESIZABLE | SDL_WINDOW_OPENGL);

	if (!SDL_GL_CreateContext(window))
	{
		throw std::exception();
	}

	if (glewInit() != GLEW_OK)
	{
		throw std::exception();
	}
	
	/*
	positionsVboId = 0;

	// Create a new VBO on the GPU and bind it
	glGenBuffers(1, &positionsVboId);

	if (!positionsVboId)
	{
		throw std::exception();
	}

	glBindBuffer(GL_ARRAY_BUFFER, positionsVboId);

	// Upload a copy of the data from memory into the new VBO
	glBufferData(GL_ARRAY_BUFFER, sizeof(positions), positions, GL_STATIC_DRAW);

	// Reset the state
	glBindBuffer(GL_ARRAY_BUFFER, 0);

	colorsVboId = 0;

	// Create a colors VBO on the GPU and bind it
	glGenBuffers(1, &colorsVboId);

	if (!colorsVboId)
	{
		throw std::exception();
	}

	glBindBuffer(GL_ARRAY_BUFFER, colorsVboId);

	// Upload a copy of the data from memory into the new VBO
	glBufferData(GL_ARRAY_BUFFER, sizeof(colors), colors, GL_STATIC_DRAW);

	// Reset the state
	glBindBuffer(GL_ARRAY_BUFFER, 0);

	vaoId = 0;

	// Create a new VAO on the GPU and bind it
	glGenVertexArrays(1, &vaoId);

	if (!vaoId)
	{
		throw std::exception();
	}

	glBindVertexArray(vaoId);

	*/


	// Make the following:
	// in_Model = 
	std::shared_ptr<Context> context = Context::initialize();
	shader = context->createShader();
	shader->parse(src);


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
	
	/*
	// Bind the position VBO, assign it to position 0 on the bound VAO and flag it to be used
	glBindBuffer(GL_ARRAY_BUFFER, positionsVboId);
	glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 3 * sizeof(GLfloat), (void *)0);
	glEnableVertexAttribArray(0);

	// Bind the color VBO, assign it to position 1 on the bound VAO and flag it to be used
	glBindBuffer(GL_ARRAY_BUFFER, colorsVboId);
	glVertexAttribPointer(1, 4, GL_FLOAT, GL_FALSE, 4 * sizeof(GLfloat), (void *)0);
	glEnableVertexAttribArray(1);

	// Reset the state
	glBindBuffer(GL_ARRAY_BUFFER, 0);
	glBindVertexArray(0);


	GLuint vertexShaderId = glCreateShader(GL_VERTEX_SHADER);
	glShaderSource(vertexShaderId, 1, &vertexShaderSrc, NULL);
	glCompileShader(vertexShaderId);
	GLint success = 0;
	glGetShaderiv(vertexShaderId, GL_COMPILE_STATUS, &success);

	if (!success)
	{
		throw std::exception();
	}

	GLuint fragmentShaderId = glCreateShader(GL_FRAGMENT_SHADER);
	glShaderSource(fragmentShaderId, 1, &fragmentShaderSrc, NULL);
	glCompileShader(fragmentShaderId);
	glGetShaderiv(fragmentShaderId, GL_COMPILE_STATUS, &success);

	if (!success)
	{
		throw std::exception();
	}

	programId = glCreateProgram();

	glAttachShader(programId, vertexShaderId);
	glAttachShader(programId, fragmentShaderId);
	glBindAttribLocation(programId, 0, "in_Position");
	glBindAttribLocation(programId, 1, "in_Color");
	

	if (glGetError() != GL_NO_ERROR)
	{
		throw std::exception();
	}

	glLinkProgram(programId);
	glGetProgramiv(programId, GL_LINK_STATUS, &success);

	if (!success)
	{
		throw std::exception();
	}

	glDetachShader(programId, vertexShaderId);
	glDeleteShader(vertexShaderId);
	glDetachShader(programId, fragmentShaderId);
	glDeleteShader(fragmentShaderId);
	*/
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

	// TODO: Move SDL_Window to Core::initialize
	// TODO: Add Sound init to Core::initialize
	// TODO: Move clear to core
	// TODO: Move SDL_GL_SwapWindow to core
	// TODO: Remove old raw gl stuff out of here
	// TODO: View matrix
	// TODO: Move this class (TriangleRender), -> MeshRenderer -> engine
	//getEntity()->addComponent<SoundSource>(Resources::load<AudioClip>("sounds/bang"));

	glClearColor(1.0f, 0.0f, 0.0f, 1.0f);
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

	// VAO -> Comes from Mesh
	// Projection -> Camera
	// View -> Camera transform inverse
	// Model -> this. transform


	//	glUseProgram(programId);
	//	glBindVertexArray(vaoId);

		shader->setUniform("in_Projection", glm::perspective(glm::radians(45.0f), 1.0f, 0.1f, 100.0f));
		//shader->setUniform("in_View", getCore()->getCamera()->getTransform()->getView());
		shader->setUniform("in_Model", getTransform()->getMat());

		shader->render();

	//	glDrawArrays(GL_TRIANGLES, 0, 3);

	//	glBindVertexArray(0);
	//	glUseProgram(0);

	SDL_GL_SwapWindow(window);
}

