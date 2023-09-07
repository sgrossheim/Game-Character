//-------------------------------------------------------------------------------
// Name: Sarah Grossheim
// Course-Section: CS355_01
// Assignment #3: GameCharacter Class
// Date due: 08/31/2023
// Description: Create a class that represents a character in a video game.
// ------------------------------------------------------------------------------
#include "GameCharacterAdvanced.h"
#include <fstream>
#include <iostream>
#include <string>
using namespace std;
/* Function Name: GameCharacter(string, int, int, int) (constructor)
 * Function Description: initializes character's attributes to specified input
 * Return Value: none*/
GameCharacter::GameCharacter(string Name, int mH, int aP, int dP)
{
	name = Name;
	maxHealth = mH;
	attackPoints = aP;
	defensePoints = dP;
	healthPoints = maxHealth;
	isAlive = true;
}

/* Function Name: getName()
 * Function Description: gets character's name
 * Return Value: string*/
string GameCharacter::getName() const
{
	return name;
}

/* Function Name: getMaxHealth()
 * Function Description: gets character's max health
 * Return Value: int*/
int GameCharacter::getMaxHealth() const
{
	return maxHealth;
}

/* Function Name: getHealthPoints()
 * Function Description: gets character's health points
 * Return Value: int*/
int GameCharacter::getHealthPoints() const
{
	return healthPoints;
}

/* Function Name: getAttackPoints()
 * Function Description: gets character's attack points
 * Return Value: int*/
int GameCharacter::getAttackPoints() const
{
	return attackPoints;
}

/* Function Name: getDefensePoints()
 * Function Description: gets character's defense points
 * Return Value: int*/
int GameCharacter::getDefensePoints() const
{
	return defensePoints;
}

/* Function Name: isAlive()
 * Function Description: determines whether the chracter is alive or not
 * Return Value: bool*/
bool GameCharacter::getIsAlive() const
{
	return isAlive;
}

/* Function Name: takeDamage(int damage)
 * Function Description: reduces character's health by the damage amount,
 * 			 if enough damage is taken, the affected player 
 * 			 will die
 * Return Value: void */
void GameCharacter::takeDamage(int damage)
{
	// subtract damage from health points
	healthPoints -= damage;
	
	// If the health points are less than 0, then player is dead
	if(healthPoints <=  0)
	{
		isAlive = false;
	}
}

/* Function Name: attack(GameCharacter& target)
 * Function Description: Attacks a targeted character and calculates
 * 			 the total damage based on the attacker's
 * 			 attack points and the target's defense points
 * Return Value: void */
void GameCharacter::attack(GameCharacter& target)
{
	// Create variable for the amount of damage
	int damage;
	
	// Damage is the difference between the attacker's attack points
	// and the target's defense points
	damage = attackPoints - target.defensePoints;

	// If damage is is greater than or equal to 0, apply the damage
	if(damage >= 0)
	{
		target.takeDamage(damage);
	}
}

/* Function Name: play(GameCharacter& player)
 * Function Description: Create and fight the boss character until death
 * Return Value: void */
void GameCharacter::play(GameCharacter& player)
{
	// Create variable for if the game is done
	bool done = false;
	
	cout << "Now " << player.name << ", Fight THE BOSS to the death!!!!" << endl << endl;
	
	// Create final boss character and show details
	GameCharacter gc4("THE BOSS - Dr. Ray", 30, 45, 20);
	cout << gc4;
	
	// Create counter variable 
	int i = 1;
	
	// While both players are still alive, play the game.
	while(!done)
	{
		// Display what round it is
		cout << "Round " << i << endl;

		// Let player attack the boss
		cout << player.name << " attacks " << gc4.name << endl << endl;
		player.attack(gc4);
		
		// Display boss's current health
		cout << " - " << gc4.name << " Current Health: " << gc4.healthPoints << endl;
		cout << endl;
	
		// Check to see if the boss is dead
		if(gc4.isAlive == false)
		{
			cout << "---------------------------------------------------" << endl;
			cout << gc4.name << " has died!" << endl << endl;
			cout << player.name << " has won the game!" << endl;
			done = true;
			cout << "---------------------------------------------------" << endl;
			return;
		}
		
		// The boss attacks player
		cout << gc4.name << " attacks " << player.name << endl << endl;
		gc4.attack(player);
		
		// Display player's current health
		cout << " - " << player.name << " Current Health: " << player.healthPoints << endl;
		cout << endl;
		cout << "---------------------------------------------------" << endl;

		// Check to see if player is dead
		if(player.isAlive == false)
		{
			cout << player.name << " has died!" << endl << endl;
			cout << gc4.name << " has won the game!" << endl;
			done = true;
			cout << "---------------------------------------------------" << endl;
			return;
		}
		// Add 1 to round counter
		i++;
	}
}

