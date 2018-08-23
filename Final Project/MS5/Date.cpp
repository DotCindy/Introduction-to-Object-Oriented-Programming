// Final Project Milestone 6
//
// Version 2.0
// Date			2018-08-07
// Author		Cindy Le
// Description
//
//
//
//
// Revision History
// -----------------------------------------------------------
// Name               Date                 Reason
// Cindy Le			  2018-06-29		   Original
/////////////////////////////////////////////////////////////////
#include <iostream>
#include <iomanip>
#include "Date.h"
using namespace std;

namespace AMA {

	// number of days in month mon_ and year year_
	int Date::mdays(int mon, int year)const {
		int days[] = { 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31, -1 };
		int month = mon >= 1 && mon <= 12 ? mon : 13;
		month--;
		return days[month] + int((month == 1)*((year % 4 == 0) && (year % 100 != 0)) || (year % 400 == 0));
	}

	void Date::errCode(int errorCode) {
		m_errorState = errorCode;
	}

	// Default constructor
	Date::Date() {
		m_year = 0;
		m_month = 0;
		m_day = 0;
		m_comparator = 0;
		m_errorState = NO_ERROR;
	}

	// Constructor with 3 arguments
	Date::Date(int year, int month, int day) {
		m_comparator = year * 372 + month * 13 + day;
		if (m_comparator > 0) {
			if (year < min_year || year > max_year) {
				m_year = 0;
				m_month = 0;
				m_day = 0;
				m_comparator = 0;
				m_errorState = YEAR_ERROR;
			}
			else if (month < 1 || month > 12) {
				m_year = 0;
				m_month = 0;
				m_day = 0;
				m_comparator = 0;
				m_errorState = MON_ERROR;
			}
			else if (day < 1 || day > mdays(month, year)) {
				m_year = 0;
				m_month = 0;
				m_day = 0;
				m_comparator = 0;
				m_errorState = DAY_ERROR;
			}
			else {
				m_year = year;
				m_month = month;
				m_day = day;
				m_comparator = 0;
				m_errorState = NO_ERROR;
			}
		}
		else {
			m_year = 0;
			m_month = 0;
			m_day = 0;
			m_comparator = 0;
			m_errorState = NO_ERROR;
		}
	}

	// Returns true if left side = right side
	bool Date::operator==(const Date& rhs) const {
		if (m_year == rhs.m_year && m_month == rhs.m_month && m_day == rhs.m_day) {
			return true;
		}
		else {
			return false;
		}
	}

	// Returns true if left side != right side
	bool Date::operator!=(const Date& rhs) const {
		if (m_year == rhs.m_year && m_month == rhs.m_month && m_day == rhs.m_day) {
			return false;
		}
		else {
			return true;
		}
	}

	// Returns true if left side < right side
	bool Date::operator<(const Date& rhs) const {
		if (m_year == rhs.m_year && m_month == rhs.m_month && m_day < rhs.m_day) {
			return true;
		}
		else if (m_year == rhs.m_year && m_month < rhs.m_month) {
			return true;
		}
		else if (m_year < rhs.m_year) {
			return true;
		}
		else {
			return false;
		}
	}

	// Returns true if left side > right side
	bool Date::operator>(const Date& rhs) const {
		if (m_year == rhs.m_year && m_month == rhs.m_month && m_day > rhs.m_day) {
			return true;
		}
		else if (m_year == rhs.m_year && m_month > rhs.m_month) {
			return true;
		}
		else if (m_year > rhs.m_year) {
			return true;
		}
		else {
			return false;
		}
	}

	// Returns true if left side <= right side
	bool Date::operator<=(const Date& rhs) const {
		if (m_year == rhs.m_year && m_month == rhs.m_month && m_day <= rhs.m_day) {
			return true;
		}
		else if (m_year == rhs.m_year && m_month <= rhs.m_month) {
			return true;
		}
		else if (m_year <= rhs.m_year) {
			return true;
		}
		else {
			return false;
		}
	}

	// Returns true if left side >= right side
	bool Date::operator>=(const Date& rhs) const {
		if (m_year == rhs.m_year && m_month == rhs.m_month && m_day >= rhs.m_day) {
			return true;
		}
		else if (m_year == rhs.m_year && m_month >= rhs.m_month) {
			return true;
		}
		else if (m_year >= rhs.m_year) {
			return true;
		}
		else {
			return false;
		}
	}

	// Returns ERROR state as 0-4
	int Date::errCode() const {
		return m_errorState;
	}

	// Returns true if error state is not NO_ERROR
	bool Date::bad() const {
		if (m_errorState != 0) {
			return true;
		}
		else {
			return false;
		}
	}

	// Reads the date from console
	std::istream& Date::read(std::istream& istr) {
		char c;

		istr >> m_year >> c >> m_month >> c >> m_day;

		if (istr.fail()) {
			m_errorState = CIN_FAILED;
		}
		else {
			if (m_year < min_year || m_year > max_year) {
				m_year = 0;
				m_month = 0;
				m_day = 0;
				m_comparator = 0;
				m_errorState = YEAR_ERROR;
			}
			else if (m_month < 1 || m_month > 12) {
				m_year = 0;
				m_month = 0;
				m_day = 0;
				m_comparator = 0;
				m_errorState = MON_ERROR;
			}
			else if (m_day < 1 || m_day > mdays(m_month, m_year)) {
				m_year = 0;
				m_month = 0;
				m_day = 0;
				m_comparator = 0;
				m_errorState = DAY_ERROR;
			}
			else {
				m_errorState = NO_ERROR;
			}
		}
		return istr;
	}

	// Writes the date to ostream
	std::ostream& Date::write(std::ostream& ostr) const {
		ostr << m_year << "/" << setw(2) << setfill('0') <<
			m_month << "/" << setw(2) << setfill('0') <<
			m_day;
		return ostr;
	}

	// Prints date
	std::ostream& operator<<(std::ostream& os, const Date& rhs) {
		rhs.write(os);
		return os;
	}

	// Reads date
	std::istream& operator >> (std::istream& is, Date& rhs) {
		rhs.read(is);
		return is;
	}
}
