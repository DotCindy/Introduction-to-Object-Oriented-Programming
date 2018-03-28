/*
Name:                   Cindy Le
Email:                  cle15@myseneca.ca
Workshop:               At Home
Date:                   January 30, 2018
Description:            Dynamic Memory
*/

// TODO: header safeguards
#ifndef SICT_KINGDOM_H
#define SICT_KINGDOM_H

// TODO: sict namespace
namespace sict {
	// TODO: define the structure Kingdom in the sict namespace
	struct Kingdom {
		char m_name[32];
		int m_population;
	};

	// TODO: declare the function display(...),
	//         also in the sict namespace
	void display(Kingdom& kingdom);
	void display(const Kingdom* kingdom, int count);
}
#endif
