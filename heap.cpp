/*
C++ Data Structures: Heap Project
by Akhil Baidya

Date of Submission: 2/22/2024 

Notes: This program creates a max heap that can store a max of 100 integers. The user can ADD to the heap, DELETE from it, DELETE_ALL, PRINT the heap, and QUIT the program.

1. ADD: After inputting this command, the user will be prompted to manually input values or input values into the heap from a file. In the manual input, the user can input up to 100 integers (must be non-negative, ideally a range between 1 and 1000 inclusive for each number) into the heap. In the file input, the user inputs the name of a file whose numbers (same criteria, up to 100 of such numbers) are put into the heap.

2. DELETE: After inputting this command, the root (largest element of the heap) will be deleted from the heap and printed out.

3. DELETE_ALL: In this command, delete is called repeatedly until the heap is empty (a value of -5 for a spot in the heap represents emptiness).

4. PRINT: After inputting this command, the heap is printed out in the form of a binary tree (with parents larger than their children), which is sideways.  

5. QUIT: After inputting this command, the program will end.


Overall Credits (resources referred to to understand what a max heap and binary tree are):

Referred to Wikipedia, as linked on Canvas, and the site's articles on heap (https://en.wikipedia.org/wiki/Heap_(data_structure)) and on binary tree (https://en.wikipedia.org/wiki/Binary_tree). This helped me visualize what I was creating during the assignment. 
*/

#include <iostream>
#include <cstring>
#include <fstream>

using namespace std;

//FUNCTION PROTOTYPES:

//The basic commands:
void add(int, int* &, int &);
void del(int* &, int &);
void delAll(int* &, int &);
void print(int* &, int, int);

//The different methods of adding:
void manualInput(int* &, int &);
void fileInput(int* & ,int &);

//Functions to reorder the heap/tree:
void checkParent(int, int* &);
void checkChild(int, int* &);


//MAIN FUNCTION (in this function the user will input their commands to edit the max heap or display the heap):
int main() {

  //Variables:
  int mxh[100]; //this will be the max heap
  int* mxhPnt = mxh; //setting a pointer to the array (for passing by reference later on)
  int indexL = 0; //"Index Last": the index of the bottom-right most element in the tree representing the current max heap
  bool editing = true; //indicates that the user is editing the max heap
  char answer[15]; //stores a user's command
  
  for (int i = 0; i < 100; i++) { //first empty the max heap (empty spots contain a value of -5)
  mxh[i] = -5;
  }

  cout << "Max heap ready for editing:" << endl;

  while (editing) {
    cout << "Would you like to ADD to the max heap, DELETE the root, DELETE_ALL, PRINT the heap, or QUIT this program?" << endl;
    cin >> answer;
    
    if (!strcmp(answer, "ADD")) { //If the user wants to add to the heap:

      char inputType[15];

      cout << "Would you like to add manually (MAN) or by file (FILE)?" << endl;
      cin >> inputType;

      if (!strcmp(inputType, "MAN")) {
	manualInput(mxhPnt, indexL); //input manually
      }

      else if (!strcmp(inputType, "FILE")) {
	fileInput(mxhPnt, indexL); //input by file
      }

      else {
	cout << "Did not understand (please input capitalized commands)" << endl;
      }
    }

    else if (!strcmp(answer, "DELETE")) { //If the user wants to delete the heap's root:
      del(mxhPnt, indexL); //delete
    }

    else if (!strcmp(answer, "DELETE_ALL")) { //If the user wants to delete all of the heap:
      delAll(mxhPnt, indexL); //delete all
    }

    else if (!strcmp(answer, "PRINT")) { //If the user wants to print the heap:
      print(mxhPnt, 0, 0); //print it as a tree
    }
    
    else if (!strcmp(answer, "QUIT")) { //If the user wants to quit the program:
      cout << "Quitting..." << endl;
      editing = false; //end the while loop
    }

    else {
      cout << "Did not understand (please input capitalized commands)" << endl;
    }
  }
  return 0;
}

