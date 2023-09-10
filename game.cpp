#include <iostream>
#include <ctime>
#include "GameCharacterAdvanced.h"
using namespace std;

int main()
{	
	// Welcome the user
	cout << "---------------------------------------------------" << endl;
	cout << "Welcome to GameCharacterAdvanced!!" << endl;
	cout << "---------------------------------------------------" << endl;

	/* PLEASE USE THIS FOR TESTING MY MAIN!!!!!!!!!!!!
	 * Test Values for +, <, and > operators to make the game work!
	 * GameCharacter 1:
	 * 	+ - 25, 30, 30 (Characters are the same health, create new character
	 * 			 		this also will use loadFromFile & saveToFile)
	 * 	< - 15, 30, 30 (Character 2 wins)
	 * 	> - 25, 30, 30 (Character 1 wins)
	 * GameCharacter 2:
	 * 	+ - 25, 30, 20 (Characters are the same health, create new character
	 * 			 		this also will use loadFromFile & saveToFile)
	 * 	< - 25, 30, 30 (Character 2 wins)
	 * 	> - 15, 30, 30 (Character 1 wins)
	 */
	
	// Create first game character, display details & saveToFile
	cout << "Here is your first character: " << endl << endl;
	GameCharacter gc1("Mrs. Herath", 25, 30, 30);
	cout << gc1;
	gc1.saveToFile("Herath_details", gc1);


	// Create second game character, display details & saveToFile
	cout << "Here is your second character: " << endl << endl;
	GameCharacter gc2("Mrs. Jenkins", 25, 30, 20);
	cout << gc2;
	gc2.saveToFile("Jenkins_details", gc2);

	// Check who is stronger by using overloaded < and > operators
	cout << "- Who is stronger? " << gc1.getName() << " or " << gc2.getName() << "?" << endl;
	cout << "- Whoever wins gets to take on THE BOSS!" << endl << endl;

	// Character 1 is stronger - Goes on to fight the boss
	if(gc1 > gc2)
	{
		cout << "- " << gc1.getName() << " is stronger." << endl;
		cout << "---------------------------------------------------" << endl;
		gc1.play(gc1);
	}
	// Character 2 is stronger - Goes on to fight the boss
	else if(gc1 < gc2)
	{
		cout << "- " << gc2.getName() << " is stronger." << endl;
		cout << "---------------------------------------------------" << endl;
		gc2.play(gc2);
	}
	// Characters are even, so create a new character to fight boss
	else
	{
		cout << "OH NO! IT IS AN EVEN MATCH!! CREATING NEW CHARACTER!!!" << endl << endl;

		// Combine first to characters to make a new one
		GameCharacter gc3 = gc1 + gc2;

		// Display the details
		cout << gc3;

		// Save character 3's attributes to a file
		// This function also displays date and time of last save
		gc3.saveToFile("girlBoss_details.txt", gc3);
		
		// Create new character
		GameCharacter newbie("Placeholder", 0, 0, 0);

		// Load character 3's attributes into newly made character
		newbie.loadFromFile("girlBoss_details.txt");

		// Goes on to play the boss
		newbie.play(newbie);

		// Display time since last saved
		gc3.displayTimeSinceLastSave();
	}


	return 0;
}
