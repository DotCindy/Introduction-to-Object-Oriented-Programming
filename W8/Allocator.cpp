/*
Name:	Cindy Le
Email:	cle15@myseneca.ca
Date:	Jul 16, 2018
OOP244 - Workshop 8
*/

#define _CRT_SECURE_NO_WARNINGS
#include <cstring>
#include "SavingsAccount.h" 
#include "ChequingAccount.h"
using namespace std;

namespace sict {
	// define interest rate
	double m_interestRate = 0.05;
	double m_transFee = 0.50;
	double m_monthlyFee = 2.00;

	// TODO: Allocator function
	iAccount* CreateAccount(const char* accountType, double balance) {
		iAccount* account = nullptr;	//creating account
		char temp[20];		//account to hold 20 characters
		strcpy(temp, accountType);		//copying accountType to temp
		if (temp[0] == 'S') {			//if initial character of temp is "S"
			account = new SavingsAccount(balance, m_interestRate);		//create SavingsAccount
		}
		else if (temp[0] == 'C') {
			account = new ChequingAccount(balance, m_transFee, m_monthlyFee);
		}
		else {
			account = nullptr;
		}
		return account;
	}
}
