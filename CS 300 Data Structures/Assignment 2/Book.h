#ifndef BOOK
#define BOOK
#include <iostream>
#include <string>


using namespace std;

class Book {
  private:
    string title;
    string authors;
    string publisher;
    int isbn;

  public:
    Book() {};

    Book(string bookTitle, int isbnNum, string bookAuthor, string bookPublish);

    ~Book() {};

    Book(int isbnNum);

    void setTitle(string bookTitle);

    string getTitle();

    void setAuthors(string bookAuthors);

    string getAuthors();

    void setPublisher(string publishers);

    string getPublisher();
    
    void setISBN(int num);

    int getISBN();

};
#endif

