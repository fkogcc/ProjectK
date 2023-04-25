#pragma once

#include"DinosaurStateBase.h"

class DinosaurAttackManager
{
public:
	DinosaurAttackManager();
	virtual ~DinosaurAttackManager() {}
	// 初期化
	void Init();
	// 終了
	void End();
	// 毎フレームの処理
	void Update();
	// 描画
	void Draw();

private:
	// シーンベースポインタ
	DinosaurStateBase* m_pAttack;
};

