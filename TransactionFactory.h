/**
facilitates the creation of new transactions via input stream (commands file).

void createInventoryTransaction(string, vector<BST*> *, HashTable *)
void createBorrowTransaction(string, vector<BST*> *, HashTable *)
void createReturnTransaction(string, vector<BST*> *, HashTable *)
void createHistoryTransaction(string, vector<BST*> *, HashTable *)
void loadTransactionFile(ifstream &, vector<BST*> *, HashTable *)
**/
#include "BST.h"
#include "HashTable.h"
#include <vector>
#include <string>
#include <fstream>
using namespace std;

class TransactionFactory
{
public:
	// print out what is left in the inventory (stock)
	void createInventoryTransaction(string, vector<BST*> *, HashTable *);
	
	// customer borrowing movie logic (edit stock and borrowed movies)
	void createBorrowTransaction(string, vector<BST*> *, HashTable *);
	
	// customer returning a movie logic
	void createReturnTransaction(string, vector<BST*> *, HashTable *);
	
	// print out customer movies that they have rented
	void createHistoryTransaction(string, vector<BST*> *, HashTable *);

	// creates transactions (from commands) for customers in HashTable and movies in vector form
	void loadTransactionFile(ifstream &, vector<BST*> *, HashTable *);
};
