/*
Name:	Cindy Le
Email:	cle15@myseneca.ca
Date:	Jul 10, 2018
OOP244 - Workshop 7
*/

#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <iomanip>
#include <cstring>
#include "Hero.h"
using namespace std;

namespace sict {
	// Default constructor
	Hero::Hero() {
		m_name[0] = '\0';
		m_hp = 0;
		m_attStr = 0;
	}

	// Constructor with 3 variable
	Hero::Hero(const char* name, int health, int strength) {
		strcpy(m_name, name);
		m_hp = health;
		m_attStr = strength;
	}

	// Deducts strength
	void Hero::operator-=(int attack) {
		m_attStr -= m_attStr;
	}

	// Returns true if current object's health is > 0
	bool Hero::isAlive() const {
		if (m_hp > 0) {
			return true;
		}
		else {
			return false;
		}
	}

	// Returns attack strength of current object
	int Hero::attackStrength() const {
		if (m_name[0] == '\0' && m_hp == 0 && m_attStr == 0) {
			return 0;
		}
		else {
			return m_attStr;
		}
	}

	// Deducts attack from health
	void Hero::deductHp(int att) {
		m_hp -= att;
	}

	// Display function for the friend function below
	// Inserts name of hero into os stream
	std::ostream& Hero::display(std::ostream& ostr) const {
		if (m_name[0] != '\0' && m_hp != 0 && m_attStr != 0) {
			ostr << m_name;
		}
		else {
			cout << "No hero" << endl;
		}
		return ostr;
	}

	std::ostream& operator<<(std::ostream& os, const Hero& hero) {
		return hero.display(os);
	}

	// Deduct attack from health
	void applyDmg(Hero& first, Hero& second) {
		if (first.isAlive() && second.isAlive()) {
			first.deductHp(second.attackStrength());
			second.deductHp(first.attackStrength());
		}
	}

	// Returns winner of the battle
	const Hero& operator*(const Hero& first, const Hero& second) {
		int round = 0;
		const Hero *winner = nullptr;
		Hero a = first;
		Hero b = second;
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
		cout << "Ancient Battle! " << first << " vs " << second << " : " <<
			"Winner is " << *winner << " in " << round << " rounds." << endl;
		return *winner;
	}
}