/* Function Name: saveToFile(const string& filename) const
 * Function Description: Saves characters details to a file
 * Return Value: none */
void GameCharacter::saveToFile(const string& filename) const
{
	ofstream outFile(filename);
	if(outFile.fail())
	{
		cout << "Failed to open file for writing." << endl;
		exit(1);
	}
	// Output attributes to a file
	outFile << name << endl;
	outFile << maxHealth << endl;
	outFile << attackPoints << endl;
	outFile << defensePoints << endl;
	outFile << healthPoints << endl;
	outFile << isAlive << endl;
}

/* Function Name: loadFromFile(const string& filename) const
 * Function Description: Takes character's details from file to use in program
 * Return Value: none */
void GameCharacter::loadFromFile(const string& filename) 
{
	ifstream inFile(filename);
	if(inFile.fail())
	{
		cout << "Failed to open file for reading." << endl;
		exit(1);
	}
	// Input attributes from file
	getline(inFile, name);
	inFile >> maxHealth;
	inFile >> attackPoints;
	inFile >> defensePoints;
	inFile >> healthPoints;
	inFile >> isAlive;
}
 
/* Function Name: (Overloading < operator)
 * Function Description: Compares characters based on health
 * Return Value: bool */
bool operator<(GameCharacter lhs, GameCharacter rhs)
{
	if(lhs.getHealthPoints() < rhs.getHealthPoints())
	{
		return true;
	}
	else
	{
		return false;
	}
}

/* Function Name: (Overloading > operator)
 * Function Description: Compares Characters based on heatlh
 * Return Value: bool */
bool operator>(GameCharacter lhs, GameCharacter rhs)
{
	if(lhs.getHealthPoints() > rhs.getHealthPoints())
	{
		return true;
	}
	else
	{
		return false;
	}
}

/* Function Name: (Overloading << Operator)
 * Function Description: Prints out character's details
 * Return Value: ostream& */
ostream& operator<<(ostream& os, const GameCharacter& gc)
{
	os << "Name: " << gc.name << endl;
	os << "Max Health: " << gc.maxHealth << endl;
	os << "Health Points: " << gc.healthPoints << endl;
	os << "Attack Points: " << gc.attackPoints << endl;
	os << "Defense Points: " << gc.defensePoints << endl;
	cout << "---------------------------------------------------" << endl;

	return os;
}

/* Function Name: (Overloading + Operator)
 * Function Description: Combine two character's attributes to create
 * 			 a new character. The new character's maxHealth
 * 			 is the sum of the original character's maxHealth,
 * 			 and the rest of the attributes are averages
 * Return Value: GameCharacter */
GameCharacter GameCharacter::operator+(const GameCharacter& lhs)
{
	GameCharacter temp("Placeholder", 0,0,0);
	temp.name = "GIRL BOSS - Morgan Burcham";
	temp.maxHealth = lhs.maxHealth + maxHealth;
	temp.attackPoints = ((lhs.attackPoints + attackPoints) / 2);
	temp.defensePoints = ((lhs.defensePoints + defensePoints) / 2);
	temp.healthPoints = temp.maxHealth;
	temp.isAlive = true;

	return temp;
}
