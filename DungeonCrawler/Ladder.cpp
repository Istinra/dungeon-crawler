#include "Ladder.h"
#include "NotificationManager.h"

Ladder::Ladder(Vector3 const &position, std::string levelName) : Entity(position), levelName(levelName)
{

}

Ladder::~Ladder()
{

}

void Ladder::Collide(Entity *e)
{
	NotificationManager::Instance().TransitionToLevel(levelName);
}
