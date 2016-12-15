// ------------------------------------------------ BSTree.h ----------------------------------------------------------
// John Fitzgerald, Christine Sutton CSS343 A 
// Date of Creation: 11-24-16
// Date of Last Modification: 11-24-16
// --------------------------------------------------------------------------------------------------------------------
// Purpose: 
// --------------------------------------------------------------------------------------------------------------------
#ifndef BSTREE_H
#define BSTREE_H
#include <iostream>
#include <fstream>
#include "Classic.h"
#include "Comedy.h"
#include "Drama.h"
using namespace std;

#pragma once
template <class T>							// T is either Drama, Comedy, or Classic
class BSTree
{
	template <class T1>
	friend ostream& operator<<(ostream&, const BSTree<T1>&);

public:
	BSTree();								// constructor
	BSTree(const BSTree&);					// copy constructor
	~BSTree();								// destructor, calls makeEmpty	

	bool isEmpty() const;					// true if tree is empty, otherwise false
	void makeEmpty();						// make the tree empty so isEmpty returns true
	BSTree& operator=(const BSTree&);
	void print();
	bool operator==(const BSTree&) const;
	bool operator!=(const BSTree&) const;
	bool insert(T*, string, string);
	T* retrieve(string, string);
	void displaySideways() const;			// provided below, displays the tree sideways
	//int getHeight(const NodeData<T>&) const;
	//void bstreeToArray(const NodeData<T>*[]);
	//void arrayToBSTree(const NodeData<T>*[]);

private:
	struct Node
	{
		T* data;						// pointer to data object
		string firstSortCriterion;
		string secondSortCriterion;
		Node* left;						// left subtree pointer
		Node* right;					// right subtree pointer
	};

	Node* root;								// root of the tree
	int numNodes;							// total number of BST nodes

											// utility functions
	void sideways(Node*, int) const;		// provided below, helper for displaySideways()
	void insert(Node*&, Node*&);
	Node* copyTree(const Node*, Node*);
	bool testEqual(const Node*, const Node*) const;
	void makeEmpty(Node*);
	T* retrieve(string, string, const Node*);
	void displayInOrder(const Node*) const;
	void classicCopy(T*&, T*&);
	//void getHeight_FindNode(const NodeData<T>&, Node*&, Node*) const;
	//int getHeight(const NodeData<T>&, Node*&) const;
	//void bstreetoArray(NodeData<T>*[], Node*, int&);
	//Node* arrayToBSTree(NodeData<T>*[], int, int);
};
#endif

//---------------------------- DefaultConstructor -------------------------------------
// creates an empty tree
template <class T>
BSTree<T>::BSTree()
{
	root = NULL;
	numNodes = 0;
}

//---------------------------- CopyConstructor -------------------------------------
// deep copy
template <class T>
BSTree<T>::BSTree(const BSTree& originalBST)
{
	root = NULL;
	numNodes = 0;

	// recursive function to populate tree
	root = copyTree(originalBST.root, root);
}

//---------------------------- copyTree -------------------------------------
// a helper function for the copy constructor
template <class T>
typename BSTree<T>::Node* BSTree<T>::copyTree(const Node* originalBST, Node* newBST)
{
	// break case: reached a leaf
	if (originalBST == NULL) //base case to end recursion when at tree end
		return NULL;

	// create and populate new node
	Node* newNode = new Node;
	T* ptr = new T(*originalBST->data);		// T constructor takes T

											// store data and pointers in the newNode
	newNode->data = ptr;
	newNode->left = newNode->right = NULL;

	// point temp newNode to newBST
	newBST = newNode;

	newBST->left = copyTree(originalBST->left, newNode->left);
	newBST->right = copyTree(originalBST->right, newNode->right);

	numNodes++;

	return newNode;
}

//---------------------------- ~BSTree -------------------------------------
// destructor, calls makeEmpty
template <class T>
BSTree<T>::~BSTree()
{
	makeEmpty();
}

//---------------------------- isEmpty -------------------------------------
// true if tree is empty, otherwise false
template <class T>
bool BSTree<T>::isEmpty() const
{
	return (root == NULL);
}

