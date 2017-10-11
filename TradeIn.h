//----------------------------------------------------------------------------
// TradeIn.h
// Author: Yauheniya Zapryvaryna CSS 343 Winter 2015 UWB
//----------------------------------------------------------------------------
// DESCRIPTION:  Class TradeIn implements a transaction of type TradeIn, and
//				is a derived class of Barter 9inherits from Barter)
//				
// FUNCTIONALITY: 
//	--outputs the contents of a transaction to the console 
//	--performs a TradeIn transaction 
//	--inserts a TradeIn transaction into customer's history
//-----------------------------------------------------------------------------

#pragma once
#include "Store.h"
#include "Barter.h"
#include "Transaction.h"
#include <fstream> 
using namespace std;
class TradeIn: public Barter
{
public:
	//-------------------------------Default Constructor-----------------------
	// Creates a new TradeIn Transaction object
	// Pre: none
	// Post: a new TradeIn transaction object is created
	TradeIn();

	//------------------------------- Constructor-----------------------------
	// Creates a new TradeIn Transaction object with the ID of a customer,
	// and Item pointer
	// Pre: none
	// Post: a TradeIn transaction object is created and its ID and Item * get
	// initialized to given customerID and poiner to an Item object.
	TradeIn (int , Item *);

	//---------------------------------- print -------------------------------
	// Prints the transaction on the console
	// Pre: transaction object this has been allocated in memory
	// Post: the transaction gets printed on the console
	virtual void print (ostream &) const;

	//------------------------------ perform ---------------------------------
	// Performs a trade-in transaction on myStore according to its specs
	// Pre: transaction object this has been allocated in memory. myStore is a 
	// valid Store object and has been allocated in memory.
	// Post: a transaction is performed according to its specs: item is added
	// to myStore's inventory and this TradeIn transaction is added to the 
	// customer's transaction history; deleteT is changed to indicate whether the
	// transaction needs to be deleted.
	virtual bool perform(Store *, bool &);

	//------------------------------ create -----------------------------------
	// Creates a new TradeIn Transaction from file input
	// Pre: ifstream has data to read; myStore is a valid Store object which
	// has been allocated in memeory.
	// Post: a TradeIn transaction is created using factory method
	virtual Transaction * create(ifstream & , Store *);

	//-------------------------------Destructor ------------------------------
	// Destructs a TradeIn Transaction object
	// Pre: transaction object this has been allocated in memory
	// Post: transaction object is appropriately deallocated
	virtual~TradeIn();
};

