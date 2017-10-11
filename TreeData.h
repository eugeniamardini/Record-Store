//----------------------------------------------------------------------------
// TreeData.h
// Author: Yauheniya Zapryvaryna CSS 343 Winter 2015 UWB
//----------------------------------------------------------------------------
// DESCRIPTION: Abstract Class TreeData implements an abstract data type held by BSTree's
//			   nodes.The TreeData is represented by the character data type.
// FUNCTIONALITY: 
//	--compares 2 TreeData objects among themselves
//	--outputs the TreeData object to the console;
// ASSUMPTIONS:
//-----------------------------------------------------------------------------

#pragma once
#include <iostream>
using namespace std;

class TreeData
{
//-----------------------------  <<  ----------------------------------------
// Overloaded output operator for class TreeData
// Preconditions: a TreeData  must be a valid object (Customer or Item)
// Postconditions: the TreeData's value is sent to the output
friend ostream& operator<<(ostream& , const TreeData &);

public:
	//-------------------------------Default Constructor-----------------------
	// Preconditions:none
	// Postconditions: a new TreeData object is created  
	TreeData();

	//---------------------------- print --------------------------------------
	// Prints a Treedata object 
	// Preconditions: a TreeData  must be a valid object (Customer or Item)
	// Postconditions: the TreeData's value is sent to the output
	virtual void print (ostream &) const = 0;

	//------------------------------  <  --------------------------------------
	// Determine if this TreeData object is smaller than the one passed in.
	// Preconditions: two TreeData objects are  of valid type (Customer or Item) 
	// and can be compared 
	// Postconditions: true is returned if this TreeData object is 
	// smaller than of the one passed in as a parameter, and false if it is
	// bigger.
	virtual bool operator<(const TreeData & ) const = 0;

	//------------------------------  >  --------------------------------------
	// Determine if this TreeData object is bigger than the one passed in.
	// Preconditions: two TreeData objects are of valid type (Customer or Item)
	// and can be compared 
	// Postconditions: true is returned if this TreeData object
	// is bigger than of the one passed in as a parameter, and false if it's 
	// otherwise.
	virtual  bool operator>(const TreeData & ) const =0;

	//------------------------------  ==  -------------------------------------
	// Determine if two TreeData objects are equal.
	// Preconditions: both TreeData objects are of valid type (Customer or Item)
	// and can be compared.
	// Postconditions:true is returned if the objects are the same, false 
	// otherwise.
	virtual bool operator==(const TreeData & ) const =0;

	//------------------------------  !=  -------------------------------------
	// Determine if two TreeData objects are not equal.
	// Preconditions: both TreeData objects are of valid type (Customer or Item)
	// and can be compared.
	// Postconditions:true is returned if the objects are not the same, false 
	// otherwise.
	 virtual  bool operator!=(const TreeData & ) const = 0;
	
	//---------------------------- Destructor ---------------------------------
	// Destructor for class TreeData
	// Preconditions: none
	// Postconditions: TreeData object is destructed appropriately
	virtual ~TreeData();
};

