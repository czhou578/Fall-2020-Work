/**
 *  Colin Zhou
 *  Fatma Serce
 *  Assignment 4
 * 11/4/2020
 * This file represents the Node, which is the basic building block of the linked list implementation.
 * */

#include <iostream>

using namespace std;

class Node { //class for individual Node Object

  public:
    char letter;
    Node* next;

    Node(char _letter, Node* _next) { //pointer to next Node
      letter = _letter;
      next = _next;
    }
};