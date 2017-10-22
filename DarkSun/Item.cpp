#include "Item.h"

Item::Item(const char* name, const char* description, Entity* parent, ParentTypes parentType) :
parent(parent),
parentType(parentType),
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