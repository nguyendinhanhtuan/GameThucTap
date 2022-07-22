#include "AiPlay1.h"
#include "SpriteAnimation.h"

AiPlay1::AiPlay1(float x, float y)
{
	m_DisapearTime = 2.0f;
	isDie = false;
	posX = x;
	posY = y;
	auto model = ResourceManagers::GetInstance()->GetModel("Sprite2D.nfg");
	auto shader = ResourceManagers::GetInstance()->GetShader("Animation");
	auto texture = ResourceManagers::GetInstance()->GetTexture("AiPlay1.tga");
	AiPlay1Sprite = std::make_shared<SpriteAnimation>(model, shader, texture, 5, 3, 0, 0.2f);
	AiPlay1Sprite->SetSize(200, 500);
	AiPlay1Sprite->Set2DPosition(posX, posY);
	isPlayable = true;
	isFaceRight = true;
}

AiPlay1::~AiPlay1()
{
}

void AiPlay1::Dead(int die)
{
	if (die == 1)
	{
		isDie = true;
		std::printf("AiPlayDie");

	}
}
void AiPlay1::Move(int dir) {

	switch (dir)
	{
	case 0:
		if (isDie == false)
		{
			AiPlay1Sprite->SetCurrentAction(0);
			AiPlay1Sprite->Set2DPosition(posX, 270);
		}
		else if (isDie == true)
		{
			AiPlay1Sprite->SetCurrentAction(2);
			AiPlay1Sprite->Set2DPosition(posX, 130);
		}
		break;
	case 1:
		//move left
		AiPlay1Sprite->SetCurrentAction(1);
		X_Val = -0.9f; //-0.5f; 
		posX += X_Val;
		if (posX < 100 || posX + 10 > 1280 && !isFaceRight)
		{
			isFaceRight = true;
			AiPlay1Sprite->SetRotation(Vector3(0, PI, 0));
			posX -= X_Val;
			AiPlay1Sprite->SetCurrentAction(0);
			AiPlay1Sprite->Set2DPosition(posX, 270);
		}
		break;
	default:
		break;
	}
}


void AiPlay1::UpdateAiPlay1Pos(GLfloat deltaTime)
{
	AiPlay1Sprite->Set2DPosition(posX, posY);

}

void AiPlay1::AiPlay1Update(GLfloat deltaTime)
{
	if (isDie && m_DisapearTime > 0.0f)
	{
		m_DisapearTime -= deltaTime;
	}
	AiPlay1Sprite->Update(deltaTime);
}
void AiPlay1::AiPlay1Draw()
{
	if (m_DisapearTime >= 0.0f)
	{
		AiPlay1Sprite->Draw();
	}
}