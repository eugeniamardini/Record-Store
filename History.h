//----------------------------------------------------------------------------
// History.h
// Author: Yauheniya Zapryvaryna CSS 343 Winter 2015 UWB
//----------------------------------------------------------------------------
// DESCRIPTION:  Class History implements a transaction of type History, and
//				is a derived class of Transaction (inherits from Transaction)
//				
// FUNCTIONALITY: 
//	--changes (sets) transaction's customerID
//	--outputs the contents of a transaction to the console 
//	--performs a History transaction 
//-----------------------------------------------------------------------------

#pragma once
#include <fstream> 
using namespace std;

class History: public Transaction
{
public:

	//-------------------------------Default Constructor-----------------------
	// Creates a new History Transaction object
	// Pre: none
	// Post: a new History transaction object is created
	History();

	//------------------------------- Constructor-----------------------------
	// Creates a new History Transaction object with the ID of a customer
	// Pre: none
	// Post: a THistory transaction object is created and its ID gets
	// initialized to given customerID 
	History (int );


	//------------------------------- setID ---------------------------------
	// Sets History Transaction's customerID
	// Pre: transaction object this has been allocated in memory
	// Post: this transaction's ID gets changed to ID
	virtual void setID( int );

	//------------------------------- getID ---------------------------------
	// returns History Transaction's customerID
	// Pre: transaction object this has been allocated in memory
	// Post: transaction's customerID gets returned
	virtual int getID() const;

	//---------------------------------- print -------------------------------
	// Prints the transaction on the console
	// Pre: transaction object this has been allocated in memory
	// Post: the transaction gets printed to the console
	virtual void print (ostream &) const;

	//------------------------------ perform ---------------------------------
	// Performs a history transaction on myStore according to its specs
	// Pre: transaction object this has been allocated in memory. myStore is a 
	// valid Store object and has been allocated in memory.
	// Post: a transaction is performed according to its specs: the transaction 
	// history for the specified customer gets printed out; 
	// deleteT is changed to true indicate that transaction needs to be deleted
	// by Store class
	virtual bool perform( Store *, bool &);
	
	//------------------------------ create -----------------------------------
	// Creates a new History Transaction from file input
	// Pre: ifstream has data to read; myStore is a valid Store object which
	// has been allocated in memeory.
	// Post: a History transaction is created using factory method
	virtual Transaction * create(ifstream &, Store *);

	//-------------------------------Destructor ------------------------------
	// Destructs a History Transaction object
	// Pre: transaction object this has been allocated in memory
	// Post: transaction object is appropriately deallocated
	virtual ~History();

private:
	int customerID;
};

