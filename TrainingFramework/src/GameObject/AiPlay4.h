#include "SpriteAnimation.h"
#include "ResourceManagers.h"
class SpriteAnimation;

class AiPlay4

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
	AiPlay4(float x, float y);
	~AiPlay4();
	//function
	void Move(int dir);
	void Dead(int die);
	// caculate function
	void UpdateAiPlay4Pos(GLfloat deltaTime);
	// sprite function
	void AiPlay4Update(GLfloat deltaTime);
	void AiPlay4Draw();
private:
	std::shared_ptr <SpriteAnimation> AiPlay4Sprite;
};