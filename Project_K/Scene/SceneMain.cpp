#include "SceneMain.h"
#include "../Object/Player/Elf/Elf.h"
#include "../Util/DrawFunctions.h"
#include "../Object/Player/Elf/ElfIdol.h"
#include "../Object/Player/Elf/ElfAttackArrowPunch.h"
#include "../Object/Player/Elf/ElfAttackArrowShot.h"
#include "../Object/Player/Elf/ElfAttackArrowChargeShot.h"
#include "../condition.h"
#include <assert.h>

#include <iostream>

namespace// �����͉��̃l�[���X�y�[�X�ł� ���F�L�����I�����
{
	const char* const kPlayerImage = "Data/Image/Player/Elf/Elf.png";
}
SceneMain::SceneMain(bool player1, bool player2, bool player3, bool player4) :
	m_pos             (0.0f,0.0f),// �v���C���[�ʒu
	m_pElf            (nullptr),  // �G���t�p�|�C���^��
	m_pElfIdol        (nullptr),
	m_pElfAttackNormal(nullptr),
	m_pElfAttackShot  (nullptr),
	m_pElfAttackChargeShot(nullptr)
{
	m_isPlayerDrawTest[0] = player1;
	m_isPlayerDrawTest[1] = player2;
	m_isPlayerDrawTest[2] = player3;
	m_isPlayerDrawTest[3] = player4;

	m_pElf                 = new Elf;// �G���t�p�|�C���^��
	m_pElfIdol             = new ElfIdol;
	m_pElfAttackNormal     = new ElfAttackArrowPunch;
	m_pElfAttackShot       = new ElfAttackArrowShot;
	m_pElfAttackChargeShot = new ElfAttackArrowChargeShot;

	for (int i = 0; i < 4; i++)
	{
		m_vPos.push_back(Vec2(0.0f, 0.0f));
		m_vImageX.push_back(0);
		m_vImageY.push_back(0);
		m_vImageSizeX.push_back(288);
		m_vImageSizeY.push_back(128);
		m_vHPlayer.push_back(-1);
	}
}

SceneMain::~SceneMain()
{
	delete m_pElf;// �G���t�|�C���^���
	delete m_pElfIdol;
	delete m_pElfAttackNormal;
	delete m_pElfAttackShot;
	delete m_pElfAttackChargeShot;
}

void SceneMain::Init()
{
//	m_hPlayer = my::MyLoadGraph(kPlayerImage);// �������ɉ摜�f�[�^�ǂݍ���
	m_vHPlayer[0] = my::MyLoadGraph(kPlayerImage);// �������ɉ摜�f�[�^�ǂݍ���

	//writing_file.open(filename, std::ios::ate);//app�t�@�C������������͊J�n
	//writing_file.close();// �t�@�C�������
}

void SceneMain::End()
{
	my::MyDeleteGraph(m_hPlayer);//�摜�f�[�^���������
}

void SceneMain::ElfMoveIdol()// �G���t�ҋ@���[�V����
{
	m_pElfIdol->Update();// �G���t�̃A�C�h�����
	if (m_pElf->SetMove() == static_cast<int>(moveType::Idol))// �������Ă��Ȃ��ꍇ�̓A�C�h�����
	{
		//m_imageX = m_pElfIdol->SetPosImageX();// �A�C�h����ԗp�摜���[�V�����ʒu
		//m_imageY = m_pElfIdol->SetPosImageY();
		m_vImageX[0] = m_pElfIdol->SetPosImageX();// �A�C�h����ԗp�摜���[�V�����ʒu
		m_vImageY[0] = m_pElfIdol->SetPosImageY();
	}
}

void SceneMain::ElfMoveAttack()// �G���t��{�U�����[�V����
{
	m_pElfAttackNormal->Update();// �G���t�̍U�����[�V����
	if (m_pElf->SetMove() == static_cast<int>(moveType::Attack1))// �v���C���[��Pad1����������U��
	{
		m_pElfAttackNormal->SetMoveTime(true);// �U����L����
	}
	if (m_pElfAttackNormal->IsSetMove())// �U���A�j���[�V�������Đ�
	{
	//	m_imageX = m_pElfAttackNormal->SetPosImageX();// �U���p�摜���[�V�����ʒu
	//	m_imageY = m_pElfAttackNormal->SetPosImageY();
		m_vImageX[0] = m_pElfAttackNormal->SetPosImageX();// �U���p�摜���[�V�����ʒu
		m_vImageY[0] = m_pElfAttackNormal->SetPosImageY();

		if (!m_pElfAttackNormal->IsSetMove())// �A�j���[�V�������Ō�܂ōĐ����ꂽ��
		{
			m_pElfAttackNormal->SetMoveTime(false);// �A�j���[�V������~
		}
	}
}

