#ifndef SKELETON_ENEMY_H__
#define SKELETON_ENEMY_H__

#include "Enemy.h"

class SkeletonEnemy : public Enemy
{
public:
	SkeletonEnemy(Vector3 position, int textureId);

	virtual void Update() override;

	inline void Boss(bool isBoss)
	{
		this->isBoss = isBoss;
	}

private:
	bool IsPathClear(const Vector3 &object) const;
	bool isBoss;
};

#endif
