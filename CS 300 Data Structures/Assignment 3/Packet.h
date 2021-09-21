// This is the header file for Packet
#include <iostream>
#include <string>
#include <vector>
#ifndef PACKET
#define PACKET

using namespace std;

class Packet {
  private:
    int arriveTime;
    int processTime;
  
  public:
    Packet() {};
    Packet(int time1, int time2);
    int getArriveTime();
    int getProcessTime();
};

#endif