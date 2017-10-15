#include "Creature.h"

Creature::Creature(const char* name, const char* description, Room* room) :
room(room),
Entity(name, description)
{
	type = CREATURE;
}

Creature::~Creature()
{
}

void Creature::SetRoom(Room* room)
{
	this->room = room;
}
