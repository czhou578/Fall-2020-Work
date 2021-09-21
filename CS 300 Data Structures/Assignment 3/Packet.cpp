//Implementation of Packet (I know that I can put this in the header file!)
#include <vector>
#include "Packet.h"

using namespace std;

    Packet::Packet(int time1, int time2) { //constructor for Packet object
      arriveTime = time1;
      processTime = time2;
    }

    int Packet::getArriveTime() {
      return arriveTime;
    }

    int Packet::getProcessTime() {
      return processTime;
    }
