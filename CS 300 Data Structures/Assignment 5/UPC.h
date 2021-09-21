/*
  This class contains the methods for constructing a UPC object, which contains the UPC
  key for the specific product along with the description of the object. 

*/

#pragma once
#include <iostream>

using namespace std;

class UPC {
  private:
    long long UPCkey;
    string description;

  public:

    UPC() {}; //default contructor.

    UPC(long long key) { //overloaded constructor
      UPCkey = key;
    }

    UPC(long long key, string str) {
      UPCkey = key;
      description = str;
    }

    long long getKey() {
      return UPCkey;
    }

    string getDescription() {
      return description;
    }
};