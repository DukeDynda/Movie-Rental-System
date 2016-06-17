/*
Drama (Movie type)

Part of Movie Parent Class

Drama(string)
bool operator<(const Movie &) const
bool operator>(const Movie &) const
bool operator==(const Movie &) const
*/
#include "Drama.h"
#include <sstream>
#include <cstdlib>
#include <iostream>

// string constructor
Drama::Drama(string line)
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
	if(item[0] == ' ')
		item.erase(item.begin());
	setDirector(item);

	getline(items, item, ',');			// title
	if (item[0] == ' ')
		item.erase(item.begin());
	setTitle(item);

	getline(items, item, ',');			// year
	if (item[0] == ' ')
		item.erase(item.begin());
	num = atoi(item.c_str());
	setYearReleased(num);
}

// compare operator (compare this movie to another) (sort by director then title)
bool Drama::operator<(const Movie &m) const
{
	// get the smaller number of characters in string of director and compared director
	int minCharsD = getDirector().length() < m.getDirector().length() ?
		getDirector().length() : m.getDirector().length();
	// get the smaller number of characters in string of title and compared title
	int minCharsT = getTitle().length() < m.getTitle().length() ?
		getTitle().length() : m.getTitle().length();
	
	if (getDirector() == m.getDirector() && getTitle() == m.getTitle())
		return false;

	for (int i = 0; i < minCharsD; i++)		// compare director first by ascii value of chars
	{
		if (getDirector()[i] > m.getDirector()[i])
			return false;
	}

	for (int i = 0; i < minCharsT; i++)		// then compare title by ascii value of chars
	{
		if (getTitle()[i] > m.getTitle()[i])
			return false;
	}

	return true;		// all comparisons went through, movie must be less than other movie
}

// greater than comparison operator
bool Drama::operator>(const Movie &m) const
{
	if (*this < m || *this == m)
		return false;
	else
		return true;
}

// equals comparison operator
bool Drama::operator==(const Movie &m) const
{
	if (getDirector() == m.getDirector() && getTitle() == m.getTitle())
		return true;
	else
		return false;
}