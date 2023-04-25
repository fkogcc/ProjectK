#pragma once
#include "DinosaurStateBase.h"
class DinosaurIdle : public DinosaurStateBase
{
public:
	DinosaurIdle();
	virtual ~DinosaurIdle();

	virtual DinosaurStateBase* Update() override;
};

