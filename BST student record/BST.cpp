#include <iostream>
#include <fstream>
#include <algorithm>
#include "BST.h"


using namespace std;


BST::BST() {
	root = NULL;
	count = 0;
}


bool BST::empty() {
	if (count == 0) return true;
	return false;
}


int BST::size() {
	return count;
}


void BST::preOrderPrint() {
	if (root == NULL) return;// handle special case
	else preOrderPrint2(root);// do normal process
	cout << endl;
}


void BST::preOrderPrint2(BTNode *cur) {

	if (cur == NULL) return;
	cur->item.print(cout);
	preOrderPrint2(cur->left);
	preOrderPrint2(cur->right);
}


void BST::inOrderPrint() {
	if (root == NULL) return;// handle special case
	else inOrderPrint2(root);// do normal process
	cout << endl;
}


void BST::inOrderPrint2(BTNode *cur) {

	if (cur == NULL) return;

	inOrderPrint2(cur->left);
	cur->item.print(cout);
	inOrderPrint2(cur->right);
}


void BST::postOrderPrint() {
	if (root == NULL) return;// handle special case
	else postOrderPrint2(root);// do normal process
	cout << endl;
}


void BST::postOrderPrint2(BTNode *cur) {
	if (cur == NULL) return;
	postOrderPrint2(cur->left);
	postOrderPrint2(cur->right);
	cur->item.print(cout);
}



int BST::countNode() {
	int	counter = 0;
	if (root == NULL) return 0;
	countNode2(root, counter);
	return counter;
}


void BST::countNode2(BTNode *cur, int &count) {
	if (cur == NULL) return;
	countNode2(cur->left, count);
	countNode2(cur->right, count);
	count++;
}


bool BST::findGrandsons(type grandFather) {
	if (root == NULL) return false;
	return (fGS2(grandFather, root));
}


bool BST::fGS2(type grandFather, BTNode *cur) {
	if (cur == NULL) return false;
	//if (cur->item == grandFather) {
	if (cur->item.compare2(grandFather)){

		fGS3(cur, 0);// do another TT to find grandsons
		return true;
	}
	if (fGS2(grandFather, cur->left)) return true;
	return fGS2(grandFather, cur->right);
}


void BST::fGS3(BTNode *cur, int level) {
	if (cur == NULL) return;
	if (level == 2) {
		cur->item.print(cout);
		return;  // No need to search downward
	}
	fGS3(cur->left, level + 1);
	fGS3(cur->right, level + 1);
}



void BST::topDownLevelTraversal() {
	BTNode			*cur;
	Queue		    q;


	if (empty()) return; 	// special case
	q.enqueue(root);	// Step 1: enqueue the first node
	while (!q.empty()) { 	// Step 2: do 2 operations inside
		q.dequeue(cur);
		if (cur != NULL) {
			cur->item.print(cout);

			if (cur->left != NULL)
				q.enqueue(cur->left);

			if (cur->right != NULL)
				q.enqueue(cur->right);
		}
	}
}

//insert for BST
bool BST::insert(type newItem) {
	BTNode	*cur = new BTNode(newItem);
	if (!cur) return false;		// special case 1
	if (root == NULL) {
		root = cur;
		count++;
		return true; 			// special case 2
	}
	insert2(root, cur);			// normal
	count++;
	return true;
}


void BST::insert2(BTNode *cur, BTNode *newNode) {
	//if (cur->item > newNode->item) {
	if (cur->item.compare1(newNode->item)){
		if (cur->left == NULL)
			cur->left = newNode;
		else
			insert2(cur->left, newNode);
	}
	else {
		if (cur->right == NULL)
			cur->right = newNode;
		else
			insert2(cur->right, newNode);
	}
}



bool BST::remove(type item) {
	if (root == NULL) return false; 		// special case 1: tree is empty
	return remove2(root, root, item); 		// normal case
}

bool BST::remove2(BTNode *pre, BTNode *cur, type item) {

	// Turn back when the search reaches the end of an external path
	if (cur == NULL) return false;

	// normal case: manage to find the item to be removed
	//if (cur->item == item) {
	if (cur->item.compare2(item)){
		if (cur->left == NULL || cur->right == NULL)
			case2(pre, cur);	// case 2 and case 1: cur has less than 2 sons
		else
			case3(cur);		// case 3, cur has 2 sons
		count--;				// update the counter
		return true;
	}

	// Current node does NOT store the current item -> ask left sub-tree to check
	//if (cur->item > item)
	if (cur->item.compare1(item))
		return remove2(cur, cur->left, item);

	// Item is not in the left subtree, try the right sub-tree instead
	return remove2(cur, cur->right, item);
}


void BST::case2(BTNode *pre, BTNode *cur) {

	// special case: delete root node
	if (pre == cur) {
		if (cur->left != NULL)	// has left son?
			root = cur->left;
		else
			root = cur->right;

		free(cur);
		return;
	}

	if (pre->right == cur) {		// father is right son of grandfather? 
		if (cur->left == NULL)			// father has no left son?
			pre->right = cur->right;			// connect gfather/gson
		else
			pre->right = cur->left;
	}
	else {						// father is left son of grandfather?
		if (cur->left == NULL)			// father has no left son? 
			pre->left = cur->right;				// connect gfather/gson
		else
			pre->left = cur->left;
	}

	free(cur);					// remove item
}


