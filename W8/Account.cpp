/*
Name:	Cindy Le
Email:	cle15@myseneca.ca
Date:	Jul 16, 2018
OOP244 - Workshop 8
*/

#include "Account.h"
using namespace std;

namespace sict {
	// Setting to safe empty state
	Account::Account() {
		m_balance = 0.0;
	}

	// Setting to safe empty state
	Account::Account(double balance) {
		if (balance >= 0.0) {
			m_balance = balance;
		}
		else {
			m_balance = 0.0;
		}
	}

	// Return true if amount is greater than or equal to $0
	bool Account::credit(double addAmount) {
		if (addAmount >= 0) {
			m_balance += addAmount;
			return true;
		}
		else {
			return false;
		}
	}

	// Return true if amount is greater than or equal to $0
	bool Account::debit(double deductAmount) {
		if (deductAmount >= 0) {
			m_balance -= deductAmount;
			return true;
		}
		else {
			return false;
		}
	}

	// Return current balance
	double Account::balance() const {
		return m_balance;
	}
}
