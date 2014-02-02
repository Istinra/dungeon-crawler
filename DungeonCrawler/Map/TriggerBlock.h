#pragma once
#include "Block.h"
#include "../Entity.h"

class TriggerBlock : public Block
{
public:
	TriggerBlock(unsigned int id, int x, int y, unsigned int tex);
	virtual ~TriggerBlock();
	virtual bool Use(Item& item) override;

	void SetBlockToTrigger(Block* b)
	{ 
		this->block = b; 
	}
	inline const unsigned int TargetId() 
	{ 
		return targetId; 
	}
	inline void TargetId(unsigned int tId) 
	{ 
		targetId = tId; 
	}
private:
	unsigned int targetId;
	Block* block;
};

