#ifndef __World__
#define __World__

#include <list>
#include <string>
#include <vector>
#include "time.h"

using namespace std;

class Entity;
class Player;
class Item;
class Creature;

class World
{
public:
	World();
	~World();

	Player* player = nullptr;

	void ParseCommand(vector<string>& args);
	bool CheckIfBattle();
	Creature* FindOpponent();
	bool Fight(Creature* opponent, bool playerAtack);

private:
	vector<Room*> rooms;
	vector<Item*> items;
	vector<Creature*> creatures;
};

#endif