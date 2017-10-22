#include "Room.h"

Room::Room(const char* name, const char* generalDescription, 
	const char* descriptionNorth,
	const char* descriptionSouth,
	const char* descriptionEast,
	const char* descriptionWest) :
descriptionNorth(descriptionNorth),
descriptionSouth(descriptionSouth),
descriptionEast(descriptionEast),
descriptionWest(descriptionWest),
Entity(name, generalDescription)
{
}

Room::~Room()
{
}