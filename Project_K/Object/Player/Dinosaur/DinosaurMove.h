#pragma once
#include "DinosaurStateBase.h"
class DinosaurMove : public DinosaurStateBase
{
public:
	DinosaurMove();
	virtual ~DinosaurMove();

	virtual DinosaurStateBase* Update() override;
};

