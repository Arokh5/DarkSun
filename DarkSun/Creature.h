#ifndef __Creature__
#define __Creature__

#include "Entity.h"
#include <vector>
#include "globals.h"

class Room;
class Item;

class Creature : public Entity
{
public:
	Creature(const char* name, const char* description, Room* room, const int strength, const int resistance, const int vitality);
	~Creature();
	
	Room* room = nullptr;
	vector<Item*> items;

	// Stats //
	const int strength;
	const int resistance;
	const int vitality;

	// Skills //
	int atack;
	int defense;
	int health;

	void SetAtack();
	void SetDefense();
	void SetHealth();

	void SetRoom(Room* room);
	void CollectItem(Item* item);
	bool EquipItem(const string item);
	void ShowStats();
};

#endif