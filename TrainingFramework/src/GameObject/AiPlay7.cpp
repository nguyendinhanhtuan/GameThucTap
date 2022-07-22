#include "AiPlay7.h"
#include "SpriteAnimation.h"

AiPlay7::AiPlay7(float x, float y)
{
	m_DisapearTime = 0.8f;
	isDie = false;
	posX = x;
	posY = y;
	auto model = ResourceManagers::GetInstance()->GetModel("Sprite2D.nfg");
	auto shader = ResourceManagers::GetInstance()->GetShader("Animation");
	auto texture = ResourceManagers::GetInstance()->GetTexture("AiPlay7.tga");
	AiPlay7Sprite = std::make_shared<SpriteAnimation>(model, shader, texture, 5, 3, 0, 0.2f);
	AiPlay7Sprite->SetSize(200, 500);
	AiPlay7Sprite->Set2DPosition(posX, posY);
	isPlayable = true;
	isFaceRight = true;
}

AiPlay7::~AiPlay7()
{
}

void AiPlay7::Dead(int die)
{
	if (die == 1)
	{
		isDie = true;
	}
}
void AiPlay7::Move(int dir) {

	switch (dir)
	{
	case 0:
		if (isDie == false)
		{
			AiPlay7Sprite->SetCurrentAction(0);
			AiPlay7Sprite->Set2DPosition(posX, 370);
		}
		else if (isDie == true)
		{
			AiPlay7Sprite->SetCurrentAction(2);
			AiPlay7Sprite->Set2DPosition(posX, 220);
		}
		break;
	case 1:
		//move left
		AiPlay7Sprite->SetCurrentAction(1);
		X_Val = -0.1f; //-0.5f; 
		posX += X_Val;
		if (posX < 100 || posX + 10 > 1280 && !isFaceRight)
		{
			isFaceRight = true;
			AiPlay7Sprite->SetRotation(Vector3(0, PI, 0));
			posX -= X_Val;
			AiPlay7Sprite->SetCurrentAction(0);
			AiPlay7Sprite->Set2DPosition(posX, 370);
		}
		break;
	default:
		break;
	}
}


void AiPlay7::UpdateAiPlay7Pos(GLfloat deltaTime)
{
	AiPlay7Sprite->Set2DPosition(posX, posY);

}

void AiPlay7::AiPlay7Update(GLfloat deltaTime)
{
	if (isDie && m_DisapearTime > 0.0f)
	{
		m_DisapearTime -= deltaTime;
	}
	AiPlay7Sprite->Update(deltaTime);
}
void AiPlay7::AiPlay7Draw()
{
	if (m_DisapearTime >= 0.0f)
	{
		AiPlay7Sprite->Draw();
	}
}