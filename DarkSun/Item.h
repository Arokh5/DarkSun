#ifndef __Item__
#define __Item__

#include "Entity.h"

class Item : public Entity
{
public:
	Item(const char* name, const char* description);
	~Item();
};

#endif