// Final Project Milestone 1
//
// Version 1.0
// Date			2018-06-29
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
#ifndef AMA_DATE_H
#define AMA_DATE_H

#define NO_ERROR 0
#define CIN_FAILED 1
#define YEAR_ERROR 2
#define MON_ERROR 3
#define DAY_ERROR 4
#include <iostream>

namespace AMA {
	const int min_year = 2000;
	const int max_year = 2030;
	class Date {
		int m_year;
		int m_month;
		int m_day;
		int m_comparator;	// Used to compare date stored in current object with date stored in another Date object
		int m_errorState;	// For client to reference ERROR 0-4

		int mdays(int, int)const;	// Returns number of days in month of year
		void errCode(int errorCode);	// Sets error state to ERROR 0-4

	public:
		Date();	// Default constructor
		Date(int year, int month, int day);	// Constructor with 3 arguments

		bool operator==(const Date& rhs) const;	// Returns true if left side = right side
		bool operator!=(const Date& rhs) const;	// Returns true if left side != right side
		bool operator<(const Date& rhs) const;	// Returns true if left side < right side
		bool operator>(const Date& rhs) const;	// Returns true if left side > right side
		bool operator<=(const Date& rhs) const;	// Returns true if left side <= right side
		bool operator>=(const Date& rhs) const;	// Returns true if left side >= right side

		int errCode() const;	// Returns ERROR state as 0-4
		bool bad() const;	// Returns true if error state is not NO_ERROR
		std::istream& read(std::istream& istr);	// Reads the date from console
		std::ostream& write(std::ostream& ostr) const;	// Writes the date to ostream
	};
	std::ostream& operator<<(std::ostream& os, const Date& rhs);	// Prints date
	std::istream& operator>>(std::istream& is, Date& rhs);		// Reads date
}
#endif
