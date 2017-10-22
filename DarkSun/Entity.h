#ifndef __Entity__
#define __Entity__

#include <string>

using namespace std;

class Entity
{
public:
	Entity(const char* name, const char* description);
	~Entity();

	string name;
	string description;
};

#endif