//ADD FUNCTION:
//This function takes in a value to be added to the array and adds it to the next available spot (increasing a variable indexL representing the index of the bottom-right most element of the tree by one). It then runs the checkParent function to recursively check if the parents of this added value are bigger than it; otherwise, the added value is swapped into an earlier generation/row in the tree).    
void add(int val, int* &array, int &indexL) {

  int i = 0;

  while ((array)[i] != -5) {
    i++; //finds the index of the next open spot (as soon as there is a -5 in the array)
  }

  array[i] = val; //the next open spot is given to the input value
  indexL = i; //this is also the new "last index"
  checkParent(i, array); //reorder the max heap such that every child is smaller than the parent
}


//PRINT FUNCTION:
/*This function recurses through the array and prints out the max heap in the form of a tree (sideways). The idea of using recursion to go down the right branch of the tree, increasing a variable called "count" to increase the number of tabs to add when printing (to represent the depth of the tree) was suggested by Mr. Galbraith. Additionally suggested by Mr. Galbraith was to print the current value when the program no longer can go down right (then the code will go back to the parent and print it out if the program can't go down right, fulfilling the "print current value" of the previous case in the recursion down right), and then recursively going down left. */
void print(int* &array, int index, int count) {
  
  if (array[(2*index)+2] != -5) {
    print(array, (2*index) + 2, count+1); //go down the right branch recursively until there is no way to go down right (empty right child), recording each depth (by increasing count)
  }

  //Actually printing out value in the heap:
  for (int i = 0; i < count; i++) {//tab by the count (represents the depth of the value in the tree that will be printed)
    cout << "\t";
  }
  if (array[index] != -5) {
    cout << array[index] << endl; //print out the current value if it is not empty (not -5)
  }

  if (array[(2*index)+1] != -5) {
    print(array, (2*index) + 1, count+1); //similarly, recursively go down left
  }
  return;
}


//DELETE FUNCTION:
//This function deletes the root value from the heap. It prints the root value out and places the bottom-right most element from the tree representation of the max heap in its position (shrinking the table size by 1). Another check function is used here to compare the new root to its children, to make sure it is bigger than its children (to format the max heap correctly). 
void del(int* &array, int &indexL) {
  cout << "Here's the deleted root value: " << array[0] << endl; //print out root
  array[0] = array[indexL]; //replace root with end value
  array[indexL] = -5; //end value is gone
  indexL = indexL - 1; //table size shrunk by 1
  checkChild(0, array); //reformat the tree by checking if the children of the root are smaller than it (otherwise, swap and check again)
}


//DELETE_ALL FUNCTION:
//This function calls the delete function repeatedly, to delete all the values from the max heap.
void delAll(int* &array, int &indexL) {
  for (int i = 0; i < 100; i++) { //for the max number of elements in the heap:
    if (array[0] != -5) { //if the array is not already empty (with an empty, -5, root)
      del(array, indexL); //delete the root repeatedly
    }
  }
}


//MANUAL INPUT FUNCTION:
//This function performs a while loop prompting the user to input numbers to add to the max heap. These numbers are added to the heap ONE AT A TIME (and a max of 100 numbers can be added). 
void manualInput(int* &array, int &indexL) {
  bool adding = true; //indicates if the user is still adding numbers to the heap
  int count = 0; //number of times the user added a number
  char answer; //will store whether user wants to continue adding
  int toAdd = 0; //the number to add
  
  while (adding && count < 100) { //stop adding after 100 elements added

    //Continue adding numbers:
    cout << "Would you like to add a value to the max heap? y/n" << endl;
    cout << "(max of 100 numbers can be added - numbers should be between 1 - 1000)" << endl;
    cin >> answer;

    if (answer == 'y') { //Add a number specified by the user:
      cout << "Type the number you wish to add" << endl;
      cin >> toAdd;
      add(toAdd, array, indexL);
    }

    else { //If the user does not want to continue adding, end the while loop.
      adding = false;
    }
  }
  cout << "Finished adding numbers to max heap" << endl;
}


