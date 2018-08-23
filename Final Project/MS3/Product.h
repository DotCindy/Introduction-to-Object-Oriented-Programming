// Final Project Milestone 3
//
// Version 1.0
// Date			2018-07-22
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

#ifndef AMA_PRODUCT_H
#define AMA_PRODUCT_H
#define max_sku_length 7
#define max_unit_length 10
#define max_name_length 75
#define tax_rate 0.13
#include <iostream>
#include <fstream>
#include "ErrorState.h"

namespace AMA {
	class Product {
		char m_type;	// type of product
		char m_sku[max_sku_length + 1];		// array that holds product's stock keeping unit
		char m_unit[max_unit_length + 1];	// array that describes product's unit
		char* m_name;		// pointer to name of product
		int m_qtyOnHand;	// quantity of product on hand
		int m_qtyNeed;		// quantity of product needed
		double m_price;		// price of single unit
		bool m_taxable;		// taxable status of product
		ErrorState m_errorState;	// error state of Product object
	protected:
		void name(const char* _name);	// stores name of product
		void sku(const char* _sku);		// stores sku of product
		void unit(const char* _unit);	// stores unit of product
		const char* name() const;		// returns address of name
		const char* sku() const;		// returns address of sku
		const char* unit() const;		// returns address of unit
		bool taxed() const;				// returns taxable status of product
		double price() const;			// returns price of a single item
		double cost() const;			// returns price of a single item plus any tax that applies
		void message(const char* _errorState);	// stores message in ErrorState object
		bool isClear() const;			// returns true if ErrorState object is clear
	public:
		Product(char type = 'N');		// zero-one argument constructor that optionally receives a character. 'N' is default
		Product(const char* _sku, const char* _name, const char* _unit, int _qtyOnHand = 0, 
			bool _taxable = true, double _price = 0.0, int _qtyNeed = 0);	// 7 argument constructor with default values
		Product(const Product& pr);						// copy constructor
		Product& operator=(const Product& pr);			// copy assignment constructor
		~Product();										// destructor
		std::fstream& store(std::fstream& file, bool newLine = true) const;		// inserts into fstream object
		std::fstream& load(std::fstream& file);			// extracts from fstream
		std::ostream& write(std::ostream& os, bool linear = true) const;		// writes to ostream
		std::istream& read(std::istream& is);			// reads from istream
		bool operator==(const char* _sku) const;		// returns true if string is identical
		double total_cost() const;						// returns total cost of all products on hand
		void quantity(int _qty);						// holds number of units on hand
		bool isEmpty() const;							// returns true if object is in safe empty state
		int qtyNeeded() const;							// returns number of units needed
		int quantity() const;							// returns number of units on hand
		bool operator>(const char* _sku) const;			// overload operator>
		bool operator<(const Product& pr) const;		// overload operator<
		int operator+=(int add);						// adds units to Product object and returns updated units on hand
	};
	std::ostream& operator<<(std::ostream& os, const Product& pr);	// insert a Product object into the ostream
	std::istream& operator>>(std::istream& is, Product& pr);		// extracts a Product object from the istream
	double operator+=(double& cost, const Product& pr);				// adds total cost of Product object to the double received and returns updated double
}
#endif
