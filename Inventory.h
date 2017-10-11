//----------------------------------------------------------------------------
// Inventory.h
// Author: Yauheniya Zapryvaryna CSS 343 Winter 2015 UWB
//----------------------------------------------------------------------------
// DESCRIPTION: Class Inventory implements a store's inventory object by using 
//				a hash table of pointers to BSTree objects
// FUNCTIONALITY: 
//	--outputs the inventory of a specific type of item to the console 
//	--inserts a pointer to a Item object into a inventory
//	--removes an Item object from  the inventory
//	--deallocates the transaction history vector memory.
//-----------------------------------------------------------------------------

#pragma once
#include "Item.h"
class BSTree;
class Inventory
{

public:
	//-------------------------------Default Constructor-----------------------
	// Creates a new Inventory object
	// Pre: none
	// Post: new inventory object gest properly initialized to default values
	Inventory();

	//------------------------------  remove  ---------------------------------
	// Removes an Item from the Inventory
	bool remove (const Item &, int );

	//------------------------------  add  ---------------------------------
	// Adds an Item to the Inventory
	bool add (Item * , int );

	//------------------------------- display - ------------------------------
	// displays an inventory of an item type at a specific index in the hash 
	// table
	void display(char ) const;

	//-------------------------------Destructor ------------------------------
	// Destructs an Inventory object
	~Inventory();

private:
	BSTree * inventory [26];       //hash table of all Items in Inventory
};

