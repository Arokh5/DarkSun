#include "Item.h"

Item::Item(const char* name, const char* description, Entity* parent, ItemTypes itemType, bool weapon1, bool weapon2, bool armor, bool equiped) :
parent(parent),
itemType(itemType),
weapon1(weapon1),
weapon2(weapon2),
armor(armor),
equiped(equiped),
Entity(name, description)
{
}

Item::~Item()
{
}

void Item::AddBonus(const char* bonusName, const int bonusValue)
{
	bonus.insert(pair<string, int>(bonusName, bonusValue));
}