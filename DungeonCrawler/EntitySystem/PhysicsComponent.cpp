#include "PhysicsComponent.h"
#include "../Map/Block.h"
#include "../Map/Level.h"

const float PhysicsComponent::boundingWidth = 20.0f;

PhysicsComponent::PhysicsComponent()
{
}


PhysicsComponent::~PhysicsComponent()
{
}

void PhysicsComponent::Update(float total, float dt)
{

}

void PhysicsComponent::Move(Vector3 movement)
{
	//Check if the there is a collision 
	float bound = movement.x < 0 ? -boundingWidth : boundingWidth;
	int xBox = static_cast<int>((position.x + movement.x + bound) / 64.0f);
	int zBox = static_cast<int>((position.z + movement.z) / 64.0f);
	Block *xBlock = (*level)[xBox + level->Width() * zBox];
	if (xBlock->IsCollidable())
	{
		movement.x = 0.0f;
	}
	bound = movement.z < 0 ? -boundingWidth : boundingWidth;
	xBox = static_cast<int>((position.x + movement.x) / 64.0f);
	zBox = static_cast<int>((position.z + movement.z + bound) / 64.0f);
	Block *zBlock = (*level)[xBox + level->Width() * zBox];
	if (zBlock->IsCollidable())
	{
		movement.z = 0.0f;
	}
	position = position + movement;
	for (Entity *entity : level->Entities())
	{
		if (entity == this) continue;
		if (ContainsPoint(entity->Position().x, entity->Position().z))
		{
			Collide(entity);
			entity->Collide(this);
			return;
		}
	}
}