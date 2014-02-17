#include "Projectile.h"
#include <math.h>

Projectile::Projectile(Vector3 position, float yaw) : Entity(position), 
movementVector(Vector3(PROJECTILE_MOVE_STEP * cosf(yaw), 0, -PROJECTILE_MOVE_STEP * sinf(yaw)))
{
	this->yaw = yaw;
	SetSprite(new Sprite(0, 0, 0, 0, 0, 0.25f));
}

Projectile::~Projectile()
{

}

void Projectile::Update()
{
	Move(movementVector);
}
