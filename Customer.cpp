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
#include "Customer.h"
#include <sstream>

//default constructor
Customer::Customer()
{
	// don't have anything to initialize here, but need the default constructor
}

// string constructor (id, first name, last name)
Customer::Customer(string line)
{
	stringstream items;
	items << line;
	int num;
	string item;

	items >> num;
	setID(num);

	items >> item;
	setLastName(item);

	items >> item;
	setFirstName(item);
}

// destructor
Customer::~Customer()
{
	
}

// print out all customer information
void Customer::print(ostream &output)
{
	output << getID() << ", " << getLastName() << ", " << getFirstName() << ", " << endl;
	for (int i = 0; i < getMoviesBorrowed().size(); i++)
		moviesBorrowed.at(i).print(cout);
}

// set ID
void Customer::setID(int i)
{
	ID = i;
}

// get ID
int Customer::getID() const
{
	return ID;
}

// set first name
void Customer::setFirstName(string f)
{
	firstName = f;
}

// get first name
string Customer::getFirstName() const
{
	return firstName;
}

// set last name
void Customer::setLastName(string l)
{
	lastName = l;
}

// get last name
string Customer::getLastName() const
{
	return lastName;
}

// add movie to movies borrowed (adds to the vector)
void Customer::addMoviesBorrowed(Movie movie)
{
	moviesBorrowed.push_back(movie);
}

// get movies the customer has borrowed thus far
vector<Movie> Customer::getMoviesBorrowed()
{
	return moviesBorrowed;
}

// get movies customer has borrowed thus far passing a pointer to parameter
void Customer::getMoviesBorrowed(vector<Movie*> *movies)
{
	for (int i = 0; i < moviesBorrowed.size(); i++)
	{
		movies->push_back(&moviesBorrowed.at(i));
	}
}

// removes a movie that is borrowed at a specified location in the vector
void Customer::removeMovieBorrowed(int movieLocation)
{
	swap(moviesBorrowed.at(movieLocation), moviesBorrowed.back());
	moviesBorrowed.pop_back();
}
