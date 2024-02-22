#include <iostream>
#include <cstring>
#include <fstream>

using namespace std;

//Function Prototypes:
void add(int, int* &, int &);
void check(int, int* &, int &);
void del(int* &, int &, int &);
void delAll(int* &);
void print(int* &, int, int);
void manualInput(int* &);
void fileInput(int* &);
void checkChild(int &, int* &);

//Main function (this is where the user will input values):
int main() {

  int size = 100; //initially
  int mxh[size]; //this will be the max heap
  int* mxhPnt = mxh; //pointer so I can pass by reference and edit this array just to be sure (will take out later)
  int indexL = 0; //last index added


  
  for (int i = 0; i < 100; i++) { //empty it
  mxh[i] = -5;
  }

  fileInput(mxhPnt);
  print(mxhPnt, 0, 0);
  return 0;
}

//Add function (takes in a node and the current array and adds the node in the array according to the ordering of a max heap):
void add(int val, int* &array, int &indexL) {

  int i = 0;

  while ((array)[i] != -5) {
    i++;
  }

  array[i] = val; //the next open spot is given to the input value
  check(i, array, indexL); //reorder max heap such that every child is smaller than the parent
}

//Check function (makes sure that the parent of the current node has a larger value than it; otherwise, it will swap the nodes)
void check(int index, int* &array, int &indexL) {
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
    indexL = index; //the final spot 
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

void del(int* &array, int &size, int &indexL) {

  cout << "Here's the deleted root value: " << array[0] << endl;
  array[0] = -5; //root is gone

  int* oldArray = array;

  array = new int[size-1];
  array[0] = oldArray[indexL];
    
  for (int i = 1; i < indexL + 1; i++) {
    array[i] = oldArray[i];
  }
  
  delete[] oldArray;
  indexL = indexL - 1; //array shrunk by 1
  
  /*
  for (int i = 1; i < 100; i++) {
    array[i-1] = array[i]; //move everything down 1 to fill the empty root!
  }

  for (int i = 0; i < 100; i++) {
    check(i, array); //need to make sure the array is organized
  }*/
}

void delAll(int* &array) {

  for (int i = 0; i < 100; i++) {
    if (array[0] != -5) { //if the array is not already empty
      del(array);
    }
  }
}

//Manual Input function (reads values from cin and calls "add" for each one):
void manualInput(int* &array) {
  bool adding = true;
  int count = 0;
  char answer;
  int toAdd = 0;
  
  while (adding && count < 100) {

    //continue adding numbers
    cout << "Would you like to add a value to the max heap? y/n" << endl;
    cout << "(max of 100 numbers can be added - numbers should be between 1 - 1000)" << endl;
    cin >> answer;

    if (answer == 'y') { //add
      cout << "Type the number you wish to add" << endl;
      cin >> toAdd;
      add(toAdd, array);
    }

    else {
      adding = false;
    }
  }
  cout << "Finished adding numbers to max heap" << endl;
}

void fileInput(int* &array) {
  //used this source from the udacity team on ways to read in files: https://www.udacity.com/blog/2021/05/how-to-read-from-a-file-in-cpp.html
  char answer[50];
  cout << "What is the name of the file you would like to read into the max heap? " << endl;
  cin >> answer;

  ifstream theFile(answer); //source notes that the >> operator reads until white space and while loop can run using the file name:

  while(theFile) {
    int toAdd = 0;
    theFile >> toAdd;
    add(toAdd, array);
  }

  cout << "Finished adding numbers to max heap" << endl;
}

void checkChild(int &index, int* &array) {
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
    indexL = index; //the final spot 
    check(index, array);
  }
  return;
}
