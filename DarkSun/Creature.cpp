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

void Creature::CollectItem(Item* item, Entity* newParent)
{
	items.push_back(item);
	item->parent = newParent;
}

void Creature::DropItem(Item* item, Entity* carrierRoom)
{
	items.remove(item);
	item->parent = carrierRoom;

	UnEquipItem(item);
}

bool Creature::EquipItem(Item* item)
{
	bool itemEquiped = false;

	if (item->itemType == EQUIPABLE)
	{
		if (!item->equiped)
		{
			if (item->weapon1 && !item->weapon2)
			{
				if (weapon1 == nullptr)
				{
					itemEquiped = true;
					weapon1 = item;
				}
				else if (weapon2 == nullptr)
				{
					itemEquiped = true;
					weapon2 = item;
				}
				else
				{
					cout << endl << "I do not have any free hands to equip this." << endl;
				}
			}
			else if (item->weapon1 && item->weapon2)
			{
				if (weapon1 == nullptr && weapon2 == nullptr)
				{
					itemEquiped = true;
					weapon1 = item;
					weapon2 = item;
				}
				else
				{
					cout << endl << "I do not have any free hands to equip this." << endl;
				}
			}
			else if (item->armor)
			{
				if (armor == nullptr)
				{
					itemEquiped = true;
					armor = item;
				}
				else
				{
					cout << endl << "I already have equipped an armor, I have to unequip first the equipped armor." << endl;
				}
			}
		}
		else
		{
			cout << endl << "I have already equipped this item." << endl;
		}

		if (itemEquiped)
		{
			item->equiped = true;

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
					if (health > vitality)
					{
						health = vitality;
					}
				}
			}
		}
	}

	return itemEquiped;
}

bool Creature::UnEquipItem(Item* item)
{
	bool equiped = false;

	if (item == weapon1)
	{
		equiped = true;
		weapon1 = nullptr;
	}
	if (item == weapon2)
	{
		equiped = true;
		weapon2 = nullptr;
	}
	if (item == armor)
	{
		equiped = true;
		armor = nullptr;
	}

	if (equiped)
	{
		item->equiped = false;

		for (map<string, int>::iterator it = item->bonus.begin(); it != item->bonus.end(); ++it)
		{
			if (Same(it->first, "strength"))
			{
				atack -= it->second;
			}
			else if (Same(it->first, "resistance"))
			{
				defense -= it->second;
			}
			else if (Same(it->first, "vitality"))
			{
				health -= it->second;
			}
		}

		cout << endl;
		ShowStats();
	}

	return equiped;
}

void Creature::ShowStats()
{
	cout << "Atack -> " << atack << endl;
	cout << "Defense -> " << defense << endl;
	cout << "Health -> " << health << endl;
}

bool Creature::IngestConsumable(Item* item)
{
	bool ingested = false;

	if (item->itemType == CONSUMABLE)
	{
		ingested = true;

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
				if (health > vitality)
				{
					health = vitality;
				}
			}
		}

		items.remove(item);
	}

	return ingested;
}