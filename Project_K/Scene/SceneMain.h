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

	void test(std::string writing_text);// 引数は入力文字

private:

	virtual void ElfMoveIdol            ();// エルフ待機モーション
	virtual void ElfMoveAttack          ();// エルフ基本攻撃モーション
	virtual void ElfMoveAttackShot      ();// エルフ弓矢で攻撃モーション
	virtual void ElfMoveAttackChargeShot();// エルフチャージショット攻撃モーション
	virtual void ElfData            ();// エルフ位置,方向,攻撃力,のデータ

	int m_hPlayer = -1;// プレイヤー画像データ

	int m_imageX = 0,m_imageY = 0;// プレイヤー画像位置

	int m_left = 0, m_top = 0, m_right = 0, m_bottom = 0;

	Vec2 m_pos = { 0.0f,0.0f };//プレイヤー位置

	Elf*				      m_pElf;// エルフポインタ類
	ElfIdol*			      m_pElfIdol;
	ElfAttackArrowPunch*      m_pElfAttackNormal;
	ElfAttackArrowShot*       m_pElfAttackShot;
	ElfAttackArrowChargeShot* m_pElfAttackChargeShot;

	bool m_isPlayerDrawTest;

	std::ofstream writing_file;
	std::string filename = "Test.csv";

	std::string str;
};

