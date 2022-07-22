#include "SpriteAnimation.h"
#include "ResourceManagers.h"

class SpriteAnimation;
class BackGound

{
public:
	std::string name1 = "enemysound.wav";
	GLfloat posX = 0.0f;
	GLfloat posY = 0.0f;
	int state;
	float timer;
	//stat
	//decletion
	BackGound(float x, float y);
	~BackGound();
	//function
	void Move(int dir);
	void onDead();
	// caculate function
	void UpdateBackGoundPos(GLfloat deltaTime);
	// ActorACC function
	void BackGoundUpdate(GLfloat deltaTime);
	void BackGoundDraw();
private:
	std::shared_ptr <SpriteAnimation> BackGoundSprite;
};



