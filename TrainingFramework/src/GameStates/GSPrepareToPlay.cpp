#include "GSPrepareToPlay.h"
#include "SpriteAnimation.h"
#include "Shader.h"
#include "Texture.h"
#include "Model.h"

GSPrepareToPlay::GSPrepareToPlay() : GameStateBase(StateType::STATE_PrepareToPlay), m_time(0.0f)
{
}


GSPrepareToPlay::~GSPrepareToPlay()
{
}


void GSPrepareToPlay::Init()
{
	auto model = ResourceManagers::GetInstance()->GetModel("Sprite2D.nfg");
	auto shader = ResourceManagers::GetInstance()->GetShader("TextureShader");
	auto texture = ResourceManagers::GetInstance()->GetTexture("logo.tga");

	// background
	texture = ResourceManagers::GetInstance()->GetTexture("bg_count.tga");
	shader = ResourceManagers::GetInstance()->GetShader("TextureShader");
	m_background = std::make_shared<Sprite2D>(model, shader, texture);
	m_background->Set2DPosition(Globals::screenWidth / 2, Globals::screenHeight / 2);
	m_background->SetSize(Globals::screenWidth, Globals::screenHeight);

	//count 3 2 1 letgo
	shader = ResourceManagers::GetInstance()->GetShader("Animation");
	texture = ResourceManagers::GetInstance()->GetTexture("Count1.tga");
	std::shared_ptr<SpriteAnimation> count = std::make_shared<SpriteAnimation>(model, shader, texture, 5, 1, 0, 1.1f);
	count->Set2DPosition(Globals::screenWidth / 2.0f, Globals::screenHeight / 2.0f);
	count->SetSize(300, 1000);
	m_listAnimation.push_back(count);
	ResourceManagers::GetInstance()->PlaySound(name);
}

void GSPrepareToPlay::Exit()
{
}


void GSPrepareToPlay::Pause()
{
}

void GSPrepareToPlay::Resume()
{
}


void GSPrepareToPlay::HandleEvents()
{
}

void GSPrepareToPlay::HandleKeyEvents(int key, bool bIsPressed)
{
}

void GSPrepareToPlay::HandleTouchEvents(int x, int y, bool bIsPressed)
{
}

void GSPrepareToPlay::HandleMouseMoveEvents(int x, int y)
{
}

void GSPrepareToPlay::Update(float deltaTime)
{
	m_time += deltaTime;
	if (m_time > 3.3)
	{
		GameStateMachine::GetInstance()->ChangeState(StateType::STATE_PLAY);
		m_time = 0;
	}
	for (auto it : m_listAnimation)
	{
		it->Update(deltaTime);
	}
}

void GSPrepareToPlay::Draw()
{
	m_background->Draw();
	for (auto& it : m_listAnimation)
	{
		it->Draw();
	}
							
}