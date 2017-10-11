//----------------------------------------------------------------------------
// Transaction.cpp
// Author: Yauheniya Zapryvaryna CSS 343 Winter 2015 UWB
//----------------------------------------------------------------------------
// DESCRIPTION: Abstract Class Transaction implements a transaction object by 
//				using a character to define its type
//				
// FUNCTIONALITY: 
//	--changes (sets) type of transaction
//	--outputs the contents of a transaction to the console 
//-----------------------------------------------------------------------------

#include "Transaction.h"
#include "Store.h"
#include "Customer.h"
#include "Barter.h"
#include "History.h"
#include "HistoryAll.h"
#include "Display.h"

//-------------------------------Default Constructor-----------------------
// Creates a new Transaction object
// Pre: none
// Post: a new transaction object is created
Transaction::Transaction()
{
}

//------------------------------- Constructor-----------------------------
// Creates a new Transaction object with the type ch
// Pre: none
// Post: a transaction object is created and its type is initialized to ch.
Transaction::Transaction (char ch)
{
	this->type = ch;
}

//------------------------------- setType -------------------------------
// Sets Transaction's type
// Pre: transaction object this has been allocated in memory
// Post: this transaction's type gets assigned to ch
void Transaction::setType( char ch )
{
	this->type = ch;
}

//------------------------------- getType -------------------------------
// returns Transaction's type
// Pre: transaction object this has been allocated in memory
// Post: this transaction's type gets returned 
char Transaction::getType() const
{
	return this->type;
}

//-----------------------------  <<  ----------------------------------------
// Overloaded output operator for class Transaction
// Preconditions: a Transaction must be allocated and be of valid type (P, T,
// H, A. I)
// Postconditions: the transaction's contents are printed
ostream & operator<<(ostream &output, const Transaction &t)
{
	 t.print(output);
	 return output;
}

//-------------------------------Destructor ------------------------------
// Destructs a Transaction object
// Pre: transaction object this has been allocated in memory
// Post: transaction object id appropriately deallocated
Transaction::~Transaction()
{
}
