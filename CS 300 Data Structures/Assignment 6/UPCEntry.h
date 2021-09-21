/*
    Contains both hash functions
*/

#pragma once;
#include <cstring>
#include <list>
#include <sstream>
using namespace std;

class UPCEntry // the two hash functions that both return a position
{  
    public:

    long long upc = -1;
    string desc = "";

    UPCEntry(){};

    UPCEntry(string);
    
    int hash1(int tableSize)
    {
        return upc % tableSize;
    }

    int hash2(int tableSize)
    {
        return abs(desc[0] + 27 * desc[1] + 729 * desc[2]) % tableSize;
    }

};

UPCEntry::UPCEntry(string description) { //constructor
    desc = description;
}

bool operator==(const UPCEntry& item1, const UPCEntry& item2) {
    bool isSameItem; //item2 is to be found item, item1 is item comparing with
    long long temp;
    string input = item2.desc;
    stringstream ss(input); // item 2 description has to be broken up since it contains both upc and descrip.
    string token;
    int tempCounter = 0; 


    while(getline(ss, token, ',')) {
        tempCounter++;
        if (tempCounter == 2) {
            input = token;
            break;
        }
    } 
    // at this point, the upc is taken out of the item2's string descrip, which is what we want

    int countLoop = 0;
    stringstream ss2(item1.desc);

    if (item2.upc != item1.upc) {
        return false;
    }
    
    while(getline(ss2, token, ',')) { //using to compare the descriptions
        countLoop++;
        if (countLoop == 1) {
            if (input != token) {
                return false;
            }

        }

    }
    return true;
    

}

