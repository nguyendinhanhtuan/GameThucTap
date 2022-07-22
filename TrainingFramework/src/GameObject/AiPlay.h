#include "SpriteAnimation.h"
#include "ResourceManagers.h"
class SpriteAnimation;

class AiPlay

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
	AiPlay(float x, float y);
	~AiPlay();
	//function
	void Move(int dir);
	void Dead(int die);
	// caculate function
	void UpdateAiPlayPos(GLfloat deltaTime);
	// sprite function
	void AiPlayUpdate(GLfloat deltaTime);
	void AiPlayDraw();
private:
	std::shared_ptr <SpriteAnimation> AiPlaySprite;
};

