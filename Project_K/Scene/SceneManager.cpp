#include <cassert>
#include "SceneManager.h"
#include "SceneMain.h"
#include "SceneTitle.h"
#include "SceneCharacterSelect.h"

SceneManager::SceneManager():
	m_pScene(nullptr)
{
}
// 初期化
void SceneManager::Init()
{
	m_pScene = new SceneCharacterSelect;
	m_pScene->Init();
}
// 終了
void SceneManager::End()
{
	assert(m_pScene);// 確認処理
	if (!m_pScene)	return;

	m_pScene->End();// 終了処理
	delete m_pScene;
}
// 毎フレームの処理
void SceneManager::Update()
{
	assert(m_pScene);// 確認処理
	if (!m_pScene)	return;

	SceneBase* pScene = m_pScene->Update();// SceneBaseのupdate処理呼び出し

	if (pScene != m_pScene)
	{
		m_pScene->End();// 終了処理
		delete m_pScene;
		
		m_pScene = pScene;
		m_pScene->Init();// 初期化
	}
}
// 描画
void SceneManager::Draw()
{
	assert(m_pScene);
	if (!m_pScene)	return;
	m_pScene->Draw();// 描画
}