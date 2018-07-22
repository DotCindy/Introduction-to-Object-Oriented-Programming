/*
Name:	Cindy Le
Email:	cle15@myseneca.ca
Date:	Jul 10, 2018
OOP244 - Workshop 7
*/

#ifndef SICT_HERO_H
#define SICT_HERO_H
#define max_rounds 100
#include <iostream>

namespace sict {
	class Hero {
		char m_name[40];
		int m_hp;
		int m_attStr;
	public:
		Hero();		// Default constructor
		Hero(const char* name, int health, int strength);	// Constructor with 3 variables
		void operator-=(int attack);	// Deducts strength
		bool isAlive() const;	// Returns true if current object's health is > 0
		int attackStrength() const;	// Returns attack strength of current object
		void deductHp(int att);		// Deducts attack from health
		std::ostream& display(std::ostream& ostr) const;	// Insert name of hero into os stream
		friend std::ostream& operator<<(std::ostream& os, const Hero& hero);	// Friend function for function above
	};
	void applyDmg(Hero& first, Hero& second);	// Deduct attack from health
	const Hero& operator*(const Hero& first, const Hero& second);	// Returns winner of the battle
}

#endif
