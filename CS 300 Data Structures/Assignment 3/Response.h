//The header file for Response
#include <iostream>
#include "Packet.h"
#include "Buffer.h"
#ifndef RESPONSE
#define RESPONSE

using namespace std;

class Response {
  private:
    int responseTime;

  public:
    Response() {};
    Response(int processTime);
    void printResponses(vector <Response> vector);
    int getResponseTime();

};

#endif
