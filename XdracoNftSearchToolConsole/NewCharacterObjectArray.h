#pragma once
#include "Character.h"

class NewCharacterObjectArray
{
public:
	NewCharacterObjectArray(int count);
	~NewCharacterObjectArray();
	Character* character();
private:
	Character* character_;
};
