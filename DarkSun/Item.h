#ifndef __Item__
#define __Item__

#include "Entity.h"
#include <map>

enum ParentTypes
{
	ROOM,
	ITEM,
	CREATURE,
	PLAYER
};

class Item : public Entity
{
public:
	Item(const char* name, const char* description, Entity* parent, ParentTypes parentType);
	~Item();

	Entity* parent;
	ParentTypes parentType;
	map<string, int> bonus;

	void AddBonus(const char* bonusName, const int bonusValue);
};

#endif