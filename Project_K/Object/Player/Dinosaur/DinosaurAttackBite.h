#pragma once
#include "DinosaurStateBase.h"
class DinosaurAttackBite : public DinosaurStateBase
{
public:
	DinosaurAttackBite();
	virtual ~DinosaurAttackBite();

	virtual DinosaurStateBase* Update() override;
};

