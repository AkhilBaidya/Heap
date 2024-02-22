#include <iostream>
#include <cstring>
#include <fstream>

using namespace std;

//Function Prototypes:
void add(int, int* &, int &);
void checkParent(int, int* &);
void del(int* &, int &);
void delAll(int* &, int &);
void print(int* &, int, int);
void manualInput(int* &, int &);
void fileInput(int* & ,int &);
void checkChild(int, int* &);

//Main function (this is where the user will input values):
int main() {
  int mxh[100]; //this will be the max heap
  int* mxhPnt = mxh; //pointer set as the array (for passing by reference later on)
  int indexL = 0; //"Index Last": the index of the bottom-right most element in the tree representing the current max heap
  bool editing = true; //editing the max heap
  char answer[15];
  
  for (int i = 0; i < 100; i++) { //empty it
  mxh[i] = -5;
  }

  cout << "Max heap ready for editing:" << endl;

  while (editing) {
    cout << "Would you like to ADD to the max heap, DELETE the root, DELETE_ALL, or QUIT this program?" << endl;
    cin >> answer;
    
    if (!strcmp(answer, "ADD")) {

      char inputType[15];

      cout << "Would you like to add manually (MAN) or by file (FILE)?" << endl;
      cin >> inputType;

      if (!strcmp(answer, "MAN")) {
	manualInput(mxhPnt, indexL);
      }

      else if (!strcmp(answer, "FILE")) {
	fileInput(mxhPnt, indexL);
      }

      else {
	cout << "Did not understand (please input capitalized commands)" << endl;
      }
    }
    
  }


  

  return 0;
}

//Add function (takes in a node and the current array and adds the node in the array according to the ordering of a max heap):
void add(int val, int* &array, int &indexL) {

  int i = 0;

  while ((array)[i] != -5) {
    i++;
  }

  array[i] = val; //the next open spot is given to the input value
  indexL = i;
  checkParent(i, array); //reorder max heap such that every child is smaller than the parent
}

//Check function (makes sure that the parent of the current node has a larger value than it; otherwise, it will swap the nodes)
void checkParent(int index, int* &array) {
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
    checkParent(index, array);
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

void del(int* &array, int &indexL) {
  cout << "Here's the deleted root value: " << array[0] << endl;
  array[0] = array[indexL]; //replace root with end value
  array[indexL] = -5;
  indexL = indexL - 1; //table shrunk by 1
  checkChild(0, array); //reformat
}

void delAll(int* &array, int &indexL) {
  for (int i = 0; i < 100; i++) {
    if (array[0] != -5) { //if the array is not already empty
      del(array, indexL);
    }
    }
}

//Manual Input function (reads values from cin and calls "add" for each one):
void manualInput(int* &array, int &indexL) {
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
      add(toAdd, array, indexL);
    }

    else {
      adding = false;
    }
  }
  cout << "Finished adding numbers to max heap" << endl;
}

void fileInput(int* &array, int &indexL) {
  //used this source from the udacity team on ways to read in files: https://www.udacity.com/blog/2021/05/how-to-read-from-a-file-in-cpp.html
  char answer[50];
  cout << "What is the name of the file you would like to read into the max heap? " << endl;
  cin >> answer;

  ifstream theFile(answer); //source notes that the >> operator reads until white space and while loop can run using the file name:

  while(theFile) {
    int toAdd = 0;
    theFile >> toAdd;
    add(toAdd, array, indexL);
  }

  cout << "Finished adding numbers to max heap" << endl;
}

void checkChild(int index, int* &array) {
  //brought from above check function
  int child1 = (2 * index) + 1;
  int child2 = (2 * index) + 2;

  if (array[child1] != -5 && array[child2] != -5) { //not empty children

    if (array[child1] > array[index] || array[child2] > array[index]) { //if there are larger children

      if (array[child1] < array[child2]) {
	int temp = array[child2];
	array[child2] = array[index];
	array[index] = temp; //swap
	index = child2;
      }

      else {
	int temp = array[child1];
	array[child1] = array[index];
	array[index] = temp; //swap with the other
	index = child1;
      }
      
    }

    else {
      return;
    }
  }


  else if (array[child1] != -5 && array[child1] > array[index]) { //swap with child1 is it is larger
    int temp = array[child1];
	array[child1] = array[index];
	array[index] = temp; // from above
	index = child1;
  }

  else if (array[child2] != -5 && array[child2] > array[index]) {
    int temp = array[child2];
	array[child2] = array[index];
	array[index] = temp; //swap
	index = child2;
  }

  else {
    return; //there are empty spots
  }
  checkChild(index, array); //check again!
  return;
}
