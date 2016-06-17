/*
Classic (Movie type)

Part of Movie Parent Class

Classic()
Classic(string)
string getMajorActor() const
void setMajorActor(string)
int getMonthReleased() const
void setMonthReleased(int)
bool operator<(const Movie &) const
bool operator>(const Movie &) const
bool operator==(const Movie &) const
void print(ostream &)
*/
#include "Classic.h"
#include <sstream>
#include <cstdlib>
#include <iostream>

// default constructor
Classic::Classic()
{
	// just need a constructor to create the object, but no initialization required
}

// string constructor
Classic::Classic(string line)
{
	stringstream items;
	items << line;
	string item;
	int num;

	getline(items, item, ',');			// empty whitespace after input stream

	getline(items, item, ',');			// number of movie items from the input
	if (item[0] == ' ')
		item.erase(item.begin());
	num = atoi(item.c_str());			// stock of this DVD converted to int
	setStock(num);

	getline(items, item, ',');			// director
	if (item[0] == ' ')
		item.erase(item.begin());
	setDirector(item);

	getline(items, item, ',');			// title
	if (item[0] == ' ')
		item.erase(item.begin());
	setTitle(item);
	
	// using >> due to no commas after major actor and month and year
	items >> item;						// major actor
	string mALastName;
	items >> mALastName;
	item += " " + mALastName;
	setMajorActor(item);

	items >> num;						// month
	setMonthReleased(num);

	items >> num;						// year
	setYearReleased(num);
}

// get major actor
string Classic::getMajorActor() const
{
	return majorActor;
}

// set major actor
void Classic::setMajorActor(string mA)
{
	majorActor = mA;
}

// get month released
int Classic::getMonthReleased() const
{
	return monthReleased;
}

// set month released
void Classic::setMonthReleased(int m)
{
	monthReleased = m;
}

// compare operator (compare this movie to another) (sort by year/ month released then major actor)
bool Classic::operator<(const Movie &m) const
{
	// dynamic cast to convert movie to classic (since its called by classic we know its a classic)
	const Classic *cm = dynamic_cast <const Classic *> (&m);

	// get the smaller number of characters in string of major actor and compared major actor
	int minCharsT = getMajorActor().length() < cm->getMajorActor().length() ?
		getMajorActor().length() : cm->getMajorActor().length();

	// if everything is equal then this is not < other
	if (getYearReleased() == m.getYearReleased() && getMonthReleased() == cm->getMonthReleased()
		&& getMajorActor() == cm->getMajorActor())
		return false;

	// compare years and months
	if (getYearReleased() > m.getYearReleased()
		|| getMonthReleased() > cm->getMonthReleased())
		return false;

	// compare major actor by ascii value of chars
	for (int i = 0; i < minCharsT; i++)
	{
		if (getMajorActor()[i] > cm->getMajorActor()[i])
			return false;
	}

	// all comparisons went through, movie must be less than other movie
	return true;
}

// greater than comparison operator
bool Classic::operator>(const Movie &m) const
{
	if (*this < m || *this == m)
		return false;
	else
		return true;
}

// equals comparison operator
bool Classic::operator==(const Movie &m) const
{
	const Classic *cm = dynamic_cast <const Classic *> (&m);

	if (getYearReleased() == m.getYearReleased() && getMonthReleased() == 
		cm->getMonthReleased() && getMajorActor() == cm->getMajorActor())
		return true;
	else
		return false;
}

// print out all classic movie data
void Classic::print(ostream &output)
{
	output << getStock() << ", " << getType() << ", " << getDirector() << ", " << getTitle() << ", ";
	output << getMajorActor() << ", " << getMonthReleased() << ", " << getYearReleased() << endl;
}