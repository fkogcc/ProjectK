#pragma once
#include "DinosaurStateBase.h"
class DinosaurJump : public DinosaurStateBase
{
public:
	DinosaurJump();
	virtual ~DinosaurJump();

	virtual DinosaurStateBase* Update() override;
};

