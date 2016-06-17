/*
movie object to store types of movies and its data (constructed via inheritance).

movies to be store in a binary search tree and used for customer transactions.
*/
#pragma once
#include <string>
#include <iostream>
using namespace std;

class Movie
{
public:
	virtual string getDirector() const;
	virtual void setDirector(const string);

	virtual string getTitle() const;
	virtual void setTitle(const string);

	virtual char getType() const;
	virtual void setType(const char);

	virtual int getYearReleased() const;
	virtual void setYearReleased(int);

	virtual int getStock() const;
	virtual void setStock(int);

	virtual bool operator<(const Movie &) const;
	virtual bool operator>(const Movie &) const;
	virtual bool operator==(const Movie &) const;

	virtual void print(ostream &);

private:
	string director;	//director of movie
	string title;		//title of movie
	char type;			//genre of movie
	int yearReleased;	//release date of movie
	int stock;			//number of this movie in stock
};

