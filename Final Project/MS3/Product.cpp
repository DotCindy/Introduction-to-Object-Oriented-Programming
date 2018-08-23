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

#define _CRT_SECURE_NO_WARNINGS
#define filename "ms3.txt"
#include <iostream>
#include <iomanip>
#include <cstring>
#include <fstream>
#include "Product.h"
using namespace std;

namespace AMA {
	// zero-one argument constructor
	Product::Product(char type) {
		m_type = type;
		m_sku[0] = '\0';
		m_unit[0] = '\0';
		m_name = nullptr;
		m_qtyOnHand = 0;
		m_qtyNeed = 0;
		m_price = 0.00;
		m_taxable = false;
	}

	// seven-argument constructor
	Product::Product(const char* _sku, const char* _name, const char* _unit, int _qtyOnHand, bool _taxable, double _price, int _qtyNeed) {
		sku(_sku);
		name(_name);
		unit(_unit);
		m_qtyOnHand = _qtyOnHand;
		m_qtyNeed = _qtyNeed;
		m_price = _price;
		m_taxable = _taxable;
	}
	
	// copy constructor
	Product::Product(const Product& pr) {
		if (pr.m_name != nullptr) {
			name(pr.m_name);
		}
		strncpy(m_sku, pr.m_sku, max_sku_length);
		strncpy(m_name, pr.m_name, max_name_length);
		strncpy(m_unit, pr.m_unit, max_unit_length);
		m_qtyOnHand = pr.m_qtyOnHand;
		m_qtyNeed = pr.m_qtyNeed;
		m_price = pr.m_price;
		m_taxable = pr.m_taxable;
	}

	// copy assignment constructor
	Product& Product::operator=(const Product& pr) {
		if (this != &pr) {
			strncpy(m_sku, pr.m_sku, max_sku_length);
			strncpy(m_unit, pr.m_unit, max_unit_length);
			m_price = pr.m_price;
			m_qtyOnHand = pr.m_qtyOnHand;
			m_qtyNeed = pr.m_qtyNeed;
			m_taxable = pr.m_taxable;
			delete[] m_name;
			name(pr.m_name);
		}
		return *this;
	}

	// destructor
	Product::~Product() {
		delete[] m_name;
	}

	// stores name of product
	void Product::name(const char* _name) {
		if (_name == nullptr) {
			m_name = nullptr;
		}
		else {
			m_name = new char[max_name_length + 1];
			strncpy(m_name, _name, max_name_length + 1);
			m_name[max_name_length] = '\0';
		}
	}

	// stores sku of product
	void Product::sku(const char* _sku) {
		strncpy(m_sku, _sku, max_sku_length + 1);
	}

	// stores unit of product
	void Product::unit(const char* _unit) {
		strncpy(m_unit, _unit, max_unit_length + 1);
	}

	// returns address of name
	const char* Product::name() const {
		return m_name;
	}

	// returns address of sku
	const char* Product::sku() const {
		return m_sku;
	}

	// returns address of unit
	const char* Product::unit() const {
		return m_unit;
	}

	// returns taxable status of product
	bool Product::taxed() const {
		return m_taxable;
	}

	// returns price of single item
	double Product::price() const {
		return m_price;
	}

	// returns price of single item plus any tax that applies
	double Product::cost() const {
		if (taxed() == true) {
			return m_price * (tax_rate + 1);
		}
		else {
			return m_price;
		}
	}

	// stores message in ErrorState object
	void Product::message(const char* errorState) {
		m_errorState.message(errorState);
	}

	// returns true if ErrorState object is clear
	bool Product::isClear() const {
		return (m_errorState.message() == '\0');
	}

	// inserts into fstream object
	std::fstream& Product::store(std::fstream& file, bool newLine) const {
		file.open(filename, ios::out | ios::app);			// opens file
		// inserts data for current object in comma separated fields
		file << m_type << ", "
			<< m_sku << ", "
			<< m_name << ", "
			<< m_taxable << ", "
			<< fixed << setprecision(2) << price() << ", "
			<< m_qtyOnHand << ", "
			<< m_qtyNeed;
		// if bool parameter is true, insert a newline
		if (newLine == true) {
			file << endl;
		}
		file.clear();
		file.close();
		return file;
	}

	// extracts from fstream object
	std::fstream& Product::load(std::fstream& file) {
		// list temp variables to create temp object
		char t_sku[max_sku_length + 1];
		char t_unit[max_unit_length + 1];
		char* t_name = nullptr;
		int t_qtyOnHand;
		int t_qtyNeed;
		double t_price;
		bool t_taxable;
		// open file
		file.open(filename, ios::in);
		// extracts data from file
		if (file.is_open()) {
			file >> t_sku;
			file >> t_name;
			file >> t_unit;
			file >> t_taxable;
			file >> t_price;
			file >> t_qtyOnHand;
			file >> t_qtyNeed;
			file.clear();
			file.close();
			// create temp object
			Product temp = Product(t_sku, t_name, t_unit, t_qtyOnHand, t_taxable, t_price, t_qtyNeed);
			// copy assign temp object to current object
			*this = temp;
		}
		file.clear();
		file.close();
		return file;
	}

