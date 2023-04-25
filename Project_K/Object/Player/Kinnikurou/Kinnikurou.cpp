#include "Kinnikurou.h"
#include "../../condition.h"
#include "../../Util/DrawFunctions.h"
#include "KinnnikuIdle.h"

namespace
{
	const char* const kIdle = "Data/Image/Player/Kinnikurou/Idle";
}

Kinnikurou::Kinnikurou() :
	m_pIdle(new Kinnikurou),
	m_idleHandle(-1),
	m_drawPosX(0),
	m_drawPosY(0),
	m_imgPosX(0),
	m_imgPosY(0)
{

}

Kinnikurou::~Kinnikurou()
{
	delete m_pIdle;
	m_pIdle = nullptr;
}

void Kinnikurou::Init()
{
	m_idleHandle = my::MyLoadGraph(kIdle);

	m_drawPosX = 200;
	m_drawPosY = 900;

	m_imgPosX = 0;
	m_imgPosY = 0;
}

void Kinnikurou::End()
{
	my::MyDeleteGraph(m_idleHandle);
}

void Kinnikurou::Update()
{
	Pad::update();

	m_moveType = static_cast<int>(moveType::Idol);// アイドル状態

	if (Pad::isPress(PAD_INPUT_RIGHT))m_pos.x += 10;
	if (Pad::isPress(PAD_INPUT_LEFT))m_pos.x -= 10;

	// アイドル状態
	if (m_moveType == static_cast<int>(moveType::Idol)) m_pIdle->Update();

}

void Kinnikurou::Draw()
{
	// キャラクターの描画
	if (m_moveType == static_cast<int>(moveType::Idol)) 
	{
		my::MyDrawRectRotaGraph(m_drawPosX, m_drawPosY,
			m_imgPosX * 18, m_imgPosY * 23,
			18, 23,
			3.0f, 0.0f,
			m_idleHandle,
			true, false);
	}
}
