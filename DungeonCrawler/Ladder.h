#ifndef Ladder_h__
#define Ladder_h__

#include <string>
#include "Entity.h"

class Ladder : public Entity
{
public:
	Ladder(Vector3 const &position, std::string levelName);
	
	virtual ~Ladder();

	virtual void Collide(Entity *e) override;

private:
	std::string levelName;
};

#endif // Ladder_h__
