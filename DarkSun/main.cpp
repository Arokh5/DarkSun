#include <iostream>
#include <thread>         // std::this_thread::sleep_for
#include <chrono>         // std::chrono::seconds
#include <string>
#include <vector>
#include <conio.h>
#include "World.h"
#include "Player.h"
#include "Room.h"
#include "globals.h"
#include "time.h"

using namespace std;

enum GameStates
{
	NOFIGHT,
	FIGHT
};

int main()
{
	GameStates gameState = NOFIGHT;
	Creature* opponent = nullptr;
	clock_t gameNow = clock();
	clock_t playerNow = clock();
	clock_t opponentNow = clock();
	char key;
	string playerInput;
	vector<string> args;
	bool quit = false;
	World world;
	int playerAtackSpeed;
	int opponentAtackSpeed;
	int sleepTime = 3;

	cout << "  *--------------------------------------*" << endl;
	cout << "*---------- Welcome to Dark Sun -----------*" << endl;
	cout << "  *--------------------------------------*" << endl << endl;
	cout << "You are a ten years old child that lives with his parents and his little sister in a tiny house in the forest, few meters of a village called Asmund." << endl;
	cout << "You are lying in your bed, you wake up and open your eyes. There is something strange in your bedroom. Everything seems to be on the opposite side, inverted." << endl;
	cout << "You get up and stand in the middle of the room. It's time to investigate what's going on..." << endl;
	cout << "> ";

	while (!quit)
	{
		if (gameState == NOFIGHT)
		{
			// Check if key pressed is available
			// The kbhit function returns 0 if has not been recorded a key pressed. If one is available, then the value returned is nonzero.
			if (_kbhit() != 0)
			{
				// Get the key pressed
				key = _getch();
				// Backspace (delete)
				if (key == '\b')
				{
					if (playerInput.length() > 0)
					{
						// Delete the last char introduced and put the cursor in the right place to continue writting
						playerInput.pop_back();
						cout << '\b';
						cout << " ";
						cout << '\b';
					}
				}
				// Return
				else if (key != '\r')
				{
					// Add to playerInput each introduced char
					playerInput += key;

					// Write by console each char introduced
					cout << key;
				}
				else
				{
					Tokenize(playerInput, args);
				}
			}

			if (args.size() > 0 && (Same(args[0], "quit") || Same(args[0], "q")))
			{
				quit = true;
				cout << endl;
			}
			else if (args.size() > 0)
			{
				world.ParseCommand(args);
				args.clear();
				playerInput.clear();
				cout << "> ";
			}

			// Check each 5 seconds
			if (clock() - gameNow >= 5000)
			{
				if (world.CheckIfBattle() || Same(world.player->room->name, "Village"))
				{
					gameState = FIGHT;
					args.clear();
					opponent = world.FindOpponent();
					playerAtackSpeed = world.player->atackSpeed <= 0 ? 1000 : world.player->atackSpeed;
					opponentAtackSpeed = opponent->atackSpeed <= 0 ? 1000 : opponent->atackSpeed;
					playerNow = clock();
					opponentNow = clock();
					cout << endl << "A " << opponent->name << " appears!" << endl;
					cout << opponent->description << endl;
				}
				gameNow = clock();
			}
		}

		if (gameState == FIGHT)
		{
			if (clock() - playerNow >= playerAtackSpeed)
			{
				if (world.Fight(opponent, true))
				{
					if (Same(opponent->name, "Wicked Wizard"))
					{
						cout << "Congratulations! You have saved the world from the threat of the mad magician. ";
						cout << "Now peace reigns on earth again and you can return with your family, they are waiting for you at home!" << endl;
						sleepTime = 10;
						quit = true;
					}
					else
					{
						gameState = NOFIGHT;
						gameNow = clock();
						cout << "> ";
					}
				}
				playerNow = clock();
			}
			else if (clock() - opponentNow >= opponentAtackSpeed)
			{
				if (world.Fight(opponent, false))
				{
					gameState = NOFIGHT;
					quit = true;
				}
				opponentNow = clock();
			}
		}
	}

	cout << "Thanks for playing Black Sun, come back again!" << endl;
	this_thread::sleep_for(std::chrono::seconds(sleepTime));
	return 0;
}