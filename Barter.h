//----------------------------------------------------------------------------
// Barter.h
// Author: Yauheniya Zapryvaryna CSS 343 Winter 2015 UWB
//----------------------------------------------------------------------------
// DESCRIPTION:  Class Barter implements a transaction of type Purchase or 
//				TradeIn, thus being their Base class.
//				
// FUNCTIONALITY: 
//	--changes (sets) transaction's customerID
//	--changes (sets) transaction's pointer to an Item object
//-----------------------------------------------------------------------------

#pragma once
#include "Transaction.h"
class Item;

class Barter: public Transaction 
{
public:

	//-------------------------------Default Constructor-----------------------
	// Creates a new  Barter Transaction object
	// Pre: none
	// Post: a new Barter transaction object is created
	Barter();

	//------------------------------- Constructor-----------------------------
	// Creates a new barter Transaction object with given customerID and poiner
	// to an Item object
	// Pre: none
	// Post: a Barter transaction object is created and its ID and Item * get
	// initialized to given customerID and poiner to an Item object.
	Barter (int , Item *);

	//------------------------------- setID ---------------------------------
	// Sets barter Transaction's customerID
	// Pre: transaction object this has been allocated in memory
	// Post: this transaction's ID gets changed to ID
	virtual void setID(int );

	//------------------------------- getID ---------------------------------
	// returns Purchase Transaction's customerID
	// Pre: transaction object this has been allocated in memory
	// Post: transaction's customerID gets returned
	virtual int getID() const;

	//------------------------------- setItem ---------------------------------
	// Sets Purchase Transaction's Item pointer
	// Pre: transaction object this has been allocated in memory
	// Post: transaction's pointer to an Item object gets changed
	virtual void setItem(Item * );

	//------------------------------- getItem ---------------------------------
	// returns barter Transaction's pointer to an Item
	// Pre: transaction object this has been allocated in memory
	// Post: this transaction's item pointer gets returned 
	virtual Item * getItem() const;

	//-------------------------------Destructor ------------------------------
	// Destructs a Barter Transaction object
	// Pre: transaction object this has been allocated in memory
	// Post: transaction object is appropriately deallocated
	virtual ~Barter();

protected:
	Item * item;
	int customerID;
};

