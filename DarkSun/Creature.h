#include "Entity.h"

class Room;

class Creature : public Entity
{
public:
	Creature(const char* name, const char* description, Room* room);
	~Creature();

	void SetRoom(Room* room);

private:
	Room* location;
};

