#include "Item.h"
#include "Disc.h"
#include "TreeData.h"
#include "Inventory.h"

using namespace std;

//-------------------------------Default Constructor-----------------------
// Creates a new Item object
   Item::Item(){} 

//------------------------------- Constructor-----------------------------
// Creates a new Item object with the quantity and type
Item::Item ( char ch)
{
	this->type = ch;	
}

//------------------------------- setType -------------------------------
// Sets Item's type
void Item::setType(char ch ) 
{
	this->type = ch;
}

//------------------------------- getType -------------------------------
// returns Item's type
char Item::getType() const 
{
	return this->type;
}


//-------------------------------Destructor ------------------------------
// Destructs an Item object
Item::~Item(){}