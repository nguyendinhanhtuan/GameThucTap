#include "AiPlay2.h"
#include "SpriteAnimation.h"

AiPlay2::AiPlay2(float x, float y)
{
	m_DisapearTime = 2.0f;
	isDie = false;
	posX = x;
	posY = y;
	auto model = ResourceManagers::GetInstance()->GetModel("Sprite2D.nfg");
	auto shader = ResourceManagers::GetInstance()->GetShader("Animation");
	auto texture = ResourceManagers::GetInstance()->GetTexture("AiPlay2.tga");
	AiPlay2Sprite = std::make_shared<SpriteAnimation>(model, shader, texture, 5, 3, 0, 0.2f);
	AiPlay2Sprite->SetSize(200, 500);
	AiPlay2Sprite->Set2DPosition(posX, posY);
	isPlayable = true;
	isFaceRight = true;
}

AiPlay2::~AiPlay2()
{
}

void AiPlay2::Dead(int die)
{
	if (die == 1)
	{
		isDie = true;
		std::printf("AiPlayDie");

	}
}
void AiPlay2::Move(int dir) {

	switch (dir)
	{
	case 0:
		if (isDie == false)
		{
			AiPlay2Sprite->SetCurrentAction(0);
			AiPlay2Sprite->Set2DPosition(posX, 300);
		}
		else if (isDie == true)
		{
			AiPlay2Sprite->SetCurrentAction(2);
			AiPlay2Sprite->Set2DPosition(posX, 160);
		}
		break;
	case 1:
		//move left
		AiPlay2Sprite->SetCurrentAction(1);
		X_Val = -0.8f; //-0.5f; 
		posX += X_Val;
		if (posX < 100 || posX + 10 > 1280 && !isFaceRight)
		{
			isFaceRight = true;
			AiPlay2Sprite->SetRotation(Vector3(0, PI, 0));
			posX -= X_Val;
			AiPlay2Sprite->SetCurrentAction(0);
			AiPlay2Sprite->Set2DPosition(posX, 300);
		}
		break;
	default:
		break;
	}
}


void AiPlay2::UpdateAiPlay2Pos(GLfloat deltaTime)
{
	AiPlay2Sprite->Set2DPosition(posX, posY);

}

void AiPlay2::AiPlay2Update(GLfloat deltaTime)
{
	if (isDie && m_DisapearTime > 0.0f)
	{
		m_DisapearTime -= deltaTime;
	}
	AiPlay2Sprite->Update(deltaTime);
}
void AiPlay2::AiPlay2Draw()
{
	if (m_DisapearTime >= 0.0f)
	{
		AiPlay2Sprite->Draw();
	}
}