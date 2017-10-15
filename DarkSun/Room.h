#ifndef __Room__
#define __Room__

#include "Entity.h"
#include <vector>
#include <map>

enum RoomSide
{
	NORTH,
	SOUTH,
	EAST,
	WEST
};

class Room : public Entity
{
public:
	Room(const char* name, const char* generalDescription,
		const char* descriptionNorth, 
		const char* descriptionSouth, 
		const char* descriptionEast, 
		const char* descriptionWest,
		const map<Room*, char*> accessibleRooms);
	~Room();

	string descriptionNorth;
	string descriptionSouth;
	string descriptionEast;
	string descriptionWest;
	map<Room*, char*> accessibleRooms;

	RoomSide roomSide;
};

#endif