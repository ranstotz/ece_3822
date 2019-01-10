#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <iostream>

using namespace std;

// Node class to link nodes of the linked list
//
class Node {
  // Declare char pointer 'data' and Node pointer 'next'
  //
  char* data;
  Node* next;

  // Declare public data
  //
public:
  // Default constructor
  //
  Node() {};

  // Setter methods
  // SetData sets the new data as a node in the linked list
  //
  void SetData(char* aData) { data = aData; };

  // Set Next sets the next node to NULL 
  //
  void SetNext(Node* aNext) { next = aNext; };

  // Return functions
  //
  char* Data() { return data; };
  Node* Next() { return next; };
};

// List class to generate the linked list
//
class List {
  // Declare pointer head as Node
  //
  Node *head;
public:
  // head node points to NULL
  //
  List() { head = NULL; };

  // Print current linked list method
  //
  void Print();

  // Append char string as a node in the linked list method
  //
  void Append(char* data);

  // Delete char string as a node in the linked list method
  //
  void Delete(char* data);
};


// Print the contents of the list
//
void List::Print() {

  // Temp pointer
  //
  Node *tmp = head;

  // If no nodes are linked, print 'EMPTY'
  //
  if ( tmp == NULL ) {
    cout << "EMPTY" << endl;
    return;
  }

  // If one node is in the list
  //
  if ( tmp->Next() == NULL ) {
    cout << tmp->Data();
    cout << " --> ";
    cout << "NULL" << endl;
  }
  else {
    // Parse and print the list
    do {
      cout << tmp->Data();
      cout << " --> ";
      tmp = tmp->Next();
    }
    while ( tmp != NULL );

    cout << "NULL" << endl;
  }
}


// Append a node to the linked list
//
void List::Append(char* data) {

  // Create a new node
  Node* newNode = new Node();
  newNode->SetData(data);
  newNode->SetNext(NULL);

  // Create a temp pointer
  Node *tmp = head;

  if ( tmp != NULL ) {
    // Nodes already present in the list
    // Parse to end of list
    while ( tmp->Next() != NULL ) {
      tmp = tmp->Next();
    }

    // Point the last node to the new node
    tmp->SetNext(newNode);
  }
  else {
    // Set head to the new node generated at end of linked list
    //
    head = newNode;
  }
}


// Delete a node from the list
//
void List::Delete(char* data) {

  // Create a temp pointer
  Node *tmp = head;

  // No nodes
  if ( tmp == NULL )
    return;

  // Last node of the list
  if ( tmp->Next() == NULL ) {
    delete tmp;
    head = NULL;
  }
  else {
    // Parse thru the nodes
    Node *prev;
    do {
      if ( tmp->Data() == data ) break;
      prev = tmp;
      tmp = tmp->Next();
    } while ( tmp != NULL );

    // Adjust the pointers
    prev->SetNext(tmp->Next());

    // Delete the current node
    delete tmp;
  }
}
