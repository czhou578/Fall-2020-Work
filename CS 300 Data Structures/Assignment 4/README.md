# CS300assignment4
## Due Date: November 6, 2020 11:59pm
# String as Singly Linked List

In many programming languages, the String class is typically implemented as an array of characters. Some other languages, such as Haskell, Erlang, and a few other functional programming languages, however, implement strings as **Singly Linked List (SLL)** of characters. Compared with the array implementations, the SLL ones are very easy for pattern matching because of the recursive structure of linked list. Let’s don’t worry about recursion in this assignment.
In this assignment, you will implement a `SLLString` class using SLL. Your `SLLString` class will include the following members:

- `SLLString();` //Default constructor
- `SLLString(const string& other);` //copy constructor taking a C++ string as parameter.
- `~SLLString();` // destructor
- `SLLString(const SLLString& other);` //copy constructor taking another SLLString
- `SLLString& operator=(const SLLString& other);` // assignment constructor
- `int length();` // get length of this string.
- `SLLString& operator+= (const SLLString& other);` // concatenation
- `char& operator[](const int n);` //get character at index n. 
- `int findSubstring(const SLLString& substring);` // find the index of the first occurrence of substring in the current string. Returns -1 if not found.
- `void erase(char c);` //erase all occurrences of character c from the current string.
- support `<<` operator (cout<<).
- `Node* head;` // the head pointer to the SLL.

Each `Node` object should contain a char data type and a next pointer to `Node`.

Here are the sample use cases:
```
int main(){
    SLLString str(“Hello world!”);
    SLLString newStr = new SLLString;

    newStr = str;
    newStr += SLLString(“ CS@BC”);
    newStr[6] = ‘W’;

    cout << newStr << endl; 
    cout << newStr.length() << endl; 

    int loc = newStr.findSubstring(“World”);
    cout << loc << endl; 

    newStr.erase(‘l’); //erase the letter l.
    cout << newStr << endl; 

    newStr.erase(‘C’);
    cout << newStr << endl; 
}

```

> *Sample Ouput:*  
> Hello World! CS@BC   
> 18  
> 6   
> Heo Word! CS@BC 
> Heo Word! S@B  
 

You are provided with a starter code (`ass4.cpp`). The class is partially implemented, and your task is to implement the rest of it. 

## How to Submit

-	You’ll submit your work via GitHub Classroom assignment created by your instructor
-	You’ll receive a link to your assignment via Assignment tool on Canvas 
-	After you accept the assignment, you’ll enter the assignment repository on GitHub 
-	Click “Clone or Download” and clone the assignment onto your computer
-	After you make changes, commit them. Commits are essentially taking a snapshot of your projects.
-	At some point you'll want to get the updated version of the assignment back onto GitHub, either so that we can help you with your code, or so that it can be graded. You can do this by performing push operation.
- If you are **late** in submitting your work, please submit your assignment via **CANVAS**.



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
