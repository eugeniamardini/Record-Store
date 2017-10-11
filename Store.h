//----------------------------------------------------------------------------
// Store.h
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
//- -all text files are formatted correctly
//-----------------------------------------------------------------------------

#pragma once
#include "Customer.h"
#include "BSTree.h"
#include "Inventory.h"

static const int MAX_CUSTOMERS = 1000;
static const int MAX_LETTERS = 26;
static const int A = 65;
class Store
{
public:
	//-------------------------------Default Constructor-----------------------
	// Preconditions: itemDummyTable, transactionDummyTable, customerHashT are
	// declared as data members of this Store
	// Postconditions: itemDummyTable, transactionDummyTable, customerHashT are
	// initialized to default values; new instances of Item and Transsaction
	// classes are created;
	Store();

	//------------------------------ initializeInventory ----------------------
	// Initializes Inventory by reading data from text file
	// Preconditions: the string file is proprely formatted
	// Postconditions: an item is created using factory method; the item is then 
	// added to inventory, if its quantity is positive.
	void initializeInventory(string );

	//-----------------------------processTransactions ------------------------
	// Processes transactions by reading data from text file
	// Preconditions: the string file is proprely formatted
	// Postconditions: a transaction is created using factory method; the transaction
	// is then performed.
	void processTransactions(string );

	//-------------------------------buildClientele ---------------------------
	// Initializes Customer List by reading data from text file
	// Preconditions: the string file is proprely formatted
	// Postconditions: a Customer is created and inserted into Store's BSTree
	// for better sorting and a hast table for faster look up.
	void buildClientele(string );

	//------------------------------  remove  ------------------------------------
	// Removes an item from inventory
	// Preconditions: item is a valid Item object and the inventory may have a 
	// pointer to this Item object to remove
	// Postconditions: Inventory's remove is called; if item's occurrence is 
	// removed successfully, true is returned. Otherwise, false is returned.
	bool remove (const Item &, int );

	//----------------------------------- add ------------------------------------
	// Inserts a pointer to Item object into inventory
	// Preconditions: Item object item is a valid Item object and has been 
	// allocated in memory
	// Postconditions: Inventory's add function is called and true is returned if
	// item is added, and false gets returned if item is found in inventory (thus,
	// not inserted and its quantity only updated), or not found at all. 
	bool add (Item *, int );

	//-----------------------------------  display   -----------------------------
	// Outputs the contents of the inventory to the console 
	// Preconditions: inventory is not empty
	// Postconditions: the constents of the inventory get output to to console 
	void display() const;

	//---------------------------------- getItem ---------------------------------
	// returns an Item pointer at specific location
	Item * getItemAt(int ) const;

	//---------------------------------- getCustomerAt---------------------------
	//retrns a Customer pointer at a specific index in hast table
	Customer * getCustomerAt( int ) const;

	//-------------------------------- getCustomer ------------------------------
	// returns a BSTree of customers that Store holds
	BSTree getCustomers() const;


	//-------------------------------Destructor ------------------------------
	// Destructs a Store object
	// Preconditions: none
	// Postconditions: data structures with dynamic memeory allocated and used 
	// by Stre are destructed
	virtual ~Store();

private:
	BSTree customers;							//BSTree of store's customers
	Customer * customersHashT [MAX_CUSTOMERS];	//Hash Table of customers
	Inventory storeInventory;						//Inventory object of the store
	Item * itemDummyTable [MAX_LETTERS];					//Item Hash Factory
	Transaction * transactionDummyTable [MAX_LETTERS];	//Transaction Hash Factory 
};

