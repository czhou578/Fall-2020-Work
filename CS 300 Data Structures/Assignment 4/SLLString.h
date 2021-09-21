/**
 *  Colin Zhou
 *  Fatma Serce
 *  Assignment 4
 * 11/4/2020
 * This file is the file with all the implementations for the functions necessary to create a custom SLLString
 * using linked lists.
 * */

#pragma once
#include <iostream>
#include <cstring>
#include "Node.h"

using namespace std;

class SLLString {

  private:
    string str;
    Node* dummyHead;

  public:

    SLLString(); //Default constructor

    SLLString(const string& other); //copy constructor taking a C++ string as parameter. 

    ~SLLString(); // destructor fixed

    SLLString(const SLLString& other); //copy constructor taking another SLLString 

    SLLString& operator = (const SLLString& other); // assignment constructor 

    int length() const; // get length of this string. 

    SLLString& operator += (const SLLString& other); // concatenation 

    char& operator[](const int n) const; //get character at index n. done

    int findSubstring(const SLLString& substring); // done find the index of the first occurrence of substring in the current string. Returns -1 if not found.

    int findSubstring(string str); // takes in c++ string and finds it in the current object.

    void erase(char c); //erase the chosen letter from the SLLString

    friend ostream& operator << (ostream& os, SLLString& string); //done

};

ostream& operator << (ostream& os, SLLString& string) { //operator overload 
  Node* head = string.dummyHead;

  while (head->next != NULL) { //traverse list and print
    os << head->letter;
    head = head->next;
  }

  os << head->letter;

  return os;
}

SLLString::SLLString() { //SLL constructor that initializes dummyhead
  dummyHead = new Node('\0', NULL);
}

SLLString::SLLString(const string& other) { //constructor taking in one c++ string
  dummyHead = new Node('\0', NULL);
  Node* first = dummyHead->next;
  first = new Node(other.at(0), NULL);
  dummyHead->next = first;

  for (int i = 1; i < other.length(); i++) { //traverse and create new node that contains letter of input string
    if (i == other.length() - 1) {
      first->next = new Node(other.at(i), NULL);
    }

    first->next = new Node(other.at(i), NULL);
    first = first->next;
  }
}

SLLString::SLLString(const SLLString& other) { //copy constructor
  dummyHead = new Node('\0', NULL);
  *this = other;
}

SLLString::~SLLString() { // destructor
  Node* p = this->dummyHead->next;

  while(p->next != NULL) { //deletes the nodes of the list one by one
    if (p->next->next == NULL) {
      p->next = NULL;
      delete p->next;

    } else {
      Node* nextNode = p->next;
      p->next = nextNode->next;
      delete nextNode;

    }
  }

  delete p; //deletes first node of the list
  delete dummyHead; //deletes the dummyhead
}

SLLString& SLLString::operator=(const SLLString& other) { //assignment operator
  if (this != &other) {
    Node* otherDummyHead = other.dummyHead; //input string dummyhead
    Node* otherFirst = otherDummyHead->next;

    dummyHead = new Node('\0', NULL); //initialize the dummyhead
    Node* currentFirst = dummyHead->next;
    currentFirst = new Node(otherFirst->letter, NULL);
    dummyHead->next = currentFirst;

    while (otherFirst) {
      if (otherFirst->next == NULL) {
        break;
      }

      otherFirst = otherFirst->next; //increment paramString
      currentFirst->next = new Node(otherFirst->letter, NULL); 
      currentFirst = currentFirst->next; //increment currentstring
    }
  }

  return *this;
}

int SLLString::length() const { //string length
  int strLength = 0;
  Node* currentFirst = this->dummyHead;
  while (currentFirst->next != NULL) { //add to strLength variable, then return at end
    strLength++;
    currentFirst = currentFirst->next;
  }
  return strLength;
}

SLLString& SLLString::operator+= (const SLLString& other) { //modifying object, thus calls destructor
  int paramLength = other.length();
  Node* currentFirst = this->dummyHead->next;
  Node* otherHead = other.dummyHead->next;

  while(currentFirst->next != NULL) { //loop until the end of the current string.
    currentFirst = currentFirst->next;
  }

  while(otherHead->next != NULL) { // loop and add new Node with the chars of "other" string
    Node* newLetter = new Node(otherHead->letter, NULL);
    currentFirst->next = newLetter;
    currentFirst = currentFirst->next;
    otherHead = otherHead->next;    
  }

  Node* lastLetter = new Node(otherHead->letter, NULL); //end case, when otherHead-> next is NULL
  currentFirst->next = lastLetter;

  return *this;
} 

char& SLLString::operator[](const int n) const { //find the char at the given location number
  int count = 0;
  Node* currentFirst = dummyHead->next;
  while (currentFirst->next != NULL) { // loop, find char, then return char in string.
    if (count == n) {
      return currentFirst->letter;
    }
    currentFirst = currentFirst->next;
    count++;
  }
  return currentFirst->letter;
}

int SLLString::findSubstring(string str) { //if input is c++ string, put str as parameter of SLLstr object.
  return findSubstring(SLLString(str));
}

int SLLString::findSubstring(const SLLString& substring) { //find substring within the string
  int paramStringLength = substring.length();
  bool foundFirstLetter; //flag for finding first char of substring within string
  int firstLetterIndex; //ultimately returns this variable
  int charCounter = 0; //counts number of consecutive correct chars in string that matches in substring
  int currentFirstNextCounter = 0; // counts the index position within current string while iterating

  Node* currentFirst = this->dummyHead->next;

  while(currentFirst->next != NULL) {
    if (currentFirst == this->dummyHead->next) { // 0 should be index of first node, that's why the continue is here
      currentFirst = currentFirst->next;
      continue;
    }

    currentFirstNextCounter++;

    if (currentFirst->letter == substring.operator[](0)) { //found first letter
      foundFirstLetter = true;
      charCounter++;
      firstLetterIndex = currentFirstNextCounter;
    }

    if (foundFirstLetter == true) { //start iterating to see if other letters match
      for (int i = 1; i < paramStringLength; i++) {
        currentFirst = currentFirst->next;
        if (currentFirst->letter == substring.operator[](i)) {
          charCounter++;
        }
      }

      if (charCounter == paramStringLength) { // if entire substring has been found
        return firstLetterIndex;
      }

    } else {
      currentFirst = currentFirst->next;
    }
  }
  return -1;
}

void SLLString::erase(char c) { //erases character from the list
  Node* currentFirst = this->dummyHead->next;
  Node* previousElement; //getes assigned to current element when comparing to next element

  while (currentFirst->next != NULL) {
    if (currentFirst->next->letter == c) {
      previousElement = currentFirst; //saves current node
      Node* matchElement = currentFirst->next; //saves the matching element
      previousElement->next = matchElement->next; //links current to the node following matching element
      delete matchElement; //deleting matching node

      if (previousElement->next == NULL) { // last element deleted, then break from the loop
        break; 

      } else if (previousElement->next->letter == c) { // 
        continue;
      }

    } else { //keep traversing
      currentFirst = currentFirst->next;
    }
  }

}

