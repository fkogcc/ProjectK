#pragma once

#include "../Base/PlayerBase.h"

class KinnikurouIdle;

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

	// �n���h��
	int m_idleHandle;// �A�C�h�����
	

	// �`����W
	int m_drawPosX;// X
	int m_drawPosY;// Y

	// �摜�̍��W
	int m_imgPosX;// X
	int m_imgPosY;// Y

};

