/*
Name:	Cindy Le
Email:	cle15@myseneca.ca
Date:	May 30, 2018
OOP244 - Workshop 3
*/

#ifndef CRA_ACCOUNT_H
#define CRA_ACCOUNT_H

namespace sict {
	const int max_name_length = 41;
	const int min_sin = 100000000;
	const int max_sin = 999999999;
	const int max_yrs = 4;

	class CRA_Account {
		char m_familyName[max_name_length];
		char m_givenName[max_name_length];
		int  m_sin;
		int  m_taxYr[max_yrs];
		double m_balance[max_yrs];
		int  m_nYear;
	public:
		CRA_Account();
		~CRA_Account();
		void set(const char* familyName, const char* givenName, int sinx);
		void set(int year, double balance);
		bool isEmpty() const;
		void display() const;
	};
}

#endif
