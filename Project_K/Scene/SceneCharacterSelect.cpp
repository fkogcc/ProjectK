#include "SceneCharacterSelect.h"
#include "SceneMain.h"

SceneCharacterSelect::SceneCharacterSelect()
{
}

SceneCharacterSelect::~SceneCharacterSelect()
{
}

void SceneCharacterSelect::Init()
{
}

void SceneCharacterSelect::End()
{
}

SceneBase* SceneCharacterSelect::Update()
{

#if true// SceneMain�R���X�g���N�^��������
	// m_pSceneMain = new SceneMain(true);
	return(new SceneMain(true, true, true, true));// 1�X�e�[�W�؂�ւ�
#else	// SceneMain�R���X�g���N�^�����Ȃ�
	return(new SceneMain);// 1�X�e�[�W�؂�ւ�
#endif
	return this;
}

void SceneCharacterSelect::Draw()
{
}
