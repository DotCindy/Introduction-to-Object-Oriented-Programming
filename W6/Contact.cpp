/*
Name:	Cindy Le
Email:	cle15@myseneca.ca
Date:	Jun 20, 2018
OOP244 - Workshop 6
*/

#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <iomanip>
#include <cstring>
#include "Contact.h"

using namespace std;

namespace sict {
	Contact::Contact() {
		m_name[0] = '\0';
		m_phone = nullptr;
		m_size = 0;
	}

	Contact::Contact(const char* name, const long long* phone, int size) {
		if (name != nullptr && name[0] != '\0') {
			m_name[0] = '\0';
			strncpy(m_name, name, 20);
			m_name[20 - 1] = '\0';

			int validSize = 0, j = 0;
			if (size > 0) {
				for (int i = 0; i < size; i++) {
					if (isValid(&phone[i])) {
						validSize++;
					}
				}
				m_phone = new long long[m_size = validSize];
				for (int i = 0; i < size; i++) {
					if (isValid(&phone[i])) {
						m_phone[j] = phone[i];
						j++;
					}
				}
			}
			else {
				m_phone = nullptr;
				m_size = 0;
			}
		}
		else {
			m_name[0] = '\0';
			m_phone = nullptr;
			m_size = 0;
		}
	}

	Contact::~Contact() {
		if (m_phone != nullptr) {
			delete[] m_phone;
		}
	}

	bool Contact::isEmpty() const {
		if (m_size == 0 && m_name[0] == '\0') {
			return true;
		}
		else {
			return false;
		}
	}

	void Contact::display() const {
		if (isEmpty()) {
			cout << "Empty contact!" << endl;
		}
		else {
			cout << m_name << endl;
			for (int i = 0; i < m_size; i++) {
				cout << "(+" << countryCode(&m_phone[i]) << ") " <<
					areaCode(&m_phone[i]) << " " <<
					(int)(phoneNum(&m_phone[i]) / 10000) << "-" <<
					std::setw(4) << std::setfill('0') <<
					phoneNum(&m_phone[i]) % 10000 << endl;
			}
		}
	}

	bool Contact::isValid(const long long* phone) const {
		if ((countryCode(phone) >= 1 && countryCode(phone) <= 99) &&
			(areaCode(phone) >= 100 && areaCode(phone) <= 999) &&
			(phoneNum(phone) >= 1000000 && phoneNum(phone) <= 9999999)) {
			return true;
		}
		else {
			return false;
		}
	}

	int Contact::countryCode(const long long* phone) const {
		return (int)(*phone / 10000000000);
	}

	int Contact::areaCode(const long long* phone) const {
		return (int)((*phone % 10000000000) / 10000000);
	}

	int Contact::phoneNum(const long long* phone) const {
		return *phone % 10000000;
	}

	Contact::Contact(const Contact& src) {
		m_name[0] = src.m_name[0];
		m_size = src.m_size;

		if (src.m_phone != nullptr) {
			m_phone = new long long[m_size];
			for (int i = 0; i < m_size; i++) {
				m_phone[i] = src.m_phone[i];
			}
		}
		else {
			m_phone = nullptr;
		}
	}

	Contact& Contact::operator=(const Contact& src) {
		if (this != &src) {
			m_name[0] = src.m_name[0];
			m_size = src.m_size;
			delete[] m_phone;

			if (src.m_phone != nullptr) {
				m_phone = new long long[m_size];
				for (int i = 0; i < m_size; i++) {
					m_phone[i] = src.m_phone[i];
				}
			}
			else {
				m_phone = nullptr;
			}
		}
		return *this;
	}

	Contact& Contact::operator+=(long long newPhone) {
		long long* temp = new long long[m_size + 1];
		int i;

		if (m_name[0] != '\0') {
			for (i = 0; i < m_size; i++) {
				temp[i] = m_phone[i];
			}
			m_size += 1;
			temp[i] = newPhone;
			delete[] m_phone;
			m_phone = temp;
		}
		else {
			Contact();
		}
		return *this;
	}
}
