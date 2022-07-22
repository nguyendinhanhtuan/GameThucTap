#include "SpriteAnimation.h"
#include "ResourceManagers.h"
class SpriteAnimation;

class AiPlay3

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
	AiPlay3(float x, float y);
	~AiPlay3();
	//function
	void Move(int dir);
	void Dead(int die);
	// caculate function
	void UpdateAiPlay3Pos(GLfloat deltaTime);
	// sprite function
	void AiPlay3Update(GLfloat deltaTime);
	void AiPlay3Draw();
private:
	std::shared_ptr <SpriteAnimation> AiPlay3Sprite;
};