/*
BST (Binary Search Tree).

Binary Tree Object that will insert, automatically sort, and print data
of typedef specified below (edit << and typedef as needed to fit needs).

Specified typedef data structure must include <, >, ==, and <<.
*/
#pragma once
#ifndef BST_H
#define BST_H
#include "Movie.h"
#include <vector>
#include <iostream>
using namespace std;

class BST
{
	// overloaded output stream (may make edits here to fit needs better)
	friend ostream &operator<<(ostream &, const BST &);
	// use any type that has BST's required operations (<, >, ==, <<)
	//typedef Movie type;

public:
	// default constructor (sets root to null)
	BST();
	// destructor (makes root empty then deletes root)
	~BST();
	// insertion of type into binary tree (doesn't insert if item already exists)
	void insert(Movie *);
	// return the bst in vector format
	void bstToVector(vector<Movie*> *);

private:
	// binary tree of typedef defined
	struct Node
	{
		Movie *data;
		Node *left;
		Node *right;
	};
	// root/ head of the binary tree
	Node *root;
	// deletes everything in binary tree (root)
	void makeEmpty(Node *);
	// bstToArray helper
	void bstToVectorHelper(Node *, vector<Movie*> *, int *);
	// displays the binary tree using cout's
	ostream &outputHelper(Node *, ostream &) const;
};
#endif