void BST::case3(BTNode *cur) {
	BTNode		*is, *isFather;

	// get the IS and IS_parent of current node
	is = isFather = cur->right;
	while (is->left != NULL) {
		isFather = is;
		is = is->left;
	}

	// copy IS node into current node
	cur->item = is->item;

	// Point IS_Father (grandfather) to IS_Child (grandson)
	if (is == isFather)
		cur->right = is->right;		// case 1: There is no IS_Father    
	else
		isFather->left = is->right;	// case 2: There is IS_Father

	// remove IS Node
	free(is);
}

bool BST::CloneSubtree(BST t1, type item)
{
	if (!empty() || t1.empty())
	{
		cout << "Cannot clone sub tree.\n";
		return false; // Clone's target tree must be empty tree before cloning, if source tree is empty also return false 
	}
	else if (CloneSubtree2(t1.root, item))
	{
		cout << "T1:\n";
		t1.preOrderPrint();
		cout << "T2 (Cloned Subtree):\n";
		preOrderPrint();
		return true;
	}
	cout << "None of the student ids match.\n";

	return false;
}

bool BST::CloneSubtree2(BTNode* cur, type item)
{
	if (cur == NULL) // Node cannot be found then return false
		return false;
	else if (cur->item.compare2(item))  // check if subtree's Node found
	{
		CloneSubtree3(cur); // recursion function to clone the sub trees
		return true;
	}
	else if (cur->item.compare1(item))  // binary search tree traversal
		return CloneSubtree2(cur->left, item);
	else
		return CloneSubtree2(cur->right, item);
}

void BST::CloneSubtree3(BTNode* cur)
{
	if (cur == NULL)
		return;
	insert(cur->item);
	CloneSubtree3(cur->left);
	CloneSubtree3(cur->right);
}

bool BST::printLevelNodes() {
	//check whether empty or not
	if (empty()) {
		return false; // Return false if it is empty
	}

	Queue q; // Create a queue for level order traversal
	q.enqueue(root); // Enqueue the root node

	int level = 1; // Initialize the level to 1

	while (!q.empty()) {
		cout << "Level " << level << " nodes: ";
		int nodesAtCurrentLevel = q.size();

		// Traverse nodes at the current level
		for (int i = 0; i < nodesAtCurrentLevel; ++i) {
			BTNode* cur;
			q.dequeue(cur);

			cout << cur->item.id << " ";

			// Enqueue left and right children if they exist
			if (cur->left != nullptr) {
				q.enqueue(cur->left);
			}
			if (cur->right != nullptr) {
				q.enqueue(cur->right);
			}
		}

		cout << endl;
		++level; // proceed to the next level
	}

	return true;
}

bool BST::printPath() {
	int path[1000];
	if (root == NULL) {
		cout << "\nThe tree is empty.\n\n";
		return false;
	}
	cout << "\nBelow are all the paths for the tree:\n\n";
	printPath2(root, path, 0);
	return true;
}

/* Recursive helper function -- given a node,
and an array containing the path from the root
node up to but not including this node,
print out all the root-leaf paths.*/
void BST::printPath2(BTNode* cur, int path[], int pathLen)
{
	if (cur == NULL)
		return;

	/* append this node to the path array */
	path[pathLen] = cur->item.id;
	pathLen++;

	/* it's a leaf, so print the path that lead to here */
	if (cur->left == NULL && cur->right == NULL)
	{
		printPath3(path, pathLen);
	}
	else
	{
		/* otherwise try both subtrees */
		printPath2(cur->left, path, pathLen);
		printPath2(cur->right, path, pathLen);
	}
}

/* UTILITY FUNCTIONS */
/* Utility that prints out an array on a line. */
void BST::printPath3(int ints[], int len)
{
	int i;

	for (i = 0; i < len; i++)
	{
		cout << ints[i] << " ";
	}
	cout << endl;
}

bool BST::display(int order, int source) {
	if (empty()) return 0;	//returns false for empty tree
	ofstream outfile;
	outfile.open("student-info.txt");

	if (order == 1 && source == 1) display2(root, cout);					//prints in asc order to screen
	else if (order == 2 && source == 1) displayReverse2(root, cout);		//prints in desc order to screen
	else if (order == 1 && source == 2) display2(root, outfile);			//prints in asc order to file
	else if (order == 2 && source == 2) displayReverse2(root, outfile);	//prints in desc order to file
	cout << endl;

	outfile.close();
	return 1;
}

/*sub functions for display */
void display2(BTNode*, ostream&);
void displayReverse2(BTNode*, ostream&);

/*Recursive function for display (asc) */
void BST::display2(BTNode* cur, ostream& out) {

	if (cur == NULL) return;
	display2(cur->left, out);
	cur->item.print(out);
	display2(cur->right, out);
}

/*Recursive function for display (desc) */
void BST::displayReverse2(BTNode* cur, ostream& out) {

	if (cur == NULL) return;
	displayReverse2(cur->right, out);
	cur->item.print(out);
	displayReverse2(cur->left, out);
}

bool BST::deepestNodes() {
	if (root == NULL) return 0;
	deepestNodes3(root, deepestNodes2(root));

	return true;
}

int BST::deepestNodes2(BTNode* cur) {
	if (cur == NULL)
		return 0;
	else {
		// Find the height of both subtrees
		// and use the larger one
		int left_height = deepestNodes2(cur->left);
		int right_height = deepestNodes2(cur->right);
		if (left_height >= right_height) {
			return left_height + 1;
		}
		else {
			return right_height + 1;
		}
	}
}

void BST::deepestNodes3(BTNode* cur, int levels)
{
	if (!cur) return;

	if (levels == 1)
		cur->item.print(cout);

	else if (levels > 1)
	{
		deepestNodes3(cur->left, levels - 1);
		deepestNodes3(cur->right, levels - 1);
	}
}