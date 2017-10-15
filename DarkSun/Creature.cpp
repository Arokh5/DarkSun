#include "Creature.h"

Creature::Creature(const char* name, const char* description, Room* room) :
Entity(name, description)
{
	location = room;
	type = CREATURE;
}

Creature::~Creature()
{
}

void Creature::SetRoom(Room* room)
{
	location = room;
}