void SceneMain::ElfMoveAttackShot()
{
	m_pElfAttackShot->Update();// �G���t�̍U�����[�V����
	if (m_pElf->SetMove() == static_cast<int>(moveType::Attack2))// �v���C���[��Pad1����������U��
	{
		m_pElfAttackShot->SetMoveTime(true);// �U����L����
	}
	if (m_pElfAttackShot->IsSetMove())// �U���A�j���[�V�������Đ�
	{
	//  m_imageX = m_pElfAttackShot->SetPosImageX();// �U���p�摜���[�V�����ʒu
	//	m_imageY = m_pElfAttackShot->SetPosImageY();
		m_vImageX[0] = m_pElfAttackShot->SetPosImageX();// �U���p�摜���[�V�����ʒu
		m_vImageY[0] = m_pElfAttackShot->SetPosImageY();

		if (!m_pElfAttackShot->IsSetMove())// �A�j���[�V�������Ō�܂ōĐ����ꂽ��
		{
			m_pElfAttackShot->SetMoveTime(false);// �A�j���[�V������~
		}
	}
}

void SceneMain::ElfMoveAttackChargeShot()
{
	m_pElfAttackChargeShot->Update();// �G���t�̍U�����[�V����
	if (m_pElf->SetMove() == static_cast<int>(moveType::Attack3))// �v���C���[��Pad1����������U��
	{
		m_pElfAttackChargeShot->SetMoveTime(true);// �U����L����
	}
	if (m_pElfAttackChargeShot->IsSetMove())// �U���A�j���[�V�������Đ�
	{
	//	m_imageX = m_pElfAttackChargeShot->SetPosImageX();// �U���p�摜���[�V�����ʒu
	//	m_imageY = m_pElfAttackChargeShot->SetPosImageY();
		m_vImageX[0] = m_pElfAttackChargeShot->SetPosImageX();// �U���p�摜���[�V�����ʒu
		m_vImageY[0] = m_pElfAttackChargeShot->SetPosImageY();

		if (!m_pElfAttackChargeShot->IsSetMove())// �A�j���[�V�������Ō�܂ōĐ����ꂽ��
		{
			m_pElfAttackChargeShot->SetMoveTime(false);// �A�j���[�V������~
		}
	}
}

void SceneMain::ElfData()// �G���t�ʒu�Ȃǂ̑��
{
	//m_pos.x = m_pElf->SetPos().x;// �G���t�̈ʒu
	//m_pos.y = m_pElf->SetPos().y;

	m_vPos[0].x = m_pElf->SetPos().x;// �G���t�̈ʒu
	m_vPos[0].y = m_pElf->SetPos().y;

	m_left   = m_pElf->SetPosLeft  ();
	m_top    = m_pElf->SetPosTop   ();
	m_right  = m_pElf->SetPosRight ();
	m_bottom = m_pElf->SetPosBottom();
}

SceneBase* SceneMain::Update()
{
	if (m_isPlayerDrawTest)// �G���t���I�����ꂽ���ǂ���
	{
		m_pElf->Update();// �G���t�̍s������
		ElfMoveIdol	           ();// �G���t�ҋ@���[�V����
		ElfMoveAttack	       ();// �G���t��{�U�����[�V����
		ElfMoveAttackShot      ();// �G���t�|��ōU�����[�V����
		ElfMoveAttackChargeShot();// �G���t�`���[�W�V���b�g�U�����[�V����
		ElfData                ();// �G���t�ʒu,����,�U����,�̃f�[�^
	}



	return this;
}

void SceneMain::Draw()
{
	if (m_isPlayerDrawTest)// �G���t���I�����ꂽ���ǂ���
	{
		// �v���C���[�A�j���[�V�����`��
		//my::MyDrawRectRotaGraph(m_pos.x, m_pos.y,
		//	m_imageX, m_imageY, 288, 128,
		//	1.5 * 3, DX_PI * 2, m_hPlayer, true, false);
		// �G���t�̉摜�P�L����
		// ��288
		// �c136
	}

	for (int i = 0; i < 4; i++)
	{
		my::MyDrawRectRotaGraph(m_vPos[i].x, m_vPos[i].y,
			m_vImageX[i], m_vImageY[i], m_vImageSizeX[i], m_vImageSizeY[i],
			1.5 * 3, DX_PI * 2, m_vHPlayer[i], true, false);
	}


	DrawBox(m_left, m_top, m_right,m_bottom,0xff0000,false);// �����蔻��m�F�p
}


void SceneMain::test(std::string writing_text)// �����͓��͕���
{
	writing_file.open(filename, std::ios::app);// �t�@�C���̂ǂ��ɏ������ނ�
	assert(writing_file);// �t�@�C������ɓ����Ă��邩�m�F
	writing_file << writing_text << std::endl;// ��������
	writing_file.close();// �t�@�C�������
}
