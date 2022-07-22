#include "GSPlay.h"
#include <cstdlib>
#include "Shader.h"
#include "Texture.h"
#include "Model.h"
#include "Camera.h"
#include "ActorACC.h"
#include "Slime.h"
#include "loading.h"
#include "BackGound.h"
#include "Font.h"
#include "Sprite2D.h"
#include "Sprite3D.h"
#include "Text.h"
#include "GameButton.h"
#include "SpriteAnimation.h"
#include "AiPlay.h"
#include "AiPlay1.h"
#include "AiPlay2.h"
#include "AiPlay3.h"
#include "AiPlay4.h"
#include "AiPlay5.h"
#include "AiPlay6.h"
#include "AiPlay7.h"




GSPlay::GSPlay()
{
}


GSPlay::~GSPlay()
{
}


void GSPlay::Init()
{
	auto model = ResourceManagers::GetInstance()->GetModel("Sprite2D.nfg");
	auto texture = ResourceManagers::GetInstance()->GetTexture("bg_play1.tga");

	// background
	auto shader = ResourceManagers::GetInstance()->GetShader("TextureShader");
	m_background = std::make_shared<Sprite2D>(model, shader, texture);
	m_background->Set2DPosition((float)Globals::screenWidth / 2, (float)Globals::screenHeight / 2);
	m_background->SetSize(Globals::screenWidth, Globals::screenHeight);

	// button close
	texture = ResourceManagers::GetInstance()->GetTexture("btn_close.tga");
	std::shared_ptr<GameButton>  button = std::make_shared<GameButton>(model, shader, texture);
	button->Set2DPosition(Globals::screenWidth - 100, 50);
	button->SetSize(150, 50);
	button->SetOnClick([this]() {
		GameStateMachine::GetInstance()->PopState();
		ResourceManagers::GetInstance()->StopSound(name1);
		ResourceManagers::GetInstance()->PlaySound(name);
		});
	m_listButton.push_back(button);

	// button reset
	texture = ResourceManagers::GetInstance()->GetTexture("btn_pause.tga");
	std::shared_ptr<GameButton>  buttonPause = std::make_shared<GameButton>(model, shader, texture);
	buttonPause->Set2DPosition(Globals::screenWidth - 400, 50);
	buttonPause->SetSize(50, 50);
	buttonPause->SetOnClick([]() {
		GameStateMachine::GetInstance()->PushState(StateType::STATE_PrepareToPlay);
		});
	m_listButton1.push_back(buttonPause);

	// time
	shader = ResourceManagers::GetInstance()->GetShader("TextShader");
	std::shared_ptr<Font> font = ResourceManagers::GetInstance()->GetFont("arialbd.ttf");
	m_time = std::make_shared< Text>(shader, font, "60", TextColor::BLACK, 1.5);
	m_time->Set2DPosition(Vector2(690, 127));
	// 00:00
	shader = ResourceManagers::GetInstance()->GetShader("TextShader");
	std::shared_ptr<Font> font1 = ResourceManagers::GetInstance()->GetFont("arialbd.ttf");
	m_time1 = std::make_shared< Text>(shader, font1, "00:", TextColor::BLACK, 1.5);
	m_time1->Set2DPosition(Vector2(635, 127));

	// Bg Time
	model = ResourceManagers::GetInstance()->GetModel("Sprite2D.nfg");
	texture = ResourceManagers::GetInstance()->GetTexture("BgTime.tga");
	shader = ResourceManagers::GetInstance()->GetShader("TextureShader");
	m_BgTime = std::make_shared<Sprite2D>(model, shader, texture);
	m_BgTime->SetSize(400, 400);
	m_BgTime->Set2DPosition(680, 115);


	// Actor ATT 
	model = ResourceManagers::GetInstance()->GetModel("Sprite2D.nfg");
	texture = ResourceManagers::GetInstance()->GetTexture("ActorATT.tga");
	shader = ResourceManagers::GetInstance()->GetShader("TextureShader");
	m_ATT = std::make_shared<Sprite2D>(model, shader, texture);
	m_ATT->SetSize(200, 150);
	m_ATT->Set2DPosition(200, 600);

	model = ResourceManagers::GetInstance()->GetModel("Sprite2D.nfg");
	texture = ResourceManagers::GetInstance()->GetTexture("ActorATT.tga");
	shader = ResourceManagers::GetInstance()->GetShader("TextureShader");
	m_ATT1 = std::make_shared<Sprite2D>(model, shader, texture);
	m_ATT1->SetSize(200, 150);
	m_ATT1->Set2DPosition(200, 300);


	//Slime
	std::shared_ptr<Slime> Obj = std::make_shared<Slime>(1220, 350);
	pointerSlime = Obj;
	m_listSlimeAnimation.push_back(Obj);
	m_KeyPress = 0;

	//ActorACC
	std::shared_ptr<ActorACC> Bbj = std::make_shared<ActorACC>(110, 450);
	pointerActorACC = Bbj;
	m_listActorACCAnimation.push_back(Bbj);

	//loading
	std::shared_ptr<Loading> Cbj = std::make_shared<Loading>(680, 54);
	pointerLoading = Cbj;
	m_listLoadingAnimation.push_back(Cbj);

	//BackGound
	std::shared_ptr<BackGound> Dbj = std::make_shared<BackGound>(864,-7);
	pointerBackGound = Dbj;
	m_listBackGoundAnimation.push_back(Dbj);

	//AiPlay
	std::shared_ptr<AiPlay> aiPlay = std::make_shared<AiPlay>(1220, 450);
	pointerAiPlay = aiPlay;
	m_listAiPlayAnimation.push_back(aiPlay);
	checkAiPlayMove = 0;
		//1 
		std::shared_ptr<AiPlay1> aiPlay1 = std::make_shared <AiPlay1>(1220, 200);
		pointerAiPlay1 = aiPlay1;
		m_listAiPlay1Animation.push_back(aiPlay1);
		//2 
		std::shared_ptr<AiPlay2> aiPlay2 = std::make_shared <AiPlay2>(1220, 230);
		pointerAiPlay2 = aiPlay2;
		m_listAiPlay2Animation.push_back(aiPlay2);
		//3
		std::shared_ptr<AiPlay3> aiPlay3 = std::make_shared<AiPlay3>(1220, 260);
		pointerAiPlay3 = aiPlay3;
		m_listAiPlay3Animation.push_back(aiPlay3);
		//4
		std::shared_ptr<AiPlay4> aiPlay4 = std::make_shared<AiPlay4>(1220, 500);
		pointerAiPlay4 = aiPlay4;
		m_listAiPlay4Animation.push_back(aiPlay4);
		//5
		std::shared_ptr<AiPlay5> aiPlay5 = std::make_shared<AiPlay5>(1220, 550);
		pointerAiPlay5 = aiPlay5;
		m_listAiPlay5Animation.push_back(aiPlay5);
		//6
		std::shared_ptr<AiPlay6> aiPlay6 = std::make_shared<AiPlay6>(1220, 600);
		pointerAiPlay6 = aiPlay6;
		m_listAiPlay6Animation.push_back(aiPlay6);
		//7
		std::shared_ptr<AiPlay7> aiPlay7 = std::make_shared<AiPlay7>(1220, 300);
		pointerAiPlay7 = aiPlay7;
		m_listAiPlay7Animation.push_back(aiPlay7);
}

