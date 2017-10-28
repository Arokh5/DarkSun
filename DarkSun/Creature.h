#ifndef __Creature__
#define __Creature__

#include "Entity.h"
#include <list>
#include "globals.h"

class Room;
class Item;

class Creature : public Entity
{
public:
	Creature(const char* name, const char* description, Room* room, const int strength, const int resistance, const int vitality, const int accuracy, const int agility);
	~Creature();
	
	Room* room = nullptr;
	list<Item*> items;

	// Stats //
	const int strength;
	const int resistance;
	const int vitality;
	const int accuracy;
	const int agility;

	// Skills //
	int atack;
	int defense;
	int health;
	int atackSpeed;

	// Equip //
	Item* weapon1 = nullptr;
	Item* weapon2 = nullptr;
	Item* armor = nullptr;

	void SetAtack();
	void SetDefense();
	void SetHealth();
	void SetAtackSpeed();

	void SetRoom(Room* room);
	void CollectItem(Item* item, Entity* newParent);
	void DropItem(Item* item, Entity* carrierRoom);
	bool EquipItem(Item* item);
	bool UnEquipItem(Item* item);
	void ShowStats();
	bool IngestConsumable(Item* item);
};

#endif