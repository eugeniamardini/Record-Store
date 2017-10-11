#pragma once

#include "TreeData.h"


#include <fstream>
using namespace std;
class Item: public TreeData
{
public:

	//-------------------------------Default Constructor-----------------------
	// Creates a new Item object
	Item();

	//------------------------------- Constructor-----------------------------
	// Creates a new Item object with the quantity and type
	Item (char);

	////------------------------------- setQuantity ----------------------------
	//// Sets Item's quantity
	//virtual void setQuantity( int );

	////------------------------------- getQuantity ----------------------------
	//// returns Item's quantity
	//virtual int getQuantity() const;

	//------------------------------- setType -------------------------------
	// Sets Item's type
	virtual void setType( char );

	//------------------------------- getType -------------------------------
	// returns Item's type
	virtual char getType() const;

	//------------------------------ create -----------------------------------
	// Creates a new Item from file input
	virtual Item * create(ifstream &) = 0;


	//-------------------------------Destructor ------------------------------
	// Destructs an Item object
	virtual  ~Item();

protected:
	char type;
};

