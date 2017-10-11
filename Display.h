//----------------------------------------------------------------------------
// Display.h
// Author: Yauheniya Zapryvaryna CSS 343 Winter 2015 UWB
//----------------------------------------------------------------------------
// DESCRIPTION:  Class Display implements a transaction of type Display, and
//				is a derived class of Transaction (inherits from Transaction)
//				
// FUNCTIONALITY: 
//	--outputs the contents of a transaction to the console 
//	--performs a History transaction 
//-----------------------------------------------------------------------------

#pragma once
#include "Transaction.h"
#include <fstream> 
using namespace std;

class Display: public Transaction
{
public:
	//-------------------------------Default Constructor-----------------------
	// Creates a new Display Transaction object
	// Pre: none
	// Post: a new Display transaction object is created
	Display();

	//---------------------------------- print -------------------------------
	// Prints the transaction's type to the console
	// Pre: transaction object this has been allocated in memory
	// Post: the transaction gets printed to the console
	virtual void print (ostream &) const;

	//------------------------------ perform ---------------------------------
	// Performs a display transaction on myStore according to its specs
	// Pre: transaction object this has been allocated in memory. myStore is a 
	// valid Store object and has been allocated in memory.
	// Post: a transaction is performed according to its specs: the inventory 
	// of myStore (incl.quantity for items) gets printed out; 
	// deleteT is changed to true indicate that transaction needs to be deleted
	// by Store class
	virtual bool perform( Store * , bool &);

	//------------------------------ create -----------------------------------
	// Creates a new Display Transaction 
	// Pre: none
	// Post: a Display transaction is created by using factory method
	virtual Transaction * create(ifstream &, Store *);
	
	//-------------------------------Destructor ------------------------------
	// Destructs a Display Transaction object
	// Pre: transaction object this has been allocated in memory
	// Post: transaction object is appropriately deallocated
	virtual~Display();
};