//---------------------------- makeEmpty -------------------------------------
// make the tree empty so isEmpty returns true
template <class T>
void BSTree<T>::makeEmpty()
{
	if (root)
	{
		makeEmpty(root);
		root = NULL;
		numNodes = 0;
	}
}

template <class T>
void BSTree<T>::print()
{
	displayInOrder(root);
}

//---------------------------- makeEmpty -------------------------------------
// deletes all bst nodes
template <class T>
void BSTree<T>::makeEmpty(Node* currNode)
{
	// use recursion and stack frames to delete subtree nodes
	if (currNode)
	{
		if (currNode->left)
			makeEmpty(currNode->left);
		if (currNode->right)
			makeEmpty(currNode->right);

		// this may be unecessary but I wanted to ensure everything was cleared from heap mem
		delete currNode->data;
		currNode->data = NULL;
		currNode->left = currNode->right = NULL;
		delete currNode;
		currNode = NULL;
	}
}

//---------------------------- operator= -------------------------------------
// assignment operator
template <class T>
BSTree<T>& BSTree<T>::operator=(const BSTree& right)
{
	// ensure this BST isn't already a copy of originalBST
	if (!isEmpty())
	{
		if (*this == right)
			return *this;
		else
			makeEmpty();
	}

	// initialize values
	root = NULL;
	numNodes = 0;

	// recursive function to populate tree
	root = copyTree(right.root, root);

	return *this;
}

//---------------------------- operator== -------------------------------------
// is equal to operator
template <class T>
bool BSTree<T>::operator==(const BSTree& rightBST) const
{
	// determine if both BSTs have the same number of nodes -- return false if they don't
	if (numNodes != rightBST.numNodes)
		return false;
	else  // both BSTs have same number of nodes
		return testEqual(root, rightBST.root);
}

//---------------------------- operator== -------------------------------------
// helper function to the is equal to operator
template <class T>
bool BSTree<T>::testEqual(const Node* leftBST, const Node* rightBST) const
{
	// both BST roots are null (both empty
	if (leftBST == NULL && rightBST == NULL)
		return true;

	// recursively check both BSTs against each other
	if (leftBST != NULL && rightBST != NULL)
	{
		// the nodes are not equal to one another
		if (*leftBST->data != *rightBST->data)
			return false;
		else
		{
			// continue recursion searching to see if both are equal
			return testEqual(leftBST->left, rightBST->left) && testEqual(leftBST->right, rightBST->right);
		}
	}

	// one BST root is null while the other is not NULL
	return false;
}

//---------------------------- operator!= -------------------------------------
// is not equal to operator
template <class T>
bool BSTree<T>::operator!=(const BSTree& rightBST) const
{
	return (!(*this == rightBST));	// use is equal to operator
}

//---------------------------- insert -------------------------------------
// insert a node into the BST
template <class T>
bool BSTree<T>::insert(T* dataNode, string first, string second)
{
	Node *newNode;

	// create and populate new node
	newNode = new Node;
	newNode->data = dataNode;
	newNode->left = newNode->right = NULL;
	newNode->firstSortCriterion = first;
	newNode->secondSortCriterion = second;

	// insert the node recursively
	insert(root, newNode);

	numNodes++; // increment the total number of nodes in the BST

	return true;
}

