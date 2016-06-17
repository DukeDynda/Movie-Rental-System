/*
customer object to store customer information

Customer()
Customer(string)
~Customer()
void print(ostream &)
void setID(int)
int getID() const
void setFirstName(string)
string getFirstName() const
void setLastName(string)
string getLastName() const
void addMoviesBorrowed(Movie)
vector<Movie> getMoviesBorrowed()
void getMoviesBorrowed(vector<Movie*> *)
void removeMovieBorrowed(int)
int ID
string firstName
string lastName
*/
#pragma once
#ifndef CUSTOMER_H
#define CUSTOMER_H
#include <string>
#include <iostream>
#include <vector>
#include "Movie.h"
using namespace std;

class Customer
{
public:
	Customer();
	Customer(string);
	~Customer();
	//console friendly version of all data of customer
	void print(ostream &);
	void setID(int);
	int getID() const;
	void setFirstName(string);
	string getFirstName() const;
	void setLastName(string);
	string getLastName() const;
	// adds to the movies borrowed by this customer
	void addMoviesBorrowed(Movie);
	vector<Movie> getMoviesBorrowed();
	void getMoviesBorrowed(vector<Movie*> *);
	void removeMovieBorrowed(int);
private:
	//stores the ID of the customer
	int ID;
	//stores the first name of the customer
	string firstName;
	//stores the last name of the customer
	string lastName;
	//stores the copy of the transactions of the customer (all movies the customer has borrowed thus far)
	vector <Movie> moviesBorrowed;
};
#endif
