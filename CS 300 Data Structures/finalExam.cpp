#include <iostream>
#include <cstring>

using namespace std;

class ArrayStack {                            //uses array
  private:
    int * data;
    int size;
    int stop;

}

void copyStack(const ArrayStack& other) {
  if (!other.isEmpty()) {
    destroy();
  }
  data = new ArrayStack[other.size];
  stop = other.stop;
  for (int i = 0; i < stop; i++) {
    data[i] = other[i];
  }

}

ArrayStack::ArrayStack(const ArrayStack& other) {
  copyStack(other);
}

ArrayStack& ArrayStack::operator=(const ArrayStack& other) {
  if (this != &other) {
    copyStack(other);
  }
  return *this;
}

~ArrayStack() {
  destroy();
}


void destroy() {
  delete [] data;
  stop = 0; 
}

class Queue {
  int* data,
  int front, back;
  int size, count;
};

Queue::Queue(const Queue& other) {                 //array implementation
  copyQueue();
}

void copyQueue(const Queue& other) {
  data = new int[other.size];
  front = other.front;
  for (int i = 0; i < other.length; i++) {
    data[i] = other[i];
  }
}

Queue& Queue::operator=(const Queue& other) {
  copyQueue();
  return * this;
}

void destroy() {
  delete [] data;

}

class LinkedList {                            //linked list starts here
  private:
    Node* dummyhead;
}

LinkedList::LinkedList(const LinkedList& other) { //calls assignment operator
  dummyhead = new Node(other.zeroth()-> data, NULL);
  *this = other;
}

LinkedList& LinkedList::operator=(const LinkedList& other) {
  Node* temp = other.zeroth();
  Node* temp2 = other.first();
  dummyhead = temp;
  while (temp != NULL) {
    temp = temp->next;
    dummyhead = temp;
    dummyhead = dummyhead->next;
  }
  return *this;
}

void destroy() {
  Node*temp = first;
  while (temp != null) {
    remove(first()->element);
  }
}

LinkedList::~LinkedList() {
  destroy();
  delete dummyhead;
}

class BST {                         //bst starts here
  BST::BST() {
    root = NULL;
  }
}

BST::BST(const BST& other) {
  root = copy(other.root);
}

BST& BST::operator=(BST* pointer) { //assigning one binary tree to another
  if (pointer != NULL) {
    destroy();
    root = copy(pointer.root);
  }
  return *this;
  
}

BinaryNode* copy(BinaryNode* root) {
  if (root != null) {
    BinaryNode* node = new BinaryNode;
    node->data = root.data;
    node->left = copy(root->left);
    node->right = copy(root->right);
    return node;
  }
  return NULL;
}

class binaryHeap {                      //binary heap starts here
  binaryHeap() {
    root = null;
  }
}

binaryHeap::binaryHeap(const binaryHeap& other) {
  root = copy(other.root);
}

void copy(const binaryHeap& other) {
  if ()
}

