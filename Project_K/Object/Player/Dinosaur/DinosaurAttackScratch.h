#pragma once
#include "DinosaurStateBase.h"
class DinosaurAttackScratch : public DinosaurStateBase
{
public:

	DinosaurAttackScratch();
	virtual ~DinosaurAttackScratch();

	virtual DinosaurStateBase* Update() override;
};

