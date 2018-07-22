/*
Name:	Cindy Le
Email:	cle15@myseneca.ca
Date:	Jun 20, 2018
OOP244 - Workshop 6
*/

#ifndef SICT_CONTACT_H
#define SICT_CONTACT_H

namespace sict {
	class Contact {
		char m_name[20];
		long long *m_phone;
		int m_size;
		int countryCode(const long long* phone) const;
		int areaCode(const long long* phone) const;
		int phoneNum(const long long* phone) const;
		bool isValid(const long long* phone) const;
	public:
		Contact();
		Contact(const char* name, const long long* phone, int size);
		~Contact();
		bool isEmpty() const;
		void display() const;
		Contact(const Contact& src);
		Contact& operator=(const Contact&);
		Contact& operator+=(long long newPhone);
	};
}
#endif
