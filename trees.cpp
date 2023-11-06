#ifndef TREES_CPP
#define TREES_CPP

#include "trees.h"

//**********BST METHODS**********//
BST::BST()
{
	root = nullptr;
	nil = nullptr;
}

void BST::NewNode(Node* node, int key)
{
	node->key = key;
	node->parent = nullptr;
	node->left = nil;
	node->right = nil;
	node->red = true;
}


void BST::InsertNode(Node* node)
{
	Node* x = this->root;
	Node* y = nil;

	while(x != nil)
	{
		y = x;
		if (node->key < x->key) { x = x->left; }
		else { x = x->right; }
	}

	node->parent = y;

	if (y == nil) { root = node; }
	else if (node->key < y->key) { y->left = node; }
	else { y->right = node; }
}

Node* BST::DeleteNode(Node* node, int key)
{
	if (node == nil) { return node;}

	if (node->key > key)
	{
		node->left = DeleteNode(node->left, key);
		return node;
	}
	else if (node->key < key)
	{
		node->right = DeleteNode(node->right, key);
		return node;
	}

	// If the node has one child...
	if (node->left == nil)
	{
		Node* temp = node->right;
		delete node;
		return temp;
	}
	else if (node->right == nil)
	{
		Node* temp = node->left;
		delete node;
		return temp;
	}
	else // If the node has two children...
	{
		Node* parent = node;
		Node* successor = node->right;

		while (successor->left != nil)
		{
			parent = successor;
			successor = successor->left;
		}

		if (parent != node) { parent->left = successor->right; }
		else { parent->right = successor->right; }

		node->key = successor->key;

		delete successor;
		return node;
	}
}

void BST::Transplant(Node* node, Node* right)
{
	if (node->parent == nil) { this->root = right; }
	else if (node == node->parent->left) { node->parent->left = right; }
	else { node->parent->right = right; }
	
	if (right != nil) { right->parent = node->parent; }
}

Node* BST::Minimum(Node* node)
{
	while (node->left != nil) { node = node->left; }
	return node;
}

Node* BST::Maximum(Node* node)
{
	while (node->right != nil) { node = node->right; }
	return node;
}

void BST::InOrderPrint(Node* node) const
{
	if (node != nil)
	{
		InOrderPrint(node->left);
		std::cout << node->key << ", ";
		InOrderPrint(node->right);
	}
}

Node* BST::GetRoot() const { return root; }

Node* BST::Search(Node* x, int key) const
{
	if (x == nil || key == x->key) { return x; }
	if (key < x->key) { return Search(x->left, key); }
	else { return Search(x->right, key); }
}


//**********RBT METHODS**********//

RBT::RBT() { root = nil; }

void RBT::RotateLeft(Node* x)
{
	Node* y = x->right;
	x->right = y->left;

	if (y->left != nil) { y->left->parent = x; }

	y->parent = x->parent;

	if (x->parent == nil) {root = y; }
	else if (x == x->parent->left) { x->parent->left = y; }
	else { x->parent->right = y; }

	y->left = x;
	x->parent = y;
}

void RBT::RotateRight(Node* x)
{
	Node* y = x->left;
	x->left = y->right;

	if (y->right != nil) { y->right->parent = x; }

	y->parent = x->parent;

	if (x->parent == nil) {root = y; }
	else if (x == x->parent->right) { x->parent->right = y; }
	else { x->parent->left = y; }

	y->right = x;
	x->parent = y;
}

void RBT::NewNodeRB(Node* node, int key)
{
	node->key = key;
	node->parent = nullptr;
	node->left = nil;
	node->right = nil;
	node->red = true;
}

void RBT::InsertNodeRB(Node* node)
{
	Node* x = this->root;
	Node* y = nil;

	while(x != nil)
	{
		y = x;
		if (node->key < x->key) { x = x->left; }
		else { x = x->right; }
	}

	node->parent = y;

	if (y == nil) { root = node; }
	else if (node->key < y->key) { y->left = node; }
	else { y->right = node; }

	// while(node->parent->red == true)
	// {
	// 	if(node->parent == node->parent->parent->right)
	// 	{
	// 		Node* temp = node->parent->parent->left;

	// 		if(temp->red == true)
	// 		{
	// 			temp->red = false;
	// 			node->parent->red = false;
	// 			node->parent->parent->red = true;
	// 			node = node->parent->parent;
	// 		}
	// 		else
	// 		{
	// 			if(node == node->parent->left)
	// 			{
	// 				node = node->parent;
	// 				RotateLeft(node->parent->parent);
	// 			}

	// 			node->parent->red = false;
	// 			node->parent->parent->red = true;
	// 			RotateRight(node->parent->parent);
	// 		}
	// 	}
	// 	else
	// 	{
	// 		Node* temp = node->parent->parent->right;

	// 		if(temp->red == true)
	// 		{
	// 			temp->red = false;
	// 			node->parent->red = false;
	// 			node->parent->parent->red = true;
	// 			node = node->parent->parent;
	// 		}
	// 		else
	// 		{
	// 			if(node == node->parent->right)
	// 			{
	// 				node = node->parent;
	// 				RotateLeft(node->parent->parent);
	// 			}

	// 			node->parent->red = false;
	// 			node->parent->parent->red = true;
	// 			RotateRight(node->parent->parent);
	// 		}
	// 	}
	// }
	// root->red = false;
}

Node* RBT::GetRoot() const { return root; }


#endif