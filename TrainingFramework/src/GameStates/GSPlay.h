#pragma once
#include "GameStateBase.h"
#include <map>
#include "GameManager/Singleton.h"
#include "GameConfig.h"
class Sprite2D;
class Sprite3D;
class Text;
class GameButton;
class SpriteAnimation;
class Slime;
class ActorACC;
class Loading;
class BackGound;
class AiPlay;
class AiPlay1;
class AiPlay2;
class AiPlay3;
class AiPlay4;
class AiPlay5; 
class AiPlay6;
class AiPlay7;
class GSPlay :
	public GameStateBase
{
public:
	std::string name1 = "enemysound.wav";
	std::string name = "SoundCountDown1.wav";
	GSPlay();
	~GSPlay();
	bool	die = false;
	GLfloat m_ACCTime = 0.0f;
	GLfloat m_RandumTime = 0.0f;
	GLfloat countTime = 60.0f;
	GLfloat timeMoveDie = 0.6f;
	GLfloat timeAiPlayMove = 0.0f;
	GLfloat timeAiPlayMove1 = 0.0f;
	GLfloat timeAiPlayMove2 = 0.0f;
	int		checkAiPlayMove ;
	int		checkAiPlayMove1 ;
	int		checkAiPlayMove2;
	bool	aTime = true;
	void	Init() override;
	void	Exit() override;
	void	CheckDie(int key, GLfloat deltaTime);
	void	CheckDieAiPlay(int checkAiPlayMoveOption, GLfloat deltaTime);
	void	CheckDieAiPlay1(int checkAiPlayMoveOption, GLfloat deltaTime);
	void	CheckDieAiPlay2(int checkAiPlayMoveOption, GLfloat deltaTime);
	void	Pause() override;
	void	Resume() override;

	void	HandleEvents() override;
	void	HandleKeyEvents(int key, bool bIsPressed) override;
	void	HandleTouchEvents(int x, int y, bool bIsPressed) override;
	void	HandleMouseMoveEvents(int x, int y) override;
	void	Update(float deltaTime) override;
	void	Draw() override;
	void	TimeACC(GLfloat deltaTime);
	void	CountTime(GLfloat deltaTime);
	void	AiPlayMove(GLfloat deltaTime);
	void	AiPlayMove1(GLfloat deltaTime);
	void	AiPlayMove2(GLfloat deltaTime);
	int		m_KeyPress;

private:




	//
	std::shared_ptr<Sprite2D>	m_background;
	std::shared_ptr<Sprite2D>	m_ATT;
	std::shared_ptr<Sprite2D>	m_ATT1;
	std::shared_ptr<Text>		m_time;
	std::shared_ptr<Text>		m_time1;
	std::shared_ptr<Sprite2D>	m_BgTime;

	//slime
	std::shared_ptr<Slime> pointerSlime;
	std::list<std::shared_ptr<Slime>>	m_listSlimeAnimation;


	//ActorACC
	std::shared_ptr<ActorACC> pointerActorACC;	
	std::list<std::shared_ptr<ActorACC>>	m_listActorACCAnimation;

	//loading
	std::shared_ptr<Loading> pointerLoading;
	std::list<std::shared_ptr<Loading>>	m_listLoadingAnimation;

	// BackgoundRED
	std::shared_ptr<BackGound> pointerBackGound;	
	std::list<std::shared_ptr<BackGound>>	m_listBackGoundAnimation;

	//Button
	std::list<std::shared_ptr<GameButton>>	m_listButton;
	std::list<std::shared_ptr<GameButton>>	m_listButton1;

	// none
	std::list<std::shared_ptr<Text>>	m_listTime;
	std::list<std::shared_ptr<SpriteAnimation>>	m_listAnimation;

	// AiPlay
	std::shared_ptr<AiPlay> pointerAiPlay;
	std::list<std::shared_ptr<AiPlay>>	m_listAiPlayAnimation;
		 //1
		std::shared_ptr<AiPlay1> pointerAiPlay1;
		std::list<std::shared_ptr<AiPlay1>>	m_listAiPlay1Animation;
		//2
		std::shared_ptr<AiPlay2> pointerAiPlay2;
		std::list<std::shared_ptr<AiPlay2>>	m_listAiPlay2Animation;
		//3
		std::shared_ptr<AiPlay3> pointerAiPlay3;
		std::list<std::shared_ptr<AiPlay3>>	m_listAiPlay3Animation;
		//4
		std::shared_ptr<AiPlay4> pointerAiPlay4;
		std::list<std::shared_ptr<AiPlay4>>	m_listAiPlay4Animation;
		//5
		std::shared_ptr<AiPlay5> pointerAiPlay5;
		std::list<std::shared_ptr<AiPlay5>>	m_listAiPlay5Animation;
		//6
		std::shared_ptr<AiPlay6> pointerAiPlay6;
		std::list<std::shared_ptr<AiPlay6>>	m_listAiPlay6Animation;
		//7
		std::shared_ptr<AiPlay7> pointerAiPlay7;
		std::list<std::shared_ptr<AiPlay7>>	m_listAiPlay7Animation;
};

