#include <iostream>
#include <cstring>

using namespace std;

//So there's no need for pointers... (. _ .)

//Function Prototypes:
void add(int, int*);
void check(int, int*);
void manualInput(int*);

//Main function (this is where the user will input values):
int main() {
  int bob[100]; //this will be the max heap
  
  for (int i = 0; i < 100; i++) { //empty it
    bob[i] = NULL;
  }
  
  return 0;
}

//Add function (takes in a node and the current array and adds the node in the array according to the ordering of a max heap):
void add(int val, int array[100]) {

  int i = 0;

  while (array[i] != NULL) {
    i++;
  }

  array[i] = val;
  check(i, array);
  
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
void check(node* val, node* array[100]) {

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
}

//Manual Input function (reads values from cin and calls "add" for each one):
void manualInput(node* array[100]) {
}
