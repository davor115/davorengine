/// Use this.
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
