#pragma once
#include <DxLib.h>

// �Q�[���V�[�����N���X
class SceneBase
{
public:
	SceneBase() {}
	virtual ~SceneBase() {}
	virtual void Init        () {			   }// ������
	virtual void End         ()	{			   }// �I��
	virtual SceneBase* Update() { return this; }// ���t���[���̏���
	virtual void Draw        ()	{              }// �`��
};

