/*
BST (Binary Search Tree).

Creates a binary search tree to insert/ sort and print data.

Data is printed from lowest to highest value.

BST()
~BST()
void insert(Movie *item)
void bstToVector(vector<Movie*> *)
void makeEmpty(Node *leaf)
void bstToVectorHelper(Node *, vector<Movie*> *, int *)
ostream outputHelper(Node *current, ostream &output) const
ostream &operator<<(ostream &output, const BST &bst)
*/
#include "BST.h"

// default constructor
BST::BST()
{
	root = NULL;
}

// destructor
BST::~BST()
{
	makeEmpty(root);
}

// insert an item into the binary tree (non-recursive)
void BST::insert(Movie *item)
{
	// create temporary node with added data to be inserted into binary tree
	Node *temp = new Node;
	temp->data = item;
	temp->left = NULL;
	temp->right = NULL;
	// if root has no data, temporary node will become root's data
	if (root == NULL)
	{
		root = temp;
		return;
	}
	// otherwise root has data, thus insert into proper leaf
	else
	{
		Node *current = root;

		while (true)
		{
			// insert to the left ( < )
			if (*item < *current->data)
			{
				if (current->left == NULL)
				{
					current->left = temp;
					return;
				}
				else
				{
					current = current->right;
				}
			}
			// insert to the right ( > )
			else if (*item > *current->data)
			{
				if (current->right == NULL)
				{
					current->right = temp;
					return;
				}
				else
				{
					current = current->right;
				}
			}
			// do not insert, as item already exists ( == )
			else if (*item == *current->data)
			{
				delete temp;
				return;
			}
		}
	}
	// something went wrong (item is/ is not NULL, is/ is not >, is/ is not <, and is/ is not ==)
	delete temp;
	return;
}

// returns this bst in the form of an array
void BST::bstToVector(vector<Movie*> *data)
{
	int *intPtr = new int(1);
	bstToVectorHelper(root, data, intPtr);
	delete intPtr;
}

// recursively delete everything in binary tree (root) making it empty
void BST::makeEmpty(Node *leaf)
{
	if (leaf != NULL)
	{
		makeEmpty(leaf->left);
		makeEmpty(leaf->right);
		delete leaf;
	}
}

// bstToArray helper function (recursive)
void BST::bstToVectorHelper(Node *rootCopy, vector<Movie*> *data, int *level)
{
	if (rootCopy != NULL)
	{
		bstToVectorHelper(rootCopy->left, data, level);
		data->push_back(rootCopy->data);
		bstToVectorHelper(rootCopy->right, data, level);
	}
}

// recursive helper for output stream ( << )
ostream &BST::outputHelper(Node *current, ostream &output) const
{
	if (current != NULL)
	{
		outputHelper(current->left, output);
		current->data->print(output);
		outputHelper(current->right, output);
	}
	return output;
}

// overloaded output stream (edit as needed to fit needs better)
ostream &operator<<(ostream &output, const BST &bst)
{
	bst.outputHelper(bst.root, output);
	cout << endl;
	return output;
}
