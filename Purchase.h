//----------------------------------------------------------------------------
// Purchase.h
// Author: Yauheniya Zapryvaryna CSS 343 Winter 2015 UWB
//----------------------------------------------------------------------------
// DESCRIPTION:  Class Purchase implements a transaction of type Purchase, and
//				is a derived class of Barter
//				
// FUNCTIONALITY: 
//	--outputs the contents of a transaction to the console 
//	--performs a Purchase transaction 
//	--inserts a Purchase transaction into customer's history, if a item is 
//    available  for Purchase
//-----------------------------------------------------------------------------

#pragma once
#include "Transaction.h"
#include "Store.h"
#include "Barter.h"
#include <fstream> 
using namespace std;

class Purchase: public Barter
{
public:

	//-------------------------------Default Constructor-----------------------
	// Creates a new Purchase Transaction object
	// Pre: none
	// Post: a new Purchase transaction object is created
	Purchase();

	//------------------------------- Constructor-----------------------------
	// Creates a new Purchase Transaction object with the ID of a customer,
	// and Item pointer
	// Pre: none
	// Post: a Purchase transaction object is created and its ID and Item * get
	// initialized to given customerID and poiner to an Item object.
	Purchase (int , Item *);

	//---------------------------------- print -------------------------------
	// Prints the transaction on the console
	// Pre: transaction object this has been allocated in memory
	// Post: the transaction gets printed on the console
	virtual void print (ostream &) const;

	//------------------------------ perform ---------------------------------
	// Performs a purchase transaction on myStore according to its specs
	// Pre: transaction object this has been allocated in memory. myStore is a 
	// valid Store object and has been allocated in memory.
	// Post: a transaction is performed according to its specs: item is removed
	// from myStore's inventory and this Purchase transaction is added to the 
	// customer's transaction history; deleteT is changed to indicate whether the
	//  transaction needs to be deleted.
	virtual bool perform(Store *, bool &);

	//------------------------------ create -----------------------------------
	// Creates a new Purchase Transaction from file input
	// Pre: ifstream has data to read; myStore is a valid Store object which
	// has been allocated in memeory.
	// Post: a Purchase transaction is created using factory method
	virtual Transaction * create(ifstream & , Store * );

	//-------------------------------Destructor ------------------------------
	// Destructs a Purchase Transaction object
	// Pre: transaction object this has been allocated in memory
	// Post: transaction object is appropriately deallocated
	virtual~Purchase();
};

