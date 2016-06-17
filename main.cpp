/*
business logic and file input logic

facilitates the execution of customers, movies, and commands

movie logic
customer logic
commands logic
*/
#include "BST.h"
#include "Movie.h"
#include "Drama.h"
#include "Comedy.h"
#include "Classic.h"
#include "Customer.h"
#include "HashTable.h"
#include "TransactionFactory.h"
#include <vector>
#include <fstream>
#include <iostream>
using namespace std;

int main()
{
	// determines the size of the HashTable (should be at least twice the size needed)
	int maxNumCustomers = 40;

	BST dramaTree;
	BST comedyTree;
	BST classicTree;
	/*** movie logic ***/
	ifstream inFile("data4movies.txt");
	if (!inFile)
	{
		cout << "movies file could not be opened." << endl;
		return 1;
	}

	Movie *drama;
	Movie *comedy;
	Movie *classic;
	// read in all movies in the file and create a bst of movies
	while (!inFile.eof())
	{
		string line;
		char firstChar;
		inFile >> firstChar;
		// drama
		if (firstChar == 'D')
		{
			getline(inFile, line);
			drama = new Drama(line);
			drama->setType('D');
			dramaTree.insert(drama);
		}
		// comedy
		else if (firstChar == 'F')
		{
			getline(inFile, line);
			comedy = new Comedy(line);
			comedy->setType('F');
			comedyTree.insert(comedy);
		}
		// classic
		else if (firstChar == 'C')
		{
			getline(inFile, line);
			classic = new Classic(line);
			classic->setType('C');
			classicTree.insert(classic);
		}
		// otherwise movie type is invalid, throw error message
		else
		{
			cout << "Invalid characterLineID (FDC):	" << firstChar << endl << endl;
			getline(inFile, line);
		}
	}
	/*** customer logic ***/
	Customer *customer;
	
	ifstream customersFile("data4customers.txt");
	if (!customersFile)
	{
		cout << "customers file could not be opened" << endl;
		return 1;
	}
	// make a hash table to store customers, size of table will be ~ twice needed size
	HashTable *customersTable = new HashTable(maxNumCustomers);
	// get all customers and add to hash table
	while (!customersFile.eof())
	{
		string line;
		getline(customersFile, line);
		if (line[0] >= '0' && line[0] <= '9')
		{
			customer = new Customer(line);
			customersTable->set(customer->getID(), *customer);
		}
	}
	/*** commands logic ***/
	ifstream commandsFile("data4commands.txt");
	if (!commandsFile)
	{
		cout << "commands file could not be opened" << endl;
		return 1;
	}
	// create a vector pointer to all the movies in the bst
	vector<BST*> allMovies;
	allMovies.push_back(&dramaTree);
	allMovies.push_back(&comedyTree);
	allMovies.push_back(&classicTree);
	TransactionFactory transFactory;
	transFactory.loadTransactionFile(commandsFile, &allMovies, customersTable);
	// delete all pointers (delete because of new keyword)
	delete drama;
	delete comedy;
	delete classic;
	delete customer;
	return 0;
}