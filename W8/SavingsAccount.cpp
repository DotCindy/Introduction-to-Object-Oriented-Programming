/*
Name:	Cindy Le
Email:	cle15@myseneca.ca
Date:	Jul 16, 2018
OOP244 - Workshop 8
*/

#include "SavingsAccount.h"
using namespace std;

namespace sict {
	// Setting to safe empty state
	SavingsAccount::SavingsAccount() : Account() {
		m_interestRate = 0;
	}

	// Setting to safe empty state
	SavingsAccount::SavingsAccount(double balance, double interestRate) : Account(balance) {
		if (interestRate >= 0) {
			m_interestRate = interestRate;
		}
		else {
			m_interestRate = 0.0;
		}
	}

	// Calculates interest earned on current balance and credits account with that interest
	void SavingsAccount::monthEnd() {
		Account::credit(Account::balance() * m_interestRate);
	}

	// Displays account information
	void SavingsAccount::display(std::ostream& os) const {
		os.setf(ios::fixed);
		os.precision(2);
		os << "Account type: Savings" << endl;
		os << "Balance: $" << balance() << endl;
		os << "Interest Rate (%): " << m_interestRate * 100 << endl;
	}
}
