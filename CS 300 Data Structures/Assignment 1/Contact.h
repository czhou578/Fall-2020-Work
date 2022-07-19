#pragma once
#include <iostream>
#include <string>
#include <fstream>
#include <vector>

using namespace std;

class Contact
{
private:
  string firstName;
  string lastname;
  int phoneNum;

public:
  Contact(){}; // dummy default constructor

  Contact(string fName, string lName, int num)
  { // contact constructor
    firstName = fName;
    lastname = lName;
    phoneNum = num;
  }

  Contact(string fName, string lName)
  {
    firstName = fName;
    lastname = lName;
  }

  string getfirstName()
  { // getter methods
    return firstName;
  }

  string getLastName()
  {
    return lastname;
  }

  int getphoneNum()
  {
    return phoneNum;
  }
};
