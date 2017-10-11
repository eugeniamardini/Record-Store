/** Manager.cpp */ 
#include "Store.h"
#include <string>
using namespace std;

/** DRIVER OF THE PROGRAM */
int main()
{
	Store myStore;;
	myStore.initializeInventory("HW4Inventory.txt");
	myStore.buildClientele("HW4Customers.txt");
	myStore.processTransactions("HW4Transactions.txt");
}