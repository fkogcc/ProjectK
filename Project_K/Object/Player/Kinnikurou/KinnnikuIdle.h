#pragma once

#include "../Base/MoveTypeBase.h"

class KinnnikuIdle : public MoveTypeBase
{
public:
	KinnnikuIdle();
	virtual ~KinnnikuIdle();

	void Init();// 初期化
	void End();// 終了
	void Update();// 更新

private:
};

