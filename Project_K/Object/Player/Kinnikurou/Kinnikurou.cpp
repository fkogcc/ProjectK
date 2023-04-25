#include "Kinnikurou.h"
#include "../../condition.h"
#include "../../Util/DrawFunctions.h"
#include "KinnnikuIdle.h"
#include "KinnikurouJab.h"

namespace
{
	const char* const kIdle = "Data/Image/Player/Kinnikurou/Idle";
	const char* const kJab = "Data/Image/Player/Kinnikurou/AttackNeutral.png";
}

Kinnikurou::Kinnikurou() :
	m_pIdle(nullptr),
	m_pushBottom(false),
	m_charHandle(-1),
	m_idleHandle(-1),
	m_jabHandle(-1),
	m_drawPosX(0),
	m_drawPosY(0),
	m_imgPosX(0),
	m_imgPosY(0)
{
	m_pIdle = new KinnikurouIdle;
}

Kinnikurou::~Kinnikurou()
{
	delete m_pIdle;
	m_pIdle = nullptr;
}

void Kinnikurou::Init()
{
	m_idleHandle = my::MyLoadGraph(kIdle);
	m_jabHandle = my::MyLoadGraph(kJab);

	m_drawPosX = 200;
	m_drawPosY = 900;

	m_imgPosX = 0;
	m_imgPosY = 0;
}

void Kinnikurou::End()
{
	my::MyDeleteGraph(m_idleHandle);
	my::MyDeleteGraph(m_jabHandle);
}

void Kinnikurou::Update()
{
	Pad::update();

	if (!m_pushBottom) m_moveType = static_cast<int>(moveType::Idol);// �A�C�h�����
	if (Pad::isTrigger(PAD_INPUT_2)) m_pushBottom = false;

	m_moveType = static_cast<int>(moveType::Attack1);// �W���u�U�����

	if (Pad::isPress(PAD_INPUT_RIGHT))m_pos.x += 10;
	if (Pad::isPress(PAD_INPUT_LEFT))m_pos.x -= 10;

	// �A�C�h�����
	if (m_moveType == static_cast<int>(moveType::Idol)) m_pIdle->Update();
	if (m_moveType == static_cast<int>(moveType::Idol)) m_pIdle->Update();


}

void Kinnikurou::Draw()
{
	// �A�C�h�����
	if (m_moveType == static_cast<int>(moveType::Idol)) m_charHandle = m_idleHandle;
	// �W���u�U�����
	if (m_moveType == static_cast<int>(moveType::Attack1)) m_charHandle = m_jabHandle;

	// �L�����N�^�[�̕`��
	if (m_moveType == static_cast<int>(moveType::Idol)) 
	{
		my::MyDrawRectRotaGraph(m_drawPosX, m_drawPosY,
			m_imgPosX * 18, m_imgPosY * 23,
			18, 23,
			3.0f, 0.0f,
			m_charHandle,
			true, false);
	}
}
