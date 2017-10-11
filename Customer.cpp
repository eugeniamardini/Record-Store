
//----------------------------------------------------------------------------
// Customer.cpp
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

#include "Transaction.h"
#include "Customer.h"
#include "TreeData.h"
#include <iomanip>
#include <string>
using namespace std;

//-------------------------------Default Constructor-----------------------
// Creates a new Costumer object
//Pre: none
// Post: a new Customer object is created
Customer::Customer()
{
}

//------------------------------- Constructor-----------------------------
// Creates a new Costumer object with ID, last name, first name
// Pre: none
// Post: a new Customer object is created with give last and first names, ID 
Customer::Customer(int ID, string lastN, string firstN)
{
	this->ID = ID;
	this->lastName = lastN;
	this->firstName = firstN;
}

//------------------------------- getFirstName ----------------------------
// returns this customer's first name
// Pre: customer object is allocate in memeory
// Post: this customer's first name gets returned
string Customer::getFirstName() const
{
	return this->firstName;
}

//------------------------------- getLastName ----------------------------
// returns this customer's last name
// Pre: customer object is allocated in memeory
// Post: this customer's last name gets returned
string Customer::getLastName() const
{
	return this->lastName;
}

//------------------------------- setFirstName ----------------------------
// Changes this customer's first name to a string in a parameter
// Pre: customer object is allocated in memeory
// Post: this customer's first name gets changed
void Customer::setFirstName(string fn)
{
	this->firstName = fn;
}

//------------------------------- setLastName ----------------------------
// Changes this customer's last name to a string in a parameter
// Pre: customer object is allocated in memeory
// Post: this customer's last name gets changed
void Customer::setLastName(string ln)
{
	this->lastName = ln;
}

//----------------------------------- getID -------------------------------
// returns this customer's ID
// Pre: customer object is allocated in memeory
// Post: this customer's ID gets returned
int Customer::getID() const
{
	return this->ID;
}

//------------------------------- setLastName ----------------------------
// Changes this customer's ID to an int in a parameter
// Pre: customer object is allocated in memeory
// Post: this customer's ID gets changed
void Customer::setID(int  id)
{
	this->ID = id;
}

//-----------------------------insertTransaction  -------------------------
// Inserts a pointer to a Transaction object into this customer's transaction
// history vector
// Pre: customer object is allocated in memory; this customer has a vector of 
// pointers to Transaction objects 
// Post: a new Transaction is inserted into this customer's vector for 
// transaction history 
void Customer::insertTransaction(Transaction *t) 
{
	this->transactions.push_back(t);
}

//------------------------------  <  --------------------------------------
// Determine if this Customer object is smaller than the one passed in.
// Preconditions: two Customer objects have valid last and first names,
// and can be compared.
// Postconditions: true is returned if this TreeData object's last Name
// is smaller than of the one passed in as a parameter, and false if it is
// bigger. If equal, the first names get compared
bool Customer::operator<(const TreeData &otherCustomer ) const
{
	const Customer &c = static_cast<const Customer &>(otherCustomer);
	int lastVal = lastName.compare(c.lastName);
	if(lastVal < 0)
	{
		return true;
	}
	else if (lastVal == 0 && (firstName.compare(c.firstName) < 0))
	{
		return true;
	}
	else
	{
		return false;
	}
}

//------------------------------  >  --------------------------------------
// Determine if this Customer object is bigger than the one passed in.
// Preconditions: two Customer objects have valid last and first names,
// and can be compared.
// Postconditions: true is returned if this TreeData object's last Name
// is bigger than of the one passed in as a parameter, and false if it is
// smaller. If equal, the first names get compared
 bool Customer::operator>(const TreeData &otherCustomer) const
{
	const Customer &c = static_cast<const Customer &>(otherCustomer);
	return c < *this;
}

//------------------------------  == --------------------------------------
// Determine if this Customer object is equal to the one passed in.
// Preconditions: two Customer objects have valid last and first names,
// and can be compared.
// Postconditions: true is returned if this TreeData object's last Name,
// first name, and ID are equal to the one passed in as a parameter, and 
//false if they are not. 
 bool Customer::operator==(const TreeData &otherCustomer) const
{
	const Customer &c = static_cast<const Customer &>(otherCustomer);
	return ((lastName == c.lastName) && (firstName == c.firstName) 
		&& (ID== c.ID));
}

//------------------------------  != --------------------------------------
// Determine if this Customer object is not equal to the one passed in.
// Preconditions: two Customer objects have valid last and first names,
// and can be compared.
// Postconditions: true is returned if this TreeData object's last Name,
// first name, and ID are not equal to the one passed in as a parameter, and 
//false if they are. 
 bool Customer::operator!=(const TreeData &otherCustomer) const
{
	const Customer &c = static_cast<const Customer &>(otherCustomer);
	return !(*this == c);
}


//------------------------------- print ------------------------------------
// Print out the customer object to the console
// Pre: customer object has been allocated in memory
// Post: this customer objects is printed to the console (last name, first 
// name, ID, transaction history order)
void Customer::print(ostream& output) const
{
	output << this->lastName << ", " << this->firstName << ", ID# " << this->ID << endl;
	if ((int)transactions.size() == 0) //if no transaction history
	{
		cout << "No transactions to display." << endl;
	}
	for (int i = 0; i < (int) transactions.size(); i++)
	{
		cout << setw(4) << *transactions[i] << endl;
	}
}

//-------------------------------Destructor ------------------------------
// Destructs a Costumer object
// Pre: customer object has been allocated in memory
// Post: customer object's and its vector's memory appropriately get
// deallocated
Customer::~Customer()
{
	for (int i = 0; i < (int) transactions.size(); i ++)
	{
		delete transactions[i];
		transactions[i] = NULL;
	}
}
