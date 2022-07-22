#include "AiPlay5.h"
#include "SpriteAnimation.h"

AiPlay5::AiPlay5(float x, float y)
{
	m_DisapearTime = 0.8f;
	isDie = false;
	posX = x;
	posY = y;
	auto model = ResourceManagers::GetInstance()->GetModel("Sprite2D.nfg");
	auto shader = ResourceManagers::GetInstance()->GetShader("Animation");
	auto texture = ResourceManagers::GetInstance()->GetTexture("AiPlay5.tga");
	AiPlay5Sprite = std::make_shared<SpriteAnimation>(model, shader, texture, 5, 3, 0, 0.2f);
	AiPlay5Sprite->SetSize(200, 500);
	AiPlay5Sprite->Set2DPosition(posX, posY);
	isPlayable = true;
	isFaceRight = true;
}

AiPlay5::~AiPlay5()
{
}

void AiPlay5::Dead(int die)
{
	if (die == 1)
	{
		isDie = true;
	}
}
void AiPlay5::Move(int dir) {

	switch (dir)
	{
	case 0:
		if (isDie == false)
		{
			AiPlay5Sprite->SetCurrentAction(0);
			AiPlay5Sprite->Set2DPosition(posX, 620);
		}
		else if (isDie == true)
		{
			AiPlay5Sprite->SetCurrentAction(2);
			AiPlay5Sprite->Set2DPosition(posX, 470);
		}
		break;
	case 1:
		//move left
		AiPlay5Sprite->SetCurrentAction(1);
		X_Val = -0.5f; //-0.5f; 
		posX += X_Val;
		if (posX < 100 || posX + 10 > 1280 && !isFaceRight)
		{
			isFaceRight = true;
			AiPlay5Sprite->SetRotation(Vector3(0, PI, 0));
			posX -= X_Val;
			AiPlay5Sprite->SetCurrentAction(0);
			AiPlay5Sprite->Set2DPosition(posX, 620);
		}
		break;
	default:
		break;
	}
}


void AiPlay5::UpdateAiPlay5Pos(GLfloat deltaTime)
{
	AiPlay5Sprite->Set2DPosition(posX, posY);

}

void AiPlay5::AiPlay5Update(GLfloat deltaTime)
{
	if (isDie && m_DisapearTime > 0.0f)
	{
		m_DisapearTime -= deltaTime;
	}
	AiPlay5Sprite->Update(deltaTime);
}
void AiPlay5::AiPlay5Draw()
{
	if (m_DisapearTime >= 0.0f)
	{
		AiPlay5Sprite->Draw();
	}
}