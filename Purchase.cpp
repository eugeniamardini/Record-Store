//----------------------------------------------------------------------------
// Purchase.cpp
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

#include "Purchase.h"
#include "Store.h"
#include "Barter.h"
#include <fstream>
#include <string>
using namespace std;

//-------------------------------Default Constructor-----------------------
// Creates a new Purchase Transaction object
// Pre: none
// Post: a new Purchase transaction object is created
Purchase::Purchase()
{
}

//------------------------------- Constructor-----------------------------
// Creates a new Purchase Transaction object with the ID of a customer,
// and Item pointer
// Pre: none
// Post: a Purchase transaction object is created and its ID and Item * get
// initialized to given customerID and poiner to an Item object.
Purchase::Purchase (int ID, Item *obj)
{
	this->setID(ID);
	this->setItem(obj);
}


//---------------------------------- print -------------------------------
// Prints the transaction on the console
// Pre: transaction object this has been allocated in memory
// Post: the transaction gets printed on the console
 void Purchase::print (ostream &output) const
 {
	 output << type << ", " << *item ;
 }

//------------------------------ perform ---------------------------------
// Performs a purchase transaction on myStore according to its specs
// Pre: transaction object this has been allocated in memory. myStore is a 
// valid Store object and has been allocated in memory.
// Post: a transaction is performed according to its specs: item is removed
// from myStore's inventory and this Purchase transaction is added to the 
// customer's transaction history; deleteT is changed to indicate whether the
//  transaction needs to be deleted.
bool Purchase::perform(Store *myStore, bool &deleteT) 
{
	bool success = myStore->remove(*this->getItem(), 1);
	if (success )
	{
		//if item was available in the store, insert into customer's history
		myStore->getCustomerAt(this->customerID)->insertTransaction(this);
	}
	deleteT = !success; // delete if not successful
	return success;  // return whether transaction was successful
}

//------------------------------ create -----------------------------------
// Creates a new Purchase Transaction from file input
// Pre: ifstream has data to read; myStore is a valid Store object which
// has been allocated in memeory.
// Post: a Purchase transaction is created using factory method
Transaction * Purchase::create(ifstream & line, Store * myStore)
{
	string s;
	getline(line, s, ',');
	int id = abs(atoi(s.c_str()));
	if (id >=0 && id < 1000)
	{
		char itemType;
		line.ignore(1);
		line.get(itemType);
		line.ignore(1);
		char ch = static_cast<int>(itemType) - A;
		Item * obj = myStore->getItemAt(ch); 
		if (obj != NULL) //is a valid Item
		{
			Item * item = obj->create(line);
			item->setType(itemType);
			if (item != NULL)
			{
				Purchase *p = new Purchase(id, item);
				return p;
			}
			else 
			{
				return NULL;
			}
		}
		else //not a valid item - skip to next line to read
		{
			line.ignore(1000, '\n');
			return NULL;
		}
	}
	else
	{
		cerr << "ERROR: Invalid ID!"<< endl;
		return NULL;
	}
}

//-------------------------------Destructor ------------------------------
// Destructs a Purchase Transaction object
// Pre: transaction object this has been allocated in memory
// Post: transaction object is appropriately deallocated
Purchase::~Purchase()
{
}
