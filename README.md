# Project Instructions
## Due Date: 20231019

In this assignment will be focused on trees and things you can do with trees! In particular, you will be implementing a binary search tree data structure as well as a red-black tree data structure. For this assignment, you will be required to implement the insertion and deletion methods for each data structure, as well as any helper functions that may be needed for these methods. I’ve given you some test data that you can use to test your implementations. These files, sadly, just contain random integers for you to insert into and delete from your trees.

Finally, you will submit a writeup in Word or PDF that summarizes your results and all
code as a zip file. Submit the writeup (with attached source code) to the Canvas submission
locker before 11:59pm on the due date.

## Implement a Binary Search Tree (30 Points)
Here, you will implement a binary search tree. In this assignment, you will create a linked-representation binary search tree. This will likely involve the creation of a node object, and
potentially a tree object as well. Remember, node objects, at a minimum, contain a key field, pointers to its left and right child, and a pointer to its parent. In addition to the basic
node object, you will also implement methods for inserting and deleting from the tree. I have provided various datasets that you can use for testing. Those are testRandom, testBad,
and deleteNodes.csv.]

To evaluate whether these methods have executed successfully, implement an inorder traversal to print out the tree. If things were implemented correctly, keys should be printed in sorted order.
- You may not use a high-level function for implementing this structure. For example, you can’t use the max or min command in C++. If you have questions about whether a command is permissible, please ask and I will let you know.
- As mentioned at the start of class, all code should be written in C++.
- Please include instructions for how to compile and run your code in your writeup.
- Explain any implementation choices you had to make in the final report (such as how ties were broken).

## Implement a Red-Black Tree (30 points)
In this part of the assignment, we’re going to extend our binary search tree into a red-black tree so that it remains somewhat balanced. Implement a red-black tree as well as the methods needed to insert and delete from it. Test the red black tree using the data provided paired with an inorder traversal.
- Another reminder to not use high level functions to complete these algorithms. Feel free to reuse any code that you have already written, though (hint hint!).
- As mentioned at the start of class, all code should be written in C++.
- Please include instructions for how to compile and run your code in your writeup.
- Explain any implementation choices you had to make in the final report (such as how ties were broken).

## Calculate the Height of Each Tree (20 points)
In the final part of this assignment, we’re going to compare the heights of each of these trees on each dataset provided. For this, you’ll need to implement a method that can calculate the height of an arbitrary binary search tree or red-black tree. Hint: This can be done using an inorder traversal. You don’t need to do this, but I found it pretty easy to implement. Report the height of both the binary search tree and red-black tree after inserting the nodes in both test datasets, and after deleting the nodes in deleteNodes.csv from both datasets. Be sure to discuss these results in your writeup. Were they what you expected?

Details:
- Another reminder to not use high level functions to complete these algorithms.
- As mentioned at the start of class, all code should be written in C++.
- Please include instructions for how to compile and run your code in your writeup.
- Explain any implementation choices you had to make in the final report (such as how ties were broken).

## Writeup (20 points)
You will include a written report with your submission detailing important details about your implementation, as well as the results of any analyses requested in the assignment. The report must be complete and clear. A few key points to remember:
- Complete: the report does not need to be long, but should include everything that was requested.
- Clear: your grammar should be correct, your graphics should be clearly labeled and easy to read.
- Concise: I sometimes print out reports to ease grading, don’t make figures larger than they need to be. Graphics and text should be large enough to get the point across, but not much larger.
- Credit (partial): if you are not able to get something working, or unable to generate a particular figure, explain why in your report. If you don’t explain, I can’t give partial credit.

# Changelog
## 20231016
1) Initialized Project.
2) Created main.cpp file and imported project instructions as README.txt.