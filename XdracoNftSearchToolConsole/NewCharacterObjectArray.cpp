#include "NewCharacterObjectArray.h"

NewCharacterObjectArray::NewCharacterObjectArray(int count) {
	character_ = new Character[count]();
}

NewCharacterObjectArray::~NewCharacterObjectArray() {
	delete[] character_;
}

Character* NewCharacterObjectArray::character() {
	return character_;
}
