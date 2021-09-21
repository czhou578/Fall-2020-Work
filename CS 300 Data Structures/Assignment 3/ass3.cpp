/*
ass3.cpp
Colin Zhou
10/20/2020
Takes in user input of numbers as string, converts the string into two integers, creates a 
packet out of the two integers, and determines the processing time of when each Packet was 
processed. 

*/

#include <iostream>
#include <vector>
#include <sstream>
#include "Packet.h"
#include "Response.h"
#include "Buffer.h"

using namespace std;

vector<Packet> readPackets() {
    vector<Packet> vector; 
    int numPackets;
    cin >> numPackets;
    
    string string;
    int counter = 0; //number of times looped
    int firstNum;
    int secondNum;

    while(true) { 

        if (counter == 0) {
            cin.ignore();
        }

        getline(cin, string); 

        if (string.length() == 0) {
            return vector;
        }

        stringstream ss(string); //break up input into respective values
        ss >> firstNum >> secondNum;

        Packet packet(firstNum, secondNum); //creates specific packets and pushes them into vector defined above
        vector.push_back(packet);
        counter++;
        
    }
    return vector;
}

vector<Response> processPackets(vector<Packet>& requests, Buffer<Packet> *buffer) { //pass in dereferenced object
    vector<Response> processed;
    int timeKeeper = 0; //keeps track of the time elapsed
    int sameArriveCount = 0; //account for first element in buffer already
    int bufferSize = buffer->getBufferSize(); // buffer size
    bool isFinished = false; //checks to see if the processing is finished
    int prevPacketArrivTime; // when the previous packet arrived

    if (requests.empty()) { // if there are no requests inputted by user
        processed.push_back(Response(-2));
        return processed;
    }

    for (int i = 0; i < requests.size();) { //loop until requests.size is reached

        if (i == requests.size() - 1 && buffer->isEmpty()) { //case 1
            if (requests[i].getArriveTime() == prevPacketArrivTime) {
                sameArriveCount++;
                if (sameArriveCount > buffer->getBufferSize()) {
                    processed.push_back(-1);
                    return processed;
                }
            }

            buffer->enqueue(requests[i]);
            isFinished = true;
        } 

        if (buffer->isEmpty() && i == 0) { //add the first packet into the buffer at i == 0
            sameArriveCount++;
            buffer->enqueue(requests[i]);
            prevPacketArrivTime = requests[i].getArriveTime();
        }
        
        if (i > 0 && i < requests.size() - 1) { //in the middle of traversing the request vector
            if (requests[i].getArriveTime() == prevPacketArrivTime) { // counts packets that arrive at same time
                sameArriveCount++;
            } else {
                sameArriveCount = 1;
            }

            if (sameArriveCount > buffer->getBufferSize()) {  //account for case if packets need to be dropped
                processed.push_back(-1);
                i++;
                continue;
            }
            buffer->enqueue(requests[i]);

        } else if (buffer->isEmpty()) { //repeat the same if buffer is empty while in middle of traversing
            if (requests[i].getArriveTime() == prevPacketArrivTime) {
                sameArriveCount++; //wrong
            } else {
                sameArriveCount = 1;
            } 

            sameArriveCount++;
            if (sameArriveCount > buffer->getBufferSize()) { //drop packet if necessary
                processed.push_back(-1);
                i++;
                continue;
            }
            buffer->enqueue(requests[i]);
        }
 
        while (!buffer->isEmpty()) { //start processing packets one by one
            if (buffer->qFront().getArriveTime() == 0 && i == 0) { // case 1
                processed.push_back(0);
                timeKeeper += buffer->qFront().getArriveTime() + buffer->qFront().getProcessTime();
                buffer->dequeue();
                i++;
                continue;

            } else if (buffer->qFront().getArriveTime() > 0 && i == 0) {
                processed.push_back(-2);
                processed.push_back(buffer->qFront().getArriveTime());
                timeKeeper += buffer->qFront().getArriveTime() + buffer->qFront().getProcessTime();
                buffer->dequeue();
                i++;
                continue;
            }

            if (!buffer->isEmpty() || i == requests.size() - 1) { //second case

                if (isFinished == true && prevPacketArrivTime == buffer->qFront().getArriveTime()) {
                    processed.push_back(timeKeeper);
                    buffer->dequeue();
                    return processed;
                }

                if (prevPacketArrivTime == buffer->qFront().getArriveTime()) { // ex: (1,1), (1,2)
                    processed.push_back(timeKeeper);
                    timeKeeper += buffer->qFront().getProcessTime();
                    prevPacketArrivTime = buffer->qFront().getArriveTime();
                    buffer->dequeue();
                    i++;
                    continue;
                }

                if (timeKeeper == buffer->qFront().getArriveTime()) { //deals with timeKeeper cases 
                    processed.push_back(timeKeeper);
                } else if (timeKeeper > buffer->qFront().getArriveTime()) {
                    processed.push_back(timeKeeper);
                } else if (buffer->qFront().getArriveTime() - timeKeeper > 1) {
                    int idlingTime = buffer->qFront().getArriveTime() - timeKeeper;
                    for (int i = 0; i < idlingTime; i++) {
                        processed.push_back(-2);
                    }
                    processed.push_back(buffer->qFront().getArriveTime());
                    timeKeeper = buffer->qFront().getArriveTime();
                } else if (timeKeeper < buffer->qFront().getArriveTime()) {
                    processed.push_back(buffer->qFront().getArriveTime());
                    timeKeeper = buffer->qFront().getArriveTime();
                }
            }
            
            if (isFinished == true && i == requests.size() - 1) {
                return processed;
            }

            timeKeeper += buffer->qFront().getProcessTime();
            prevPacketArrivTime = requests[i].getArriveTime();
            buffer->dequeue();
            i++;
        }
    } 
}

void printResponses(vector<Response> vector) { // prints the responses in the Response type vector
    for (int i = 0; i < vector.size(); i++) {
      cout << vector[i].getResponseTime() << endl;
    }
}

//please don't modify main function
int main() {
    int bufferSize;
    cin >> bufferSize;
    vector<Packet> requests = readPackets(); //read packets from user

    //create buffer with the given size
    Buffer<Packet> buffer(bufferSize);

    //process the packets
    vector<Response> responses = processPackets(requests, &buffer);

    //print responses
    printResponses(responses);

    return 0;
}