void GSPlay::Exit()
{
}


void GSPlay::Pause()
{
}

void GSPlay::Resume()
{
}


void GSPlay::HandleEvents()
{
}

void GSPlay::HandleKeyEvents(int key, bool bIsPressed)
{
	if (bIsPressed)
	{
		switch (key)
		{
		case KEY_MOVE_LEFT:
			m_KeyPress |= 1;
			break;
		case KEY_MOVE_BACKWORD:
			m_KeyPress |= 1 << 1;
			break;
		case KEY_MOVE_RIGHT:
			m_KeyPress |= 1 << 2;
			break;
		case KEY_MOVE_FORWORD:
			m_KeyPress |= 1 << 3;
			break;
		default:
			break;
		}
	}
	else
	{
		switch (key)
		{
		case KEY_MOVE_LEFT:
			m_KeyPress ^= 1;
			break;
		case KEY_MOVE_BACKWORD:
			m_KeyPress ^= 1 << 1;
			break;
		case KEY_MOVE_RIGHT:
			m_KeyPress ^= 1 << 2;
			break;
		case KEY_MOVE_FORWORD:
			m_KeyPress ^= 1 << 3;
			break;
		default:
			break;
		}
	}
}

void GSPlay::HandleTouchEvents(int x, int y, bool bIsPressed)
{
	for (auto button : m_listButton)
	{
		if (button->HandleTouchEvents(x, y, bIsPressed))
		{
			break;
		}
	}

	for (auto buttonPause : m_listButton1)
	{
		if (buttonPause->HandleTouchEvents(x, y, bIsPressed))
		{
			break;
		}
	}
}

