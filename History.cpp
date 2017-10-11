//----------------------------------------------------------------------------
// History.cpp
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

#include "Transaction.h"
#include "History.h"
#include "Store.h"
#include <iostream>
#include <fstream>
#include <string>
using namespace std;

//-------------------------------Default Constructor-----------------------
// Creates a new History Transaction object
// Pre: none
// Post: a new History transaction object is created
History::History()
{
}

//------------------------------- Constructor-----------------------------
// Creates a new History Transaction object with the ID of a customer
// Pre: none
// Post: a History transaction object is created and its ID gets
// initialized to given customerID 
History::History(int ID)
{
	this->customerID = ID;
}

//------------------------------- setID ---------------------------------
// Sets History Transaction's customerID
// Pre: transaction object this has been allocated in memory
// Post: this transaction's ID gets changed to ID
void History::setID(int ID)
{
	this->customerID = ID;
}

//------------------------------- getID ---------------------------------
// returns History Transaction's customerID
// Pre: transaction object this has been allocated in memory
// Post: transaction's customerID gets returned
int History::getID() const
{
	return this->customerID;
}

//---------------------------------- print -------------------------------
// Prints the transaction on the console
// Pre: transaction object this has been allocated in memory
// Post: the transaction gets printed to the console
 void History::print (ostream &output) const
{
	output<< type;
}

//------------------------------ perform ---------------------------------
// Performs a history transaction on myStore according to its specs
// Pre: transaction object this has been allocated in memory. myStore is a 
// valid Store object and has been allocated in memory.
// Post: a transaction is performed according to its specs: the transaction 
// history for the specified customer gets printed out; 
// deleteT is changed to true indicate that transaction needs to be deleted
// by Store class
bool History::perform(Store *myStore, bool &deleteT)
{
	deleteT = true;	
	cout << "TRANSACTION HISTORY for ";
	cout << *myStore->getCustomerAt(this->customerID) << endl;
	return deleteT;
}

//------------------------------ create -----------------------------------
// Creates a new History Transaction from file input
// Pre: ifstream has data to read; myStore is a valid Store object which
// has been allocated in memeory.
// Post: a History transaction is created using factory method
Transaction * History::create(ifstream &line, Store *myStore)
{
	string s;
	getline(line, s, '\n');
	int ID = atoi(s.c_str());
	if (ID >= 0 && ID < 1000)
	{
		History *h;
		if (myStore->getCustomerAt(ID) != NULL) //valid customer ID
		{
			h = new History(ID);
		}
		else 
		{
			cerr << "ERROR: Invalid Customer ID!" << endl;
			h = NULL;
		}
		return h;
	}
	else //customerID is out of appropriate bounds (<0, > 999)
	{
		cerr << "ERROR: Invalid ID!"<< endl;
		return NULL;
	}
}

//-------------------------------Destructor ------------------------------
// Destructs a History Transaction object
// Pre: transaction object this has been allocated in memory
// Post: transaction object is appropriately deallocated
History::~History()
{
}
