#pragma once
#include "DinosaurStateBase.h"
class DinosaurAttackShot : public DinosaurStateBase
{
public:
	DinosaurAttackShot();
	virtual ~DinosaurAttackShot();

	virtual DinosaurStateBase* Update() override;
};

