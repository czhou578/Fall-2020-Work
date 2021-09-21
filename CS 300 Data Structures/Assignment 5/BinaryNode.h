/*
  This class represents one BinaryNode, to  be inserted in the tree, along with the UPC
  object it contains and the left and right pointers. 

*/

#pragma once
#include <iostream>
#include <cstring>
#include "UPC.h"

using namespace std;

class BinaryNode {
  public:
    UPC productObj;
    BinaryNode* left;
    BinaryNode* right;

    BinaryNode() {}; //default constructor
    
    BinaryNode(UPC prodObj, BinaryNode* _left = NULL, BinaryNode* _right = NULL) { //constructor
      productObj = UPC(prodObj.getKey(), prodObj.getDescription());
      left = _left;
      right = _right;
    }
};