//----------------------------------------------------------------------------
// Customer.h
// Author: Yauheniya Zapryvaryna CSS 343 Winter 2015 UWB
//----------------------------------------------------------------------------
// DESCRIPTION: Class Customer implements a customer object by using a string 
//				lastName, string firstname, vector of pointers to Transaction
//				objects, and an int ID.
// FUNCTIONALITY: 
//	--outputs the customer to the console in the order last name, first name,
//	  ID, transaction history in chronological order.
//	--changes customer's name, ID
//	--inserts a pointer to a Transaction object into a transaction history vector
//	--deallocates the transaction history vector memory.
//-----------------------------------------------------------------------------

#pragma once
#include "TreeData.h"
#include <queue>
using namespace std;
class Transaction;
class Customer: public TreeData
{

public:
	//-------------------------------Default Constructor-----------------------
	// Creates a new Costumer object
	//Pre: none
	// Post: a new Customer object is created
	Customer();

	//------------------------------- Constructor-----------------------------
	// Creates a new Costumer object with ID, last name, first name
	// Pre: none
	// Post: a new Customer object is created with give last and first names, ID 
	Customer(int , string , string );

	//------------------------------- getFirstName ----------------------------
	// returns this customer's first name
	// Pre: customer object is allocate in memeory
	// Post: this customer's first name gets returned
	string getFirstName() const;

	//------------------------------- getLastName ----------------------------
	// returns this customer's last name
	// Pre: customer object is allocated in memeory
	// Post: this customer's last name gets returned
	string getLastName() const;

	//------------------------------- setFirstName ----------------------------
	// Changes this customer's first name to a string in a parameter
	// Pre: customer object is allocated in memeory
	// Post: this customer's first name gets changed
	void setFirstName(string );

	
	//------------------------------- setLastName ----------------------------
	// Changes this customer's last name to a string in a parameter
	// Pre: customer object is allocated in memeory
	// Post: this customer's last name gets changed
	void setLastName(string );

	//----------------------------------- getID -------------------------------
	// returns this customer's ID
	// Pre: customer object is allocated in memeory
	// Post: this customer's ID gets returned
	int getID() const;

	//------------------------------- setLastName ----------------------------
	// Changes this customer's ID to an int in a parameter
	// Pre: customer object is allocated in memeory
	// Post: this customer's ID gets changed
	void setID(int  );

	//-----------------------------insertTransaction  -------------------------
	// Inserts a pointer to a Transaction object into this customer's transaction
	// history vector
	// Pre: customer object is allocated in memory; this customer has a vector of 
	// pointers to Transaction objects 
	// Post: a new Transaction is inserted into this customer's vector for 
	// transaction history 
	void insertTransaction(Transaction *);

	//------------------------------  <  --------------------------------------
	// Determine if this Customer object is smaller than the one passed in.
	// Preconditions: two Customer objects have valid last and first names,
	// and can be compared.
	// Postconditions: true is returned if this TreeData object's last Name
	// is smaller than of the one passed in as a parameter, and false if it is
	// bigger. If equal, the first names get compared
	virtual bool operator<(const TreeData & ) const;

	//------------------------------  >  --------------------------------------
	// Determine if this Customer object is bigger than the one passed in.
	// Preconditions: two Customer objects have valid last and first names,
	// and can be compared.
	// Postconditions: true is returned if this TreeData object's last Name
	// is bigger than of the one passed in as a parameter, and false if it is
	// smaller. If equal, the first names get compared
	virtual bool operator>(const TreeData &) const;

	//------------------------------  == --------------------------------------
	// Determine if this Customer object is equal to the one passed in.
	// Preconditions: two Customer objects have valid last and first names,
	// and can be compared.
	// Postconditions: true is returned if this TreeData object's last Name,
	// first name, and ID are equal to the one passed in as a parameter, and 
	//false if they are not. 
	virtual bool operator==(const TreeData &) const;

	//------------------------------  != --------------------------------------
	// Determine if this Customer object is not equal to the one passed in.
	// Preconditions: two Customer objects have valid last and first names,
	// and can be compared.
	// Postconditions: true is returned if this TreeData object's last Name,
	// first name, and ID are not equal to the one passed in as a parameter, and 
	//false if they are. 
	virtual bool operator!=(const TreeData &) const;

	//------------------------------- print ------------------------------------
	// Print out the customer object to the console
	// Pre: customer object has been allocated in memory
	// Post: this customer objects is printed to the console (last name, first 
	// name, ID, transaction history order)
	virtual void print (ostream &) const;

	//-------------------------------Destructor ------------------------------
	// Destructs a Costumer object
	// Pre: customer object has been allocated in memory
	// Post: customer object's and its vector's memory appropriately get
	// deallocated
	virtual ~Customer();

private:
	vector <Transaction*> transactions;   //queue to store Transaction history
	int ID;
	string lastName;
	string firstName;
};

