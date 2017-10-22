#ifndef __Item__
#define __Item__

#include "Entity.h"
#include <map>

enum ItemTypes
{
	EQUIPABLE,
	CONSUMABLE
};

class Item : public Entity
{
public:
	Item(const char* name, const char* description, Entity* parent, ItemTypes itemType, bool weapon1, bool weapon2, bool armor);
	~Item();

	Entity* parent;
	map<string, int> bonus;
	ItemTypes itemType;

	// Slots //
	bool weapon1;
	bool weapon2;
	bool armor;

	void AddBonus(const char* bonusName, const int bonusValue);
};

#endif