void GSPlay::HandleMouseMoveEvents(int x, int y)
{

}

void GSPlay::TimeACC(GLfloat deltaTime)
{
	m_ACCTime += deltaTime;
	m_RandumTime = 4.0f;
	if (m_ACCTime <= m_RandumTime)
	{
		aTime = true;
	}
	else if (m_ACCTime > m_RandumTime && m_ACCTime < m_RandumTime * 2)
	{
		aTime = false;

	}
	else if (m_ACCTime > m_RandumTime * 2)
	{
		m_ACCTime = 0.0f;
	}

}

void GSPlay::CountTime(GLfloat deltaTime) 
{
	if (countTime > 0) {
		countTime -= deltaTime ;
		m_time->SetText(std::to_string(int(countTime)));
	}
}

void GSPlay::CheckDie(int key, GLfloat deltaTime)
{
	switch (key)
	{

	case 1:
		pointerSlime->Dead(1);
		if (timeMoveDie >= 0.2f)
		{
			m_KeyPress = 1;
			timeMoveDie -= deltaTime;
		}
		else {
			m_KeyPress = 0;
		}
		break;
	case 4:
		pointerSlime->Dead(1);
		if (timeMoveDie >= 0.2f)
		{
			m_KeyPress = 4;
			timeMoveDie -= deltaTime;
		}
		else {
			m_KeyPress = 0;
		}
		break;
	default:
		break;
	}
}

void GSPlay::CheckDieAiPlay(int checkAiPlayMoveOption, GLfloat deltaTime)
{
	switch (checkAiPlayMoveOption)
	{
	case 1:
		pointerAiPlay->Dead(1);
		pointerAiPlay1->Dead(1);
		pointerAiPlay4->Dead(1);
		pointerAiPlay7->Dead(1);
		if (timeMoveDie >= 0.2f)
		{
			checkAiPlayMove = 1;
			timeMoveDie -= deltaTime;
		}
		else {
			checkAiPlayMove = 0;
		}
		break;

	default:
		break;
	}
}

void GSPlay::CheckDieAiPlay1(int checkAiPlayMoveOption, GLfloat deltaTime)
{
	switch (checkAiPlayMoveOption)
	{
	case 1:
		pointerAiPlay3->Dead(1);
		pointerAiPlay6->Dead(1);
		if (timeMoveDie >= 0.2f)
		{
			checkAiPlayMove1 = 1;
			timeMoveDie -= deltaTime;
		}
		else {
			checkAiPlayMove1 = 0;
		}
		break;

	default:
		break;
	}
}
void GSPlay::CheckDieAiPlay2(int checkAiPlayMoveOption, GLfloat deltaTime)
{
	switch (checkAiPlayMoveOption)
	{
	case 1:
		pointerAiPlay5->Dead(1);
		pointerAiPlay2->Dead(1);
		if (timeMoveDie >= 0.2f)
		{
			checkAiPlayMove2 = 1;
			timeMoveDie -= deltaTime;
		}
		else {
			checkAiPlayMove2 = 0;
		}
		break;

	default:
		break;
	}
}

void GSPlay::AiPlayMove(GLfloat deltaTime)
{
	timeAiPlayMove += deltaTime;

	if (timeAiPlayMove <= 3.8f)
	{
		checkAiPlayMove = 1;
	}
	else if (timeAiPlayMove > 3.8f && timeAiPlayMove < 8.0f) {
		checkAiPlayMove = 0;
	}
	else if (timeAiPlayMove > 8.0f)
	{
		checkAiPlayMove = 1;
		timeAiPlayMove = 0.0f;
	}

}

