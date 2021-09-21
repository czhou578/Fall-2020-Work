#include <iostream>
#include "Book.h"
#include "BookstoreManager.h"

using namespace std;

int main() { 
    BookstoreManager bookstoreManager;
    //bookstoreManager.print();

    //prints true if the bookstore is empty
    //cout << bookstoreManager.isEmpty() << endl;

    //insert 4 books
    string title, authors, publisher;
    int isbn;
    //int loopiterations;

    for(int i=0;i<2;i++){
        cout<<"Enter book title:";
        cin>>title;
        if (i == 0) {
            cout << "Enter authors:";
        } else {
            cout << "Enter authors:";
        }
        cin.ignore();
        getline(cin, authors);
        cout<<"Enter isbn:"; 
        cin>>isbn;
        cout<<"Enter publisher:";
        cin>>publisher;
        Book aBook(title, isbn, authors, publisher);
        bookstoreManager.insert(aBook); 
    }

    //print bookstore
    //bookstoreManager.print();

    //search for books
    // for (int j = 0; j < 2; j++)
    // {
    //     cout<<"Searching…"<<endl;
    //     cout<<"ISBN:";
    //     cin>>isbn;
    //     Book b2(isbn);
    //     bookstoreManager.search(b2);
       
    // }
    
    cout<<"Searching…"<<endl;
    cout<<"ISBN:";
    cin>>isbn;
    Book b2(isbn);
    bookstoreManager.search(b2);

    //remove a book
    // for (int j = 0; j < 2; j++) //works
    // {
    //     cout<<"Removing…"<<endl;
    //     cout<<"ISBN:";
    //     cin>>isbn;
    //     Book b1(isbn);
    //     bookstoreManager.remove(b1);
    //     bookstoreManager.print();
    // }
    

    // //print bookstore
    //bookstoreManager.print();

    //remove books from a particular publisher
    for (int k = 0; k < 2; k++)
    {
        cout<<"Removing publisher"<<endl;
        cout<<"Publisher:";
        cin>>publisher; 
        bookstoreManager.removePublisher(publisher);
        bookstoreManager.print();
        
    }
    

    // //print bookstore
//    bookstoreManager.print();


    // //prints the number of books 
    // bookstoreManager.listSize();
    
}
