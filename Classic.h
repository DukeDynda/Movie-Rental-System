/*
Classic (Movie type)

Part of Movie Parent Class

Classic movies have their own private string variable (major actor)
No other movie type has a major actor, thus this child class
declares it.
*/
#pragma once
#ifndef CLASSIC_H
#define CLASSIC_H
#include <string>
#include <iostream>
#include "Movie.h"
using namespace std;

class Classic : public Movie
{
public:
	// default constructor
	Classic();
	// constructor
	Classic(string);
	// getter for major actor
	string getMajorActor() const;
	// setter for major actor
	void setMajorActor(string);
	// getter for month
	virtual int getMonthReleased() const;
	// setter for month
	virtual void setMonthReleased(int);
	// compare release date and major actor of this and other movie (sort by release date, then major actor)
	bool operator<(const Movie &) const;
	bool operator>(const Movie &) const;
	bool operator==(const Movie &) const;
	virtual void print(ostream &);
private:
	// major actor specific to classic movie type
	string majorActor;
	//the month the movie was released 
	int monthReleased;
};
#endif