//---------------------------- insert -------------------------------------
// inserts value or skips insertion if duplicate -- unless the insertion is Classic which indicates the 
template <class T>
void BSTree<T>::insert(Node*& currNode, Node*& newNode)
{	
	//else if (newNode->firstSortCriterion < currNode->firstSortCriterion)
	//	insert(currNode->left, newNode);     // Search the left branch
	//else if (newNode->firstSortCriterion > currNode->firstSortCriterion)
	//	insert(currNode->right, newNode);    // Search the right branch
	//else if (newNode->firstSortCriterion == currNode->firstSortCriterion)		// TODO: SWITCH TO SECOND SEARCH CRITERION
	//{
	//	classicCopy(currNode->data, newNode->data);
	//}

	// finds the correct BST position and inserts the newNode
	if (currNode == NULL)
	{
		currNode = newNode;                  // Insert the node.
		return;
	}

	if (newNode->firstSortCriterion == currNode->firstSortCriterion && 
		newNode->secondSortCriterion == currNode->secondSortCriterion &&
		numNodes > 0)
	{
		classicCopy(currNode->data, newNode->data);
	}
	// determine if a duplicate
	else if (currNode->data->compareEqual(newNode->data))
	{
		delete newNode;
		newNode = NULL;
	}
	// LEFT
	else if (currNode->data->compareGreater(newNode->data))
		insert(currNode->left, newNode);     // Search the left branch
	// RIGHT
	else //if (newNode->firstSortCriterion > currNode->firstSortCriterion)
		insert(currNode->right, newNode);    // Search the right branch

	// add pointer between two nodes (as they are the same movie)

}

//---------------------------- classicCopy -------------------------------------
// points each Classic's classicCopy pointer to that of the other Classic with the same title & month + year
template <class T>
void BSTree<T>::classicCopy(T*& currNode, T*& newNode)
{
	currNode->assignClassicCopy(newNode);
	newNode->assignClassicCopy(currNode);
}

//---------------------------- retrieve -------------------------------------
// retrieves a given node's ptr
template <class T>
T* BSTree<T>::retrieve(string first, string second)
{
	return retrieve(first, second, root);
}

//---------------------------- retrieve -------------------------------------
// recursively retrieves a given node's ptr
template <class T>
T* BSTree<T>::retrieve(string first, string second, const Node* bstNode)
{
	// TODO: 
	// need to search with both first and second criteria
	// determine if first and/or second are valid (some will be blank, bogus, etc. for transactions)


	// the node is not in the BST
	//if (bstNode == NULL)
	//	return NULL;
	//else if (first < *bstNode->firstSortCriterion)	// search down the left subtree
	//	retrieve(first, second, bstNode->left);
	//else if (first > *bstNode->firstSortCriterion)   // search down the right subtree
	//	retrieve(first, second, bstNode->right);
	//else									// the node was found
	//{
		return bstNode->data;
	//}
}

//------------------------- displaySideways ---------------------------------
// Displays a binary tree as though you are viewing it from the side;
// hard coded displaying to standard output.
// Preconditions: NONE
// Postconditions: BSTree remains unchanged.
template <class T>
void BSTree<T>::displaySideways() const
{
	sideways(root, 0);
}

