#include "DinosaurIdle.h"
#include "../Base/PlayerBase.h"
#include "DinosaurAttackScratch.h"
#include "DinosaurAttackPounce.h"
#include "DinosaurAttackShot.h"
#include "DinosaurAttackBite.h"


DinosaurIdle::DinosaurIdle()
{
}

DinosaurIdle::~DinosaurIdle()
{
}

DinosaurStateBase* DinosaurIdle::Update()
{
	if (Pad::isTrigger(PAD_INPUT_1))// XBOX A
	{
		return new DinosaurAttackScratch;
	}
	if (Pad::isTrigger(PAD_INPUT_2))// XBOX B
	{
		return new DinosaurAttackScratch;
	}
	if (Pad::isTrigger(PAD_INPUT_3) || (Pad::isTrigger(PAD_INPUT_4)))// XBOX X or Y
	{
		return new DinosaurAttackScratch;
	}
	return this;
}
