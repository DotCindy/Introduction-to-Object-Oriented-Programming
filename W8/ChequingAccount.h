/*
Name:	Cindy Le
Email:	cle15@myseneca.ca
Date:	Jul 16, 2018
OOP244 - Workshop 8
*/

#ifndef SICT_CHEQUINGACCOUNT_H__
#define SICT_CHEQUINGACCOUNT_H__
#include <iostream>
#include "Account.h"

namespace sict {
	class ChequingAccount : public Account {
		// Holds transaction fee
		double m_transFee;
		// Holds month-end fee
		double m_monthlyFee;
	public:
		// TODO: constructor initializes account balance and transaction fee
		ChequingAccount();

		// Constructor
		ChequingAccount(double balance, double transFee, double monthFee);

		// TODDO: credit adds +ve amount to the balance
		bool credit(double addAmount);

		// TODO: debit subtracts a +ve amount from the balance
		bool debit(double deductAmount);

		// TODO: month end
		void monthEnd();

		// TODO: display inserts the account information into an ostream
		void display(std::ostream& os) const;
	};
}
#endif
