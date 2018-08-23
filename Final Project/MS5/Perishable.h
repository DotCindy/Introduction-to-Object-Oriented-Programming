// Final Project Milestone 6
//
// Version 1.0
// Date			2018-08-06
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

#ifndef AMA_PERISHABLE_H
#define AMA_PERISHABLE_H
#include <iostream>
#include <fstream>
#include "Product.h"
#include "Date.h"

namespace AMA {
	class Perishable : public Product {
		Date m_date;		// Date object that holds expiry date for perishable product
	public:
		// No argument constructor
		Perishable();
		// Stores single file record for current object
		std::fstream& store(std::fstream& file, bool newLine = true) const;
		// Extracts data field for single record from fstream
		std::fstream& load(std::fstream& file);
		// Writes data in either linear or non-linear format
		std::ostream& write(std::ostream& os, bool linear) const;
		// Reads data extracted from istream object
		std::istream& read(std::istream& is);
		// Returns expiry date
		const Date& expiry() const;
	};
}

#endif
