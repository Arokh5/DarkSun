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
		const char* descriptionWest);
	~Room();

	const string descriptionNorth;
	const string descriptionSouth;
	const string descriptionEast;
	const string descriptionWest;
	map<Room*, char*> accessibleRooms;
};

#endif