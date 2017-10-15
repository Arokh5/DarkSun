#include "Room.h"

Room::Room(const char* name, const char* generalDescription, 
	const char* descriptionNorth,
	const char* descriptionSouth,
	const char* descriptionEast,
	const char* descriptionWest,
	const map<Room*, char*> accessibleRooms) :
descriptionNorth(descriptionNorth),
descriptionSouth(descriptionSouth),
descriptionEast(descriptionEast),
descriptionWest(descriptionWest),
accessibleRooms(accessibleRooms),
Entity(name, generalDescription)
{
	type = ROOM;
}

Room::~Room()
{
}