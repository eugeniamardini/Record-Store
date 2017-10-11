#pragma once
#include "Disc.h"
class DVD: public Disc
{

public:

	//-------------------------------Default Constructor-----------------------
	// Creates a new DVD object
	DVD();

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

	//------------------------------ create -----------------------------------
	// Creates a new DVD object from the file input
	virtual Item * create (ifstream &);

	//-------------------------------Destructor ------------------------------
	// Destructs a DVD object
	virtual ~DVD();

private:
};

