#include "AiPlay.h"
#include "SpriteAnimation.h"

AiPlay::AiPlay(float x, float y)
{
	m_DisapearTime = 0.8f;
	isDie = false;
	posX = x;
	posY = y;
	auto model = ResourceManagers::GetInstance()->GetModel("Sprite2D.nfg");
	auto shader = ResourceManagers::GetInstance()->GetShader("Animation");
	auto texture = ResourceManagers::GetInstance()->GetTexture("AiPlay.tga");
	AiPlaySprite = std::make_shared<SpriteAnimation>(model, shader, texture, 5, 3, 0, 0.2f);
	AiPlaySprite->SetSize(200, 500);
	AiPlaySprite->Set2DPosition(posX, posY);
	isPlayable = true;
	isFaceRight = true;
}

AiPlay::~AiPlay()
{
}

void AiPlay::Dead(int die)
{
	if (die == 1)
	{
		isDie = true;
	}
}
void AiPlay::Move(int dir) {

	switch (dir)
	{
	case 0:
		if (isDie == false)
		{
			AiPlaySprite->SetCurrentAction(0);
			AiPlaySprite->Set2DPosition(posX, 520);
		}
		else if (isDie == true)
		{
			AiPlaySprite->SetCurrentAction(2);
			AiPlaySprite->Set2DPosition(posX, 380);
		}
		break;
	case 1:
		//move left
		AiPlaySprite->SetCurrentAction(1);
		X_Val = -1.0f; //-0.5f; 
		posX += X_Val;
		if (posX < 100 || posX + 10 > 1280 && !isFaceRight )
		{ 
			isFaceRight = true;
			AiPlaySprite->SetRotation(Vector3(0, PI, 0));
			posX -= X_Val;
			AiPlaySprite->SetCurrentAction(0);
			AiPlaySprite->Set2DPosition(posX, 520);
		}
		break;
	default:
		break;
	}
}


void AiPlay::UpdateAiPlayPos(GLfloat deltaTime)
{
	AiPlaySprite->Set2DPosition(posX, posY);

}

void AiPlay::AiPlayUpdate(GLfloat deltaTime)
{
	if (isDie && m_DisapearTime > 0.0f)
	{
		m_DisapearTime -= deltaTime;
	}
	AiPlaySprite->Update(deltaTime);
}
void AiPlay::AiPlayDraw()
{
	if (m_DisapearTime >= 0.0f)
	{
		AiPlaySprite->Draw();
	}
}