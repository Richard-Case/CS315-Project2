#include "trees.h"

void BuildBST(BST&, std::vector<int>&);
void DeleteBSTNodes(BST&, std::vector<int>&);
void BuildRBT(RBT&, std::vector<int>&);
// void DeleteRBTNodes(RBT&, std::vector<int>&);
std::vector<int> BuildAdds(std::ifstream&);
std::vector<int> BuildDeletes(std::ifstream&);


int main()
{
	BST bst;
	RBT rbt;
	std::ifstream userData;
	
	std::vector<int> addKeys = BuildAdds(userData);
	BuildBST(bst, addKeys);
	
	std::cout << std::endl << std::endl
		<< "BST before deleting any nodes:" << std::endl;
	bst.InOrderPrint(bst.GetRoot());

	std::cout << std::endl << std::endl;
	
	std::vector<int> deleteKeys = BuildDeletes(userData);
	DeleteBSTNodes(bst, deleteKeys);

	std::cout << std::endl << std::endl
		<< "BST after deleting nodes:" << std::endl;
	bst.InOrderPrint(bst.GetRoot());

	BuildRBT(rbt, addKeys);

	std::cout << std::endl << std::endl
		<< "RBT before deleting any nodes:" << std::endl;
	rbt.InOrderPrint(rbt.GetRoot());

	// Implement a Red-Black Search Tree (30 Points).
		// Implement insertion and deletion methods...including any necessary helper function.
		
		// Extend the binary search tree into a red-black tree so that it remains somewhat balanced.
		
		// Test the red black tree using the data provided paired with an inorder traversal.


	// Calculate the height of each tree (20 Points).
		// Compare the heights of each of these trees on each dataset provided.
		
		// Implement a method which can calculate the height of an arbitrary Binary Search Tree or Red-Black Tree.

		/**** HINT: This can be done using an inorder traversal. You don’t need to do this, but I found it pretty easy to implement. ****/
		
		// Report the height of both...
			// - After inserting the nodes in each dataset
			// - After deleting the nodes in deleteNodes.csv from each dataset.
			
		// Be sure to discuss these results in your writeup. Were they what you expected?

	return 0;
}


void BuildBST(BST& bst, std::vector<int>& keys)
{
	// Convert array of node keys into a Binary Search Tree...
	for(int index : keys)
	{
		Node *newNode = new Node;
		bst.NewNode(newNode, keys[index]);
		bst.InsertNode(newNode);
	}
}


void BuildRBT(RBT& rbt, std::vector<int>& keys)
{
	// Convert array of node keys into a Binary Search Tree...
	for(int index : keys)
	{
		Node *newNode = new Node;
		rbt.NewNodeRB(newNode, keys[index]);
		rbt.InsertNodeRB(newNode);
	}
}


void DeleteBSTNodes(BST& bst, std::vector<int>& keys)
{
	for(int index : keys)
	{
		Node* nodeToDelete = bst.Search(bst.GetRoot(), index);
		std::cout << "Deleting NODE: " << nodeToDelete->key << std::endl;

		bst.DeleteNode(bst.GetRoot(), index);
	}
}


std::vector<int> BuildAdds(std::ifstream& data)
{
	std::string line;
	std::vector<int> keys;

	data.open("./data/testrandom.csv");

	while (std::getline(data, line))
    {
		std::istringstream iss(line);
		int n;
		while(iss >> n) { keys.push_back(n); }
    }
	data.close();

	return keys;
}


std::vector<int> BuildDeletes(std::ifstream& data)
{
	std::string line;
	std::vector<int> keys;

	data.open("./data/deleteNodes.csv");

	while (std::getline(data, line))
    {
		std::istringstream iss(line);
		int n;
		while(iss >> n) { keys.push_back(n); }
    }
	data.close();

	return keys;	
}