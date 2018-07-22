/*
Name:	Cindy Le
Email:	cle15@myseneca.ca
Date:	Jun 10, 2018
OOP244 - Workshop 5
*/

// TODO: insert header files
#include <iostream>
#include "Fraction.h"
using namespace std;

// TODO: continue the namespace
namespace sict {
	// TODO: implement the default constructor
	Fraction::Fraction() {
		numerator = 0;
		denominator = -1;
	}

	// TODO: implement the two-argument constructor
	Fraction::Fraction(int num, int denom) {
		if (num >= 0 && denom > 0) {
			numerator = num;
			denominator = denom;
			reduce();
		}
		else {
			denominator = -1;
		}
	}

	// TODO: implement the max query
	int Fraction::max() const {
		if (numerator >= denominator) {
			return numerator;
		}
		else {
			return denominator;
		}
	}

	// TODO: implement the min query
	int Fraction::min() const {
		if (numerator >= denominator) {
			return denominator;
		}
		else {
			return numerator;
		}
	}

	// gcd returns the greatest common divisor of num and denom
	//
	int Fraction::gcd() const {
		int mn = min();  // min of numerator and denominator
		int mx = max();  // max of numerator and denominator
		int g_c_d = 1;
		bool found = false;

		for (int x = mn; !found && x > 0; --x) { // from mn decrement until divisor found
			if (mx % x == 0 && mn % x == 0) {
				found = true;
				g_c_d = x;
			}
		}
		return g_c_d;
	}

	// TODO: implement the reduce modifier
	void Fraction::reduce() {
		int simplify = gcd();
		numerator /= simplify;
		denominator /= simplify;
	}

	// TODO: implement the display query
	void Fraction::display() const {
		if (isEmpty()) {
			cout << "no fraction stored";
		}
		else if (denominator == 1) {
			cout << numerator;
		}
		else {
			cout << numerator << "/" << denominator;
		}
	}

	// TODO: implement the isEmpty query
	bool Fraction::isEmpty() const {
		if (denominator == -1) {
			return true;
		}
		else {
			return false;
		}
	}

	// TODO: implement the + operator
	Fraction Fraction::operator+(const Fraction& rhs) const {
		Fraction result = *this;
		result += rhs;
		return result;
	}

	Fraction Fraction::operator*(const Fraction& rhs) const {
		Fraction result;
		if (isEmpty() || rhs.isEmpty()) {
			Fraction();
		}
		if (!isEmpty() && !rhs.isEmpty()) {
			result.numerator = numerator * rhs.numerator;
			result.denominator = denominator * rhs.denominator;
			result.reduce();
		}
		return result;
	}

	bool Fraction::operator==(const Fraction& rhs) const {
		if (isEmpty() || rhs.isEmpty()) {
			return false;
		}
		if (!isEmpty() && !rhs.isEmpty()) {
			if (numerator*rhs.denominator == rhs.numerator*denominator) {
				return true;
			}
			return false;
		}
		else {
			return false;
		}
	}

	bool Fraction::operator!=(const Fraction& rhs) const {
		if (isEmpty() || rhs.isEmpty()) {
			return false;
		}
		if (!isEmpty() && !rhs.isEmpty()) {
			if (*this != rhs) {
				return true;
			}
			return false;
		}
		else {
			return false;
		}
	}

	Fraction& Fraction::operator+=(const Fraction& rhs) {
		if (isEmpty() || rhs.isEmpty()) {
			Fraction();
		}
		if (!isEmpty() && !rhs.isEmpty()) {
			this->numerator = (numerator*rhs.denominator) + (rhs.numerator*denominator);
			this->denominator = denominator * rhs.denominator;
			this->reduce();
		}
		return *this;
	}
}
