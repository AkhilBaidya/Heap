#include <iostream>
#include <cstring>

using namespace std;

//So there's no need for pointers... (. _ .)

//Function Prototypes:
void add(int, int* &);
void check(int, int* &);
void del(int* &);
void delAll(int* &);
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
  del(mxhPnt);
  print(mxhPnt, 0,0);
  del(mxhPnt);
  print(mxhPnt, 0,0);
  delAll(mxhPnt);
  print(mxhPnt, 0,0);
 
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

  if (array[index] != -5) {//just don't want to print out empty values
  cout << array[index] << endl;
  }
  
  if (array[(2*index)+2] != -5) {
    //count = count + 1;
    print(array, (2*index) + 2, count+1); //go down left
  }

  //cout << "printing this one with count" << count << endl;
   
  return;
}

void del(int* &array) {

  cout << "Here's the deleted root value: " << array[0] << endl;
  array[0] = -5; //root is gone!
  
  for (int i = 1; i < 100; i++) {
    array[i-1] = array[i]; //move everything down 1 to fill the empty root!
  }

  for (int i = 0; i < 100; i++) {
    check(i, array); //need to make sure the array is organized
  }
}

void delAll(int* &array) {

  for (int i = 0; i < 100; i++) {
    if (array[0] != -5) { //if the array is not already empty
      del(array);
    }
  }
}

//Manual Input function (reads values from cin and calls "add" for each one):
void manualInput(int* array) {
}
