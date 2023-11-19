#ifndef TREES_H
#define	TREES_H

#include <array>
#include <vector>
#include <string>
#include <iostream>
#include <fstream>
#include <ios>
#include <sstream>
#include <queue>

enum Color
{
	RED,
	BLACK
};

class Node
{
public:
	Node(int);

	bool HasRedChild();
	bool IsOnLeft();

	void MoveDown(Node*);
	
	Node* FindUncle();
	Node* FindSibling();


	//**Public Variables**//

	int key;
	Color color;
	Node* left;
	Node* right;
	Node* parent;
};


class Tree
{
public:
	Tree();

	Node* Search(int);

	void InsertNode(int);
	void InsertNodeRBT(int);

	// Deletes node with the given KEY...
	void DeleteNode(int);
	void DeleteNodeRBT(int);

	// prints inorder of the tree
	void PrintInOrder();

	// prints level order of the tree
	int GetHeight();

private:
	Node* root;

	void RotateLeft(Node*);
	void RotateRight(Node*);

	// Swaps first node's color with the second node's color.
	void SwapColors(Node*, Node*);

	// Swaps first node's key with the second node's key.
	void SwapKeys(Node*, Node*);

	void FixDoubleRed(Node*);

	Node* Successor(Node*);

	Node* Replace(Node*);

	void Transplant(Node*, Node*);

	Node* GetMinimum(Node*);

	void DeleteRBT(Node*);

	void FixDoubleBlack(Node*);

	int CalculateHeight(Node*);

	void InOrderTraversal(Node*);
};

#endif
#include "trees.cpp"


//***********************//
//******PSEUDO-CODE******//
//***********************//

/*
Tree-Search(x, k)
	if (x == NIL or k == x.key)
		return x
	if (k < x.key)
		return Tree-Search(x.left, k)
	else
		return Tree-Search(x.right, k)

Tree-Minimum(x)
	while (x.left != NIL)
		x = x.left
	return x

Tree-Maximum(x)
	while (x.right != NIL)
		x = x.right
	return x

Tree-Insert(T, z)
	y = NIL
	x = T.root
	while (x != NIL)
		y = x
		if (z.key < x.key)
			x = x.left
		else
			x = x.right
	z.parent = y
	if (y == NIL)
		T.root = z
	else if(z.key < y.key)
		y.left = z
	else
		y.right = z

Tree-Delete(T, z)
	if (z.left == NIL)
		Transplant(T, z, z.right)
	else if(z.right == NIL)
		Transplant(T, z, z.left)
	else
		y = Tree-Minimum(z.right)
		if (y.parent != z)
			Transplant(T, y, y.right)
			y.right = z.right
			y.right.parent = y
		Transplant(T, z, y)
		y.left = z.left
		y.left.parent = y

Transplant(T, u, v)
	if (u.parent == NIL)
		T.root = v
	else if(u == u.parent.left)
		u.parent.left = v
	else
		u.parent.right = v
	if (v != NIL)
		v.parent = u.parent

In-Order-Traversal(x)
	if (x != NIL)
		Traversal(x.left)
		print(x)
		Traversal(x.right)


RED BLACK TREES!!!

Rotate-Left(T, x)
	y = x.right
	x.right = y.left
	if (y.left != T.nil)
		y.left.parent = x
	y.parent = x.parent
	if (x.parent == T.nil)
		T.root = y
	else if(x == x.parent.left)
		x.parent.left = y
	else
		x.parent.right = y
	y.left = x
	x.parent = y

Rotate-Right(T, x)
	y = x.left
	x.left = y.right
	if (y.right != T.nil)
		y.right.parent = x
	y.parent = x.parent
	if (x.parent == T.nil)
		T.root = y
	else if (x == x.parent.right)
		x.parent.right = y
	else
		x.parent.left = y
	y.right = x
	x.parent = y

RB-Insert(T, z)
	y = T.nil
	x = T.root
	while (x != T.nil)
		y = x
		if (z.key < x.key)
			x = x.left
		else
			x = x.right
	z.parent = y
	if (y == T.nil)
		T.root = z
	else if (z.key < y.key)
		y.left = z
	else
		y.right = z
	z.left = T.nil
	z.right = T.nil
	z.color = RED
	RB-Insert-Fixup(T, z)

RB-Insert-Fixup(T, z)
	if (z.parent == z.parent.parent.left)
		y = z.parent.parent.right
		if (y.color == RED)
			z.parent.color = BLACK
			y.color = BLACK
			z.parent.parent.color = RED
			z = z.parent.parent
		else
			if (z == z.parent.right)
				z = z.parent
				Left-Rotate(T, z)
			z.parent.color = BLACK
			z.parent.parent.color = RED
			Right-Rotate(T, z.parent.parent)
	else
		y = z.parent.parent.left
		if (y.color == RED)
			z.parent.color = BLACK
			y.color = BLACK
			z.parent.parent.color = RED
			z = z.parent.parent
		else
			if (z == z.parent.left)
				z = z.parent
				Right-Rotate(T, z)
			z.parent.color = BLACK
			z.parent.parent.color = RED
			Left-Rotate(T, z.parent.parent)
	T.root.color = BLACK

RB-Delete(T, z)
	y = z
	y-original-color = y.color
	if (z.left == T.nil)
		x = z.right
		RB-Transplant(T, z, z.right)
	else if (z.right == T.nil)
		x = z.left
		RB-Transplant(T, z, z.left)
	else
		y-originl-color = y.color
		x = y.right
		if (y.parent == z)
			x.parent = y
		else
			RB-Transplant(T, y, y.right)
			y.right = z.left
			y.right.parent = y
		RB-Transplant(T, z, y)
		y.left = z.left
		y.left.parent = y
		y.color = z.color
	if (y-original-color == BLACK)
		RB-Delete-Fixup(T, x)
	
RB-Delete-Fixup(T, x)
	while (x != T.root && x.color == BLACK)
		if(x == x.parent.left)
			w = x.parent.right
			if (w.color == RED)
				w.color = BLACK
				x.parent.color = RED
				Left-Rotate(T, x.parent)
				w = x.parent.right
			if (w.left.color == BLACK && w.right.color == BLACK)
				w.color = RED
				x = x.parent
			else
				if (w.right.color == BLACK)
					w.left.color = BLACK
					w.color = RED
					Right-Rotate(T, w)
					w = x.parent.right
				w.color = x.parent.color
				x.parent.color = BLACK
				w.right.color = BLACK
				Left-Rotate(T, x.parent)
				x = T.root
		else
			w = x.parent.left
			if (w.color == RED)
				w.color = BLACK
				x.parent.color = RED
				Right-Rotate(T, x.parent)
				w = x.parent.left
			if (w.right.color == BLACK && w.left.color == BLACK)
				w.color = RED
				x = x.parent
			else
				if (w.left.color == BLACK)
					w.right.color = BLACK
					w.color = RED
					Left-Rotate(T, w)
					w = x.parent.left
				w.color = x.parent.color
				x.parent.color = BLACK
				w.left.color = BLACK
				Right-Rotate(T, x.parent)
				x = T.root
	x.color = BLACK
	
RB-Transplant(T, u, v)
	if (u.parent == T.nil)
		T.root = v
	else if (u == u.parent.left)
		u.parent.left = v
	else
		u.parent.right = v
	v.parent = u.parent

*/

