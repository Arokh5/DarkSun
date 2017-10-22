#include <iostream>
#include "Creature.h"
#include "Item.h"

Creature::Creature(const char* name, const char* description, Room* room, const int strength, const int resistance, const int vitality) :
room(room),
strength(strength),
resistance(resistance),
vitality(vitality),
Entity(name, description)
{
	SetAtack();
	SetDefense();
	SetHealth();
}

Creature::~Creature()
{
}

void Creature::SetAtack()
{
	atack = strength;
}

void Creature::SetDefense()
{
	defense = resistance;
}

void Creature::SetHealth()
{
	health = vitality;
}

void Creature::SetRoom(Room* room)
{
	this->room = room;
}

void Creature::CollectItem(Item* item)
{
	items.push_back(item);
}

bool Creature::EquipItem(const string selectedItem)
{
	bool itemEquiped = false;

	for each (Item* item in items)
	{
		if (Same(item->name, selectedItem))
		{
			itemEquiped = true;

			for (map<string, int>::iterator it = item->bonus.begin(); it != item->bonus.end(); ++it)
			{
				if (Same(it->first, "strength"))
				{
					atack += it->second;
				}
				else if (Same(it->first, "resistance"))
				{
					defense += it->second;
				}
				else if (Same(it->first, "vitality"))
				{
					health += it->second;
				}
			}
		}
	}

	return itemEquiped;
}

void Creature::ShowStats()
{
	cout << "Atack -> " << atack << endl;
	cout << "Defense -> " << defense << endl;
	cout << "Health -> " << health << endl;
}