#include <math.h>

#include "SkeletonEnemy.h"
#include "Map\Level.h"
#include "Player.h"
#include "SoundManager.h"
#include "Projectile.h"

const static float maxFireDistance = 1280.0f;
const static float testStep = 62.0f;

SkeletonEnemy::SkeletonEnemy(Vector3 position, int textureId) :
Enemy(position, textureId)
{

}

void SkeletonEnemy::Update()
{
	//TODO, shouldn't shoot if it can't hit
	//TODO, Angel breaks in some cases
	if (!attackCoolDown)
	{
		attackCoolDown = 200;
		const Player * const player = level->GetPlayer();
		Vector3 playerPos = player->Position();

		float xDiff = position.x - playerPos.x;
		float zDiff = position.z - playerPos.z;

		float aimingAngle = atanf(xDiff / zDiff) + M_PI_2;
		
		//SoundManager::Instance().PlaySound(LASER);
		Projectile* proj = new Projectile(position, aimingAngle, Item(0, GUN), this);
		proj->SetLevel(level);
		level->AddEntity(proj);
	}
	Enemy::Update();
}
