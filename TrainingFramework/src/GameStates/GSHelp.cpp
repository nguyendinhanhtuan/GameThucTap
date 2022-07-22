#include "GSHelp.h"
#include "SpriteAnimation.h"
#include "Shader.h"
#include "Texture.h"
#include "Model.h"

GSHelp::GSHelp() : GameStateBase(StateType::STATE_HELP), m_time(0.0f)
{
}


GSHelp::~GSHelp()
{
}


void GSHelp::Init()
{
	auto model = ResourceManagers::GetInstance()->GetModel("Sprite2D.nfg");
	auto shader = ResourceManagers::GetInstance()->GetShader("TextureShader");

	//button Menu
	auto texture = ResourceManagers::GetInstance()->GetTexture("btn_ExitGame1 .tga");
	std::shared_ptr<GameButton> buttonMenu = std::make_shared<GameButton>(model, shader, texture);
	buttonMenu->Set2DPosition(Globals::screenWidth - 500, 50);
	buttonMenu->SetSize(80, 80);
	buttonMenu->SetOnClick([this]() {
		GameStateMachine::GetInstance()->ChangeState(StateType::STATE_MENU);
		ResourceManagers::GetInstance()->PlaySound(name);
		ResourceManagers::GetInstance()->StopSound(name1);

		});
	m_listButtonMenu.push_back(buttonMenu);

	// background
	texture = ResourceManagers::GetInstance()->GetTexture("menuHelp.tga");
	shader = ResourceManagers::GetInstance()->GetShader("TextureShader");
	m_background = std::make_shared<Sprite2D>(model, shader, texture);
	m_background->Set2DPosition(Globals::screenWidth / 2, Globals::screenHeight / 2);
	m_background->SetSize(Globals::screenWidth, Globals::screenHeight);
	ResourceManagers::GetInstance()->PlaySound(name1);
}

void GSHelp::Exit()
{
	ResourceManagers::FreeInstance();
}


void GSHelp::Pause()
{
}

void GSHelp::Resume()
{
}


void GSHelp::HandleEvents()
{
}

void GSHelp::HandleKeyEvents(int key, bool bIsPressed)
{
}

void GSHelp::HandleTouchEvents(int x, int y, bool bIsPressed)
{

	for (auto buttonMenu : m_listButtonMenu)
	{
		if (buttonMenu->HandleTouchEvents(x, y, bIsPressed))
		{
			//ResourceManagers::GetInstance()->StopSound(name);
			break;
		}
	}
}

void GSHelp::HandleMouseMoveEvents(int x, int y)
{
}

void GSHelp::Update(float deltaTime)
{
	m_background->Update(deltaTime);

	for (auto it : m_listButtonMenu)
	{
		it->Update(deltaTime);
	}
}

void GSHelp::Draw()
{
	m_background->Draw();
	for (auto it : m_listButtonMenu)
	{
		it->Draw();
	}
}