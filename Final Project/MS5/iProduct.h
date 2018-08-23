// Final Project Milestone 4
//
// Version 1.0
// Date			2018-08-01
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

#ifndef AMA_IPRODUCT_H
#define AMA_IPRODUCT_H
#include <fstream>
#include <iostream>
using namespace std;

namespace AMA {
	class iProduct {
	public:
		// insert Product records into the fstream object
		virtual std::fstream& store(std::fstream& file, bool newLine = true) const = 0;
		// extracts iProduct records from fstream object
		virtual std::fstream& load(std::fstream& file) = 0;
		// insert iProduct record for current object into ostream object
		virtual std::ostream& write(std::ostream& os, bool linear) const = 0;
		// extract iProduct record for current object from istream object
		virtual std::istream& read(std::istream& is) = 0;
		// returns true if string is identical to sku of iProduct record
		virtual bool operator==(const char*) const = 0;
		// returns cost of single unit of an iProduct with taxes
		virtual double total_cost() const = 0;
		// returns address of string containing name of an iProduct
		virtual const char* name() const = 0;
		// holds number of units of an iProduct. Sets number of units available
		virtual void quantity(int) = 0;
		// returns number of units needed
		virtual int qtyNeeded() const = 0;
		// returns number of units available
		virtual int quantity() const = 0;
		// adds units to iProduct and returns updated number of units available
		virtual int operator+=(int) = 0;
		// returns true if current object is greater than referenced iProduct object
		virtual bool operator>(const iProduct&) const = 0;
		// destructor
		virtual ~iProduct() {};
	};
	// returns address of Product object
	iProduct* CreateProduct();
	// returns address of Perishable object
	iProduct* CreatePerishable();
}
#endif