void GSPlay::AiPlayMove1(GLfloat deltaTime)
{
	timeAiPlayMove1 += deltaTime;

	if (timeAiPlayMove1 <= 4.0f)
	{
		checkAiPlayMove1 = 1;
	}
	else if (timeAiPlayMove1 > 4.0f && timeAiPlayMove1 < 8.0f) {
		checkAiPlayMove1 = 0;
	}
	else if (timeAiPlayMove1 > 8.0f)
	{
		checkAiPlayMove1 = 1;
		timeAiPlayMove1 = 0.0f;
	}

}
void GSPlay::AiPlayMove2(GLfloat deltaTime)
{
	timeAiPlayMove2 += deltaTime;

	if (timeAiPlayMove2 <= 3.8f)
	{
		checkAiPlayMove2 = 1;
	}
	else if (timeAiPlayMove2 > 3.8f && timeAiPlayMove2 < 8.0f) {
		checkAiPlayMove2 = 0;
	}
	else if (timeAiPlayMove2 > 8.0f && timeAiPlayMove2 < 11.0f)
	{
		checkAiPlayMove2 = 1;
	}
	else if (timeAiPlayMove2 > 15.0f)
	{
		checkAiPlayMove2 = 0;
		timeAiPlayMove2 = 0.0f;
	}

}

void GSPlay::Update(float deltaTime)
{

	//count time
	CountTime(deltaTime);
	/*
	if (countTime > 0) {
		countTime -= deltaTime * 2.0f;
		m_time->SetText(std::to_string(int(countTime)));
	}
	*/

	// (ACC + backgouh + loading) MOVE
	for (auto it : m_listActorACCAnimation)
	{
		it->UpdateActorACCPos(deltaTime);
	}
	TimeACC(deltaTime);
	switch (aTime)
	{
	case true:
		pointerActorACC->Move(0);
		pointerLoading->Move(0);
		pointerBackGound->Move(0);
		break;
	case false:
		pointerActorACC->Move(1);
		pointerLoading->Move(1);
		pointerBackGound->Move(1);
		CheckDie(m_KeyPress, deltaTime);
		CheckDieAiPlay(checkAiPlayMove, deltaTime);
		CheckDieAiPlay1(checkAiPlayMove1, deltaTime); 
		CheckDieAiPlay2(checkAiPlayMove2, deltaTime);
		break;
	default:
		break;
	}

	//Slime Move
	for (auto it : m_listSlimeAnimation)
	{
		it->UpdateSlimePos(deltaTime);
	}

	switch (m_KeyPress)//Handle Key event
	{
	case 0:
		pointerSlime->Move(0);
		break;
	case 1:
		pointerSlime->Move(1);
		break;
	case 4:
		pointerSlime->Move(4);
		break;
	default:
		break;
	}

	//AiPlay Move

	for (auto it : m_listAiPlayAnimation)
	{
		it->UpdateAiPlayPos(deltaTime);
	}
		//1
		for (auto it : m_listAiPlay1Animation)
		{
			it->UpdateAiPlay1Pos(deltaTime);
		}
		//2
		for (auto it : m_listAiPlay2Animation)
		{
			it->UpdateAiPlay2Pos(deltaTime);
		}
		//3
		for (auto it : m_listAiPlay3Animation)
		{
			it->UpdateAiPlay3Pos(deltaTime);
		}
		//4
		for (auto it : m_listAiPlay4Animation)
		{
			it->UpdateAiPlay4Pos(deltaTime);
		}
		//5
		for (auto it : m_listAiPlay5Animation)
		{
			it->UpdateAiPlay5Pos(deltaTime);
		}
		//6
		for (auto it : m_listAiPlay6Animation)
		{
			it->UpdateAiPlay6Pos(deltaTime);
		}
		//7
		for (auto it : m_listAiPlay7Animation)
		{
			it->UpdateAiPlay7Pos(deltaTime);
		}
	//Option 1 AiPlay Move
	AiPlayMove(deltaTime);
	switch (checkAiPlayMove)
	{
	case 0:
		pointerAiPlay->Move(0);
		pointerAiPlay1->Move(0);
		pointerAiPlay4->Move(0);
		pointerAiPlay7->Move(0);
		break;
	case 1:
		pointerAiPlay->Move(1);
		pointerAiPlay1->Move(1);
		pointerAiPlay4->Move(1);
		pointerAiPlay7->Move(1);
		break;
	default:
		break;
	}

	//Option 2 AiPlay Move
	AiPlayMove1(deltaTime);
	switch (checkAiPlayMove1)
	{
	case 0:
		pointerAiPlay3->Move(0);
		pointerAiPlay6->Move(0);
		break;
	case 1:
		pointerAiPlay3->Move(1);
		pointerAiPlay6->Move(1);
		break;
	default:
		break;
	}
	AiPlayMove2(deltaTime);
	switch (checkAiPlayMove2)
	{
	case 0:
		pointerAiPlay5->Move(0);
		pointerAiPlay2->Move(0);
		break;
	case 1:
		pointerAiPlay5->Move(1);
		pointerAiPlay2->Move(1);
		break;
	default:
		break;
	}

	for (auto it : m_listAiPlayAnimation)
	{
		it->AiPlayUpdate(deltaTime);
	}
		//1
		for (auto it : m_listAiPlay1Animation)
		{
			it->AiPlay1Update(deltaTime);
		}
		//2
		for (auto it : m_listAiPlay2Animation)
		{
			it->AiPlay2Update(deltaTime);
		}
		//3
		for (auto it : m_listAiPlay3Animation)
		{
			it->AiPlay3Update(deltaTime);
		}
		//4
		for (auto it : m_listAiPlay4Animation)
		{
			it->AiPlay4Update(deltaTime);
		}
		//5
		for (auto it : m_listAiPlay5Animation)
		{
			it->AiPlay5Update(deltaTime);
		}
		//6
		for (auto it : m_listAiPlay6Animation)
		{
			it->AiPlay6Update(deltaTime);
		}
		//7
		for (auto it : m_listAiPlay7Animation)
		{
			it->AiPlay7Update(deltaTime);
		}
	/////////////////////////////////////////////////////////
	for (auto it : m_listButton)
	{
		it->Update(deltaTime);
	}
	for (auto it : m_listSlimeAnimation)
	{
		it->SlimeUpdate(deltaTime);
	}

	for (auto it : m_listActorACCAnimation)
	{
		it->ActorACCUpdate(deltaTime);
	}
	for (auto it : m_listLoadingAnimation)
	{
		it->LoadingUpdate(deltaTime);
	}
	for (auto it : m_listBackGoundAnimation)
	{
		it->BackGoundUpdate(deltaTime);
	}
}

