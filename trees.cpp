#ifndef TREES_CPP
#define TREES_CPP

#include "trees.h"

//******************************************//
//************NODE CLASS METHODS************//
//******************************************//

Node::Node(int key) : key(key)
{
	parent = left = right = nullptr;
	color = RED;
}


bool Node::HasRedChild() { return ((left != nullptr && left->color == RED) || (right != nullptr && right->color == RED)); }

bool Node::IsOnLeft() { return this == parent->left; }


void Node::MoveDown(Node *nodeParent)
{
	if (parent != nullptr)
	{
		if (IsOnLeft()) { parent->left = nodeParent; }
		else { parent->right = nodeParent; }
	}
	
	nodeParent->parent = parent;
	parent = nodeParent;
}


Node* Node::FindUncle()
{
	if (parent == nullptr or parent->parent == nullptr) { return nullptr; }

	if (parent->IsOnLeft()) { return parent->parent->right; }
	else { return parent->parent->left; }
}


Node* Node::FindSibling()
{
	if (parent == nullptr) { return nullptr; }

	if (IsOnLeft()) { return parent->right; }
	else { return parent->left; }
}



//******************************************//
//************Tree CLASS METHODS************//
//******************************************//


// Public Member Methods...

Tree::Tree() { root = nullptr; }


void Tree::DeleteNode(int key)
{
	Node* z = Search(key);

	if (z->left == nullptr) { Transplant(z, z->right);}
	else if(z->right == nullptr) { Transplant(z, z->left); }
	else
	{
		Node* y = GetMinimum(z->right);

		if (y->parent != z)
		{
			Transplant(y, y->right);
			y->right = z->right;
			y->right->parent = y;
		}

		Transplant(z, y);
		y->left = z->left;
		y->left->parent = y;
	}
}


void Tree::DeleteNodeRBT(int key)
{
	if (root == nullptr) { return; }

	Node *node = Search(key);

	DeleteRBT(node);
}


void Tree::InsertNode(int key)
{
	Node *newNode = new Node(key);

	Node* y = nullptr;
	Node* x = root;

	while (x != nullptr)
	{
		y = x;
		if (newNode->key < x->key) { x = x->left; }
		else { x = x->right; }
	}

	newNode->parent = y;

	if (y == nullptr) { root = newNode; }
	else if(newNode->key < y->key) { y->left = newNode; }
	else { y->right = newNode; }
}


void Tree::InsertNodeRBT(int key)
{
	Node *newNode = new Node(key);

	if (root == nullptr)
	{
		newNode->color = BLACK;
		root = newNode;
	}
	else
	{
		Node *temp = Search(key);

		if (temp->key == key) { return; }

		newNode->parent = temp;

		if (key < temp->key) { temp->left = newNode; }
		else { temp->right = newNode; }

		FixDoubleRed(newNode);
	}
}


void Tree::PrintInOrder()
{
	std::cout << "In Order Print: " << std::endl;
	height = InOrderTraversal(root);
}


int Tree::GetHeight() { return height; }


Node* Tree::Search(int key)
{
	Node *temp = root;

	while (temp != nullptr)
	{
		if (key < temp->key)
		{
			if (temp->left == nullptr) { break; }
			else { temp = temp->left; }
		}
		else if (key == temp->key) { break; }
		else {
			if (temp->right == nullptr) { break; }
			else { temp = temp->right; }
		}
	}

	return temp;
}


// Private Member Methods...


void Tree::DeleteRBT(Node *tempNode)
{
	Node *nodeToDelete = Replace(tempNode);

	bool bothNodesBlack = ((nodeToDelete == nullptr || nodeToDelete->color == BLACK) && (tempNode->color == BLACK));
	Node *parent = tempNode->parent;


	if (nodeToDelete == nullptr)																						// tempNode has NO CHILDREN
	{
		if (tempNode == root) { root = nullptr; }
		else
		{
			if (bothNodesBlack) { FixDoubleBlack(tempNode); }
			else { if (tempNode->FindSibling() != nullptr) { tempNode->FindSibling()->color = RED; }}

			if (tempNode->IsOnLeft()) { parent->left = nullptr; }
			else { parent->right = nullptr; }
		}

		delete tempNode;
		return;
	}
	else if (tempNode->left == nullptr or tempNode->right == nullptr)													// tempNode has ONE CHILD
	{
		if (tempNode == root)
		{
			tempNode->key = nodeToDelete->key;
			tempNode->left = tempNode->right = nullptr;
			delete nodeToDelete;
		}
		else
		{
			if (tempNode->IsOnLeft()) { parent->left = nodeToDelete; }
			else { parent->right = nodeToDelete; }

			delete tempNode;
			nodeToDelete->parent = parent;
			
			if (bothNodesBlack) { FixDoubleBlack(nodeToDelete); }
			else { nodeToDelete->color = BLACK; }
		}

		return;
	}
	else																												// tempNode has TWO CHILDREN
	{
		SwapKeys(nodeToDelete, tempNode);
		DeleteRBT(nodeToDelete);
	}
}


