// ------------------------------------------------ BSTree.cpp ----------------------------------------------------------
// John Fitzgerald, Christine Sutton CSS343 A 
// Date of Creation: 11-24-16
// Date of Last Modification: 11-24-16
// --------------------------------------------------------------------------------------------------------------------
// Purpose: 
// --------------------------------------------------------------------------------------------------------------------
#include "BSTree.h"

//---------------------------- DefaultConstructor -------------------------------------
// creates an empty tree
template <typename T>
BSTree<T>::BSTree()
{
	root = NULL;
	numNodes = 0;
}

//---------------------------- CopyConstructor -------------------------------------
// deep copy
template <typename T>
BSTree<T>::BSTree(const BSTree<T>& originalBST)
{
	root = NULL;
	numNodes = 0;

	// recursive function to populate tree
	root = copyTree(originalBST.root, root);
}

//---------------------------- copyTree -------------------------------------
// a helper function for the copy constructor
template <typename T>
BSTree<T>::Node* BSTree::copyTree(const Node* originalBST, Node* newBST)
{
	// break case: reached a leaf
	if (originalBST == NULL) //base case to end recursion when at tree end
		return NULL;

	// create and populate new node
	Node* newNode = new Node;
	NodeData<T>* ptr = new NodeData<T>(*originalBST->data);		// NodeData<T> constructor takes T

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
template <typename T>
BSTree<T>::~BSTree()
{
	makeEmpty();
}

//---------------------------- isEmpty -------------------------------------
// true if tree is empty, otherwise false
template <typename T>
bool BSTree<T>::isEmpty() const
{
	return (root == NULL);
}

//---------------------------- makeEmpty -------------------------------------
// make the tree empty so isEmpty returns true
template <typename T>
void BSTree<T>::makeEmpty()
{
	makeEmpty(root);
	root = NULL;
	numNodes = 0;
}

//---------------------------- makeEmpty -------------------------------------
// deletes all bst nodes
template <typename T>
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
template <typename T>
BSTree& BSTree<T>::operator=(const BSTree<T>& right)
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
template <typename T>
bool BSTree<T>::operator==(const BSTree<T>& rightBST) const
{
	// determine if both BSTs have the same number of nodes -- return false if they don't
	if (numNodes != rightBST.numNodes)
		return false;
	else  // both BSTs have same number of nodes
		return testEqual(root, rightBST.root);
}

//---------------------------- operator== -------------------------------------
// helper function to the is equal to operator
template <typename T>
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
template <typename T>
bool BSTree<T>::operator!=(const BSTree<T>& rightBST) const
{
	return (!(*this == rightBST));	// use is equal to operator
}

//---------------------------- insert -------------------------------------
// insert a node into the BST
template <typename T>
bool BSTree<T>::insert(NodeData<T>* dataNode)
{
	Node *newNode;
	bool isUnique = true;

	// create and populate new node
	newNode = new Node;
	newNode->data = dataNode;
	newNode->left = newNode->right = NULL;

	// insert the node recursively
	insert(root, newNode, isUnique);

	// determine if the node was unique or not (duplicate)
	if (isUnique)
	{
		numNodes++;		// increment the total number of nodes in the BST
		return true;
	}
	else  // the node was not unique
	{
		delete newNode;
		return false;
	}
}

//---------------------------- insert -------------------------------------
// inserts value (return true) or skips insertion if duplicate (return false)
template <typename T>
void BSTree<T>::insert(Node*& currNode, Node*& newNode, bool& isUnique)
{
	// finds the correct BST position and inserts the newNode
	if (currNode == NULL)
	{
		currNode = newNode;                  // Insert the node.
		//cout << *currNode->data;
	}
	else if (*newNode->data < *currNode->data)
		insert(currNode->left, newNode, isUnique);     // Search the left branch
	else if (*newNode->data > *currNode->data)
		insert(currNode->right, newNode, isUnique);    // Search the right branch
	else if (*newNode->data == *currNode->data)
		isUnique = false;					// Data is a duplicate
}

//---------------------------- retrieve -------------------------------------
// retrieves a given node's ptr
template <typename T>
bool BSTree<T>::retrieve(const NodeData<T>& searchData, NodeData<T>*& foundPtr)
{
	return retrieve(searchData, foundPtr, root);
}

//---------------------------- retrieve -------------------------------------
// recursively retrieves a given node's ptr
template <typename T>
bool BSTree<T>::retrieve(const NodeData<T>& searchData, NodeData<T>*& foundPtr, const Node* bstNode)
{
	// the node is not in the BST
	if (bstNode == NULL)
		return false;    
	else if (searchData < *bstNode->data)	// search down the left subtree
		retrieve(searchData, foundPtr, bstNode->left);
	else if (searchData > *bstNode->data)   // search down the right subtree
		retrieve(searchData, foundPtr, bstNode->right);
	else									// the node was found
	{
		foundPtr = bstNode->data;
		return true;
	}
}

//------------------------- displaySideways ---------------------------------
// Displays a binary tree as though you are viewing it from the side;
// hard coded displaying to standard output.
// Preconditions: NONE
// Postconditions: BSTree remains unchanged.
template <typename T>
void BSTree<T>::displaySideways() const
{
	sideways(root, 0);
}

//---------------------------- GetHeight -------------------------------------
// gets height of Node from furthest leaf node (not necessarily a BST)
template <typename T>
int BSTree<T>::getHeight(const NodeData<T>& searchData) const
{
	// Find node in tree (ensure you found node)
	Node* foundNode;
	foundNode = NULL;		// set to NULL to help return false if the node wasn't found
	getHeight_FindNode(searchData, foundNode, root);	// locates node in BST

	return getHeight(searchData, foundNode);			// returns the height of the node
}

//---------------------------- GetHeight -------------------------------------
// recursively gets the height of a Node from furthest leaf node (not necessarily a BST)
template <typename T>
void BSTree<T>::getHeight_FindNode(const NodeData<T>& searchData, Node*& foundNode, Node* bstNode) const
{
	// in-order search
	if (bstNode != NULL)
	{
		// the correct node was found
		if (searchData == *bstNode->data)
		{
			foundNode = bstNode;
			return;
		}

		getHeight_FindNode(searchData, foundNode, bstNode->left);
		getHeight_FindNode(searchData, foundNode, bstNode->right);
	}
}

//---------------------------- GetHeight -------------------------------------
// gets height of Node from furthest leaf node
template <typename T>
int BSTree<T>::getHeight(const NodeData<T>& searchData, Node*& bstNode) const
{
	// base case
	if (bstNode == NULL)
		return 0;
	
	int left = getHeight(searchData, bstNode->left);
	int right = getHeight(searchData, bstNode->right);

	int max = 0;	// part of the value to be returned

	// determine if left or right was higher
	if (left > right)
		max = left;
	else if (right > max)
		max = right;
	else  // left and right are same length
		max = left;

	return 1 + max;
}

//---------------------------- bstreeToArray -------------------------------------
// fill an array with the inorder traversal of a BST
template <typename T>
void BSTree<T>::bstreeToArray(NodeData<T>* arr[])
{
	int index = 0;

	// assign the BST to an array
	bstreetoArray(arr, root, index);

	// empty BST
	makeEmpty();
}

//---------------------------- bstreeToArray -------------------------------------
// recursive helper function to fill an array with the inorder traversal of a bst
template <typename T>
void BSTree<T>::bstreetoArray(NodeData<T>* arr[], Node* bstNode, int& index)
{
	// in-order traversal 
	if (bstNode)
	{
		bstreetoArray(arr, bstNode->left, index);

		// store ptr to NodeData in array
		NodeData<T>* ptr = new NodeData<T>(*bstNode->data);
		arr[index] = ptr;
		++index;

		bstreetoArray(arr, bstNode->right, index);
	}
}

//---------------------------- arrayToBSTree -------------------------------------
// fill BST with an array that has a BST stored in-order storage
template <typename T>
void BSTree<T>::arrayToBSTree(NodeData<T>* arr[])
{
	int arraySize = 0;
	int beg = 0;
	int end = 0;

	while (arr[arraySize] != NULL)	// determine size of valid pointers stored in the array
		arraySize++;

	numNodes = arraySize;	// set BST's number of nodes
	end = arraySize - 1;	// the end of the 

	// assign the array to a BST root
	root = arrayToBSTree(arr, beg, end);

	// empty array (ensure it's catching the last stored pointer (might be off by 1)
	for (int i = 0; i < arraySize; i++)
	{
		delete arr[i];
		arr[i] = NULL;
	}
}

//---------------------------- arrayToBSTree -------------------------------------
// recursive helper function to fill a BST with an array that has a BST stored in-order storage
template <typename T>
BSTree<T>::Node* BSTree<T>::arrayToBSTree(NodeData<T>* arr[], /*Node* bstNode,*/ int beg, int end)
{
	// base case
	if (beg > end)
		return NULL;

	// determine new middle
	int mid = (beg + end) / 2;
	
	// create and populate new node
	Node* newNode = new Node;
	NodeData<T>* ptr = new NodeData<T>(*arr[mid]);

	// store data and pointers in the newNode
	newNode->data = ptr;
	newNode->left = newNode->right = NULL;

	// in-order array requires find the middle and accessing and storing in opposite directions
	newNode->left = arrayToBSTree(arr, beg, mid - 1);
	newNode->right = arrayToBSTree(arr, mid + 1, end);

	return newNode;
}

//---------------------------- Sideways -------------------------------------
// Helper method for displaySideways
// Preconditions: NONE
// Postconditions: BSTree remains unchanged.
template <typename T>
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


//-------------------------- operator<< --------------------------------------
// stream operator to output in-order BST
template <typename T>
ostream& operator<<(ostream& output, const BSTree<T>& bst)
{
	// in-order traversal output of the values
	bst.displayInOrder(bst.root, output);
	output << endl;

	return output;
}

//-------------------------- displayInOrder --------------------------------------
// a helper function for the stream operator to output in-order BST
template <typename T>
void BSTree<T>::displayInOrder(const Node* currNode, ostream& output) const
{
	// in-order traversal
	if (currNode)
	{
		displayInOrder(currNode->left, output);
		output << *currNode->data << " ";
		displayInOrder(currNode->right, output);
	}
}