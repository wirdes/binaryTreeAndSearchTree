Binary Tree And Binary Search Tree
-------------

# 1. Binary Tree Data Structure
A tree structure with a maximum of two Child nodes on each node is called a Binary tree data structure. This adding data to the tree is done in two ways:
- Adding from the right. 
- Adding from the left. 

These two methods of addition both is following the rule.
- If there is no data on the right (or left) of the node to which data will be added to the right (or left), the data will be added directly.
- If there is data on the right (or left) of the node to which data will be added, that data will be added to the right (or left) of the new data and the new tree will be added to the right (or left) of the node to be added.
Searching in binary treee data structure is done with two basic training. These are Deep first search (DFS) and Extensive first search (BFS). In the course for the first of these, there are also three approach methods and for the second, the approach method using the queue data type is the nurse. This assignment is given below.
Data structure and functions to be created
- A data structure for implementing the Binary Tree
- A Function that adds to the tree from the right according to the rules given in the lesson. 3. A function that adds to the tree from the left according to the rules given in the lesson. 4. Pre-order Given in Lecture With DFS approach, all elements of the tree are software functions. 5. A software function that prints the whole tree sequentially using the DFS approach. 6. Given in the course, it is a function to program all the elements of the tree with the Post-order DFS approach. 7. Desrte A function that outputs all elements of the tree with the given BFS approach.
# 2.Index Table
Binary search tree data development design is required for an index table that sorts the sample grades from the highest to the same, and the student number is enlarged by using the student number and lecture notes given in the other tables.

  Index   StNumber    Note

![](https://raw.githubusercontent.com/wirdes/binaryTreeAndSearchTree/main/%C4%B1ndexTable.png?token=AK6HHKXCFBWQNV52WDB2APS75CLLG)

- Add function: This function saves the index by finding the appropriate place in the tree for the student number and the index of the course grade in the given table.
- Delete function: This function removes the given index from the index table (ie Binary search tree).
- Change function: Updates the order of the student whose grade is changed in the index table. 
- Print: Prints the students who got a higher grade than a given course grade on the screen in the order in the index table.
You are expected to upload all the codes that you will create within the scope of the homework as a single c file.-
