#include "TriggerBlock.h"


TriggerBlock::TriggerBlock(unsigned int id, int x, int y, unsigned int tex)
: Block(id, x, y, tex), block(nullptr), targetId(0)
{
}


TriggerBlock::~TriggerBlock()
{
}

bool TriggerBlock::Use(Item& item)
{
	if (item.type != GUN && block && tex == 1)
	{
		++tex;
		return block->Use(item);
	}
	return false;
}
