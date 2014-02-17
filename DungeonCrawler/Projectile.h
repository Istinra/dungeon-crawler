#ifndef Projectile_h__
#define Projectile_h__

#include "Entity.h"

#define PROJECTILE_MOVE_STEP 1.5f

class Projectile : public Entity 
{
public:
	Projectile(Vector3 position, float yaw);

	virtual ~Projectile();

	void Update() override;

private:
	Vector3 movementVector;
};

#endif // Projectile_h__
