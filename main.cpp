#include "trees.h"

void BuildBST(Tree&, std::vector<int>&);
void BuildRBT(Tree&, std::vector<int>&);
void DeleteBSTNodes(Tree&, std::vector<int>&);
void DeleteRBTNodes(Tree&, std::vector<int>&);

std::vector<int> BuildAdds(std::ifstream&, std::string);
std::vector<int> BuildDeletes(std::ifstream&);

int main()
{
	Tree bstRand;
	Tree bstBad;
	Tree rbtRand;
	Tree rbtBad;

	std::ifstream userData;

	std::vector<int> addKeysBad = BuildAdds(userData, "data/testBad.csv");
	std::vector<int> addKeysRand = BuildAdds(userData, "data/testRandom.csv");
	std::vector<int> deleteKeys = BuildDeletes(userData);


	std::cout << "Implementing with 'Random' data file..." << std::endl << std::endl;

	BuildBST(bstRand, addKeysRand);
	bstRand.PrintInOrder();
	std::cout << std::endl << "Tree Height: " << bstRand.GetHeight()
			  << std::endl << std::endl;

	DeleteBSTNodes(bstRand, deleteKeys);
	bstRand.PrintInOrder();
	std::cout << std::endl << "Tree Height: " << bstRand.GetHeight()
			  << std::endl << std::endl << std::endl << std::endl;

	BuildRBT(rbtRand, addKeysRand);
	rbtRand.PrintInOrder();
	std::cout << std::endl << "Tree Height: " << rbtRand.GetHeight()
			  << std::endl << std::endl;

	DeleteRBTNodes(rbtRand, deleteKeys);
	rbtRand.PrintInOrder();
	std::cout << std::endl << "Tree Height: " << rbtRand.GetHeight()
			  << std::endl << std::endl << std::endl << std::endl;
	

	std::cout << "Implementing with 'Bad' data file..." << std::endl << std::endl;

	BuildBST(bstBad, addKeysBad);
	bstBad.PrintInOrder();
	std::cout << std::endl << "Tree Height: " << bstBad.GetHeight()
			  << std::endl << std::endl;

	DeleteBSTNodes(bstBad, deleteKeys);
	bstBad.PrintInOrder();
	std::cout << std::endl << "Tree Height: " << bstBad.GetHeight()
			  << std::endl << std::endl << std::endl << std::endl;

	BuildRBT(rbtBad, addKeysBad);
	rbtBad.PrintInOrder();
	std::cout << std::endl << "Tree Height: " << rbtBad.GetHeight()
			  << std::endl << std::endl;

	DeleteRBTNodes(rbtBad, deleteKeys);
	rbtBad.PrintInOrder();
	std::cout << std::endl << "Tree Height: " << rbtBad.GetHeight()
			  << std::endl << std::endl;

	return 0;
}



void BuildBST(Tree& bst, std::vector<int>& keys)
{
	std::cout << "Inserting Nodes: " << std::endl;

	for (int index = 0; index < keys.size(); index++)
	{
		std::cout << keys[index] << " ";
		bst.InsertNode(keys[index]);
	}

	std::cout << std::endl << std::endl;
}

void BuildRBT(Tree& rbt, std::vector<int>& keys)
{
	std::cout << "Inserting Nodes: " << std::endl;

	for (int index = 0; index < keys.size(); index++)
	{
		std::cout << keys[index] << " ";
		rbt.InsertNodeRBT(keys[index]);
	}

	std::cout << std::endl << std::endl;
}


void DeleteBSTNodes(Tree& bst, std::vector<int>& keys)
{
	std::cout << "Deleting Nodes: " << std::endl;
	for(int index = 0; index < keys.size(); index++)
	{
		std::cout << keys[index] << " ";
		bst.DeleteNode(keys[index]);
	}

	std::cout << std::endl << std::endl;
}


void DeleteRBTNodes(Tree& rbt, std::vector<int>& keys)
{
	std::cout << "Deleting Nodes: " << std::endl;
	for(int index = 0; index < keys.size(); index++)
	{
		std::cout << keys[index] << " ";
		rbt.DeleteNodeRBT(keys[index]);
	}

	std::cout << std::endl << std::endl;
}


std::vector<int> BuildAdds(std::ifstream& data, std::string fileName)
{
	std::string line;
	std::vector<int> keys;

	data.open(fileName);

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