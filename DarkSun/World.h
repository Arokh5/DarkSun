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

	void ParseCommand(vector<string>& args);
	bool CheckIfBattle();

private:
	list<Entity*> entities;
	Player* player = nullptr;
	vector<Item*> items;
};

#endif