
//----------------------------------------------------------------------------
// HistoryAll.cpp
// Author: Yauheniya Zapryvaryna CSS 343 Winter 2015 UWB
//----------------------------------------------------------------------------
// DESCRIPTION:  Class HistoryAll implements a transaction of type HistoryAll, and
//				is a derived class of Transaction (inherits from Transaction)
//				
// FUNCTIONALITY: 
//	--outputs the contents of a transaction to the console 
//	--performs a History transaction 
//-----------------------------------------------------------------------------

#include "HistoryAll.h"
#include "Transaction.h"
#include "Store.h"
#include <fstream>
#include <string>
using namespace std;

//-------------------------------Default Constructor-----------------------
// Creates a new HistoryAll Transaction object
// Pre: none
// Post: a new HistoryAll transaction object is created
HistoryAll::HistoryAll()
{
}

//---------------------------------- print -------------------------------
// Prints the transaction's type to the console
// Pre: transaction object this has been allocated in memory
// Post: the transaction gets printed to the console
 void HistoryAll::print(ostream &output) const
{
	output << type;
}

//------------------------------ perform ---------------------------------
// Performs a HistoryAll transaction on myStore according to its specs
// Pre: transaction object this has been allocated in memory. myStore is a 
// valid Store object and has been allocated in memory.
// Post: a transaction is performed according to its specs: the history for 
// every customer of myStore (incl. item) gets printed out; 
// deleteT is changed to true indicate that transaction needs to be deleted
// by Store class
bool HistoryAll::perform(Store *myStore, bool &deleteT)
{
	deleteT = true;
	cout << "ALL TRANSACTION HISTORY BY CUSTOMER "<< endl;
	cout << myStore->getCustomers();
	return deleteT;
}

//------------------------------ create -----------------------------------
// Creates a new HistoryAll Transaction 
// Pre: none
// Post: a HistoryAll transaction is created by using factory method
Transaction * HistoryAll::create(ifstream &line, Store *myStore)
{
	HistoryAll *ha = new HistoryAll();
	return ha;
}

//-------------------------------Destructor ------------------------------
// Destructs a HistoryAll Transaction object
// Pre: transaction object this has been allocated in memory
// Post: transaction object is appropriately deallocated
HistoryAll::~HistoryAll()
{
}

