#pragma once

#include "../Base/MoveTypeBase.h"

class KinnnikuIdle : public MoveTypeBase
{
public:
	KinnnikuIdle();
	virtual ~KinnnikuIdle();

	void Init();// ������
	void End();// �I��
	void Update();// �X�V

private:
};

