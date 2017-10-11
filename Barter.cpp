//----------------------------------------------------------------------------
// Barter.cpp
// Author: Yauheniya Zapryvaryna CSS 343 Winter 2015 UWB
//----------------------------------------------------------------------------
// DESCRIPTION: Class Barter implements a transaction object by 
//				using a character to define its type
//				
// FUNCTIONALITY: 
//	--changes (sets) type of transaction
//	--changes (sets) transaction's pointer to an Item object
//-----------------------------------------------------------------------------

#include "Transaction.h"
#include "Barter.h"
using namespace std;

//-------------------------------Default Constructor-----------------------
// Creates a new  Barter Transaction object
// Pre: none
// Post: a new Barter transaction object is created
Barter::Barter()
{
}


//------------------------------- Constructor-----------------------------
// Creates a new barter Transaction object with given customerID and poiner
// to an Item object
// Pre: none
// Post: a Barter transaction object is created and its ID and Item * get
// initialized to given customerID and poiner to an Item object.
Barter::Barter (int ID, Item *obj)
{
	this->customerID = ID;
	this->item = obj;
}


//------------------------------- setID ---------------------------------
// Sets barter Transaction's customerID
// Pre: transaction object this has been allocated in memory
// Post: this transaction's ID gets changed to ID
void Barter::setID(int ID)
{
	this->customerID = ID;
}

//------------------------------- getID ---------------------------------
// returns Purchase Transaction's customerID
// Pre: transaction object this has been allocated in memory
// Post: transaction's customerID gets returned
int Barter::getID() const
{
	return this->customerID;
}

//------------------------------- setItem ---------------------------------
// Sets Purchase Transaction's Item pointer
// Pre: transaction object this has been allocated in memory
// Post: transaction's pointer to an Item object gets changed
void Barter::setItem(Item * obj)
{
	this->item = obj;
}

//------------------------------- getItem ---------------------------------
// returns barter Transaction's pointer to an Item
// Pre: transaction object this has been allocated in memory
// Post: this transaction's item pointer gets returned 
Item * Barter::getItem() const
{
	return this->item;
}

//-------------------------------Destructor ------------------------------
// Destructs a Barter Transaction object
// Pre: transaction object this has been allocated in memory
// Post: transaction object is appropriately deallocated
Barter::~Barter(){}

