#include "AiPlay3.h"
#include "SpriteAnimation.h"

AiPlay3::AiPlay3(float x, float y)
{
	m_DisapearTime = 0.8f;
	isDie = false;
	posX = x;
	posY = y;
	auto model = ResourceManagers::GetInstance()->GetModel("Sprite2D.nfg");
	auto shader = ResourceManagers::GetInstance()->GetShader("Animation");
	auto texture = ResourceManagers::GetInstance()->GetTexture("AiPlay3.tga");
	AiPlay3Sprite = std::make_shared<SpriteAnimation>(model, shader, texture, 5, 3, 0, 0.2f);
	AiPlay3Sprite->SetSize(200, 500);
	AiPlay3Sprite->Set2DPosition(posX, posY);
	isPlayable = true;
	isFaceRight = true;
}

AiPlay3::~AiPlay3()
{
}

void AiPlay3::Dead(int die)
{
	if (die == 1)
	{
		isDie = true;
	}
}
void AiPlay3::Move(int dir) {

	switch (dir)
	{
	case 0:
		if (isDie == false)
		{
			AiPlay3Sprite->SetCurrentAction(0);
			AiPlay3Sprite->Set2DPosition(posX, 330);
		}
		else if (isDie == true)
		{
			AiPlay3Sprite->SetCurrentAction(2);
			AiPlay3Sprite->Set2DPosition(posX, 190);
		}
		break;
	case 1:
		//move left
		AiPlay3Sprite->SetCurrentAction(1);
		X_Val = -0.7f; //-0.5f; 
		posX += X_Val;
		if (posX < 100 || posX + 10 > 1280 && !isFaceRight)
		{
			isFaceRight = true;
			AiPlay3Sprite->SetRotation(Vector3(0, PI, 0));
			posX -= X_Val;
			AiPlay3Sprite->SetCurrentAction(0);
			AiPlay3Sprite->Set2DPosition(posX, 330);
		}
		break;
	default:
		break;
	}
}


void AiPlay3::UpdateAiPlay3Pos(GLfloat deltaTime)
{
	AiPlay3Sprite->Set2DPosition(posX, posY);

}

void AiPlay3::AiPlay3Update(GLfloat deltaTime)
{
	if (isDie && m_DisapearTime > 0.0f)
	{
		m_DisapearTime -= deltaTime;
	}
	AiPlay3Sprite->Update(deltaTime);
}
void AiPlay3::AiPlay3Draw()
{
	if (m_DisapearTime >= 0.0f)
	{
		AiPlay3Sprite->Draw();
	}
}