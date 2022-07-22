#include "Slime.h"
#include "SpriteAnimation.h"

Slime::Slime(float x, float y)
{
	m_DisapearTime = 0.8f;
	isDie = false;
	posX = x;
	posY = y;
	auto model = ResourceManagers::GetInstance()->GetModel("Sprite2D.nfg");
	auto shader = ResourceManagers::GetInstance()->GetShader("Animation");
	auto texture = ResourceManagers::GetInstance()->GetTexture("Actor1_2.tga");
	SlimeSprite = std::make_shared<SpriteAnimation>(model, shader, texture, 5, 3, 0, 0.2f);
	SlimeSprite->SetSize(200, 500);
	SlimeSprite->Set2DPosition(posX, posY);
	isPlayable = true;

	isFaceRight = true;
}

Slime::~Slime()
{
}

void Slime::Dead(int die)
{
	
	if (die == 1)
	{
		isDie = true;
		std::printf("Die");
	}
}

void Slime::Move(int dir) {

	switch (dir)
	{
	case 0:
		if(isDie == false)
		{
		SlimeSprite->SetCurrentAction(0);
		SlimeSprite->Set2DPosition(posX, 420);
		}
		else if (isDie == true)
		{
			SlimeSprite->SetCurrentAction(2);
			SlimeSprite->Set2DPosition(posX, 280);
			GameStateMachine::GetInstance()->ChangeState(StateType::STATE_DIE);
		}
		break;
	case 1:
		//move left
		SlimeSprite->SetCurrentAction(1);
		XX_Val = -0.8f;
		posX += XX_Val;
		if (posX < 200 && posX + 10 > 1280)
		{
			posX -= XX_Val;
			dir = 0;
			GameStateMachine::GetInstance()->ChangeState(StateType::STATE_WIN);
		}
		if (isFaceRight) {
			isFaceRight = false;
			SlimeSprite->SetRotation(Vector3(0, 0, 0));
		}
		break;
	case 4:
		//move right
		SlimeSprite->SetCurrentAction(1);
		XX_Val = 0.8f;
		posX += XX_Val;
		if (posX < 200 && posX + 10 > 1280)
		{ 
			posX -= XX_Val;
		}
		if (!isFaceRight) {
			isFaceRight = true;
			SlimeSprite->SetRotation(Vector3(0, PI, 0));
		}
		break;
	default:
		break;
	}
}


void Slime::UpdateSlimePos(GLfloat deltaTime)
{
	SlimeSprite->Set2DPosition(posX, posY);

}

void Slime::SlimeUpdate(GLfloat deltaTime)
{

	if (isDie && m_DisapearTime > 0.0f)
	{
		m_DisapearTime -= deltaTime;
	}
	SlimeSprite->Update(deltaTime);
}
void Slime::SlimeDraw()
{	
	if (m_DisapearTime >= 0.0f)
	{
		SlimeSprite->Draw();
	}
}