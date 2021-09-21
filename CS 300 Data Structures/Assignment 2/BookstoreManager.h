#ifndef BOOKSTOREMANAGER
#define BOOKSTOREMANAGER
#include <iostream>
#include <string>
#include "Book.h"

using namespace std;

class BookstoreManager {
  private:
    int numOfBooks;
    int slotsUsed;

  public:
    Book* bookStore;

    BookstoreManager();

    bool isEmpty();

    bool isFull();

    void listSize();

    void print();

    Book* insert(Book newBook);

    Book* remove(Book book);

    Book* removePublisher(string str);

    void search(Book book);
};
#endif