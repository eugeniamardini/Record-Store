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

#include "BSTree.h"
#include "TreeData.h"
#include "Store.h"
#include <iomanip>
using namespace std;

//-------------------------------Default Constructor-----------------------
// Creates a new BSTree object
// Preconditions:none
// Postconditions: a new BSTree object is created with root set to NULL
BSTree::BSTree()
{
	root = NULL;
}

void BSTree::displayCount(bool display) 
{
	this->displayCountForTreeData = display;
}

//-------------------------------- insert --------------------------------
// Inserts a Node with a TreeData object's value into this BSTree
// Preconditions: TreeData object key has been allocated in memory
// Postconditions: insertHelper function is called and true is returned if key
// is inserted, and false gets returned if key is found in this BSTree (thus,
// not inserted). if key is inserted for the first time, its count becomes 1, 
// else its count gets incremented by 1.
bool BSTree::insert(TreeData *key, int quantity)
{
	bool inserted;
	if (key != NULL)
	{
		inserted = insertHelper(root, key, quantity);
	}
	else
	{
		inserted = false;
	}
	return inserted;
}

//-------------------------------- insertHelper ---------------------------
// Inserts a pointer to a TreeData object into the BSTree or increments the 
// quantity if the data is found in the tree. 
// Preconditions: TreeData object key has been allocated in memory
// Postconditions: true is returned if key is inserted, and false gets
// returned if key is found in this BSTree (thus, not inserted). if key is 
// inserted for the first time, its count becomes 1, else its count gets
// incremented by 1.
bool BSTree::insertHelper (Node *&root, TreeData *key, int quantity)
{
	bool inserted;
	if (root == NULL)
	{
		root = new Node;
		root->data = key;
		root->quantity = quantity;
		root->left = root->right = NULL;
		return true;
	}
	else
	{
		if (*key < *root->data)
		{
			inserted = insertHelper(root->left, key, quantity);
		}
		else if (*key > *root->data)
		{
			inserted =  insertHelper(root->right, key, quantity);
		}
		else
		{
			root->quantity += quantity;
			inserted = false;
		}
	}
	return inserted;
}

//------------------------------  remove  ---------------------------------
// Removes a TreeData object from the BST. 
// Preconditions: key is a valid TreeData object and the tree may have a 
// pointer to this TreeData object to remove
// Postconditions: removeHelper is called; if count is greater than one, 
// quantity is decremented and true is returned. If count is 1, the item is
// removed from the tree and true is returned. Otherwise, false is returned
bool BSTree::remove(const TreeData &key, int quantity)
{
	return removeHelper(root, key, quantity);
}

//------------------------------  removeHelper  ---------------------------
// Removes one occurrence of a TreeData object from the BST. 
// Preconditions: the tree may have a pointer to a TreeData object to remove
// Postconditions: removeHelper is called; if count is greater than one, 
// count is decremented and true is returned. If count is 1, the item is 
// removed from the tree and true is returned. Otherwise, false is returned
bool BSTree::removeHelper(Node * &root, const TreeData &key, int quantity)
{
	bool removed;
	if(root == NULL)
	{
		removed = false;
	}
	else if (*root->data == key)
	{
		if (root->quantity == 1)
		{
			removeRoot(root);
			removed = true;
		}
		else 
		{
			root->quantity -= quantity;
			removed = true;
		}
	}
	else if (key < *root->data)
	{
		removed = removeHelper(root->left, key, quantity);
	}
	else
	{
		removed = removeHelper(root->right, key, quantity);
	}
	return removed;
}

//------------------------------  removeRoot  -----------------------------
// Removes a node with the last occurrence of a TreeData from the BST. 
// Preconditions: root is not NULL; the tree has this pointer to a TreeData 
// object and it is its last occurrence
// Postconditions: the node with the key is removed, and the new root
// is assigned to the value returned by findAndDeleteSmallest()
void BSTree::removeRoot(Node *&root)
{
	if (root->left == NULL && root->right == NULL)
	{
		delete root->data;
		delete root;
		root = NULL;
	}
	else if (root->left == NULL)
	{
		Node *temp = root;
		root = root->right;
		delete temp->data;
		delete temp;
	}
	else if (root->right == NULL)
	{
		Node *temp = root;
		root = root->left;
		delete temp->data;
		delete temp;
	}
	else
	{
		delete root->data;
		int count = 0;
		root->data = findAndDeleteSmallest(root->right, count);
	    root->quantity = count;
	}
}

//------------------------------  findAndDeleteSmallest  ----------------------
// Finds the node with the smallest TreeData value
// Preconditions: root is not NULL
// Postconditions: the smallest value in the subtree is returned and node is
// deleted
TreeData * BSTree::findAndDeleteSmallest(Node *&root, int &count)
{
	if (root->left == NULL)
	{
		TreeData *key = root->data;
		count = root->quantity;
		Node *temp = root;
		root = root->right;
		delete temp;
		return key;
	}
	else
	{
		return findAndDeleteSmallest(root->left, count);
	}
}

//-----------------------------  <<  ----------------------------------------
// Overloaded output operator for class BSTree
// Preconditions: root is not NULL and b (BSTree) is allocated in memory
// Postconditions: the displayHelper function is called upon this tree, 
// and the constents of the tree get output to to console in the inorder
// manner. 
ostream& operator<<(ostream& output, const BSTree &b)
{
	return b.displayHelper(output, b, b.root);
}

//-----------------------------  displayhelper  -------------------------------
// Outputs the contents of the BSTree to the console
// Preconditions: root is not NULL
// Postconditions: the constents of the tree get output to to console in the 
// inorder traversing manner. 
ostream& BSTree::displayHelper(ostream& output, const BSTree &b, Node *root) const
{
	if (root != NULL)
	{
		displayHelper(output, b, root->left);
		if (this->displayCountForTreeData == true)
		{
			output << setw(4) <<  *root->data << ", " << root->quantity << endl;
		}
		else
		{
			output << setw(4) <<  *root->data << endl;
		}
		displayHelper(output, b, root->right);
	}
	return output;
}


//--------------------------------makeEmpty--------------------------------
// Empties the BSTree
// Preconditions: none
// Postconditions: the helper function is called, and the tree's memory is 
// deallocated
void BSTree::makeEmpty()
{
	makeEmptyHelper(root);
}

//--------------------------------makeEmptyHelper------------------------------
// Clears the tree's contents, deleting the TreeData objects themselves
// Preconditions: none
// Postconditions: the tree's memory is deallocated
void BSTree::makeEmptyHelper(Node * &root)
{
	if (root != NULL)
	{
		makeEmptyHelper(root->left);
		makeEmptyHelper(root->right);
		delete root->data;
		delete root;
		root = NULL;
	}
}

//--------------------------------isEmpty----------------------------------
// Checks whether the BSTree is empty
// Preconditions: the BSTree has a root with allocated memory 
// Postconditions: true is returned if BSTree is empty, false otherwise.
bool BSTree::isEmpty() const
{
	return root == NULL;
}

//---------------------------- Destructor ---------------------------------
// Destructor for class BSTree; deallocates the used memory appropriately
// Preconditions: none
// Postconditions: BSTree is destructed, memory occupied previously by the 
// tree is deallocated
BSTree::~BSTree(){}