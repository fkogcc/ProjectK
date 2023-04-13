#pragma once
#include "SceneBase.h"
#include "../Util/Vec2.h"

#include <fstream>
#include <string>

class Elf;
class ElfIdol;
class ElfAttackArrowPunch;
class ElfAttackArrowShot;
class ElfAttackArrowChargeShot;

class SceneMain : public SceneBase
{
public:
	SceneMain(bool player);
	virtual ~SceneMain();

	virtual void Init();
	virtual void End();

	virtual SceneBase* Update() override;
	virtual void Draw();

	void test(std::string writing_text);// �����͓��͕���

private:

	virtual void ElfMoveIdol            ();// �G���t�ҋ@���[�V����
	virtual void ElfMoveAttack          ();// �G���t��{�U�����[�V����
	virtual void ElfMoveAttackShot      ();// �G���t�|��ōU�����[�V����
	virtual void ElfMoveAttackChargeShot();// �G���t�`���[�W�V���b�g�U�����[�V����
	virtual void ElfData            ();// �G���t�ʒu,����,�U����,�̃f�[�^

	int m_hPlayer = -1;// �v���C���[�摜�f�[�^

	int m_imageX = 0,m_imageY = 0;// �v���C���[�摜�ʒu

	int m_left = 0, m_top = 0, m_right = 0, m_bottom = 0;

	Vec2 m_pos = { 0.0f,0.0f };//�v���C���[�ʒu

	Elf*				      m_pElf;// �G���t�|�C���^��
	ElfIdol*			      m_pElfIdol;
	ElfAttackArrowPunch*      m_pElfAttackNormal;
	ElfAttackArrowShot*       m_pElfAttackShot;
	ElfAttackArrowChargeShot* m_pElfAttackChargeShot;

	bool m_isPlayerDrawTest;

	std::ofstream writing_file;
	std::string filename = "Test.csv";

	std::string str;
};

