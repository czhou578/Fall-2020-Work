## Due Date: October 16, 2020 11:59pm
# A Bookstore Application

Design the class `Book`. Each object of the class `Book` can hold the following information about a book: 
+ title, 
+ authors, 
+ publisher, 
+ ISBN

Include the member functions to perform the various operations on the objects of `Book`. For example, the typical operations that can be performed on the title are to show the title, set the title. Add similar operations for the publisher, ISBN , and authors. Add the appropriate constructors and a destructor (if one is needed).

+ Write the definitions of the member functions of the class Book
+ Design a `BookstoreManager` class which creates a dynamic array of type `Book` (don’t use vectors), and provide implementation for the following operations on books in the array with the given time-complexity
+ A starter code and a sample output are provided. 
+ As shown in the sample output, books are kept sorted by ISBN. Each time a new book is inserted, it’ll be inserted in the sorted order. 
+ You are not allowed to use any existing sorting and searching functions. 

## The Functionalities available in BookstoreManager
| Function   | Time-complexity |
|----------|:-------------:|
| ``` isEmpty() ``` : returns true if the array is empty, otherwise false | O(1) |
| ``` isFull() ```: returns true if the array is full, otherwise false | O(1) |
| ``` listSize() ```: prints the number of books in the array | O(1) |
| ``` print() ```: prints the content of the array | O(n) |
| ``` insert(Book) ```: asks user to enter new book info, and it adds the book to the array in sorted order. If array is full, it’ll double the size of the array | O(n) |
| ``` remove(Book) ```: asks user to enter ISBN info, and it removes the book from the array; shifts the other elements up in the array. Prints “Not Found” if search fails | O(n) |
| ``` removePublisher(string) ```: asks user to enter publisher name, and it removes all the books with the same publisher from the array; shifts the other elements up in the array. Prints “Not Found” if search fails. | O(n) |   
| ``` search(Book) ```: asks user to enter ISBN or title, and prints the content of the book. Prints “Not Found”, if book is not found | O(logn) |  


## Sample Output:
###### user inputs are given in bold

> true
>
> Enter book title: **C++: Programming Basics**  
> Enter authors: **Nathan Clark**  
> Enter ISBN: **154296**  
> Enter publisher: **CreateSpace**  
>  
> Enter book title: **Data Structures & Algorithm Analysis in C++**  
> Enter authors: **Mark Weiss**  
> Enter ISBN: **132847**  
> Enter publisher: **Pearson**  
>  
> Enter book title: **Introduction to Programming Using Python**  
> Enter authors: **Daniel Liang**  
> Enter ISBN: **147231**  
> Enter publisher: **Pearson**  
>  
> Enter book title: **Introduction to Algorithms**  
> Enter authors: **Thomas H. Cormen , Charles E. Leiserson**  
> Enter ISBN: **189352**  
> Enter publisher: **MIT**  
>  
> Data Structures & Algorithm Analysis in C++  
> by Mark Weiss  
> 132847  
> Pearson  
>  
> Introduction to Programming Using Python  
> Daniel Liang  
> 147231  
> Pearson  
>   
> C++: Programming Basics  
> by Nathan Clark  
> 154296  
> CreateSpace  
>   
> Introduction to Algorithms  
> Thomas H. Cormen , Charles E. Leiserson  
> 189352  
> MIT  
>   
> Searching…  
> ISBN: **147231**  
> Introduction to Programming Using Python  
> Daniel Liang  
> 147231  
> Pearson  
>   
> Removing…  
> ISBN: **154296**  
>   
> Data Structures & Algorithm Analysis in C++  
> by Mark Weiss  
> 132847  
> Pearson  
>   
> Introduction to Programming Using Python  
> Daniel Liang  
> 147231  
> Pearson  
>   
> Introduction to Algorithms  
> Thomas H. Cormen , Charles E. Leiserson  
> 189352  
> MIT  
>   
> Removing all books for a publisher  
> Publisher: **Pearson**  
>   
> Introduction to Algorithms  
> Thomas H. Cormen , Charles E. Leiserson  
> 189352  
> MIT    
> 1  

## How to Submit

-	You’ll submit your work via GitHub Classroom assignment created by your instructor
-	You’ll receive a link to your assignment via Assignment tool on Canvas 
-	After you accept the assignment, you’ll enter the assignment repository on GitHub 
-	Click “Clone or Download” and clone the assignment onto your computer
-	After you make changes, commit them. Commits are essentially taking a snapshot of your projects.
-	At some point you'll want to get the updated version of the assignment back onto GitHub, either so that we can help you with your code, or so that it can be graded. You can do this by performing push operation.




## How to Evaluate

The following rubric describes how your work will be evaluated.
**Correctness** (90 points) 
- [90]   Program is correct in object oriented design and function; meets specification
- [75]   Program output is correct but elements of specification missing, e.g. variable/method declarations.
- [45]   Part of the specification has been implemented, e.g. one out of two required subprograms.
- [20]   Program has elements of correct code but does not assemble/compile. 

**Readability** (20 points) 
- [10]   Programmer name and assignment present. Sufficient comments to illustrate program logic. Well-chosen identifiers. 
- [7]   Programmer name present, most sections have comments. Fair choice of identifiers 
- [5]     Few comments, non-meaningful identifiers
- [0]     No programmer name. No comments. Poor identifiers
