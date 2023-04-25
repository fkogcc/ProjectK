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
// 初期化
void DinosaurAttackManager::Init()
{
	m_pAttack = new DinosaurIdle;
}
// 終了
void DinosaurAttackManager::End()
{
	assert(m_pAttack);// 確認処理
	if (!m_pAttack)	return;

	//m_pAttack->End();// 終了処理
	//delete m_pScene;
}
// 毎フレームの処理
void DinosaurAttackManager::Update()
{
	assert(m_pAttack);// 確認処理
	if (!m_pAttack)	return;

	DinosaurStateBase* pAttack = m_pAttack->Update();// AttackBaseのupdate処理呼び出し

	if (m_pAttack != m_pAttack)
	{
		//m_pAttack->End();// 終了処理
		//delete m_pScene;

		m_pAttack = m_pAttack;
		//m_pScene->Init();// 初期化
	}
}
// 描画
void DinosaurAttackManager::Draw()
{
	assert(m_pAttack);
	if (!m_pAttack)	return;
//	m_pAttack->Draw();// 描画
}