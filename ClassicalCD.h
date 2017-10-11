#pragma once
#include "CD.h"
class ClassicalCD: public CD
{

public:
	//-------------------------------Default Constructor-----------------------
	// Creates a new ClassicalCD object
	ClassicalCD();

	//------------------------------- Constructor-----------------------------
	// Creates a new ClassicalCD object with the composer's name
	ClassicalCD (string );

	//------------------------------- setComposer ----------------------------
	// Sets ClassicalCD's composer
	void setComposer(string );

	//------------------------------- getComposer ----------------------------
	// returns ClassicalCD's composer's name
	string getComposer() const;

	////------------------------------- setQuantity ----------------------------
	//// Sets quantity
	//virtual void setQuantity( int );
	virtual void print(ostream& ) const;
	////------------------------------- getQuantity ----------------------------
	//// returns quantity
	//virtual int getQuantity() const;

	////------------------------------- setType -------------------------------
	//// Sets type
	//virtual void setType( char );

	////------------------------------- getType -------------------------------
	//// returns type
	//virtual int getType() const;

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
	// Creates a new ClassicalCD object from the file input
	virtual Item * create (ifstream &);

	//-------------------------------Destructor ------------------------------
	// Destructs a ClassicalCD object
	virtual ~ClassicalCD();

private:
	string composer;
};

