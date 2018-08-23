// Final Project Milestone 6
//
// Version 2.0
// Date			2018-08-06
// Author		Cindy Le
// Description	
//
//
//
//
// Revision History
// -----------------------------------------------------------
// Name               Date                 Reason
// Cindy Le			  2018-07-14		   Origial
/////////////////////////////////////////////////////////////////
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <iomanip>
#include <cstring>
#include "ErrorState.h"
using namespace std;

namespace AMA {
	// Pointer that holds address of message
	ErrorState::ErrorState(const char* errorMessage) {
		if (errorMessage == nullptr) {
			pMessage = nullptr;
		}
		else {
			pMessage = new char[(strlen(errorMessage) + 1)];
			strcpy(pMessage, errorMessage);
		}
	}

	// Deallocates memory dynamically allocated by current object
	ErrorState::~ErrorState() {
		delete[] pMessage;
		pMessage = nullptr;
	}

	// Clears any messages stored by current object and initializes the object to safe empty state
	void ErrorState::clear() {
		delete[] pMessage;
		pMessage = nullptr;
	}

	// Returns true if current object is in safe empty state
	bool ErrorState::isClear() const {
		if (pMessage == nullptr) {
			return true;
		}
		else {
			return false;
		}
	}

	// Stores a copy of the string pointed to by str
	void ErrorState::message(const char* str) {
		if (str == nullptr) {
			pMessage = nullptr;
		}
		else {
			delete[] pMessage;
			pMessage = new char[(strlen(str) + 1)];
			strcpy(pMessage, str);
		}
	}

	// Returns address of the message stored in current object
	const char* ErrorState::message() const {
		return pMessage;
	}

	// Sends ErrorState message to ostream object and returns reference to ostream object
	std::ostream& operator<<(std::ostream& os, const ErrorState& rhs) {
		if (rhs.isClear() == false) {
			std::cout << rhs.message();
		}
		return os;
	}
}
