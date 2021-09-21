/*
  BookstoreManager.cpp
  Colin Zhou
  10/15/2020
  Stores Book objects into dynamically created array (bookstore) and allows for various
  operations to be performed.

  Fun project!
*/

#include <iostream>
#include <string>
#include "Book.h"
#include "BookstoreManager.h"

using namespace std;

  BookstoreManager::BookstoreManager() { //constructor implementation
    numOfBooks = 10;
    slotsUsed = 0;
    bookStore = new Book [numOfBooks];
  }

  bool BookstoreManager::isEmpty() { // checks to see if bookstore is empty.
    if (slotsUsed == 0) {
      return true;
    }
    return false;
  }

  bool BookstoreManager::isFull() { //checks to see if bookstore is full.
    if (slotsUsed == numOfBooks) {
      return true;
    } 
    return false;
  }

  void BookstoreManager::listSize() { //returns the size of the bookstore so far.
    cout << "This is the number of books currently: " << slotsUsed << endl;
  }

  void BookstoreManager::print() { //prints the store
    for (int i = 0; i < numOfBooks; i++) {
      if (bookStore[i].getTitle() != "") {
        cout << bookStore[i].getTitle() << endl;
        cout << bookStore[i].getAuthors() << endl;
        cout << bookStore[i].getISBN() << endl;
        cout << bookStore[i].getPublisher() << endl;
        cout << "\n" << endl;

      } else {
        return;
      }
    }
  }

  Book* BookstoreManager::insert(Book newBook) { //inserts the books based on isbn order (ascending)
    Book tempBook;
    Book tempBook2;
    int indexHold;
    bool bookInserted = false;

    if (isFull() == true) {  
      numOfBooks *= 2;
    }

    if (isEmpty()) { // initially no new books
      bookStore[0] = newBook;
      slotsUsed++;
      return bookStore;
    }

    for (int i = 0; i < numOfBooks - 1; i++) {

      if (bookStore[i].getISBN() >= newBook.getISBN()) {
        indexHold = i;
        tempBook = bookStore[i];
        bookStore[i] = newBook;
        slotsUsed++;
        break;

      } else if (slotsUsed == i) {
        bookStore[i] = newBook;
        slotsUsed++;
        return bookStore;
      }      
    }

    for (int i = indexHold; i < numOfBooks - 1; i++) { //moves all books in array up after initial swap
        tempBook2 = bookStore[i + 1];
        bookStore[i + 1] = tempBook;
        tempBook = tempBook2;
    }

    return bookStore;
  }

  Book* BookstoreManager::remove(Book book) { //removes the specified book (isbn) from the list.
    int temp; //temp and temp2 are placeholders for the index.

    for (int k = 0; k < slotsUsed; k++) {
      if (k == slotsUsed - 1 && bookStore[k].getISBN() != book.getISBN()) { //check to see if book is not found
        cout << "Book not found!" << endl;
        return bookStore;
      } else if (bookStore[k].getISBN() == book.getISBN()) {
        break;
      }
    }

    for (int i = 0; i < numOfBooks - 1; i++) { //checks the following cases for the right book
      int temp2 = i;

      if (i == numOfBooks - 2 && bookStore[i + 1].getISBN() == book.getISBN()) { //last book of list
        delete &bookStore[i + 1]; //assign that slot to NULL?
        slotsUsed--;
        return bookStore;
      }

      if (book.getISBN() == bookStore[i].getISBN() && temp2 + 1 == slotsUsed - 1) { // 
        temp = i;
        bookStore[i] = bookStore[i + 1];
        slotsUsed--;
        break;

      } else if (book.getISBN() == bookStore[i].getISBN()) { //middle of array
        temp = i;
        delete &bookStore[i];
        //cout << &bookStore[i] << endl;
        bookStore[i] = bookStore[i + 1];
        slotsUsed--;
        break;
      }
    }

    for (int i = temp; i < numOfBooks - 1; i++) {
      if (i == numOfBooks - 2) {
        bookStore[i] = bookStore[i + 1];
        delete &bookStore[i + 1];
        return bookStore;
      }
      bookStore[i] = bookStore[i + 1];
      
    }
    return bookStore;

  } 

  Book* BookstoreManager::removePublisher(string str) { //removes book based on publisher.
    int temp; //placeholder for index, just like remove function

    for (int k = 0; k < numOfBooks; k++) { //check to see if book is not found
      if (k == slotsUsed - 1 && bookStore[k].getPublisher() != str) {
        cout << "Book not found!" << endl;
      } else if (bookStore[k].getPublisher() == str) {
        break;
      }
    }

    for (int i = 0; i < numOfBooks - 1;) { //checks the corresponding cases for the publisher. 

      if (bookStore[0].getPublisher() == str && bookStore[i + 1].getPublisher() == str) {         
        temp = i;
        while (bookStore[0].getPublisher() == str) {
          for (int i = temp; i < numOfBooks - 1; i++) {
            bookStore[i] = bookStore[i + 1];
          }
          slotsUsed--;
        }

        if (slotsUsed > 0) {
          continue;
        }
      
        return bookStore;

      } else if (bookStore[0].getPublisher() == str && bookStore[i + 1].getPublisher() != str) {
          temp = i;
          bookStore[i] = bookStore[i + 1];
          for (int j = temp; j <= slotsUsed + 1; j++) {
            bookStore[j] = bookStore[j + 1];
          }
          slotsUsed--;

        continue;
      }

      if (bookStore[i].getPublisher() == str && bookStore[i + 1].getPublisher() == str) {
        temp = i;

        while (bookStore[temp].getPublisher() == str) {
          for (int j = temp; j <= slotsUsed + 1; j++) {
            bookStore[j] = bookStore[j + 1];
          }
          slotsUsed--;
        }
        return bookStore;

      } else if (bookStore[i].getPublisher() == str && bookStore[i + 1].getPublisher() != str) {
        temp = i;
        for (int j = temp; j <= slotsUsed + 1; j++) {
          bookStore[j] = bookStore[j + 1];
        }
        slotsUsed--;
        continue;

      } else if (bookStore[i].getPublisher() != str) {
          i++;
          continue;
      }

      if (i == (slotsUsed - 1) && bookStore[slotsUsed - 1].getPublisher() == str) {
        temp = slotsUsed - 1;
        for (int j = temp; j <= slotsUsed + 1; j++) {
          bookStore[j] = bookStore[j + 1];
        }
        slotsUsed--;
        return bookStore;
      } 

      i++;
    }
  }

  void BookstoreManager::search(Book book) { // search for a book (enter the ISBN)
    int bookISBN = book.getISBN();

    if (bookStore[0].getISBN() == book.getISBN()) { //check the very beginning index (1st case)
      cout << bookStore[0].getTitle() << endl;
      cout << bookStore[0].getAuthors() << endl;
      cout << bookStore[0].getISBN() << endl;
      cout << bookStore[0].getPublisher() << endl;
      cout << "\n" << endl;
    }

    for (int i = 1; i < numOfBooks; i *= 2) {

      if (bookStore[i].getISBN() == bookISBN) {
        cout << bookStore[i].getTitle() << endl;
        cout << bookStore[i].getAuthors() << endl;
        cout << bookStore[i].getISBN() << endl;
        cout << bookStore[i].getPublisher() << endl;
        cout << "\n" << endl;
        return;
      }

      if (bookStore[i].getISBN() > bookISBN) { //save index when ISBN is greater, then use while loop to loop nack and find element
        int temp = i / 2;
        while (i >= temp) {
          if (bookStore[i].getISBN() == book.getISBN()) {
            cout << bookStore[i].getTitle() << endl;
            cout << bookStore[i].getAuthors() << endl;
            cout << bookStore[i].getISBN() << endl;
            cout << bookStore[i].getPublisher() << endl;
            cout << "\n" << endl;
            return;
          }
          i--;
        }
      }
    } 

    cout << "Book not found" << endl;
  }
