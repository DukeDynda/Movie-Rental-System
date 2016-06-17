/*
Drama (Movie type)

Part of Movie Parent Class
*/
#pragma once
#ifndef DRAMA_H
#define DRAMA_H
#include <string>
#include <iostream>
#include "Movie.h"
using namespace std;

class Drama : public Movie
{
public:
	// constructor
	Drama(string);
	// compare director and title of this and other movie (sort by director, then title)
	bool operator<(const Movie &) const;
	bool operator>(const Movie &) const;
	bool operator==(const Movie &) const;

};
#endif