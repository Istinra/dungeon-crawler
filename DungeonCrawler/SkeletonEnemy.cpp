#include <math.h>

#include "SkeletonEnemy.h"
#include "Map\Level.h"
#include "Player.h"

SkeletonEnemy::SkeletonEnemy(Vector3 position, int textureId) :
Enemy(position, textureId)
{

}

void SkeletonEnemy::Update()
{

	const Player * const player = level->GetPlayer();
	Vector3 playerPos = player->Position();

	float xDiff = position.x - playerPos.x;
	float zDiff = position.z - playerPos.z;

	float aimingAngle = atanf(xDiff / zDiff);



	Enemy::Update();
}
