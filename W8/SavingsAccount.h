/*
Name:	Cindy Le
Email:	cle15@myseneca.ca
Date:	Jul 16, 2018
OOP244 - Workshop 8
*/

#ifndef SICT_SAVINGSACCOUNT_H__
#define SICT_SAVINGSACCOUNT_H__
#include "Account.h"

namespace sict {
	class SavingsAccount : public Account {
		// Holds the interest rate applied to the account
		double m_interestRate;
	public:
		// Default constructor
		SavingsAccount();

		// TODO: constructor initializes balance and interest rate
		SavingsAccount(double balance, double interestRate);

		// TODO: perform month end transactions
		void monthEnd();

		// TODO: display inserts the account information into an ostream			
		void display(std::ostream& os) const;
	};
}
#endif
