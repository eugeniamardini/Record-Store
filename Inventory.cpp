//----------------------------------------------------------------------------
// Inventory.cpp
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

#include "Inventory.h"
#include "Store.h"
#include "Item.h"
using namespace std;

//-------------------------------Default Constructor-----------------------
// Creates a new Inventory object
// Pre: none
// Post: new inventory object gest properly initialized to default values
Inventory::Inventory()
{
	for (int i = 0; i < MAX_LETTERS; i++)
	{
		inventory[i] = new BSTree();
		inventory[i]->displayCount(true);
	}
}

//------------------------------  remove  ---------------------------------
// Removes an Item from the Inventory
bool Inventory::remove (const Item & item , int quantity)
{
	 return inventory[static_cast<int>(item.getType()) - A]->remove(item, quantity);
}

//------------------------------  add  ---------------------------------
// Adds an Item to the Inventory
bool Inventory::add (Item * item, int quantity)
{
	return inventory[static_cast<int>(item->getType()) - A]->insert(item, quantity);
}

//------------------------------- display - ------------------------------
// displays an inventory of an item type at a specific index in the hash 
// table
void Inventory::display(char ch) const
{
	cout << *inventory[ch];
}

//-------------------------------Destructor ------------------------------
// Destructs an Inventory object
Inventory::~Inventory()
{
	for (int i = 0; i < MAX_LETTERS; i++)
	{
		 delete inventory[i];
			inventory[i] = NULL;
	}
}
