/*
    Specific position in the table and bin determined by the two integers
*/

#ifndef POSITION_H
#define POSITION_H

struct Position
{
    int indexInTable = -1; //position in the table.
    int indexInBin = -1;   // position in the linked list.
};

#endif