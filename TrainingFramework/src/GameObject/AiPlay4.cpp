#include "AiPlay4.h"
#include "SpriteAnimation.h"

AiPlay4::AiPlay4(float x, float y)
{
	m_DisapearTime = 0.8f;
	isDie = false;
	posX = x;
	posY = y;
	auto model = ResourceManagers::GetInstance()->GetModel("Sprite2D.nfg");
	auto shader = ResourceManagers::GetInstance()->GetShader("Animation");
	auto texture = ResourceManagers::GetInstance()->GetTexture("AiPlay4.tga");
	AiPlay4Sprite = std::make_shared<SpriteAnimation>(model, shader, texture, 5, 3, 0, 0.2f);
	AiPlay4Sprite->SetSize(200, 500);
	AiPlay4Sprite->Set2DPosition(posX, posY);
	isPlayable = true;
	isFaceRight = true;
}

AiPlay4::~AiPlay4()
{
}

void AiPlay4::Dead(int die)
{
	if (die == 1)
	{
		isDie = true;
	}
}
void AiPlay4::Move(int dir) {

	switch (dir)
	{
	case 0:
		if (isDie == false)
		{
			AiPlay4Sprite->SetCurrentAction(0);
			AiPlay4Sprite->Set2DPosition(posX, 570);
		}
		else if (isDie == true)
		{
			AiPlay4Sprite->SetCurrentAction(2);
			AiPlay4Sprite->Set2DPosition(posX, 430);
		}
		break;
	case 1:
		//move left
		AiPlay4Sprite->SetCurrentAction(1);
		X_Val = -0.6f; //-0.5f; 
		posX += X_Val;
		if (posX < 100 || posX + 10 > 1280 && !isFaceRight)
		{
			isFaceRight = true;
			AiPlay4Sprite->SetRotation(Vector3(0, PI, 0));
			posX -= X_Val;
			AiPlay4Sprite->SetCurrentAction(0);
			AiPlay4Sprite->Set2DPosition(posX, 570);
		}
		break;
	default:
		break;
	}
}


void AiPlay4::UpdateAiPlay4Pos(GLfloat deltaTime)
{
	AiPlay4Sprite->Set2DPosition(posX, posY);

}

void AiPlay4::AiPlay4Update(GLfloat deltaTime)
{
	if (isDie && m_DisapearTime > 0.0f)
	{
		m_DisapearTime -= deltaTime;
	}
	AiPlay4Sprite->Update(deltaTime);
}
void AiPlay4::AiPlay4Draw()
{
	if (m_DisapearTime >= 0.0f)
	{
		AiPlay4Sprite->Draw();
	}
}