	// writes to ostream
	std::ostream& Product::write(std::ostream& os, bool linear) const {
		if (linear == true) {
			if (isEmpty()) {
				os << setw(max_sku_length) << "" << "|";
				os << setw(20) << "" << "|";
			} 
			else {
				os << left << setw(max_sku_length) << m_sku << "|";
				os << left << setw(20) << m_name << right << "|";
			}
			os << setw(7) << fixed << setprecision(2) << cost() << "|";
			os << setw(4) << m_qtyOnHand << "|";
			os << left << setw(10) << m_unit << right << "|";
			os << setw(4) << m_qtyNeed << "|";
		}
		else {
			os << " Sku: " << sku() << endl;
			os << " Name (no spaces): " << name() << endl;
			os << " Price: " << price() << endl;
			if (m_taxable == true) {
				os << " Price after tax: " << cost() << endl;
			}
			else {
				os << " N/A" << endl;
			}
			os << " Quantity on hand: " << quantity() << endl;
			os << " Quantity needed: " << qtyNeeded() << endl;
		}
		return os;
	}

	// reads from istream
	std::istream& Product::read(std::istream& is) {
		// list temp variables
		char t_sku[max_sku_length + 1];
		char t_unit[max_unit_length + 1];
		char* t_name = nullptr;
		t_name = new char[max_name_length];
		int t_qtyOnHand;
		int t_qtyNeed;
		double t_price = 0.00;
		bool t_taxable;
		char taxInput;
		double priceInput;
		int onHandInput;
		int neededInput;
		bool check = true;
		Product temp;
		// extracts data for current object in the following order
		// sku
		cout << " Sku: ";
		is >> t_sku;
		temp.sku(t_sku);
		
		// name
		cout << " Name (no spaces): ";
		is >> t_name;
		temp.name(t_name);
		
		// unit
		cout << " Unit: ";
		is >> t_unit;
		temp.unit(t_unit);
		
		// tax input only accepts y, Y, n or N
		cout << " Taxed? (y/n): ";
		is >> taxInput;
		if (taxInput == 'y' || taxInput == 'Y') {
			t_taxable = true;
		} else if (taxInput == 'n' || taxInput == 'N') {
			t_taxable = false;
		}
		else {
			cout << "Only (Y)es or (N)o are acceptable" << endl;
		}

		// price input only accepts double
		cout << " Price: ";
		is >> priceInput;
		if (is.fail()) {
			is.setstate(std::ios::failbit);
			message("Invalid Price Entry");
			check = false;
		}
		else {
			t_price = priceInput;
			check = true;
		}

		// on hand input only accepts integer
		cout << " Quantity on hand: ";
		is >> onHandInput;
		if (is.fail()) {
			is.setstate(std::ios::failbit);
			message("Invalid Quantity Entry");
			check = false;
		}
		else {
			t_qtyOnHand = onHandInput;
			check = true;
		}

		// needed input only accepts integer
		cout << " Quantity needed: ";
		is >> neededInput;
		if (is.fail()) {
			is.setstate(std::ios::failbit);
			message("Invalid Quantity Needed Entry");
			check = false;
		}
		else {
			t_qtyNeed = neededInput;
			check = true;
		}
		if (check == true) {
			*this = Product(t_sku, t_name, t_unit, t_qtyOnHand, t_taxable, t_price, t_qtyNeed);
		}
		delete[] t_name;
		return is;
	}

	// returns true if string is identical
	bool Product::operator==(const char* sku) const {
		if (strcmp(sku, m_sku) == 0) {
			return true;
		}
		else {
			return false;
		}
	}

	// returns total cost of all products on hand, including taxes
	double Product::total_cost() const {
		double total;
		if (m_taxable == true) {
			total = m_qtyOnHand * m_price * (tax_rate + 1);
		}
		else {
			total = m_qtyOnHand * m_price;
		}
		return total;
	}

	// holds number of units on hand
	void Product::quantity(int qty) {
		m_qtyOnHand = qty;
	}

	// returns true if object is in safe empty state
	bool Product::isEmpty() const {
		if (m_name[0] == '\0') {
			return true;
		}
		else {
			return false;
		}
	}

	// returns number of units needed
	int Product::qtyNeeded() const {
		return m_qtyNeed;
	}

	// returns number of units on hand
	int Product::quantity() const {
		return m_qtyOnHand;
	}

	// compares sku of current object and string received
	bool Product::operator>(const char* sku) const {
		// returns true if sku of current object is greater than string
		if (strcmp(m_sku, sku) > 0) {
			return true;
		}
		else {
			return false;
		}
	}

	bool Product::operator<(const Product& pr) const {
		// returns true if sku of current object is less than stirng
		if (strcmp(m_name, pr.m_name) > 0) {
			return true;
		}
		else {
			return false;
		}
	}

	// adds units to Product object and returns updated units on hand
	int Product::operator+=(int add) {
		if (add > 0) {
			m_qtyOnHand += add;
		}
		return m_qtyOnHand;
	}

	// insert a Product object into the ostream
	std::ostream& operator<<(std::ostream& os, const Product& pr) {
		pr.write(os);
		return os;
	}

	// extracts a Product object from the istream
	std::istream& operator>>(std::istream& is, Product& pr) {
		pr.read(is);
		return is;
	}

	// adds total cost of Product object to the double received and returns updated double
	double operator+=(double& cost, const Product& pr) {
		cost += pr.total_cost();
		return cost;
	}
}
