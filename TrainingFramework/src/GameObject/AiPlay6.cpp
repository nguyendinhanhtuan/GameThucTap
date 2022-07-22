#include "AiPlay6.h"
#include "SpriteAnimation.h"

AiPlay6::AiPlay6(float x, float y)
{
	m_DisapearTime = 0.8f;
	isDie = false;
	posX = x;
	posY = y;
	auto model = ResourceManagers::GetInstance()->GetModel("Sprite2D.nfg");
	auto shader = ResourceManagers::GetInstance()->GetShader("Animation");
	auto texture = ResourceManagers::GetInstance()->GetTexture("AiPlay6.tga");
	AiPlay6Sprite = std::make_shared<SpriteAnimation>(model, shader, texture, 5, 3, 0, 0.2f);
	AiPlay6Sprite->SetSize(200, 500);
	AiPlay6Sprite->Set2DPosition(posX, posY);
	isPlayable = true;
	isFaceRight = true;
}

AiPlay6::~AiPlay6()
{
}

void AiPlay6::Dead(int die)
{
	if (die == 1)
	{
		isDie = true;
	}
}
void AiPlay6::Move(int dir) {

	switch (dir)
	{
	case 0:
		if (isDie == false)
		{
			AiPlay6Sprite->SetCurrentAction(0);
			AiPlay6Sprite->Set2DPosition(posX, 670);
		}
		else if (isDie == true)
		{
			AiPlay6Sprite->SetCurrentAction(2);
			AiPlay6Sprite->Set2DPosition(posX, 520);
		}
		break;
	case 1:
		//move left
		AiPlay6Sprite->SetCurrentAction(1);
		X_Val = -0.5f; //-0.5f; 
		posX += X_Val;
		if (posX < 100 || posX + 10 > 1280 && !isFaceRight)
		{
			isFaceRight = true;
			AiPlay6Sprite->SetRotation(Vector3(0, PI, 0));
			posX -= X_Val;
			AiPlay6Sprite->SetCurrentAction(0);
			AiPlay6Sprite->Set2DPosition(posX, 670);
		}
		break;
	default:
		break;
	}
}


void AiPlay6::UpdateAiPlay6Pos(GLfloat deltaTime)
{
	AiPlay6Sprite->Set2DPosition(posX, posY);

}

void AiPlay6::AiPlay6Update(GLfloat deltaTime)
{
	if (isDie && m_DisapearTime > 0.0f)
	{
		m_DisapearTime -= deltaTime;
	}
	AiPlay6Sprite->Update(deltaTime);
}
void AiPlay6::AiPlay6Draw()
{
	if (m_DisapearTime >= 0.0f)
	{
		AiPlay6Sprite->Draw();
	}
}