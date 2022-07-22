#include "GSMenu.h"
#include "Camera.h"

GSMenu::GSMenu() : GameStateBase(StateType::STATE_MENU), 
	m_background(nullptr), m_listButton(std::list<std::shared_ptr<GameButton>>{}), m_textGameName(nullptr)
{
}


GSMenu::~GSMenu()
{
}



void GSMenu::Init()
{
	auto model = ResourceManagers::GetInstance()->GetModel("Sprite2D.nfg");
	auto texture = ResourceManagers::GetInstance()->GetTexture("bg_main_menu.tga");

	// background
	auto shader = ResourceManagers::GetInstance()->GetShader("TextureShader");
	m_background = std::make_shared<Sprite2D>(model, shader, texture);
	m_background->Set2DPosition(Globals::screenWidth / 2, Globals::screenHeight / 2);
	m_background->SetSize(Globals::screenWidth, Globals::screenHeight);

	// play button
	texture = ResourceManagers::GetInstance()->GetTexture("btn_play.tga");
	std::shared_ptr<GameButton> button = std::make_shared<GameButton>(model, shader, texture);
	button->Set2DPosition(Globals::screenWidth -168 , Globals::screenHeight / 2 );
	button->SetSize(250, 100);
	button->SetOnClick([this]() {
			GameStateMachine::GetInstance()->ChangeState(StateType::STATE_PrepareToPlay);
			ResourceManagers::GetInstance()->StopSound(name);
		});
	m_listButton.push_back(button);

	// button help
	texture = ResourceManagers::GetInstance()->GetTexture("btn_help.tga");
	std::shared_ptr<GameButton> buttonHelp = std::make_shared<GameButton>(model, shader, texture);
	buttonHelp->Set2DPosition(Globals::screenWidth - 168, Globals::screenHeight / 2 + 120);
	buttonHelp->SetSize(250, 100);
	buttonHelp->SetOnClick([this]() {
		GameStateMachine::GetInstance()->ChangeState(StateType::STATE_HELP);
		ResourceManagers::GetInstance()->StopSound(name);
		});
	m_listButtonHelp.push_back(buttonHelp);

	// exit button
	texture = ResourceManagers::GetInstance()->GetTexture("btn_close.tga");
	button = std::make_shared<GameButton>(model, shader, texture);
	button->Set2DPosition(Globals::screenWidth - 164, Globals::screenHeight / 2 + 240);
	button->SetSize(250, 100);
	button->SetOnClick([this]() {
		exit(0);
		ResourceManagers::GetInstance()->StopSound(name);
		});
	m_listButton.push_back(button);

	// game title
	shader = ResourceManagers::GetInstance()->GetShader("TextShader");
	std::shared_ptr<Font> font = ResourceManagers::GetInstance()->GetFont("arialbd.ttf");
	m_textGameName = std::make_shared< Text>(shader, font, " ", Vector4(1.0f, 0.5f, 0.0f, 1.0f), 3.0f);
	m_textGameName->Set2DPosition(Vector2(350, 250));

	//Menu
	model = ResourceManagers::GetInstance()->GetModel("Sprite2D.nfg");
	shader = ResourceManagers::GetInstance()->GetShader("TextureShader");
	texture = ResourceManagers::GetInstance()->GetTexture("menu.tga");

	m_Menu = std::make_shared<Sprite2D>(model, shader, texture);
	m_Menu->Set2DPosition((float)Globals::screenWidth -180 , 440);
	m_Menu->SetSize(700, 600);

	ResourceManagers::GetInstance()->PlaySound(name);
}

void GSMenu::Exit()
{
	ResourceManagers::FreeInstance();
}


void GSMenu::Pause()
{
}

void GSMenu::Resume()
{
}


void GSMenu::HandleEvents()
{
}

void GSMenu::HandleKeyEvents(int key, bool bIsPressed)
{
}

void GSMenu::HandleTouchEvents(int x, int y, bool bIsPressed)
{
	for (auto button : m_listButton)
	{
		if (button->HandleTouchEvents(x, y, bIsPressed))
		{
			ResourceManagers::GetInstance()->StopSound(name);
			break;
		}
	}

	for (auto buttonHelp : m_listButtonHelp)
	{
		if (buttonHelp->HandleTouchEvents(x, y, bIsPressed))
		{
			
			break;
		}
	}
}

void GSMenu::HandleMouseMoveEvents(int x, int y)
{
}

void GSMenu::Update(float deltaTime)
{
	m_background->Update(deltaTime);
	for (auto it : m_listButton)
	{
		it->Update(deltaTime);
	}
	for (auto it : m_listButtonHelp)
	{
		it->Update(deltaTime);
	}
}

void GSMenu::Draw()
{
	m_background->Draw();
	m_Menu->Draw();
	for (auto it : m_listButton)
	{
		it->Draw();
	}
	for (auto it : m_listButtonHelp)
	{
		it->Draw();
	}
	m_textGameName->Draw();
}
