#include <iostream>
#include "Player.h"
#include "Room.h"
#include "Item.h"
#include <vector>

Player::Player(const char* name, const char* description, Room* room, const int strength, const int resistance, const int vitality, const int accuracy, const int agility) :
Creature(name, description, room, strength, resistance, vitality, accuracy, agility)
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

void Player::ShowInventory()
{
	bool inventory = false;

	for each (Item* item in items)
	{
		inventory = true;
		cout << item->name << ":" << endl;

		for (map<string, int>::iterator it = item->bonus.begin(); it != item->bonus.end(); ++it)
		{
			if (Same(it->first, "strength"))
			{
				cout << "+ " << it->second << " atack." << endl;
			}
			else if (Same(it->first, "resistance"))
			{
				cout << "+ " << it->second << " defense." << endl;
			}
			else if (Same(it->first, "agility"))
			{
				cout << "+ " << it->second << " atackSpeed." << endl;
			}
			else if (Same(it->first, "vitality"))
			{
				cout << "+ " << it->second << " health." << endl;
			}
		}
		cout << endl;
	}

	if (!inventory)
	{
		cout << "There are no items in my inventory." << endl;
	}
}