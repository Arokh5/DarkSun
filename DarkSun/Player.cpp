#include "Player.h"
#include "Room.h"
#include <vector>

Player::Player(const char* name, const char* description, Room* room) :
Creature(name, description, room)
{
	type = PLAYER;
	this->room->roomSide = WEST;
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

		switch (room->roomSide)
		{
			case NORTH:
				desc += room->descriptionNorth;
				break;

			case SOUTH:
				desc += room->descriptionSouth;
				break;

			case EAST:
				desc += room->descriptionEast;
				break;

			case WEST:
				desc += room->descriptionWest;
				break;
		}
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
		for (map<Room*, char*>::const_iterator it = room->accessibleRooms.begin(); it != room->accessibleRooms.end(); ++it)
		{
			if (Same(it->second, direction)) // NO FUNCIONA!
			{
				SetRoom(it->first);
				success = true;
			}
		}
	}

	return success;
}