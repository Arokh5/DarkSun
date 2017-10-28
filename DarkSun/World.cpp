#include <iostream>
#include "Room.h"
#include "Item.h"
#include "Player.h"
#include "Creature.h"
#include "World.h"

World::World()
{
	/****************** Corridor *****************/
	Room* corridor = new Room("Corridor", "This corridor communicates with the dining room.",
		"There is a wall.",
		"From here I can go to the dinning room.",
		"This is my sister's bedroom, it's closed.",
		"From here I can go to my bedroom again");
	/*********************************************/

	/***************** Bedroom *******************/
	Room* bedroom = new Room("Bedroom", "This is my bedroom, something strange has happened here.", 
		"I look out the window and realize that the atmosphere is rarefied, everything has a dull color. What happens to the Sun! It is hidden as in an eclipse! I had no idea that there was a solar eclipse today...",
		"There is a bookshelf with books, none that I am interested in reading now.",
		"This is my bedroom's door.",
		"I look at myself in the mirror. I notice that my bracelet is not where it should be, it is in the opposite arm where I have been wearing it ...");
	/********************************************/

	/*************** Dinning room ***************/
	Room* dinningRoom = new Room("Dinning room", "This is the dinning room of the house, here we usually make family life.",
		"From here I can go back to the corridor, also I can see the little kitchen of my home where my father has a knife collection.",
		"Following this path I would leave the house and enter to South Garden.",
		"There is a door that leads me to the East Garden of the house.",
		"I can see the door of my parents bedroom.");
	/*******************************************/

	/************** East garden ****************/
	Room* eastGarden = new Room("East garden", "This is the east side of the garden, my parents grow all kinds of vegetables here.",
		"I can see a grille, because there is no way out.",
		"There is a lot of vegetables, such as lettuce, tomatoe and eggplant.",
		"In the distance I see mountains, I always wanted to visit them because my parents do not let me go so far...",
		"This way I can go back to the dinning room.");
	/******************************************/

	/************* South garden ***************/
	Room* southGarden = new Room("South garden", "This is the south side of the garden, following this path I can leave the house and enter to the forest.",
		"I see the front door to my house.",
		"I come out of the garden here and into the woods...",
		"In this direction there is a plain where I will often play.",
		"Among a pile of rocks I see half buried a tool, it looks like a screwdriver");
	/******************************************/

	/*************** The forest ***************/
	Room* forest = new Room("Forest", "This forest is very lush. They tell the popular legends that somewhere in the forest a warrior lost his weapon...",
		"Following this way I return to my garden.",
		"I see a small clearing in the forest and a silhouette of something nailed to the trunk of a tree, could it be a sword?!",
		"If I follow this way I will reach the village, it is a charming place.",
		"A lot of logs block the passage, it seems that someone has made a barricade on purpose.");
	/*****************************************/

	/*************** The plain ***************/
	Room* plain = new Room("Plain", "I love this place, it is very relaxing to lie on the grass watching the clouds.",
		"From here I can see the grille of my garden.",
		"If I follow this way I will reach the village, it is a charming place.",
		"I see something metallic in the distance, it looks like a worn armor.",
		"Following this way I return to my garden.");
	/*****************************************/

	/************** The village **************/
	Room* village = new Room("Village", "This is the closest town to my house, it is a very nice place and its people are very friendly.",
		"From here I return to the plain.",
		"A wall surrounds the whole village.",
		"A wall surrounds the whole village.",
		"From here I return to the forest.");
	/*****************************************/

	/**** Define accessible rooms for each room ****/
	corridor->accessibleRooms.insert(pair<Room*, char*>(bedroom, "west"));
	corridor->accessibleRooms.insert(pair<Room*, char*>(dinningRoom, "south"));
	bedroom->accessibleRooms.insert(pair<Room*, char*>(corridor, "east"));
	dinningRoom->accessibleRooms.insert(pair<Room*, char*>(eastGarden, "east"));
	dinningRoom->accessibleRooms.insert(pair<Room*, char*>(southGarden, "south"));
	dinningRoom->accessibleRooms.insert(pair<Room*, char*>(corridor, "north"));
	eastGarden->accessibleRooms.insert(pair<Room*, char*>(dinningRoom, "west"));
	southGarden->accessibleRooms.insert(pair<Room*, char*>(dinningRoom, "north"));
	southGarden->accessibleRooms.insert(pair<Room*, char*>(forest, "south"));
	southGarden->accessibleRooms.insert(pair<Room*, char*>(plain, "east"));
	forest->accessibleRooms.insert(pair<Room*, char*>(southGarden, "north"));
	forest->accessibleRooms.insert(pair<Room*, char*>(village, "east"));
	plain->accessibleRooms.insert(pair<Room*, char*>(village, "south"));
	plain->accessibleRooms.insert(pair<Room*, char*>(southGarden, "west"));
	village->accessibleRooms.insert(pair<Room*, char*>(forest, "west"));
	village->accessibleRooms.insert(pair<Room*, char*>(plain, "north"));
	/***********************************************/

	/********** Adding rooms to vector *************/
	rooms.push_back(corridor);
	rooms.push_back(bedroom);
	rooms.push_back(dinningRoom);
	rooms.push_back(eastGarden);
	rooms.push_back(southGarden);
	rooms.push_back(forest);
	rooms.push_back(plain);
	rooms.push_back(village);
	/***********************************************/

	/******************** Items ********************/
	Item* lettuce = new Item("lettuce", "Eating this you regain some vitality.", eastGarden, CONSUMABLE, false, false, false, false);
	lettuce->AddBonus("vitality", 5);
	items.push_back(lettuce);

	Item* tomatoe = new Item("tomatoe", "Eating this you regain some vitality.", eastGarden, CONSUMABLE, false, false, false, false);
	tomatoe->AddBonus("vitality", 7);
	items.push_back(tomatoe);

	Item* eggplant = new Item("eggplant", "Eating this you regain some vitality.", eastGarden, CONSUMABLE, false, false, false, false);
	eggplant->AddBonus("vitality", 10);
	items.push_back(eggplant);

	Item* knife = new Item("knife", "With this kitchen knife my father prepares many delicious dishes.", dinningRoom, EQUIPABLE, true, false, false, false);
	knife->AddBonus("strength", 10);
	items.push_back(knife);

	Item* screwdriver = new Item("screwdriver", "This screwdriver was half buried among a pile of rocks.", southGarden, EQUIPABLE, true, false, false, false);
	screwdriver->AddBonus("strength", 5);
	items.push_back(screwdriver);

	Item* armor = new Item("armor", "It is a worn armor.", plain, EQUIPABLE, false, false, true, false);
	armor->AddBonus("resistance", 21);
	armor->AddBonus("vitality", 12);
	armor->AddBonus("agility", -3000);
	items.push_back(armor);

	Item* log = new Item("log", "A log of the forest.", forest, EQUIPABLE, true, false, false, false);
	log->AddBonus("strength", 3);
	items.push_back(log);

	Item* sword = new Item("sword", "Legendary sword with magical properties.", forest, EQUIPABLE, true, true, false, false);
	sword->AddBonus("strength", 25);
	sword->AddBonus("resistance", 15);
	sword->AddBonus("agility", 7000);
	sword->AddBonus("vitality", 10);
	items.push_back(sword);
	/*********************************************/

	/********** Instantiating creatures **********/
	creatures.push_back(new Creature("Raging Fox", "It's not a normal fox, it has the skin reversed!", southGarden, 56, 40, 26, 92, 4000));
	creatures.push_back(new Creature("Raging Fox", "It's not a normal fox, it has the skin reversed!", forest, 56, 40, 26, 92, 4000));
	creatures.push_back(new Creature("Assasins Bees", "These bees move frantically, it will be difficult to reach them!", eastGarden, 49, 31, 17, 89, 2000));
	creatures.push_back(new Creature("Twisted Rabbit", "What is wrong with this rabbit? It is completely amorphous!", eastGarden, 53, 37, 20, 77, 5500));
	creatures.push_back(new Creature("Twisted Rabbit", "What is wrong with this rabbit? It is completely amorphous!", southGarden, 53, 37, 20, 77, 5500));
	creatures.push_back(new Creature("Bloody Bear", "This bear has his mouth all bloody, it seems that he has just eaten something...", forest, 62, 46, 33, 75, 8000));
	creatures.push_back(new Creature("Poisonous Hyena", "The smell of this animal is corrosive, it seems to be rotten.", plain, 51, 42, 27, 83, 6000));
	creatures.push_back(new Creature("Damned Vulture", "It has a strange glow in the eyes, if you look at them for a long time it seems that it can enter your mind.", plain, 47, 33, 19, 88, 4500));
	creatures.push_back(new Creature("Wicked Wizard", "He seems to be the cause of all this. I'm afraid ... I feel his power and it's huge.", village, 55, 47, 43, 93, 4000));
	/*********************************************/

	/********** Instantiating the player *********/
	player = new Player("Jacke", "The hero of the adventure", bedroom, 53, 44, 60, 80, 5000);
	/*********************************************/
}

