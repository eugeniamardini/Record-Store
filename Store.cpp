//----------------------------------------------------------------------------
// Store.cpp
// Author: Yauheniya Zapryvaryna CSS 343 Winter 2015 UWB
//----------------------------------------------------------------------------
// DESCRIPTION: Class Store implements a local record store  by using a variety
//				of data structures: Binary Search Tree and hash table of 
//				customers, dummy hash tables of Item and Transaction pointers to
//				properly create the instances of Item and Transaction classes.
//				
// FUNCTIONALITY: 
//	--processes transactions from a file
//	--reads customer list from a file and builds clientele 
//	--reads the Inventory list from file and stores the products in its 
//    inventory
//	--outputs the contents of the inventory to the console 
//	--adds items to inventory
//	--removes an item from inventory
//	--deallocates the memeory of all data structures used
//
//ASSUMPTIONS:
//-- all text files are formatted correctly
//-----------------------------------------------------------------------------

#include "Store.h"
#include "Transaction.h"
#include "Inventory.h"
#include "BSTree.h"
#include "ClassicalCD.h"
#include "RockCD.h"
#include "DVD.h"
#include "Purchase.h"
#include "TradeIn.h"
#include "HistoryAll.h"
#include "History.h"
#include "Display.h"
#include "Barter.h"
#include "Disc.h"
#include "CD.h"
#include <fstream>
#include <iostream>
#include <iomanip>
#include <string> 
using namespace std;

//-------------------------------Default Constructor---------------------------
// Preconditions: itemDummyTable, transactionDummyTable, customerHashT are
// declared as data members of this Store
// Postconditions: itemDummyTable, transactionDummyTable, customerHashT are
// initialized to default values; new instances of Item and Transsaction
// classes are created;
Store::Store()
{
	for (int i = 0; i < MAX_LETTERS; i++)
	{
		itemDummyTable[i] = NULL;
		transactionDummyTable[i] = NULL;
	}
	itemDummyTable[static_cast<int>('C') - A] = new ClassicalCD();
	itemDummyTable[static_cast<int>('R') - A] = new RockCD();
	itemDummyTable[static_cast<int>('D') - A] = new DVD();
	transactionDummyTable[static_cast<int>('P') - A] = new Purchase();
	transactionDummyTable[static_cast<int>('I') - A] = new Display();
	transactionDummyTable[static_cast<int>('H') - A] = new History();
	transactionDummyTable[static_cast<int>('A') - A] = new HistoryAll();
	transactionDummyTable[static_cast<int>('T') - A] = new TradeIn();
	for (int c = 0; c < MAX_CUSTOMERS; c++)
	{
		customersHashT[c] = NULL;
	}
	customers.displayCount(false);
} 

//------------------------------ initializeInventory ----------------------
// Initializes Inventory by reading data from text file
// Preconditions: the string file is proprely formatted
// Postconditions: an item is created using factory method; the item is then 
// added to inventory, if its quantity is positive.
void Store::initializeInventory(string file)
{
	ifstream infile(file);
	if (!infile) 
	{
		cerr << "File could not be opened." << endl;
		return;
	}
	char t;
	for(;;)
	{
		if (infile.eof()) 
			break;
		infile.get(t);
		if((char)t =='\n')
		{
			infile.ignore(1000, '\n'); //if line is empty - skip until next line
		}
		else
		{
			string q;
			infile.ignore(1);
			getline(infile, q, ',');
			int quantity = atoi(q.c_str());
			char ch = static_cast<int>(t) - A;
			Item * obj = itemDummyTable[ch];
			if (obj != NULL)  //if item is valid
			{
				//factory method called to instanciate an Item of appropriate type
				Item * item = obj->create(infile);  
				if (item != NULL)
				{
					item->setType(t);				   
					if (quantity > 0)
					{
						storeInventory.add(item, quantity);  //item added to inventory
					}
				}
				else
				{
					cerr << "ERROR: Invalid Item!" << endl;
				}
			}
			else 
			{
				infile.ignore(256, '\n'); //if item is not valid, skip to next line
			}
		}
	}
}

