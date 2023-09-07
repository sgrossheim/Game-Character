//---------------------------------------------------------------------------
// Name: Sarah Grossheim
// Course-Section: CS-355-01
// Assignment #3: Game Character Class
// Date Due: 08/31/2023
// Description: Create a class that represents a character in a video game
// --------------------------------------------------------------------------
#ifndef GameCharacter_H
#define GameCharacter_H
#include <iostream>
using namespace std;

class GameCharacter
{
	private:
		string name;
		int maxHealth;
		int healthPoints;
		int attackPoints;
		int defensePoints;
		bool isAlive;

	public:
		GameCharacter(string, int, int, int);
		string getName() const;
		int getMaxHealth() const;
		int getHealthPoints() const;
		int getAttackPoints() const;
		int getDefensePoints() const;
		bool getIsAlive() const;
		void takeDamage(int damage);
		void attack(GameCharacter&);
		void play(GameCharacter&);
		void saveToFile(const string&) const;
		void loadFromFile(const string&);
		friend bool operator<(GameCharacter, GameCharacter);
		friend bool operator>(GameCharacter, GameCharacter);
		friend ostream& operator<<(ostream&, const GameCharacter&);
		GameCharacter operator+(const GameCharacter&);
};
#endif
