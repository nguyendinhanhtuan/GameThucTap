#include "SpriteAnimation.h"
#include "ResourceManagers.h"

class SpriteAnimation;
class ActorACC

{
public:
	GLfloat posX = 0.0f;
	GLfloat posY = 0.0f;
	int state;
	float timer;
	//decletion
	ActorACC(float x, float y);
	~ActorACC();
	//function
	void Move(int dir);
	// caculate function
	void UpdateActorACCPos(GLfloat deltaTime);
	// ActorACC function
	void ActorACCUpdate(GLfloat deltaTime);
	void ActorACCDraw();
private:
	std::shared_ptr <SpriteAnimation> ActorACCSprite;
};


