/*
Name:	Cindy Le
Email:	cle15@myseneca.ca
Date:	Jul 16, 2018
OOP244 - Workshop 8
*/

#ifndef SICT_ACCOUNT_H__
#define SICT_ACCOUNT_H__
#include "iAccount.h"

namespace sict {
	class Account : public iAccount {
		// Holds the current balance
		double m_balance;
	protected:
		// Returns the current balance
		double balance() const;
	public:
		// Default constructor
		Account();

		// TODO: constructor initializes account balance, defaults to 0.0 
		Account(double balance);

		// TODO: credit adds +ve amount to the balance 
		bool credit(double addAmount);

		// TODO: debit subtracts a +ve amount from the balance
		bool debit(double deductAmount);
	};
}
#endif
