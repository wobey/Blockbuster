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
#include "NodeData.h"
using namespace std;

template <typename T>
class BSTree
{
	friend ostream & operator<<(ostream&, const BSTree<T>&);

public:
	BSTree();								// constructor
	BSTree(const BSTree&);					// copy constructor
	~BSTree();								// destructor, calls makeEmpty	
	bool isEmpty() const;					// true if tree is empty, otherwise false
	void makeEmpty();						// make the tree empty so isEmpty returns true
	BSTree<T>& operator=(const BSTree<T>&);
	bool operator==(const BSTree<T>&) const;
	bool operator!=(const BSTree<T>&) const;
	bool insert(NodeData<T>*);
	bool retrieve(const NodeData<T>&, NodeData<T>*&);
	void displaySideways() const;			// provided below, displays the tree sideways
	int getHeight(const NodeData<T>&) const;
	void bstreeToArray(NodeData<T>*[]);
	void arrayToBSTree(NodeData<T>*[]);

private:
	struct Node
	{
		NodeData<T>* data;						// pointer to data object
		Node* left;							// left subtree pointer
		Node* right;						// right subtree pointer
	};
	Node* root;								// root of the tree
	int numNodes;							// total number of BST nodes

	// utility functions
	void sideways(Node*, int) const;		// provided below, helper for displaySideways()
	void insert(Node*&, Node*&, bool&);
	Node* copyTree(const Node*, Node*);
	bool testEqual(const Node*, const Node*) const;
	void makeEmpty(Node *);
	void displayInOrder(const Node*, ostream&) const;
	bool retrieve(const NodeData<T>&, NodeData<T>*&, const Node*);
	void getHeight_FindNode(const NodeData<T>&, Node*&, Node*) const;
	int getHeight(const NodeData<T>&, Node*&) const;
	void bstreetoArray(NodeData<T>*[], Node*, int&);
	Node* arrayToBSTree(NodeData<T>*[], int, int);
};

#endif