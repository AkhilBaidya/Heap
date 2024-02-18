#include <iostream>
#include <cstring>

using namespace std;

//So there's no need for pointers... (. _ .)

//Function Prototypes:
void add(int, int* &);
void check(int, int* &);
void print(int* &, int, int);
void manualInput(int* &);

//Main function (this is where the user will input values):
int main() {
  int mxh[100]; //this will be the max heap
  int* mxhPnt = mxh; //pointer so I can pass by reference and edit this array just to be sure (will take out later)
  
  for (int i = 0; i < 100; i++) { //empty it
  mxh[i] = -5;
  }

  add(5, mxhPnt);
  add(3, mxhPnt);
  add(4,mxhPnt);
  //print(mxhPnt, 0, 0);
  add(6, mxhPnt);
  add(7, mxhPnt);
  add(2, mxhPnt);
  add(10, mxhPnt);
  add(3, mxhPnt);
  print(mxhPnt, 0, 0);

  cout << "now the actual array" << endl;
  for (int i = 0; i<100; i++) {
    if (mxhPnt[i] != -5) {
    cout << mxhPnt[i] << "," << endl; //great news my adding works!
    }
  }
  return 0;
}

//Add function (takes in a node and the current array and adds the node in the array according to the ordering of a max heap):
void add(int val, int* &array) {

  int i = 0;

  while ((array)[i] != -5) {
    i++;
  }

  array[i] = val; //the next open spot is given to the input value
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
void check(int index, int* &array) {
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

  else if (array[pInd] >= array[index]) {
    return;
  }

  if (array[pInd] < array[index]) {

    //then swap parent and child:
    
    int temp = array[pInd];

    array[pInd] = array[index];
    array[index] = temp;

    //now recurse and check again for the same value but at its new position:
    index = pInd;
    check(index, array);
  }
  return;
}

//Print function (prints out the heap as a tree!!!)
void print(int* &array, int index, int count) {

  if (array[(2*index)+1] != -5) {
    //count = count + 1;
    print(array, (2*index) + 1, count+1); //count to read depth, suggested by Mr. Galbraith (also going by his method of going down one branch first)
  }

  for (int i = 0; i < count; i++) {//tab by the count
    cout << "\t";
  }
  cout << array[index] << endl;
  
  if (array[(2*index)+2] != -5) {
    //count = count + 1;
    print(array, (2*index) + 2, count+1); //go down left
  }

  //cout << "printing this one with count" << count << endl;
   
  return;
  
  /*
  cout << "going to print" << endl;
  int oldGen = 1;
  int gen = 1; //generation # for some index in array (get the odd index of each generation and add 3 div 2)

  char* temp; //will store each generation to print
  int skip = 1;

  cout << array[0];
  
  for (int i = 1; i < 100; i += skip) {

    cout << "looking at " << i << endl;

    if (i%2 == 1) {
	gen = (i+3)/2;
     }

      else if (i%2 == 0) {
	gen = (i+2)/2;
      }

    cout << "got generations" << endl;

      for (int j = i; j < i+skip; j++) { //for the next n elements
     
	temp = temp + array[j];
	cout << "added to temp" << endl;
	
	int num = 3 * (2 ^ (6 - gen));


	for (int k = 0; k < num; k++) {
	  temp = temp + '\n';
	  cout << "added space" << endl;
	}
     
      }

    cout << temp;
	//for (int i = 0; i < 100; i++) {
	//temp[i] = ;
	//}
	//temp = NULL;
	//cout << "set to null" << endl;
	
    skip = skip * 2; //go by powers of 2
      
      //this would result in very wide trees (the #of spaces in the first gen will be fixed at around 48

      }*/
}


//Manual Input function (reads values from cin and calls "add" for each one):
void manualInput(int* array) {
}
