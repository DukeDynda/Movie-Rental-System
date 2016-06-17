/*
Comedy (Movie type)

Part of Movie Parent Class
*/
#pragma once
#ifndef COMEDY_H
#define COMEDY_H
#include <string>
#include <iostream>
#include "Movie.h"
using namespace std;

class Comedy : public Movie
{
public:
	// constructor
	Comedy(string);
	// compare title and year of this and other movie (sort by title, then year of release)
	bool operator<(const Movie &) const;
	bool operator>(const Movie &) const;
	bool operator==(const Movie &) const;
};
#endif