#include <string>
#include <list>

using namespace std;

enum EntityType
{
	ENTITY,
	ROOM,
	ITEM,
	CREATURE,
	PLAYER
};

class Entity
{
public:
	Entity(const char* name, const char* description);
	~Entity();

	string name;
	string description;
	EntityType type;

private:
	list<Entity*> container;
};