void Tree::FixDoubleBlack(Node* node)
{
	if (node == root) { return; }
 
	Node* sibling = node->FindSibling();
	Node* parent = node->parent;

	if (sibling == nullptr) { FixDoubleBlack(parent); }
	else
	{
		if (sibling->color == RED)
		{
			parent->color = RED;
			sibling->color = BLACK;

			if (sibling->IsOnLeft())
			{ RotateRight(parent); }
			else { RotateLeft(parent); }

			FixDoubleBlack(node);
		}
		else
		{
			if (sibling->HasRedChild())
			{
				if (sibling->left != nullptr and sibling->left->color == RED)
				{
					if (sibling->IsOnLeft())
					{
						sibling->left->color = sibling->color;
						sibling->color = parent->color;
						RotateRight(parent);
					}
					else
					{
						sibling->left->color = parent->color;
						RotateRight(sibling);
						RotateLeft(parent);
					}
				}
				else
				{
					if (sibling->IsOnLeft())
					{
						sibling->right->color = parent->color;
						RotateLeft(sibling);
						RotateRight(parent);
					}
					else
					{
						sibling->right->color = sibling->color;
						sibling->color = parent->color;
						RotateLeft(parent);
					}
				}

				parent->color = BLACK;
			}
			else
			{
				sibling->color = RED;

				if (parent->color == BLACK) { FixDoubleBlack(parent); }
				else { parent->color = BLACK; }
			}
	  	}
	}
}


void Tree::FixDoubleRed(Node* node)
{
	if (node == root)
	{
		node->color = BLACK;
		return;
	}

	Node* parent = node->parent;
	Node* grandparent = parent->parent;
	Node* uncle = node->FindUncle();

	if (parent->color != BLACK)
	{
		if (uncle != nullptr && uncle->color == RED)
		{
			parent->color = BLACK;
			uncle->color = BLACK;
			grandparent->color = RED;
			FixDoubleRed(grandparent);
		}
		else
		{
			if (parent->IsOnLeft())
			{
				if (node->IsOnLeft()) { SwapColors(parent, grandparent); }
				else
				{
					RotateLeft(parent);
					SwapColors(node, grandparent);
				}
				
				RotateRight(grandparent);
			}
			else
			{
				if (node->IsOnLeft())
				{
					RotateRight(parent);
					SwapColors(node, grandparent);
				}
				else { SwapColors(parent, grandparent); }

				RotateLeft(grandparent);
			}
		}
	}
}


void Tree::RotateLeft(Node* node)
{
	Node *newParent = node->right;

	if (node == root) { root = newParent; }

	node->MoveDown(newParent);

	node->right = newParent->left;

	if (newParent->left != nullptr) { newParent->left->parent = node; }

	newParent->left = node;
}


void Tree::RotateRight(Node* node)
{
	Node *nParent = node->left;

	if (node == root) { root = nParent; }

	node->MoveDown(nParent);
	node->left = nParent->right;

	if (nParent->right != nullptr) { nParent->right->parent = node; }

	nParent->right = node;
}


void Tree::SwapColors(Node* node1, Node* node2)
{
	Color temp;
	temp = node1->color;
	node1->color = node2->color;
	node2->color = temp;
}


void Tree::SwapKeys(Node* node1, Node* node2)
{
	int temp;
	temp = node1->key;
	node1->key = node2->key;
	node2->key = temp;
}


void Tree::Transplant(Node* u, Node* v)
{
	if (u->parent == nullptr) { root = v; }
	else if (u == u->parent->left) { u->parent->left = v; }
	else { u->parent->right = v; }

	if (v != nullptr) { v->parent = u->parent; }
}


int Tree::InOrderTraversal(Node* node)
{
	if (node == nullptr) { return 0; }
	else
	{
		int left = InOrderTraversal(node->left);
		std::cout << node->key << " ";
		int right = InOrderTraversal(node->right);

		if (left >= right) { return left + 1; }
		else { return right + 1; }
	}
}


Node* Tree::GetMinimum(Node* node)
{
	while (node->left != nullptr) { node = node->left; }

	return node;
}


Node* Tree::Replace(Node *node)
{
	if (node->left != nullptr and node->right != nullptr) { return Successor(node->right); }	// Node has TWO CHILDREN
	else if (node->left != nullptr) { return node->left; }										// Node only has LEFT CHILD
	else if (node->right != nullptr) { return node->right; }									// Node only has RIGHT CHILD
	else { return nullptr; }																	// Node has NO CHILDREN
}


Node* Tree::Successor(Node* node)
{
	Node *temp = node;

	while (temp->left != nullptr) { temp = temp->left; }

	return temp;
}


#endif