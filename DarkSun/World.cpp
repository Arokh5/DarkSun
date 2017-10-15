#include <iostream>
#include "Room.h"
#include "Player.h"
#include "World.h"

World::World()
{
	// Aux objects
	map<Room*, char*> accessibleRooms;
	
	/***** Corridor *****/
	Room* corridor = new Room("Corridor", "This corridor communicates with the dining room. ",
		"There is a wall.",
		"From here I can go to the dining room.",
		"This is my sister's bedroom, it's closed.",
		"From here I can go to my room again",
		accessibleRooms);
	/********************/

	/***** Bedroom ******/
	accessibleRooms.insert(pair<Room*, char*>(corridor, "east"));
	Room* bedroom = new Room("Bedroom", "This is my bedroom, something strange has happened here. ", 
		"I look out the window and realize that the atmosphere is rarefied, everything has a dull color. Sun! It is hidden as in an eclipse! I had no idea that there was a solar eclipse today...",
		"There is a bookshelf with books, none that I am interested in reading now.",
		"This is my bedroom's door.",
		"I look at myself in the mirror. I notice that my bracelet is not where it should be, it is in the opposite arm where I have been wearing it ...",
		accessibleRooms);
	accessibleRooms.clear();
	/********************/

	player = new Player("Jacke", "The hero of the adventure", bedroom);
	entities.push_back(bedroom);
	entities.push_back(corridor);
	entities.push_back(player);
}

World::~World()
{
}

void World::ParseCommand(vector<string>& args)
{
	bool match = true;

	switch (args.size())
	{
		// Commands with one word
		case 1:
			if (args[0].compare("look") == 0)
			{
				cout << endl << player->Look(nullptr) << endl;
			}
			else
			{
				match = false;
			}
			break;
		// Commands with two words
		case 2:
			if (args[0].compare("go") == 0)
			{
				if (args[1].compare("north") == 0 || args[1].compare("forward") == 0)
				{
					if (player->Go("north"))
					{
						cout << endl << "I enter to the " << player->room->name << ". " << endl;
						cout << endl << player->room->description << "." << endl;
					}
					else
					{
						cout << endl << "I cannot go there." << endl;
					}
				}
				else if (args[1].compare("south") == 0 || args[1].compare("back") == 0)
				{
					if (player->Go("south"))
					{
						cout << endl << "I enter to the " << player->room->name << ". " << endl;
						cout << endl << player->room->description << "." << endl;
					}
					else
					{
						cout << endl << "I cannot go there." << endl;
					}
				}
				else if (args[1].compare("east") == 0 || args[1].compare("right") == 0)
				{
					if (player->Go("east"))
					{
						cout << endl << "I enter to the " << player->room->name << ". " << endl;
						cout << endl << player->room->description << "." << endl;
					}
					else
					{
						cout << endl << "I cannot go there." << endl;
					}
				}
				else if (args[1].compare("west") == 0 || args[1].compare("left") == 0)
				{
					if (player->Go("west"))
					{
						cout << endl << "I enter to the " << player->room->name << ". " << endl;
						cout << endl << player->room->description << "." << endl;
					}
					else
					{
						cout << endl << "I cannot go there." << endl;
					}
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
					cout << endl << player->Look("around") << endl;
				}
				else if (args[1].compare("north") == 0 || args[1].compare("forward") == 0)
				{
					cout << endl << player->Look("north") << endl;
				}
				else if (args[1].compare("east") == 0 || args[1].compare("right") == 0)
				{
					cout << endl << player->Look("east") << endl;
				}
				else if (args[1].compare("west") == 0 || args[1].compare("left") == 0)
				{
					cout << endl << player->Look("west") << endl;
				}
				else if (args[1].compare("south") == 0 || args[1].compare("back") == 0)
				{
					cout << endl << player->Look("south") << endl;
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