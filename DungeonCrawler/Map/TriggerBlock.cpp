#include "TriggerBlock.h"


TriggerBlock::TriggerBlock(unsigned int id, int x, int y, unsigned int tex)
: Block(id, x, y, tex), block(nullptr)
{
}


TriggerBlock::~TriggerBlock()
{
}

bool TriggerBlock::Use()
{
	if (block)
	{
		return block->Use();
	}
	return false;
}
