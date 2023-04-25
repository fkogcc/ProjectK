#pragma once
#include "DinosaurStateBase.h"
class DinosaurAttackPounce : public DinosaurStateBase
{
public:
	DinosaurAttackPounce();
	virtual ~DinosaurAttackPounce();

	virtual DinosaurStateBase* Update() override;
};

