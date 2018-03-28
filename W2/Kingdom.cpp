/*
Name:                   Cindy Le
Email:                  cle15@myseneca.ca
Workshop:               At Home
Date:                   January 30, 2018
Description:            Dynamic Memory
*/

// TODO: include the necessary headers
#include <iostream>
#include "Kingdom.h"
using namespace std;

// TODO: the sict namespace
namespace sict {
	// TODO:definition for display(...) 
	void display(Kingdom& kingdom) {
		cout << kingdom.m_name << ", population " << kingdom.m_population << endl;
	};

	void display(const Kingdom* kingdom, int count) {
		cout << "------------------------------" << endl;
		cout << "Kingdoms are" << endl;
		cout << "------------------------------" << endl;
		int sum = 0;
		for (int i = 0; i < count; i++) {
			cout << i + 1 << ". "      
			<< kingdom[i].m_name << ", population " 
			<< kingdom[i].m_population << endl;
			sum += kingdom[i].m_population;
		}
		cout << "------------------------------" << endl;
		cout << "Total population of all Kingdoms: " << sum << endl;
		cout << "------------------------------" << endl;
	}
}
