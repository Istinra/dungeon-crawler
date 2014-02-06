#include "IceBlock.h"

IceBlock::IceBlock(unsigned int id, int x, int y, unsigned int tex) :Block(id, x, y, tex), closed(true)
{
}

bool IceBlock::Use(const Item& item)
{
	if (closed && item.type == GUN)
	{
		closed = false;
		return true;
	}
	return false;
}

bool IceBlock::IsSolid() const
{
	return closed;
}