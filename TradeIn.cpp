//----------------------------------------------------------------------------
// TradeIn.cpp
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

#include "TradeIn.h"
#include "Store.h"
#include "Barter.h"
#include <fstream>
#include <string>
using namespace std;

//-------------------------------Default Constructor-----------------------
// Creates a new TradeIn Transaction object
// Pre: none
// Post: a new TradeIn transaction object is created
TradeIn::TradeIn()
{
}

//------------------------------- Constructor-----------------------------
// Creates a new TradeIn Transaction object with the ID of a customer,
// and Item pointer
// Pre: none
// Post: a TradeIn transaction object is created and its ID and Item * get
// initialized to given customerID and poiner to an Item object.
TradeIn::TradeIn (int ID, Item *obj)
{
	this->setID(ID);
	this->setItem(obj);
}

//---------------------------------- print -------------------------------
// Prints the transaction on the console
// Pre: transaction object this has been allocated in memory
// Post: the transaction gets printed on the console
 void TradeIn::print (ostream &output) const
 {
	 output << type << ", " << *item;
 }

//------------------------------ perform ---------------------------------
// Performs a trade-in transaction on myStore according to its specs
// Pre: transaction object this has been allocated in memory. myStore is a 
// valid Store object and has been allocated in memory.
// Post: a transaction is performed according to its specs: item is added
// to myStore's inventory and this TradeIn transaction is added to the 
// customer's transaction history; deleteT is changed to indicate whether the
// transaction needs to be deleted.
bool TradeIn::perform(Store *myStore, bool &deleteT)
{
	bool success = myStore->add(this->getItem(), 1);
	myStore->getCustomerAt(this->customerID)->insertTransaction(this);
	if (success == true) //new item was inserted
	{
		deleteT = false; //customer will dealloc memory
	}
	return success;
}

//------------------------------ create -----------------------------------
// Creates a new TradeIn Transaction from file input
// Pre: ifstream has data to read; myStore is a valid Store object which
// has been allocated in memeory.
// Post: a TradeIn transaction is created using factory method
Transaction * TradeIn::create(ifstream &line, Store *myStore)
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
		if (obj != NULL) // valid transaction 
		{
			Item * item = obj->create(line);
			item->setType(itemType);
			if (item != NULL)
			{
				TradeIn *ti = new TradeIn(id, item);
				return ti;
			}
			else
			{
				return NULL;
			}
		}
		else
		{
			//skip to next line, if transaction is invalid
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
// Destructs a TradeIn Transaction object
// Pre: transaction object this has been allocated in memory
// Post: transaction object is appropriately deallocated
TradeIn::~TradeIn(){}

