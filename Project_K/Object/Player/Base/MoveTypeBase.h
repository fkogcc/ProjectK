#pragma once

#include "../../Util/Vec2.h"

class MoveTypeBase //�v���C���[�̊��N���X
{
public:
	MoveTypeBase() {};
	virtual ~MoveTypeBase() {};

	virtual void Update() {};// �X�V

	int SetPosAttackLeft  () { return m_posAttackLeft;   } //SceneMain�Ƀv���C���[�̍U���͈͂�n��
	int SetPosAttackTop   () { return m_posAttackTop;    }
	int SetPosAttackRight () { return m_posAttackRight;  }
	int SetPosAttackBottom() { return m_posAttackBottom; }

	int SetPosImageX() { return m_imagePosX; }// �摜�̃L�����̂ǂ���`������邩�ǂ���
	int SetPosImageY() { return m_imagePosY; }

	int SetAttackDamage() { return m_attackDamage; }// �G�ɗ^����_���[�W��

	bool IsSetMove() { return m_isMove; }
	void SetMoveTime(bool move) { m_isMove = move; }

protected:
	int m_posAttackLeft   = 0;// �v���C���[�̍U���͈�
	int m_posAttackTop    = 0;
	int m_posAttackRight  = 0;
	int m_posAttackBottom = 0;

	int m_frameCount = 0;// �A�j���[�V�������Đ�������p�t���[���J�E���g

	int m_imagePosX = 0;// �摜�̕`��ʒu
	int m_imagePosY = 0;

	int m_attackDamage = 0;// �v���C���[���G�l�~�[�ɗ^����_���[�W��
	bool m_isMove = false;
	Vec2 m_vec = { 0.0f,0.0f };// �^����
};