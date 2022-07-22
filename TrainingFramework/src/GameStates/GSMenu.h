#pragma once
#include "GameStateBase.h"
#include "GameButton.h"

class GSMenu :
	public GameStateBase
{
public:
	GSMenu();
	~GSMenu();
	std::string name = "Alarm02.wav";
	void	Init() override;
	void	Exit() override;

	void	Pause() override;
	void	Resume() override;

	void	HandleEvents() override;
	void	HandleKeyEvents(int key, bool bIsPressed) override;
	void	HandleTouchEvents(int x, int y, bool bIsPressed) override;
	void	HandleMouseMoveEvents(int x, int y) override;
	void	Update(float deltaTime) override;
	void	Draw() override;

private:
	std::shared_ptr<Sprite2D>				m_Menu;
	std::shared_ptr<Sprite2D>				m_background;
	std::list<std::shared_ptr<GameButton>>	m_listButton;
	std::list<std::shared_ptr<GameButton>>	m_listButtonHelp;
	std::shared_ptr<Text>					m_textGameName;

};

