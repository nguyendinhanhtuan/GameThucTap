#include "SpriteAnimation.h"
#include "ResourceManagers.h"
#include <GameStates/GameStateMachine.h>

class SpriteAnimation;

class Slime

{
public:
	bool isDie;
	bool stable = true;
	GLfloat posX = 0.0f;
	GLfloat posY = 0.0f;
	GLfloat XX_Val = 0.0f;
	GLfloat m_DisapearTime;
	std::string SoundGun = "M4-shoot.wav";
	int state;
	float timer;
	//stat
	bool isPlayable;
	bool isFaceRight;
	//decletion
	Slime(float x, float y);
	~Slime();
	//function
	void Move(int dir);
	void Dead(int die);
	// caculate function
	void UpdateSlimePos(GLfloat deltaTime);
	// sprite function
	void SlimeUpdate(GLfloat deltaTime);
	void SlimeDraw();
private:
	std::shared_ptr <SpriteAnimation> SlimeSprite;
};