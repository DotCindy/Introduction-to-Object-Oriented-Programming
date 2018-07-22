/*
Name:	Cindy Le
Email:	cle15@myseneca.ca
Date:	Jul 13, 2018
OOP244 - Workshop 7
*/

#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <iomanip>
#include <cstring>
#include "Hero.h"
#include "SuperHero.h"
using namespace std;

namespace sict {
	// Default constructor that inherits data members from Hero class
	SuperHero::SuperHero() : Hero() {
		m_superPower = 0;
		m_defence = 0;
	}

	// Constructor with 5 variables.
	// Inherits name, health and strength from Hero class
	SuperHero::SuperHero(const char* name, int health, int strength, int spAttack, int defence) : 
		Hero(name, health, strength) {
		m_superPower = spAttack;
		m_defence = defence;
	}

	// Returns attack strength of current object
	int SuperHero::attackStrength() const {
		return Hero::attackStrength() + m_superPower;
	}

	// Returns defence of current object
	int SuperHero::defend() const {
		return m_defence;
	}

	// Apply damage done during battle
	void applyDmg(SuperHero& first, SuperHero& second) {
		int damageA = second.attackStrength() - first.defend();
		int damageB = first.attackStrength() - second.defend();

		if (first.isAlive() && second.isAlive()) {
			first.deductHp(damageA);
			second.deductHp(damageB);
		}
	}

	// Returns winner of battle
	const SuperHero& operator*(const SuperHero& first, const SuperHero& second) {
		int round = 0;
		const SuperHero *winner = nullptr;
		SuperHero a = first;
		SuperHero b = second;
		for (int i = 0; i < max_rounds; i++) {
			if (a.isAlive() && b.isAlive()) {
				applyDmg(a, b);
				round++;
			}
		}
		if (a.isAlive()) {
			winner = &first;
		}
		else {
			winner = &second;
		}
		cout << "Super Fight! " << first << " vs " << second << " : " <<
			"Winner is " << *winner << " in " << round << " rounds." << endl;
		return *winner;
	}
}
