#pragma once

#include"DinosaurStateBase.h"

class DinosaurAttackManager
{
public:
	DinosaurAttackManager();
	virtual ~DinosaurAttackManager() {}
	// ������
	void Init();
	// �I��
	void End();
	// ���t���[���̏���
	void Update();
	// �`��
	void Draw();

private:
	// �V�[���x�[�X�|�C���^
	DinosaurStateBase* m_pAttack;
};

