/*
loads input file of commands that create borrow, inventory, return, and history transactions.

void loadTransactionFile(ifstream &, vector<BST*> *, HashTable *)
void createBorrowTransaction(string, vector<BST*> *, HashTable *)
void createInventoryTransaction(string, vector<BST*> *, HashTable *)
void createReturnTransaction(string, vector<BST*> *, HashTable *)
void createHistoryTransaction(string, vector<BST*> *, HashTable *)
*/
#include "Drama.h"
#include "Comedy.h"
#include "Classic.h"
#include "TransactionFactory.h"
#include <sstream>
#include <iostream>

// load transactions commands file, creating transactions accordingly
void TransactionFactory::loadTransactionFile(ifstream &inFile, vector<BST*> *movies, HashTable *customers)
{
	// read commands file and create transactions (IHBR)
	while (!inFile.eof())
	{
		string line;
		char firstChar;
		inFile >> firstChar;
		// create inventory transaction
		if (firstChar == 'I')
		{
			getline(inFile, line);
			createInventoryTransaction(line, movies, customers);
		}
		// create history transaction
		else if (firstChar == 'H')
		{
			getline(inFile, line);
			createHistoryTransaction(line, movies, customers);
		}
		// create borrow (rental) transaction
		else if (firstChar == 'B')
		{
			getline(inFile, line);
			createBorrowTransaction(line, movies, customers);
		}
		// create return transaction
		else if (firstChar == 'R')
		{
			getline(inFile, line);
			createReturnTransaction(line, movies, customers);
		}
		// otherwise transaction char is invalid, throw error message
		else
		{
			cout << "Bad Transaction ID (RIBH) in loadTransactionFile" << endl;
			getline(inFile, line);
		}
	}
}

// create borrow transaction (customer renting a movie)
void TransactionFactory::createBorrowTransaction(string line, vector<BST*> *movies, HashTable *customers)
{
	cout << "Customer Rental " << endl;

	stringstream items;
	string item;
	Movie findMovie;
	int num;
	char character;

	items << line;

	items >> num;
	int customerID = num;

	items >> character;
	char mediaType = character;

	items >> character;
	char movieType = character;
	// drama transaction logic
	if (movieType == 'D')
	{
		// director
		getline(items, item, ',');
		if (item[0] == ' ')
			item.erase(item.begin());
		findMovie.setDirector(item);
		// title
		getline(items, item, ',');
		if (item[0] == ' ')
			item.erase(item.begin());
		findMovie.setTitle(item);
		// pointer to drama movies used to get vector from bst of dramas
		vector<Movie*> dramas;
		movies->at(0)->bstToVector(&dramas);
		// subtract stock of movie in inventory and add the movie to customer borrowed movies
		for (int i = 0; i < dramas.size(); i++)
		{
			if (findMovie.getDirector() == dramas.at(i)->getDirector() &&
				findMovie.getTitle() == dramas.at(i)->getTitle())
			{
				if (dramas.at(i)->getStock() > 0)
				{
					dramas.at(i)->setStock(dramas.at(i)->getStock() - 1);
					customers->get(customerID)->addMoviesBorrowed(*dramas.at(i));
				}
			}
		}
	}
	// comedy transaction logic
	else if (movieType == 'F')
	{
		// title
		getline(items, item, ',');
		if (item[0] == ' ')
			item.erase(item.begin());
		findMovie.setTitle(item);
		// year released
		items >> num;
		findMovie.setYearReleased(num);
		// comedies from the bst in vector form (pointer)
		vector<Movie*> comedies;
		movies->at(1)->bstToVector(&comedies);
		// subtract stock of movie in inventory and add the movie to customer borrowed movies
		for (int i = 0; i < comedies.size(); i++)
		{
			if (findMovie.getTitle() == comedies.at(i)->getTitle() &&
				findMovie.getYearReleased() == comedies.at(i)->getYearReleased())
			{
				if (comedies.at(i)->getStock() > 0)
				{
					comedies.at(i)->setStock(comedies.at(i)->getStock() - 1);
					customers->get(customerID)->addMoviesBorrowed(*comedies.at(i));
				}
			}
		}
	}
	// classic transaction logic
	else if (movieType == 'C')
	{
		items >> num;
		int monthReleased = num;

		items >> num;
		int yearReleased = num;
		// major actor (stored in item)
		getline(items, item);
		if (item[0] == ' ')
			item.erase(item.begin());
		// classic movie vector pointer
		vector<Movie*> classics;
		movies->at(2)->bstToVector(&classics);
		// temporary classic vector pointer for accessing classic's specific methods/ variables
		vector<Classic*> tempClassic;
		// subtract stock of movie in inventory and add the movie to customer borrowed movies
		for (int i = 0; i < classics.size(); i++)
		{
			// cast movie to classic for access of classic only variables and methods
			tempClassic.push_back(dynamic_cast <Classic *> (classics.at(i)));
			if (monthReleased == tempClassic.at(i)->getMonthReleased() && 
				yearReleased == tempClassic.at(i)->getYearReleased() && 
				item == tempClassic.at(i)->getMajorActor())
			{
				if (classics.at(i)->getStock() > 0)
				{
					classics.at(i)->setStock(classics.at(i)->getStock() - 1);
					customers->get(customerID)->addMoviesBorrowed(*classics.at(i));
				}
			}
		}
	}
	// not a movie type, throw error message
	else
	{
		cout << "Bad character line ID (FDC) in createBorrowTransaction" << endl << endl;
		return;
	}
	cout << endl;
}

