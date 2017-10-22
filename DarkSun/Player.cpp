#include "Player.h"
#include "Room.h"
#include <vector>

Player::Player(const char* name, const char* description, Room* room, int strength, int resistance, int vitality) :
Creature(name, description, room, strength, resistance, vitality)
{
}

Player::~Player()
{
}

string Player::Look(const char* direction)
{
	string desc = "";

	if (direction == nullptr)
	{
		desc = room->description;
	}
	else if (direction == "north")
	{
		desc = room->descriptionNorth;
	}
	else if (direction == "south")
	{
		desc = room->descriptionSouth;
	}
	else if (direction == "east")
	{
		desc = room->descriptionEast;
	}
	else if (direction == "west")
	{
		desc = room->descriptionWest;
	}
	else
	{
		desc = room->description;
	}

	return desc;
}

bool Player::Go(const char* direction)
{
	bool success = false;

	if (direction != nullptr)
	{
		for (map<Room*, char*>::iterator it = room->accessibleRooms.begin(); !success && it != room->accessibleRooms.end(); ++it)
		{
			if (Same(it->second, direction))
			{
				SetRoom(it->first);
				success = true;
			}
		}
	}

	return success;
}