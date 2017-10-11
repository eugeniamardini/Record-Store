//----------------------------------------------------------------------------
// HistoryAll.h
// Author: Yauheniya Zapryvaryna CSS 343 Winter 2015 UWB
//----------------------------------------------------------------------------
// DESCRIPTION:  Class HistoryAll implements a transaction of type HistoryAll, and
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

class HistoryAll: public Transaction
{
public:

	//-------------------------------Default Constructor-----------------------
	// Creates a new HistoryAll Transaction object
	// Pre: none
	// Post: a new HistoryAll transaction object is created
	HistoryAll();

	//---------------------------------- print -------------------------------
	// Prints the transaction's type to the console
	// Pre: transaction object this has been allocated in memory
	// Post: the transaction gets printed to the console
	virtual void print (ostream &) const;

	//------------------------------ perform ---------------------------------
	// Performs a HistoryAll transaction on myStore according to its specs
	// Pre: transaction object this has been allocated in memory. myStore is a 
	// valid Store object and has been allocated in memory.
	// Post: a transaction is performed according to its specs: the history for 
	// every customer of myStore (incl. item) gets printed out; 
	// deleteT is changed to true indicate that transaction needs to be deleted
	// by Store class
	virtual bool perform(Store *, bool &);

	//------------------------------ create -----------------------------------
	// Creates a new HistoryAll Transaction 
	// Pre: none
	// Post: a HistoryAll transaction is created by using factory method
	virtual Transaction * create(ifstream &, Store *);
	
	//-------------------------------Destructor ------------------------------
	// Destructs a HistoryAll Transaction object
	// Pre: transaction object this has been allocated in memory
	// Post: transaction object is appropriately deallocated
	virtual~HistoryAll();
};

