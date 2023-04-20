#include "Kinnikurou.h"
#include "../../condition.h"


Kinnikurou::Kinnikurou()
{

}

Kinnikurou::~Kinnikurou()
{
}

void Kinnikurou::Init()
{
}

void Kinnikurou::End()
{
}

void Kinnikurou::Update()
{
	Pad::update();

	m_moveType = static_cast<int>(moveType::Idol);// �A�C�h�����

	if (Pad::isPress(PAD_INPUT_RIGHT))m_pos.x += 10;
	if (Pad::isPress(PAD_INPUT_LEFT))m_pos.x -= 10;
	if (Pad::isPress(PAD_INPUT_UP))m_pos.y -= 10;
	if (Pad::isPress(PAD_INPUT_DOWN))m_pos.y += 10;

	if (Pad::isTrigger(PAD_INPUT_1))// XBOX A
	{
		m_moveType = static_cast<int>(moveType::Attack2);;// �U��
	}
	if (Pad::isTrigger(PAD_INPUT_2))// XBOX B
	{
		m_moveType = static_cast<int>(moveType::Attack1);;// �U��
	}
	if (Pad::isTrigger(PAD_INPUT_3) || (Pad::isTrigger(PAD_INPUT_4)))// XBOX X or Y
	{
		//�@�W�����v
	}
	if (Pad::isTrigger(XINPUT_BUTTON_LEFT_SHOULDER) || (Pad::isTrigger(PAD_INPUT_R)))// XBOX X or Y
	{
		//�@�W�����v
		printfDx("aaaa");
	}
	if (Pad::isTrigger(PAD_INPUT_1) && (Pad::isTrigger(PAD_INPUT_RIGHT)) ||// XBOX A && RIGHT
		Pad::isTrigger(PAD_INPUT_1) && (Pad::isTrigger(PAD_INPUT_LEFT)))   // XBOX A && LEFT
	{
		m_moveType = static_cast<int>(moveType::Attack3);;// �U��
	}

	m_posLeft = m_pos.x - 50;// �v���C���[�̃T�C�Y
	m_posTop = m_pos.y + 90;
	m_posRight = m_posLeft + 100;
	m_posBottom = m_posTop + 195;

}

void Kinnikurou::Draw()
{

}
