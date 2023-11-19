# Project Instructions
### Due Date: 20231019

## Project Outline:
In this assignment we will be focused on trees and things you can do with them!
In particular, you will be implementing a binary search tree data structure as well as a red-black tree data structure. You are required to implement the insertion and deletion methods for each data structure, as well as any helper functions that may be required by these methods.

Lastly, submit a writeup and all code as a zip file.

## Implement a Binary Search Tree (30 Points)
Create a linked-representation Binary Search Tree.

This will likely involve:
- The creation of a node object
- A tree object

In addition to the basic node object, implement methods for inserting and deleting from the tree.


## Implement a Red-Black Tree (30 points)
Extend the Binary Search Tree into a Red-Black Tree so that it remains somewhat balanced. In addition to the basic node object, implement methods for inserting and deleting from the tree.

- Test the red black tree using the data provided paired with an inorder traversal.


## Calculate the Height of Each Tree (20 points)
Compare the heights of each of these trees on each dataset provided.

Implement a method which can calculate the height of an arbitrary Binary Search Tree or Red-Black Tree.

Report the height of each...
1) After inserting the nodes in both test datasets
2) After deleting the nodes in deleteNodes.csv from both datasets.

- Be sure to discuss these results in your writeup. Were they what you expected?


## Writeup (20 points)
Include a written report of any important details about your implementation--as well as the results of any analyses requested in the assignment--with your code submission. This writeup must be:

- Complete: The report does not need to be long, but should include everything that was requested.
- Clear: Correct grammar should be used and any graphics should be clearly labeled and easy to read.
- Concise: Print out reports to ease grading, don’t make figures larger than they need to be. Graphics and text should be large enough to get the point across, but not much larger.
- Credit (partial): if you are not able to get something working, or unable to generate a particular figure, explain why in your report. If you don’t explain, I can’t give partial credit.

## Rules / Expectations
1) You may not use a high-level function for implementing this structure. For example, you can’t use the max or min command in C++. If you have questions about whether a command is permissible, please ask and I will let you know.
2) All code should be written in C++.
3) Include instructions for how to compile and run your code in your writeup.
4) Explain any implementation choices you had to make in the writeup (such as how ties were broken).


# Changelog
## 20231016
1) Initialized Project.
2) Created main.cpp file and imported project instructions as README.txt.
3) Converted instructions into code comments and pseudocode.
4) Created the initial writeup.txt file.

## 20231027
1) Initialized header and implementation files.
2) Set up member method declarations and definitions for Binary Search Trees.
	- Currently working with hardcoded values.
3) Declared member methods for Red-Black Trees.

## 20231031
1) Began writing member method definitions for Red-Black Trees.

## 20231105
1) Refactored project and rewrote BST class for readability.
	- BST methods fully functional.
2) Began writing RBT class, to inherit from BST class.
	- Segmentation Fault ocurring with RBT Fixup code.

## 20231106
1) Refactored main.cpp for readability.

## 20231107
1) Refactored BST and RBT to be a single "Tree" class.
	- Unable to resolve segmentation fault.
	- Attempting to narrow down possible causes.

## 20231110
1) Created a series of output statements to act as checkpoints within the InsertNodeFixup() method.
	- Was able to determine that the problem lie in attempting to access non-existent nodes.
	- Resolved by adding an existence checks to most of the if statements.
2) Began coding DeleteNodeRB() method.
	- More segmentation fault errors. A lot more.

## 20231117
After completely rewriting the program four times using the pseudocode provided in class, and continually encountering the same segmentation faults, I've decided to re-do the entire program using the explanations provided here: https://www.geeksforgeeks.org/deletion-in-red-black-tree/?ref=lbp#

1) Beginning to refactor code.

## 20231118
1) Finished refactoring code.
2) Converted to work with provided data files, rather than "magic" numbers.
	- Program appears to compile and run correctly.
3) Attempting to add code to calculate the height of the RBT.
	- Finished with this.
4) Lastly, I need to re-integrate the original BST into this program.
	- Finished.

### It appears as though everything is functioning as intended.

5) Cleaned up the code for submission.