//FILE INPUT FUNCTION:
//Reads numbers from a file, one at a time, into the max heap. The numbers in the file are assumed to be seperated out by a single space " "
void fileInput(int* &array, int &indexL) {
  char answer[50];
  cout << "What is the name of the file you would like to read into the max heap? " << endl;
  cin >> answer;

  //Referenced this source from the Udacity team on ways to read in files: https://www.udacity.com/blog/2021/05/how-to-read-from-a-file-in-cpp.html. From the source, I learned that I can refer to the file using a variable with the class "ifstream" with a constructor that takes in the name of the file.
  
  ifstream theFile(answer);
  
  while(theFile) { //The source also noted how one can loop through the file using the ifstream object itself as a condition
    
    int toAdd = -5; //what we're adding is empty first (because the theFile >> toAdd seems to read in the return as a number too)
    theFile >> toAdd; //using theFile >> since, as the Udacity source mentions, it reads until a space " " 
    if (toAdd != -5) {
      add(toAdd, array, indexL); //add non-empty (not -5) numbers
    }
  }
  cout << "Finished adding numbers to max heap" << endl;
}

//CHECK PARENT FUNCTION:
//This function checks if the current value (at the index specified) has parents with a greater value than it. Otherwise, if the parent is smaller, it swaps with the position of the parent. This is done repeatedly through recursion.
void checkParent(int index, int* &array) {
  int pInd = 0; //the parent's index
  
  if (index%2 == 0) {
    pInd = (index - 1)/2; //finding the parent index if the input value is on its right branch
  }

  else if (index%2 == 1) {
    pInd = (index)/2; //finding the parent index if the input value is on its left branch
  }

  if (pInd < 0) { //If the parent index is less than 0 (meaning the index currently being looked at is the root), don't swap anything
    return;
  }

  else if (array[pInd] >= array[index]) { //If there is no need for a swap (the parent is bigger than or equal to the child), don't swap anything
    return;
  }

  if (array[pInd] < array[index]) { //If the parent is smaller than its child:

    //Swap them:
    int temp = array[pInd]; //store the value of the parent
    array[pInd] = array[index]; //the parent value becomes the child's value
    array[index] = temp; //the child's value becomes the parent's old value

    //Now recurse and run this check again for the same value but at its new position:
    index = pInd; 
    checkParent(index, array);
  }
  return;
}


//CHECK CHILD FUNCTION:
//This function checks if the current valye (at the index specified) has children with a smaller value than it. Otherwise, if the children are bigger, it swaps with the position of the largest child (or the only child that is bigger than it). This is done repeatedly through recursion.
void checkChild(int index, int* &array) {
  //Indices of the left child (1) and the right child (2):
  int child1 = (2 * index) + 1;
  int child2 = (2 * index) + 2;

  if (array[child1] != -5 && array[child2] != -5) { //If the children are not empty:

    if (array[child1] > array[index] || array[child2] > array[index]) { //If at least one of them is larger than the parent:

      if (array[child1] < array[child2]) { //Swap with child 2 if it is bigger than the value of child 1 (it will either be the only one bigger than the parent or the bigger child that is bigger than the parent)
	int temp = array[child2];
	array[child2] = array[index];
	array[index] = temp; //Swap values
	index = child2; //Set the index of the current value to the new position
      }

      else { //Otherwise, swap with the child 1 (when both children are bigger than the parent and equal in value, when both are bigger and the first child is the largest one, or when the first child is the only one larger than the parent)
	int temp = array[child1];
	array[child1] = array[index];
	array[index] = temp; //Swap
	index = child1;
      } 
    }
    else {
      return;
    }
  }

  else if (array[child1] != -5 && array[child1] > array[index]) { //In the case that child 1 is bigger than the parent and child 2 is empty:
    int temp = array[child1];
    array[child1] = array[index];
    array[index] = temp; //Swap
    index = child1;
  }

  else if (array[child2] != -5 && array[child2] > array[index]) { //In the case that child 2 is bigger than the parent and child 1 is empty:
    int temp = array[child2];
    array[child2] = array[index];
    array[index] = temp; //Swap
    index = child2;
  }

  else {
    return; //There are only empty spots as children
  }
  checkChild(index, array); //Check the value again at its new index!
  return;
}
