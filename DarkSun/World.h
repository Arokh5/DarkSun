#include <list>
#include <string>
#include <vector>

using namespace std;

class Entity;

class World
{
public:
	World();
	~World();

	void ParseCommand(vector<string>& args);

private:
	list<Entity>* entities;
};

