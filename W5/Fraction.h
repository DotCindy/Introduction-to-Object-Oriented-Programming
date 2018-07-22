/*
Name:	Cindy Le
Email:	cle15@myseneca.ca
Date:	Jun 10, 2018
OOP244 - Workshop 5
*/

// TODO: header file guard
#ifndef SICT_FRACTION_H
#define SICT_FRACTION_H
// TODO: create namespace
namespace sict {
	// TODO: define the Fraction class
	class Fraction {
		// TODO: declare instance variables 
		int numerator;
		int denominator;
		// TODO: declare private member functions
		int max() const;
		int min() const;
		void reduce();
		int gcd() const;
	public:
		// TODO: declare public member functions
		Fraction();
		Fraction(int num, int denom);
		bool isEmpty() const;
		void display() const;
		// TODO: declare the + operator overload
		Fraction operator+(const Fraction& rhs) const;
		Fraction operator*(const Fraction& rhs) const;
		bool operator==(const Fraction& rhs) const;
		bool operator!=(const Fraction& rhs) const;
		Fraction& operator+=(const Fraction& rhs);
	};
}
#endif
