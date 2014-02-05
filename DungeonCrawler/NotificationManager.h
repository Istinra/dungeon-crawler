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

	void PostNotification(std::string notification, int frames)
	{
		currentNotification = notification;
		framesRemaining = frames;
	}

	bool HasPendingNotification()
	{
		return framesRemaining > 0;
	}

	std::string CurrentNotification()
	{
		return currentNotification;
	}

	void Tick()
	{
		if (framesRemaining > 0)
		{
			--framesRemaining;
		}
	}

private:
	NotificationManager()
	{
	}

	std::string currentNotification;
	int framesRemaining;
};


#endif // NotificationManager_h__
