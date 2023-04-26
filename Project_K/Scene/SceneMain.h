#pragma once
#include "SceneBase.h"
#include "../Util/Vec2.h"

#include <fstream>
#include <string>
#include <vector>

class Elf;// �G���t
class ElfIdol;
class ElfAttackArrowPunch;
class ElfAttackArrowShot;
class ElfAttackArrowChargeShot;

class Kinnikurou;// ����ɂ��낤
class KinnnikuIdle;

class Stage;

class SceneMain : public SceneBase
{
public:
	SceneMain(bool player1, bool player2, bool player3, bool player4);
	virtual ~SceneMain();

	virtual void Init();
	virtual void End();

	virtual SceneBase* Update() override;
	virtual void Draw();

	void test(std::string writing_text);// �����͓��͕���

private:

	void ElfMoveIdol();// �G���t�ҋ@���[�V����
	void ElfMoveAttack();// �G���t��{�U�����[�V����
	void ElfMoveAttackShot();// �G���t�|��ōU�����[�V����
	void ElfMoveAttackChargeShot();// �G���t�`���[�W�V���b�g�U�����[�V����
	void ElfData();// �G���t�ʒu,����,�U����,�̃f�[�^

	void KinnikurouMoveIdol();// ����ɂ��낤�ҋ@���[�V����
	void KinnikurouData();// ����ɂ��낤�ʒu,����,�U����,�̃f�[�^

	int m_hPlayer = -1;// �v���C���[�摜�f�[�^
	std::vector<int>m_vHPlayer;

	int m_playerNum;

	int m_imageX = 0, m_imageY = 0;// �v���C���[�摜�ʒu
	std::vector<int>m_vImageX, m_vImageY;
	std::vector<int>m_vImageSizeX, m_vImageSizeY;

	int m_left = 0, m_top = 0, m_right = 0, m_bottom = 0;

	Vec2 m_pos = { 0.0f,0.0f };//�v���C���[�ʒu

	std::vector<Vec2> m_vPos = { {0.0f,0.0f},{0.0f,0.0f} };// �v���C���[�ʒu��錾

	Elf* m_pElf;// �G���t�|�C���^��
	ElfIdol* m_pElfIdol;
	ElfAttackArrowPunch* m_pElfAttackNormal;
	ElfAttackArrowShot* m_pElfAttackShot;
	ElfAttackArrowChargeShot* m_pElfAttackChargeShot;

	Kinnikurou* m_pKinnikurou;// ����ɂ��낤�|�C���^��
	//KinnnikuIdle* m_pKinnnikuIdle;


	std::shared_ptr<Stage> m_pStage;// �X�e�[�W�̃|�C���^

	bool m_isPlayerDrawTest[4];

	std::ofstream writing_file;
	std::string filename = "Test.csv";

	std::string str;


};


	