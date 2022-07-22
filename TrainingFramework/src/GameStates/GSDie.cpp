#include "GSDie.h"
#include "SpriteAnimation.h"
#include "Shader.h"
#include "Texture.h"
#include "Model.h"

GSDie::GSDie() : GameStateBase(StateType::STATE_DIE), m_time(0.0f)
{
}


GSDie::~GSDie()
{
}


void GSDie::Init()
{
	auto model = ResourceManagers::GetInstance()->GetModel("Sprite2D.nfg");
	auto shader = ResourceManagers::GetInstance()->GetShader("TextureShader");

	//button Menu
	auto texture = ResourceManagers::GetInstance()->GetTexture("btn_MenuAgian.tga");
	std::shared_ptr<GameButton> buttonMenu = std::make_shared<GameButton>(model, shader, texture);
	buttonMenu->Set2DPosition(Globals::screenWidth - 50, 50);
	buttonMenu->SetSize(100, 100);
	buttonMenu->SetOnClick([this]() {
		GameStateMachine::GetInstance()->ChangeState(StateType::STATE_MENU);
		//ResourceManagers::GetInstance()->StopSound(name);
		});
	m_listButtonMenu.push_back(buttonMenu);

	//button Play again
	texture = ResourceManagers::GetInstance()->GetTexture("btn_PlayAgain.tga");
	std::shared_ptr<GameButton> buttonPlayAgain = std::make_shared<GameButton>(model, shader, texture);
	buttonPlayAgain->Set2DPosition(Globals::screenWidth -780, 650);
	buttonPlayAgain->SetSize(100, 100);
	buttonPlayAgain->SetOnClick([this]() {
		GameStateMachine::GetInstance()->ChangeState(StateType::STATE_PrepareToPlay);
		ResourceManagers::GetInstance()->PlaySound(Click);
		//ResourceManagers::GetInstance()->StopSound(name);
		});
	m_listButtonPlayAgain.push_back(buttonPlayAgain);

	//button exit
	texture = ResourceManagers::GetInstance()->GetTexture("btn_ExitGame .tga");
	std::shared_ptr<GameButton> buttonExit = std::make_shared<GameButton>(model, shader, texture);
	buttonExit->Set2DPosition(Globals::screenWidth - 490, 650);
	buttonExit->SetSize(100, 100);
	buttonExit->SetOnClick([this]() {
		exit(0);
		//ResourceManagers::GetInstance()->StopSound(name);
		});
	m_listButtonExit.push_back(buttonExit);
	// background
	texture = ResourceManagers::GetInstance()->GetTexture("bg_die.tga");
	shader = ResourceManagers::GetInstance()->GetShader("TextureShader");
	m_background = std::make_shared<Sprite2D>(model, shader, texture);
	m_background->Set2DPosition(Globals::screenWidth / 2, Globals::screenHeight / 2);
	m_background->SetSize(Globals::screenWidth, Globals::screenHeight);

	//animation die
	shader = ResourceManagers::GetInstance()->GetShader("Animation");
	texture = ResourceManagers::GetInstance()->GetTexture("Actor1_2.tga");
	std::shared_ptr<SpriteAnimation> count = std::make_shared<SpriteAnimation>(model, shader, texture, 5, 3, 2, 0.1f);
	count->Set2DPosition(Globals::screenWidth / 2.0f, Globals::screenHeight / 3.0f);
	count->SetSize(250, 500);
	m_listAnimation.push_back(count);
	ResourceManagers::GetInstance()->PlaySound(name);
}

void GSDie::Exit()
{
	ResourceManagers::FreeInstance();
}


void GSDie::Pause()
{
}

void GSDie::Resume()
{
}


void GSDie::HandleEvents()
{
}

void GSDie::HandleKeyEvents(int key, bool bIsPressed)
{
}

void GSDie::HandleTouchEvents(int x, int y, bool bIsPressed)
{
	for (auto buttonExit : m_listButtonExit)
	{
		if (buttonExit->HandleTouchEvents(x, y, bIsPressed))
		{
			//ResourceManagers::GetInstance()->StopSound(name);
			break;
		}
	}
	for (auto buttonPlayAgain : m_listButtonPlayAgain)
	{
		if (buttonPlayAgain->HandleTouchEvents(x, y, bIsPressed))
		{
			//ResourceManagers::GetInstance()->StopSound(name);
			break;
		}
	}
	for (auto buttonMenu : m_listButtonMenu)
	{
		if (buttonMenu->HandleTouchEvents(x, y, bIsPressed))
		{
			//ResourceManagers::GetInstance()->StopSound(name);
			break;
		}
	}
}

void GSDie::HandleMouseMoveEvents(int x, int y)
{
}

void GSDie::Update(float deltaTime)
{
	m_background->Update(deltaTime);

	for (auto it : m_listButtonExit)
	{
		it->Update(deltaTime);
	}
	for (auto it : m_listAnimation)
	{
		it->Update(deltaTime);
	}
	for (auto it : m_listButtonPlayAgain)
	{
		it->Update(deltaTime);
	}
	for (auto it : m_listButtonMenu)
	{
		it->Update(deltaTime);
	}
}

void GSDie::Draw()
{
	m_background->Draw();
	for (auto& it : m_listAnimation)
	{
		it->Draw();
	}
	for (auto it : m_listButtonExit)
	{
		it->Draw();
	}
	for (auto it : m_listButtonPlayAgain)
	{
		it->Draw();
	}
	for (auto it : m_listButtonMenu)
	{
		it->Draw();
	}
}