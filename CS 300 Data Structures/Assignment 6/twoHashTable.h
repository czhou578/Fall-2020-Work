/*
    Colin Zhou
    Fatma Serce
    11/28/2020
    This assignment uses double hashing to insert a grocery list of objects based
    on their upc code. 

*/

#pragma once;
#include "position.h"
#include "UPCEntry.h"
#include <cmath>
#include <fstream>
#include <vector>
#include <list>
using namespace std;

class TwoHashTable
{
public:
    TwoHashTable(string filename, int tableSize); //creates the table with the file
    bool insert(UPCEntry &item);     // returns true if successful, false otherwise.
    Position search(UPCEntry &item); // if not found, return the default position with both indices set as -1
    float getStdDev(); //calls private standard deviation function

private:
    int firstHash; //first hash value
    int secondHash; //second hash value
    int SizeOfTable; //size of table
    vector<list<UPCEntry>> arrLists; //array of chained lists

    float stddev(int *binLengths, int tableSize)
    {
        float sum = 0;
        for (int i = 0; i < tableSize; i++)
            sum += binLengths[i];

        float average = sum / tableSize;

        float dev_sum = 0;
        for (int i = 0; i < tableSize; i++)
        {
            dev_sum = dev_sum + (binLengths[i] - average) * (binLengths[i] - average);
        }

        float variance = dev_sum / tableSize;
        return sqrt(variance);
    }
};

TwoHashTable::TwoHashTable(string filename, int tableSize) { //just insert into proper list!
    SizeOfTable = tableSize;
    arrLists.resize(tableSize); //resizes vector to specified storage.

    ifstream file;
    file.open(filename);
    string line;
    getline(file, line); //skips first line
    long long id;
    string description;

    while(getline(file, line)) { //reads each value in
        id = stoll(line.substr(0, 12));
        description = line.substr(13);
        UPCEntry entry(description);
        entry.upc = id;
        firstHash = entry.hash1(tableSize);
        secondHash = entry.hash2(tableSize);
        insert(entry); //calls insert function
    }
}


bool TwoHashTable::insert(UPCEntry& item) { //inserts into the hash table based on certain conditions

    if (firstHash == secondHash) {
        arrLists.at(firstHash).push_front(item);
        return true;

    } else if (arrLists.at(firstHash).size() == arrLists.at(secondHash).size()) {
        arrLists.at(firstHash).push_front(item);
        return true;

    } else if (arrLists.at(firstHash).size() > arrLists.at(secondHash).size()) {
        arrLists.at(secondHash).push_front(item);
        return true;

    } else if (arrLists.at(firstHash).size() < arrLists.at(secondHash).size()) {
        arrLists.at(firstHash).push_front(item);
        return true;
    }
}

Position TwoHashTable::search(UPCEntry& item) { //searches for the specific item in both hash tables
    Position position;
    bool itemFound = false;
    int numPosition = 0;
    long long code;
    string descrip;
    code = stoll(item.desc.substr(0, 12));
    item.upc = code;
    descrip = item.desc.substr(13);

    firstHash = item.hash1(SizeOfTable); //hashes based on the item's upc
    secondHash = item.hash2(SizeOfTable);
    position.indexInTable = firstHash;

    //searches firsthash table
    for (auto it = arrLists.at(position.indexInTable).begin(); it != arrLists.at(position.indexInTable).end(); it++) {

        if (*it == item) {
            position.indexInBin = numPosition;
            itemFound = true;
            return position;
        }

        numPosition++;
    }

    numPosition = 0; //resets if firsthash doesn't result in position. 
    
    position.indexInTable = secondHash; //assign table index to second hash value

    //searches secondhash table
    for (auto it = arrLists.at(position.indexInTable).begin(); it != arrLists.at(position.indexInTable).end(); it++) {

        if (*it == item) {
            position.indexInBin = numPosition;
            itemFound = true;
            return position;
        }

        numPosition++;
    }
    position.indexInTable = -1;
    position.indexInBin = -1;
    return position;

}

float TwoHashTable::getStdDev() { //calls private function
    int binLength[SizeOfTable];
    for (int i = 0; i < SizeOfTable; i++) {
        binLength[i] = arrLists.at(i).size();
    }
    return stddev(binLength, SizeOfTable);
}