// create inventory transaction (display all movies left in stock in order)
void TransactionFactory::createInventoryTransaction(string line, vector<BST*> *movies, HashTable *customers)
{
	cout << "Inventory " << endl;

	for (int i = 0; i < movies->size(); i++)
		cout << *movies->at(i);
}

// create return transaction (customer returning a movie)
void TransactionFactory::createReturnTransaction(string line, vector<BST*> *movies, HashTable *customers)
{
	cout << "Customer Return " << endl;

	stringstream items;
	string item;
	int num;
	char character;

	items << line;

	items >> num;
	int customerID = num;

	items >> character;
	char mediaType = character;

	items >> character;
	char movieType = character;

	Movie findMovie;
	// drama transaction logic
	if (movieType == 'D')
	{
		// director
		getline(items, item, ',');
		if (item[0] == ' ')
			item.erase(item.begin());
		findMovie.setDirector(item);
		// title
		getline(items, item, ',');
		if (item[0] == ' ')
			item.erase(item.begin());
		findMovie.setTitle(item);
		// pointer to customer's list of movies borrowed
		vector<Movie*> customerDramas;
		customers->get(customerID)->getMoviesBorrowed(&customerDramas);
		// pointer to list of comedies in inventory (main)
		vector<Movie*> dramas;
		movies->at(0)->bstToVector(&dramas);
		// remove the movie from the customers list of borrowed movies
		for (int i = 0; i < dramas.size(); i++)
			if (findMovie.getDirector() == customerDramas.at(i)->getDirector() &&
				findMovie.getTitle() == customerDramas.at(i)->getTitle())
				customers->get(customerID)->removeMovieBorrowed(i);
		// increase the stock of movie that the customer has returned in the inventory
		for (int i = 0; i < dramas.size(); i++)
			if (findMovie.getDirector() == dramas.at(i)->getDirector() &&
				findMovie.getTitle() == dramas.at(i)->getTitle())
				dramas.at(i)->setStock(dramas.at(i)->getStock() + 1);
	}
	// comedy transaction logic
	else if (movieType == 'F')
	{
		// title
		getline(items, item, ',');
		if (item[0] == ' ')
			item.erase(item.begin());
		findMovie.setTitle(item);

		items >> num;
		findMovie.setYearReleased(num);
		// pointer to customer's list of movies borrowed
		vector<Movie*> customerComedies;
		customers->get(customerID)->getMoviesBorrowed(&customerComedies);
		// pointer to list of comedies in inventory (main)
		vector<Movie*> comedies;
		movies->at(1)->bstToVector(&comedies);
		// remove the movie from the customers list of borrowed movies
		for (int i = 0; i < customerComedies.size(); i++)
		{
			if (findMovie.getTitle() == customerComedies.at(i)->getTitle() &&
				findMovie.getYearReleased() == customerComedies.at(i)->getYearReleased())
			{
				customers->get(customerID)->removeMovieBorrowed(i);
			}
		}
		// increase the stock of movie that the customer has returned in the inventory
		for (int i = 0; i < comedies.size(); i++)
		{
			if (findMovie.getTitle() == comedies.at(i)->getTitle() && 
				findMovie.getYearReleased() == comedies.at(i)->getYearReleased())
			{
				comedies.at(i)->setStock(comedies.at(i)->getStock() + 1);
			}
		}
	}
	// classic transaction logic
	else if (movieType == 'C')
	{
		items >> num;
		int monthReleased = num;

		items >> num;
		int yearReleased = num;
		// major actor (item)
		getline(items, item);
		if (item[0] == ' ')
			item.erase(item.begin());
		// pointer to customer's list of movies borrowed
		vector<Movie*> customerClassics;
		customers->get(customerID)->getMoviesBorrowed(&customerClassics);
		// classic vector for customers list of movies borrowed (for full access)
		vector<Classic*> tempCustomerClassics;
		// pointer to list of classics in inventory
		vector<Movie*> classics;
		movies->at(2)->bstToVector(&classics);
		// classic pointer to list of classics in inventory (full access)
		vector<Classic*> tempClassic;
//		// remove the movie from the customers list of borrowed movies
		for (int i = 0; i < customerClassics.size(); i++)
		{
			if(customerClassics.at(i)->getType() == 'C')
				if(yearReleased == customerClassics.at(i)->getYearReleased())
					customers->get(customerID)->removeMovieBorrowed(i);
		}
		// increase the stock of movie that the customer has returned in the inventory
		for (int i = 0; i < classics.size(); i++)
		{
			tempClassic.push_back(dynamic_cast <Classic *> (classics.at(i)));
			if (monthReleased == tempClassic.at(i)->getMonthReleased() &&
				yearReleased == tempClassic.at(i)->getYearReleased() &&
				item == tempClassic.at(i)->getMajorActor())
			{
				classics.at(i)->setStock(classics.at(i)->getStock() + 1);
			}
		}
	}
	// not a movie type, throw error message
	else
	{
		cout << "Bad character line ID (FDC) in createReturnTransaction" << endl << endl;
		return;
	}
	cout << endl;
}

// create history transaction logic (print movies borrowed by a specific customer)
void TransactionFactory::createHistoryTransaction(string line, vector<BST*> *movies, HashTable *customers)
{
	stringstream items;
	items << line;
	int customerID = -1;

	items >> customerID;
	// check customer ID first, otherwise would give error looking up an invalid customer id ( -# )
	if (customerID != -1 && customers->get(customerID)->getID() != -1)
	{
		cout << "Customer History " << endl;
		customers->get(customerID)->print(cout);
	}
	cout << endl;
}
