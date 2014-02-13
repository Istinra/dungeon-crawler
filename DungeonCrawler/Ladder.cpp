#include "Ladder.h"
#include "Map/Level.h"

Ladder::Ladder(Vector3 const &position, std::string levelName) : Entity(position), levelName(levelName)
{

}

Ladder::~Ladder()
{

}

void Ladder::Collide(Entity *e)
{
	level->LoadLevel(levelName);
}


