#pragma once
#include <DxLib.h>
#include "../../Util/Pad.h"
#include "../../Util/Vec2.h"

class PlayerBase //�v���C���[�̊��N���X
{
public:
	PlayerBase() {};
	virtual ~PlayerBase() {};

	virtual void Init  () {};// ������
	virtual void End   () {};// �I������
	virtual void Update() {};// �X�V
	virtual void Draw  () {};// �`��
	
	int SetPosLeft  () { return m_posLeft;   }// SceneMain�Ƀv���C���[�̈ʒu��n��
	int SetPosTop   () { return m_posTop;    }
	int SetPosRight () { return m_posRight;  }
	int SetPosBottom() { return m_posBottom; }

	int SetMove() { return m_moveType; }// SceneMain�ɂǂ̍U�������Ă��邩��n��
	void GetMove(int check) { m_moveType = check; }// SceneMain����U����Ԃ��󂯎��
	void GetDamage(int damage) { m_damage = damage; }// SceneMain����v���C���[���󂯂�_���[�W���󂯎��

	Vec2 SetPos() { return m_pos; }

protected:
	int m_posLeft   = 0;// �v���C���[�̈ʒu(�����蔻�p��)
	int m_posTop    = 0;
	int m_posRight  = 0;
	int m_posBottom = 0;

	int m_moveType = 0;
	int m_hp     = 100;// �v���C���[�̗̑͗�(100���W��)
	int m_damage = 0; // �v���C���[���󂯂�_���[�W

	Vec2 m_pos = { 0.0f,0.0f };// �ʒu
	Vec2 m_vec = { 0.0f,0.0f };// �^����
};

