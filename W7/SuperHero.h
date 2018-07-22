/*
Name:	Cindy Le
Email:	cle15@myseneca.ca
Date:	Jul 13, 2018
OOP244 - Workshop 7
*/

#ifndef SICT_SUPERHERO_H
#define SICT_SUPERHERO_H
#include <iostream>
#include "Hero.h"

namespace sict {
	class SuperHero : public Hero {
		int m_superPower;
		int m_defence;
	public:
		SuperHero();	// Default constructor
		SuperHero(const char* name, int health, int strength, int spAttack, int defence);	// Constructor with 5 variables
		int attackStrength() const;	// Returns attack strength of current object
		int defend() const;		// Returns defence of current object
	};
	void applyDmg(SuperHero& first, SuperHero& second);	// Apply damage done during battle
	const SuperHero& operator*(const SuperHero& first, const SuperHero& second);	// Returns winner of battle
}

#endif
