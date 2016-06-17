/*
movie object to store types of movies and its data (constructed via inheritance).

movies to be store in a binary search tree and used for customer transactions.

virtual string getDirector() const
virtual void setDirector(const string)
virtual string getTitle() const
virtual void setTitle(const string)
virtual char getType() const
virtual void setType(const char)
virtual int getYearReleased() const
virtual void setYearReleased(int)
virtual int getStock() const
virtual void setStock(int)
virtual bool operator<(const Movie &) const
virtual bool operator>(const Movie &) const
virtual bool operator==(const Movie &) const
virtual void print(ostream &)
*/
#include "Movie.h"
#include "Comedy.h"
#include "Drama.h"
#include "Classic.h"
#include <iostream>
using namespace std;

// get director
string Movie::getDirector() const
{
	return director;
}

// set director
void Movie::setDirector(const string d)
{
	director = d;
}

// get title
string Movie::getTitle() const
{
	return title;
}

// set title
void Movie::setTitle(const string t)
{
	title = t;
}

// get type of movie (F(comedy) Drama Comedy)
char Movie::getType() const
{
	return type;
}

// set type of movie
void Movie::setType(const char t)
{
	type = t;
}

// get release year
int Movie::getYearReleased() const
{
	return yearReleased;
}

// set release year
void Movie::setYearReleased(int y)
{
	yearReleased = y;
}

// get stock information (inventory)
int Movie::getStock() const
{
	return stock;
}

// set stock information (inventory)
void Movie::setStock(int s)
{
	stock = s;
}

// less than comparison operator
bool Movie::operator<(const Movie &m) const
{
	cout << "movie operator<" << endl;
	return false;
}

// greater than comparison operator
bool Movie::operator>(const Movie &m) const
{
	cout << "movie operator>" << endl;
	return false;
}

// equals comparison operator
bool Movie::operator==(const Movie &m) const
{
	cout << "movie operator==" << endl;
	return false;
}

// print out general movie information shared by all movies
void Movie::print(ostream &output)
{
	output << getStock() << ", " << getType() << ", " << getDirector() << ", ";
	output << getTitle() << ", " << getYearReleased() << endl;
}