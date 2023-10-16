int main(int argc, char const *argv[])
{
	// Implement a Binary Search Tree (30 Points).
		// Implement insertion and deletion methods...including any necessary helper function.
		
		// Create a linked-representation binary search tree.
			// This will likely involve:
			// - The creation of a node object (and potentially a tree object).
			
			/*
				Remember that node objects--at a minimum--contain a key field, pointers to its left and right child, and a pointer to its parent
			*/
			
			// In addition to the basic node object:
				// Implement methods for inserting and deleting from the tree.
				
				// I have provided various datasets that you can use for testing.
				// Those are testRandom, testBad, and deleteNodes.csv.

			// Evaluate whether these methods have executed successfully...
				// Implement an inorder traversal to print out the tree.
					// - Keys should be printed in sorted order.
					
			/****
				You may *NOT* use high-level functions for implementing this structure.
				* For example, you cannot use the max or min command in C++.
				* If you have questions about whether a command is permissible, please ask and I will let you know.
			****/


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