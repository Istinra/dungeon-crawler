#include "Ladder.h"
#include "NotificationManager.h"
#include "SoundManager.h"
#include "Player.h"

Ladder::Ladder(Vector3 const &position, std::string levelName) : Entity(position), levelName(levelName)
{

}

Ladder::~Ladder()
{

}

void Ladder::Collide(Entity *e)
{
	if (dynamic_cast<Player*>(e))
	{
		SoundManager::Instance().PlaySound(LADDER);
		NotificationManager::Instance().TransitionToLevel(levelName);
	}
}
