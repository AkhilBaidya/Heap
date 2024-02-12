#include <iostream>
#include <cstring>

using namespace std;

//Struct for a node:
Struct node {
  int value; //has a value
  node* child1; //has child nodes
  node* child2;
};

//Function Prototypes:
void add(node*, node**);
void manualInput(node**);

//Main function (this is where the user will input values):
int main() {
  node* bob[100]; //this will be the max heap

  for (int i = 0; i < 100; i++) { //empty it
    bob[i] = NULL;
  }
  
  return 0;
}

//Add function (takes in a node and the current array and adds the node in the array according to the ordering of a max heap):
void add(node* val, node* array[100]) {

  node* current = array[0];

  if (current == NULL) { //there's nothing in the max heap, so just add the input
    array[0] = val;
  }

  else {

    

  }
}

//Manual Input function (reads values from cin and calls "add" for each one):
void manualInput(node* array[100]) {
}
