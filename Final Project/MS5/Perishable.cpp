// Final Project Milestone 6
//
// Version 1.0
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
/////////////////////////////////////////////////////////////////
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <fstream>
#include <cstring>
#include <iomanip>
#include "Perishable.h"
#include "Date.h"
using namespace std;

namespace AMA {
	// Constructor passes Product P to base class constructor
	// Sets current object to safe empty state in Date()
	Perishable::Perishable() : Product('P') {
		m_date = Date();
	}

	std::fstream& Perishable::store(std::fstream& file, bool newLine) const {
		// Calls base class version
		Product::store(file, false);
		// Inserts comma into file record
		file << "," << m_date;
		// If newLine is true, insert newline character
		if (newLine == true) {
			file << "\n";
		}
		return file;
	}

	std::fstream& Perishable::load(std::fstream& file) {
		// Calls base class version
		Product::load(file);
		// loads expiry date from file record using read()
		m_date.read(file);
		file.ignore();
		return file;
	}

	std::ostream& Perishable::write(std::ostream& os, bool linear) const {
		// Calls base class version
		Product::write(os, linear);
		// If current object is error or safe empty state, do nothing
		if (this->isEmpty() == true || this->isClear() == true) {
			// If linear is true, add expiry date on the same line
			if (linear == true) {
				os << m_date;
			}
			// Else, add newline character, string, expiry date
			else {
				os << "\n Expiry date: " << expiry();
			}
		}
		return os;
	}

	std::istream& Perishable::read(std::istream& is) {
		// Create temporary Date object
		Date temp;
		// Calls base class version
		Product::read(is);
		// If base class extracts successfully
		if (!is.fail()) {
			// cout string and stores it into temp Date object
			cout << " Expiry date (YYYY/MM/DD): ";
			temp.read(is);
			// if temp Date object is in error state
			if (temp.bad() == true) {
				// set member function to failbit, print corresponding error message
				is.setstate(std::ios::failbit);
				if (temp.errCode() == YEAR_ERROR) {
					message("Invalid Year in Date Entry");
				}
				else if (temp.errCode() == MON_ERROR) {
					message("Invalid Month in Date Entry");
				}
				else if (temp.errCode() == DAY_ERROR) {
					message("Invalid Day in Date Entry");
				}
				else {
					message("Invalid Date Entry");
				}
			}
			else {
				m_date = temp;
			}
		}
		return is;
	}

	// Returns expiry date
	const Date& Perishable::expiry() const {
		return m_date;
	}
}
