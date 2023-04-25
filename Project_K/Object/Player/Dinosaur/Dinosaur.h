#pragma once
#include "../Base/PlayerBase.h"

class DinosaurAttackManager;
class Dinosaur : public PlayerBase
{
public:
	Dinosaur();
	~Dinosaur();

	void Init();// ‰Šú‰»
	void End();// I—¹ˆ—
	void Update();// XV
	void Draw();// •`‰æ
private:
	DinosaurAttackManager* m_AttackManager;
};