////---------------------------- GetHeight -------------------------------------
//// gets height of Node from furthest leaf node (not necessarily a BST)
//template <class T>
//int BSTree<T>::getHeight(const T& searchData) const
//{
//	// Find node in tree (ensure you found node)
//	Node* foundNode;
//	foundNode = NULL;		// set to NULL to help return false if the node wasn't found
//	getHeight_FindNode(searchData, foundNode, root);	// locates node in BST
//
//	return getHeight(searchData, foundNode);			// returns the height of the node
//}
//
////---------------------------- GetHeight -------------------------------------
//// recursively gets the height of a Node from furthest leaf node (not necessarily a BST)
//template <class T>
//void BSTree<T>::getHeight_FindNode(const T& searchData, Node*& foundNode, Node* bstNode) const
//{
//	// in-order search
//	if (bstNode != NULL)
//	{
//		// the correct node was found
//		if (searchData == *bstNode->data)
//		{
//			foundNode = bstNode;
//			return;
//		}
//
//		getHeight_FindNode(searchData, foundNode, bstNode->left);
//		getHeight_FindNode(searchData, foundNode, bstNode->right);
//	}
//}
//
////---------------------------- GetHeight -------------------------------------
//// gets height of Node from furthest leaf node
//template <class T>
//int BSTree<T>::getHeight(const T& searchData, Node*& bstNode) const
//{
//	// base case
//	if (bstNode == NULL)
//		return 0;
//	
//	int left = getHeight(searchData, bstNode->left);
//	int right = getHeight(searchData, bstNode->right);
//
//	int max = 0;	// part of the value to be returned
//
//	// determine if left or right was higher
//	if (left > right)
//		max = left;
//	else if (right > max)
//		max = right;
//	else  // left and right are same length
//		max = left;
//
//	return 1 + max;
//}
//
////---------------------------- bstreeToArray -------------------------------------
//// fill an array with the inorder traversal of a BST
//template <class T>
//void BSTree<T>::bstreeToArray(T* arr[])
//{
//	int index = 0;
//
//	// assign the BST to an array
//	bstreetoArray(arr, root, index);
//
//	// empty BST
//	makeEmpty();
//}
//
////---------------------------- bstreeToArray -------------------------------------
//// recursive helper function to fill an array with the inorder traversal of a bst
//template <class T>
//void BSTree<T>::bstreetoArray(T* arr[], Node* bstNode, int& index)
//{
//	// in-order traversal 
//	if (bstNode)
//	{
//		bstreetoArray(arr, bstNode->left, index);
//
//		// store ptr to NodeData in array
//		T* ptr = new T(*bstNode->data);
//		arr[index] = ptr;
//		++index;
//
//		bstreetoArray(arr, bstNode->right, index);
//	}
//}
//
////---------------------------- arrayToBSTree -------------------------------------
//// fill BST with an array that has a BST stored in-order storage
//template <class T>
//void BSTree<T>::arrayToBSTree(T* arr[])
//{
//	int arraySize = 0;
//	int beg = 0;
//	int end = 0;
//
//	while (arr[arraySize] != NULL)	// determine size of valid pointers stored in the array
//		arraySize++;
//
//	numNodes = arraySize;	// set BST's number of nodes
//	end = arraySize - 1;	// the end of the 
//
//	// assign the array to a BST root
//	root = arrayToBSTree(arr, beg, end);
//
//	// empty array (ensure it's catching the last stored pointer (might be off by 1)
//	for (int i = 0; i < arraySize; i++)
//	{
//		delete arr[i];
//		arr[i] = NULL;
//	}
//}
//
////---------------------------- arrayToBSTree -------------------------------------
//// recursive helper function to fill a BST with an array that has a BST stored in-order storage
//template <class T>
//BSTree<T>::Node* BSTree<T>::arrayToBSTree(T* arr[], /*Node* bstNode,*/ int beg, int end)
//{
//	// base case
//	if (beg > end)
//		return NULL;
//
//	// determine new middle
//	int mid = (beg + end) / 2;
//	
//	// create and populate new node
//	Node* newNode = new Node;
//	T* ptr = new T(*arr[mid]);
//
//	// store data and pointers in the newNode
//	newNode->data = ptr;
//	newNode->left = newNode->right = NULL;
//
//	// in-order array requires find the middle and accessing and storing in opposite directions
//	newNode->left = arrayToBSTree(arr, beg, mid - 1);
//	newNode->right = arrayToBSTree(arr, mid + 1, end);
//
//	return newNode;
//}

//---------------------------- Sideways -------------------------------------
// Helper method for displaySideways
// Preconditions: NONE
// Postconditions: BSTree remains unchanged.
template <class T>
void BSTree<T>::sideways(Node* current, int level) const {
	if (current != NULL) {
		level++;
		sideways(current->right, level);

		// indent for readability, 4 spaces per depth level 
		for (int i = level; i >= 0; i--) {
			cout << "    ";
		}
		cout << *current->data << endl;        // display information of object

		sideways(current->left, level);
	}
}

//-------------------------- displayInOrder --------------------------------------
// a helper function for the stream operator to output in-order BST
template <class T>
void BSTree<T>::displayInOrder(const Node* currNode) const
{
	// in-order traversal
	if(currNode)
	{
		displayInOrder(currNode->left);
		cout << currNode->data << endl;
		displayInOrder(currNode->right);
	}
}

//-------------------------- operator<< --------------------------------------
// stream operator to output in-order BST
template <class T1>
ostream& operator<<(ostream& output, const BSTree<T1>& bst)
{
	// in-order traversal output of the values
	bst.displayInOrder(bst.root);
	output << endl;

	return output;
}
