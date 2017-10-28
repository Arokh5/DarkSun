#ifndef __Player__
#define __Player__

#include "Creature.h"

using namespace std;

class Player : public Creature
{
public:
	Player(const char* name, const char* description, Room* room, const int strength, const int resistance, const int vitality, const int accuracy, const int agility);
	~Player();

	string Look(const char* direction);
	bool Go(const char* direction);
	void ShowInventory();
	void ShowEquip();
};

#endif