//-----------------------------processTransactions ------------------------
// Processes transactions by reading data from text file
// Preconditions: the string file is proprely formatted
// Postconditions: a transaction is created using factory method; the transaction
// is then performed.
void Store::processTransactions(string file)
{
	ifstream infile(file);
	if (!infile) 
	{
		cerr << "File could not be opened." << endl;
		return;
	}
	char t;
	for(;;)
	{
		if (infile.eof()) 
			break;
		infile.get(t); 
		if((char)t =='\n')
		{
			infile.ignore(1000, '\n'); //if line is empty - skip until next line
		}
		else
		{
			infile.ignore(1);
			char ch = static_cast<int>(t) - A;
			Transaction *trans = transactionDummyTable[ch];
			if (trans != NULL) //if transaction is valid
			{
				//factory method called to instanciate a transaction of appropriate type
 				Transaction * transaction = trans->create(infile, this);
				if (transaction != NULL)
				{
					transaction->setType(t);
					// to establish whether transaction needs to be deallocated by the Store 
					bool deleteT = false;      
					// transaction gets performed and deleteT changes its value, based on
					//whether it must be deallocated b yStore or Customer object that contains it
					bool success = transaction->perform(this, deleteT);
					if (deleteT)
					{
						delete transaction;
						transaction = NULL;
					}
				}
				else 
				{
					cerr << "ERROR: Invalid Transaction!" << endl;
				}
			}
			else 
			{
				infile.ignore(256, '\n'); //if transaction is invalid, skip to next line
			}
		}
	}
}

//-------------------------------buildClientele ---------------------------
// Initializes Customer List by reading data from text file
// Preconditions: the string file is proprely formatted
// Postconditions: a Customer is created and inserted into Store's BSTree
// for better sorting and a hast table for faster look up.
void Store::buildClientele(string file)
{
	ifstream infile(file);
	if (!infile) 
	{
		cerr << "File could not be opened." << endl;
		return;
	}
	for(;;)
	{
		if (infile.eof()) 
			break;
		string s;
		getline(infile, s, ',');
		if (s == "\n\n\n\n\n")
		{
			infile.ignore(1000, '\n'); //if line is empty, go to next
		}
		else
		{
			int ID = atoi(s.c_str());
			if (ID >= 0 && ID < MAX_CUSTOMERS)
			{
				getline(infile, s, ',');
				string lastN = s;
				getline(infile, s, '\n');
				string firstN= s;
				//ensures no customer with same ID "lives" there
				if (customersHashT[ID] == NULL) 
				{
					Customer * customer = new Customer(ID, lastN, firstN);
					customers.insert(customer, 1);
					customersHashT[ID] = customer;
				}
				else
				{
					cerr<<"ERROR: Invalid customer ID!"<< endl;
				}
			}
			else
			{
				cerr << "ERROR: Invalid ID!" << endl;
				//skip to next line if ID is out of allowed bounds
				infile.ignore(256, '\n'); 
			}
		}
	}
}

//---------------------------------- getItem ---------------------------------
// returns an Item pointer at specific location
 Item * Store::getItemAt(int index) const 
{
	return itemDummyTable[index];
}

//---------------------------------- getCustomerAt---------------------------
//retrns a Customer pointer at a specific index in hast table
Customer* Store::getCustomerAt(int ID) const
{
	return customersHashT[ID];
}

//-------------------------------- getCustomer ------------------------------
// returns a BSTree of customers that Store holds
BSTree Store::getCustomers() const
{
	return customers;
}

//------------------------------  remove  ------------------------------------
// Removes an item from inventory
// Preconditions: item is a valid Item object and the inventory may have a 
// pointer to this Item object to remove
// Postconditions: Inventory's remove is called; if item's occurrence is 
// removed successfully, true is returned. Otherwise, false is returned.
bool Store::remove(const Item & item, int q)
{
	return storeInventory.remove(item, q);
}

//----------------------------------- add ------------------------------------
// Inserts a pointer to Item object into inventory
// Preconditions: Item object item is a valid Item object and has been 
// allocated in memory
// Postconditions: Inventory's add function is called and true is returned if
// item is added, and false gets returned if item is found in inventory (thus,
// not inserted and its quantity only updated), or not found at all. 
bool Store::add( Item * item, int q)
{
	return storeInventory.add(item, q);
}

//-----------------------------------  display   -----------------------------
// Outputs the contents of the inventory to the console 
// Preconditions: inventory is not empty
// Postconditions: the constents of the inventory get output to to console 
void Store::display() const
{
	cout << "Rock CDs:" << endl;
	cout << setw(6); 
	storeInventory.display(static_cast<int>('R') - A);
	cout << endl;
	cout << "Classical CDs:" << endl;
	cout << setw(6); 
	storeInventory.display(static_cast<int>('C') - A);
	cout  << endl;
	cout << "DVDs:" << endl;
	cout << setw(6);
	storeInventory.display(static_cast<int>('D') - A);
	cout << endl;
}

//-------------------------------Destructor ------------------------------
// Destructs a Store object
// Preconditions: none
// Postconditions: data structures with dynamic memeory allocated and used 
// by Stre are destructed
Store::~Store()
{
	for (int i = 0; i < MAX_LETTERS; i++)
	{
		delete itemDummyTable[i];
		itemDummyTable[i] =  NULL;
		delete transactionDummyTable[i];
		transactionDummyTable[i] = NULL;
	}
	for (int c = 0; c < MAX_CUSTOMERS; c++)
	{
		delete customersHashT[c];
		customersHashT[c] = NULL;
	}
}
