#pragma once
#include "../../../condition.h"
class DinosaurStateBase
{
public:
	DinosaurStateBase() {}
	virtual ~DinosaurStateBase(){};

	virtual DinosaurStateBase* Update() { return this; }
};

