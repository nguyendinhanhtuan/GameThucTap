#include "GameStateBase.h"

class SpriteAnimation;

class GSDie : public GameStateBase
{
public:
	GSDie();
	~GSDie();
	std::string name = "game-lose-sound.wav";
	std::string Click = "click.wav";
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
	std::list<std::shared_ptr<GameButton>>	m_listButtonMenu;
	std::list<std::shared_ptr<GameButton>>	m_listButtonExit;
	std::list<std::shared_ptr<GameButton>>	m_listButtonPlayAgain;
	std::shared_ptr<Sprite2D>m_background;
	std::list<std::shared_ptr<SpriteAnimation>>	m_listAnimation;
	float	m_time;
};