void GSPlay::Draw()
{
	m_background->Draw();
	for (auto& it : m_listBackGoundAnimation)
	{
		it->BackGoundDraw();
	}
	m_BgTime->Draw();
	m_ATT->Draw();
	m_ATT1->Draw();
	m_time->Draw();
	m_time1->Draw();
	for (auto& it : m_listButton)
	{
		it->Draw();
	}
	for (auto& it : m_listButton1)
	{
		it->Draw();
	}
	for (auto& it : m_listSlimeAnimation)
	{
		it->SlimeDraw();
	}

	for (auto& it : m_listActorACCAnimation)
	{
		it->ActorACCDraw();
	}
	for (auto& it : m_listLoadingAnimation)
	{
		it->LoadingDraw();
	}
	// AiPlayDraw
	for (auto& it : m_listAiPlayAnimation)
	{
		it->AiPlayDraw();
	}
		//1
		for (auto& it : m_listAiPlay1Animation)
		{
			it->AiPlay1Draw();
		}
		//2
		for (auto& it : m_listAiPlay2Animation)
		{
			it->AiPlay2Draw();
		}
		//3
		for (auto& it : m_listAiPlay3Animation)
		{
			it->AiPlay3Draw();
		}
		//4
		for (auto& it : m_listAiPlay4Animation)
		{
			it->AiPlay4Draw();
		}
		//5
		for (auto& it : m_listAiPlay5Animation)
		{
			it->AiPlay5Draw();
		}
		//6
		for (auto& it : m_listAiPlay6Animation)
		{
			it->AiPlay6Draw();
		}
		//7
		for (auto& it : m_listAiPlay7Animation)
		{
			it->AiPlay7Draw();
		}
}