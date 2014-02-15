#ifndef NotificationManager_h__
#define NotificationManager_h__

#include <string>

class NotificationManager
{
public:
	
	~NotificationManager()
	{
	}

	static NotificationManager& Instance()
	{
		static NotificationManager manager;
		return manager;
	}

	void PostNotification(std::string notification, int frames);

	bool HasPendingNotification() const
	{
		return framesRemaining > 0;
	}

	std::string CurrentNotification() const
	{
		return currentNotification;
	}

	void Tick();

	std::string* PopPendingLevelTransition();
	
	void TransitionToLevel(std::string level);

private:
	std::string currentNotification;
	int framesRemaining;
	
	std::string level;
	bool transitioned;

	NotificationManager() : transitioned(true)
	{
	}
};

#endif // NotificationManager_h__
