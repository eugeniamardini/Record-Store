#pragma once
#include "CD.h"
class RockCD: public CD
{

public:

	//-------------------------------Default Constructor-----------------------
	// Creates a new RockCD object
	RockCD();

	//------------------------------ create -----------------------------------
	// Creates a new RockCD object from the file input
	virtual Item * create (ifstream &);

	////------------------------------- setQuantity ----------------------------
	//// Sets quantity
	//virtual void setQuantity( int );

	////------------------------------- getQuantity ----------------------------
	//// returns quantity
	//virtual int getQuantity() const;

	////------------------------------- setType -------------------------------
	//// Sets type
	//virtual void setType(char );

	////------------------------------- getType -------------------------------
	//// returns type
	//virtual int getType() const;

	virtual void print(ostream& ) const;
			//------------------------------  <  --------------------------------------
	// Determine if this TreeData object is smaller than the one passed in.
	// Preconditions: two TreeData objects have a valid character value, and 
	// can be compared by ASCII decimal value
	// Postconditions: true is returned if this TreeData object's decimal value
	// is smaller than of the one passed in as a parameter, and false if it is
	// bigger.
	virtual bool operator<(const  TreeData & ) const;

	//------------------------------  >  --------------------------------------
	// Determine if this TreeData object is bigger than the one passed in.
	// Preconditions: two TreeData objects have a valid character value, and 
	// can be compared by ASCII decimal value
	// Postconditions: true is returned if this TreeData object's decimal value
	// is bigger than of the one passed in as a parameter, and false if it's 
	// otherwise.
	virtual bool operator>(const TreeData &) const;

	//------------------------------  ==  -------------------------------------
	// Determine if two TreeData objects are equal.
	// Preconditions: both TreeData objects have a valid character value ch and
	// can be compared by ASCII decimal value.
	// Postconditions:true is returned if the objects have the same character
	// value ch, false otherwise.
	virtual bool operator==(const TreeData &) const;

	//------------------------------  !=  -------------------------------------
	// Determine if two TreeData objects are not equal.
	// Preconditions: both TreeData objects have a valid character value ch and
	// can be compared by ASCII decimal value.
	// Postconditions:true is returned if the objects don't have the same 
	// character value ch, false otherwise.
	virtual bool operator!=(const TreeData &) const;

	//-------------------------------Destructor ------------------------------
	// Destructs a RockCD object
	virtual ~RockCD();
};

