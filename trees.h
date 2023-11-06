#ifndef TREES_H
#define	TREES_H

#include <array>
#include <vector>
#include <string>
#include <iostream>
#include <fstream>
#include <ios>
#include <sstream>

// Struct for new Node type...
struct Node
{
	int key;
	Node *parent, *left, *right;
	bool red;
};

class BST
{
public:
	BST();

	void InsertNode(Node*);
	void InOrderPrint(Node*) const;
	void NewNode(Node*, int);

	Node* DeleteNode(Node*, int);
	Node* GetRoot() const;
	Node* Search(Node*, int) const;

private:
	void Transplant(Node*, Node*);

	Node* Maximum (Node*);
	Node* Minimum (Node*);

	Node* nil;
	Node* root;
};


class RBT : public BST
{
public:
	RBT();

	void NewNodeRB(Node*, int);
	void InsertNodeRB(Node*);
	void RotateLeft(Node*);
	void RotateRight(Node*);

	Node* GetRoot() const;

private:
	Node* root;
	Node* nil;
};

#endif
#include "trees.cpp"

/************************/

