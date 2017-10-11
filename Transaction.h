//----------------------------------------------------------------------------
// Transaction.h
// Author: Yauheniya Zapryvaryna CSS 343 Winter 2015 UWB
//----------------------------------------------------------------------------
// DESCRIPTION: Abstract Class Transaction implements a transaction object by 
//				using a character to define its type
//				
// FUNCTIONALITY: 
//	--changes (sets) type of transaction
//	--outputs the contents of a transaction to the console 
//-----------------------------------------------------------------------------

#pragma once
#include <fstream>
using namespace std;
class Store;
class Transaction
{

//-----------------------------  <<  ----------------------------------------
// Overloaded output operator for class Transaction
// Preconditions: a Transaction must be allocated and be of valid type (P, T,
// H, A. I)
// Postconditions: the transaction's contents are printed
friend ostream& operator<<(ostream& , const Transaction&);
public:

	//-------------------------------Default Constructor-----------------------
	// Creates a new Transaction object
	// Pre: none
	// Post: a new transaction object is created
	Transaction();

	//------------------------------- Constructor-----------------------------
	// Creates a new Transaction object with the type ch
	// Pre: none
	// Post: a transaction object is created and its type is initialized to ch.
	Transaction (char);

	//------------------------------- setType -------------------------------
	// Sets Transaction's type
	// Pre: transaction object this has been allocated in memory
	// Post: this transaction's type gets assigned to ch
	virtual void setType(char );

	//------------------------------- getType -------------------------------
	// returns Transaction's type
	// Pre: transaction object this has been allocated in memory
	// Post: this transaction's type gets returned 
	virtual char getType() const;

	//---------------------------------- print -------------------------------
	// Prints the transaction on the console
	// Pre: transaction object this has been allocated in memory
	// Post: the transaction gets printed on the console
	virtual void print (ostream &) const = 0; 

	//------------------------------ perform ---------------------------------
	// Performs a transaction according to its specs
	// Pre: transaction object this has been allocated in memory
	// Post: a transaction is performed according to its specs
	virtual bool perform(Store *, bool &) = 0;

	//------------------------------ create -----------------------------------
	// Creates a new Transaction from file input
	// Pre: ifstream has data to read
	// Post: a transaction is created using factory method
	virtual Transaction * create(ifstream & , Store *) = 0;

	//-------------------------------Destructor ------------------------------
	// Destructs a Transaction object
	// Pre: transaction object this has been allocated in memory
	// Post: transaction object is appropriately deallocated
	virtual ~Transaction();

protected:
	char type;
};

