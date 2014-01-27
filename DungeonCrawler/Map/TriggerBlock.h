#pragma once
#include "Block.h"
#include "../Entity.h"

class TriggerBlock : public Block
{
public:
	TriggerBlock(unsigned int id, int x, int y, unsigned int tex);
	virtual ~TriggerBlock();
	virtual bool Use() override;
private:
	Entity* entity;
	Block* block;
};

