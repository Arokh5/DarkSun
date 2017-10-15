#include "Item.h"

Item::Item(const char* name, const char* description) :
Entity(name, description)
{
	type = ITEM;
}

Item::~Item()
{
}
