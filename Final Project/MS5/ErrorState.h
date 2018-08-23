// Final Project Milestone 2
//
// Version 1.0
// Date			2018-07-14
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

#ifndef AMA_ERRORSTATE_H
#define AMA_ERRORSTATE_H
#include <iostream>
namespace AMA {
	class ErrorState {
		char* pMessage;	// Pointer that holds address of message
	public:
		explicit ErrorState(const char* errorMessage = nullptr);	// Receives address of error message
		ErrorState(const ErrorState& em) = delete;	// Deleted copy constructor prevents copying of any ErrorState object
		ErrorState& operator=(const ErrorState& em) = delete;	// Deleted assignment operator prevents assignemnt of any ErrorState object to current object
		virtual ~ErrorState();	// Deallocates memory dynamically allocated by current object
		void clear();	// Clears any messages stored by current object and initializes the object to safe empty state
		bool isClear() const;	// Returns true if current object is in safe empty state
		void message(const char* str);	// Stores a copy of the string pointed to by str
		const char* message() const;	// Returns address of the message stored in current object
	};
	std::ostream& operator<<(std::ostream& os, const ErrorState& rhs);	// Sends ErrorState message to ostream object and returns reference to ostream object
}

#endif
