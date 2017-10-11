//----------------------------------------------------------------------------
// BSTree.h
// Author: Yauheniya Zapryvaryna CSS 343 Winter 2015 UWB
//----------------------------------------------------------------------------
// DESCRIPTION: Class BSTree implements a binary search tree by using a struct 
//			   Node, which has a pointer to a TreeData object.
// FUNCTIONALITY: 
//	--outputs the contents of a BSTree to the console 
//	--adds non-repeating TreeData objects (otherwise just increments quantity)
//	--checks whether a TreeData object is contained;
//	--removes an occurrence of a TreeData object
//	--deallocates its memory upon a makeEmpty command.
//-----------------------------------------------------------------------------

#pragma once
#include <iostream>
using namespace std;
class TreeData;
class BSTree
{
//-----------------------------  <<  ----------------------------------------
// Overloaded output operator for class BSTree
// Preconditions: root is not NULL and BSTree to be output is allocated
// in memory
// Postconditions: the displayHelper function is called upon this tree, 
// and the constents of the tree get output to to console in the inorder
// manner. 
friend ostream& operator<<(ostream & , const BSTree &);
public:
	//-------------------------------Default Constructor-----------------------
	// Creates a new BSTree object
	// Preconditions:none
	// Postconditions: a new BSTree object is created with root set to NULL
	BSTree();

	//-------------------------------- insert --------------------------------
	// Inserts a Node with a TreeData object's value into this BSTree
	// Preconditions: TreeData object key has been allocated in memory
	// Postconditions: insertHelper function is called and true is returned if key
	// is inserted, and false gets returned if key is found in this BSTree (thus,
	// not inserted). if key is inserted for the first time, its count becomes 1, 
	// else its count gets incremented by 1.
	bool insert(TreeData * , int );

	//------------------------------  remove  ---------------------------------
	// Removes a TreeData object from the BST. 
	// Preconditions: key is a valid TreeData object and the tree may have a 
	// pointer to this TreeData object to remove
	// Postconditions: removeHelper is called; if count is greater than one, 
	// quantity is decremented and true is returned. If count is 1, the item is
	// removed from the tree and true is returned. Otherwise, false is returned
	bool remove(const TreeData &, int);

	//--------------------------------makeEmpty--------------------------------
	// Empties the BSTree
	// Preconditions: none
	// Postconditions: the helper function is called, and the tree's memory is 
	// deallocated
	void makeEmpty();

	//------------------------------displayCount ------------------------------
	// Sets a boolean displayCountForTreeData to a value true or false
	// Preconditions: none
	// Postconditions: this BSTree will have a means (boolean) to "know"
	// whether to display quantity for treeData object
	void displayCount (bool );

	//--------------------------------isEmpty----------------------------------
	// Checks whether the BSTree is empty
	// Preconditions: the BSTree has a root with allocated memory 
	// Postconditions: true is returned if BSTree is empty, false otherwise.
	bool isEmpty() const;

	//---------------------------- Destructor ---------------------------------
	// Destructor for class BSTree; deallocates the used memory appropriately
	// Preconditions: none
	// Postconditions: BSTree is destructed, memory occupied previously by the 
	// tree is deallocated
	virtual ~BSTree();

private:
	struct Node {
		TreeData *data;  //pointer to TreeData object
		Node *right;
		Node *left;
		int quantity;
	};
	Node *root;
	bool displayCountForTreeData;
	
	//-------------------------------- insertHelper ---------------------------
	// Inserts a pointer to a TreeData object into the BSTree or increments the 
	// quantity if the data is found in the tree. 
	// Preconditions: TreeData object key has been allocated in memory
	// Postconditions: true is returned if key is inserted, and false gets
	// returned if key is found in this BSTree (thus, not inserted). if key is 
	// inserted for the first time, its count becomes 1, else its count gets
	// incremented by 1.
	bool insertHelper(Node *& , TreeData * , int );

	//------------------------------  removeHelper  ---------------------------
	// Removes one occurrence of a TreeData object from the BST. 
	// Preconditions: the tree may have a pointer to a TreeData object to remove
	// Postconditions: removeHelper is called; if count is greater than one, 
	// count is decremented and true is returned. If count is 1, the item is 
	// removed from the tree and true is returned. Otherwise, false is returned
	bool removeHelper(Node *& , const TreeData & , int );

	//------------------------------  removeRoot  -----------------------------
	// Removes a node with the last occurrence of a TreeData from the BST. 
	// Preconditions: root is not NULL; the tree has this pointer to a TreeData 
	// object and it is its last occurrence
	// Postconditions: the node with the key is removed, and the new root
	// is assigned to the value returned by findAndDeleteSmallest()
	void removeRoot(Node *&);

	//------------------------------  findAndDeleteSmallest  ------------------
	// Finds the node with the smallest TreeData value
	// Preconditions: root is not NULL
	// Postconditions: the smallest value in the subtree is returned and node
	// is deleted
	TreeData * findAndDeleteSmallest(Node *& , int &);

	//--------------------------------makeEmptyHelper--------------------------
	// Clears the tree's contents, deleting the TreeData objects themselves
	// Preconditions: none
	// Postconditions: the tree's memory is deallocated
	void makeEmptyHelper(Node *&);

	//-----------------------------  displayhelper  ---------------------------
	// Outputs the contents of the BSTree to the console 
	// Preconditions: root is not NULL
	// Postconditions: the constents of the tree get output to to console in
	// the inorder traversing manner. 
	ostream& displayHelper(ostream &, const BSTree &, Node *) const;

	
};


