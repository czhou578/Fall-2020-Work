/*
  I tried out Visual Studio Code's text indent formatting on this file. I prefer to have the 
  first curly brace on the same line as the method declaration, rather then the next line.
  Thus, I did not do the same for the other files. Sorry for the inconsistency. 
*/

#include <iostream>
#include <string>
#include "Book.h"

using namespace std;

  Book::Book(string bookTitle, int isbnNum, string bookAuthor, string bookPublish)
  {
    title = bookTitle;
    authors = bookAuthor;
    publisher = bookPublish;
    isbn = isbnNum;
  }

  Book::Book(int isbnNum)
  {
    isbn = isbnNum;
  }

  void Book::setTitle(string bookTitle)
  {
    title = bookTitle;
  }

  string Book::getTitle()
  {
    return title;
  }

  void Book::setAuthors(string bookAuthors)
  {
    authors = bookAuthors;
  }

  string Book::getAuthors()
  {
    return authors;
  }

  void Book::setPublisher(string publishers)
  {
    publisher = publishers;
  }

  string Book::getPublisher()
  {
    return publisher;
  }

  void Book::setISBN(int num)
  {
    isbn = num;
  }

  int Book::getISBN()
  {
    return isbn;
  }

