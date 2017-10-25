#ifndef __World__
#define __World__

#include <list>
#include <string>
#include <vector>

using namespace std;

class Entity;
class Player;
class Item;

class World
{
public:
	World();
	~World();

	list<Entity*> entities;
	Player* player = nullptr;

	void ParseCommand(vector<string>& args);
	bool CheckIfBattle();

private:
	vector<Item*> items;
};

#endif