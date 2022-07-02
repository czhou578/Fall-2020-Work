// Contact.cpp
// Colin Zhou
// 10/08/2020
// Stores all information from phonebook text file into dynamic array of Contact
// objects, then allows for performance of operations on the specific array.

#include <iostream>
#include <string>
#include <fstream>
#include <sstream>
#include <vector>
#include "Contact.h"
#include "PhoneBookManager.h"

using namespace std;

int main()
{

  string myText; // each line of the text file
  ifstream file;
  int totalLineFile = 151425;
  int arrayPos = 0;

  Contact *contactInfos;
  contactInfos = new Contact[totalLineFile + 1]; // dynamically created array

  file.open("phonebook2.txt");

  while (getline(file, myText))
  { // reading file into array
    string fName;
    string lName;
    int phoneNumber;

    stringstream ss(myText);
    ss >> fName >> lName >> phoneNumber;
    Contact contactInfo(fName + " ", lName + " ", phoneNumber);
    contactInfos[arrayPos] = contactInfo;
    arrayPos++;
  }

  file.close();

  char inputChar; // defined variables for collecting input
  int inputNumber;
  string inputfirstName;
  string inputLastName;

  while (inputChar != 'Q')
  { // registering user entered command
    cout << "MY PHONEBOOK APPLICATION" << endl;
    cout << "Please choose an operation" << endl;
    cout << "A(Add) | S(Search) | D(Delete) | L(List) | Q(Quit):";
    cin >> inputChar;

    if (inputChar == 'A')
    { // if statements for determining actions based on user input
      cout << "Enter First Name: ";
      cin >> inputfirstName;
      cout << "Enter Last Name: ";
      cin >> inputLastName;
      cout << "Phone Number: ";
      cin >> inputNumber;
      Contact tempContact(inputfirstName + " ", inputLastName + " ", inputNumber); // space added here
      addContact(contactInfos, tempContact, totalLineFile);
    }
    else if (inputChar == 'S')
    {
      cout << "Enter First Name: ";
      cin >> inputfirstName;
      cout << "Enter Last Name: ";
      cin >> inputLastName;
      Contact tempContact(inputfirstName + " ", inputLastName + " ");
      search(contactInfos, tempContact, totalLineFile);
    }
    else if (inputChar == 'D')
    {
      cout << "Enter First Name: ";
      cin >> inputfirstName;
      cout << "Enter Last Name: ";
      cin >> inputLastName;
      deleteContact(contactInfos, inputfirstName, inputLastName, totalLineFile);
    }
    else if (inputChar == 'L')
    {
      list(contactInfos, totalLineFile);
    }
    else if (inputChar == 'Q')
    {
      delete[] contactInfos; // delete array if the program is terminated
      exit(0);
    }
    else
    {
      delete[] contactInfos;
      exit(0);
    }
  }
}