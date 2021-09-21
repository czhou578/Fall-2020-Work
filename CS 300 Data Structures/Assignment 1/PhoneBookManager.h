#include <iostream>
#include <string>
#include <fstream>
#include <vector>

using namespace std;

  void search(Contact contactInfo[], Contact contact, int& totalLineFile) { //search for specific Object in array
    for (int i = 0; i < totalLineFile; i++) {

      if (contactInfo[i].getfirstName() == contact.getfirstName() && contactInfo[i].getLastName() == contact.getLastName()) {
        cout << contactInfo[i].getfirstName() << contactInfo[i].getLastName() << contactInfo[i].getphoneNum() << endl;
      }
    }
  }

  void list(Contact contactInfo[], int& totalLineFile) { //add to list
    for (int i = 0; i < totalLineFile; i++) {
      if (contactInfo[i].getfirstName() != "") {
        cout << contactInfo[i].getfirstName() << contactInfo[i].getLastName() << contactInfo[i].getphoneNum() << endl;
      } else {
        return;
      }
    }
  }

  Contact addContact(Contact contactInfo[], Contact contact, int& totalLineFile) { //add contact function
    totalLineFile++;
    contactInfo[totalLineFile - 1] = contact;
    return contactInfo[totalLineFile - 1];
  }

  Contact deleteContact(Contact contactInfo[], string firstName, string lastName,  int& totalLineFile) { //delete contact function
    totalLineFile--;
    for (int i = 0; i < totalLineFile; i++) {
      if (contactInfo[i].getfirstName() == firstName && contactInfo[i].getLastName() == lastName) {
        delete &contactInfo[i];
      }
    }

    return contactInfo[totalLineFile - 1];
  }
