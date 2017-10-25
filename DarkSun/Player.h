#ifndef __Player__
#define __Player__

#include "Creature.h"

using namespace std;

class Player : public Creature
{
public:
	Player(const char* name, const char* description, Room* room, int strength, int resistance, int vitality);
	~Player();

	string Look(const char* direction);
	bool Go(const char* direction);
	void ShowInventory();
};

#endif