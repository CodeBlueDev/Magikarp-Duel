#include <iostream>

using namespace std;

int main()
{
	// Variables
	bool continuePlaying = true;

	// Player information
	int playerHealth = 100;
	int playerSpirit = 10;
	int playerExperience = 0;

	// Determines whose turn it is: 1: Player 0: Magikarp
	int turnType = 1;

	// Determines what attack should be used.
	int attackType = 0;

	// Determines the amount of damage to be done.
	int damageAmount;

	// Set the title of the console.
	system("title Magikarp Duel");

	while (continuePlaying)
	{
		// Display the intro.
		cout << "A wild Magikarp has appeared!" << endl << endl;
		// Magikarp information
		int magikarpHealth = 100;

		// Main loop that checks the health of both participants.
		while (playerHealth > 0 && magikarpHealth > 0)
		{
			// Players turn
			if (turnType == 1)
			{
				// Reset the attackType
				attackType = 0;

				// Reset the damageAmount
				damageAmount = 0;

				// Display the hero information so the user knows values.
				cout << "It is YOUR turn hero." << endl << endl;
				cout << "Your HP is: " << playerHealth << "." << endl;
				cout << "Your SP is: " << playerSpirit << "." << endl;
				cout << "-----------------------" << endl;

				// Attack loop used to get a valid attack value from the user.
				while (attackType < 1 || attackType > 3)
				{
					// Display the options available to the user.
					cout << "Decide your next move:" << endl;
					cout << "1. Punch (10 DMG 0 SP)." << endl;
					cout << "2. Psyki (20 DMG 5 SP)." << endl;
					cout << "3. Nothing (0 DMG 0 SP)." << endl;
					cout << "-----------------------" << endl;

					// Read the user's input.
					cin >> attackType;

					// Check that attackType is valid.
					if (attackType < 1 || attackType > 3)
					{
						cout << "Not a valid option, try again." << endl << endl;
					}
					else if (attackType == 2 && playerSpirit - 5 < 0)
					{
						cout << "You do not have enough SP for that! Select another move." << endl << endl;
						attackType = 0;
					}
				}

				// Determine the amount of damage to deal (if any).
				if (attackType == 1)
				{
					damageAmount = 10;
				}
				else if (attackType == 2)
				{
					damageAmount = 20;
					playerSpirit -= 5;
				}

				// Display the damage done to the Magikarp
				cout << "You do: " << damageAmount << " DMG." << endl;
				magikarpHealth -= damageAmount;

				// Check if magikarpHealth is less than 0 to prevent displaying a negative value.
				if (magikarpHealth < 0)
				{
					magikarpHealth = 0;
				}

				// Display Magikarp's health so the user knows how much is left
				cout << "Wild Magikarp's HP is: " << magikarpHealth << "." << endl << endl;
				cout << "-----------------------" << endl;

				// Set it to be Magikarp's turn.
				turnType--;
			}

			// Magikarp's turn
			if (magikarpHealth > 0 && turnType == 0)
			{
				// Display the results of Magikarp's turn.
				cout << "Wild Magikarp's turn." << endl;
				cout << "Wild Magikarp bites you for: 10 DMG." << endl;
				cout << "-----------------------" << endl;

				// Set the player's health appropriately
				playerHealth -= 10;

				// Set it to be the Player's turn.
				turnType++;
			}
		}

		// Display outro text.
		if (playerHealth <= 0)
		{
			cout << "You have DIED hero!" << endl;
			continuePlaying = false;
		}
		else if (magikarpHealth <= 0)
		{
			cout << "Congratulations! You have defeated a Wild Magikarp!" << endl;
			playerExperience += 10;
			cout << "You have gained 10 experience, you now have " << playerExperience << " experience!" << endl;

			cout << "Continue playing? [No=0,Yes=1]" << endl;

			cin >> attackType;
			if(attackType == 0)
			{
				continuePlaying = false;
			}
			else
			{
				turnType = 1;
			}
		}
	}

	cout << endl << "You collected " << playerExperience << " experience in total." << endl;
	cout << "Thanks for playing!" << endl;

	// Pause the application, wait for key input to continue.
	system("pause");
	return 0;
}