World::~World()
{
	delete player;
	player = nullptr;

	for (std::vector<Creature*>::reverse_iterator it = creatures.rbegin(); it != creatures.rend(); ++it)
	{
		delete *it;
		*it = nullptr;
	}

	for (std::vector<Item*>::reverse_iterator it = items.rbegin(); it != items.rend(); ++it)
	{
		delete *it;
		*it = nullptr;
	}

	for (std::vector<Room*>::reverse_iterator it = rooms.rbegin(); it != rooms.rend(); ++it)
	{
		delete *it;
		*it = nullptr;
	}
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

bool World::CheckIfBattle()
{
	bool fight = false;

	if (!Same(player->room->name, "Corridor") && !Same(player->room->name, "Bedroom") && !Same(player->room->name, "Dinning room"))
	{
		// 20% chance
		if (RandomRange(1, 100) <= 20)
		{
			fight = true;
		}
	}

	return fight;
}

Creature* World::FindOpponent()
{
	int creatureIndex = RandomRange(0, creatures.size() - 1);

	while (creatures.at(creatureIndex)->room != player->room)
	{
		creatureIndex = RandomRange(0, creatures.size() - 1);
	}

	return creatures.at(creatureIndex);
}

bool World::Fight(Creature* opponent, bool playerAtack)
{
	bool stopFight = false;

	if (playerAtack)
	{
		int atack = RandomRange(player->atack - (100 - player->accuracy), player->atack);
		int damage = atack - opponent->defense < 0 ? 0 : atack - opponent->defense;
		opponent->health -= damage;
		if (opponent->health < 0) opponent->health = 0;
		cout << "You atack with a potency of " << atack << endl;
		cout << opponent->name << " has a defense of " << opponent->defense << endl;
		cout << opponent->name << " gets " << damage << " of damage" << endl;
		cout << opponent->name << " life falls to " << opponent->health << endl;
	}
	else
	{
		int atack = RandomRange(opponent->atack - (100 - opponent->accuracy), opponent->atack);
		int damage = atack - player->defense < 0 ? 0 : atack - player->defense;
		player->health -= damage;
		if (player->health < 0) player->health = 0;
		cout << opponent->name << " atacks you with a potency of " << atack << endl;
		cout << "You have a defense of " << player->defense << endl;
		cout << "You get " << damage << " of damage" << endl;
		cout << "Your life falls to " << player->health << endl;
	}
	cout << endl;

	if (player->health == 0 || opponent->health == 0)
	{
		if (opponent->health == 0)
		{
			cout << opponent->name << " has been defeated." << endl;
			opponent->health = opponent->vitality;
		}
		else if (player->health == 0)
		{
			cout << "You died." << endl;
			cout << "GAME OVER" << endl;
		}

		stopFight = true;
	}

	return stopFight;
}