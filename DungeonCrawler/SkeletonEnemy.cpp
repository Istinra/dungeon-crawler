#include <math.h>

#include "SkeletonEnemy.h"
#include "Map\Level.h"
#include "Player.h"
#include "SoundManager.h"
#include "Projectile.h"
#include "RayCastBitmap.h"

const static float maxFireDistance = 1280.0f;
const static float testStep = 62.0f;

SkeletonEnemy::SkeletonEnemy(Vector3 position, int textureId) :
Enemy(position, textureId)
{

}

void SkeletonEnemy::Update()
{
	//TODO, shouldn't shoot if it can't hit
	if (!attackCoolDown)
	{
		attackCoolDown = 200;
		const Player * const player = level->GetPlayer();
		Vector3 playerPos = player->Position();

		float xDiff = position.x - playerPos.x;
		float zDiff = position.z - playerPos.z;

		if (IsPathClear(playerPos))
		{
			float aimingAngle = static_cast<float>(atan2f(xDiff, zDiff) + M_PI_2);
			SoundManager::Instance().PlaySound(LASER);
			Projectile* proj = new Projectile(position, aimingAngle, Item(0, GUN), this);
			proj->SetLevel(level);
			level->AddEntity(proj);
		}
	}
	Enemy::Update();
}

bool SkeletonEnemy::IsPathClear(const Vector3 &object) const
{
	//TODO - Increments should be 64 not 1
	const int levelWidth = level->Width();
	const int levelHeight = level->Height();

	float dx = fabsf(object.x - position.x);
	float dz = fabsf(object.z - position.z);

	int x = static_cast<int>(position.x);
	int z = static_cast<int>(position.z);

	int n = 1;
	int xIncrement, yIncrement;
	float error;

	if (dx == 0)
	{
		xIncrement = 0;
		error = std::numeric_limits<float>::infinity();
	}
	else if (object.x > position.x)
	{
		xIncrement = 1;
		n += static_cast<int>(floorf(object.x)) - x;
		error = (floorf(position.x) + 1 - position.x) * dz;
	}
	else
	{
		xIncrement = -1;
		n += x - static_cast<int>(object.x);
		error = (position.x - floorf(position.x)) * dz;
	}

	if (dz == 0)
	{
		yIncrement = 0;
		error -= std::numeric_limits<float>::infinity();
	}
	else if (object.z > position.z)
	{
		yIncrement = 1;
		n += static_cast<int>(floorf(object.z)) - z;
		error -= (floorf(position.z) + 1 - position.z) * dx;
	}
	else
	{
		yIncrement = -1;
		n += z - static_cast<int>(object.z);
		error -= (position.z - floorf(position.z)) * dx;
	}

	for (; n > 0; --n)
	{
		int xIndex = static_cast<int>(x / 64);
		int zIndex = static_cast<int>(z / 64);
		if (xIndex > -1 && zIndex > -1 && xIndex < levelWidth &&  zIndex < levelHeight &&
			(*level)[xIndex + zIndex * level->Width()]->IsSolid())
		{
			return false;
		}

		if (error > 0)
		{
			z += yIncrement;
			error -= dx;
		}
		else
		{
			x += xIncrement;
			error += dz;
		}
	}

	return true;
}
