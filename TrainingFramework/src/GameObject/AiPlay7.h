#include "SpriteAnimation.h"
#include "ResourceManagers.h"
class SpriteAnimation;

class AiPlay7

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
	AiPlay7(float x, float y);
	~AiPlay7();
	//function
	void Move(int dir);
	void Dead(int die);
	// caculate function
	void UpdateAiPlay7Pos(GLfloat deltaTime);
	// sprite function
	void AiPlay7Update(GLfloat deltaTime);
	void AiPlay7Draw();
private:
	std::shared_ptr <SpriteAnimation> AiPlay7Sprite;
};
