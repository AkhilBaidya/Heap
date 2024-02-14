#include <iostream>
#include <cstring>

using namespace std;

//So there's no need for pointers... (. _ .)

//Function Prototypes:
void add(int, int* &);
void check(int, int* &);
void manualInput(int* &);

//Main function (this is where the user will input values):
int main() {
  int mxh[100]; //this will be the max heap
  int* mxhPnt = mxh;
  
  for (int i = 0; i < 100; i++) { //empty it
    bob[i] = NULL;
  }
  
  return 0;
}

//Add function (takes in a node and the current array and adds the node in the array according to the ordering of a max heap):
void add(int val, int* &array) {

  int i = 0;

  while ((*array)[i] != NULL) {
    i++;
  }

  (*array)[i] = val; //the next open spot is given to the input value
  check(i, array); //reorder max heap such that every child is smaller than the parent
  
  /*
  node* current = array[0];

  if (current == NULL) { //there's nothing in the max heap, so just add the input
    array[0] = val;
  }

  else {

    while (current != NULL) {

      if (current -> child1 == NULL) {
	child1 = val; //if the next child 1 is empty, just add the input there
	child1 -> parent = current;//the parent was the current node
      }

      else if (current -> child2 == NULL) {
	child2 = val; //otherwise, if the next child 2 is empty, just add the input there
	child2 -> parent = current; //the parent was the current node
      }

      else { //else move down the binary tree

	int myval = val -> value;
	int lefval = current -> child1 -> value;
	int rightval = current -> child2 -> value;
	
	if (leftval > myval || leftval == myval  && rightval !> myval || leftval < myval && rightval < myval) { //going down the left takes precedence

	  current = current -> child1;
	}

	else if (leftval == myval && rightval > myval || leftval < myval && rightval !< myval) { //otherwise go right

	  current = current -> child2;
	}

	else {

	  cout << "Error when going down binary tree" << endl;
	  
	}
	
      }
    }
  }
  */
}

//Check function (makes sure that the parent of the current node has a larger value than it; otherwise, it will swap the nodes)
void check(int index, int &array) {
  int pInd = 0;
  
  if (index%2 == 0) {
    pInd = (index - 1)/2; //the parent if the input value is on the right branch
  }

  else if (index%2 == 1) {
    pInd = (index)/2; //the parent if the input value is on the left branch
  }

  if (pInd < 0) { //looking at the root
    return;
  }

  else if ((*array)[pInd] >= (*array)[index]) {
    return;
  }

  if ((*array)[pInd] < (*array)[index]) {

    //then swap parent and child:
    
    int temp = (*array)[pInd];

    (*array)[pInd] = (*array)[index];
    (*array)[index] = temp;

    delete temp;

    //now recurse and check again for the same value but at its new position:
    index = pInd;
    check(index, array);
  }
  /*
  //Get the parties involved:
  node* valC1 = val -> child1;
  node* valC2 = val -> child2;
  node* par = val -> parent;
  node* sib = par -> child1;

  if (sib == val) {
    sib = par -> child2;
  }  
  */
  return;
}

//Manual Input function (reads values from cin and calls "add" for each one):
void manualInput(node* array[100]) {
}
