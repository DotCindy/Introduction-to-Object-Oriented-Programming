// TODO: add file header comments here
/*
Name:	Cindy Le
Email:	cle15@myseneca.ca
Date:	May 30, 2018
OOP244 - Workshop 4
*/

// TODO: add your headers here
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstring>
#include <iomanip>
#include "Passenger.h"
using namespace std;

// TODO: continue your namespace here
namespace sict {
	// TODO: implement the default constructor here
	Passenger::Passenger() {
		m_name[0] = '\0';
		m_destination[0] = '\0';
		m_year = 0;
		m_month = 0;
		m_day = 0;
	}

	// TODO: implement the constructor with 2 parameters here
	Passenger::Passenger(const char* name, const char* destination) {
		if (name == nullptr || destination == nullptr) {
			*this = Passenger();
		}
		else {
			strcpy(m_name, name);
			strcpy(m_destination, destination);
		}
	}

	Passenger::Passenger(const char* name, const char* destination,
		int year, int month, int day) {
		if (name == nullptr || destination == nullptr ||
			(year < 2017 || year > 2020) ||
			(month < 1 || month > 12) ||
			(day < 1 || day > 31)) {
			*this = Passenger();
		}
		else {
			strcpy(m_name, name);
			strcpy(m_destination, destination);
			m_year = year;
			m_month = month;
			m_day = day;
		}
	}

	const char* Passenger::name() const {
		return m_name;
	}

	bool Passenger::canTravelWith(const Passenger& alt) const {
		return (std::strcmp(this->m_destination, alt.m_destination) == 0) &&
			this->m_year == alt.m_year &&
			this->m_month == alt.m_month &&
			this->m_day == alt.m_day;
	}

	// TODO: implement isEmpty query here
	bool Passenger::isEmpty() const {
		if (m_name[0] == '\0' || m_destination[0] == '\0') {
			return true;
		}
		else {
			return false;
		}
	}

	// TODO: implement display query here
	void Passenger::display() const {
		if (!isEmpty()) {
			cout << m_name << " - " << m_destination << " on " <<
				m_year << "/" <<
				std::setw(2) << std::setfill('0') << m_month << "/" <<
				m_day << endl;
		}
		else {
			cout << "No Passenger!" << endl;
		}
	}
}
