//----------------------------------------------------------------------------
// TreeData.h
//Author: Yauheniya Zapryvaryna CSS 343 Winter 2015 UWB
//----------------------------------------------------------------------------
// DESCRIPTION: Abstract Class TreeData implements an abstract data type held by BSTree's
//			   nodes.The TreeData can be represented by Customer or Item object.
// FUNCTIONALITY: 
//	--compares 2 TreeData objects among themselves
//	--outputs the TreeData object to the console;
// ASSUMPTIONS:
//-----------------------------------------------------------------------------

#include "BSTree.h"
#include "TreeData.h"
#include "Item.h"
#include "Customer.h"
#include <iostream>
using namespace std;

//-------------------------------Default Constructor---------------------------
// Preconditions:none
// Postconditions: a new TreeData object is created 
TreeData::TreeData()
{
}

//-----------------------------  <<  ----------------------------------------
// Overloaded output operator for class TreeData
// Preconditions: a TreeData must be a valid object (Customer or Item)
// Postconditions: the TreeData's value is sent to the output 
ostream & operator << (ostream & output, const TreeData &t)
{
	t.print(output);
	return output;
}

//---------------------------- Destructor -------------------------------------
// Destructor for class TreeData
// Preconditions: none
// Postconditions: TreeData object is destructed appropriately
TreeData::~TreeData()
{
}
