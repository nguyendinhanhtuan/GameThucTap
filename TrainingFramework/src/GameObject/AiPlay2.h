#include "SpriteAnimation.h"
#include "ResourceManagers.h"
class SpriteAnimation;

class AiPlay2

{
public:
	std::string name1 = "M4-shoot.wav";
	bool isDie;
	bool stable = true;
	GLfloat posX = 0.0f;
	GLfloat posY = 0.0f;
	GLfloat X_Val = 0.0f;
	GLfloat m_DisapearTime;
	bool isPlayable;
	bool isFaceRight;
	//stat
	//decletion
	AiPlay2(float x, float y);
	~AiPlay2();
	//function
	void Move(int dir);
	void Dead(int die);
	// caculate function
	void UpdateAiPlay2Pos(GLfloat deltaTime);
	// sprite function
	void AiPlay2Update(GLfloat deltaTime);
	void AiPlay2Draw();
private:
	std::shared_ptr <SpriteAnimation> AiPlay2Sprite;
};