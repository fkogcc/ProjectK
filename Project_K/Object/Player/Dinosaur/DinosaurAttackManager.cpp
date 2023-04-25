#include "DinosaurAttackManager.h"
#include <cassert>
#include "DinosaurAttackBite.h"
#include "DinosaurAttackPounce.h"
#include "DinosaurAttackScratch.h"
#include "DinosaurAttackShot.h"
#include "DinosaurIdle.h"
#include "DinosaurJump.h"
#include "DinosaurMove.h"
#include "DinosaurIdle.h"

DinosaurAttackManager::DinosaurAttackManager() :
	m_pAttack(nullptr)
{
}
// ������
void DinosaurAttackManager::Init()
{
	m_pAttack = new DinosaurIdle;
}
// �I��
void DinosaurAttackManager::End()
{
	assert(m_pAttack);// �m�F����
	if (!m_pAttack)	return;

	//m_pAttack->End();// �I������
	//delete m_pScene;
}
// ���t���[���̏���
void DinosaurAttackManager::Update()
{
	assert(m_pAttack);// �m�F����
	if (!m_pAttack)	return;

	DinosaurStateBase* pAttack = m_pAttack->Update();// AttackBase��update�����Ăяo��

	if (m_pAttack != m_pAttack)
	{
		//m_pAttack->End();// �I������
		//delete m_pScene;

		m_pAttack = m_pAttack;
		//m_pScene->Init();// ������
	}
}
// �`��
void DinosaurAttackManager::Draw()
{
	assert(m_pAttack);
	if (!m_pAttack)	return;
//	m_pAttack->Draw();// �`��
}