/*
Name:	Cindy Le
Email:	cle15@myseneca.ca
Date:	May 30, 2018
OOP244 - Workshop 3
*/

#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <iomanip>
#include <cstring>
#include "CRA_Account.h"

using namespace std;

namespace sict {
	CRA_Account::CRA_Account() {
		m_familyName[0] = '\0';
		m_givenName[0] = '\0';
		m_sin = 0;
	}

	CRA_Account::~CRA_Account() {
	}

	void CRA_Account::set(const char* familyName, const char* givenName, int sinx) {
		int sin = sinx;
		if (sin >= min_sin && sin <= max_sin && familyName[0] != '\0' && givenName[0] != '\0') {
			int checkDigit = 0;
			for (int i = 0; i <= 4; ++i) {
				int alternate = sin % 100;
				int addSelf = alternate / 10 * 2;
				checkDigit += alternate % 10 + addSelf / 10 + addSelf % 10;
				sin /= 100;
			}
			if (checkDigit % 10 == 0) {
				m_sin = sinx;
				strncpy(m_familyName, familyName, max_name_length + 1);
				m_familyName[max_name_length] = '\0';
				strncpy(m_givenName, givenName, max_name_length + 1);
				m_givenName[max_name_length] = '\0';
			}
		}
		else {
			m_familyName[0] = '\0';
			m_givenName[0] = '\0';
			m_sin = 0;
		}
		for (int i = 0; i < max_yrs; ++i) {
			m_balance[i] = 0;
			m_nYear = 0;
		}
	}

	void CRA_Account::set(int year, double balance) {
		if (!isEmpty() && m_nYear < max_yrs) {
			m_taxYr[m_nYear] = year;
			m_balance[m_nYear] = balance;
			m_nYear++;
		}
	}

	bool CRA_Account::isEmpty() const {
		if (m_sin == 0) {
			return true;
		}
		else {
			return false;
		}
	}

	void CRA_Account::display() const {
		if (!isEmpty()) {
			cout << "Family Name: " << m_familyName << endl;
			cout << "Given Name : " << m_givenName << endl;
			cout << "CRA Account: " << m_sin << endl;
			cout << fixed << setprecision(2);
			for (int i = 0; i < m_nYear; ++i) {
				cout << "Year (" << m_taxYr[i] << ") ";
				if (m_balance[i] > 2) {
					cout << "balance owing: " << m_balance[i] << endl;
				}
				else if (m_balance[i] < -2) {
					cout << "refund due: " << -m_balance[i] << endl;
				}
				else {
					cout << "No balance owing or refund due!" << endl;
				}
			}
		}
		else {
			cout << "Account object is empty!" << endl;
		}
	}
}
