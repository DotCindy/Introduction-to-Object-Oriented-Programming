/*
Name:	Cindy Le
Email:	cle15@myseneca.ca
Date:	Jul 16, 2018
OOP244 - Workshop 8
*/

// OOP244 Workshop 8: Virtual Functions and Abstract Base Classes
// File: ChequingAccount.cpp
// Version: 2.0
// Date: 2017/12/11
// Author: Chris Szalwinski, based on previous work by Heidar Davoudi
// Description:
// This file implements the ChequingAccount class
///////////////////////////////////////////////////

#include "ChequingAccount.h"
using namespace std;

namespace sict {
	// constructor initializes balance and transaction fee
	ChequingAccount::ChequingAccount() {
		m_transFee = 0.0;
		m_monthlyFee = 0.0;
	}

	// Setting safe empty state
	ChequingAccount::ChequingAccount(double balance, double transFee, double monthFee) : Account(balance) {
		if (transFee >= 0) {
			m_transFee = transFee;
		}
		else {
			m_transFee = 0.0;
		}
		if (monthFee >= 0) {
			m_monthlyFee = monthFee;
		}
		else {
			m_monthlyFee = 0.0;
		}
	}

	// credit (add) an amount to the account balance and charge fee
	// returns bool indicating whether money was credited
	bool ChequingAccount::credit(double addAmount) {
		if (Account::credit(addAmount)) {
			Account::debit(m_transFee);
			return true;
		}
		else {
			return false;
		}
	}

	// debit (subtract) an amount from the account balance and charge fee
	// returns bool indicating whether money was debited
	bool ChequingAccount::debit(double deductAmount) {
		if (Account::debit(deductAmount)) {
			Account::debit(m_transFee);
			return true;
		}
		else {
			return false;
		}
	}

	// monthEnd debits month end fee
	void ChequingAccount::monthEnd() {
		Account::debit(m_transFee);
		Account::debit(m_monthlyFee);
	}

	// display inserts account information into ostream os
	void ChequingAccount::display(std::ostream& os) const {
		os.setf(ios::fixed);
		os.precision(2);
		os << "Account type: Chequing" << endl;
		os << "Balance: $" << balance() << endl;
		os << "Per Transaction Fee: " << m_transFee << endl;
		os << "Monthly Fee: " << m_monthlyFee << endl;
	}
}
