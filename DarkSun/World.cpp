#include <iostream>
#include "Room.h"
#include "Item.h"
#include "Player.h"
#include "World.h"

World::World()
{
	/******** Corridor ********/
	Room* corridor = new Room("Corridor", "This corridor communicates with the dining room.",
		"There is a wall.",
		"From here I can go to the dinning room.",
		"This is my sister's bedroom, it's closed.",
		"From here I can go to my bedroom again");
	/**************************/

	/******** Bedroom *********/
	Room* bedroom = new Room("Bedroom", "This is my bedroom, something strange has happened here.", 
		"I look out the window and realize that the atmosphere is rarefied, everything has a dull color. What happens to the Sun! It is hidden as in an eclipse! I had no idea that there was a solar eclipse today...",
		"There is a bookshelf with books, none that I am interested in reading now.",
		"This is my bedroom's door.",
		"I look at myself in the mirror. I notice that my bracelet is not where it should be, it is in the opposite arm where I have been wearing it ...");
	/**************************/

	/****** Dinning room ******/
	Room* dinningRoom = new Room("Dinning room", "This is the dinning room of the house, here we usually make family life.",
		"From here I can go back to the corridor, also I can see the little kitchen of my home where my father has a knife collection.",
		"Following this path I would leave the house and enter to South Garden.",
		"There is a door that leads me to the East Garden of the house.",
		"I can see the door of my parents bedroom.");
	/**************************/

	/****** East garden *******/
	Room* eastGarden = new Room("East garden", "This is the east side of the garden, my parents grow all kinds of vegetables here.",
		"I can see a grille, because there is no way out.",
		"There is a lot of vegetables, such as lettuce, tomatoes and eggplants.",
		"In the distance I see mountains, I always wanted to visit them because my parents do not let me go so far...",
		"This way I can go back to the dinning room.");
	/**************************/

	/****** South garden *******/
	Room* southGarden = new Room("South garden", "This is the south side of the garden, following this path I can leave the house and enter to the forest.",
		"",
		"",
		"",
		"");
	/**************************/

	/**** Define accessible rooms for each room ****/
	corridor->accessibleRooms.insert(pair<Room*, char*>(bedroom, "west"));
	corridor->accessibleRooms.insert(pair<Room*, char*>(dinningRoom, "south"));
	bedroom->accessibleRooms.insert(pair<Room*, char*>(corridor, "east"));
	dinningRoom->accessibleRooms.insert(pair<Room*, char*>(eastGarden, "east"));
	dinningRoom->accessibleRooms.insert(pair<Room*, char*>(southGarden, "south"));
	dinningRoom->accessibleRooms.insert(pair<Room*, char*>(corridor, "north"));
	eastGarden->accessibleRooms.insert(pair<Room*, char*>(dinningRoom, "west"));
	southGarden->accessibleRooms.insert(pair<Room*, char*>(dinningRoom, "north"));
	
	/***********************************************/

	/****** Items ****/
	Item* lettuce = new Item("lettuce", "Eating this you regain some vitality", eastGarden, CONSUMABLE, false, false, false, false);
	lettuce->AddBonus("vitality", 5);
	items.push_back(lettuce);

	Item* knife = new Item("knife", "With this kitchen knife my father prepares many delicious dishes", dinningRoom, EQUIPABLE, true, false, false, false);
	knife->AddBonus("strength", 10);
	items.push_back(knife);
	/*****************/

	player = new Player("Jacke", "The hero of the adventure", bedroom, 53, 44, 60);
	entities.push_back(player);
	entities.push_back(bedroom);
	entities.push_back(corridor);
	entities.push_back(dinningRoom);
	entities.push_back(eastGarden);
	entities.push_back(southGarden);
	entities.push_back(knife);
	entities.push_back(lettuce);
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
			else if (args[0].compare("go") == 0)
			{
				cout << endl << "Where do you want to go?" << endl;
			}
			else if (args[0].compare("collect") == 0)
			{
				cout << endl << "What do you want to collect?" << endl;
			}
			else if (args[0].compare("equip") == 0)
			{
				cout << endl << "What do you want to equip?" << endl;
			}
			else if (args[0].compare("show") == 0)
			{
				cout << endl << "What do you want to show?" << endl;
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
			else if (args[0].compare("collect") == 0)
			{
				bool found = false;
				// Loop through items cheking if they are in the same room as player
				for each (Item* item in items)
				{
					if (Same(args[1], item->name))
					{
						found = true;
						// If item parent is same as player room
						if (item->parent == player->room)
						{
							player->CollectItem(item, player);
							cout << endl << "You've found a " << item->name << "!" << endl;
						}
						else
						{
							cout << endl << "There is no " << args[1] << " here." << endl;
						}
						break;
					}
				}
				if (!found)
				{
					cout << endl << "There is no " << args[1] << " here." << endl;
				}
			}
			else if (args[0].compare("drop") == 0)
			{
				bool found = false;
				for each (Item* item in player->items)
				{
					if (Same(args[1], item->name))
					{
						found = true;
						player->DropItem(item, player->room);
						cout << endl << "You have dropped the " << args[1] << "." << endl;
						break;
					}
				}
				if (!found)
				{
					cout << endl << "You don't have a " << args[1] << "." << endl;
				}
			}
			else if (args[0].compare("equip") == 0)
			{
				bool found = false;
				for each (Item* item in player->items)
				{
					if (Same(args[1], item->name))
					{
						found = true;
						if (player->EquipItem(item))
						{
							cout << endl << args[1] << " equiped." << endl;
							player->ShowStats();
						}
						else
						{
							cout << endl << "I can not equip myself with that." << endl;
						}
						break;
					}
				}
				if (!found)
				{
					cout << endl << "I don't have a " << args[1] << " in my inventory." << endl;
				}
			}
			else if (args[0].compare("unequip") == 0)
			{
				bool found = false;
				for each (Item* item in player->items)
				{
					if (Same(args[1], item->name))
					{
						found = true;
						if (player->UnEquipItem(item))
						{
							cout << endl << args[1] << " unequiped." << endl;
						}
						else
						{
							cout << endl << "The " << args[1] << " was not equipped." << endl;
						}
						break;
					}
				}
				if (!found)
				{
					cout << endl << "I don't have a " << args[1] << " in my inventory." << endl;
				}
			}
			else if (args[0].compare("eat") == 0 || args[0].compare("ingest") == 0)
			{
				bool found = false;
				for each (Item* item in player->items)
				{
					if (Same(args[1], item->name))
					{
						found = true;
						if (player->IngestConsumable(item))
						{
							cout << endl << args[1] << " ingested." << endl;
							player->ShowStats();
						}
						else
						{
							cout << endl << "I can not eat that." << endl;
						}
						break;
					}
				}
				if (!found)
				{
					cout << endl << "I don't have a " << args[1] << " in my inventory." << endl;
				}
			}
			else if (args[0].compare("show") == 0)
			{
				if (args[1].compare("stats") == 0)
				{
					cout << endl;
					player->ShowStats();
				}
				else if (args[1].compare("inventory") == 0 || args[1].compare("items") == 0)
				{
					cout << endl;
					player->ShowInventory();
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
		cout << "Your command is not valid, please try again." << endl;
	}
}