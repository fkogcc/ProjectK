#pragma once

#include "../Base/PlayerBase.h"

class KinnikurouIdle;
class KinnikurouJab;

class Kinnikurou : public PlayerBase
{
public:
	Kinnikurou();
	virtual ~Kinnikurou();

	void Init  ();// ������
	void End   ();// �I������
	void Update();// �X�V
	void Draw  ();// �`��
private:

	Kinnikurou* m_pIdle;

	bool m_pushBottom;

	// �n���h��
	int m_charHandle;// �L�����N�^�[�S��
	int m_idleHandle;// �A�C�h�����
	int m_jabHandle;// �W���u�U�����

	// �`����W
	int m_drawPosX;// X
	int m_drawPosY;// Y

	// �摜�̍��W
	int m_imgPosX;// X
	int m_imgPosY;// Y

};

