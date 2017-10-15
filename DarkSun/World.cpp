#include <iostream>
#include "Room.h"
#include "Player.h"
#include "World.h"

World::World()
{
	/******** Corridor ********/
	Room* corridor = new Room("Corridor", "This corridor communicates with the dining room.",
		"There is a wall.",
		"From here I can go to the dinning room.",
		"This is my sister's bedroom, it's closed.",
		"From here I can go to my room again");
	/**************************/

	/******** Bedroom *********/
	Room* bedroom = new Room("Bedroom", "This is my bedroom, something strange has happened here.", 
		"I look out the window and realize that the atmosphere is rarefied, everything has a dull color. What happens to the Sun! It is hidden as in an eclipse! I had no idea that there was a solar eclipse today...",
		"There is a bookshelf with books, none that I am interested in reading now.",
		"This is my bedroom's door.",
		"I look at myself in the mirror. I notice that my bracelet is not where it should be, it is in the opposite arm where I have been wearing it ...");
	/**************************/

	corridor->accessibleRooms.insert(pair<Room*, char*>(bedroom, "west"));

	/****** Dinning room ******/
	Room* dinningRoom = new Room("Dinning room", "This is the dinning room of the house, here we usually make family life.",
		"",
		"",
		"",
		"");
	/**************************/

	/****** East garden *******/
	Room* eastGarden = new Room("East garden", "This is the east side of the garden, my parents grow all kinds of vegetables here.",
		"",
		"",
		"",
		"");
	/**************************/

	/****** South garden *******/
	Room* southGarden = new Room("South garden", "This is the south side of the garden, following this path I can leave the house and enter to the forest.",
		"",
		"",
		"",
		"");
	/**************************/

	/**** Define accessible rooms for each room ****/
	corridor->accessibleRooms.insert(pair<Room*, char*>(bedroom, "north"));
	corridor->accessibleRooms.insert(pair<Room*, char*>(dinningRoom, "south"));
	bedroom->accessibleRooms.insert(pair<Room*, char*>(corridor, "east"));
	dinningRoom->accessibleRooms.insert(pair<Room*, char*>(eastGarden, "east"));
	dinningRoom->accessibleRooms.insert(pair<Room*, char*>(southGarden, "south"));
	dinningRoom->accessibleRooms.insert(pair<Room*, char*>(corridor, "north"));
	eastGarden->accessibleRooms.insert(pair<Room*, char*>(dinningRoom, "west"));
	southGarden->accessibleRooms.insert(pair<Room*, char*>(dinningRoom, "north"));
	
	/***********************************************/

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
						cout << endl << "I enter to the " << player->room->name << "." << endl;
						cout << player->room->description << endl;
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
						cout << endl << "I enter to the " << player->room->name << "." << endl;
						cout << player->room->description << endl;
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
						cout << endl << "I enter to the " << player->room->name << "." << endl;
						cout << player->room->description << endl;
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
						cout << endl << "I enter to the " << player->room->name << "." << endl;
						cout << player->room->description << endl;
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