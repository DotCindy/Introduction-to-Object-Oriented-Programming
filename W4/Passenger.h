// TODO: add file header comments here
/*
Name:	Cindy Le
Email:	cle15@myseneca.ca
Date:	May 30, 2018
OOP244 - Workshop 4
*/

// TODO: add header file guard here
#ifndef SICT_PASSENGER_H
#define SICT_PASSENGER_H
// TODO: declare your namespace here
namespace sict {
	// TODO: define the Passenger class here
	class Passenger {
		char m_name[32];
		char m_destination[32];
		int m_year;
		int m_month;
		int m_day;
	public:
		Passenger();
		Passenger(const char* name, const char* destination);
		Passenger(const char* name, const char* destination,
			int year, int month, int day);
		const char* name() const;
		bool canTravelWith(const Passenger&) const;
		bool isEmpty() const;
		void display() const;
	};
}
#endif
