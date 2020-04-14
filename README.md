# Data-Structure
3rd Semester DS Assignments

Batch: Hx

Prof: Dr. Indrajeet Banerjee

Assignment 1
____________
1. Write a method duplicate Stack that returns a new stack containing the same
elements and in the same order as the stack specified in the parameter. The
method should create a new stack and fill it with the same data elements as the
given stack. (You do not need to duplicate the contents of the elements.).
Before the method finishes, it must restore the contents of the original stack to
its original state (same contents in the same order).

2. Write a program to convert an infix expression of integers into its equivalent
postfix notation-using stack ADT.

3. Write a program to evaluate a postfix and prefix expression using a stack data
structure.

4. Write a program to implement three stacks ADT using one array.

5. Use your stack to check whether a String is a Palindrome or not.

6. Sort the given set of elements present in three stack data structures and put
them in a single stack, without using any other variable.

Assignment 2
____________
1. Write a C Program to implement Circular Queue in an array.

2. Write a program to implement a queue using two stacks of data structure.

3. Write a program to implement priority scheduling scheme using a circular 
queue. The data elements will be the student's name, ID, CGPA, Departments, and 
Semester. In priority scheduling higher priority elements selected first. 
Here the CGPA will be considered as the priority of students

Assignment 3
____________

1. Design a program to simulate “Movie-Maker”. It must have the following functionalities: - >Allow the users to add images to the slide show.

>Allow the users to delete any image from the list.

>Allow the users to start the slide show. There must be a comfortable time gap between two consecutive images.

(The path of individual images are stored in a singly circular linked list. The slide show can start from any slide.)

2. Design a program to simulate a “Photo-Viewer” having the following features: - >The path of the images are stored in a doubly circular linked list.

>Allow the users to add an image at the current location.

>Allow the user to delete an image at the current location.

>Allow the user to navigate the images using any two buttons of his/her/ choice denoting the actions-previous and next.

(The pathnames used in the linked list may also be stored in a file for later use.)

3. Write a program to count the number of elements in a circular link list. Write another function which will search and delete an element from the above circular linked list.


4. Write a program to evaluate a postfix and prefix expression using a stack data structure. Your program has to consider two or three-digit numbers (eg. 112 34 5 * + ) Implement the stack using Linked List ADT.


5. Write a program which will take elements from the console and store them in a single linked list in sorted order. The linked list must not contain any duplicate element.

6. Write a program to implement queue ADT using the doubly circular link list.

7. Write a program to add two polynomial equation where the data are supposed to store in a doubly-linked list

Assignment 4
------------

1. Write a program to implement insertion and deletion of node in a binary search tree. Write a function
to implement in-order, pre-order and post-order traversal of binary search tree using recursion.

2. Write a program to implement BST using three array (data, left address, right address). Also write
an in-order traversal of this binary search tree using stack.

3. Write a C Program to implement the Max Heap and then delete all the elements from the tree so the
deleted elements are in sorted order.

4. Write a C program to implements Huffman Coding
I. Build a Huffman Tree from input characters. (Ask user about the characters and their number of
appearance)
II. Traverse the Huffman Tree and assign codes to characters.

5. Implement a ternary tree where each node may contain two key value in sorted form. Each node
may have maximum three children. Data insertion rule for the tree is as search tree i.e. data in leftmost
child is less than the data of first key. Data in middle child is greater that the first key but less than
second key. Data in third child is greater than the data in second key.

6. Given a Binary Tree where each node has following structure, write a function to populate next
pointer for all nodes. The next pointer for every node should be set to point to inorder successor.

7. Write a program to convert a given in-order expression to pre-order and post-order form using
Expression tree.
struct node
{
int data;
struct node* left;
struct node* right;
struct node* next;
