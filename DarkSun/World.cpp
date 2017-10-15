#include <iostream>
#include "World.h"

World::World()
{
}

World::~World()
{
}

void World::ParseCommand(vector<string>& args)
{
	bool match = true;

	switch (args.size())
	{
		// Don't allow commands with just one word
		case 1:
			match = false;
			break;
		// Commands with two words
		case 2:
			if (args[0].compare("go") == 0)
			{
				if (args[1].compare("north") == 0 || args[1].compare("forward") == 0)
				{
					cout << endl << "You are going to the north" << endl;
				}
				else if (args[1].compare("south") == 0 || args[1].compare("back") == 0)
				{
					cout << endl << "You are going to the south" << endl;
				}
				else if (args[1].compare("east") == 0 || args[1].compare("right") == 0)
				{
					cout << endl << "You are going to the east" << endl;
				}
				else if (args[1].compare("west") == 0 || args[1].compare("left") == 0)
				{
					cout << endl << "You are going to the west" << endl;
				}
				else
				{
					match = false;
				}
			}
			else if (args[0].compare("look") == 0)
			{
				if (args[1].compare("around") == 0)
				{
					cout << endl << "General description of the room" << endl;
				}
				else if (args[1].compare("forward") == 0)
				{
					cout << endl << "Description of what you are watching if look at north" << endl;
				}
				else if (args[1].compare("right") == 0)
				{
					cout << endl << "Description of what you are watching if look at east" << endl;
				}
				else if (args[1].compare("left") == 0)
				{
					cout << endl << "Description of what you are watching if look at west" << endl;
				}
				else if (args[1].compare("back") == 0 || args[1].compare("behind") == 0)
				{
					cout << endl << "Description of what you are watching if look at south" << endl;
				}
				else
				{
					match = false;
				}
			}
			else
			{
				match = false;
			}
			break;
	}

	if (!match)
	{
		cout << endl;
		cout << "Your command is not valid, try again" << endl;
	}
}
