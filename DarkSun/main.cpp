#include <iostream>
#include <string>
#include <vector>
#include <conio.h>
#include "World.h"
#include "globals.h"
#include "time.h"

using namespace std;

int main()
{
	clock_t now = clock();
	char key;
	string playerInput;
	vector<string> args;
	bool quit = false;
	World world;

	cout << "  *--------------------------------------*" << endl;
	cout << "*---------- Welcome to Dark Sun -----------*" << endl;
	cout << "  *--------------------------------------*" << endl << endl;
	cout << "You are a ten years old child that lives with his parents and his little sister in a tiny house in the forest, few meters of a village called Asmund." << endl;
	cout << "You are lying in your bed, you wake up and open your eyes. There is something strange in your bedroom. Everything seems to be on the opposite side, inverted." << endl;
	cout << "You get up and stand in the middle of the room. It's time to investigate what's going on..." << endl;
	cout << "> ";

	while (!quit)
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
		
		// Check each 5 seconds
		if (clock() - now >= 5000)
		{
			if (world.CheckIfBattle())
			{
				cout << "Fight!" << endl;
			}
			now = clock();
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
	}

	cout << "Thanks for playing Black Sun, come back again!" << endl;

	return 0;
}