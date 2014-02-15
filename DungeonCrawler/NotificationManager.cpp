#include "NotificationManager.h"

std::string* NotificationManager::PopPendingLevelTransition()
{
	if (transitioned)
	{
		return nullptr;
	}
	transitioned = true;
	return &level;
}

void NotificationManager::TransitionToLevel(std::string level)
{
	this->level = level;
	transitioned = false;
}

void NotificationManager::Tick()
{
	if (framesRemaining > 0)
	{
		--framesRemaining;
	}
}

void NotificationManager::PostNotification(std::string notification, int frames)
{
	currentNotification = notification;
	framesRemaining = frames;
}
