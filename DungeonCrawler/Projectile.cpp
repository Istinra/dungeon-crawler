#include "Projectile.h"
#include "Map/Block.h"
#include "Map/Level.h"
#include <math.h>

const float Projectile::projectBoundingWidth = 10.0f;

Projectile::Projectile(Vector3 position, float yaw, Item sourceItem, Entity* sourceEntity) : Entity(position), 
destroyed(false), 
sourceEntity(sourceEntity),
sourceItem(sourceItem),
animationStep(0),
movementVector(Vector3(PROJECTILE_MOVE_STEP * cosf(yaw), 0, -PROJECTILE_MOVE_STEP * sinf(yaw)))
{
	this->yaw = yaw;
}

Projectile::~Projectile()
{

}

void Projectile::Update()
{
	Move(movementVector);
	++animationStep;
	if (animationStep == 60)
	{
		sprite->texNumber = sprite->texNumber + 1;
	}
	else if (animationStep == 120)
	{
		sprite->texNumber = sprite->texNumber - 1;
		animationStep = 0;
	}
}

void Projectile::Move(Vector3 movement)
{
	float bound = movement.x < 0 ? -projectBoundingWidth : projectBoundingWidth;
	int xBox = static_cast<int>((position.x + movement.x + bound) / 64.0f);
	int zBox = static_cast<int>((position.z + movement.z) / 64.0f);
	Block *xBlock = (*level)[xBox + level->Width() * zBox];
	if (xBlock->IsCollidable())
	{
		destroyed = true;
		xBlock->Use(this, sourceItem);
		return;
	}
	bound = movement.z < 0 ? -projectBoundingWidth : projectBoundingWidth;
	xBox = static_cast<int>((position.x + movement.x) / 64.0f);
	zBox = static_cast<int>((position.z + movement.z + bound) / 64.0f);
	Block *zBlock = (*level)[xBox + level->Width() * zBox];
	if (zBlock->IsCollidable())
	{
		destroyed = true;
		zBlock->Use(this, sourceItem);
		return;
	}
	position = position + movement;
	for (Entity *entity : level->Entities())
	{
		if (entity == this || entity == sourceEntity) continue;
		if (ContainsPoint(entity->Position().x, entity->Position().z))
		{
			entity->Use(sourceEntity, sourceItem);
			destroyed = true;
			return;
		}
	}
}
