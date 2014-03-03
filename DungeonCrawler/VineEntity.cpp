#include "VineEntity.h"
#include "Map\Level.h"

VineEntity::VineEntity(Vector3 position, int xIndex, int zIndex) : 
Entity(position),
xIndex(xIndex),
zIndex(zIndex)
{
}

VineEntity::~VineEntity()
{
}

bool VineEntity::Use(Entity *source, Item &item)
{
	Block *b = (*level)[xIndex + level->Width() * zIndex];
	if (item.type == SWORD && b->IsCollidable())
	{
		b->Collidable(false);
		sprite->texNumber += 1;
		return true;
	}
	return false;
}